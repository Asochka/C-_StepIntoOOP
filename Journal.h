#ifndef JOURNAL_H
#define JOURNAL_H
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

#define DEFAULT_INT 0
#define DEFAULT_STR ""
#define PATH "D:/Users/User/Documents/STUDY/ооп/laba_1/laba1_FAA_v12/file.txt"

class Journal {
public:
	class JournalReport {
	public:
    	JournalReport();
		JournalReport (const int &timeHour, const int &timeMinutes, const std::string &name, const std::string &position, const std::string &academicDegree, const int &influence);
		JournalReport (const JournalReport &other);

		void setTimeHour(const int &value);
		void setTimeMinutes(const int &value);
		void setName(const std::string &value);
		void setPosition(const std::string &value);
		void setAcademicDegree(const std::string &value);
		void setInfluence(const int &value);

		const int getTimeHour() const;
		const int getTimeMinutes() const;
		const std::string getName() const;
		const std::string getPosition() const;
		const std::string getAcademicDegree() const;
		const int getInfluence() const;

	private:
		int timeHour;
		int timeMinutes;
		std::string name;
		std::string position;
		std::string academicDegree;
		int influence;
	};
	Journal();
	Journal(const int &timeHour, const int &timeMinutes, const std::string &name, const std::string &position, const std::string &academicDegree, const int &influence, const int &capacity);
	Journal(const Journal &other);
	~Journal();

	int getCapacity(int pos) const;
	void setCapacity(int pos, int capacity);

	bool checkOnCorrect() const;
	void addNewElement(int posAfter, const JournalReport &element, int capacity);
	JournalReport popElement(int index);
	void disposeAll();
	int numberOfElements() const;

	bool compareArray(Journal array2) const;
	void printArray() const;

	void writeInFile() const;
	void readFromFile();

private:  
	struct node
    {
        int capacity;
        JournalReport info;
        node *prev, *next;
    };
    node *first;
};

#endif