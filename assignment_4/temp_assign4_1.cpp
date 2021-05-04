














int third_mog=0;
   
if(M==111){  
bool init=true;

//bool init2=true;
loop_cluster_count=cluster_count; 
while(loop_cluster_count >= K)
{
output="";
output="top of loop\tloop_cluster_count: ";
output.append(to_string(loop_cluster_count));
output.append("\tK\t");
output.append(to_string(K));
Output(output,false);


int cluster_merge_candidate=0; 

for(int jj=0;jj<cluster_count;jj++){


//if(jj==4){return 0;}

//float last_merged_cluster_distance=9999;
int last_min=0;
min_distance=99999;
max_distance=0;
float distance=0;

int j_index=0;

int dist_iterator=0;
int min_dist_iterator=0;

diameters=empty_diameters;
diameters_cl1=empty_valid_clusters;
diameters_cl2=empty_valid_clusters;

dist=empty_dist;


/*
dist.max_cluster_distances.push_back(distance);
dist.cluster_merge_candidate.push_back(i);
dist.j_index.push_back(j);
dist.distance_id.push_back(dist_iterator);
dist_iterator++;
*/


valid_clusters=empty_valid_clusters;
// add all valid cluster_id's to valid_clusters
for(auto itr : clusters){
if(itr.is_valid){
valid_clusters.push_back(itr.cluster_id);
} // if(itr.is_valid){
} // for(auto itr : clusters){



//int t_cluster_size=valid_clusters.size(); 
//for(int j=0;j<t_cluster_size;j++){
int j_size=valid_clusters.size(); 

for(auto j : valid_clusters){
last_min++;








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


//x=at.cluster_points_x.at(0)=0;
//y=at.cluster_points_y.at(0)=0;



// determine_if_multiple_points_are_assigned_to_this_inner_cluster
reentrant_cluster_size=at.cluster_points_x.size(); 
for(int z=0;z<reentrant_cluster_size;z++){

x=at.cluster_points_x.at(z);
y=at.cluster_points_y.at(z);



/*
NOTES
complete link
differences require additional consideration in the case where
the closest two clusters don't have the closest max diameter
this is most likely the cases that are processing incorrectly
to resolve run min+max for all NxN instead of NxN(M) results
rather than try to do this in(process place) for now record all data
and 100% post process.
Iteration is now looped + linked NxN(M)
it needs to store NxN first, then process











if(j_index==0){
x=at.centroid_x;
y=at.centroid_y;
// calculate the distance between at and iat clusters

}
*/


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
/*
if(re_reentrant_cluster_size>1 || reentrant_cluster_size>1){
x2=iat.centroid_x;
y2=iat.centroid_y;
} // if(re_reentrant_cluster_size>1 || reentrant_cluster_size>1){

*/

// calculate the distance between at and iat clusters
distance=Euclidean(x, x2, y, y2);



/*


if(j_index==0){
x2=iat.centroid_x;
y2=iat.centroid_y;
// calculate the distance between at and iat clusters
distance=Euclidean(x, x2, y, y2);

}
if(distance <= max_distance){
diameters.push_back(distance);
diameters_cl1.push_back(0);
diameters_cl2.push_back(0);
} // if(distance <= max_distance){


   diameters.push_back(distance);
diameters_cl1.push_back(j);
diameters_cl2.push_back(i);
if(distance < min_distance){
min_distance=distance;
cluster_merge_candidate=i;
j_index=j;
} //    if(distance < min_distance){


   if(distance > max_distance){
max_distance=distance;

if(distance < smallest){
smallest=distance;
cluster_merge_candidate=i;
j_index=j;
} // if(distance < smallest){
} //    if(distance > max_distance){

*/


// complete link (max)
//if(distance > max_distance){
//if(distance > max_distance || distance < min_distance){
//max_distance=distance;
//cluster_merge_candidate=i;
//j_index=j;

//at.max_distance=distance;
/*
bool is_there=false;
for (auto & t : dist.distance_id) { 
if(dist.max_cluster_distances.at(t) == distance){is_there=true;}
} // for (auto & i : dist.distance_id) { 
if(! is_there){
*/
if(! init){
output="";
output.append(" distance: ");
output.append(to_string(distance));
Output(output,false);
dist.max_cluster_distances.push_back(distance);
dist.cluster_merge_candidate.push_back(i);
dist.j_index.push_back(j);
dist.distance_id.push_back(dist_iterator);
dist_iterator++;
//} /// if(! is_there){
//} //    if(distance < min_distance){
} // if(! init){


if(init){
if(distance <= min_distance && j!=i){
if(cluster_merge_candidate != i && j_index != j){
//last_min=min_distance;
min_distance=distance;

output="";
output.append(to_string(j));
output.append(" init distance: ");
output.append(to_string(distance));
output.append(" init min_distance: ");
output.append(to_string(min_distance));
Output(output,false);
///*
dist.max_cluster_distances.push_back(distance);
dist.cluster_merge_candidate.push_back(i);
dist.j_index.push_back(j);
dist.distance_id.push_back(dist_iterator);
dist_iterator++;


//*/
//if(!init2){

cluster_merge_candidate=j;
j_index=i;
//} // if(init2){
//init2=false;
} // if(cluster_merge_candidate != i && j_index != j){
} //if(distance < min_distance && j==0){
} //if(init){




// simple link 
if(distance < min_distance && false){
//float last_distance=min_distance;

//min_distance=distance;
//at.min_distance=distance;

dist.min_cluster_distances.push_back(distance);
dist.min_cluster_merge_candidate.push_back(i);
dist.min_j_index.push_back(j);
dist.min_distance_id.push_back(min_dist_iterator);
min_dist_iterator++;
//bool is_there=false;
//for (auto & t : dist.min_distance_id) { 
//if(dist.min_cluster_distances.at(t) == distance){is_there=true;}
//} // for (auto & i : dist.min_distance_id) { 

//cluster_merge_candidate=i;
//j_index=j;




} //    if(distance > max_distance || distance < min_distance){

} // for(int zz=0;zz<re_reentrant_cluster_size;zz++){
} // if(i!=j){
} // if(iat.is_valid){
} // for(int i=0;i<cluster_count;i++){
} //    for(int z=0;z<reentrant_cluster_size;z++){


} //    if(at.is_valid){

} //    for(int j=0;j<cluster_count;j++){

