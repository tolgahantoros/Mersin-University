%Sunu-VI: Tablo 13.3
%Newton Method

clc;
clear;

syms x
f = @(x) 2*sin(x)-((x^2)/10); %fonksiyon

mx = zeros(5,5); %tablo icin degerleri saklayan matris

xi = 2.5; %ilk tahmin x degeri
f1 = diff(f(x)); %f'in 1.turevi
f2 = diff(f(x),2); %f'in 2.turevi
fx = double(subs(f,{x},{xi})); %f'de x degerinin yazilmasi
f1x = double(subs(f1,{x},{xi})); %1.turevde x degerinin yazilmasi
f2x = double(subs(f2,{x},{xi})); %2.turevde x degerinin yazilmasi
x_sonraki = xi - (f1x/f2x); %sonucun sonraki x'e atanmasi
mx(1,:) = [0, xi, fx, f1x, f2x]; %ilk verinin matrise yazilmasi

%kalan verilen dongu ile matrise yazilmasi
for i=2:5
    xi = x_sonraki;
    fx = double(subs(f,{x},{xi}));
    f1x = double(subs(f1,{x},{xi}));
    f2x = double(subs(f2,{x},{xi}));
    x_sonraki = xi - (f1x/f2x);
    mx(i,:) = [i-1, xi, fx, f1x, f2x];
end

format short;
disp("    i         x         f(x)      f'(x)     f''(x)")
mx %veri matrisinin ekrana yazilmasi
