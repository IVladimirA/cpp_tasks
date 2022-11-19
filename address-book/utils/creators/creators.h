#pragma once

#include "../../people/student/student.h"
#include "../../people/teacher/teacher.h"
#include "../../scores/scores.h"
#include "../../subject/subject.h"

namespace creators {

people::Student student();
people::Teacher teacher();
Scores scores();
Subject subject();

}; // namespace creators
