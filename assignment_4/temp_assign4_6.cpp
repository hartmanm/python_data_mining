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
//float total_distance;
};

struct ordered_index_points{
vector<float> cluster_points_x;
vector<float> cluster_points_y;
};


struct distances{
vector<int> distance_id;
//vector<float> cluster_distances;
vector<float> max_cluster_distances;
vector<int> cluster_merge_candidate;
vector<int> j_index;
//vector<float> merged_cluster_distances;
//vector<float> min_cluster_distances;
//vector<int> min_distance_id;
//vector<int> min_cluster_merge_candidate;
//vector<int> min_j_index;
};

void Output_all_clusters(vector<cluster> clusters);

void Output_all_distances(distances dist);

int main(){

int last_centroid_index=0;

distances dist;
distances empty_dist;

vector<int> output_clusters;

float min_distance=99999;
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

a.min_distance=99999;
a.max_distance=0;
a.used_centroid=false;


clusters.push_back(a);
cluster_count++;
} //    for(int i=0;i<N;i++){
    
   



if(M==1){  
int cc=cluster_count;
int j_index=0;
int cluster_merge_candidate=0;
loop_cluster_count=cluster_count; 
while(loop_cluster_count >= K)
{
for(int jj=0;jj<cluster_count;jj++){
min_distance=9999;
max_distance=0;
float distance=0;
int dist_iterator=0;

dist=empty_dist;



valid_clusters=empty_valid_clusters;
// add all valid cluster_id's to valid_clusters
for(auto itr : clusters){
if(itr.is_valid){
valid_clusters.push_back(itr.cluster_id);
} // if(itr.is_valid){
} // for(auto itr : clusters){


int j_size=valid_clusters.size(); 

for(auto j : valid_clusters){




float x=0;
float y=0;  
int reentrant_cluster_size=0;
int re_reentrant_cluster_size=0;
cluster at;
at=clusters.at(j);
if(! at.is_valid){//cluster_count++;j=j+1;
output="";
output.append("at.is_valid\tis invalid");
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

//min_distance=9999;
//max_distance=0;

re_reentrant_cluster_size=iat.cluster_points_x.size(); 
max_distance=0;
for(int zz=0;zz<re_reentrant_cluster_size;zz++){
x2=iat.cluster_points_x.at(zz);
y2=iat.cluster_points_y.at(zz);



// calculate the distance between at and iat clusters
distance=Euclidean(x, x2, y, y2);
if(zz==0){
max_distance=distance;
cluster_merge_candidate=i;
j_index=j;

output="at zz: ";
output.append(to_string(zz));
output.append(" distance: ");
output.append(to_string(distance));
Output(output,false);

}

/*
if(distance >= at.max_distance && distance > 0){
at.max_distance=distance;
// j_index
} //    if(distance < min_distance){
if(distance > iat.max_distance && distance > 0){
iat.max_distance=distance;
// cluster
} //    if(distance < min_distance){
*/

if(distance > max_distance && distance > 0){
output="";
output.append(" distance: ");
output.append(to_string(distance));
Output(output,false);

cluster_merge_candidate=i;
j_index=j;

output="at zz: ";
output.append(to_string(zz));
output.append(" distance: ");
output.append(to_string(distance));
Output(output,false);
}





} // for(int zz=0;zz<re_reentrant_cluster_size;zz++){

dist.max_cluster_distances.push_back(max_distance);
dist.cluster_merge_candidate.push_back(cluster_merge_candidate);
dist.j_index.push_back(j_index);
dist.distance_id.push_back(dist_iterator);
dist_iterator++;
/*
output="at i: ";
output.append(to_string(i));
output.append(" distance: ");
output.append(to_string(max_distance));
output.append(" vs : at.max_distance ");
output.append(to_string(at.max_distance));
output.append(" vs : iat.max_distance ");
output.append(to_string(iat.max_distance));
Output(output,false);
*/

if(distance >= at.max_distance && distance > 0){
at.max_distance=distance;
// j_index
} //    if(distance < min_distance){
if(distance > iat.max_distance && distance > 0){
iat.max_distance=distance;
// cluster
} //    if(distance < min_distance){

} // if(i!=j){
} // if(iat.is_valid){



} // for(int i=0;i<cluster_count;i++){
} //    for(int z=0;z<reentrant_cluster_size;z++){


} //    if(at.is_valid){

} //    for(int j=0;j<cluster_count;j++){

























