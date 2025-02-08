class NumberContainers {
public:
    unordered_map<int,int>indexToNumber;
    unordered_map<int,set<int>> numberToIndices;
    NumberContainers() {}
    
    void change(int index, int number) {
        if(indexToNumber.count(index)){
            int prevNumber=indexToNumber[index];
            numberToIndices[prevNumber].erase(index);
            if(numberToIndices[prevNumber].empty()){
                numberToIndices.erase(prevNumber);
            }
        }
        indexToNumber[index]=number;
        numberToIndices[number].insert(index);      
    }
    
    int find(int number) {
        return numberToIndices.count(number)? *numberToIndices[number].begin():-1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
