#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include <vector>
#include "Room_classes/room.h"
#include "Room_classes/livingroom.h"
#include "Room_classes/universityroom.h"
#include "People_classes/admin.h"
#include "People_classes/director.h"
#include "People_classes/labemployee.h"
#include "People_classes/professor.h"
#include "People_classes/student.h"

#include "Additional_classes/roomlocation.h"
#include "Room_classes/cabinet.h"
#include "Room_classes/classroom.h"
#include "Room_classes/conferenceroom.h"
#include "Room_classes/directorcabinet.h"
#include "Room_classes/lectureroom.h"
#include "Room_classes/livingroom.h"

class University
{
public:
    University(const std::string& name = "University");
    University(const University&) = delete;
    void operator=(const University&) = delete;

    ~University();
    void addStudent(const People &people, LivingRoom* lroom, unsigned short course);
    void addEmployess(const People& people);
    void addProfessor(const People& people, Cabinet* cabinet, const std::string& course);
    void addAdmin(const People& people, std::string pass);

    void setDirector(const People& people );
    std::string getFullListPeoples();
    std::string getCommonListPeoples();

    void addCabinet(const RoomLocation& location, unsigned short max_people);
    void addClassRoom(const RoomLocation& location);
    void addConferenceRoom(const RoomLocation& location, unsigned short max_people);
    void addLectureRoom(const RoomLocation& location, unsigned short max_people);
    void addLivingRoom(const RoomLocation& location, unsigned short max_people);

    void setDirectorCabinet(const RoomLocation& location);
    std::string getListRooms();

    void getPeopleByType(UniversityPeople::Position type, std::vector<UniversityPeople *>& people);
    Director *getDirector();
    std::vector<Admin *>& getAdmins();
    std::vector<LabEmployee *>& getLabEmployees();
    std::vector<Professor *>& getProfessors();
    std::vector<Student *>& getStudents();

    void getRoomByType(UniversityRoom::RoomType type, std::vector<Room *>& rooms);
    DirectorCabinet *getDirectorCabinet();
    std::vector<ClassRoom *>& getClassRoom();
    std::vector<ConferenceRoom *>& getConferenceRoom();
    std::vector<LectureRoom *>& getLectureRoom();
    std::vector<Cabinet *>& getCabinetRoom();
    std::vector<LivingRoom *>& getLivingRoom();

    std::string getName() const;

    std::vector<RoomType> getAllRoomType();
    std::vector<Position> getAllPositions();
    std::vector<AccessLevel> getAllAccessLevels();
    std::vector<std::string> getAllRoomAccess();

private:
    std::string name;
    std::vector<LivingRoom*> campuse;
    std::vector<UniversityRoom*> university;

    Director* director;
    std::vector<Admin*> admins;
    std::vector<LabEmployee*> lab_employees;
    std::vector<Professor*> professors;
    std::vector<Student*> students;

    DirectorCabinet* director_cabinet;
    std::vector<ClassRoom* > class_room;
    std::vector<ConferenceRoom* > conference_room;
    std::vector<LectureRoom* > lecture_room;
    std::vector<Cabinet* > cabinet_room;
    std::vector<LivingRoom* > living_room;

};

#endif // UNIVERSITY_H
