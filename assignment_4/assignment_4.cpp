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
float centroid_x;
float centroid_y;

float min_distance;
float max_distance;
bool used_centroid;
float total_distance;
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

int last_centroid_index=0;

distances dist;

vector<int> output_clusters;

float min_distance=9999;
float max_distance=0;


bool is_on=false;
vector<int> valid_clusters; 
vector<int> empty_valid_clusters; 
int loop_cluster_count=0;
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

a.min_distance=1000;
a.max_distance=0;
a.used_centroid=false;

clusters.push_back(a);
cluster_count++;
} //    for(int i=0;i<N;i++){
    
   
if(M!=2){  
loop_cluster_count=cluster_count; 
while(loop_cluster_count >= K)
{
output="";
output="top of loop\tloop_cluster_count: ";
output.append(to_string(loop_cluster_count));
output.append("\tK\t");
output.append(to_string(K));
Output(output,is_on);


for(int jj=0;jj<cluster_count;jj++){

min_distance=99999;
max_distance=0;
float distance=0;
int cluster_merge_candidate=0; 
int j_index=0;


valid_clusters=empty_valid_clusters;
// add all valid cluster_id's to valid_clusters
for(auto itr : clusters){
if(itr.is_valid){
valid_clusters.push_back(itr.cluster_id);
} // if(itr.is_valid){
} // for(auto itr : clusters){



//int t_cluster_size=valid_clusters.size(); 
//for(int j=0;j<t_cluster_size;j++){
for(auto j : valid_clusters){









float x=0;
float y=0;  
int reentrant_cluster_size=0;
int re_reentrant_cluster_size=0;
cluster at;
at=clusters.at(j);
if(! at.is_valid){//cluster_count++;j=j+1;
output="";
output.append("\at.is_valid\tis invalid");
Output(output,false);
} // if(! at.is_valid){
// guard agianst old unmerged / merged cluster tomestones
if(at.is_valid){



// determine_if_multiple_points_are_assigned_to_this_inner_cluster
reentrant_cluster_size=at.cluster_points_x.size(); 
for(int z=0;z<reentrant_cluster_size;z++){

x=at.cluster_points_x.at(z);
y=at.cluster_points_y.at(z);

//for(int i=0;i<t_cluster_size;i++){
for(auto i : valid_clusters){
float x2=0;
float y2=0;
cluster iat=clusters.at(i);
if(iat.is_valid){
if(i!=j){

re_reentrant_cluster_size=iat.cluster_points_x.size(); 
for(int zz=0;zz<re_reentrant_cluster_size;zz++){
x2=iat.cluster_points_x.at(zz);
y2=iat.cluster_points_y.at(zz);

// if multiple points take the centroid as the points
if(M==2){
if(re_reentrant_cluster_size>1 || reentrant_cluster_size>1){
x2=iat.centroid_x;
y2=iat.centroid_y;
} // if(re_reentrant_cluster_size>1 || reentrant_cluster_size>1){
} // if(M==2){

// calculate the distance between at and iat clusters
distance=Euclidean(x, x2, y, y2);

//dist.cluster_distances.push_back(distance);

// Single link: min
if(M==0){
if(distance < min_distance){
min_distance=distance;
cluster_merge_candidate=i;
j_index=j;
} //    if(distance < min_distance){
} // if(M==0){

// complete link (max)
if(M==1){
if(distance > max_distance){
max_distance=distance;
cluster_merge_candidate=i;
j_index=j;
} //    if(distance < min_distance){
} // if(M==1){

// average link (mean)
if(M==2){
if(distance < min_distance){
min_distance=distance;
cluster_merge_candidate=i;
j_index=j;
} //    if(distance < min_distance){
} // if(M==2){

} // for(int zz=0;zz<re_reentrant_cluster_size;zz++){
} // if(i!=j){
} // if(iat.is_valid){
} // for(int i=0;i<cluster_count;i++){
} //    for(int z=0;z<reentrant_cluster_size;z++){


} //    if(at.is_valid){
} //    for(int j=0;j<cluster_count;j++){



output="";
output.append("1 itr: ");
output.append(to_string(cluster_count));
Output(output,false);
    

// append all j's points to the growing cluster cluster_merge_candidate
for(auto itr : clusters.at(j_index).cluster_points_x){
clusters.at(cluster_merge_candidate).cluster_points_x.push_back(itr);
} // for(auto itr : at.cluster_points_x){

for(auto itr : clusters.at(j_index).cluster_points_y){
clusters.at(cluster_merge_candidate).cluster_points_y.push_back(itr);
} // for(auto itr : at.cluster_points_y){

// tombstone_merged_cluster 
clusters.at(j_index).is_valid=false;
//cluster_count++;

/*
// append all cluster_merge_candidate's points to the growing cluster j
for(auto itr : clusters.at(cluster_merge_candidate).cluster_points_x){
at.cluster_points_x.push_back(itr);
output.append(" itr : ");
output.append(to_string(itr));
Output(output,true);
} // for(auto itr : at.cluster_points_x){

for(auto itr : clusters.at(cluster_merge_candidate).cluster_points_y){
at.cluster_points_y.push_back(itr);
} // for(auto itr : at.cluster_points_y){

// tombstone_merged_cluster 
clusters.at(cluster_merge_candidate).is_valid=false;


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
*/

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
 Output(output,is_on);
 } // for(int i=0;i<final_cluster_size;i++){
 clusters.at(cluster_merge_candidate).centroid_x=x_total/final_cluster_size;
 clusters.at(cluster_merge_candidate).centroid_y=y_total/final_cluster_size;


    
loop_cluster_count--;
output="";
output.append("loop_cluster_count: ");
output.append(to_string(loop_cluster_count));
Output(output,false);
    
//Output_all_clusters(clusters);
        
output="";   
output="bottom of loop\tloop_cluster_count:";
output.append(to_string(loop_cluster_count));
output.append("\tK\t");
output.append(to_string(K));
Output(output,false);


//} //    if(at.is_valid){ jj

if(! clusters.at(j_index).is_valid){
output="";
output="invalid\t";
output.append(to_string(clusters.at(j_index).cluster_id));
Output(output,is_on);
} //    if(! at.is_valid){

if(loop_cluster_count <= K){            
output="";
output="\tbreak\t";
Output(output,is_on);
break;
} //    if(loop_cluster_count < K){                    
} //    for(int j=0;j<cluster_count;j++){ jj


if(loop_cluster_count <= K){            
output="";
output="\tbreak\t";
Output(output,is_on);
break;
} //    if(loop_cluster_count < K){ 


} //    while(loop_cluster_count > K)
} // if(M!=2){
   
















