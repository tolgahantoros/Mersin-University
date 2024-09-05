%Tablo 2.2

clc;
clear;
clear all;

[mx,c,err,yc]=regula(@(x)x*sin(x)-1,0,2,0,0,4)