#include "web.h"
#include <sstream>
#include <fstream>


Web::Web() 
{ 
   
}

Web::~Web() 
{ 
 
}

bool Web::read_graph(const char *filename) 
{ 
    ifstream ifile(filename);

    if(!ifile){
        return 0;
    }

    ifile >> npage;
    
    if(!ifile){
        ifile.close();
        return 0;
    }    
    else{ //file success
     
        for(int i = 0; i<npage; i++){
            
            int idf;
            string urlf;
            double rankf;
            vector<int> linksf;
            string temp;
            
            ifile >> idf >> urlf >> rankf;
            //read links int->o string via getline, from getline read into stringstream, then convert stringstream into vector<int>
            getline(ifile, temp);
            getline(ifile, temp);
            stringstream ss(temp);
            
            int buffer;
            
            while(ss >> buffer){
                linksf.push_back(buffer); 
            }
            //cout << idf << " " << urlf << " " << rankf <<" " << linksf.size()<< "\n";

            Page* createdPage = new Page;
            
            createdPage->setid(idf);
            createdPage->seturl(urlf);
            createdPage->setrank(rankf);
            createdPage->setlinks(linksf);
            list.push_back(createdPage);
        }
    }
    

    return 1;   

}

bool Web::write_graph(const char *filename)
{ 
    ofstream ofile(filename);
    
    
    ofile << npage << "\n";

    for(int i = 0; i<npage; i++){
        ofile << list[i]->getid() << endl;
        ofile << '\t' << list[i]->geturl() << '\n' << '\t' <<  list[i]->getrank() << '\n' << '\t';
            //need loop to get everything out of the vector
        
        vector<int> temp_links = list[i]->getlinks();
        for(unsigned int j = 0; j < temp_links.size(); j++){
            ofile << temp_links[j];
            if(j != temp_links.size()-1){
                ofile << " ";
            }
        }
        if(i != npage-1){
            ofile << endl;
        }
    }
    ofile.close();
    return 1;
}

void Web::calculate_rank(int S,int N)
{  
    for(int i = 0; i<npage; i++){
        walkers.push_back(0); 
    }

    //distribute walkers evenly
    for(int i = 0; i<npage; i++){
        int frac = N/npage;
        walkers[i] = frac;
        //distribute extras if theres uneven amount of walkers    
                
    }
    
    int rem = N%npage;
    if(rem !=0){
        for(int i = 0; i<npage; i++){
            if(rem!=0){
                walkers[i]+=1;
                rem--;
            }
        }
    } 
          //look below 
    //function to keep track of # of walkers at EACH index, amount will change with every simulation (Aka repetition)
    for(int j = 0; j<S; j++){
        for(int i = 0; i<npage; i++){
            int length = list[i]->getlinks().size(); 
            if(length != 0 && walkers[i]>0){
                //cout<< "I am" << i << " and I have" << walkers[i] << "\n";
                int random = (rand()%length);
                //cout << "i will give to" << list[i]->getlinks()[random] << "\n";
                walkers[list[i]->getlinks()[random]] +=1;
                //cout<< "XXXXX I am" << list[i]->getlinks()[random] << " and now I have" << walkers[list[i]->getlinks()[random]] << "\n";
                walkers[i] -=1; 
                //cout<< "I am" << i << " and now I have" << walkers[i] << "\n";
            }
            

        }
     }
    //establish empirical pagerank

    for(int i = 0; i<npage; i++){
        double walker_count = walkers[i];
        double proportion = walker_count/N;
        list[i]->setrank(proportion);
    }
    
}
