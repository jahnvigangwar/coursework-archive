%practice graphical method

% Minimize 
% Z = 3x1 + 2x2 
% subject to the constraints 
% 5x1 + x2 ≥ 10; 
% x1 + x2 > 6; 
% x1+ 4x2 ≥ 12 
% and x1, x2 ≥ 0.

clc 
clear all 

A = [5 1; 1 1; 1 4];
B = [10; 6 ; 12];
C = [3 2];

 y1 = 0:1:max(B);
x21 = (B(1)-A(1,1).*y1)./A(1,2);
x22 = (B(2)-A(2,1).*y1)./A(2,2);
x23 = (B(3)-A(3,1).*y1)./A(3,2);
x21 = max(0,x21);
x22 = max(0,x22);
x23 = max(0,x23);
plot(y1,x21,'r', y1,x22,'black', y1,x23,'b')

cx1 = find(y1==0);
 x1 = find(x21==0);
line1 = [y1(:,[x1 cx1]); x21(:,[x1 cx1])]' ;
 x2 = find(x22==0);
line2 = [y1(:,[x2 cx1]); x22(:,[x2 cx1])]' ;
 x3 = find(x23==0);
line3 = [y1(:,[x3 cx1]); x23(:,[x3 cx1])]' ;
corpt = unique([line1;line2;line3], 'rows');

HG = [0;0];
for i=1:size(A,1)
    hg1 = A(i,:);
    b1 = B(i,:);
    for j= i+1:size(A,1)
        hg2 = A(j,:);
        b2 = B(j,:);
        Aa = [hg1 ; hg2];
        Bb = [b1 ; b2];
        Xx = Aa\Bb;
        HG = [HG Xx];
    end
end
pt = HG';

allpts = [corpt ; pt];
allpts = unique(allpts, 'rows');


PT = prac_constraint(allpts);
PT = unique(PT, 'rows');

for i=1:size(PT,1)
    Fx(i,:) = sum(PT(i,:).*C);
end
vertFns = [PT Fx];

[maxval maxind] = min(Fx)
optval = vertFns(maxind,:);
OPTIMAL_BFS = array2table(optval)


