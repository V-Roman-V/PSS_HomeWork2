#include "professor.h"

Professor::Professor()
    :cabinet(nullptr)
{
    init();
}

Professor::Professor(const People &p, Cabinet* _cabinet, std::string t_course)
    :UniversityPeople(p), cabinet(_cabinet), teaching_course (t_course)
{
    init();
}

Position Professor::getPosition() const
{
    return Position::professor;
}

void Professor::init()
{
    card.setAccessLevel(AccessLevel::red);
}