/*
int dsize=diameters_cl1.size(); 
int vc=valid_clusters.size(); 

output="";
output.append("dsize: ");
output.append(to_string(dsize));
Output(output,false);

output="";
output.append("vc: ");
output.append(to_string(vc));
Output(output,false);

//max_distance=0;
//min_distance=9999;
for(auto itr : diameters_cl1){
if(itr < vc){
output.append(" itr: ");
output.append(to_string(itr));
Output(output,false);
if(diameters.at(itr) < min_distance ){
min_distance=diameters.at(itr);
cluster_merge_candidate=diameters_cl1.at(itr);
j_index=diameters_cl2.at(itr);
output="";
output.append("min_distance: ");
output.append(to_string(min_distance));
output.append(" cluster_merge_candidate: ");
output.append(to_string(cluster_merge_candidate));
output.append(" j_index: ");
output.append(to_string(j_index));
Output(output,false);
} // if(itr < vc){
} // if(diameters.at(itr) < min_distance && diameters.at(itr) != 0){
} // for(auto itr : diameters){



dist.cluster_distances.push_back(distance);
dist.cluster_merge_candidate.push_back(i);
dist.j_index.push_back(j);

*/






/*

for (auto & dis : dist.distance_id) { 

if(dist.cluster_distances.at(dis) < min_distance && last_merged_cluster_distance != max_distance){
   output="";
output.append("max_distance: ");
output.append(to_string(max_distance));
output.append(" min_distance: ");
output.append(to_string(min_distance));
output.append(" last_merged_cluster_distance: ");
output.append(to_string(last_merged_cluster_distance));
Output(output,true);
min_distance=dist.cluster_distances.at(dis);
cluster_merge_candidate=dist.cluster_merge_candidate.at(dis);
j_index=dist.j_index.at(dis);
//merged_cluster_distances.push_back(min_distance);
last_merged_cluster_distance=min_distance;
} // if(dis.cluster_distances < min_distance ){
} // for (auto & dis : dist) { 
*/

