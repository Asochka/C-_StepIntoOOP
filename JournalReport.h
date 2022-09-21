#ifndef JOURNALREPORT_H
#define JOURNALREPORT_H
#include <string>

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
#endif