
#ifndef M1_LINEMANAGER_H
#define M1_LINEMANAGER_H
#include <vector>
#include <fstream>
#include <algorithm>
#include "Workstation.h"

namespace sdds {

    class LineManager {
        std::vector<Workstation*> m_activeLine {};
        size_t m_cntCustomerOrder {0u};
        Workstation* m_firstStation {nullptr};
    public:
        LineManager(const std::string& file, const std::vector<Workstation*>& stations);
        void reorderStations();
        bool run(std::ostream& os);
        void display(std::ostream& os) const;

    };

}
#endif //M1_LINEMANAGER_H
