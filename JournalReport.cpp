#include "JournalReport.h"

JournalReport::JournalReport():
    timeHour(0),
    timeMinutes(0),
    name(0),
    position(0),
    academicDegree(0),
    influence(0) {}

JournalReport::JournalReport(const int &timeHour, const int &timeMinutes, const std::string &name, const std::string &position, const std::string &academicDegree, const int &influence) :
    timeHour(timeHour),
    timeMinutes(timeMinutes),
    name(name),
    position(position),
    academicDegree(academicDegree),
    influence(influence) {}

    JournalReport::JournalReport(const JournalReport &other):
        timeHour(other.timeHour),
        timeMinutes(other.timeMinutes),
        name(other.name),
        position(other.position),
        academicDegree(other.academicDegree),
        influence(other.influence) {}

    const int JournalReport::getTimeHour() const {
	    return timeHour;
    }
    const int JournalReport::getTimeMinutes() const {
	    return timeMinutes;
    }
    const std::string JournalReport::getName() const {
	    return name;
    }
    const std::string JournalReport::getPosition() const {
	    return position;
    }
    const std::string JournalReport::getAcademicDegree() const {
	    return academicDegree;
    }
    const int JournalReport::getInfluence() const {
	    return influence;
    }

    void JournalReport::setTimeHour(const int &x) {
	    JournalReport::timeHour = x;
    }
    void JournalReport::setTimeMinutes(const int &x) {
	    JournalReport::timeMinutes = x;
    }
    void JournalReport::setName(const std::string &x) {
	    JournalReport::name = x;
    }
    void JournalReport::setPosition(const std::string &x) {
	    JournalReport::position = x;
    }
    void JournalReport::setAcademicDegree(const std::string &x) {
	    JournalReport::academicDegree = x;
    }
    void JournalReport::setInfluence(const int &x) {
	    JournalReport::influence = x;
    }