if(M==2){
loop_cluster_count=cluster_count; 

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
last_centroid_index=0;

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



// reset each clusters total_distance at the beginning of each iteration
at.total_distance=0;

x=at.cluster_points_x.at(z);
y=at.cluster_points_y.at(z);
//x=clusters.at(j).centroid_x;
//y=clusters.at(j).centroid_y;

float distance;
//float min_distance=1000;
//float max_distance=0;
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




// if a single point cluster
if(re_reentrant_cluster_size==1){
x2=iat.cluster_points_x.at(zz);
y2=iat.cluster_points_y.at(zz);
} //if(re_reentrant_cluster_size==1){


// /*
// if multiple points take the centroid as the points
if(re_reentrant_cluster_size>1){
x2=iat.centroid_x;
y2=iat.centroid_y;
iat.used_centroid=true;
last_centroid_index=i;
} // if(re_reentrant_cluster_size>1){
// */


output="";
output.append("\tre_reentrant_cluster_size\t");
output.append(to_string(re_reentrant_cluster_size));
Output(output,is_on);



// calculate the distance between at and iat clusters
distance=Euclidean(x, x2, y, y2);

dist.cluster_distances.push_back(distance);





/*

if(re_reentrant_cluster_size>1){
// generate total distance
at.total_distance+=distance;
iat.centroid_x=at.total_distance/re_reentrant_cluster_size;
iat.centroid_y=at.total_distance/re_reentrant_cluster_size;

if(zz==re_reentrant_cluster_size-1){
if(M==0){
if(iat.centroid_x < at.min_distance){
at.min_distance=distance;
cluster_merge_candidate=i;
} //    if(distance < min_distance){
} // if(M==0){

// complete link (max)
if(M==1){
if(iat.centroid_x > at.max_distance){
at.max_distance=distance;
cluster_merge_candidate=i;
} //    if(distance < min_distance){
} // if(M==1){

// average link (mean)
if(M==2){
if(iat.centroid_x < at.min_distance){
at.min_distance=distance;
cluster_merge_candidate=i;
} //    if(distance < min_distance){
} // if(M==2){

} // if(zz==re_reentrant_cluster_size-1){
} //if(re_reentrant_cluster_size>1){


if(re_reentrant_cluster_size==1){


*/

/*
if(distance < at.min_distance){
   at.min_distance=distance;
   
   }
if(distance > at.max_distance){
   at.max_distance=distance;

   }
*/



// Single link: min
if(M==0){
if(distance < at.min_distance){
at.min_distance=distance;
cluster_merge_candidate=i;
} //    if(distance < min_distance){
} // if(M==0){

// complete link (max)
if(M==1){
if(distance > at.max_distance){
at.max_distance=distance;
cluster_merge_candidate=i;
} //    if(distance < min_distance){
} // if(M==1){

// average link (mean)
if(M==2){
if(distance < at.min_distance){
at.min_distance=distance;
cluster_merge_candidate=i;
} //    if(distance < min_distance){
} // if(M==2){



//} // if(re_reentrant_cluster_size==1){







} // for(int zz=0;zz<re_reentrant_cluster_size;zz++){

} // if(i!=j){
} // if(iat.is_valid){
} // for(int i=0;i<cluster_count;i++){


} //    for(int z=0;z<reentrant_cluster_size;z++){
















