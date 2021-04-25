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

void Output(string the_output, bool is_on);

struct cluster{
int cluster_id;
vector<float> cluster_points_x;
vector<float> cluster_points_y;
bool is_valid;
};

struct ordered_index_points{
vector<float> cluster_points_x;
vector<float> cluster_points_y;
};


struct distances{
vector<float> cluster_distances;
};

void Output_all_clusters(vector<cluster> clusters);

void Output_all_distances(distances dist);

int main(){

distances dist;

vector<int> output_clusters;

float min_distance=9999;
float max_distance=0;


bool is_on=false;
vector<int> valid_clusters; 
ordered_index_points oip;
vector<cluster> clusters; 
string output;
int cluster_count=0; 
int N;
int K;
int M;
cin >> N >> K >> M;
// N The number of data points (lines) following the first line .
// K The number of output clusters .
// M The cluster similarity measure to be used.  for single link,  for complete link,  for average link .

// initialize_clusters
for(int i=0;i<N;i++){
float x=0;
float y=0;
cin >> x >> y;
oip.cluster_points_x.push_back(x);
oip.cluster_points_y.push_back(y);
cluster a;
a.cluster_id=i;
a.cluster_points_x.push_back(x);
a.cluster_points_y.push_back(y);
a.is_valid=true;
clusters.push_back(a);
cluster_count++;
} //    for(int i=0;i<N;i++){
    
   
    
int loop_cluster_count=cluster_count; 
while(loop_cluster_count >= K)
{
output="";
output="top of loop\tloop_cluster_count: ";
output.append(to_string(loop_cluster_count));
output.append("\tK\t");
output.append(to_string(K));
Output(output,is_on);



float distance;
for(int j=0;j<cluster_count;j++){

output="";
output.append("\tcluster_count\t");
output.append(to_string(cluster_count));
Output(output,is_on);


int cluster_merge_candidate=0; 
float x=0;
float y=0;  
int reentrant_cluster_size=0;
int re_reentrant_cluster_size=0;
cluster at;
at=clusters.at(j);
// guard agianst old unmerged / merged cluster tomestones
if(at.is_valid){

min_distance=99999;
max_distance=0;

// determine_if_multiple_points_are_assigned_to_this_inner_cluster
reentrant_cluster_size=at.cluster_points_x.size(); 
for(int z=0;z<reentrant_cluster_size;z++){




x=at.cluster_points_x.at(z);
y=at.cluster_points_y.at(z);

for(int i=0;i<cluster_count;i++){
float x2=0;
float y2=0;
cluster iat=clusters.at(i);
if(iat.is_valid){
if(i!=j){

re_reentrant_cluster_size=iat.cluster_points_x.size(); 
for(int zz=0;zz<re_reentrant_cluster_size;zz++){
x2=iat.cluster_points_x.at(zz);
y2=iat.cluster_points_y.at(zz);

// calculate the distance between at and iat clusters
distance=Euclidean(x, x2, y, y2);

dist.cluster_distances.push_back(distance);

// Single link: min
if(M==0){
if(distance < min_distance){
min_distance=distance;
cluster_merge_candidate=i;
} //    if(distance < min_distance){
} // if(M==0){

// complete link (max)
if(M==1){
if(distance > max_distance){
max_distance=distance;
cluster_merge_candidate=i;
} //    if(distance < min_distance){
} // if(M==1){

// average link (mean)
if(M==2){
if(distance < min_distance){
min_distance=distance;
cluster_merge_candidate=i;
} //    if(distance < min_distance){
} // if(M==2){


} // for(int zz=0;zz<re_reentrant_cluster_size;zz++){

} // if(i!=j){
} // if(iat.is_valid){
} // for(int i=0;i<cluster_count;i++){


} //    for(int z=0;z<reentrant_cluster_size;z++){




// append all j's points to the growing cluster cluster_merge_candidate
for(auto itr : at.cluster_points_x){
clusters.at(cluster_merge_candidate).cluster_points_x.push_back(itr);
} // for(auto itr : at.cluster_points_x){

for(auto itr : at.cluster_points_y){
clusters.at(cluster_merge_candidate).cluster_points_y.push_back(itr);
} // for(auto itr : at.cluster_points_y){


// tombstone_merged_cluster 
clusters.at(j).is_valid=false;


output="";
output.append(" adding x: ");
output.append(to_string(x));
output.append(" adding y: ");
output.append(to_string(y));
output.append(" cluster_merge_candidate : ");
output.append(to_string(cluster_merge_candidate));
output.append(" j : ");
output.append(to_string(j));
Output(output,false);
    


    
loop_cluster_count--;
output="";
output.append("loop_cluster_count: ");
output.append(to_string(loop_cluster_count));
Output(output,false);
    
    
//Ensure_continous_cluster_index_for_valid_clusters(clusters);
//if(is_on){Output_all_clusters(clusters);}
        
output="";   
output="bottom of loop\tloop_cluster_count:";
output.append(to_string(loop_cluster_count));
output.append("\tK\t");
output.append(to_string(K));
Output(output,false);


} //    if(at.is_valid){

if(! at.is_valid){
output="";
output="invalid\t";
output.append(to_string(at.cluster_id));
Output(output,is_on);
} //    if(! at.is_valid){

if(loop_cluster_count <= K){            
output="";
output="\tbreak\t";
Output(output,is_on);
break;
} //    if(loop_cluster_count < K){                    
} //    for(int j=0;j<cluster_count;j++){


if(loop_cluster_count <= K){            
output="";
output="\tbreak\t";
Output(output,is_on);
break;
} //    if(loop_cluster_count < K){ 


} //    while(loop_cluster_count > K)

   
output="exit main loop";
Output(output,false);


// add all valid cluster_id's to valid_clusters
for(auto itr : clusters){
if(itr.is_valid){
valid_clusters.push_back(itr.cluster_id);
} // if(itr.is_valid){
} // for(auto itr : clusters){

int final_cluster_size=0;

int cluster_size=oip.cluster_points_x.size(); 
for(int z=0;z<cluster_size;z++){


// output_final_clusters_data
for(auto itr : valid_clusters){
float x=0;
float y=0;
cluster at;
at=clusters.at(itr);


final_cluster_size=clusters.at(itr).cluster_points_x.size(); 
for(int j=0;j<final_cluster_size;j++){

x=at.cluster_points_x.at(j);
y=at.cluster_points_y.at(j);

if(oip.cluster_points_x.at(z) == x && oip.cluster_points_y.at(z) == y){

output_clusters.push_back(at.cluster_id);
//if(last != at.cluster_id){final_cluster_iterator++;}
//last=at.cluster_id;
} // if(oip.cluster_points_x.at(z) == x && oip.cluster_points_y.at(z) == y){

} //    for(int j=0;j<final_cluster_size;j++){    

} //    for(auto itr : valid_clusters){

} //    for(int z=0;z<cluster_size;z++){  

bool iterate_last_lowest=false;
//bool contains_lowest=false;
int is_lowest=0;
int last_lowest=0;
int output_cluster_size=output_clusters.size(); 
for(int i=0;i<final_cluster_size;i++){ 

/*
for(int j=0;j<output_cluster_size;j++){   
int oc=output_clusters.at(j);
if(oc==last_lowest){
   contains_lowest=true;
         for(int i=0;i<output_cluster_size;i++){ 
output="";
output.append(to_string(output_clusters.at(i)));
Output(output,true); 
} // for(int i=0;i<output_cluster_size;i++){ 
   
   } // if(oc==last_lowest){
} // for(int j=0;j<output_cluster_size;j++){  
if(! contains_lowest){


   output="";
output.append(to_string(final_cluster_size));
Output(output,true); 
*/



int this_oc=output_clusters.at(is_lowest);
iterate_last_lowest=false;
for(int j=0;j<output_cluster_size;j++){   
int oc=output_clusters.at(j);
if(oc==this_oc){
  // if(last_lowest==0){output_clusters.at(j)=last_lowest;}
 // if(last_lowest!=0){output_clusters.at(j)=last_lowest;}

output_clusters.at(j)=last_lowest;
iterate_last_lowest=true;
//output="";
//output.append(to_string(output_clusters.at(j)));
//Output(output,true); 
   
   } // if(oc==this_oc){
} // for(int j=0;j<output_cluster_size;j++){  

//} // if(! contains_lowest){
////contains_lowest=false;   
is_lowest++;

if(iterate_last_lowest){
   last_lowest=last_lowest+1;
 

/*
   output="";
output.append("\nlast lowest ");
output.append(to_string(last_lowest));
Output(output,true);
//this_oc=output_clusters.at(last_lowest);
for(int j=0;j<output_cluster_size;j++){   
int oc=output_clusters.at(j);
if(last_lowest==this_oc){
  // if(last_lowest==0){output_clusters.at(j)=last_lowest;}
 // if(last_lowest!=0){output_clusters.at(j)=last_lowest;}

output_clusters.at(j)=last_lowest;
iterate_last_lowest=true;
//output="";
//output.append(to_string(output_clusters.at(j)));
//Output(output,true); 
   
   } // if(oc==this_oc){
} // for(int j=0;j<output_cluster_size;j++){  


output="\n\n";
Output(output,true); 
*/


   } // if(iterate_last_lowest){


//output="";
//output.append(to_string(is_lowest));
//Output(output,true); 
} // for(int i=0;i<output_cluster_size;i++){ 






for(int i=0;i<output_cluster_size;i++){ 
output="";
output.append(to_string(output_clusters.at(i)));
Output(output,true); 
} // for(int i=0;i<output_cluster_size;i++){ 


//Output_all_clusters(clusters);   
//Output_all_distances(dist);

return 0;
} // int main(){


