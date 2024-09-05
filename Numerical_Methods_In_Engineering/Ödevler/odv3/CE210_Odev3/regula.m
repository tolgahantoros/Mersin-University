%Tablo 2.2

function [mx,c,err,yc]=regula(f,a,b,delta,epsilon,max1) 
%[mx,c,err,yc]=regula(@(x)x*sin(x)-1,0,2,0,0,4) -> table 2.2 outputs
%Input - f is the function input as a string 'f'
%       - a and b are the left and right endpoints
%       - delta is the tolerance for the zero
%       - epsilon is the tolerance for the value of f at the zero
%       - max1 is the maximum number of iterations
%Output - c is the zero
%        - yc=f(c)
%        - err is the error estimate for c

ya=feval(f,a);
yb=feval(f,b);

if ya*yb>0
    disp('Note: f(a)*f(b) >0'),
    return,
end

format longG;
mx = zeros(floor(max1),5);

for k=1:max1
    dx=yb*(b-a)/(yb-ya);
    c=b-dx;
    ac=c-a;
    yc=feval(f,c);
    mx(k,:) = [k-1,a,c,b,yc];
    if yc==0, break;
    elseif yb*yc>0
        b=c;
        yb=yc;
    else
        a=c;
        ya=yc;
    end
    dx=min(abs(dx),ac);
    if abs(dx)<delta,break,end
    if abs(yc)<epsilon,break,end
end

c=mx(k,3);
yc=feval(f,c);
err=abs(mx(k,4)-mx(k,2));