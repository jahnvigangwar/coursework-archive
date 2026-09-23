OrigCost = [ -2 -1 0 0 -1 -1 0];
b = [3;6;3];
Info = [3 1  0 0 1 0; 4 3 -1 0 0 1; 1 2  0 1 0 0 ];
A = [Info b];


fprintf ("\n===========================")
fprintf ("\n==========PHASE 1==========")
fprintf ("\n===========================")
cost = [ 0 0 0 0 -1 -1 0];
sstartBV = [5 6];
startBV = [6 7 5];
zjcj = cost(startBV)*A - cost;

run = true; 
while run 
    zc = zjcj(1:end-1);
    if any (zc<0)
        fprintf ("optimal NOT");
        [pvt_cval, pvt_cind] = min(zc);

        column = A(:,pvt_cind);
        sol = A(:,end);

        for i=1:size(A,1)
            if (column(i)>0)
               
                ratio(i) = sol(i)./column(i);
            else
                ratio(i) = inf;
            end
        end
        [pvt_rval, pvt_rind] = min(ratio);

        startBV(pvt_rind) = pvt_cind;
        pvt_elem = A(pvt_rind,pvt_cind);

        A(pvt_rind, :) = A(pvt_rind, :) ./ pvt_elem;

        for i = 1:size(A,1)
            if (i~=pvt_rind)
                A(i,:) = A(i,:) - A(i,pvt_cind).*A(pvt_rind,:);
            end
        end
         zjcj = cost(startBV)*A -cost;
         tbl = array2table ([zjcj; A])
        

    else
        run = false;
        tbl = array2table ([zjcj; A])
        fprintf("optimal solution reached");
    end

end


fprintf ("\n===========================")
fprintf ("\n==========PHASE 2==========")
fprintf ("\n===========================")

A(:,sstartBV) = []
OrigCost (:,sstartBV) = []
zjcj = OrigCost(BV)*A - OrigCost;

run = true; 
while run 
    zc = zjcj(1:end-1);
    if any (zc<0)
        fprintf ("optimal NOT");
        [pvt_cval, pvt_cind] = min(zc);

        column = A(:,pvt_cind);
        sol = A(:,end);

        for i=1:size(A,1)
            if (column(i)>0)
               
                ratio(i) = sol(i)./column(i);
            else
                ratio(i) = inf;
            end
        end
        [pvt_rval, pvt_rind] = min(ratio);

        BV(pvt_rind) = pvt_cind;
        pvt_elem = A(pvt_rind,pvt_cind);

        A(pvt_rind, :) = A(pvt_rind, :) ./ pvt_elem;

        for i = 1:size(A,1)
            if (i~=pvt_rind)
                A(i,:) = A(i,:) - A(i,pvt_cind).*A(pvt_rind,:);
            end
        end
         zjcj = cost(BV)*A -cost;
         tbl = array2table ([zjcj; A]);
        

    else
        run = false;
        tbl = array2table([zjcj ;A])
        fprintf ("optimal")
    end

end

finaltbl = array2table ([zjcj])
