#include "AddFragment.h"
#include <iostream>
#include <stdexcept>
#include <string>

//����������� �����
class DeleteChange: public AddFragment {
public:
	//������������ �� ���������, �������������, �����������
	DeleteChange();
	DeleteChange(string baseText, string inputText, int positionEditedSubstring,
		int secondPositionEditedSubstring);
	DeleteChange(const DeleteChange& delChan);
	
	//�-�� �������������
	string identify() const override;
	//�������, �������
	int getSecondPosEditSubStr() const;
	void setSecondPosEditSubStr(int secondPositionEditedSubstring);
	
	//�����: �������� ��������� ��������� � �������� ������
	string deleteFragment(string baseText, int positionEditedSubstring, 
		int secondPositionEditedSubstring);
	
	//�����: ��������� ��������� � �������� ������
	string changeFragment(string baseText, string inputText, 
		int positionEditedSubstring, int secondPositionEditedSubstring);

private:
	int m_secondPositionEditedSubstring;
};

string DeleteChange::identify() const {
	return "DeleteChange";
}

DeleteChange::DeleteChange() : AddFragment() {
	m_secondPositionEditedSubstring = 0;
}

DeleteChange::DeleteChange(string baseText, string inputText, int positionEditedSubstring, 
	int secondPositionEditedSubstring): AddFragment(baseText, inputText, positionEditedSubstring) {
	if (secondPositionEditedSubstring >= 0) {
		m_secondPositionEditedSubstring = secondPositionEditedSubstring;
	}
	else {
		throw invalid_argument("The substring number cannot be negative.");
	}
}

DeleteChange::DeleteChange(const DeleteChange& delChan) : AddFragment(delChan) {
	m_secondPositionEditedSubstring = delChan.m_secondPositionEditedSubstring;
}

int DeleteChange::getSecondPosEditSubStr() const {
	return m_secondPositionEditedSubstring;
}

void DeleteChange::setSecondPosEditSubStr(int secondPositionEditedSubstring) {
	m_secondPositionEditedSubstring = secondPositionEditedSubstring;
}

string DeleteChange::deleteFragment(string baseText, int positionEditedSubstring, 
	int secondPositionEditedSubstring) {
	//������� � ������ �������� ��������� � ������� ���� ������� (��������� � ��������)
	if (secondPositionEditedSubstring <= baseText.size() - 1 &&
		positionEditedSubstring < secondPositionEditedSubstring) {
		baseText.replace(positionEditedSubstring, secondPositionEditedSubstring - positionEditedSubstring, "");
		return baseText;
	}
	else if (secondPositionEditedSubstring > baseText.size() - 1 && 
		positionEditedSubstring < baseText.size() - 1) {
		baseText.replace(positionEditedSubstring, baseText.size() - positionEditedSubstring, "");
		return baseText;
	}
	else {
		throw invalid_argument("The second position cannot equal or be higher than the first position.");
	}
}

string DeleteChange::changeFragment(string baseText, string inputText,
	int positionEditedSubstring, int secondPositionEditedSubstring) {
	//�������� � ������ �������� ��������� �� ��������� � ������� ���� ������� (��������� � ��������)
	if (secondPositionEditedSubstring <= baseText.size() - 1 &&
		positionEditedSubstring < secondPositionEditedSubstring) {
		baseText.replace(positionEditedSubstring, secondPositionEditedSubstring - positionEditedSubstring, inputText);
		return baseText;
	}
	else if (secondPositionEditedSubstring > baseText.size() - 1 &&
		positionEditedSubstring < baseText.size() - 1) {
		baseText.replace(positionEditedSubstring, baseText.size() - positionEditedSubstring, inputText);
		return baseText;
	}
	else {
		throw invalid_argument("The second position cannot equal or be higher than the first position.");
	}
}