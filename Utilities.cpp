
#include "Utilities.h"
 using namespace std;

namespace sdds {
    void Utilities::setFieldWidth(size_t newWidth){
        m_widthField=newWidth;
    }

    size_t Utilities::getFieldWidth() const{
        return m_widthField;
    }

    std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more){
        string token{};
        size_t end_pos= str.find(m_delimiter,next_pos);
        if (end_pos != string::npos){
            token=str.substr(next_pos,end_pos-next_pos);
            next_pos= end_pos+1;
            more=true;
        }else{
            token=str.substr(next_pos);
            more=false;
        }
        token= eraseWhiteSpace(token);
        if( token.length() > m_widthField){
            m_widthField= token.length();
        }

        if(token.empty()){
            more=false;
            throw string("ERROR: Token is empty!");
        }

        return token;

    }

    void Utilities::setDelimiter(char newDelimiter){
        m_delimiter=newDelimiter;
    }

    char Utilities::getDelimiter(){
        return m_delimiter;
    }

    std::string Utilities::eraseWhiteSpace(const std::string& str){
        string newStr {};
        size_t start= str.find_first_not_of(' ');
        size_t end= str.find_last_not_of(' ');

        newStr= (string::npos ==start) ? str : str.substr(start,(end-start +1));
        return newStr;
    }
}
