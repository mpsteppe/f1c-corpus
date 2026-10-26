int __thiscall sub_65E7A1(char **this, char *a2, int a3)
{
  char *v4; // ebx
  char *v5; // eax
  char v6; // cl
  int v7; // ebx
  char *v8; // eax
  char **v9; // ecx

  this[10] = a2;
  *(_DWORD *)(a3 + 16) = this[6];
  v4 = 0;
  *(_DWORD *)(a3 + 20) = this[7];
  if ( !sub_65E088((unsigned int *)this) )
  {
    *(_DWORD *)(a3 + 16) = this[6];
    *(_DWORD *)(a3 + 20) = this[7];
    v5 = *this;
    if ( *this >= this[1] )
    {
      *(_DWORD *)a3 = 13;
      goto LABEL_34;
    }
    v6 = *v5;
    if ( *v5 >= 48 && v6 <= 57 || v6 == 46 )
    {
      v7 = sub_65D8C5(this, v5, (double *)(a3 + 8));
      if ( v7 )
      {
        *(_DWORD *)a3 = 5;
        v8 = (char *)sub_65DBE2(this, &(*this)[v7], (int *)a3);
LABEL_10:
        v4 = &v8[v7];
        goto LABEL_34;
      }
      v7 = sub_65E1B1((int)this, *this, (int *)(a3 + 8));
      v9 = this;
      if ( v7 || (v7 = sub_65E255((int)this, *this, (int *)(a3 + 8)), v9 = this, v7) )
      {
LABEL_15:
        *(_DWORD *)a3 = 2;
        v8 = sub_65DC2C(v9, &(*this)[v7], (_DWORD *)a3);
        goto LABEL_10;
      }
      v7 = sub_65E2D3((int)this, *this, (unsigned int *)(a3 + 8));
      if ( v7 )
      {
        v9 = this;
        goto LABEL_15;
      }
    }
    else if ( v6 == 39 )
    {
      v4 = sub_65E614(this, v5, (int *)(a3 + 8));
      if ( v4 )
      {
        *(_DWORD *)a3 = 2;
        goto LABEL_34;
      }
    }
    else if ( v6 == 34 )
    {
      v4 = (char *)sub_65E657((int)this, v5, (_DWORD *)(a3 + 8));
      if ( v4 )
      {
        *(_DWORD *)a3 = 10;
        goto LABEL_34;
      }
    }
    else if ( ((_BYTE)this[10] & 4) != 0 && v6 == 60 )
    {
      v4 = (char *)sub_65E657((int)this, v5, (_DWORD *)(a3 + 8));
      if ( v4 )
      {
        *(_DWORD *)a3 = 11;
        goto LABEL_34;
      }
    }
    else if ( sub_633848() || **this == 95 )
    {
      if ( ((_BYTE)this[10] & 2) != 0 )
      {
        v4 = (char *)sub_65E50F((int)this, (unsigned int)*this, (_DWORD *)(a3 + 8));
        if ( v4 )
        {
          *(_DWORD *)a3 = 0;
          goto LABEL_34;
        }
      }
      v4 = (char *)sub_65DA50(this, *this, (_DWORD *)(a3 + 8));
      if ( v4 )
      {
        *(_DWORD *)a3 = 9;
        goto LABEL_34;
      }
    }
    v4 = (char *)sub_65DAD4(this, *this, a3 + 8);
    *(_DWORD *)a3 = 1;
    goto LABEL_34;
  }
  *(_DWORD *)a3 = 12;
LABEL_34:
  *(_DWORD *)(a3 + 24) = *this;
  *(_DWORD *)(a3 + 28) = v4;
  *this = &(*this)[(_DWORD)v4];
  return 0;
}
