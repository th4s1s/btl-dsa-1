#include "ConcatStringList.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifndef __MAIN_H__
#define __MAIN_H__


#endif

#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif



void tc1() {
    ConcatStringList s1("Hello,_world");
    // test length
    cout << "s1's length: " << s1.length() << endl;
    // test get
    cout << "char at index 2: " << s1.get(2) << endl;
    try {
        cout << "char at index 22: " << s1.get(22) << endl;
    }
    catch (out_of_range & ofr) {
        cout << "Exception out_of_range: " << ofr.what() << endl;
    }
    // test indexOf
    cout << "in s1, index of 'o': " << s1.indexOf('o') << endl;
    cout << "in s1, index of 'a': " << s1.indexOf('a') << endl;
    // test toString
    cout << "s1 toString: " << s1.toString() << endl;
}

void tc2() {
    ConcatStringList s1("Hello,");
    ConcatStringList s2("_this_is");
    ConcatStringList s3("_an_assignment");

    // test concat
    /*ConcatStringList s4 = s1.concat(s2);
    cout << "s4: " << s4.toString() << endl;*/

    ConcatStringList s5 = s1.concat(s2).concat(s3);
    cout << "s5: " << s5.toString() << endl;

    // test subString
    ConcatStringList s6 = s5.subString(5, 15);
    cout << "s6: " << s6.toString() << endl;
    try {
        ConcatStringList s6 = s5.subString(25, 15);
        cout << "s6: " << s6.toString() << endl;
    }
    catch (exception& ofr) {
        cout << "Pekowide Error: " << ofr.what() << endl;
    }


    // test reverse
    ConcatStringList s7 = s5.reverse();
    cout << "s7: " << s7.toString() << endl;
}

void tc3() {
    ConcatStringList * s1 = new ConcatStringList("Hello");
    ConcatStringList * s2 = new ConcatStringList("_world");
    ConcatStringList * s3 = new ConcatStringList(s1->concat(*s2));

    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << "---After deleting s1---" << endl;
    delete s1;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << "---After deleting s3---" << endl;
    delete s3;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << "---After deleting s2---" << endl;
    delete s2;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;
}

void tc30() {
    cout << endl;
    ConcatStringList* s0 = new ConcatStringList("XYZ");
    cout << "s0: " << s0->toString() << endl;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << endl;
    ConcatStringList* s1 = new ConcatStringList("ABC");
    cout << "s1: " << s1->toString() << endl;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << endl;
    ConcatStringList* s2 = new ConcatStringList("DEF");
    cout << "s2: " << s2->toString() << endl;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << endl;
    ConcatStringList* s3 = new ConcatStringList("GHI");
    cout << "s3: " << s3->toString() << endl;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << endl;
    ConcatStringList* s4 = new ConcatStringList(s1->concat(*s2));
    cout << "s4: " << s4->toString() << endl;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << endl;
    ConcatStringList* s5 = new ConcatStringList(s4->reverse().concat(*s3));
    cout << "s5: " << s5->toString() << endl;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << endl;
    ConcatStringList* s6 = new ConcatStringList(s5->reverse().reverse());
    cout << "s6: " << s6->toString() << endl;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << endl;
    ConcatStringList* s7 = new ConcatStringList(s5->subString(1, 8));
    cout << "s7: " << s7->toString() << endl;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << endl;
    ConcatStringList* s8 = new ConcatStringList(s5->subString(1, 8).subString(1, 5).subString(2, 3));
    cout << "s8: " << s8->toString() << endl;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << endl;
    ConcatStringList* s9 = new ConcatStringList(s6->concat(s5->reverse().subString(4, 5)).reverse());
    cout << "s9: " << s9->toString() << endl;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << endl;
    ConcatStringList* s10 = new ConcatStringList(s0->reverse().concat((s0->reverse().concat(s0->reverse()).reverse())));
    cout << "s10: " << s10->toString() << endl;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;


    cout << "---After deleting s0---" << endl;
    delete s0;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << endl;
    cout << "---After deleting s1---" << endl;
    delete s1;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << endl;
    cout << "---After deleting s3---" << endl;
    delete s3;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << endl;
    cout << "---After deleting s2---" << endl;
    delete s2;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << endl;
    cout << "---After deleting s4---" << endl;
    delete s4;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << endl;
    cout << "---After deleting s5---" << endl;
    delete s5;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << endl;
    cout << "---After deleting s6---" << endl;
    delete s6;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << endl;
    cout << "---After deleting s7---" << endl;
    delete s7;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << endl;
    cout << "---After deleting s8---" << endl;
    delete s8;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << endl;
    cout << "---After deleting s9---" << endl;
    delete s9;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << endl;
    cout << "---After deleting s10---" << endl;
    delete s10;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;
}

