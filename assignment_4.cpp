#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <array>
#include <stdlib.h> 

using namespace std;




int main() {
    
    //The number of data points (lines) following the first line .
//The number of output clusters .
//The cluster similarity measure  to be used.  for single link,  for complete link,  for average link.
    
  //  Single link: min


//Complete link: max


// Average link: mean


    
   int N;
int K;
    int M;
    int last_x_min;
        int last_y_min;
    int loop_n=N;
    
    cin >> N >> K >> M;
    //cout << N << "  " << K <<"  " << M << endl;
    cout << N << endl;
     cout << K << endl;
        cout << M << endl;
    //vector<float> points_x;
     //vector<float> points_y;
    N++;
    const int array_size =100;
    
    //array<float, 100> bucket;
    if(N > 100){cout << "bucket size exceeded" << endl;}
    
   // cout << array_size;
     array<float,array_size> points_x;
        array<float,array_size> points_y;
         array<float,array_size> ordered_points_x;
            array<float,array_size> ordered_points_y;
                array<int,array_size> cluster_assigned;
    // read in all points to arrays
    for(int x=0;x<N-1;x++){
        cin >> points_x[x] >> points_y[x]; 
ordered_points_x[x]=points_x[x];
    ordered_points_y[x]=points_y[x];
    }
    
    
        for (int i = 1; i < N; ++i)
        {
        for (int j = i; j > 0 && ordered_points_x[j] > ordered_points_x[j-1] && ordered_points_x[j] != 0 && ordered_points_x[j-1] != 0; --j)
        {
            std::swap(ordered_points_x[j], ordered_points_x[j-1]);
            std::swap(ordered_points_y[j], ordered_points_y[j-1]);
            //cout << ordered_points_x[j] << "less than " << ordered_points_x[j-1] << endl;
        }
        }
    
    cout << "ee" << endl;
                        for(int x=0;x<N-1;x++){
                cout <<  ordered_points_x[x] << "           " << ordered_points_y[x] << endl;
    }
    
    cout << "rr" << endl;
    
    int iterator=K;
    int range = ordered_points_x[0] + abs(ordered_points_x[N-2]);
    int spot = int(range/K);
    cout << "init spot " << spot << endl;
    spot=int(spot/2);
    
    //cout << "abs " << abs(ordered_points_x[N-2]) << endl;
     cout << "range " << range << endl;
         cout << "spot " << spot << endl;
    
    int current=0;
    vector<float> spots;
    current=ordered_points_x[0] - spot;
    for (int i = 0; i < K; ++i){
        
        
    //spots.push_back(spot);
        cout << current << endl;
        current=current-spot*K;
      //  cout << spots[i-1] << endl;
        }
    
    
    
    
   // for (int i = 1; i < K; ++i){
  //  cout << spots.at(i-1) << endl;
        
  //  }
    //cout << spot << endl;
    
    //spot
    
    while(iterator>0){
    //if(){}
        
         for (int i = 1; i < N; ++i){
        
            
             }
   // cluster_assigned[];
    
    
    iterator--;
    }
    
   // cout << endl;
    
   /*
        for (int i = 0; i < array_size; ++i)
        {
        for (int j = i; j > 0 && ordered_points_y[j] < ordered_points_y[j-1]; --j)
        {
            std::swap(ordered_points_y[j], ordered_points_y[j-1]);
        }
        }
    
    //int n = sizeof(ordered_points_x) / sizeof(ordered_points_x[0]); 
    //sort(ordered_points_x,ordered_points_x + n, float;
    //sort(ordered_points_y);
    //sort(ordered_points_x,ordered_points_x + array_size);
    //sort(ordered_points_y,ordered_points_y + array_size);
    
    
    //            for(int x=0;x<N;x++){
    //            cout <<  points_x[x] << " ";
   // }
   // cout << endl;
   

    
   //               for(int x=0;x<N;x++){
   //             cout <<  points_y[x] << " ";
   // }
   // cout << endl;
   
                    for(int x=0;x<N;x++){
                cout <<  ordered_points_y[x] << " ";
    }
    cout << endl;  
        // read in all points to arrays
    //for(int x=0;x<N;x++){
     //   points_x[x] 
      //  ordered_points_x=sort(points_x)
            
            
        //    >> points_y[x]; 
   // }
    
      //  Single link: min
    if(M == 0){

        
        
    };
    
    //Complete link: max
        if(M == 1){};
    
    // Average link: mean
        if(M == 2){};
    
   // for(int x=0;x<N;x++){
    //   points_x[x] >> points_y[x];  
   // }
    
    */
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}




