#include "Journal.h"

Journal::JournalReport::JournalReport() {
    influence = timeHour = timeMinutes = DEFAULT_INT;
    position = name = academicDegree = DEFAULT_STR;
}

Journal::JournalReport::JournalReport(const int &timeHour, const int &timeMinutes, const std::string &name, const std::string &position, const std::string &academicDegree, const int &influence) {
    if (timeHour >= 0 && timeHour <= 24)
        this->timeHour = timeHour;
    else
        throw invalid_argument("timeHour < 0 or timeHour > 24");

    if (timeMinutes >= 0 && timeMinutes <= 60)
        this->timeMinutes = timeMinutes;
    else
        throw invalid_argument("timeMinutes < 0 or timeMinutes > 60");

    this->position = position;
    this->name = name;
    this->academicDegree = academicDegree;
    this->influence = influence;
}

Journal::JournalReport::JournalReport(const JournalReport &other) {
    this->timeHour = other.timeHour;
    this->timeMinutes = other.timeMinutes;
    this->position = other.position;
    this->name = other.name;
    this->academicDegree = other.academicDegree;
    this->influence = other.influence;
}

const int Journal::JournalReport::getTimeHour() const {
    return timeHour;
}

void Journal::JournalReport::setTimeHour(const int &timeHour) {
    if (timeHour >= 0 && timeHour <= 24)
        this->timeHour = timeHour;
    else
        throw invalid_argument("timeHour < 0 or timeHour > 24");
}

const int Journal::JournalReport::getTimeMinutes() const {
    return timeMinutes;
}

void Journal::JournalReport::setTimeMinutes(const int &timeMinutes) {
    if (timeMinutes >= 0 && timeMinutes <= 60)
        this->timeMinutes = timeMinutes;
    else
        throw invalid_argument("timeMinutes < 0 or timeMinutes > 60");
}

const string Journal::JournalReport::getPosition() const {
    return position;
}

void Journal::JournalReport::setPosition(const string &position) {
    this->position = position;
}

const string Journal::JournalReport::getName() const {
    return name;
}

void Journal::JournalReport::setName(const string &name) {
    this->name = name;
}

const string Journal::JournalReport::getAcademicDegree() const {
    return academicDegree;
}

void Journal::JournalReport::setAcademicDegree(const string &secondName) {
    this->academicDegree = academicDegree;
}

const int Journal::JournalReport::getInfluence() const {
    return influence;
}

void Journal::JournalReport::setInfluence(const int &influence) {
    this->influence = influence;
}

Journal::Journal() {
    first = new node;
    first->prev = nullptr;
    first->next = nullptr;
    first->capacity = DEFAULT_INT;
    first->info.setTimeHour(DEFAULT_INT);
    first->info.setTimeMinutes(DEFAULT_INT);
    first->info.setInfluence(DEFAULT_INT);
    first->info.setPosition(DEFAULT_STR);
    first->info.setName(DEFAULT_STR);
    first->info.setAcademicDegree(DEFAULT_STR);
}
Journal::Journal(const int &timeHour, const int &timeMinutes, const std::string &name, const std::string &position, const std::string &academicDegree, const int &influence, const int &capacity) {
	if (capacity > 0) {
        first = new node;
         first->prev = nullptr;
         first->next = nullptr;
         first->capacity = capacity;
         first->info.setTimeHour(timeHour);
         first->info.setTimeMinutes(timeMinutes);
         first->info.setInfluence(influence);
         first->info.setPosition(position);
         first->info.setName(name);
         first->info.setAcademicDegree(academicDegree);
    }
    else
        throw invalid_argument("capacity <= 0");
}

Journal::Journal(const Journal &other) {
    node *oth = other.first, *now, *cont;
    first = new node;
    cont = now = first;
    now->prev = nullptr;
    now->next = nullptr;
    while (oth != nullptr)
    {
        now = cont;
        cont = new node;
        cont->prev = now;
        cont->next = nullptr;
        now->next = cont;
        now->capacity = oth->capacity;
        now->info.setTimeHour(oth->info.getTimeHour());
        now->info.setTimeMinutes(oth->info.getTimeMinutes());
        now->info.setInfluence(oth->info.getInfluence());
        now->info.setPosition(oth->info.getPosition());
        now->info.setName(oth->info.getName());
        now->info.setAcademicDegree(oth->info.getAcademicDegree());
        oth = oth->next;
    }
    now->next = nullptr;
    delete cont;
}
Journal::~Journal() {
    node *now = first, *cont;
    while (now != nullptr)
    {
        cont = now->next;
        delete now;
        now = cont;
    }
}

int Journal::getCapacity(int pos) const {
    node *point = first;
    for (int i = 0; i < pos && point != nullptr; ++i, point = point->next);
    if (point == nullptr) throw invalid_argument("index out of range");
    return point->capacity;
}

void Journal::setCapacity(int pos, int capacity) {
    if (capacity > 0) {
        node *point = first;
        for (int i = 0; i < pos && point != nullptr; ++i, point = point->next);
        if (point == nullptr) throw invalid_argument("index out of range");
        point->capacity = capacity;
    }
    else
        throw invalid_argument("capacity <= 0");
}

bool Journal::checkOnCorrect() const {
    bool flag = true;
    node *now = first;
    while (now != nullptr)
    {
        if (abs(now->info.getInfluence()) >= now->capacity)
            flag = false;
        now = now->next;
    }
    return flag;
}

