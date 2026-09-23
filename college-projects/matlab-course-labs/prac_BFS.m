%BFS
clc 
clear all 

C=[2 3 4 7];
A=[2 3 -1 4; 1 -2 6 -7];
B=[8;-3];




m = size(A,1)
n = size(A,2)
nv=nchoosek(n,m);
t=nchoosek(1:n,m);

sol =[];
if n>=m
    for i=1:nv
        y=zeros(n,1);
        x=A(:,t(i,:))\B;
        if all(x>=0 & x~=inf & x~=-inf)
            y(t(i,:))=x;
            sol=[sol,y];
        end
    end
else 
    error('Equations > variables')
end

z = C*sol;

[maxval maxind] = max(z);
BFS = sol(:,maxind);

optval = [BFS' maxval];
OPTIMAL_BFS = array2table(optval)

