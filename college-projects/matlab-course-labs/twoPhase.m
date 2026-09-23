%Two Phase: Jahnvi Gangwar_102003372
format short 
clear all 
clc
Variables = {'x_1', 'x_2', 'x_3', 's_1', 's_2', 'A_1', 'A_2', 'sol'};
oVariables = {'x_1', 'x_2', 'x_3', 's_1', 's_2', 'sol'};
OrigC = [-7.5 3 0 0 0 -1 -1 0];
b = [3; 2];
Info = [3 -1 -1 -1 0 1 0; 1 -1 1 0 -1 0 1 ];
A = [Info b];
BV = [6 7];
% take objective function with A only 
cost = [0 0 0 0 0 -1 -1 0];
startBV = find(cost<0);
zjcj = cost(BV)*A - cost;
init_tbl = array2table ([zjcj; A]);
init_tbl.Properties.VariableNames(1:size(A,2)) = Variables
fprintf("==================================\n")
fprintf("Phase 1\n")
fprintf("==================================\n")
%find entering variable 
run = true;
while run
    %find entering column
    zC = zjcj(1:end-1);
    if any(zC < 0)
        [pvt_cval, pvt_cind] = min(zC);
    %find min ratio 
    sol = A(:,end);
    column = A(:,pvt_cind);
     if all(column <= 0)
            error('Unbounded LPP')
     else
        for i=1:size(column,1)
            if(column(i) > 0)
                ratio(i) = sol(i)./column(i);
            else
                ratio(i) = inf;
            end
        end
        [pvt_rval, pvt_rind] = min(ratio);
        BV(pvt_rind) = pvt_cind;
        pvt_elem = A(pvt_rind,pvt_cind);
        
        A(pvt_rind, :) = A(pvt_rind, :)./pvt_elem;
        for i=1:size(A,1)
            if(i~=pvt_rind)
                A(i,:) = A(i,:) - A(i,pvt_cind).*A(pvt_rind,:);
            end
        end
        zjcj = zjcj - zjcj(pvt_cind).*A(pvt_rind,:);
        tbl = array2table ([zjcj; A]);
        tbl.Properties.VariableNames(1:size(A,2)) = Variables
     end
    else
        run = false;
        tbl = array2table ([zjcj; A]);
        tbl.Properties.VariableNames(1:size(A,2)) = Variables
        fprintf("optimal solution reached");
    end
end
fprintf("\n\n==================================\n")
fprintf("Phase 2\n")
fprintf("==================================\n")
%remove artificial variables and its cost 
A(:,startBV) = [];
OrigC (:,startBV) = [];
zjcj = OrigC(BV)*A - OrigC;

run = true;
while run
    %find entering column
    zC = zjcj(1:end-1);
    if any(zC < 0)
        [pvt_cval, pvt_cind] = min(zC);
    %find min ratio 
    sol = A(:,end);
    column = A(:,pvt_cind);
     if all(column <= 0)
            error('Unbounded LPP')
     else
        for i=1:size(column,1)
            if(column(i) > 0)
                ratio(i) = sol(i)./column(i);
            else
                ratio(i) = inf;
            end
        end
        [pvt_rval, pvt_rind] = min(ratio);
        BV(pvt_rind) = pvt_cind;
        pvt_elem = A(pvt_rind,pvt_cind);
        
        A(pvt_rind, :) = A(pvt_rind, :)./pvt_elem;
        for i=1:size(A,1)
            if(i~=pvt_rind)
                A(i,:) = A(i,:) - A(i,pvt_cind).*A(pvt_rind,:);
            end
        end
        zjcj = zjcj - zjcj(pvt_cind).*A(pvt_rind,:);
%         tbl = array2table ([zjcj; A]);
%         tbl.Properties.VariableNames(1:size(A,2)) = oVariables

     end
    else
        run = false;
        fprintf("optimal solution reached");
    end
end
finaltbl = array2table ([zjcj]);
finaltbl.Properties.VariableNames(1:size(A,2)) = oVariables
