#ifndef Argser_Hpp
#define Argser_Hpp 1
#include "config.hpp"
#include "admin.hpp"
#include <fstream> // std::fstream


//user definable Function
/*
class Value{
    public:
        Value(string value){
            this->S_V=value;

        }
        Value(int value){
            this->I_V=value;

        }
        Value(float value){
            this->F_V=value;

        }

    string S_V;
    int I_V;
    float F_V;
    
    };*/
class Value
{
public:
    Value(string Name, string Value);
    int I_value;
    float F_value;
    string S_value;
    string v_Name;

};
 
Value::Value(string Name, string Value){
    //this->F_value= stof(Value);

    std::string s = Value;
 
    try
    {
        int i = std::stoi(s);
        this->I_value=i;
        std::cout << i << '\n';
    }
    catch (std::invalid_argument const &e)
    {
        std::cout << "Bad input: std::invalid_argument thrown" << '\n';
    }
    catch (std::out_of_range const &e)
    {
        std::cout << "Integer overflow: std::out_of_range thrown" << '\n';
    }
    try
    {
        float i = std::stof(s);
        this->F_value=i;
        std::cout << i << '\n';
    }
    catch (std::invalid_argument const &e)
    {
        //std::cout << "Bad input: std::invalid_argument thrown" << '\n';
    }
    catch (std::out_of_range const &e)
    {
        std::cout << "Float overflow: std::out_of_range thrown" << '\n';
    }
    //this->I_value= stoi(Value.c_str());
    this->S_value=Value;
    this-> v_Name=Name;

}
class UD_Function{
    public:
        UD_Function(string Fname,int Bl,int El){
            this->FuncName=Fname;
            this->BeginLine=Bl;
            this->EndLine=El;
        }

        string FuncName;
        
        int BeginLine;
        int EndLine;

};


class Argser
{
public:
vector<UD_Function>Functions;
int StackPointer=0;
Argser(int argc, char **argv)
{
    //this->LastMathValue=;
    this->argc = argc;
    for (int i = 0; i < argc; i++)
    {
        string f = argv[i];
        this->argv.push_back(f);
    }
    this->init_Func();
    Cfg=Configurator();
}
    struct CallableObj
    {
        void *(*Taddr)(Argser *);
        string Name;
        string Desk;
    };
    class QSRcModule
    {
    public:
    /*
        QSRcModule(string ModuleName)
        {
            this->Module_Name = ModuleName;
        }
        QSRcModule()
        {
            
        }*/
        int Set_Name(string name){
            this->Module_Name=name;
        }
    
        int add_Cask(string fname, string desk, void *(taddr)(Argser *))
        {
            CallableObj NCO;
            NCO.Desk = desk;
            NCO.Name = fname;
            NCO.Taddr = taddr;
            __Tasks.push_back(NCO);
            return 0;
        }
        vector<CallableObj> __Tasks;
        string Module_Name;
    };
    //typedef void *(*TaskAddr)(Argser*);

    //int AddCFnc(TaskAddr, string);

    
    int Parse();
    //int Update();
    int runfile();
    int newVar(string, string);
    int DeleteVar(string);
    string getVar(string);
    int GetInsL(int);
    int GetSRCFId(string);
    //Todo
    int FncExist(string);
    int Execute(string);

    //private:
    vector<QSRcModule> QS;
    int add_Module(QSRcModule MD)
    {
        QS.push_back(MD);
        return 0;
    }
    int add_Cask(string fname, string desk, void *(taddr)(Argser *))
    {
        CallableObj NCO;
        NCO.Desk = desk;
        NCO.Name = fname;
        NCO.Taddr = taddr;
        __Tasks.push_back(NCO);
        return 0;
    }
    int RunTask()
    {

        //return Taddr();
        return 0;
    }
    bool is_Name(CallableObj Obj, string Test_Name)
    {
        return (strcmp(Obj.Name.c_str(), Test_Name.c_str()) == 0);
    }
    /*string getname()
        {
            return Name;
        }
*/
    int init_Func();

    int try_task(string tname)
    {
        for (int i = 0; i < this->__Tasks.size(); i++)
        {
            if (is_Name(this->__Tasks[i], tname))
            {

                auto Tadr = __Tasks[i].Taddr;
                Tadr(this);
                return 1;
            }
            for(int i=0;i<this->Math_Var.size();i++){
                if(strcmp(this->Math_Var[i].v_Name.c_str(),tname.c_str())==0){
                    return 1;
                }
            }
        }
        return 0;
    }
    QSRcModule getModule(string name){
    for (int i = 0; i < this->QS.size(); i++)
        {
            if (strcmp(this->QS[i].Module_Name.c_str(), name.c_str())==0)
            {

                //auto Tadr = __Tasks[i].Taddr;
                //Tadr(this);
                return this->QS[i];
            }
        }
        QSRcModule M;
        return M;
    }

    vector<CallableObj> __Tasks;
    struct Fnc
    {
        int (Argser::*CPP_Addr)();
        string Fname;
    };
    int DBuf;
    Value LastMathValue=Value("Null","Null");
    string getcurrentIns();
    int edit(string);
    int varsN = 0;
    int charstr = 0;
    //int Compile();
    //int Link();
    int executeFunc(string);
    //int Run();
    int newFunc(string, int,int);
    int import();
    string getnextIns();
    vector<Value> Math_Var;
    vector<string> vars;
    vector<Fnc> Fncs;

    //2d xyz, x=func, y=code z=call
    int NextFNCID = 0;

    /*vector<string> FuncName;
    vector<int> FuncStackP;

    vector<int> Begin_Line;
    vector<int> End_line;*/
    //vector<std::string> vardata;
    Configurator Cfg;
    int argc;
    vector<int> lines;
    vector<string> argv;
};
/*int Argser::GetSRCFId(string SrcF){
    for (int i=0;i<FuncSrc.size();i++){
        if(strcmp(SrcF.c_str(),FuncSrc[i].c_str())==0){
            return i;
        }
    }
    return -1;
}*/
class Helper
{
public:
    Helper(Argser *);
};
#else

#endif
