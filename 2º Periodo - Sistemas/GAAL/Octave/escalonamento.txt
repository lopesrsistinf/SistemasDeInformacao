% cp = coluna pivot
% lp = linha pivot
% nl = numero de linhas
% nc = numero de colunas
% lm = linhas do maximo
% em = elemento maximo
% vl = variaveis livres
vl = 0;
[nl nc]=size(A);

for cp = 1:nc-1
  lp = cp-vl;
  [em lm]=max(abs(A(lp:nl,cp)));
  if em==0 || lp > nl
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

A
vl

for i =1:nl
  if sum (abs(A(i,1:nc-1)))==0 && A(i,nc) != 0
    printf("Sistema Impossivel\n")
    return
  end
end

if vl>0
  printf("Sistema Possivel Indeterminado\n")
  return
end
  printf("Sistema Possivel Determinado\n")

