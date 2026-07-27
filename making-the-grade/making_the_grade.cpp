#include <array>
#include <string>
#include <vector>

// Round down all provided student scores.
std::vector<int> round_down_scores(std::vector<double> student_scores) {
    size_t l=student_scores.size();
    std::vector<int> nv;
    for(size_t i=0;i<l;i++){
        nv.emplace_back(static_cast<int>(student_scores[i]));
    }
    return nv;
}

// Count the number of failing students out of the group provided.
int count_failed_students(std::vector<int> student_scores) {
    int n=0;
    size_t l=student_scores.size();
    for(size_t i=0;i<l;i++){
        if(student_scores[i]<41){
            n++;
        }
    }
    return n;
}

// Create a list of grade thresholds based on the provided highest grade.
std::array<int, 4> letter_grades(int highest_score) {
    std::array<int,4> tab{41,0,0,0};
    for(size_t i=1;i<4;i++){
        tab[i]=tab[i-1]+((highest_score-40)/4);
    }
    return tab;
}

// Organize the student's rank, name, and grade information in ascending order.
std::vector<std::string> student_ranking(
    std::vector<int> student_scores, std::vector<std::string> student_names) {
    std::vector<std::string> ns;
    size_t l=student_scores.size();
    int rank=1;
    for(size_t i=0;i<l;i++){
        ns.emplace_back(std::to_string(rank++)+". "+student_names[i]
        +": "+std::to_string(student_scores[i]));
    }
    return ns;
}

// Create a string that contains the name of the first student to make a perfect
// score on the exam.
std::string perfect_score(std::vector<int> student_scores,
                          std::vector<std::string> student_names) {
    size_t l=student_names.size();
    for(size_t i=0;i<l;i++){
        if(student_scores[i]==100){
            return student_names[i];
        }
    }
    return "";
}
