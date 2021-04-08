#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <array>
#include <stdlib.h> 

using namespace std;

// https://www.hackerrank.com/contests/mcs-ds-cs412-sp2021/challenges/clustering-agglomerative-hierarchical-clustering/problem

float Euclidean(float LAT1,float LAT2, float LONG1, float LONG2);
void Output(string the_output);

struct cluster{
int cluster_id;
vector<float> cluster_points_x;
vector<float> cluster_points_y;
};

struct compare_struct {
  bool operator() (int i,int j) { return (i<j);}
} comparator;


// maintain_index or create new addressing structure for additional operations/processing?



/*
templates exist to provide extensibility to classes and structs

if we know ahead of time the maximum we intend to support for each instance of a given class/struct
and we intend to process in parallel
it makes more sense to predefine all memory locations, and optimize operations not by creating and destroying objects
but rather by simply modifiying indexes
all states should be possible to be predefined
a system designed in this way is capable of fully defining its entire state as data / a state machine

this will also have the effect of isolating the data from the logic
the logic can then in turn become what is instantiated/modified.

this inversion should be familar to metaprogrammers.

with such a system we never need to process data, we can always append additional data with processing as needed.

magic or meta shifts are possible 

*/

int main(){
// N The number of data points (lines) following the first line .
// K The number of output clusters .
// M The cluster similarity measure to be used.  for single link,  for complete link,  for average link .



// Euclidean(LAT1, LAT2, LONG1, LONG2);





vector<cluster> clusters; 

string output;
int cluster_count=0;
int cluster_iterator=0;
vector<float> points_x;
//vector<float> init_points_y;
vector<float> points_y;
float min_distance=1000;

float distance;

//vector<int> ordered_index_points_x;
//vector<int> ordered_index_points_y;

vector<int> ordered_index_points;
    
    
vector<int> cluster_assigned;

int distance_index_i;
int distance_index_j;
/*
vector<float> ordered_points_x;
vector<float> ordered_points_y;

vector<float> cluster_assigned;
*/

int N;
int K;
int M;
cin >> N >> K >> M;

float last_x=0;
//float last_y=0;
for(int i=0;i<N;i++){
float x=0;
float y=0;
cin >> x >> y;
cluster_count++;
points_x.push_back(x);
points_y.push_back(y);
ordered_index_points.push_back(i);
//ordered_index_points_y.push_back(i);


    
// ensure points_x is sorted, change points_y to match this sorted index
//if(last_x > x){
//std::swap(points_x.at(i), points_x.at(i-1));   
//std::swap(points_y.at(i), points_y.at(i-1));   
//} //    if(last_x > x){
//last_x=x;

    
//init_points_y.push_back(x);
cluster_assigned.push_back(0);
} //    for(int i=0;i<N;i++){


   
// sort input 
//std::sort (points_x.begin(), points_x.end(), comparator);
for(int j=0;j<N;j++){
float x=0;
x=points_x.at(j);
for(int i=0;i<N;i++){
float y=0;
float z=0;
if(i!=j){
z=points_x.at(i);
    
    
// replace with matching index of sorted x values
if(x < z){
ordered_index_points_x.at(i);
ordered_index_points_y.at(i);
    
} //    if(x == z){
    
    
    
} //    if(i!=j){
} //    for(int i=0;i<N;i++){
} //    for(int j=0;j<N;j++){
    
    
    
/*
// sort input 
std::sort (points_x.begin(), points_x.end(), comparator);
for(int j=0;j<N;j++){
float x=0;
x=points_x.at(j);
for(int i=0;i<N;i++){
float y=0;
float z=0;
z=init_points_y.at(i);
// replace with matching index of sorted x values
if(x == z){
y=points_y.at();
init_points_y.at(i)=y;  
} //    if(x == z){
} //    for(int i=0;i<N;i++){
} //    for(int j=0;j<N;j++){
    
//std::sort (points_y.begin(), points_y.end(), comparator); 
    
// initial_clusters
  */  
    
output="number of clusters: ";
output.append(to_string(cluster_count));
Output(output);

output="N The number of data points (lines) following the first line: ";
output.append(to_string(N));
Output(output);

output="K The number of output clusters: ";
output.append(to_string(K));
Output(output);   

output="M The cluster similarity measure to be used.  0 for single link (min),  1 for complete link (max),  2 for average link (mean): ";
output.append(to_string(M));
Output(output);



for(int i=0;i<N;i++){
float x=0;
float y=0;
x=points_x.at(i);
y=points_y.at(i);
output="cluster: ";
output.append(to_string(i));
output.append("  x,y: ");
output.append(to_string(x));
output.append(",");
output.append(to_string(y));
Output(output);
} //    for(int i=0;i<N;i++){



//while((cluster_count + K) > K)
while(cluster_count > K)
{

// Single link: min
if(M==0){
  //  cluster_count--;
//cluster_count=K;
distance_index_i=0;
distance_index_j=0;
for(int j=0;j<N;j++){
distance=1000;
min_distance=1000;
float x=0;
float y=0;
x=points_x.at(j);
y=points_y.at(j);
for(int i=0;i<N;i++){
float x2=0;
float y2=0;
if(i!=j){
x2=points_x.at(i);
y2=points_y.at(i);
distance=Euclidean(x, x2, y, y2);
if(distance < min_distance){
min_distance=distance;
distance_index_i=i;
distance_index_j=j;
output="";
output.append(to_string(distance));
    output.append("\t");
    output.append(to_string(i));
        output.append("\t");
    output.append(to_string(j));
Output(output);
} //    if(distance < min_distance){
} //    if(i!=j){
} //    for(int i=0;i<N;i++){
output="";
output.append(to_string(distance));
output.append(" ");
output.append(to_string(distance_index_j));
output.append(to_string(distance_index_i));
Output(output);
//cluster_assigned.at(distance_index_j)=cluster_iterator;
    
    
for(int r=0;r<N;r++){
if(cluster_assigned.at(r) == distance_index_i){}
} //    for(int r=0;r<N;r++){
    
    
cluster_assigned.at(distance_index_j)=distance_index_i;

  // check if previously assigned clusters redirect here
 
} //    for(int j=0;j<N;j++){





} //    if(M==0){

//cluster_count=K;
cluster_count--;
cluster_iterator++;

} //    while(cluster_count > K)


for(int i=0;i<N;i++){
int x=0;
x=cluster_assigned.at(i);
output="";
output.append(to_string(x));
Output(output);
} //    for(int i=0;i<N;i++){


    
    
    
return 0;

/*

while(cluster_count > K)
{








} // while(cluster_count > K)





    for(int i=0;i<N;i++){
    float x=0;
    float y=0;
    cin >> x >> y;
    points_x.push_back(x);
    points_y.push_back(y);
    } //    for(int i=0;i<N;i++){

    // Single link: min
    if(M==0){
    float min_distance=1000;
    distance_index=0;
    distance=1000;
    for(int i=0;i<N+1;i++){
    float x=0;
    float y=0;
    float x1=0;
    float y2=0;
    x=points_x.at[i]];
    y=points_y.at[i]];
    x2=points_x.at[i+1]];
    y2=points_y.at[i+1]];
    distance=Euclidean(x, x2, y, y2);
    if(distance < min_distance){
    min_distance=distance;
    distance_index=i;
    } //    if(distance < min_distance){


    } //    for(int i=0;i<N;i++){

    x=points_x.at[distance_index]];
    y=points_y.at[distance_index]];
    x2=points_x.at[distance_index+1]];
    y2=points_y.at[distance_index+1]];
    ordered_points_x.push_back(x);
    ordered_points_y.push_back(y);
    cluster_count++;
    cluster one;
    one.cluster_id=cluster_count;
    one.cluster_points_x=;
    one.cluster_points_y=;
    clusters.push_back(one);

    } //     if(M==0){

    // Complete link: max
    if(M==1){



        
    } //     if(M==1){

    // Average link: mean
    if(M==2){



        
    } //     if(M==2){




    //vector<float> points_x;
     //vector<float> points_y;
    N++;
    const int array_size =100;
    
    int last_x_min;
        int last_y_min;
    int loop_n=N;

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
    
   
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   


    
}




float Euclidean(float LAT1,float LAT2, float LONG1, float LONG2){
float THE_LAT=LAT1-LAT2;
THE_LAT=THE_LAT*THE_LAT;
float THE_LONG=LONG1-LONG2;
THE_LONG=THE_LONG*THE_LONG;
float THE_INPUT=THE_LAT+THE_LONG;
return sqrt(THE_INPUT);
};

void Output(string the_output){cout<<the_output<<endl;}
