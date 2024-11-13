function [dx]=ode_1(t,x)
a0=5
a1=4
a2=3
a3=1
b=2.5
y=1                  %/ либо 1, либо sin(t)
dx=zeros(3,1)      %/ обнуление массива dx[3,1]
dx(1)=x(2)
dx(2)=x(3)
dx(3)=(b*y-a0*x(1)-a1*x(2)-a2*x(3))/a3
end
