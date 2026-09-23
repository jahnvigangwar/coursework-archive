%simplex Method: Jahnvi Gangwar_102003372
format short 
clear all 
clc

NoofVariables = 3;
c = [12 3 1];
Info = [10 2 1; 7 3 2; 2 4 1];
b = [100; 77; 80];
s = eye(size(Info,1));
A = [Info s b];
Cost = zeros(1,size(A,2));
Cost(1:NoofVariables) = c;

BV = NoofVariables+1 : size(A,2)-1;

zjcj = Cost(BV)*A - Cost;
tbl = [zjcj; A];
simpleTable = array2table(tbl);
simpleTable.Properties.VariableNames(1:size(tbl,2))={'x_1', 'x_2', 'x_3', 's_1', 's_2', 's_3', 'sol'}

RUN = true;
while RUN
    zc = zjcj(1:end-1);
    if any(zc < 0)
        fprintf('Current BFS is not optimal')
%         zc = zjcj(1:end-1);
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

             [zjcj; A];
        end
    
    else
        RUN = false;
        fprintf('\nOptimal Solution Reached')
        zjcj(1,end)
    
    end
end

tbl = [zjcj; A];
finalTable = array2table(tbl);
finalTable.Properties.VariableNames(1:size(tbl,2))={'x_1', 'x_2', 'x_3', 's_1', 's_2', 's_3', 'sol'}
