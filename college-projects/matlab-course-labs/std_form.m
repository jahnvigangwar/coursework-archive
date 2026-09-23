
format short 
clear all
clc
%% PHASE 1 = INPUT PARAMETERS
C = [3,5];
A = [1,2;1 1;0 1];
b = [2000;1500;600];
%% PHASE 2 INDENTIFY < OR >
IneqSign = [0 0 1];
%% PHASE 3 
s = eye(size(A,1));
ind =find(IneqSign >0);
s (ind,:) = -s(ind,:);
%% Phase 4 standard form 
ObjFns = array2table(C);
ObjFns.Properties.VariableNames(1:2) = {'x_1','x_2'};
Mat = [A s b] ;
constraint = array2table(Mat);
constraint.Properties.VariableNames(1:size(Mat,2))={'x_1','x_2','s_1','s_2','s3','Sol'};
ObjFns
constraint