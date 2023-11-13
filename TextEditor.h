#include <DeleteChange.h>
#include <iostream>
#include <stack>
#include <stdexcept>

using namespace std;

class TextEditor {
public:
    //Конструктор
    TextEditor() = default;
    TextEditor(const DeleteChange& object);
    TextEditor(TextEditor& textEditor) = default;

    //Метод добавления правки в стек
    void add(const DeleteChange& object);

    //Метод отмены операции
    void undo();

    //Метод восстановления операции
    void redo();

    //Проверки на пустой стек
    bool isEmptyUndoStack();
    bool isEmptyRedoStack();

    //Геттеры: получение последнего элемента стека
    DeleteChange getTopUndo() const;
    DeleteChange getTopRedo() const;

    //Геттеры: получение кол-ва элементов стека
    unsigned long long getCountUndo() const;
    unsigned long long getCountRedo() const;
    //Вывод стека
    /*void showUndo();
    void showRedo();*/

private:
    //Стек для отмены операций
    stack<DeleteChange> undoStack;
    //Стек для восстановления операций
    stack<DeleteChange> redoStack;
};

TextEditor::TextEditor(const DeleteChange& object) {
    undoStack.push(object);
    redoStack.push(object);
}

void TextEditor::add(const DeleteChange& object) {
    if (undoStack.size() < redoStack.size()) {
        redoStack.pop();
        undoStack.push(object);
        redoStack.push(object);
    }
    else if (undoStack.size() == redoStack.size()) {
        undoStack.push(object);
        redoStack.push(object);
    }
}

void TextEditor::undo() {
    if (!undoStack.empty() && !redoStack.empty()) {
        if (undoStack.size() < redoStack.size()) {
            undoStack.pop();
            redoStack.pop();
        }
        else if (undoStack.size() == redoStack.size()) {
            undoStack.pop();
        }
    }
}

void TextEditor::redo() {
    if (!redoStack.empty() && undoStack.size() < redoStack.size()) {
        undoStack.push(redoStack.top());
    }
}

bool TextEditor::isEmptyUndoStack() {
    return undoStack.empty();
}

bool TextEditor::isEmptyRedoStack() {
    return redoStack.empty();
}

DeleteChange TextEditor::getTopUndo() const {
    return undoStack.top();
}

DeleteChange TextEditor::getTopRedo() const {
    return redoStack.top();
}

unsigned long long TextEditor::getCountUndo() const {
    return undoStack.size();
}

unsigned long long TextEditor::getCountRedo() const {
    return redoStack.size();
}