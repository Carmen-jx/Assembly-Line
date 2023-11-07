
#include "CustomerOrder.h"
#include "Utilities.h"
#include <array>
#include <algorithm>

namespace sdds{

    size_t CustomerOrder::m_widthField = 0u;

    //rule of 5 operators
    CustomerOrder::CustomerOrder(const std::string& str){
        Utilities utils {};
        size_t next_pos{};
        bool more=true;



        m_name=utils.extractToken(str,next_pos,more);
        m_product= utils.extractToken(str,next_pos,more);
        m_cntItem=std::count(str.begin(), str.end(),utils.getDelimiter())-1;

        m_lstItem= new Item* [m_cntItem];

        for (size_t i =0u; i< m_cntItem; i++){
            m_lstItem[i]= new Item(utils.extractToken(str, next_pos,more));
        }

        if(m_widthField< utils.getFieldWidth()){
            m_widthField=utils.getFieldWidth();
        }
    }

    CustomerOrder::~CustomerOrder(){
        for(size_t i=0; i<m_cntItem;i++){
            delete m_lstItem[i];
        }
        delete [] m_lstItem;
        m_lstItem= nullptr;
    }

    //copy operators
    CustomerOrder::CustomerOrder(const CustomerOrder& order){
        throw std::string("ERROR");
    }

    //move operators
    CustomerOrder::CustomerOrder(CustomerOrder&& order) noexcept{
        *this= std::move(order);
    }
    CustomerOrder& CustomerOrder::operator=(CustomerOrder&& order) noexcept{
        if( this != & order){

            if(m_lstItem!= nullptr){
                for(size_t i=0u; i<m_cntItem; i++){
                    delete m_lstItem[i];
                    m_lstItem[i] = nullptr;
                }
            }

            m_name=order.m_name;
            m_product=order.m_product;
            m_cntItem=order.m_cntItem;
            m_lstItem= order.m_lstItem;


            order.m_lstItem = nullptr;
            order.m_name='\0';
            order.m_cntItem=0u;
            order.m_product= '\0';
        }

        return *this;

    }

    bool CustomerOrder::isOrderFilled() const {
        bool filled= true;

        for(size_t i =0u; i< m_cntItem && filled; i++){
            if(!m_lstItem[i]->m_isFilled){
                filled=false;
            }
        }

        return filled;
    }

    bool CustomerOrder::isItemFilled(const std::string& itemName) const{
        bool filled = true;

        for(size_t i=0u; i<m_cntItem && filled;i++){
            if(m_lstItem[i]->m_itemName== itemName){
                if(!m_lstItem[i]->m_isFilled){
                    filled=false;
                }
            }
        }

        return filled;

    }

    void CustomerOrder::fillItem(Station& station, std::ostream& os){


        for(size_t i=0u; i< m_cntItem; i++){
            if(m_lstItem[i]->m_itemName == station.getItemName() && station.getQuantity() > 0){
                station.updateQuantity();
                m_lstItem[i]->m_serialNumber++;
                m_lstItem[i]->m_isFilled= true;

                os << "    Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
            } else if ((m_lstItem[i]->m_itemName == station.getItemName()) && (station.getQuantity() == 0)) {
                os << "    Unable to fill " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
            }
        }
    }

    void CustomerOrder::display(std::ostream& os) const{

        os<<m_name<< " - "<< m_product<<std::endl;

        for(size_t i=0u; i< m_cntItem; i++){
            os<<"[";
            os.setf(std::ios::left);
            os.width(6);
            os.fill(0);
            os.unsetf(std::ios::left);
            os<<"] ";

            os.setf(std::ios::left);
            os.width(m_widthField);
            os.fill(' ');
            os<< m_lstItem[i]->m_itemName;
            os.unsetf(std::ios::left);
            os<<"   - ";
            os<< (m_lstItem[i]->m_isFilled ? "FILLED" : "TO BE FILLED")<<std::endl;


        }


    }
}
