format short
clear all 
clc


Variables = {'x_1', 'x_2', 's_2', 's_3', 'A_1', 'A_2', 'sol'};
M = 1000;
cost = [-2 -1 0 0 -M -M 0];
b = [3; 6; 3];
Info = [3 1 0 0 1 0; 4 3 -1 0 0 1; 1 2 0 1 0 0];
A = [Info b];
s =eye(size(A,1));

BV = [];
for j=1:size(s,2)
    for i=1:size(A,2)
        if A(:,i)==s(:,j)
        
            BV = [BV i];
        end
    end
end


zjcj = cost(BV)*A - cost;

tbl = [zjcj; A];
simpleTable = array2table(tbl);
simpleTable.Properties.VariableNames(1:size(tbl,2))=Variables

RUN = true;
while RUN
    zc = zjcj(1:end-1); 
    if any(zc < 0)
        fprintf('Current BFS is not optimal')
        [pvt_cval, pvt_cindx] = min(zc);
    
        column = A(:,pvt_cindx);
    
        if all(column <= 0)
            error('Unbounded LPP')
        else
            sol = A(:,end);
            for i=1:size(column,1)
                if column(i) > 0
                    ratio(i) = sol(i)./column(i);
                else
                    ratio(i) = Inf;
                end
            end
    
            [pvt_rval, pvt_rindx] = min(ratio);
    
            BV(pvt_rindx) = pvt_cindx;
    
            pvt_elem = A(pvt_rindx, pvt_cindx);
    
            A(pvt_rindx, :) = A(pvt_rindx, :)./pvt_elem;
            for i = 1:size(A,1)
                if i~=pvt_rindx
                    A(i,:) = A(i,:) - A(i,pvt_cindx).*A(pvt_rindx,:);
                end
            end
            zjcj = zjcj - zjcj(pvt_cindx).*A(pvt_rindx,:);

             [zjcj; A]
        end
    
    else
        RUN = false;
        fprintf('\nOptimal Solution Reached')
        zjcj(1,end)
    
    end
end
