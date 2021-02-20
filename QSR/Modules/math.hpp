#ifndef Math_Hpp
#define Math_Hpp 1
#include "../includes/Argser.hpp"
using namespace std;

Value MathGetValue(Argser *IN,string Varname){
    for(int i=0; i<IN->Math_Var.size();i++){
        if (strcmp(IN->Math_Var[i].v_Name.c_str(),Varname.c_str())==0){
            return IN->Math_Var[i];
        }
    }
    return Value("Null","0.0");
}
void *MathMult(Argser * IN){
    Value E=Value(IN->LastMathValue.v_Name,"0.0");
    E.I_value=MathGetValue(IN,IN->argv[IN->charstr-1]).I_value*MathGetValue(IN,IN->argv[IN->charstr+1]).I_value;
    IN->LastMathValue=E;
    
    IN->charstr++;

}
void *MathDiv(Argser *IN){
    Value E=Value(IN->LastMathValue.v_Name,"0.0");
    E.I_value=MathGetValue(IN,IN->argv[IN->charstr-1]).I_value/MathGetValue(IN,IN->argv[IN->charstr+1]).I_value;
    IN->LastMathValue=E;
    
    IN->charstr++;
}
void *MathMIN(Argser *IN)
{
    //cout<<IN->argv[IN->charstr-1]<<endl<<IN->argv[IN->charstr+1]<<endl;
    //cout<<<<endl;
    Value E=Value(IN->LastMathValue.v_Name,"0.0");
    E.I_value=MathGetValue(IN,IN->argv[IN->charstr-1]).I_value-MathGetValue(IN,IN->argv[IN->charstr+1]).I_value;
    IN->LastMathValue=E;
    
    IN->charstr++;

}

void *MathPLUS(Argser *IN)
{
    Value E=Value(IN->LastMathValue.v_Name,"0.0");
    E.I_value=MathGetValue(IN,IN->argv[IN->charstr-1]).I_value+MathGetValue(IN,IN->argv[IN->charstr+1]).I_value;
    IN->LastMathValue=E;

    IN->charstr++;

}
void *MathIsequal(Argser *IN){

    Value E=Value(IN->LastMathValue.v_Name,"0.0");
    E.I_value=MathGetValue(IN,IN->argv[IN->charstr-1]).I_value==MathGetValue(IN,IN->argv[IN->charstr+1]).I_value;
    IN->LastMathValue=E;

    IN->charstr++;

}


void *MathInt(Argser *IN)
{
    //int varname value
string Varname=IN->getnextIns();
string VarValur=IN->getnextIns();
int didfoind=0;
for(int i=0;i<IN->Math_Var.size();i++){
    if(strcmp(IN->Math_Var[i].v_Name.c_str(),VarValur.c_str())==0){
        IN->DBuf=1;
        IN->Parse();
        IN->DBuf=-1;
        IN->Math_Var.push_back(IN->LastMathValue);
        cout<<"new int "<<Varname<<" With value: "<<IN->LastMathValue.I_value<<endl;
        didfoind=1;
        IN->LastMathValue=Value("Null","0.0");
    }
    
}
if (!didfoind){
    cout<<"new int "<<Varname<<" With value: "<<VarValur<<endl;

    Value VName=Value(Varname,VarValur);
    IN->Math_Var.push_back(VName);
    }
}



void *MathFMult(Argser * IN){
    Value E=Value(IN->LastMathValue.v_Name,"0.0");
    E.F_value=MathGetValue(IN,IN->argv[IN->charstr-1]).F_value*MathGetValue(IN,IN->argv[IN->charstr+1]).F_value;
    IN->LastMathValue=E;
    
    IN->charstr++;

}
void *MathFDiv(Argser *IN){
    Value E=Value(IN->LastMathValue.v_Name,"0.0");
    E.F_value=MathGetValue(IN,IN->argv[IN->charstr-1]).F_value/MathGetValue(IN,IN->argv[IN->charstr+1]).F_value;
    IN->LastMathValue=E;
    
    IN->charstr++;
}
void *MathFMIN(Argser *IN)
{
    //cout<<IN->argv[IN->charstr-1]<<endl<<IN->argv[IN->charstr+1]<<endl;
    //cout<<<<endl;
    Value E=Value(IN->LastMathValue.v_Name,"0.0");
    E.F_value=MathGetValue(IN,IN->argv[IN->charstr-1]).F_value-MathGetValue(IN,IN->argv[IN->charstr+1]).F_value;
    IN->LastMathValue=E;
    
    IN->charstr++;

}

