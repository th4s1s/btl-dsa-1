#ifndef __CONCAT_STRING_LIST_H__
#define __CONCAT_STRING_LIST_H__

#include "main.h"

class ConcatStringList {
public:
    class ReferencesList; // forward declaration
    class DeleteStringList; // forward declaration

public:
    static ReferencesList refList;
    static DeleteStringList delStrList;
    struct RefNode;
    struct DelNode;
    // TODO: may provide some attributes
    struct CharALNode
    {
        string str;
        CharALNode* next;
        CharALNode* prev;
        int size;
        CharALNode(string s, CharALNode* n = nullptr, CharALNode* p = nullptr)
        {
            str = s;
            next = n;
            prev = p;
            size = s.length();
        }
    };

    struct RefNode
    {
        CharALNode* ref;
        int num;
        RefNode* next;
        RefNode(CharALNode* s, int x = 1, RefNode* n = nullptr)
        {
            ref = s;
            num = x;
            next = n;
        }
    };

    struct DelNode
    {
        RefNode* head;
        RefNode* tail;
        DelNode* next;
        DelNode* prev;
        DelNode(RefNode* h, RefNode* t, DelNode* n = nullptr, DelNode* p = nullptr)
        {
            head = h;
            tail = t;
            next = n;
            prev = p;
        }
    };

private:
    CharALNode* head;
    CharALNode* tail;
    int len;

public:
    ConcatStringList()
    {
        head = nullptr;
        tail = nullptr;
        len = 0;
    }
    ConcatStringList(CharALNode* h, CharALNode* t, int l)
    {
        head = h;
        tail = t;
        len = l;
    }
    ConcatStringList(const char* s)
    {
        string tmp = "";
        len = 0;
        for (int i = 0; s[i] != '\0'; i++)
        {
            tmp += s[i];
            len++;
        }
        head = new CharALNode(tmp);
        tail = head;
        RefNode* p = new RefNode(head, 2);
        refList.add(p);
    }
    int length() const
    {
        return len;
    }
    char get(int index) const
    {
        if (head == nullptr || index < 0 || index >= len)
        {
            throw out_of_range("Index of string is invalid!");
        }
        CharALNode* cur = head;
        int l = cur->size;
        while (index >= l)
        {
            cur = cur->next;
            l += cur->size;
        }
        string tmp = cur->str;
        int i = cur->size;
        return tmp[i - (l - index)];
    }
    int indexOf(char c) const
    {
        CharALNode* cur = head;
        int s = 0;
        while (cur != nullptr)
        {
            int l = cur->size;
            string tmp = cur->str;
            for (int i = 0; i < l; i++)
            {
                if (tmp[i] == c) return s + i;
            }
            s += l;
            cur = cur->next;
        }
        return -1;
    }
    std::string toString() const
    {
        string tmp = "";
        CharALNode* cur = head;
        while (cur != tail)
        {
            tmp += cur->str;
            cur = cur->next;
        }
        tmp += cur->str;
        return tmp;
    }
    ConcatStringList concat(const ConcatStringList& otherS) const
    {
        this->tail->next = otherS.head;
        otherS.head->prev = this->tail;
        RefNode* p = new RefNode(this->head);
        refList.add(p);
        p = new RefNode(otherS.tail);
        refList.add(p);
        return ConcatStringList(this->head, otherS.tail, this->len + otherS.len);
    }
    ConcatStringList subString(int from, int to) const
    {
        if (from < 0 || from >= len || to < 0 || to > len) throw out_of_range("Index of string is invalid");
        if (from >= to) throw logic_error("Invalid range");
        CharALNode* cur = head;
        int l = cur->size;
        while (from >= l)
        {
            cur = cur->next;
            l += cur->size;
        }
        CharALNode* old = cur;
        string tmp = cur->str;
        int s = cur->size;
        CharALNode* headT = nullptr, * tailT = nullptr;
        int lTMP = 0;
        CharALNode* subTMP = new CharALNode(tmp.substr(s - (l - from), to - from));
        headT = subTMP;
        tailT = subTMP;
        lTMP = subTMP->size;
        RefNode* subRef = new RefNode(headT);
        refList.add(subRef);
        while (to > l)
        {
            cur = cur->next;
            l += cur->size;
            if (to > l)
            {
                CharALNode* p = new CharALNode(cur->str);
                tailT->next = p;
                p->prev = tailT;
                tailT = tailT->next;
                lTMP += cur->size;
            }
        }
        if (cur != old)
        {
            tmp = cur->str;
            s = cur->size;
            string strNew = "";
            for (int i = 0; i < s - (l - to); i++)
            {
                strNew += tmp[i];
                lTMP++;
            }
            CharALNode* p = new CharALNode(strNew);
            tailT->next = p;
            p->prev = tailT;
            tailT = tailT->next;
        }
        subRef = new RefNode(tailT);
        refList.add(subRef);
        return ConcatStringList(headT, tailT, lTMP);
    }
    ConcatStringList reverse() const
    {
        CharALNode* headT = nullptr, * tailT = nullptr;
        CharALNode* cur = head;
        bool first = 0;
        while (cur != tail)
        {
            string tmp = cur->str, re = "";
            int l = cur->size;
            for (int i = l - 1; i >= 0; i--) re += tmp[i];
            CharALNode* p = new CharALNode(re);
            p->next = headT;
            if (headT != nullptr) headT->prev = p;
            headT = p;
            if (!first)
            {
                tailT = headT;
                first = 1;
            }
            cur = cur->next;
        }
        string tmp = cur->str, re = "";
        int l = cur->size;
        for (int i = l - 1; i >= 0; i--) re += tmp[i];
        CharALNode* p = new CharALNode(re);
        p->next = headT;
        if (headT != nullptr) headT->prev = p;
        headT = p;
        if (!first)
        {
            tailT = headT;
            first = 1;
        }
        cur = cur->next;
        RefNode* subRef = new RefNode(headT);
        refList.add(subRef);
        subRef = new RefNode(tailT);
        refList.add(subRef);
        return ConcatStringList(headT, tailT, this->len);
    }
    ~ConcatStringList()
    {
        refList.remove(head);
        refList.remove(tail);
        DelNode* p = new DelNode(refList.getRefAt(head), refList.getRefAt(tail));
        delStrList.insert(p);
        refList.checkList();
        head = nullptr;
        tail = nullptr;
        len = 0;
    }
    bool checkEmptyList()
    {
        return (head == nullptr);
    }

public:
    class ReferencesList {
        // TODO: may provide some attributes
    private:
        RefNode* head = nullptr;
        RefNode* tail = nullptr;
        int nodes = 0;

