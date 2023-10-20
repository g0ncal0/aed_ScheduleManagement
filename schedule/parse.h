//
// Created by goncalo on 18-10-2023.
//

#ifndef UNISCHEDULE_PARSE_H
#define UNISCHEDULE_PARSE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include "AllUcs.h"
#include "AllStudents.h"


void parse();
AllUcs parse_classes();
AllStudents parse_students(const AllUcs& ucs);

#endif //UNISCHEDULE_PARSE_H
