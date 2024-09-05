%Tablo 2.1

clc;
clear;
clear all;

[mx,c,err,yc]=bisec(@(x)x*sin(x)-1,0,2,0.001)