/*
//bool is_output=false;
//int min_cluster_iterator=0;
//int min_cluster_size=dist.min_cluster_distances.size();
//while(! is_output){
for (auto & dis : dist.distance_id) { 
for (auto & tdis : dist.min_distance_id) { 
//cluster_merge_candidate=dist.cluster_merge_candidate.at(dis);
//j_index=dist.j_index.at(dis);
while(dist.max_cluster_distances.at(dis) > 0){
output="";
output.append("max_distance: ");
output.append(to_string(max_distance));
output.append(" min_distance: ");
output.append(to_string(min_distance));
output.append(" dist.max_cluster_distances.at(dis): ");
output.append(to_string(dist.max_cluster_distances.at(dis)));
output.append(" dist.min_cluster_distances.at(tdis): ");
output.append(to_string(dist.min_cluster_distances.at(tdis)));
output.append(" last_merged_cluster_distance: ");
output.append(to_string(last_merged_cluster_distance));
Output(output,true);
//max_distance=    
//min_distance=dist.max_cluster_distances.at(dis);

//merged_cluster_distances.push_back(min_distance);
//last_merged_cluster_distance=min_distance;
//is_output=true;

//min_cluster_iterator++;
//min_cluster_size=min_cluster_size-min_cluster_iterator;
//} // while(min_cluster_size > 0){
} // for (auto & tdis : dist.min_distance_id) { 
} // for (auto & dis : dist) { 
   if(itr==0){
if(cluster_merge_candidate == dist.cluster_merge_candidate.at(i) || j_index == dist.j_index.at(i));
}
if(itr!=0){
if(cluster_merge_candidate == dist.cluster_merge_candidate.at(i) && j_index == dist.j_index.at(i));
//{
}
itr++;
*/


//} // while(! is_output){
//float max_min=9999;
//bool found_max=false;
//int min_cluster_size=dist.min_distance_id.size();
//int max_cluster_size=dist.distance_id.size();

//for(int j=min_cluster_size;j>0;j--){
//for(int i=max_cluster_size;i>0;i--){
   
//if(! init){
//int smallest_min=9999;
int smallest_max=99999;
//int size=dist.max_cluster_distances.size();
//for (auto & i : dist.distance_id) { 
   int itr=0;
for (auto & j : dist.distance_id) { 
//for(int j=size;size>0;j--){
//for(int i=size;size>0;j--){

//if(!found_max){
float this_distance = round( dist.max_cluster_distances.at(j) * 1000.0 ) / 1000.0;

//max_min=dist.max_cluster_distances.at(i);

output="";
output.append(to_string(this_distance));
Output(output,false);
//}
//} // if(dist.min_cluster_merge_candidate.at(j) == dist.cluster_merge_candidate.at(i) && dist.min_j_index.at(j) == dist.j_index.at(i))

//} // if(!found_max){
// } // for(int j=min_cluster_size;j>0;j--){
 // for(int i=max_cluster_size;i>0;i--){
 // if(itr==0){
/*
if(smallest_min > dist.min_cluster_distances.at(j)){
smallest_min=j;
} // if(smallest_min > dist.min_cluster_distances.at(j)){
*/
//if(! init){
if(smallest_max >= this_distance && this_distance != 0){
if(smallest_max == this_distance){
output="";
output.append(" max: ");
output.append(to_string(smallest_max));
output.append(" itr: ");
output.append(to_string(itr));
//output.append(" min: ");
//output.append(to_string(smallest_min));
//output.append("\n");
Output(output,false);

} // if(smallest_max == this_distance{
smallest_max=this_distance;

cluster_merge_candidate=dist.cluster_merge_candidate.at(j);
j_index=dist.j_index.at(j);
itr++;
} // if(smallest_max > dist.max_cluster_distances.at(i)






/*
if(dist.max_cluster_distances.at(smallest_max) < dist.min_cluster_distances.at(smallest_min)){
cluster_merge_candidate=dist.cluster_merge_candidate.at(smallest_max);
j_index=dist.j_index.at(smallest_max);
} // if(dist.max_cluster_distances.at(smallest_max) < dist.max_cluster_distances.at(smallest_min)){

if(dist.min_cluster_distances.at(smallest_min) < dist.max_cluster_distances.at(smallest_max)){
cluster_merge_candidate=dist.cluster_merge_candidate.at(smallest_min);
j_index=dist.j_index.at(smallest_min);
} // if(dist.max_cluster_distances.at(smallest_max) < dist.max_cluster_distances.at(smallest_min)){
*/

 //  if(cluster_merge_candidate == dist.cluster_merge_candidate.at(i) && j_index == dist.j_index.at(i)){
  //    if(j_index == dist.j_index.at(i)){

//if(dist.min_cluster_distances.at(j) < max_min){
//if(dist.max_cluster_distances.at(i) < max_min){
///max_min=dist.max_cluster_distances.at(i);
//max_min=dist.min_cluster_distances.at(j);
//cluster_merge_candidate=dist.min_cluster_merge_candidate.at(j);
//j_index=dist.min_j_index.at(j);
//cluster_merge_candidate=dist.cluster_merge_candidate.at(i);
//j_index=dist.j_index.at(i);
/*
output="";
//output.append("max_distance: ");
//output.append(to_string(max_distance));
output.append(" max_min1: ");
output.append(to_string(max_min));
//output.append(" dist.max_cluster_distances.at(dis): ");
//output.append(to_string(dist.max_cluster_distances.at(i)));
//output.append(" dist.min_cluster_distances.at(tdis): ");
//output.append(to_string(dist.min_cluster_distances.at(j)));
Output(output,false);
*/
//}
} // for (auto & j : dist.distance_id) { 
//} // if(! init){

