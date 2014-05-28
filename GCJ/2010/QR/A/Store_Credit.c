#include <stdio.h>
int main(){
	int N,C,I,P[2000],i,j,k,found;
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%d %d",&C,&I);
		for(j=0;j<I;j++){
			scanf("%d",&P[j]);
		}
		for(j=0;j<I-1;j++){
			if(P[j]>=C) continue;
			for(k=j+1;k<I;k++){
				if(P[k]>=C) continue;
				if(P[j]+P[k]==C){
					printf("Case #%d: %d %d\n",i+1,j+1,k+1);
					found=1;
					break;
				}
			}
			if(found) break;
		}
		if(found){
			found=0;
			continue;
		}
	}
	return 0;
}
