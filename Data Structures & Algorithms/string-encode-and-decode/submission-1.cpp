class Solution {
public:

    string encode(vector<string>& strs) {
        string transportString = "";
        string sizeStr = "";
        int totalSize = 0;
        for(auto& str: strs){
            transportString+=str;
            sizeStr+=","+to_string(str.length())+",";
            totalSize+=str.length();
        }
        return transportString+sizeStr+"#"+to_string(totalSize);
    }

    vector<string> decode(string s) {
        vector<string> decodedList;
        
        string totalLength = "";
        int rtolPtr = s.length()-1;
        
        while(s[rtolPtr] != '#'){
            rtolPtr--;
        }
        
        totalLength = s.substr(++rtolPtr);

        int totalLenInt = stoi(totalLength);

        string encodedStr = s.substr(0, totalLenInt);
        string wordSizes = s.substr(totalLenInt, rtolPtr - totalLenInt);
        vector<int> sizes;

        for(int i=0; i<wordSizes.length(); i++){
            if(wordSizes[i]==','){
                i++;
                string size="";
                while(wordSizes[i]!=','){
                    size+=wordSizes[i];
                    i++;
                }
                sizes.push_back(stoi(size));
            }
        }

        int startIndex = 0; 
        for(auto& size:sizes){
            string word = encodedStr.substr(startIndex, size);
            decodedList.push_back(word);
            startIndex=startIndex+size;
        }

        return decodedList;
    }
};
