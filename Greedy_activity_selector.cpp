
#include <iostream>
#include <vector>
#include <algorithm>

/*
bool compare(const std::vector <std::pair<int, int> > &pair1, const std::vector< std::pair<int, int> > &pair2){
    int result = 0;
    if ( (pair2.first > pair1. first) || ((pair2.first == pair1.first) &&
        (pair2.second > pair1.second)) ) {
            result = 1;
        }
    return result;
}

*/

bool sortByFinish(const std::pair<int, int> &task1, const std::pair<int,int> &task2) {
    return (task1.second < task2.second);
}

std::vector<std::pair<int,int> > Greedy_Activity_Selector(int n, std::vector <std::pair<int, int> >tasks) {
    std::vector<std::pair<int, int> > selected;
    int i = 0;
    selected.push_back(tasks[i]);
    for (int j = 1; j < n; j++) {
        if (tasks[j].first >= tasks[i].second) {
            selected.push_back(tasks[j]);
            i = j;
        }
    } return selected;
}
/*
std::pair<int,int> * Greedy_Activity_Selector(int n, std::pair<int,int> tasks[n]) {
    
    std::pair<int,int> *selected = new std::pair<int, int>[n];
    int last_end = 0;
    int selected_size = 0;

    for (int i = 0; i < n; i++) {
        if(tasks[i].first >= last_end) {
            selected[selected_size++] = tasks[i];
            last_end = tasks[i].second;
        }
    } return selected;
}
*/
int main() {
    int n = 0;
    std::vector < std::pair<int, int> > tasks;
    std::cout << "Enter the number of activities" << std::endl;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        int x, y;
        std::cout << "Enter a start time: " << std::endl;
        std::cin >> x;
        std::cout << "Enter a finish time: " <<std::endl;
        std::cin >> y;
        tasks.push_back(std::make_pair(x,y));
    }
    for (int i = 0; i < n; i++) {
        std::cout << "(" << tasks[i].first << "," << tasks[i].second <<")";
    }
    /*
    std::sort(tasks.begin(), tasks.end(), [](auto &left, auto &right) {
        return left.second < right.second;
    });
    */
    
    sort(tasks.begin(), tasks.end(), sortByFinish);
    std::cout << std::endl;
    
    for (int i = 0; i < n; i++) {
        std::cout << "(" << tasks[i].first << "," << tasks[i].second <<")" ;
    }
    std::vector<std::pair<int, int> >selected = Greedy_Activity_Selector(n, tasks);
    std::cout << std::endl;
    std::cout << "The selected task intervals are : " << std::endl;
    for(int i = 0; i < selected.size(); i++) {
        std::cout << "(" << selected[i].first << "," << selected[i].second << ")";
    }
    return 0;
}