void Journal::addNewElement(int posAfter, const JournalReport &element, int capacity) {
    node *after = first, *now;
    for (int i = 0; i < posAfter && after != nullptr; ++i, after = after->next);
    if (after == nullptr) throw invalid_argument("index out of range");
    now = new node;
    now->prev = after;
    now->next = after->next;
    if (after->next != nullptr) after->next->prev = now;
    after->next = now;

    now->capacity = capacity;
    now->info.setTimeHour(element.getTimeHour());
    now->info.setTimeMinutes(element.getTimeMinutes());
    now->info.setInfluence(element.getInfluence());
    now->info.setPosition(element.getPosition());
    now->info.setName(element.getName());
    now->info.setAcademicDegree(element.getAcademicDegree());
}

Journal::JournalReport Journal::popElement(int index) {
    node *forDel = first;
    JournalReport ret;
    for (int i = 0; i < index && forDel != nullptr; ++i, forDel = forDel->next);
    if (forDel == nullptr) throw invalid_argument("index out of range");

    if (forDel->prev != nullptr)
		forDel->prev->next = forDel->next;
    if (forDel->next != nullptr)
		forDel->next->prev = forDel->prev;
    ret = forDel->info;
    if (index == 0)
		first = forDel->next;
    delete forDel;
    return ret;
}

void Journal::disposeAll() {
    node *now = first, *cont;

    while (now != nullptr) {
        cont = now->next;
        delete now;
        now = cont;
    }
    first = nullptr;
    first = new node;
    first->prev = nullptr;
    first->next = nullptr;
    first->capacity = DEFAULT_INT;
    first->info.setTimeHour(DEFAULT_INT);
    first->info.setTimeMinutes(DEFAULT_INT);
    first->info.setInfluence(DEFAULT_INT);
    first->info.setPosition(DEFAULT_STR);
    first->info.setName(DEFAULT_STR);
    first->info.setAcademicDegree(DEFAULT_STR);
}

int Journal::numberOfElements() const {
    node *now = first;
    int i;
    for (i = 0; now != nullptr; ++i, now = now->next);
    return i;
}

bool Journal::compareArray(Journal array2) const {
    bool flag = true;
    node *fir1 = first, *fir2 = array2.first;
    while (fir1 != nullptr && fir2 != nullptr) {
        if (fir1->info.getTimeHour() != fir2->info.getTimeHour()) flag = false;
        if (fir1->info.getTimeMinutes() != fir2->info.getTimeMinutes()) flag = false;
        if (fir1->info.getInfluence() != fir2->info.getInfluence()) flag = false;
        if (fir1->info.getPosition() != fir2->info.getPosition()) flag = false;
        if (fir1->info.getName() != fir2->info.getName()) flag = false;
        if (fir1->info.getAcademicDegree() != fir2->info.getAcademicDegree()) flag = false;
        if (flag == false) break;
        fir1 = fir1->next;
        fir2 = fir2->next;
    }
    if (fir1 == nullptr && fir2 != nullptr) flag = false;
    if (fir1 != nullptr && fir2 == nullptr) flag = false;
    return flag;
}

void Journal::printArray() const {
    node *now = first;
    while (now != nullptr) {
        cout << now->info.getTimeHour() << ":" << now->info.getTimeMinutes() << endl;
        cout << now->info.getName() << " " << now->info.getPosition() << " " << now->info.getAcademicDegree() << endl;
        cout << "Influence: " << now->info.getInfluence() << endl;
        cout << "capacity: " << now->capacity << endl << endl;
        now = now->next;
    }
}

void Journal::writeInFile() const {
    node *now = first;
    ofstream fileOut;
    fileOut.open(PATH);

    while (now != nullptr) {
        fileOut << now->info.getTimeHour() << "\n";
        fileOut << now->info.getTimeMinutes() << "\n";
        fileOut << now->info.getPosition() << "\n";
        fileOut << now->info.getName() << "\n";
        fileOut << now->info.getAcademicDegree() << "\n";
        fileOut << now->info.getInfluence() << "\n" << now->capacity << "\n";
        now = now->next;
    }
    fileOut.close();
}

void Journal::readFromFile() {
    node *now, *cont;
    string tempStr;
    int tempInt;
    ifstream fileIn;
    fileIn.open(PATH);

    if (fileIn.is_open()) {
        this->disposeAll();
        cont = now = first;
        while (!fileIn.eof()) {
            now = cont;
            cont = new node;
            cont->prev = now;
            cont->next = nullptr;
            now->next = cont;
            fileIn >> tempInt;
            now->info.setTimeHour(tempInt);
            fileIn >> tempInt;
            now->info.setTimeMinutes(tempInt);
            fileIn >> tempStr;
            now->info.setPosition(tempStr);
            fileIn >> tempStr;
            now->info.setName(tempStr);
            fileIn >> tempStr;
            now->info.setAcademicDegree(tempStr);
            fileIn >> tempInt;
            now->info.setInfluence(tempInt);
            fileIn >> tempInt;
            now->capacity = tempInt;
            fileIn >> tempInt;
        }
        now->next = nullptr;
        delete cont;
    }
    else
        throw invalid_argument("file couldn't be opened");

    fileIn.close();
}