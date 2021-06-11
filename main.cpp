#include <iostream>
#include <string>

int fn_IsExisted(std::string* sp_Set, int& i_Size
                 ,std::string s_Word){

	for (int i_Ct = 0; i_Ct < i_Size; i_Ct++){
        if (sp_Set[i_Ct].compare(s_Word) == 0){
            return true;
        }
	}
	return false;
}

bool fn_BreakWord(std::string* sp_Set, int& i_Size, std::string s_Msg){
	int i_MsgSize = s_Msg.length();

	if (i_MsgSize == 0){
        return true;
	}

	for (int i_Ct= 1; i_Ct<= i_MsgSize; i_Ct++){
		if (
            fn_IsExisted( sp_Set, i_Size, s_Msg.substr(0, i_Ct) ) &&
			fn_BreakWord( sp_Set, i_Size, s_Msg.substr(i_Ct, i_MsgSize- i_Ct) )
        ){
            return true;
        }

	}
	return false;
}

int main(){
    int i_Size = -1;
    std::cin>> i_Size;
    std::string sa_Set[i_Size] ={};
    for(int i_Ct=0; i_Ct< i_Size; i_Ct++){
        std::cin >> sa_Set[i_Ct];
    }
    std::string s_Msg ="";
    std::cin>>s_Msg;

    bool b_IsRes = fn_BreakWord(sa_Set, i_Size, s_Msg);
    if(b_IsRes == false){
        std::cout<< "FALSE";
    }
    else{
        std::cout<< "TRUE";
    }
	return 0;
}