void tc39() {
    cout << endl;
    ConcatStringList* s0 = new ConcatStringList("");
    cout << "s0: " << s0->toString() << " , length =" << s0->length() << endl;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << endl;
    ConcatStringList* s1 = new ConcatStringList("");
    cout << "s1: " << s1->toString() << " , length =" << s1->length() << endl;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << endl;
    ConcatStringList* s2 = new ConcatStringList("");
    cout << "s2: " << s2->toString() << " , length =" << s2->length() << endl;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << endl;
    ConcatStringList* s3 = new ConcatStringList("123456789");
    cout << "s3: " << s3->toString() << " , length =" << s3->length() << endl;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << endl;
    ConcatStringList* s4 = new ConcatStringList(s0->concat(*s1));
    cout << "s4: " << s4->toString() << " , length =" << s4->length() << endl;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << endl;
    ConcatStringList* s5 = new ConcatStringList(s0->reverse());
    //s5 is "" so head and tail is the same
    cout << "s5: " << s5->toString() << " , length =" << s5->length() << endl;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;


    cout << endl;
    ConcatStringList* s6 = new ConcatStringList(s4->reverse());
    //s6 is  "" -> "" so there are different head and tail
    cout << "s6: " << s6->toString() << " , length =" << s6->length() << endl;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;


    cout << endl;
    ConcatStringList* s7 = new ConcatStringList(s2->concat(*s3));
    //s7 is "" -> "123456789" so head is "" and tail is "123456789"
    cout << "s7: " << s7->toString() << " , length =" << s7->length() << endl;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << endl;
    ConcatStringList* s8 = new ConcatStringList(s7->reverse());
    //s8 is "987654321" -> "" so head is "987654321" and tail is ""
    cout << "s8: " << s8->toString() << " , length =" << s8->length() << endl;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;


    cout << endl;
    ConcatStringList* s9 = new ConcatStringList(s7->subString(0, 9));
    //s9 still get the empty string so ""->"123456789"
    cout << "s9: " << s9->toString() << " , length =" << s9->length() << endl;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;


    cout << endl;
    ConcatStringList* s10 = new ConcatStringList(s9->reverse());
    //try reverse it why not "987654321" ->""
    cout << "s10: " << s10->toString() << " , length =" << s10->length() << endl;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;


    cout << endl;
    ConcatStringList* s11 = new ConcatStringList(s8->subString(0, 9));
    //s11 still get the empty string so "987654321" -> ""
    cout << "s11: " << s11->toString() << " , length =" << s11->length() << endl;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << endl;
    ConcatStringList* s12 = new ConcatStringList(s11->reverse());
    //reverse it why not ""->"123456789"
    cout << "s12: " << s12->toString() << " , length =" << s12->length() << endl;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;


    cout << endl;
    ConcatStringList* s13 = new ConcatStringList(s12->concat(*s10));
    //s13 is "" -> "123456789" -> "987654321" -> "" 
    cout << "s13: " << s13->toString() << " , length =" << s13->length() << endl;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << endl;
    ConcatStringList* s14 = new ConcatStringList(s13->subString(0, 18));
    //s14 is "" -> "123456789" -> "987654321" -> "" 
    cout << "s14: " << s14->toString() << " , length =" << s14->length() << endl;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << "s14: '9' is at " << s14->indexOf('9') << " index and at index 9 is " << s14->get(9) << " , so they are equal " << (s14->indexOf(s14->get(9)) == 9) << endl;

    cout << endl;
    ConcatStringList* s15 = new ConcatStringList(s13->reverse());
    //s14 is "987654321" -> ""  -> "" -> "123456789"
    cout << "s15: " << s15->toString() << " , length =" << s15->length() << endl;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << "s15: '1' is at " << s15->indexOf('1') << " index and at index 1 is " << s15->get(1) << " , so they are equal " << (s15->indexOf(s15->get(1)) == 1) << endl;

    cout << "---After deleting s15---" << endl;
    delete s15;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;


    cout << "---After deleting s14---" << endl;
    delete s14;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << "---After deleting s13---" << endl;
    delete s13;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << "---After deleting s12---" << endl;
    delete s12;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << "---After deleting s11---" << endl;
    delete s11;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;


    cout << "---After deleting s10---" << endl;
    delete s10;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << "---After deleting s9---" << endl;
    delete s9;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << "---After deleting s8---" << endl;
    delete s8;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << "---After deleting s7---" << endl;
    delete s7;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << "---After deleting s6---" << endl;
    delete s6;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << "---After deleting s0---" << endl;
    delete s0;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << endl;
    cout << "---After deleting s1---" << endl;
    delete s1;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << endl;
    cout << "---After deleting s3---" << endl;
    delete s3;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << endl;
    cout << "---After deleting s2---" << endl;
    delete s2;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << endl;
    cout << "---After deleting s4---" << endl;
    delete s4;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << endl;
    cout << "---After deleting s5---" << endl;
    delete s5;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

}

