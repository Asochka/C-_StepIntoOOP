#include "test.h"

void JournalReportConstructorTest() {

	JournalReport journal0{};
	assert(journal0.getTimeHour() == 0);
	assert(journal0.getTimeMinutes() == 0);
	assert(journal0.getName() == "");
	assert(journal0.getPosition() == "");
	assert(journal0.getAcademicDegree() == "");
    assert(journal0.getInfluence() == 0);

	JournalReport journal1{10, 23, "Fadeeva Anastasia Andreevna", "student", "noacademicdegree", 6};
	int timeHour1 = 10;
    int timeMinutes1 = 23;
    std::string name1 = "Fadeeva Anastasia Andreevna";
    std::string position1 = "student";
    std::string academicDegree1 = "noacademicdegree";
    int influence1 = 6;
	assert(journal1.getTimeHour() == timeHour1);
	assert(journal1.getTimeMinutes() == timeMinutes1);
	assert(journal1.getName() == name1);
	assert(journal1.getPosition() == position1);
	assert(journal1.getAcademicDegree() == academicDegree1);
    assert(journal1.getInfluence() == influence1);

	JournalReport journal2{journal1};
	assert(journal1.getTimeHour() == journal2.getTimeHour());
	assert(journal1.getTimeMinutes() == journal2.getTimeMinutes());
	assert(journal1.getName() == journal2.getName());
	assert(journal1.getPosition() == journal2.getPosition());
	assert(journal1.getAcademicDegree() == journal2.getAcademicDegree());
    assert(journal1.getInfluence() == journal2.getInfluence());
	std::cout << "OK!" << std::endl;
}

void JournalReportTest() {
	JournalReport journal3{};
	int timeHour3 = 10;
    int timeMinutes3 = 23;
    std::string name3 = "Fadeeva Anastasia Andreevna";
    std::string position3 = "student";
    std::string academicDegree3 = "noacademicdegree";
    int influence3 = 6;
	journal3.setTimeHour(timeHour3);
	journal3.setTimeMinutes(timeMinutes3);
	journal3.setName(name3);
	journal3.setPosition(position3);
	journal3.setAcademicDegree(academicDegree3);
    journal3.setInfluence(influence3);
	assert(journal3.getTimeHour() == timeHour3);
	assert(journal3.getTimeMinutes() == timeMinutes3);
	assert(journal3.getName() == name3);
	assert(journal3.getPosition() == position3);
	assert(journal3.getAcademicDegree() == academicDegree3);
    assert(journal3.getInfluence() == influence3);
	std::cout << "OK!" << std::endl;
}