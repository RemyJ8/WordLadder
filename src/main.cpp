#include <iostream>
#include <string>
#include <unordered_set>
#include <fstream>
std::unordered_set<std::string>  dictionary;

bool load_dictionary(int word_length ){
    
    std::string filename = "data/processed/dictionary_" + std::to_string(word_length) + "_letters.txt";
    std::cout << filename <<"\n";
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Could not open dictionary file\n";
        return 0;
    }

    std::string word;
    while (std::getline(file, word)) {
        (dictionary).insert(word);
    }

    file.close();

    std::cout << "Loaded " << (dictionary).size() << " words\n";
    return 1;
}

bool in_dictionary(std::string search){

    if (dictionary.find(search) != dictionary.end()) {
        std::cout << search << " exists!\n";
        return 1;
    } else {
        std::cout << search << " does not exist!\n";
    }
    return 0;
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
    std::string words[1][2] ={{"cold","warm"}};
    int random=0;
    std::string start=words[random][0];
    std::string goal=words[random][1];
    if (!load_dictionary(4)){return -1;}
    const int limit =10;
    int tries=0;
    bool goal_achieved=false;
    std::string intermediate;
    std::cout<< "STARTING GAME\n" << start <<"->" << goal<<"\n";


    while((!goal_achieved) && tries<limit ){
    std::cout << "CURRENT WORD "<< start <<"\n";
    std::cout << "TURN "<<tries+1 << "\n";
    std::cin >> intermediate;
    //intermediate=to_lowercase(intermediate)
        if (is_correct_input(intermediate,start)){
            goal_achieved= intermediate==goal;
            //std::cout << goal_achieved<<"\n";
            tries++;
            start=intermediate;
        }else{
            std::cout <<"INCORRECT INPUT!\n";
        }
    }

    if (goal_achieved) {
        std::cout << "WELL DONE !!\n";
    }else{
        std::cout << "LIMIT REACHED";
    }

    return 0;
}