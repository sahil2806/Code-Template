class KarpRabin {
  private:
    const int PRIME = 107;

    // Function to calculate hash value of a string
    double calculateHash(const string& str) {
        double hash = 0;
        for (int i = 0; i < str.length(); i++) {
            hash += str[i] * pow(PRIME, i);
        }
        return hash;
    }

    // Function to update the hash value when sliding the window
    double updateHash(double prevHash, char oldChar, char newChar, int patternLength) {
        double newHash = (prevHash - oldChar) / PRIME;
        newHash = newHash + newChar * pow(PRIME, patternLength - 1);
        return newHash;
    }

  public:
    // Function to search for the pattern in the text
    int search(const string& text, const string& pattern) {
        int patternLength = pattern.length();
        int textLength = text.length();

        double patternHash = calculateHash(pattern);
        double textHash = calculateHash(text.substr(0, patternLength));

        for (int i = 0; i <= textLength - patternLength; i++) {
            if (textHash == patternHash) {
                if (text.substr(i, patternLength) == pattern) {
                   return i;
                }
            }

            if (i < textLength - patternLength) {
                textHash = updateHash(textHash, text[i], text[i + patternLength], patternLength);
            }
        }
        return -1;
    }
};

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        
         KarpRabin obj;
         vector<string> ans;
         int n = words.size();
         for(int i=0;i<n;i++){
            string text = words[i];
            for(int j=0;j<n;j++){
                if(text != words[j] ){
                    int response = obj.search(words[j],text);
                    if(response != -1){
                        ans.push_back(text);
                        break;
                    }
                }
            }
         }

         return ans;
    }
};
