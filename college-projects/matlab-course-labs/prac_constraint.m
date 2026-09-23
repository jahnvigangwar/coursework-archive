function f =prac_constraint(X)

% 5x1 + x2 ≥ 10; 
% x1 + x2 > 6; 
% x1+ 4x2 ≥ 12 
% and x1, x2 ≥ 0.

x1 = X(:,1);
x2 = X(:,2);
cons1= 5.*x1 + x2 -10;
h1 = find(cons1<0);
X(h1,:)=[]

x1 = X(:,1);
x2 = X(:,2)
cons2=x1+x2-6;
h2 = find(cons2<0);
X(h2,:)=[]

x1 = X(:,1);
x2 = X(:,2)
cons3=x1+4.*x2-12;
h3 = find(cons3<0);
X(h3,:)=[]

f = X;
end



