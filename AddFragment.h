#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

//������� �����
class AddFragment {
public:
    //������������ �� ���������, �������������, �����������
    AddFragment();
    AddFragment(string baseText, string inputText, int positionEditedSubstring);
    AddFragment(const AddFragment& fragment);

    //�-�� �������������
    virtual bool isDeleteChange();
    //�������, �������
    string getBaseText() const;
    void setBaseText(string baseText);
    string getInputText() const;
    void setInputText(string inputText);
    int getPositionEditedSubstring() const;
    void setPositionEditedSubstring(int positionEditedSubstring);
    //�����: ������� ��������� ������ � �������� ����� � ����������� �����
    string pasteFragment(string baseText, string inputText, int positionEditedSubstring);

protected:
    string m_baseText;
    string m_inputText;
    int m_positionEditedSubstring;
};

bool AddFragment::isDeleteChange() {
    return false;
}

AddFragment::AddFragment() {
    m_baseText = "";
    m_inputText = "";
    m_positionEditedSubstring = 0;
}

AddFragment::AddFragment(string baseText, string inputText, int positionEditedSubstring) {
    m_baseText = baseText;
    m_inputText = inputText;

    if (positionEditedSubstring >= 0) {
        m_positionEditedSubstring = positionEditedSubstring;
    }
    else {
        cout << "The substring number cannot be negative.";
        throw invalid_argument("The substring number cannot be negative.");
    }
}

AddFragment::AddFragment(const AddFragment& fragment) {
    m_baseText = fragment.m_baseText;
    m_inputText = fragment.m_inputText;
    m_positionEditedSubstring = fragment.m_positionEditedSubstring;
}

string AddFragment::getBaseText() const {
    return m_baseText;
}

void AddFragment::setBaseText(string baseText) {
    m_baseText = baseText;
}

string AddFragment::getInputText() const {
    return m_inputText;
}

void AddFragment::setInputText(string inputText) {
    m_inputText = inputText;
}

int AddFragment::getPositionEditedSubstring() const {
    return m_positionEditedSubstring;
}

void AddFragment::setPositionEditedSubstring(int positionEditedSubstring) {
    m_positionEditedSubstring = positionEditedSubstring;
}

string AddFragment::pasteFragment(string baseText, string inputText, int positionEditedSubstring) {
    //���� �������� ������� ��� ������� ������ ����� �������� ������, �� ��������� ���������
    //����������� � ����� ��������� ������
    if (positionEditedSubstring <= baseText.size() - 1) {
        baseText.insert(positionEditedSubstring, inputText);
        return baseText;
    }
    else {
        baseText.append(inputText);
        return baseText;
    }
}