/*
// (inner loop iterator after total_distance has been calculated)
for(auto itr : at.cluster_points_x){
clusters.at(cluster_merge_candidate).cluster_points_x.push_back(itr);
} // for(auto itr : clusters){



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






// (inner loop iterator after total_distance has been calculated)
for(int ij=0;ij<cluster_count;ij++){
//int cluster_merge_candidate=0; 
//float ix=0;
//float iy=0;  
//int ireentrant_cluster_size=0;
//int ire_reentrant_cluster_size=0;
cluster ati;
ati=clusters.at(ij);
// guard agianst old unmerged / merged cluster tomestones
if(ati.is_valid){

// determine_if_multiple_points_are_assigned_to_this_inner_cluster
//ireentrant_cluster_size=ati.cluster_points_x.size(); 
//for(int iz=0;iz<ireentrant_cluster_size;iz++){
//ix=ati.cluster_points_x.at(ij);
//iy=ati.cluster_points_y.at(ij);

//float idistance=1000;
float imin_distance=1000;
float imax_distance=0;
// inner loop
//for(int ii=0;ii<cluster_count;ii++){
//float ix2=0;
//float iy2=0;
//cluster iati=clusters.at(ii);
//if(iati.is_valid){
if(j!=ij){

//ire_reentrant_cluster_size=iati.cluster_points_x.size(); 
//for(int izz=0;izz<ire_reentrant_cluster_size;izz++){
//ix2=iati.cluster_points_x.at(izz);
//iy2=iati.cluster_points_y.at(izz);




// calculate the distance between at and iat clusters
//idistance=Euclidean(ix, ix2, iy, iy2);

// generate total distance
//ati.total_distance+=idistance;



// Single link: min
if(M==0){
if(ati.total_distance < imin_distance){
imin_distance=ati.total_distance;
cluster_merge_candidate=ij;


output="distance: ";
output.append(to_string(ati.total_distance));
output.append(" from: ");
output.append(to_string(at.cluster_id));
output.append(" to: ");
output.append(to_string(iati.cluster_id));
output.append(" cluster_count: ");
output.append(to_string(cluster_count));
Output(output,is_on);

} //    if(distance < min_distance){
} // if(M==0){

// complete link (max)
if(M==1){
if(ati.total_distance > imax_distance){
imax_distance=ati.total_distance;
cluster_merge_candidate=ij;


output="distance: ";
output.append(to_string(ati.total_distance));
output.append(" from: ");
output.append(to_string(at.cluster_id));
output.append(" to: ");
output.append(to_string(iat.cluster_id));
output.append(" cluster_count: ");
output.append(to_string(cluster_count));
Output(output,is_on);

} //    if(distance > max_distance){
} // if(M==1){

// average link (mean)
if(M==2){
if(ati.total_distance > imax_distance){
imax_distance=ati.total_distance;
cluster_merge_candidate=ij;
// more logic

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



} //    if(distance > max_distance){
} // if(M==1){


//} // for(int zz=0;<re_reentrant_cluster_size;zz++){


} //  if(j!=ij){
//} // if(iat.is_valid){
//} // for(int i=0;i<cluster_count;i++){


//} //    for(int z=0;z<reentrant_cluster_size;z++){

} //  if(ati.is_valid){

} //   (inner) for(int ij=0;ij<cluster_count;ij++){


*/





// merge_the_closest_two_clusters
// set_the_at_struct_to_the_inner_candidate
//at=clusters.at(cluster_merge_candidate);






