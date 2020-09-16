#include <string>
#include <vector>

// importing a whole namespace in a header is frowned upon
// this will at least let us write 'string'/'vector' below
using std::string;
using std::vector;

class BigInt {
   public:
      BigInt(string s);   // convert string to BigInt
      string to_string(); // get string representation
      void add(BigInt b); // add another BigInt to this one
      //int top_carry; 
    //extra credit 
    /*
      BigInt(string s, int base);
    */
    
   private:
      // whatever you need
    vector<int> number;
    int length;
    int seqdig;
    int size; 
    string numberstring;
    int sum;
    int top_carry;
    
    /*
     //extra credit
    string key;
    char seqchar;
    vector<char> charnumber;
    int stringtoint[];
    int xcarry, xsum, buffer; 
    */
 
        


};
