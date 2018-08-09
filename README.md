# ODESolver


We are given a second order ordinary differential equation. However, our numerical methods work on first order ordinary differential equations (ODEs). The trick is to replace the second order ODE with two 1st order ODEs. Here is an example
Consider the differential equation:
 
Remember, the first step is to convert the above 2nd order ODE into two 1st-order ODEs. This is a standard operation. 
Let v(t)=y'(t).  Then v'(t)=y''(t). We then get two differential equations. The 
first is easy
 
The second is obtained by rewriting the original ode. Using the fact 
that y''=v' and y'=v,
 
Now, we solve two 1st order ODEs. 

