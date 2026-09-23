format short
clear all 
clc 

noOfVariable = 3;
c = [12 3 1];
Info = [10 2 1; 7 3 2; 2 4 1];
b = [100; 77; 80];
s = eye(size(Info, 1));
A = [Info s b];

cost = zeros(1,size(A,2));
cost(1:noOfVariable) = c;

BV = noOfVariable +1 : size(A,2)-1;

zjcj = cost(BV)*A - cost;

tbl = [zjcj; A]
tbl = array2table(tbl);
tbl.Properties.VariableNames(1:size(tbl,2)) = {'x_1', 'x_2', 'x_3', 's_1', 's_2', 's_3', 'sol'};

RUN = true;
while RUN
    if any(zjcj < 0)
        %entering variable
        zc = zjcj(1:end-1);
        [pvt_cval, pvt_cindx] = min(zc);

        column = A(:,pvt_cindx);

        if all(column <= 0 )
            disp("unbounded LPP")
        else
            sol = A(:,end);
            for i=1:size(column,1)
                if(column(i) > 0)
                    ratio(i) = sol(i)./column(i);
                else
                    ratio(i) = inf;
                end
            end

            [pvt_rval, pvt_rindx] = min(ratio);
            
            BV(pvt_rindx) = pvt_cindx;
            
            pvt_elem = A(pvt_rindx, pvt_cindx);

            A(pvt_rindx,:) = A(pvt_rindx,:)./pvt_elem;
            for i=1:size(A,1)
                if(i~=pvt_rindx)
                    A(i,:) = A(i,:) - A(i,pvt_cindx).*A(pvt_rindx,:);
                end
            end
            zjcj = zjcj - zjcj(pvt_cindx).*A(pvt_rindx,:);

            [zjcj; A]

        end

    else
        RUN = false;
        disp("optimal reached")
         zjcj(1,end)
    end
end
