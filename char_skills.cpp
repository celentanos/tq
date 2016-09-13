#include "char_skills.h"

CharSkills::CharSkills()
{

}

CharSkills::~CharSkills()
{
    if(this->size() > 0) {
        qDeleteAll(this->begin(), this->end());
        this->clear();
    }
}