void *MathFPLUS(Argser *IN)
{
    Value E=Value(IN->LastMathValue.v_Name,"0.0");
    E.F_value=MathGetValue(IN,IN->argv[IN->charstr-1]).F_value+MathGetValue(IN,IN->argv[IN->charstr+1]).F_value;
    IN->LastMathValue=E;

    IN->charstr++;

}
void *MathFIsequal(Argser *IN){

    Value E=Value(IN->LastMathValue.v_Name,"0.0");
    E.F_value=MathGetValue(IN,IN->argv[IN->charstr-1]).F_value==MathGetValue(IN,IN->argv[IN->charstr+1]).F_value;
    IN->LastMathValue=E;

    IN->charstr++;

}


void *MathFloat(Argser *IN)
{
    //int varname value
string Varname=IN->getnextIns();
string VarValur=IN->getnextIns();
int didfoind=0;
for(int i=0;i<IN->Math_Var.size();i++){
    if(strcmp(IN->Math_Var[i].v_Name.c_str(),VarValur.c_str())==0){
        IN->DBuf=1;
        IN->Parse();
        IN->DBuf=-1;
        IN->Math_Var.push_back(IN->LastMathValue);
        cout<<"new float "<<Varname<<" With value: "<<IN->LastMathValue.I_value<<endl;
        didfoind=1;
        IN->LastMathValue=Value("Null","0.0");
    }
    
}
if (!didfoind){
    cout<<"new float "<<Varname<<" With value: "<<VarValur<<endl;

    Value VName=Value(Varname,VarValur);
    IN->Math_Var.push_back(VName);
    }
}
string Get_nextStr(Argser*IN){
    // "code
    //IN->getnextIns();
    string Fnal_Str;
    int Sep=0;
    while(Sep<=1){
        string Buffer=IN->getnextIns();
        int Char=Buffer.find('"');
        cout<<Char<<Buffer<<endl;
        if (!Sep&&Char==0){
            for(int i=1;i<Buffer.size();i++){
                Fnal_Str.push_back(Buffer[i]);
            }
            Fnal_Str.append(" ");
            //cout<<
            Sep=1;
        }
        else{
            string charbuffer;
            if(Char>0){
                for(int i=0;i<Char;i++){
                
                    charbuffer.push_back(Buffer[i]);

                }
                Sep++;

            }
            else{
                Fnal_Str.append(Buffer).append(" ");
            }
            Fnal_Str.append(charbuffer.c_str());
        }
    }
    return Fnal_Str;
}
void *MathString(Argser *IN)
{
    //int varname value
string Varname=IN->getnextIns();
string VarValur=Get_nextStr(IN);
int didfoind=0;
for(int i=0;i<IN->Math_Var.size();i++){
    if(strcmp(IN->Math_Var[i].v_Name.c_str(),VarValur.c_str())==0){
        IN->DBuf=1;
        IN->Parse();
        IN->DBuf=-1;
        IN->Math_Var.push_back(IN->LastMathValue);
        cout<<"new String "<<Varname<<" With value: "<<IN->LastMathValue.I_value<<endl;
        didfoind=1;
        IN->LastMathValue=Value("Null","0.0");
    }
    
}
if (!didfoind){
    cout<<"new float "<<Varname<<" With value: "<<VarValur<<endl;

    Value VName=Value(Varname,VarValur);
    IN->Math_Var.push_back(VName);
    }
}
Argser::QSRcModule Math_Module()
{
    Argser::QSRcModule M;
    M.Set_Name("Math");
    M.add_Cask("int", "create new int variable", &MathInt);
    M.add_Cask("I+", "[int] + [int]", &MathPLUS);
    M.add_Cask("I-", "[int] - [int]", &MathMIN);
    M.add_Cask("I/", "[int] / [int]", &MathDiv);
    M.add_Cask("I*", "[int] / [int]", &MathMult);
    M.add_Cask("I==", "[int] == [int]", &MathIsequal);
    M.add_Cask("float", "create new float variable", &MathFloat);
    M.add_Cask("F+", "[float] + [float]", &MathFPLUS);
    M.add_Cask("F-", "[float] - [float]", &MathFMIN);
    M.add_Cask("F/", "[float] / [float]", &MathFDiv);
    M.add_Cask("F*", "[float] / [float]", &MathFMult);
    M.add_Cask("F==", "[float] == [float]", &MathFIsequal);
    M.add_Cask("string","Create new String Variable", &MathString);
    return M;
}

#endif