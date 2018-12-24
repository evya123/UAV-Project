//
// Created by evya on 12/21/18.
//

#ifndef UAV_PROJECT_CONTROLLER_H
#define UAV_PROJECT_CONTROLLER_H
#include <vector>
#include <string>
#include <Var.h>
#include <Maps/Data.h>
#include <mutex>
mutex m_locker;
using namespace std;

class Controller{
public:
    Controller() = default;
    void toMap(map<double> &);
    void fromMap();
private:
};


#endif //UAV_PROJECT_CONTROLLER_H
