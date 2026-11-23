#include <iostream>
#include <string>
bool in_dictionary(std::string input_word){
    return true;
}
int letters_changed(std::string word1,std::string word2){
    int size=word1.length();
    int count =0;
    for(int i=0;i<size;i++){
        if (word1[i]!=word2[i]){
            count++;
        }
    }
    std::cout << "letters change from " << word1 << " to "<< word2 << " = "<< count <<"\n";
    return count;
}
bool is_correct_input(std::string input_word,std::string previous_word){
    return in_dictionary(input_word) && (letters_changed(input_word,previous_word)==1);
}

int main(){
    std::string words[1][2] ={{"COLD","WARM"}};
    int random=0;
    std::string start=words[random][0];
    std::string goal=words[random][1];
    const int limit =10;
    int tries=0;
    bool goal_achieved=false;
    std::string intermediate;
    std::cout<< "STARTING GAME\n" << start <<"->" << goal<<"\n";


    while((!goal_achieved) && tries<limit ){
    std::cout << "TURN "<<tries+1 << "\n";
    std::cin >> intermediate;
        if (is_correct_input(intermediate,start)){
            goal_achieved= intermediate==goal;
            std::cout << goal_achieved<<"\n";
            tries++;
            start=intermediate;
        }else{
            std::cout <<"INCORRECT INPUT!\n";
        }
    }
    return 0;
}