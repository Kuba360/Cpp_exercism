#include "high_scores.h"

#include <algorithm>

namespace arcade {

std::vector<int> HighScores::list_scores() {
    // TODO: Return all scores for this session.
    return scores;
}

int HighScores::latest_score() {
    // TODO: Return the latest score for this session.
    return scores.back();
}

int HighScores::personal_best() {
    // TODO: Return the highest score for this session.
    return *(std::max_element(scores.begin(),scores.end()));
}

std::vector<int> HighScores::top_three() {
    std::vector<int> nv=scores;
    std::sort(nv.begin(),nv.end(),std::greater<int>());
    if(nv.size()>3){
        nv.erase(nv.begin()+3,nv.end());
    }
    return nv;
}

}  // namespace arcade
