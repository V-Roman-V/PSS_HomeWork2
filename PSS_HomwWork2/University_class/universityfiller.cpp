#include "universityfiller.h"

void UniversityFiller::fillStartingData(University &University)
{
    // ---------------------------------------------------------- Declare people
    myQueue<People> peoples;
    peoples.emplace("Donald",
                    "Park",
                    People::Gender::male,
                    Date(06, 03, 1989),
                    Passport(4767, 235646),
                    "89534210987",
                    "American"
                    );
    peoples.emplace("Anna",
                     "Tobolenko",
                     People::Gender::female,
                     Date(26, 04, 1992),
                     Passport(4448, 624472),
                     "89534210987",
                     "Russian"
                    );
    for(int i = 0; i<33; i++)
        peoples.emplace(PeopleGenerator::getRandomPeople());

// ---------------------------------------------------------- Add peoples
    University.setDirector(peoples.pickLast());

    University.addAdmin(peoples.pickLast(),"password");
    University.addAdmin(peoples.pickLast(),"12345");

    for(int i=0;i<4;i++)
        University.addEmployess(peoples.pickLast());


    std::vector<std::string> courses = {" Introduction to Programming", "Analytical Geometry and Linear Algebra", "Data Structures and Algorithm", "Foreign Language", "Mathematical Analysis", "Theoretical Computer Science", "Operating Systems"};
    for(int i=0;i<8;i++)
        University.addProfessor(peoples.pickLast(), nullptr, courses[ i%courses.size()]);

    while(!peoples.empty())
        University.addStudent(peoples.pickLast(), nullptr, (rand()%4+1));
// ---------------------------------------------------------- Declare Room
    myQueue<RoomLocation> university_locations;

    for(int i=0;i<8;i++)
        university_locations.emplace(RoomLocation::Place::university, 1, 100+i);
    for(int i=0;i<10;i++)
        university_locations.emplace(RoomLocation::Place::university, 2, 200+i);
    for(int i=0;i<10;i++)
        university_locations.emplace(RoomLocation::Place::university, 3, 300+i);

    myQueue<RoomLocation> campuse_locations;
    for(int i=0;i<6;i++)
        campuse_locations.emplace(RoomLocation::Place::campuse, 1, i, 1);
    for(int i=0;i<6;i++)
        campuse_locations.emplace(RoomLocation::Place::campuse, 1, i, 2);

// ---------------------------------------------------------- Add Rooms
    University.setDirectorCabinet(university_locations.pickLast());

    for(int i=0;i<6;i++)
        University.addLectureRoom(university_locations.pickLast(), ((rand()%2)?120:180));

    for(int i=0;i<6;i++)
        University.addCabinet(university_locations.pickLast(), (3+rand()%3));

    for(int i=0;i<6;i++)
        University.addConferenceRoom(university_locations.pickLast(), 12);

    while(!university_locations.empty())
        University.addClassRoom(university_locations.pickLast());

    while(!campuse_locations.empty())
        University.addLivingRoom(campuse_locations.pickLast(), 2 + rand()%4);

// ---------------------------------------------------------- Make link between cabinets and professors/lab_employess
{
    University.getDirectorCabinet()->addWorker(University.getDirector());

    auto professors = University.getProfessors();
    auto employess = University.getLabEmployees();

    auto cabinets = University.getCabinetRoom();
    int num_cab = 0;
    for(int i=0;i<professors.size();i++){
        if(num_cab >= cabinets.size())break;
        if(cabinets[num_cab]->getCountWorkers() < cabinets[num_cab]->getMaxPeople())
            cabinets[num_cab]->addWorker(professors[i]);
        else{
            num_cab++;
            i--;
        }
    }
    num_cab++;
    for(int i=0;i<employess.size();i++){
        if(num_cab >= cabinets.size())break;
        if(cabinets[num_cab]->getCountWorkers() < cabinets[num_cab]->getMaxPeople())
            cabinets[num_cab]->addWorker(employess[i]);
        else{
            num_cab++;
            i--;
        }
    }
}
// ---------------------------------------------------------- Make link between livingRoom and students
{
    auto students = University.getStudents();
    auto living = University.getLivingRoom();
    int num_liv = 0;
    for(int i=0;i<students.size();i++){
        if(num_liv >= living.size())break;
        if(living[num_liv]->getCountResidents() < living[num_liv]->getMaxPeople())
            living[num_liv]->addResidents(students[i]);
        else{
            num_liv++;
            i--;
        }
    }
}

}