    public:
        void insert(RefNode* p, bool last = 0)
        {
            if (last)
            {
                p->next = tail->next;
                tail->next = p;
                tail = tail->next;
                return;
            }
            if (p->num <= head->num)
            {
                p->next = head;
                head = p;
                return;
            }
            RefNode* cur = head;
            while (cur->next != nullptr && p->num > cur->next->num && cur->next->num != 0) cur = cur->next;
            p->next = cur->next;
            cur->next = p;
            while (tail->next != nullptr) tail = tail->next;
        }
        void add(RefNode* p)
        {
            if (head == nullptr)
            {
                head = p;
                tail = p;
                nodes = 1;
                return;
            }
            if (p->ref == head->ref)
            {
                head->num += p->num;
                if (nodes == 1)
                {
                    delete p;
                    return;
                }
                RefNode* del = p;
                p = head;
                head = head->next;
                delete del;
                insert(p);
                return;
            }
            RefNode* cur = head->next, * pre = head;
            while (cur != nullptr)
            {
                if (p->ref == cur->ref)
                {
                    cur->num += p->num;
                    pre->next = cur->next;
                    delete p;
                    insert(cur);
                    return;
                }
                pre = pre->next; cur = cur->next;
            }
            nodes++;
            insert(p);
        }
        void remove(CharALNode* p)
        {
            if (head->ref == p)
            {
                head->num--;
                if (nodes > 1 && head->num == 0)
                {
                    RefNode* ins = head;
                    head = head->next;
                    insert(ins, 1);
                }
            }
            else
            {
                RefNode* pre = head, * cur = head->next;
                while (cur != nullptr)
                {
                    if (cur->ref == p)
                    {
                        cur->num--;
                        pre->next = cur->next;
                        if (cur == tail) tail = pre;
                        if (cur->num == 0) insert(cur, 1);
                        else insert(cur);
                    }
                    pre = cur;  cur = cur->next;
                }
            }
        }
        ~ReferencesList()
        {
            RefNode* cur = head;
            while (cur != nullptr)
            {
                head = head->next;
                delete cur;
                cur = head;
            }
            head = nullptr;
            tail = nullptr;
            nodes = 0;
        }
        void checkList()
        {
            if (head != nullptr && head->num == 0)
            {
                refList.~ReferencesList();
            }
        }
        int size() const
        {
            return nodes;
        }
        int refCountAt(int index) const
        {
            if (index >= nodes) throw out_of_range("Index of references list is invalid!");
            if (index == nodes - 1) return tail->num;
            RefNode* cur = head;
            for (int i = 0; i < index; i++) cur = cur->next;
            return cur->num;
        }
        int refCountAt(CharALNode* p) const
        {
            if (p == nullptr)
            {
                return 0;
            }
            RefNode* cur = head;
            while (cur != nullptr)
            {
                if (cur->ref == p)
                {
                    return cur->num;
                }
                cur = cur->next;
            }
            return 0;
        }
        RefNode* getRefAt(CharALNode* p) const
        {
            if (p == nullptr)
            {
                return nullptr;
            }
            RefNode* cur = head;
            while (cur != nullptr)
            {
                if (cur->ref == p)
                {
                    return cur;
                }
                cur = cur->next;
            }
            return nullptr;
        }
        std::string refCountsString() const
        {
            if (head == nullptr) return "RefCounts[]";
            string refCount = "RefCounts[";
            RefNode* cur = head;
            while (cur != tail)
            {
                refCount += (to_string(cur->num) + ",");
                cur = cur->next;
            }
            refCount += (to_string(cur->num) + "]");
            return refCount;
        }
        void removeRef(CharALNode* p)
        {
            if (p == nullptr) return;
            RefNode* cur = head;
            while (cur != nullptr)
            {
                if (cur->ref == p)
                {
                    cur->ref = nullptr;
                    return;
                }
                cur = cur->next;
            }
            return;
        }
    };

