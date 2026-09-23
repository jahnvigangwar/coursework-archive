format short 
clear all 
clc

OrigCost= [-2 -1 0 0 -1 -1 0];
b= [3;6;3];
Info = [3 1 0 0 1 0;
        4 3 -1 0 0 1;
        1 2 0 1 0 0]
% BV=[5 6 4];
A=[Info b];

s=eye(size(A,1));

BV=[];
for j=1:size(s,2)
    for i=1:size(A,2)
        if A(:,i) == s(:,j)
            BV  = [BV i];
        end
    end
end

BV

fprintf("\n\nPhase 1\n\n");
cost = [0 0 0 0 -1 -1 0];
BV=[5 6 4];
zjcj = cost(BV)*A -cost
A=[Info b]
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
         zjcj(end)
    end
end







fprintf("\n\nPhase 2\n\n");
cost= [-2 -1 0 0 0];
A
art = [5 6];
A(:,art) = []
zjcj = cost(BV)*A -cost


RUN = true;
while RUN
      zc = zjcj(1:end-1); 
    if any(zc < 0)
        %entering variable
     
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
         zjcj(end)
    end
end
