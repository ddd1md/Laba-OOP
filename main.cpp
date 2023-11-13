#include <iostream>
#include <cassert>
#include "TextEditor.h"

int main() {
    cout << "---Tests for the first lab---" << endl;
    //По умолчанию
    AddFragment defaultAddFragment;
    assert(defaultAddFragment.getBaseText().empty());
    assert(defaultAddFragment.getInputText().empty());
    assert(defaultAddFragment.getPositionEditedSubstring() == 0);
    cout << "The default constructor test is passed." << endl;

    //Инициализация
    AddFragment initedAddFragment("Hello, world! My name is Dima.", "Hi, hi, hi", 5);
    assert(initedAddFragment.getBaseText() == "Hello, world! My name is Dima.");
    assert(initedAddFragment.getInputText() == "Hi, hi, hi");
    assert(initedAddFragment.getPositionEditedSubstring() == 5);
    cout << "Initialization constructor test passed." << endl;

    //Копирование
    AddFragment copiedAddFragment(initedAddFragment);
    assert(copiedAddFragment.getBaseText() == "Hello, world! My name is Dima.");
    assert(copiedAddFragment.getInputText() == "Hi, hi, hi");
    assert(copiedAddFragment.getPositionEditedSubstring() == 5);
    cout << "The copy constructor test has been passed." << endl;

    //Метод идентификации
    assert(defaultAddFragment.identify() == "AddFragment");

    //Геттеры, сеттеры
    defaultAddFragment.setBaseText("Hello. Hello. Hello...");
    defaultAddFragment.setInputText("hi, hi");
    defaultAddFragment.setPositionEditedSubstring(2);
    assert(defaultAddFragment.getBaseText() == "Hello. Hello. Hello...");
    assert(defaultAddFragment.getInputText() == "hi, hi");
    assert(defaultAddFragment.getPositionEditedSubstring() == 2);
    cout << "Getters and setters test passed." << endl << endl;

    //Проверка метода: вставка введенной строки в исходный текст в назначенное место
    assert(defaultAddFragment.pasteFragment("Hello, Hello", "Hey, hey. ", 0) == "Hey, hey. Hello, Hello");
    cout << "The first test is passed." << endl;
    assert(defaultAddFragment.pasteFragment("Hello, Hello", "Hey, hey. ", 15) == "Hello, HelloHey, hey. ");
    cout << "The second test is passed." << endl;
    assert(defaultAddFragment.pasteFragment("Hello, Hello", "Hey, hey. ", 11) == "Hello, HellHey, hey. o");
    cout << "The third test is passed." << endl;

    cout << endl << "---Tests for the second lab---" << endl;
    //По умолчанию
    DeleteChange defaultDeleteChange;
    
    assert(defaultDeleteChange.getSecondPosEditSubStr() == 0);
    assert(defaultDeleteChange.getBaseText().empty());
    assert(defaultDeleteChange.getInputText().empty());
    assert(defaultDeleteChange.getPositionEditedSubstring() == 0);
    cout << "The default constructor test is passed." << endl;

    //Инициализация
    DeleteChange initedDeleteChange("Hello, world! My name is Dima.", "Hi, hi, hi", 5, 10);
    assert(initedDeleteChange.getBaseText() == "Hello, world! My name is Dima.");
    assert(initedDeleteChange.getInputText() == "Hi, hi, hi");
    assert(initedDeleteChange.getPositionEditedSubstring() == 5);
    assert(initedDeleteChange.getSecondPosEditSubStr() == 10);
    cout << "Initialization constructor test passed." << endl;

    //Копирование
    DeleteChange copiedDeleteChange(initedDeleteChange);
    assert(copiedDeleteChange.getBaseText() == "Hello, world! My name is Dima.");
    assert(copiedDeleteChange.getInputText() == "Hi, hi, hi");
    assert(copiedDeleteChange.getPositionEditedSubstring() == 5);
    assert(copiedDeleteChange.getSecondPosEditSubStr() == 10);
    cout << "The copy constructor test has been passed." << endl;

    //Метод идентификации
    assert(defaultDeleteChange.identify() == "DeleteChange");

    //Геттеры, сеттеры
    defaultDeleteChange.setBaseText("Hello. Hello. Hello...");
    defaultDeleteChange.setInputText("hi, hi");
    defaultDeleteChange.setPositionEditedSubstring(2);
    defaultDeleteChange.setSecondPosEditSubStr(8);
    assert(defaultDeleteChange.getBaseText() == "Hello. Hello. Hello...");
    assert(defaultDeleteChange.getInputText() == "hi, hi");
    assert(defaultDeleteChange.getPositionEditedSubstring() == 2);
    assert(defaultDeleteChange.getSecondPosEditSubStr() == 8);
    cout << "Getters and setters test passed." << endl << endl;

    //Проверка метода: удаление заданного фрагмента в исходном тексте
    assert(defaultDeleteChange.deleteFragment("Hello, Hello", 0, 4) == "o, Hello");
    cout << "The first test is passed." << endl;
    assert(defaultDeleteChange.deleteFragment("Hello, Hello...", 6, 10) == "Hello,lo...");
    cout << "The second test is passed." << endl;
    assert(defaultDeleteChange.deleteFragment("Hello, Hello", 9, 900) == "Hello, He");
    cout << "The third test is passed." << endl;
    
    //Проверка метода: замена заданного фрагмента в исходном тексте
    assert(defaultDeleteChange.changeFragment("hi, hi, hi...", "Dima", 0, 1) == "Dimai, hi, hi...");
    cout << "The fourth test is passed." << endl;
    assert(defaultDeleteChange.changeFragment("hi, hi, hi...", "Dima", 5, 10) == "hi, hDima...");
    cout << "The fifth test is passed." << endl;
    assert(defaultDeleteChange.changeFragment("hi, hi, hi...", "Dima", 2, 10000) == "hiDima");
    cout << "The sixth test is passed." << endl;

    //Проверка метода базового класса из производного
    assert(defaultDeleteChange.pasteFragment("Hello, Hello", "Hey, hey. ", 0) == "Hey, hey. Hello, Hello");
    cout << "The seventh test is passed." << endl;
    assert(defaultDeleteChange.pasteFragment("Hello, Hello", "Hey, hey. ", 15) == "Hello, HelloHey, hey. ");
    cout << "The eighth test is passed." << endl;
    assert(defaultDeleteChange.pasteFragment("Hello, Hello", "Hey, hey. ", 11) == "Hello, HellHey, hey. o");
    cout << "The ninth test is passed." << endl;

    //Проверки класса: хранение истории правок
    cout << endl << "---Tests for the third lab---" << endl;

    TextEditor defaultTextEditor;

    DeleteChange exampleDeleteChange1;
    exampleDeleteChange1.setBaseText("Hello. Hello. Hello...");
    exampleDeleteChange1.setInputText("hi, hi");
    exampleDeleteChange1.setPositionEditedSubstring(2);
    exampleDeleteChange1.setSecondPosEditSubStr(8);

    DeleteChange exampleDeleteChange2;
    exampleDeleteChange1.setBaseText("I'm Dmitry");
    exampleDeleteChange1.setInputText("Hello");
    exampleDeleteChange1.setPositionEditedSubstring(0);
    exampleDeleteChange1.setSecondPosEditSubStr(2);

    DeleteChange exampleDeleteChange3;
    exampleDeleteChange1.setBaseText("Bye. New;.");
    exampleDeleteChange1.setInputText("Wow");
    exampleDeleteChange1.setPositionEditedSubstring(4);
    exampleDeleteChange1.setSecondPosEditSubStr(6);

    assert(defaultTextEditor.isEmptyUndoStack() == true);
    assert(defaultTextEditor.isEmptyRedoStack() == true);
    cout << "Empty stack checks passed." << endl;

    //Проверка метода add
    defaultTextEditor.add(exampleDeleteChange1);
    defaultTextEditor.add(exampleDeleteChange2);
    defaultTextEditor.add(exampleDeleteChange3);
    assert(defaultTextEditor.isEmptyUndoStack() == false);

    assert(defaultTextEditor.getCountUndo() == 3);
    assert(defaultTextEditor.getCountRedo() == 3);
    cout << "The first test for the add method has been passed." << endl;

    //Провека метода undo
    defaultTextEditor.undo();

    assert(defaultTextEditor.getTopUndo().getBaseText() == exampleDeleteChange2.getBaseText());
    assert(defaultTextEditor.getTopUndo().getInputText() == exampleDeleteChange2.getInputText());
    assert(defaultTextEditor.getTopUndo().getPositionEditedSubstring() == exampleDeleteChange2.getPositionEditedSubstring());
    assert(defaultTextEditor.getTopUndo().getSecondPosEditSubStr() == exampleDeleteChange2.getSecondPosEditSubStr());

    assert(defaultTextEditor.getTopRedo().getBaseText() == exampleDeleteChange3.getBaseText());
    assert(defaultTextEditor.getTopRedo().getInputText() == exampleDeleteChange3.getInputText());
    assert(defaultTextEditor.getTopRedo().getPositionEditedSubstring() == exampleDeleteChange3.getPositionEditedSubstring());
    assert(defaultTextEditor.getTopRedo().getSecondPosEditSubStr() == exampleDeleteChange3.getSecondPosEditSubStr());

    assert(defaultTextEditor.getCountUndo() == 2);
    assert(defaultTextEditor.getCountRedo() == 3);

    cout << "The second test for the undo method has been passed." << endl;

    //Проверка метода add при разнице в размере стеках
    defaultTextEditor.add(exampleDeleteChange1);
    assert(defaultTextEditor.getTopUndo().getBaseText() == exampleDeleteChange1.getBaseText());
    assert(defaultTextEditor.getTopUndo().getInputText() == exampleDeleteChange1.getInputText());
    assert(defaultTextEditor.getTopUndo().getPositionEditedSubstring() == exampleDeleteChange1.getPositionEditedSubstring());
    assert(defaultTextEditor.getTopUndo().getSecondPosEditSubStr() == exampleDeleteChange1.getSecondPosEditSubStr());

    assert(defaultTextEditor.getTopRedo().getBaseText() == exampleDeleteChange1.getBaseText());
    assert(defaultTextEditor.getTopRedo().getInputText() == exampleDeleteChange1.getInputText());
    assert(defaultTextEditor.getTopRedo().getPositionEditedSubstring() == exampleDeleteChange1.getPositionEditedSubstring());
    assert(defaultTextEditor.getTopRedo().getSecondPosEditSubStr() == exampleDeleteChange1.getSecondPosEditSubStr());

    assert(defaultTextEditor.getCountUndo() == 3);
    assert(defaultTextEditor.getCountRedo() == 3);

    cout << "The second test for the add method has been passed." << endl;

    //Проверка метода redo

    defaultTextEditor.undo();
    defaultTextEditor.undo();

    defaultTextEditor.redo();

    assert(defaultTextEditor.getTopUndo().getBaseText() == exampleDeleteChange2.getBaseText());
    assert(defaultTextEditor.getTopUndo().getInputText() == exampleDeleteChange2.getInputText());
    assert(defaultTextEditor.getTopUndo().getPositionEditedSubstring() == exampleDeleteChange2.getPositionEditedSubstring());
    assert(defaultTextEditor.getTopUndo().getSecondPosEditSubStr() == exampleDeleteChange2.getSecondPosEditSubStr());

    assert(defaultTextEditor.getTopRedo().getBaseText() == exampleDeleteChange2.getBaseText());
    assert(defaultTextEditor.getTopRedo().getInputText() == exampleDeleteChange2.getInputText());
    assert(defaultTextEditor.getTopRedo().getPositionEditedSubstring() == exampleDeleteChange2.getPositionEditedSubstring());
    assert(defaultTextEditor.getTopRedo().getSecondPosEditSubStr() == exampleDeleteChange2.getSecondPosEditSubStr());

    assert(defaultTextEditor.getCountUndo() == 2);
    assert(defaultTextEditor.getCountRedo() == 2);

    cout << "The test for the redo method has been passed." << endl;
    cout << "Tests for 3 labs have been successfully passed." << endl;
    return 0;
}