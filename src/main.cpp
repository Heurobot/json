#include"JsonFileTools.h"

int main(void)
{
    std::string jsonroute="/home/ziliang/Desktop/json/data/datatransfer.json";
    JsonFileTools jsontool;
    Json::Value  root;

    root=jsontool.readJsonFile(jsonroute);

     std::string MessageID=root[std::string("MessageID")].asString();
    std::string Message=root[std::string("Message")].asString();
    std::string VendorID=root[std::string("VendorID")].asString();

    std::cout<<"MessageID:"<<MessageID<<std::endl
            <<"Message:"<<Message<<std::endl
            <<"VendorID:"<<VendorID<<std::endl;

    



    return 0;
}
