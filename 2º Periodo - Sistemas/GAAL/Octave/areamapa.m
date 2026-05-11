A = imread('mapabrasil.png');
imshow(A)
hold on;
P = []
i = 0
while true
  i = i+1
  [x,y,btn] = ginput(1);

  if btn == 1 %botao esquerdo (principal)
    P = [P ;[x y]];
  endif
  if btn == 3 %botao direito (auxiliar)
    break;
  endif
  if i>1
    plot(P(i-1:i,1),P(i-1:i,2),'color','red','LineWidth',5)
  endif
end
P = [P ;[P(1,1) P(1,2)]]
plot(P(:,1),P(:,2),'color','red','LineWidth',5)
n=size(P,1)

area = 0;
for i = 1:n-1
  area += (P(i,1)*P(i+1,2)-P(i,2)*P(i+1,1))/2;
end
area = abs(area)*100

