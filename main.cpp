#include <iostream>
#include <cassert>
#include "DeleteChange.h"

int main() {
    cout << "---Tests for the first lab---" << endl;
    //�� ���������
    AddFragment defaultAddFragment;
    assert(defaultAddFragment.getBaseText().empty());
    assert(defaultAddFragment.getInputText().empty());
    assert(defaultAddFragment.getPositionEditedSubstring() == 0);
    cout << "The default constructor test is passed." << endl;

    //�������������
    AddFragment initedAddFragment("Hello, world! My name is Dima.", "Hi, hi, hi", 5);
    assert(initedAddFragment.getBaseText() == "Hello, world! My name is Dima.");
    assert(initedAddFragment.getInputText() == "Hi, hi, hi");
    assert(initedAddFragment.getPositionEditedSubstring() == 5);
    cout << "Initialization constructor test passed." << endl;

    //�����������
    AddFragment copiedAddFragment(initedAddFragment);
    assert(copiedAddFragment.getBaseText() == "Hello, world! My name is Dima.");
    assert(copiedAddFragment.getInputText() == "Hi, hi, hi");
    assert(copiedAddFragment.getPositionEditedSubstring() == 5);
    cout << "The copy constructor test has been passed." << endl;

    //����� �������������
    assert(defaultAddFragment.isDeleteChange() == false);

    //�������, �������
    defaultAddFragment.setBaseText("Hello. Hello. Hello...");
    defaultAddFragment.setInputText("hi, hi");
    defaultAddFragment.setPositionEditedSubstring(2);
    assert(defaultAddFragment.getBaseText() == "Hello. Hello. Hello...");
    assert(defaultAddFragment.getInputText() == "hi, hi");
    assert(defaultAddFragment.getPositionEditedSubstring() == 2);
    cout << "Getters and setters test passed." << endl << endl;

    //�������� ������: ������� ��������� ������ � �������� ����� � ����������� �����
    assert(defaultAddFragment.pasteFragment("Hello, Hello", "Hey, hey. ", 0) == "Hey, hey. Hello, Hello");
    cout << "The first test is passed." << endl;
    assert(defaultAddFragment.pasteFragment("Hello, Hello", "Hey, hey. ", 15) == "Hello, HelloHey, hey. ");
    cout << "The second test is passed." << endl;
    assert(defaultAddFragment.pasteFragment("Hello, Hello", "Hey, hey. ", 11) == "Hello, HellHey, hey. o");
    cout << "The third test is passed." << endl;

    cout << endl << "---Tests for the second lab---" << endl;
    //�� ���������
    DeleteChange defaultDeleteChange;
    
    assert(defaultDeleteChange.getSecondPosEditSubStr() == 0);
    assert(defaultDeleteChange.getBaseText().empty());
    assert(defaultDeleteChange.getInputText().empty());
    assert(defaultDeleteChange.getPositionEditedSubstring() == 0);
    cout << "The default constructor test is passed." << endl;

    //�������������
    DeleteChange initedDeleteChange("Hello, world! My name is Dima.", "Hi, hi, hi", 5, 10);
    assert(initedDeleteChange.getBaseText() == "Hello, world! My name is Dima.");
    assert(initedDeleteChange.getInputText() == "Hi, hi, hi");
    assert(initedDeleteChange.getPositionEditedSubstring() == 5);
    assert(initedDeleteChange.getSecondPosEditSubStr() == 10);
    cout << "Initialization constructor test passed." << endl;

    //�����������
    DeleteChange copiedDeleteChange(initedDeleteChange);
    assert(copiedDeleteChange.getBaseText() == "Hello, world! My name is Dima.");
    assert(copiedDeleteChange.getInputText() == "Hi, hi, hi");
    assert(copiedDeleteChange.getPositionEditedSubstring() == 5);
    assert(copiedDeleteChange.getSecondPosEditSubStr() == 10);
    cout << "The copy constructor test has been passed." << endl;

    //����� �������������
    assert(defaultDeleteChange.isDeleteChange() == true);

    //�������, �������
    defaultDeleteChange.setBaseText("Hello. Hello. Hello...");
    defaultDeleteChange.setInputText("hi, hi");
    defaultDeleteChange.setPositionEditedSubstring(2);
    defaultDeleteChange.setSecondPosEditSubStr(8);
    assert(defaultDeleteChange.getBaseText() == "Hello. Hello. Hello...");
    assert(defaultDeleteChange.getInputText() == "hi, hi");
    assert(defaultDeleteChange.getPositionEditedSubstring() == 2);
    assert(defaultDeleteChange.getSecondPosEditSubStr() == 8);
    cout << "Getters and setters test passed." << endl << endl;

    //�������� ������: �������� ��������� ��������� � �������� ������
    assert(defaultDeleteChange.deleteFragment("Hello, Hello", 0, 4) == "o, Hello");
    cout << "The first test is passed." << endl;
    assert(defaultDeleteChange.deleteFragment("Hello, Hello...", 6, 10) == "Hello,lo...");
    cout << "The second test is passed." << endl;
    assert(defaultDeleteChange.deleteFragment("Hello, Hello", 9, 900) == "Hello, He");
    cout << "The third test is passed." << endl;
    
    //�������� ������: ������ ��������� ��������� � �������� ������
    assert(defaultDeleteChange.changeFragment("hi, hi, hi...", "Dima", 0, 1) == "Dimai, hi, hi...");
    cout << "The fourth test is passed." << endl;
    assert(defaultDeleteChange.changeFragment("hi, hi, hi...", "Dima", 5, 10) == "hi, hDima...");
    cout << "The fifth test is passed." << endl;
    assert(defaultDeleteChange.changeFragment("hi, hi, hi...", "Dima", 2, 10000) == "hiDima");
    cout << "The sixth test is passed." << endl;

    //�������� ������ �������� ������ �� ������������
    assert(defaultDeleteChange.pasteFragment("Hello, Hello", "Hey, hey. ", 0) == "Hey, hey. Hello, Hello");
    cout << "The seventh test is passed." << endl;
    assert(defaultDeleteChange.pasteFragment("Hello, Hello", "Hey, hey. ", 15) == "Hello, HelloHey, hey. ");
    cout << "The eighth test is passed." << endl;
    assert(defaultDeleteChange.pasteFragment("Hello, Hello", "Hey, hey. ", 11) == "Hello, HellHey, hey. o");
    cout << "The ninth test is passed." << endl;
    
    return 0;
}