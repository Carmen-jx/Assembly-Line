// Name: Carmen Lam
// Seneca Student ID: 129950226
// Seneca email: clam98@myseneca.ca
// Date of completion: August 3, 2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include "LineManager.h"

namespace sdds{
    LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations) {
        std::ifstream fp(file);
        std::string line{};
        Utilities utils{};
        size_t start_pos{0u};
        bool more{true};

        while (std::getline(fp, line)) {
            size_t start_pos{0u};
            Workstation *stationC{};
            Workstation *stationN{};
            std::string thisStation{};
            std::string nextStation{};

            thisStation = utils.extractToken(line, start_pos, more);

            if (more) {
                nextStation = utils.extractToken(line, start_pos, more);
            }

            std::for_each(stations.begin(), stations.end(), [&](Workstation *station) {
                if (thisStation == station->getItemName()) {
                    stationC=station;
                }
            });

            if (!nextStation.empty()) {
                std::for_each(stations.begin(), stations.end(), [&](Workstation *station) {
                    if (nextStation == station->getItemName()) {
                        stationN = station;
                    }
                });
                stationC->setNextStation(stationN);
            }
            m_activeLine.push_back(stationC);
        }

        fp.close();

         auto firstStation= [&](Workstation* St){
            auto matchStation=std::find_if(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* st){
                return St == st->getNextStation();
            });

            if(matchStation==m_activeLine.end()){
                m_firstStation=St;
            }
         };

        for_each(stations.begin(), stations.end(), firstStation);

        m_cntCustomerOrder = g_pending.size();
    }




    void LineManager::reorderStations(){

        Workstation* stations= m_firstStation;
        std::vector<Workstation*> reorders;

        while(stations != nullptr){
            reorders.push_back(stations);
            stations= stations->getNextStation();

        }
        m_activeLine=reorders;
    }

    bool LineManager::run(std::ostream& os){
        bool success {false};

        static size_t cnt {0u};

        os<<"Line Manager Iteration: "<<cnt++<<std::endl;

        if(!g_pending.empty()){
            *m_firstStation += std::move(g_pending.front());
            g_pending.pop_front();
        }

        for (auto st: m_activeLine){
            st->fill(os);
        }

        for(auto st: m_activeLine){
            st->attemptToMoveOrder();
        }


        if(g_completed.size() + g_incomplete.size() == m_cntCustomerOrder){
            success=true;
        }

        return success;

    }

    void LineManager::display(std::ostream& os) const{
        std::for_each(m_activeLine.begin(),m_activeLine.end(), [&](Workstation* st){st->display(os);});
    }
}