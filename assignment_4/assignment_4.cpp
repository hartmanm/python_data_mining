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
float centroid_x;
float centroid_y;
bool is_valid;
};

struct ordered_index_points{
vector<float> cluster_points_x;
vector<float> cluster_points_y;
};


void Output_all_clusters(vector<cluster> clusters);

void Ensure_continous_cluster_index_for_valid_clusters(vector<cluster> clusters);

int main(){
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
a.centroid_x=x;
a.centroid_y=y;
clusters.push_back(a);
cluster_count++;
} //    for(int i=0;i<N;i++){
    
    
    
/*
    
// initial_clusters_meta_info
output="number of clusters: ";
output.append(to_string(cluster_count));
Output(output,is_on);

output="N The number of data points (lines) following the first line: ";
output.append(to_string(N));
Output(output,is_on);

output="K The number of output clusters: ";
output.append(to_string(K));
Output(output,is_on);   

output="M The cluster similarity measure to be used.  0 for single link (min),  1 for complete link (max),  2 for average link (mean): ";
output.append(to_string(M));
Output(output,is_on);

// output_initial_clusters_data
for(int i=0;i<N;i++){
float x=0;
float y=0;
cluster at;
//if(clusters.at(i) != nullptr)
//{
at=clusters.at(i);
x=at.cluster_points_x.at(0);
y=at.cluster_points_y.at(0);
output="cluster: ";
output.append(to_string(i));
output.append("  x,y: ");
output.append(to_string(x));
output.append(",");
output.append(to_string(y));
Output(output,is_on);
//} //    if(clusters.at(i) != nullptr)
} //    for(int i=0;i<N;i++){

*/ 
    
    
int loop_cluster_count=cluster_count; 
while(loop_cluster_count >= K)
{
output="";
output="top of loop\tloop_cluster_count: ";
output.append(to_string(loop_cluster_count));
output.append("\tK\t");
output.append(to_string(K));
Output(output,is_on);










/*
// recalculate the centroid for the first cluster
int final_cluster_size=clusters.at(0).cluster_points_x.size();
float x_total=0;
float y_total=0;
for(int i=0;i<final_cluster_size;i++){
x_total+=clusters.at(0).cluster_points_x.at(i);
y_total+=clusters.at(0).cluster_points_y.at(i);
output="";
output.append("inital_cluster_size: ");
output.append(to_string(final_cluster_size));
output.append(" x_total: ");
output.append(to_string(x_total));
output.append(" y_total: ");
output.append(to_string(y_total));
output.append(" i: ");
output.append(to_string(i));
Output(output,is_on);
} // for(int i=0;i<final_cluster_size;i++){
clusters.at(0).centroid_x=x_total/final_cluster_size;
clusters.at(0).centroid_y=y_total/final_cluster_size;
*/


for(int j=0;j<cluster_count;j++){
int cluster_merge_candidate=0; 
float x=0;
float y=0;  
int reentrant_cluster_size=0;
int re_reentrant_cluster_size=0;
cluster at;
at=clusters.at(j);
if(at.is_valid){

// outer centroids itr



/*
// add all valid cluster_id's to valid_clusters
for(auto itr : clusters){
if(itr.is_valid){
valid_clusters.push_back(itr.cluster_id);
} // if(itr.is_valid){
} // for(auto itr : clusters){
*/

// iterate over all points in the cluster
//for(auto itr : at.cluster_points_x){




// determine_if_multiple_points_are_assigned_to_this_inner_cluster
reentrant_cluster_size=at.cluster_points_x.size(); 
for(int z=0;z<reentrant_cluster_size;z++){
x=at.cluster_points_x.at(z);
y=at.cluster_points_y.at(z);



//x=at.cluster_points_x.at(j);
//y=at.cluster_points_y.at(j);
//x=clusters.at(j).centroid_x;
//y=clusters.at(j).centroid_y;

float distance=1000;
float min_distance=1000;
float max_distance=0;
// inner loop
//for(int i=j+1;i<cluster_count;i++){
for(int i=0;i<cluster_count;i++){
float x2=0;
float y2=0;
cluster iat=clusters.at(i);
if(iat.is_valid){
if(i!=j){
//x2=clusters.at(i).centroid_x;
//y2=clusters.at(i).centroid_y;
//for(auto itr : iat.cluster_points_x){
//x2=itr.cluster_points_x.at();
//y2=itr.cluster_points_y.at(j);

re_reentrant_cluster_size=iat.cluster_points_x.size(); 
for(int zz=0;zz<re_reentrant_cluster_size;zz++){
x2=iat.cluster_points_x.at(zz);
y2=iat.cluster_points_y.at(zz);







distance=Euclidean(x, x2, y, y2);



// Single link: min
if(M==0){
if(distance < min_distance){
min_distance=distance;
cluster_merge_candidate=i;

output="distance: ";
output.append(to_string(distance));
output.append(" from: ");
output.append(to_string(at.cluster_id));
output.append(" to: ");
output.append(to_string(iat.cluster_id));
output.append(" cluster_count: ");
output.append(to_string(cluster_count));
Output(output,true);
} //    if(distance < min_distance){
} // if(M==0){

// complete link (max)
if(M==1){
if(distance > max_distance){
max_distance=distance;
cluster_merge_candidate=i;

output="distance: ";
output.append(to_string(distance));
output.append(" from: ");
output.append(to_string(at.cluster_id));
output.append(" to: ");
output.append(to_string(iat.cluster_id));
output.append(" cluster_count: ");
output.append(to_string(cluster_count));
Output(output,true);
} //    if(distance > max_distance){
} // if(M==1){

// average link (mean)
if(M==2){
if(distance > max_distance){
max_distance=distance;
cluster_merge_candidate=i;
} //    if(distance > max_distance){
} // if(M==1){


} // for(int zz=0;<re_reentrant_cluster_size;zz++){


} // if(i!=j){
} // if(iat.is_valid){
} // for(int i=0;i<cluster_count;i++){


} //    for(int z=0;z<reentrant_cluster_size;z++){




// merge_the_closest_two_clusters
// set_the_at_struct_to_the_inner_candidate
//at=clusters.at(cluster_merge_candidate);


// append all j's points to the growing cluster cluster_merge_candidate
at=clusters.at(j);
for(auto itr : at.cluster_points_x){
clusters.at(cluster_merge_candidate).cluster_points_x.push_back(itr);
} // for(auto itr : clusters){
for(auto itr : at.cluster_points_y){
clusters.at(cluster_merge_candidate).cluster_points_y.push_back(itr);
} // for(auto itr : clusters){




// recalculate the centroid for the growing cluster
int final_cluster_size=clusters.at(cluster_merge_candidate).cluster_points_x.size();
float x_total=0;
float y_total=0;
for(int i=0;i<final_cluster_size;i++){
x_total+=clusters.at(cluster_merge_candidate).cluster_points_x.at(i);
y_total+=clusters.at(cluster_merge_candidate).cluster_points_y.at(i);
output="";
output.append("final_cluster_size: ");
output.append(to_string(final_cluster_size));
output.append(" x_total: ");
output.append(to_string(x_total));
output.append(" y_total: ");
output.append(to_string(y_total));
output.append(" i: ");
output.append(to_string(i));
Output(output,false);
} // for(int i=0;i<final_cluster_size;i++){
clusters.at(cluster_merge_candidate).centroid_x=x_total/final_cluster_size;
clusters.at(cluster_merge_candidate).centroid_y=y_total/final_cluster_size;



// if merged cluster has already iterated append a copy to clusters and invalidate the original
if(clusters.at(cluster_merge_candidate).cluster_id <= j){
cluster copy=clusters.at(cluster_merge_candidate);
clusters.push_back(copy);  
clusters.at(j).is_valid=false;
cluster_count++;
output=" making copy ! ";
Output(output,true);
} // if(clusters.at(cluster_merge_candidate).cluster_id <= j){



    
// tombstone_merged_cluster 
clusters.at(j).is_valid=false;


output="";
output.append(" clusters.at(j).centroid_x: ");
output.append(to_string(clusters.at(j).centroid_x));
output.append(" clusters.at(j).centroid_y: ");
output.append(to_string(clusters.at(j).centroid_y));
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
if(is_on){Output_all_clusters(clusters);}
        
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
Output(output,true);
break;
} //    if(loop_cluster_count < K){                    
} //    for(int j=0;j<cluster_count;j++){


if(loop_cluster_count <= K){            
output="";
output="\tbreak\t";
Output(output,true);
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

/*
// add all oip to index
for(auto itr : oip){
if(itr.is_valid){
valid_clusters.push_back(itr.cluster_id);
} // if(itr.is_valid){
} // for(auto itr : clusters){
*/


//int final_cluster=valid_clusters.size(); 

//int final_cluster_iterator=0;
//int last=0;


int cluster_size=oip.cluster_points_x.size(); 
for(int z=0;z<cluster_size;z++){


// output_final_clusters_data
for(auto itr : valid_clusters){
float x=0;
float y=0;
cluster at;
at=clusters.at(itr);


int final_cluster_size=clusters.at(itr).cluster_points_x.size(); 
for(int j=0;j<final_cluster_size;j++){

x=at.cluster_points_x.at(j);
y=at.cluster_points_y.at(j);




if(oip.cluster_points_x.at(z) == x && oip.cluster_points_y.at(z) == y){
output="";
output.append(to_string(at.cluster_id));
Output(output,true);    
//if(last != at.cluster_id){final_cluster_iterator++;}
//last=at.cluster_id;
} // if(oip.cluster_points_x.at(z) == x && oip.cluster_points_y.at(z) == y){

} //    for(int j=0;j<final_cluster_size;j++){    

} //    for(auto itr : valid_clusters){

} //    for(int z=0;z<cluster_size;z++){  


    


    
    is_on=true;
Output("\n\n\n\n",is_on);   
if(is_on){Output_all_clusters(clusters);}
    
return 0;
} // int main(){




float Euclidean(float LAT1,float LAT2, float LONG1, float LONG2){
float THE_LAT=LAT1-LAT2;
float this_lat;
this_lat=THE_LAT*THE_LAT;
float THE_LONG=LONG1-LONG2;
float this_long;
this_long=THE_LONG*THE_LONG;
float THE_INPUT=this_lat+this_long;
return sqrt(THE_INPUT);
}; //   float Euclidean(float LAT1,float LAT2, float LONG1, float LONG2){

void Output(string the_output,bool is_on){if(is_on){cout<<the_output<<endl;}}


void Output_all_clusters(vector<cluster> clusters){
    cout<<endl;
    cout<< "-------------------------";
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
    cout<< "centroid_x: ";
 cout<<to_string(cluster.centroid_x);
    cout<< "\tcentroid_y: ";
 cout<<to_string(cluster.centroid_y); 
    }
      

 } //     for (auto & cluster : clusters) { 
       cout<< "-------------------------" <<endl;
}; //   void Output_all_clusters(vector<cluster> clusters){
                 
                 
                 
void Ensure_continous_cluster_index_for_valid_clusters(vector<cluster> clusters){
int last_cluster_id=0;
bool init=1;
for(auto & cluster : clusters){ 
if(cluster.is_valid && init == 0){
if(cluster.cluster_id > last_cluster_id+1){
cout<<endl;
    cout<< "modifiying cluster_id: ";
 cout<<to_string(cluster.cluster_id)<<endl;   
cluster.cluster_id=last_cluster_id+1;
    cout<< "to: ";
 cout<<to_string(cluster.cluster_id)<<endl;   
} //    if(cluster.cluster_id > last_cluster_id+1){
} //    if(cluster.is_valid && init == 0){
init=0;
last_cluster_id=cluster.cluster_id;
} //     for (auto & cluster : clusters) {  
}; //   void Ensure_continous_cluster_index_for_valid_clusters(vector<cluster> clusters){








