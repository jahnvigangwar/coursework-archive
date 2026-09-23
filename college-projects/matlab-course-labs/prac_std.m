
format short 
clear all
clc

C = [3,5];
A = [1,2;1 1;0 1];
IneqSign = [0 0 1];
% 0 for <= sign and
% 1 for >= sign
s = eye(size(A,1));
ind =find(IneqSign >0);
s (ind,:) = -s(ind,:);

Mat = [A s] ;
constraint = array2table(Mat);
constraint.Properties.VariableNames(1:size(Mat,2))={'x_1','x_2','s_1','s_2','s3'};
constraint


b = [2000;1500;600];
ObjFns = array2table(C);
ObjFns.Properties.VariableNames(1:2) = {'x_1','x_2'};
ObjFns