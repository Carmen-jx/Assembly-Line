// Name: Carmen Lam
// Seneca Student ID: 129950226
// Seneca email: clam98@myseneca.ca
// Date of completion: August 3, 2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include "Station.h"

using namespace std;

namespace sdds{
    Station::Station(const std::string& str){
        Utilities utils {};
        size_t next_pos{};
        bool more=true;

        m_name=utils.extractToken(str,next_pos,more);
        m_serialNumber= stoi(utils.extractToken(str,next_pos,more));
        m_qty=stoi(utils.extractToken(str,next_pos,more));

        m_widthField= max(m_widthField,utils.getFieldWidth());
        m_description=utils.extractToken(str,next_pos,more);

        m_id= ++id_generator;


    }
    const std::string& Station::getItemName() const{
   return m_name;
    }

    size_t Station::getNextSerialNumber(){

        return m_serialNumber++;
    }
    size_t Station::getQuantity() const{
        return m_qty;
    }
    void Station::updateQuantity(){
        if(m_qty>0){
            m_qty=m_qty-1;
        }
    }
    void Station::display(std::ostream& os, bool full) const{

        os<<"00";
        os<<m_id;
        os<<" | ";

        os.fill(' ');
        os.width(m_widthField);
        os.setf(ios::left);
        os<<m_name;
        os.unsetf(ios::left);
        os<<" | ";


        os.fill('0');
        os.width(6);
        os<<m_serialNumber;
        os<<" | ";

        if(full){
            os.fill(' ');
            os.width(4);
            os<<getQuantity();
            os<<" | ";

            os.setf(ios::left);
            os<<m_description;
            os.unsetf(ios::left);
        }

        os<<endl;
    }

}