if(last_centroid_index != 0){

cluster iat=clusters.at(last_centroid_index);
iat.used_centroid=false;



// determine_if_multiple_points_are_assigned_to_this_inner_cluster
reentrant_cluster_size=at.cluster_points_x.size(); 
for(int z=0;z<reentrant_cluster_size;z++){


// reset each clusters total_distance at the beginning of each iteration
at.total_distance=0;

x=at.cluster_points_x.at(z);
y=at.cluster_points_y.at(z);

float distance;

float x2=0;
float y2=0;


re_reentrant_cluster_size=iat.cluster_points_x.size(); 
for(int zz=0;zz<re_reentrant_cluster_size;zz++){
x2=iat.cluster_points_x.at(zz);
y2=iat.cluster_points_y.at(zz);



output="";
output.append("\tre_reentrant_cluster_size\t");
output.append(to_string(re_reentrant_cluster_size));
Output(output,is_on);



// calculate the distance between at and iat clusters
distance=Euclidean(x, x2, y, y2);

dist.cluster_distances.push_back(distance);


// Single link: min
if(M==0){
if(distance < at.min_distance){
at.min_distance=distance;
cluster_merge_candidate=last_centroid_index;
} //    if(distance < min_distance){
} // if(M==0){

// complete link (max)
if(M==1){
if(distance > at.max_distance){
at.max_distance=distance;
cluster_merge_candidate=last_centroid_index;
} //    if(distance < min_distance){
} // if(M==1){

// average link (mean)
if(M==2){
if(distance < at.min_distance){
at.min_distance=distance;
cluster_merge_candidate=last_centroid_index;
} //    if(distance < min_distance){
} // if(M==2){



} // for(int zz=0;zz<re_reentrant_cluster_size;zz++){




} //    for(int z=0;z<reentrant_cluster_size;z++){




















} // if(last_centroid_index != 0){






































// append all j's points to the growing cluster cluster_merge_candidate
//at=clusters.at(j);

// merge clusters if points not already present
//bool is_not_contained=true;
for(auto itr : at.cluster_points_x){
//int this_cluster_size=clusters.at(cluster_merge_candidate).cluster_points_x.size(); 
//for(int sj=0;sj<this_cluster_size;sj++){
clusters.at(cluster_merge_candidate).cluster_points_x.push_back(itr);
//is_not_contained=true;
//for(auto itri : at.cluster_points_x){
   /*
if(at.cluster_points_x.at(sj) && clusters.at(cluster_merge_candidate).cluster_points_x.at(sj))
{
if(at.cluster_points_x.at(sj) != clusters.at(cluster_merge_candidate).cluster_points_x.at(sj)){clusters.at(cluster_merge_candidate).cluster_points_x.push_back(sj);}
}
*/
//} // for(auto itri : at.cluster_points_x){
//f(is_not_contained){clusters.at(cluster_merge_candidate).cluster_points_x.push_back(itr);}
//} // for(auto itr : clusters){
} // for(auto itr : at.cluster_points_x){

for(auto itr : at.cluster_points_y){
//this_cluster_size=clusters.at(cluster_merge_candidate).cluster_points_y.size(); 
//for(int sj=0;sj<this_cluster_size;sj++){
clusters.at(cluster_merge_candidate).cluster_points_y.push_back(itr);
//is_not_contained=true;
//for(auto itri : at.cluster_points_x){
   /*
if(at.cluster_points_y.at(sj) && clusters.at(cluster_merge_candidate).cluster_points_y.at(sj))
{
if(at.cluster_points_y.at(sj) != clusters.at(cluster_merge_candidate).cluster_points_y.at(sj)){clusters.at(cluster_merge_candidate).cluster_points_y.push_back(sj);}
}
*/
//} // for(auto itri : at.cluster_points_x){
//f(is_not_contained){clusters.at(cluster_merge_candidate).cluster_points_x.push_back(itr);}
//} // for(auto itr : clusters){
} // for(auto itr : at.cluster_points_y){


//if(M==2){

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
Output(output,is_on);
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
Output(output,is_on);
} // if(clusters.at(cluster_merge_candidate).cluster_id <= j){


dist.cluster_distances.push_back(float(j));
//cluster_count++;

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



} //if(M==2){ 



















output="exit main loop";
Output(output,false);


// add all valid cluster_id's to valid_clusters
valid_clusters=empty_valid_clusters;
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
} // if(oip.cluster_points_x.at(z) == x && oip.cluster_points_y.at(z) == y){
} //    for(int j=0;j<final_cluster_size;j++){    
} //    for(auto itr : valid_clusters){
} //    for(int z=0;z<cluster_size;z++){  

/*
bool iterate_last_lowest=false;
int is_lowest=0;
int last_lowest=0;
int output_cluster_size=output_clusters.size(); 
for(int i=0;i<final_cluster_size;i++){ 

int this_oc=output_clusters.at(is_lowest);
iterate_last_lowest=false;
for(int j=0;j<output_cluster_size;j++){   
int oc=output_clusters.at(j);
if(oc==this_oc){
output_clusters.at(j)=last_lowest;
iterate_last_lowest=true;

} // if(oc==this_oc){
} // for(int j=0;j<output_cluster_size;j++){  

is_lowest++;
if(iterate_last_lowest){
last_lowest=last_lowest+1;
} // if(iterate_last_lowest){
} // for(int i=0;i<output_cluster_size;i++){ 
*/

int output_cluster_size=output_clusters.size(); 
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

//float Euclidean(float LAT1,float LAT2, float LONG1, float LONG2){
//return sqrt(pow(LAT1 - LAT2, 2) + pow(LONG1 - LONG2, 2));
//}


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