void tc47() {
    cout << endl;
    ConcatStringList* s0 = new ConcatStringList("0123456789");
    cout << "s0: " << s0->toString() << endl;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    int sum = 0;
    for (int i = 9; i >= 0; i--) {
        sum += s0->indexOf((char)'0' + i);
    }
    cout << "SUM = " << sum << endl;


    for (int i = 9; i >= 0; i--) {
        cout << s0->get(i);
    }
    cout << endl;
    cout << endl;



    ConcatStringList* s2 = new ConcatStringList
    (s0->subString(0, 1).concat(
        (s0->subString(1, 2).concat(
            (s0->subString(2, 3).concat(
                (s0->subString(3, 4).concat(
                    (s0->subString(4, 5).concat(
                        (s0->subString(5, 6).concat(
                            (s0->subString(6, 7).concat(
                                (s0->subString(7, 8).concat(
                                    (s0->subString(8, 9).concat(
                                        (s0->subString(9, 10)))
                                        .subString(0, 2)))
                                    .subString(0, 3)))
                                .subString(0, 4)))
                            .subString(0, 5)))
                        .subString(0, 6)))
                    .subString(0, 7)))
                .subString(0, 8)))
            .subString(0, 9)))
        .subString(0, 10));

    //Literally s0 == s2 = "0123456789" but take extra effort for no reason
    cout << "s2: " << s2->toString() << endl;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    sum = 0;
    for (int i = 9; i >= 0; i--) {
        sum += s2->indexOf((char)'0' + i);
    }
    cout << "SUM = " << sum << endl;


    for (int i = 9; i >= 0; i--) {
        cout << s2->get(i);
    }

    cout << endl;
    cout << "AT 10th index" << s2->indexOf(10) << endl;


    cout << endl;
    ConcatStringList* s3 = new ConcatStringList(s2->reverse());
    cout << "s3: " << s3->toString() << endl;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;
    sum = 0;
    for (int i = 9; i >= 0; i--) {
        sum += s3->indexOf((char)'0' + i);
    }
    cout << "SUM = " << sum << endl;


    for (int i = 9; i >= 0; i--) {
        cout << s3->get(i);
    }

    cout << endl;
    cout << endl;

    cout << "---After deleting 3---" << endl;
    delete s3;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << endl;
    cout << "---After deleting 0---" << endl;
    delete s0;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    //_CrtDumpMemoryLeaks();

    cout << endl;
    cout << "---After deleting s2---" << endl;
    delete s2;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    //_CrtDumpMemoryLeaks();
}

