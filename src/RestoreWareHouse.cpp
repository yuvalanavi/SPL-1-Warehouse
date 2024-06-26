#include "../include/Action.h"
#include "../include/Order.h"
#include "../include/Customer.h"
#include <iostream>
#include <string>
extern WareHouse *backup;

RestoreWareHouse::RestoreWareHouse() : BaseAction() {}
void RestoreWareHouse::act(WareHouse &wareHouse)
{
    if (backup == nullptr)
    {
        this->error("No backup available");
    }
    else
    {
        wareHouse = *backup;
        this->complete();
    }
}
RestoreWareHouse *RestoreWareHouse::clone() const
{
    return new RestoreWareHouse(*this);
}
string RestoreWareHouse::toString() const
{
    string output;
    if (this->getStatus() == ActionStatus::COMPLETED)
    {
        output = "restore COMPLETED";
    }
    else
    {
        output = "restore ERROR";
    }
    return output;
}