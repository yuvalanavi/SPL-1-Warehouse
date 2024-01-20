#include "../include/BaseAction.h"
#include <iostream>


BaseAction::BaseAction(): errorMsg(""), status(ActionStatus::ERROR){}

ActionStatus BaseAction::getStatus() const{
    return status;
}
void BaseAction::complete(){
    status = ActionStatus::COMPLETED;
}
void BaseAction::error(string errorMsg){
    status = ActionStatus::ERROR;
    this->errorMsg = errorMsg;
    cout << "ERROR: "+ errorMsg << endl; 
}
string BaseAction::getErrorMsg() const{
    string output = BaseAction::errorMsg;
    return output;
}