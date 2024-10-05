class Solution {
public:
// sliding windows based question O(n)
bool checkInclusion(string s1, string s2)
{
    vector<int> hash1(128, 0), hash2(128, 0);
    int n1 = s1.length(), n2 = s2.length();

    //condition to eliminate cases where s2 cant accomodate s1
    if (n1 > n2)
        return false;
    
    // we just add the hash for the window we wanna see, here we fill the hash2 only till n1-1 index 
    for (int i = 0; i < n1; i++)
    {
        hash1[s1[i]]++;
        hash2[s2[i]]++;
    }

    for (int i = 0; i <= n2 - n1; i++)
    {
        if (hash1 == hash2)
            return true;
        // remove the first element of the window one by one
        hash2[s2[i]]--;
        // addind the next element to the window one by one
        hash2[s2[i + n1]]++;

        // by this in one cases is hash matches then we r good to go
    }
    return false;
}

// this works as for a pallindrome the hash values will be exactly same thus we slide the window bit by bit to check if in any momement the hash matches
};