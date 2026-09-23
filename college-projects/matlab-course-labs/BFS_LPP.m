%%BASIC FEASIBLE SOLUTION

format short
clear all
clc

%% Phase 1: Input Parameters
C=[2 3 4 7];
A=[2 3 -1 4; 1 -2 6 -7];
b=[8;-3];

%% Phase 2: No of constraints and Variables
m=size(A,1);  %no of constraints | equations
n=size(A,2);  %no of variables

%% Phase 3: Compute nCm 
nv= nchoosek(n,m);   %Total no of basic solution
t = nchoosek(1:n,m); %pairs of basic variables

%% Phase 4: Construct Basic Solution 
sol = []; %Default sol is zero

if n>=m
    for i=1:nv
        y = zeros(n,1);
        x = A(:,t(i,:))\b;
    
        %check feasibility 
        if all(x>=0 & x~=inf & x~=-inf)
            y(t(i,:)) = x;
            sol=[sol,y];
        end
    end
else
    error('Equations > variables')
end

%% Phase 5: Compute objective fuction
Z=C*sol;


%% Phase 6: Find optimal Value
[Zmax, Zind] = max(Z);
BFS = sol(:,Zind);


%% Phase 7: Print all the solutions
optval = [BFS' Zmax];
OPTIMAL_BFS = array2table(optval);
OPTIMAL_BFS.Properties.VariableNames(1:size(OPTIMAL_BFS,2)) = {'x1','x2','x3','x4','Value of z'}


   