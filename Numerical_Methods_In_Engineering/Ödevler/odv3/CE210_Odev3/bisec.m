%Tablo 2.1

function [mx,c,err,yc]=bisec(f,a,b,delta) 
% [mx,c,err,yc]=bisec(@(x)x*sin(x)-1,0,2,0.001) -> table 2.1 outputs
%Input    - f is the function 
%	         - a and b are the left and right endpoints
%	         - delta is the tolerance
%Output - c is the zero
%	         - yc= f(c)
% 	         - err is the error estimate for c
ya=feval(f,a);
yb=feval(f,b);

if ya*yb>0,end %a and b positive

max1=1+round(log(b-a)-log(delta))/log(2);

format shortG;
mx = zeros(floor(max1),5);

for k=1:max1
    c=(a+b)/2;
    yc=feval(f,c);
    mx(k,:) = [k-1,a,c,b,yc];
    
    if yc==0
        a=c;
        b=c;
    elseif yb*yc>0
        b=c;
        yb=yc;
    else
        a=c;
        ya=yc;
    end
    
    if b-a<delta
        break;
    end
end

c=mx(k,3);
yc=feval(f,c);
err=abs(mx(k,4)-mx(k,2));