// Name: Ali Riza Sevgili
// Seneca Student ID: 135200228
// Seneca email: arsevgili@myseneca.ca
// Date of completion: 04/05/2024
// I confirm that I am the only author of this file and the content was created entirely by me.



#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "LineManager.h"
#include "Utilities.h"

using namespace std;

namespace seneca {

    LineManager::LineManager(const std::string& file,const std::vector<Workstation*>& stations) {
        fstream fs(file);
        Utilities ut;
        string str, item, nextItem;

        if (fs) {
            Workstation* curStation{};
            Workstation* nextStation{};
            Workstation* firstStation{};

            while (getline(fs, str)) {
                bool more = true;
                size_t pos{};

                item = ut.extractToken(str, pos, more);

                curStation = *find_if(stations.begin(), stations.end(), [&](Workstation* s) {
                    return s->getItemName() == item;
                });

                m_activeLine.push_back(curStation);

                if (more != false) {
                    nextItem = ut.extractToken(str, pos, more);
                    nextStation = *find_if(stations.begin(), stations.end(), [&](Workstation* s) {
                        return s->getItemName() == nextItem;
                    });

                    curStation->setNextStation(nextStation);
                }
            }

            for_each(stations.begin(), stations.end(), [&](Workstation* s) {
                firstStation = *find_if(stations.begin(), stations.end(), [&](Workstation* s) {
                return s->getNextStation() == firstStation;
            });
            });
            m_firstStation = firstStation;

        } else {
            throw ("ERROR: unable to open file");
        }

        fs.close();
        m_cntCustomerOrder = g_pending.size();
    }

    void LineManager::reorderStations() {
        Workstation* stn = m_firstStation;
        vector<Workstation*> orderedLine;
        while (stn) {
            orderedLine.push_back(stn);
            stn = stn->getNextStation();
        }
        m_activeLine = orderedLine;
    }

    bool LineManager::run(ostream& os) {
        bool res{};

        static size_t count = 0;
        os << "Line Manager Iteration: " << ++count << endl;

        if (!g_pending.empty()) {
            *m_activeLine.front() += move(g_pending.front());
            g_pending.pop_front();
        }

        for (auto& i : m_activeLine)
            i->fill(os);
        for (auto& i : m_activeLine)
            i->attemptToMoveOrder();

        if (g_completed.size() + g_incomplete.size() == m_cntCustomerOrder) res = true;

        return res;
    }

    void LineManager::display(ostream& os) const {
        for (auto& i : m_activeLine)
            i->display(os);
    }
}