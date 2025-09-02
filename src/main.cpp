#include"JsonFileTools.h"

int main(void)
{
    std::string jsonread="/home/ziliang/Desktop/json/data/datatransfer.json";
    std::string jsonwrite="/home/ziliang/Desktop/json/data";
    JsonFileTools jsontool;
    Json::Value  root;

    root=jsontool.readJsonFile(jsonread);
    //读取其中已知的项
    std::string MessageID=root[std::string("MessageID")].asString();
    std::string Message=root[std::string("Message")].asString();
    std::string VendorID=root[std::string("VendorID")].asString();

    std::cout<<"MessageID:"<<MessageID<<std::endl
            <<"Message:"<<Message<<std::endl
            <<"VendorID:"<<VendorID<<std::endl;

    //读取整个json文件
    std::cout<<root.toStyledString()<<std::endl;



    //写入json文件
    std::string path =jsonwrite+"/test1.json";
    jsontool.WriteFileJson(path);


    

    



    return 0;
}