    class DeleteStringList {
        // TODO: may provide some attributes
    private:
        DelNode* head;
        DelNode* tail;
        int node;

    public:
        void insert(DelNode* p)
        {
            if (head == nullptr)
            {
                head = p;
                tail = p;
                node = 1;
            }
            else
            {
                p->next = tail->next;
                p->prev = tail;
                tail->next = p;
                tail = tail->next;
                node++;
            }
            checkList();
        }
        void checkList()
        {
            if (head == nullptr)
            {
                node = 0;
                delStrList.~DeleteStringList();
            }
            DelNode* cur = head;
            while (cur != nullptr)
            {
                if (cur->head->num == 0 && cur->tail->num == 0)
                {
                    if (cur->head->ref != nullptr && cur->tail->ref != nullptr) deleteString(cur->head->ref, cur->tail->ref);
                    //CharALNode* delHead = cur->head->ref, * delTail = cur->tail->ref;
                    if (cur == head)
                    {
                        head = head->next;
                        if (head != nullptr) head->prev = nullptr;
                        delete cur;
                        cur = head;
                    }
                    else
                    {
                        DelNode* del = cur;
                        if (cur == tail) tail = cur->prev;
                        cur->prev->next = cur->next;
                        if (cur->next != nullptr) cur->next->prev = cur->prev;
                        else {}
                        cur = head;
                        delete del;
                    }
                    //if (delHead != nullptr && delTail != nullptr) deleteString(delHead, delTail);
                    node--;
                }
                else
                {
                    cur = cur->next;
                }
            }
        }
        void deleteString(CharALNode* delHead, CharALNode* delTail)
        {
            refList.removeRef(delHead);
            refList.removeRef(delTail);
            if (delHead->prev != nullptr) delHead->prev->next = nullptr;
            if (delTail->next != nullptr) delTail->next->prev = nullptr;
            CharALNode* cur = delHead;
            while (cur != delTail)
            {
                delHead = delHead->next;
                delete cur;
                cur = delHead;
            }
            delete cur;
            delTail = nullptr;
            delHead = nullptr;
        }
        int size() const
        {
            if (head == nullptr)
            {
                delStrList.checkList();
            }
            return node;
        }
        std::string totalRefCountsString() const
        {
            if (head == nullptr) return "TotalRefCounts[]";
            int total = 0;
            string out = "TotalRefCounts[";
            DelNode* cur = head;
            while (cur->next != nullptr)
            {
                if (cur->head == cur->tail) total += (cur->head != nullptr) ? cur->head->num : 0;
                else
                {
                    total += (cur->head != nullptr) ? cur->head->num : 0;
                    total += (cur->tail != nullptr) ? cur->tail->num : 0;
                }
                out += to_string(total) + ",";
                cur = cur->next;
                total = 0;
            }
            if (cur->head == cur->tail) total += (cur->head != nullptr) ? cur->head->num : 0;
            else
            {
                total += (cur->head != nullptr) ? cur->head->num : 0;
                total += (cur->tail != nullptr) ? cur->tail->num : 0;
            }
            out += to_string(total) + "]";
            return out;
        }
        ~DeleteStringList()
        {
            DelNode* cur = head;
            while (cur != nullptr)
            {
                head = head->next;
                delete cur;
                cur = head;
            }
            head = nullptr;
            tail = nullptr;
            node = 0;
        }
    };
};


#endif // __CONCAT_STRING_LIST_H__