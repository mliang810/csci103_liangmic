#ifndef PAGE_H
#define PAGE_H
#include <string>
#include <sstream>
#include <iostream>
using std::string;
#include<vector>
using std::vector;
class Page { 
public:
  Page();
  //set
  void setid(int idf);
  void seturl(string urlf);
  void setrank(double rankf);
  void setlinks(vector<int> linksf);
   
  //get
  int getid() const;
  string geturl() const;
  double getrank() const;
  vector<int> getlinks() const;
    
private:
  //Data members: id, url, pagerank, links , .. etc
    int id;
    string url;
    double rank;
    vector<int> links;
       
};  
#endif
