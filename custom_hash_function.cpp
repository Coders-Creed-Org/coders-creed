// NOTE: The following code is just for an explanation, it won't run wihtout a main function.

//Question is to group all anagrams togetger in a vector of vectors
class Solution
{
public:
    //way to define a custom hash function for any type of data structure as the key of the unordered map
    struct vector_hash
    {
        template <class T1>
        size_t operator()(vector<T1> const &v) const
        {
            return hash<T1>()(v.size());
        }
    };

    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> ans;

        unordered_map<vector<int>, vector<string>, vector_hash> mp;

        for (auto str : strs)
        {
            vector<int> freqmap(26, 0);
            for (auto c : str)
            {
                freqmap[c - 'a']++;
            }
            mp[freqmap].push_back(str);
        }

        for (auto freqm : mp)
        {
            vector<string> temp;
            for (auto s : freqm.second)
                temp.push_back(s);
            ans.push_back(temp);
        }

        return ans;
    }
};