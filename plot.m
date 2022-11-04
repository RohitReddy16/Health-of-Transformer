values = readtable(&#39;final.xlsx&#39;); %reading excel sheet
x=values.HST;                     %assigning variables
y=values.RL;                      %assigning variables
subplot(2,2,1)
figure(1);
plot(x,y)
grid on;
xlabel(&#39;HST(h)(°C)&#39;);
ylabel(&#39;Remaining Life(RL)(years)&#39;);
