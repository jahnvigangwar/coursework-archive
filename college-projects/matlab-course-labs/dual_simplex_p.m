format short
clear all 
clc 

noOfVariable = 3;
c = [-2 0 -1];
Info = [-1 -1 1; -1 2 -4];
b = [-5; -8];
s = eye(size(Info, 1));
A = [Info s b];

cost = zeros(1,size(A,2));
cost(1:noOfVariable) = c;

BV = noOfVariable +1 : size(A,2)-1;

zjcj = cost(BV)*A - cost;

tbl = [zjcj; A]
tbl = array2table(tbl);
tbl.Properties.VariableNames(1:size(tbl,2)) = {'x_1', 'x_2', 'x_3', 's_1', 's_2', 'sol'};

RUN = true;
while RUN
    sol = A(:,end);
    if any(sol < 0)
        fprintf("Currnet is not feasible")

        %leving variable
        [pvt_rval, pvt_rindx] = min(sol);

        %find entering variable 
        ROW = A(pvt_rindx,1:end-1);
        zR = zjcj(1:end-1);
        for i=1:size(ROW,2)
                if ROW(i) < 0
                    ratio(i) =abs(zR(i)./ROW(i));
                else
                    ratio(i) = Inf;
                end
        end
        [pvt_cval, pvt_cindx] = min(ratio);
            
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
    else  
        RUN = false;
        disp("optimal reached")
        zjcj(1,end)
    end
end


