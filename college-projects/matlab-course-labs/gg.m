% Convert the following system of equation into standard form
% x1-2x2-x3 = 4
% 2x1-x2+2x3 <= 5
% x1+3x2-5x3 >= 7

clc
clear all
format short

a = [1 -2 -1;
     2 -1 2;
     1 3 -5];
b = [4;
     5;
     7];
c = [3 4 5];

sign = [0 -1 1];
s = eye(size(a,1));

ind = find(sign > 0);
ind1 = find(sign == 0);

s(ind,:) = -s(ind,:);
s(ind1,:) = zeros(1,size(a,2));
s(:,ind1) = [];

a = [a s]
c = [c zeros(1,size(s,2))]
