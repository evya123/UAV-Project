////
//// Created by evya on 12/21/18.
////
//
//#include "WhileCommand.h"
//
//void WhileCommand::doCommand(vector<string> &arguments, Data *d) {
//    auto it = arguments.begin();
//    vector<string> commandsTmp;
//    while (it != arguments.end()) {
//        if ((*it).compare(WHILE_CHECK) == 0) {
//            vector<string> conditionTmp;
//            while ((*it).compare(BRACKET)) {
//                if ((*it).compare(SEMICOLON) == 0) {
//                    ++it;
//                    continue;
//                }
//                conditionTmp.push_back(*it);
//                ++it;
//            }
//            m_conditions.push(conditionTmp);
//            if ((*it).compare(BRACKET) == 0) {
//                commandsTmp.push_back(BRACKET);
//                ++it;
//            }
//        }
//        while ((*it).compare(WHILE_CHECK) && it != arguments.end()) {
//            while ((*it).compare(SEMICOLON) && //While not semicolon or empty
//                   (*it).compare(CLOSING_BRACKET)) {
//                if ((*it).empty()) {
//                    continue;
//                }
//                commandsTmp.push_back(*it);
//                ++it;
//            }
//            if ((*it).compare(WHILE_CHECK) == 0)
//                continue;
//            if ((*it).compare(CLOSING_BRACKET) == 0) {
//                commandsTmp.push_back(CLOSING_BRACKET);
//                ++it;
//            }
//            if (!commandsTmp.empty()) {
//                m_commands.push(commandsTmp);
//                commandsTmp.clear();
//            }
//            ++it;
////            if ((*it).empty())
////                break;
//        }
//    }
//    vector<string> wCond = m_conditions.front();
//    while(Utils::checkCondition(wCond,d)) {
//        Utils::ifRecursion(m_commands,m_conditions,d,m_lp);
//    }
//    m_conditions.pop();
//}
//
//WhileCommand::WhileCommand(LexerParser *lp) {
//    m_lp = lp;
//}
