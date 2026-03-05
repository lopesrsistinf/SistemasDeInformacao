% cp = coluna pivot
% lp = linha pivot
% nl = numero de linhas
% nc = numero de colunas
% lm = linhas do maximo
% em = elemento maximo
% vl = variaveis livres
vl = 0
[nl nc]=size(A)

for cp = 1:nc-1
  lp = cp-vl;
  [em lm]=max(abs(A(lp:nl,cp)));
  if em==0
    vl=vl+1
    continue
  end
  lm = lm +(lp-1);
  A([lp lm],:) = A([lm lp],:);
  A(lp,:) = A(lp,:)/A(lp,cp);


  for j = lp+1:nl
    A(j,:)=A(j,:)-A(lp,:)*A(j,cp);
  end
  for j = 1:lp-1
    A(j,:)=A(j,:)-A(lp,:)*A(j,cp);
  end
end
