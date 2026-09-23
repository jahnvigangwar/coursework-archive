M =1000;
cost = [-2 -1 0 0 -M -M 0];
b = [ 3; 6; 3];
Info = [3 1 0 0 1 0; 4 3 -1 0 0 1; 1 2 0 1 0 0];
s= eye(size(Info,1))
A = [Info b];

BV=[];
for j=1:size(s,2)
    for i=1:size(A,2)
        if A(:,i) == s(:,j)
            BV  = [BV i]
        end
    end
end

zjcj = cost(BV)*A - cost;

Variables = {'x_1', 'x_2', 's_2', 's_3', 'A_1', 'A_2', 'sol'};
tbl = [zjcj; A];
simpleTable = array2table(tbl);
simpleTable.Properties.VariableNames(1:size(tbl,2))=Variables

RUN = true;
while RUN
    zc = zjcj(1:end-1);
    if any(zc < 0)
%         fprintf("Not optimal\n");
        [pvt_cval, pvt_cind] = min(zc);

        column = A(:,pvt_cind);
        if all(column <= 0)
            error('Unbounded LPP')
        else
            sol = A(:,end);
            for i=1:size(sol,1)
                if(column>0)
                    ratio(i) = sol(i)./column(i);
                else
                    ratio(i) = inf;
                end
            end
            [pvt_rval, pvt_rind] = min(ratio);
    
            BV(pvt_rind) = pvt_cind;
            pvt_elem = A(pvt_rind,pvt_cind);
    
            A(pvt_rind,:) = A(pvt_rind,:)./pvt_elem;
            for i=1:size(A,1)
                if i~=pvt_rind
                    A(i,:) = A(i,:) - A(pvt_rind,:).*A(i,pvt_cind);
                end
            end
            zjcj = zjcj - zjcj(pvt_cind).*A(pvt_rind,:);
        end
              
    else
        RUN = false;
        tbl = [zjcj; A];
        finalTable = array2table(tbl);
        finalTable.Properties.VariableNames(1:size(tbl,2))=Variables
        fprintf('\nOptimal Solution Reached')
        zjcj(1,end);
    end
end

