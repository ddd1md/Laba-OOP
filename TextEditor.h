#include <DeleteChange.h>
#include <iostream>
#include <stack>
#include <stdexcept>

using namespace std;

class TextEditor {
public:
    //�����������
    TextEditor() = default;
    TextEditor(const DeleteChange& object);
    TextEditor(TextEditor& textEditor) = default;

    //����� ���������� ������ � ����
    void add(const DeleteChange& object);

    //����� ������ ��������
    void undo();

    //����� �������������� ��������
    void redo();

    //�������� �� ������ ����
    bool isEmptyUndoStack();
    bool isEmptyRedoStack();

    //�������: ��������� ���������� �������� �����
    DeleteChange getTopUndo() const;
    DeleteChange getTopRedo() const;

    //�������: ��������� ���-�� ��������� �����
    unsigned long long getCountUndo() const;
    unsigned long long getCountRedo() const;
    //����� �����
    /*void showUndo();
    void showRedo();*/

private:
    //���� ��� ������ ��������
    stack<DeleteChange> undoStack;
    //���� ��� �������������� ��������
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