/*



// find min
for(auto j : valid_clusters){

float x=0;
float y=0;  
int reentrant_cluster_size=0;
int re_reentrant_cluster_size=0;
cluster at;
at=clusters.at(j);
if(! at.is_valid){//cluster_count++;j=j+1;
output="";
output.append("at.is_valid\tis invalid");
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

//min_distance=9999;
//max_distance=0;

re_reentrant_cluster_size=iat.cluster_points_x.size(); 
min_distance=99999;
for(int zz=0;zz<re_reentrant_cluster_size;zz++){
x2=iat.cluster_points_x.at(zz);
y2=iat.cluster_points_y.at(zz);



// calculate the distance between at and iat clusters
distance=Euclidean(x, x2, y, y2);
if(zz==0){
min_distance=distance;
cluster_merge_candidate=i;
j_index=j;

output="at zz: ";
output.append(to_string(zz));
output.append(" distance: ");
output.append(to_string(distance));
Output(output,false);

}



if(distance < min_distance && distance > 0){
output="";
output.append(" distance: ");
output.append(to_string(distance));
Output(output,false);

cluster_merge_candidate=i;
j_index=j;

output="at zz: ";
output.append(to_string(zz));
output.append(" distance: ");
output.append(to_string(distance));
Output(output,false);
}





} // for(int zz=0;zz<re_reentrant_cluster_size;zz++){

dist.max_cluster_distances.push_back(min_distance);
dist.cluster_merge_candidate.push_back(cluster_merge_candidate);
dist.j_index.push_back(j_index);
dist.distance_id.push_back(dist_iterator);
dist_iterator++;
output="at i: ";
output.append(to_string(i));
output.append(" distance: ");
output.append(to_string(max_distance));
output.append(" vs : at.max_distance ");
output.append(to_string(at.max_distance));
output.append(" vs : iat.max_distance ");
output.append(to_string(iat.max_distance));
Output(output,false);



} // if(i!=j){
} // if(iat.is_valid){



} // for(int i=0;i<cluster_count;i++){
} //    for(int z=0;z<reentrant_cluster_size;z++){


} //    if(at.is_valid){

} //    for(int j=0;j<cluster_count;j++){


*/

































int smallest_max=99999;
int itr=0;
for (auto & j : dist.distance_id) { 
itr++;


float this_distance = dist.max_cluster_distances.at(j);
if(this_distance > 0){
if(dist.cluster_merge_candidate.at(j) != dist.j_index.at(j)){
if(this_distance <= smallest_max){
smallest_max=this_distance;
cluster_merge_candidate=dist.cluster_merge_candidate.at(j);
j_index=dist.j_index.at(j);

} // if(this_distance <= smallest_max){
} // if(dist.cluster_merge_candidate.at(j) != dist.j_index.at(j)){
} // if(this_distance > 0)
} // for (auto & j : dist.distance_id) { 

output="itr ";
output.append(to_string(itr));
Output(output,false);





// new cluster
cluster atr;
atr.cluster_id=cc;
atr.is_valid=true;
clusters.push_back(atr);
cc++;
int f=0;
int w=0;
for(auto itr : clusters){
if(itr.cluster_id == atr.cluster_id){f=w;}
w++;
} // for(auto itr : clusters){
// wipe merged clusters and add their points to the new cluster
for(auto itr : clusters.at(j_index).cluster_points_x){
clusters.at(f).cluster_points_x.push_back(itr);
} 
for(auto itr : clusters.at(j_index).cluster_points_y){
clusters.at(f).cluster_points_y.push_back(itr);
} 
for(auto itr : clusters.at(cluster_merge_candidate).cluster_points_x){
clusters.at(f).cluster_points_x.push_back(itr);
} 
for(auto itr : clusters.at(cluster_merge_candidate).cluster_points_y){
clusters.at(f).cluster_points_y.push_back(itr);
}
// tombstone_merged_clusters
clusters.at(j_index).is_valid=false;
clusters.at(cluster_merge_candidate).is_valid=false;






/*
// recalculate the centroid for the growing cluster
int final_cluster_size=clusters.at(f).cluster_points_x.size();
float x_total=0;
float y_total=0;
for(int i=0;i<final_cluster_size;i++){
x_total+=clusters.at(f).cluster_points_x.at(i);
y_total+=clusters.at(f).cluster_points_y.at(i);

max_distance=
min_distance=
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
clusters.at(f).centroid_x=x_total/final_cluster_size;
clusters.at(f).centroid_y=y_total/final_cluster_size;

*/



 Output_all_clusters(clusters);
 //Output_all_distances(dist);

loop_cluster_count--;
if(loop_cluster_count <= K){break;} //    if(loop_cluster_count < K){                
} //    for(int jj=0;j<cluster_count;j++){ jj
if(loop_cluster_count <= K){break;} //    if(loop_cluster_count < K){ 
} //    while(loop_cluster_count > K)
} // if(M==1){





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
for (auto & dis : tdist.max_cluster_distances) { 

 cout<<endl;
    cout<< "distance at " << to_string(index)<<": ";
 cout<<to_string(dis)<<endl;        
index++;
    }
      


       cout<< "-------------------------" <<endl;
}; //   void Output_all_clusters(vector<cluster> clusters){