float Euclidean(float LAT1,float LAT2, float LONG1, float LONG2){
float THE_LAT=LAT1-LAT2;
float this_lat;
this_lat=THE_LAT*THE_LAT;
float THE_LONG=LONG1-LONG2;
float this_long;
this_long=THE_LONG*THE_LONG;
//float THE_INPUT=this_lat+this_long;
return sqrt(this_lat+this_long);
}; //   float Euclidean(float LAT1,float LAT2, float LONG1, float LONG2){


void Output(string the_output,bool is_on){if(is_on){cout<<the_output<<endl;}}


void Output_all_clusters(vector<cluster> clusters){
    cout<<endl;
    cout<< "-------------------------"<<endl;
for (auto & cluster : clusters) { 
    if(cluster.is_valid){
 cout<<endl;
    cout<< "cluster_id: ";
 cout<<to_string(cluster.cluster_id)<<endl;        
int cluster_size=cluster.cluster_points_x.size(); 
for(int z=0;z<cluster_size;z++){

    cout<< "cluster_points_x: ";
 cout<<to_string(cluster.cluster_points_x.at(z));
    cout<< "\tcluster_points_y: ";
 cout<<to_string(cluster.cluster_points_y.at(z))<<endl; 
} //    for(int z=0;z<cluster_size;z++){
    }
      

 } //     for (auto & cluster : clusters) { 
       cout<< "-------------------------" <<endl;
}; //   void Output_all_clusters(vector<cluster> clusters){
                 

void Output_all_distances(distances tdist){
    cout<<endl;
    cout<< "-------------------------"<<endl;

int index=0;
for (auto & dis : tdist.cluster_distances) { 

 cout<<endl;
    cout<< "distance at " << to_string(index)<<": ";
 cout<<to_string(dis)<<endl;        
index++;
    }
      


       cout<< "-------------------------" <<endl;
}; //   void Output_all_clusters(vector<cluster> clusters){
