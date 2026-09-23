% Maximize/Minimize (3x1 + 2x2)
% Subject to 
% 2x1 +4x2> = 8,
% 3x1 + 5x2>= 15,
% x1>=0, x2>= 0.

clc 
clear all

A = [2 4; 3 5];
B = [8 ; 15];
C = [3 2];

y1 = 0:1:max(B);
x21 = (B(1)-A(1,1).*y1)./A(1,2);
x22 = (B(2)-A(2,1).*y1)./A(2,2);
x21 = max(0,x21);
x22 = max(0,x22);

plot(y1,x21,'r', y1,x22,'b')

cx1 = find(y1==0);
c1 = find(x21 == 0);
line1 = [y1(:,[c1 cx1]); x21(:,[c1 cx1])]' ;
c2 = find(x22 == 0);
line2 = [y1(:,[c2 cx1]); x22(:,[c2 cx1])]' ;
corpts = unique([line1;line2], 'rows');

HG=[0;0];
for i=1:size(A,1)
    hg1 = A(i,:);
    b1 = B(i,:);
    for j=i+1:size(A,1)
        hg2 = A(j,:);
        b2 = B(j,:);

        Aa = [hg1; hg2];
        Bb = [b1; b2];
        Xx = Aa\Bb;

        HG = [HG Xx];

    end
end
pts = HG'

allpts = [corpts ; pts];
allpts = unique(allpts,'rows');

PT = jahnvi(allpts);
PT = unique(PT,'rows');

for i=1:size(PT,1)
    Fx(i,:) = sum(PT(i,:).*C);
end
vertFns = [PT Fx];

[minval minind] = min(Fx);
optval = vertFns(minind,:)


