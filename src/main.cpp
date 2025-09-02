#include"JsonFileTools.h"

int main(void)
{
    std::string jsonread="/home/ziliang/Desktop/json/data/datatransfer.json";
    std::string jsonread_lot="/home/ziliang/Desktop/json/data/mutiply.json";
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

    
    std::cout<<root.toStyledString()<<std::endl;//读取整个json文件

    root=jsontool.readJsonFile(jsonread_lot);
    std::cout<<root.toStyledString()<<std::endl;//完全的读取
    for (const auto &item : root)               // 降低拷贝代价，无法修改数据确保安全
    {
        Msg msg;
        msg.ComponentName = item["ComponentName"].asString();
        msg.ComponentInstance = item["ComponentInstance"].asString();
        msg.VariableName = item["VariableName"].asString();
        msg.VariableInstance = item["VariableInstance"].asString();
        msg.AttributeType = item["AttributeType"].asString();
        msg.AttributeValue = item["AttributeValue"].asString();
        msg.Mode = item["Mode"].asString();
        msg.ValueList = item["ValueList"].asString();
        msg.DataType = item["DataType"].asString();
        msg.Private = item["Private"].asString();
        msg.ValueRange = item["ValueRange"].asString();
        msg.Unit = item["Unit"].asString();
        jsontool.Msgarray.push_back(msg);
    }


    //写入json文件
    std::string path =jsonwrite+"/test1.json";
    jsontool.WriteFileJson(path);


    

    



    return 0;
}
