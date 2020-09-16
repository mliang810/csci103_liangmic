#include "page.h"
#include <sstream>
#include <iostream>

Page::Page()
{
    
    id = 0;
    url = "";
    rank = 0.0;
}

//setters (mutator)
void Page::setid(int idf)
{
  id = idf;
}

void Page::seturl(string urlf)
{
  url = urlf;
}

void Page::setrank(double rankf)
{
  rank = rankf;
}

void Page::setlinks(vector<int> linksf)
{
  links = linksf;
}


//getters (Accessor) 
     
int Page::getid() const
{
  return id;
}

string Page::geturl() const
{
  return url;
}

double Page::getrank() const
{
  return rank;
}

vector<int> Page::getlinks() const
{
  return links;
}




