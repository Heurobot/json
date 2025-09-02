#pragma once

#include<string>
typedef struct Message
{
    std::string ComponentName;
    std::string ComponentInstance;
    std::string VariableName;
    std::string VariableInstance;
    std::string AttributeType;
    std::string AttributeValue;
    std::string Mode;
    std::string ValueList;
    std::string DataType;
    std::string Private;
    std::string ValueRange;
    std::string Unit; 
}Msg;

//  {
//     "ComponentName": "EVSE",
//     "ComponentInstance": "",
//     "VariableName": "Power",
//     "VariableInstance": "",
//     "AttributeType": "0",
//     "AttributeValue": "",
//     "Mode": "1",
//     "ValueList": "",
//     "DataType": "1",
//     "Private": "false",
//     "ValueRange":"",
//     "Unit": "W"
//   }