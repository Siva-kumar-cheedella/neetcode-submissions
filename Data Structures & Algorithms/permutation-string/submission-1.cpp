class Solution {
public:
    bool areMapsSame(map<char, int> smap, map<char, int> tmap){
        for(auto& i:smap){
            if(tmap.find(i.first) == tmap.end() || tmap[i.first]!=smap[i.first]) return false;
        }

        return true;
    }
    bool checkInclusion(string s1, string s2) {
        
        if(s1.length()>s2.length()) return false;
        map<char, int> smap, tmap;

        for(int i=0; i<s1.size(); i++){
            if(smap.find(s1[i]) == smap.end()){
                smap[s1[i]] = 1;
            }else{
                smap[s1[i]] ++;
            }
        }

        int l=0;
        int r=0;

        while(r < s1.length()){
            if(tmap.find(s2[r]) == tmap.end()){
                tmap[s2[r]] = 1;
            }else{
                tmap[s2[r]]++;
            }
            r++;
        }
        r--;
        // cout<< l << " " << r<<endl;

        while(r < s2.size()){
            if(areMapsSame(smap, tmap)){
                // cout<< l << " " << r << endl;
                // for(auto& i : smap){
                //     cout << "smap: "<< i.first << "  " << i.second<<endl;
                // }
                // for(auto& i : tmap){
                //     cout << "tmap: "<< i.first << "  " << i.second<<endl;
                // }
                return true;
            }
            tmap[s2[l]]--;
            l++;
            r++;
            if(r < s2.size()){
                if(tmap.find(s2[r]) == tmap.end()){
                    tmap[s2[r]] =1;
                }else{

                tmap[s2[r]]++;
                }
            }
        }
        return false;
    }
};
