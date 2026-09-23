cost=[11 20 7 8; 21 16 10 12; 8 12 18 9]; 
 A=[50 40 70] ;    %supply
  B=[30 25 35 40];    %demand



if(sum(A) == sum(B))
    fprintf("Balanced");
else
    fprintf("unbalanced");
    if(sum(A)>sum(B))
        cost(:,end+1) = zeros(size(cost,1),1);
        B(end+1)=sum(A)-sum(B) ;
    elseif sum(B)>sum(A)
        cost(end+1,:) = zeros(size(cost,2),1);
        A(end+1)=sum(B)-sum(A) ;
    end
end

X=zeros(size(cost));
Icost=cost      ; 

for i=1:size(cost,1)
    for j=1:size(cost,2)
        hh = min(cost(:));
        [r_ind,c_ind] = find(hh==cost);
        x11 = min(A(r_ind), B(c_ind));
        [val, ind] = max(x11);
        ii= r_ind(ind);
        jj= c_ind(ind);
        y11= min(A(ii),B(jj));
        cost(ii,jj) = inf;
        X(ii,jj)=y11;
        A(ii)=A(ii)-y11;
        B(jj)=B(jj)-y11;
    end
end


IBFS=array2table(X) ;
 disp(IBFS) 
sum(sum(Icost.*X))