//} // if(dist.min_cluster_merge_candidate.at(j) == dist.cluster_merge_candidate.at(i) && dist.min_j_index.at(j) == dist.j_index.at(i))



/*
output="";
//output.append("max_distance: ");
//output.append(to_string(max_distance));
output.append(" max_minf: ");
output.append(to_string(max_min));
//output.append(" dist.max_cluster_distances.at(dis): ");
//output.append(to_string(dist.max_cluster_distances.at(i)));
//output.append(" dist.min_cluster_distances.at(tdis): ");
//output.append(to_string(dist.min_cluster_distances.at(j)));
Output(output,false);
*/


/*
if(init && j_size==last_min){

output="";
output.append(" init distance: ");
output.append(to_string(distance));
output.append(" init min_distance: ");
output.append(to_string(min_distance));
output.append(" init cluster_merge_candidate: ");
output.append(to_string(cluster_merge_candidate));
output.append(" init j_index: ");
output.append(to_string(j_index));
Output(output,true);

init=false;
int smaller =cluster_merge_candidate;
int larger=j_index;
if(j_index > cluster_merge_candidate){
smaller =j_index;
larger=cluster_merge_candidate;
} //if(j_index > cluster_merge_candidate){

for(auto itr : clusters.at(larger).cluster_points_x){
clusters.at(smaller).cluster_points_x.push_back(itr);
} // for(auto itr : at.cluster_points_x){

for(auto itr : clusters.at(larger).cluster_points_y){
clusters.at(smaller).cluster_points_y.push_back(itr);
} // for(auto itr : at.cluster_points_y){

// tombstone_merged_cluster 
clusters.at(larger).is_valid=false;


} //if(init && j_size==j){

*/

////if(! init){
int smaller =cluster_merge_candidate;
int larger=j_index;
if(j_index > cluster_merge_candidate){
smaller =j_index;
larger=cluster_merge_candidate;
} //if(j_index > cluster_merge_candidate){

for(auto itr : clusters.at(larger).cluster_points_x){
clusters.at(smaller).cluster_points_x.push_back(itr);
} // for(auto itr : at.cluster_points_x){

for(auto itr : clusters.at(larger).cluster_points_y){
clusters.at(smaller).cluster_points_y.push_back(itr);
} // for(auto itr : at.cluster_points_y){

// tombstone_merged_cluster 
clusters.at(larger).is_valid=false;
//} // if(! init){





/*
if(! init){
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
} // if(! init){
*/


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
    //    Output_all_distances(dist);


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
} // if(M==111){

/*
if(M==1){
if(third_mog ==0){
cluster aa;
aa.cluster_id=0;
aa.is_valid=true;
clusters.at(0)=aa;
for(auto itr : clusters.at(3).cluster_points_x){
clusters.at(0).cluster_points_x.push_back(itr);
} // for(auto itr : at.cluster_points_x){

for(auto itr : clusters.at(3).cluster_points_y){
clusters.at(0).cluster_points_y.push_back(itr);
third_mog==1;
}
} //if(third_mog ==0){
} // if(M==1){
*/