void tc69()
{
    ///////////////////////////////////////////////////
    /// HOW WELL CAN YOU HANDLE MULTIPLE CONCAT ??? ///
    ///////////////////////////////////////////////////

    cout << "Test 1: " << '\n' << '\n';

    ConcatStringList* s1 = new ConcatStringList("A");
    ConcatStringList* s2 = new ConcatStringList("B");
    ConcatStringList* s3 = new ConcatStringList("C");
    ConcatStringList* s4 = new ConcatStringList(s1->concat(*s2).concat(*s3));
    cout << "s4: " << s4->toString() << '\n';
    cout << "refList size: " << ConcatStringList::refList.size() << '\n';
    cout << ConcatStringList::refList.refCountsString();
    cout << '\n';
    cout << "delStrList size: " << ConcatStringList::delStrList.size() << '\n';
    cout << ConcatStringList::delStrList.totalRefCountsString();
    cout << '\n' << '\n';

    cout << "After deleting s3:" << '\n';
    delete s3;
    cout << "s4: " << s4->toString() << '\n';
    cout << "refList size: " << ConcatStringList::refList.size() << '\n';
    cout << ConcatStringList::refList.refCountsString();
    cout << '\n';
    cout << "delStrList size: " << ConcatStringList::delStrList.size() << '\n';
    cout << ConcatStringList::delStrList.totalRefCountsString();
    cout << '\n' << '\n';

    cout << "After deleting s1:" << '\n';
    delete s1;
    cout << "s2: " << s2->toString() << '\n';
    cout << "refList size: " << ConcatStringList::refList.size() << '\n';
    cout << ConcatStringList::refList.refCountsString();
    cout << '\n';
    cout << "delStrList size: " << ConcatStringList::delStrList.size() << '\n';
    cout << ConcatStringList::delStrList.totalRefCountsString();
    cout << '\n' << '\n';

    cout << "After deleting s4:" << '\n';
    delete s4;
    cout << "refList size: " << ConcatStringList::refList.size() << '\n';
    cout << ConcatStringList::refList.refCountsString();
    cout << '\n';
    cout << "delStrList size: " << ConcatStringList::delStrList.size() << '\n';
    cout << ConcatStringList::delStrList.totalRefCountsString();
    cout << '\n' << '\n';

    cout << "After deleting s2:" << '\n';
    delete s2;
    cout << "refList size: " << ConcatStringList::refList.size() << '\n';
    cout << ConcatStringList::refList.refCountsString();
    cout << '\n';
    cout << "delStrList size: " << ConcatStringList::delStrList.size() << '\n';
    cout << ConcatStringList::delStrList.totalRefCountsString();
    cout << '\n' << '\n';

    //////////////////////////////////////////////////
    /// HOW ABOUT WE ADD SOME REVERSE-CEPTIONS ??? ///
    //////////////////////////////////////////////////

    cout << "Test 2: " << '\n' << '\n';

    s1 = new ConcatStringList("A");
    s2 = new ConcatStringList("B");
    s3 = new ConcatStringList("C");
    s4 = new ConcatStringList("D");
    ConcatStringList* s5 = new ConcatStringList("E");
    ConcatStringList* s6 = new ConcatStringList("F");

    ConcatStringList *s7 = new ConcatStringList(s1->concat(*s2).reverse());
    ConcatStringList *s8 = new ConcatStringList(s3->concat(*s4).reverse());
    ConcatStringList *s9 = new ConcatStringList(s5->concat(*s6).reverse());

    cout << "s7: " << s7->toString() << '\n';
    cout << "s8: " << s8->toString() << '\n';
    cout << "s9: " << s9->toString() << '\n';

    ConcatStringList* s10 = new ConcatStringList(s7->reverse().concat(s8->reverse()).concat(s9->reverse()).reverse());
    cout << "s10: " << s10->toString() << '\n';
    cout << '\n';

    cout << "After deleting s9:" << '\n';
    delete s9;
    cout << "s10: " << s10->toString() << '\n';
    cout << "refList size: " << ConcatStringList::refList.size() << '\n';
    cout << ConcatStringList::refList.refCountsString();
    cout << '\n';
    cout << "delStrList size: " << ConcatStringList::delStrList.size() << '\n';
    cout << ConcatStringList::delStrList.totalRefCountsString();
    cout << '\n' << '\n';

    cout << "After deleting s7:" << '\n';
    delete s7;
    cout << "s10: " << s10->toString() << '\n';
    cout << "refList size: " << ConcatStringList::refList.size() << '\n';
    cout << ConcatStringList::refList.refCountsString();
    cout << '\n';
    cout << "delStrList size: " << ConcatStringList::delStrList.size() << '\n';
    cout << ConcatStringList::delStrList.totalRefCountsString();
    cout << '\n' << '\n';

    cout << "After deleting s1:" << '\n';
    delete s1;
    cout << "s10: " << s10->toString() << '\n';
    cout << "refList size: " << ConcatStringList::refList.size() << '\n';
    cout << ConcatStringList::refList.refCountsString();
    cout << '\n';
    cout << "delStrList size: " << ConcatStringList::delStrList.size() << '\n';
    cout << ConcatStringList::delStrList.totalRefCountsString();
    cout << '\n' << '\n';

    cout << "After deleting s2:" << '\n';
    delete s2;
    cout << "s10: " << s10->toString() << '\n';
    cout << "refList size: " << ConcatStringList::refList.size() << '\n';
    cout << ConcatStringList::refList.refCountsString();
    cout << '\n';
    cout << "delStrList size: " << ConcatStringList::delStrList.size() << '\n';
    cout << ConcatStringList::delStrList.totalRefCountsString();
    cout << '\n' << '\n';

    cout << "After deleting s3:" << '\n';
    delete s3;
    cout << "s10: " << s10->toString() << '\n';
    cout << "refList size: " << ConcatStringList::refList.size() << '\n';
    cout << ConcatStringList::refList.refCountsString();
    cout << '\n';
    cout << "delStrList size: " << ConcatStringList::delStrList.size() << '\n';
    cout << ConcatStringList::delStrList.totalRefCountsString();
    cout << '\n' << '\n';

    cout << "After deleting s4:" << '\n';
    delete s4;
    cout << "s10: " << s10->toString() << '\n';
    cout << "refList size: " << ConcatStringList::refList.size() << '\n';
    cout << ConcatStringList::refList.refCountsString();
    cout << '\n';
    cout << "delStrList size: " << ConcatStringList::delStrList.size() << '\n';
    cout << ConcatStringList::delStrList.totalRefCountsString();
    cout << '\n' << '\n';

    cout << "After deleting s5:" << '\n';
    delete s5;
    cout << "s10: " << s10->toString() << '\n';
    cout << "refList size: " << ConcatStringList::refList.size() << '\n';
    cout << ConcatStringList::refList.refCountsString();
    cout << '\n';
    cout << "delStrList size: " << ConcatStringList::delStrList.size() << '\n';
    cout << ConcatStringList::delStrList.totalRefCountsString();
    cout << '\n' << '\n';

    cout << "After deleting s6:" << '\n';
    delete s6;
    cout << "s10: " << s10->toString() << '\n';
    cout << "refList size: " << ConcatStringList::refList.size() << '\n';
    cout << ConcatStringList::refList.refCountsString();
    cout << '\n';
    cout << "delStrList size: " << ConcatStringList::delStrList.size() << '\n';
    cout << ConcatStringList::delStrList.totalRefCountsString();
    cout << '\n' << '\n';

    /////////////////////////////////////////////////////////////////////////////////
    /// LET'S PLAY A LITTLE GAME OF SUBSTRING BEFORE ENDING THE TEST SHALL WE ??? ///
    /////////////////////////////////////////////////////////////////////////////////

    ConcatStringList* s11 = new ConcatStringList(s10->subString(3, 6).concat(s10->subString(0, 3)));
    cout << "s11: " << s11->toString() << '\n';
    cout << '\n';

    cout << "After deleting s10:" << '\n';
    delete s10;
    cout << "refList size: " << ConcatStringList::refList.size() << '\n';
    cout << ConcatStringList::refList.refCountsString();
    cout << '\n';
    cout << "delStrList size: " << ConcatStringList::delStrList.size() << '\n';
    cout << ConcatStringList::delStrList.totalRefCountsString();
    cout << '\n' << '\n';

    cout << "After deleting s8:" << '\n';
    delete s8;
    cout << "refList size: " << ConcatStringList::refList.size() << '\n';
    cout << ConcatStringList::refList.refCountsString();
    cout << '\n';
    cout << "delStrList size: " << ConcatStringList::delStrList.size() << '\n';
    cout << ConcatStringList::delStrList.totalRefCountsString();
    cout << '\n' << '\n';

    cout << "After deleting s11:" << '\n';
    delete s11;
    cout << "refList size: " << ConcatStringList::refList.size() << '\n';
    cout << ConcatStringList::refList.refCountsString();
    cout << '\n';
    cout << "delStrList size: " << ConcatStringList::delStrList.size() << '\n';
    cout << ConcatStringList::delStrList.totalRefCountsString();
    cout << '\n' << '\n';

    ///////////////////////////////////////////////////
    /// THANKS FOR TESTING !!! HERE'S MY ANSWER !!! ///
    ///////////////////////////////////////////////////

    /*
    Test 1:

    s4: ABC
    refList size: 3
    RefCounts[2,3,3]
    delStrList size: 1
    TotalRefCounts[5]

    After deleting s3:
    s4: ABC
    refList size: 3
    RefCounts[1,2,3]
    delStrList size: 2
    TotalRefCounts[5,1]

    After deleting s1:
    s2: B
    refList size: 3
    RefCounts[1,1,2]
    delStrList size: 3
    TotalRefCounts[3,1,1]

    After deleting s4:
    refList size: 3
    RefCounts[2,0,0]
    delStrList size: 1
    TotalRefCounts[2]

    After deleting s2:
    refList size: 0
    RefCounts[]
    delStrList size: 0
    TotalRefCounts[]

    Test 2:

    s7: BA
    s8: DC
    s9: FE
    s10: FEDCBA

    After deleting s9:
    s10: FEDCBA
    refList size: 20
    RefCounts[1,1,1,1,1,1,2,2,2,2,2,2,0,0,0,0,0,0,0,0]
    delStrList size: 3
    TotalRefCounts[4,4,4]

    After deleting s7:
    s10: FEDCBA
    refList size: 20
    RefCounts[1,1,1,1,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0]
    delStrList size: 3
    TotalRefCounts[4,4,4]

    After deleting s1:
    s10: FEDCBA
    refList size: 20
    RefCounts[1,1,1,1,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0]
    delStrList size: 3
    TotalRefCounts[2,4,4]

    After deleting s2:
    s10: FEDCBA
    refList size: 20
    RefCounts[1,1,1,1,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0]
    delStrList size: 2
    TotalRefCounts[4,4]

    After deleting s3:
    s10: FEDCBA
    refList size: 20
    RefCounts[1,1,1,1,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0]
    delStrList size: 2
    TotalRefCounts[2,4]

    After deleting s4:
    s10: FEDCBA
    refList size: 20
    RefCounts[1,1,1,1,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
    delStrList size: 1
    TotalRefCounts[4]

    After deleting s5:
    s10: FEDCBA
    refList size: 20
    RefCounts[1,1,1,1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
    delStrList size: 1
    TotalRefCounts[2]

    After deleting s6:
    s10: FEDCBA
    refList size: 20
    RefCounts[1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
    delStrList size: 0
    TotalRefCounts[]

    s11: CBAFED

    After deleting s10:
    refList size: 24
    RefCounts[1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
    delStrList size: 2
    TotalRefCounts[1,1]

    After deleting s8:
    refList size: 24
    RefCounts[1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
    delStrList size: 2
    TotalRefCounts[1,1]

    After deleting s11:
    refList size: 0
    RefCounts[]
    delStrList size: 0
    TotalRefCounts[]
    */
}

void tc()
{
    cout << endl;
    ConcatStringList* s0 = new ConcatStringList("XYZ");
    cout << "s0: " << s0->toString() << endl;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;

    cout << endl;
    ConcatStringList* s10 = new ConcatStringList(s0->reverse().concat((s0->reverse().concat(s0->reverse()).reverse())));
    cout << "s10: " << s10->toString() << endl;
    cout << "refList size: " << ConcatStringList::refList.size() << ", delStrList size: " << ConcatStringList::delStrList.size() << endl;
    cout << ConcatStringList::refList.refCountsString() << endl;
    cout << ConcatStringList::delStrList.totalRefCountsString() << endl;
}

int main() {
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
    _CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
    _CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
    _CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDOUT);
    _CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
    _CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDOUT);
    _CrtMemState s1, s2, s3;
    _CrtMemCheckpoint(&s1);
    tc69();
    _CrtMemCheckpoint(&s2);
    if (_CrtMemDifference(&s3, &s1, &s2))
    {
        _CrtMemDumpStatistics(&s3);
    }
    return 0;
}