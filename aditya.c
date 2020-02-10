#include<stdio.h>
#include<malloc.h>
struct node{
int arr[8][8],row,column,gn,fn,hn;
//int row;
//int column;
//int gn;
//int fn;
//int hn;
struct node *next;
};
void print(struct node *a){
int i,j;
for(i=0;i<8;i++){
for(j=0;j<8;j++){
printf("%d ",a->arr[i][j]);
}
printf("\n");
}
printf("\n");
}
int costfunction(struct node *a){
int fn=0;
int i,j;
for(i=0;i<8;i++){
if(a->arr[i][a->column]==1){
fn++;
}
}
for(i=a->row-1,j=a->column-1;i>=0&&j>=0;i--,j--){
if(a->arr[i][j]==1){
fn++;
}
}
for(i=a->row+1,j=a->column+1;i<=7&&j<=7;i++,j++){
if(a->arr[i][j]==1){
fn++;
}
}
for(i=a->row-1,j=a->column+1;i>=0&&j<=7;i--,j++){
if(a->arr[i][j]==1){
fn++;
}
}
for(i=a->row+1,j=a->column-1;i<=7&&j>=0;i++,j--){
if(a->arr[i][j]==1){
fn++;
}
}
a->fn=fn+a->hn+a->gn+a->row;
fn=a->fn;
return fn;
}
void queen(struct node *a){
struct node *last;
last=(struct node *)malloc(sizeof(struct node));
int t=1,i,j,k;
while(a->row<8){
for(i=0;i<8;i++){
struct node *b;
b=(struct node *)malloc(sizeof(struct node));
for(j=0;j<8;j++){
for(k=0;k<8;k++){
b->arr[j][k]=a->arr[j][k];
}
}
b->row=a->row+1;
b->hn=8-a->row;
b->gn=1;
b->column=i;
b->arr[b->row][i]=1;
if(t==1&&costfunction(b)<=11){
a->next=b;
last=b;
last->next=NULL;
t=0;
}else if(costfunction(b)<=11){
last->next=b;
last=b;
last->next=NULL;
}
}
if(a->next!=NULL)
a=a->next;
if(a->row==7){
print(a);
return;
}
}
}
int main(){
struct node *a;
int i,j;
a=(struct node *)malloc(sizeof(struct node));
for(i=0;i<8;i++){
for(j=0;j<8;j++){
a->arr[i][j]=0;
}
}
a->row=-1;
a->hn=8;
a->gn=1;
a->next=NULL;
queen(a);
return 0;
}
