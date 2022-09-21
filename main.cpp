#include "test.h"
using namespace std;

int main() {
    Journal test1(1,1,"a","b","c",12,10);
    Journal test2(test1);
    Journal::JournalReport forTest(3,23,"asd","asd","dsf",5);
    test2.addNewElement(0, forTest, 4);
    assert(!test1.compareArray(test2));
    //cout << "Copy test\t\t\t\tCompleted" << endl;

    Journal::JournalReport testA(3,23,"asd","asd","dsf",5);
    test1.addNewElement(0, testA, 12);
    test1.popElement(1);
    assert(!test1.compareArray(test2));
    //cout << "Add/Pop methods test\tCompleted" << endl;

    Journal test3;
    test2.disposeAll();
    assert(test2.compareArray(test3));
    //cout << "Dispose test\t\t\tCompleted" << endl;

    Journal test4(1,1,"Test","test","Tts",12,10);
    assert(test4.compareArray(test1));
    //cout << "Compare method test\t\tCompleted" << endl;

    test1.writeInFile();
    test1.readFromFile();
    assert(test1.compareArray(test4));
    //cout << "File In/Out test\t\tCompleted" << endl << endl;
    
    test4.printArray();

    return 0;
}
//	JournalReportConstructorTest();
//	JournalReportTest();