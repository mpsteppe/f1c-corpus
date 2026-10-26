int __thiscall sub_692044(_DWORD *this)
{
  int v2; // edx
  _DWORD *v3; // eax
  int v4; // ecx
  int v5; // ecx
  int *v6; // esi
  unsigned int i; // ebx
  _DWORD *v8; // eax
  int v9; // ecx
  int v10; // ebx
  int v11; // edx
  int v12; // eax
  int v13; // ecx
  unsigned int v14; // eax
  int ii; // ecx
  int v16; // ebx
  int i2; // eax
  int v18; // ebx
  int kk; // eax
  int v20; // ebx
  unsigned int mm; // eax
  int v22; // ecx
  int v23; // ecx
  int v24; // eax
  int v25; // edx
  int v26; // ecx
  unsigned int m; // [esp+98h] [ebp-10h]
  unsigned int nn; // [esp+98h] [ebp-10h]
  int v30; // [esp+9Ch] [ebp-Ch]
  unsigned int n; // [esp+A0h] [ebp-8h]
  unsigned int i1; // [esp+A0h] [ebp-8h]
  unsigned int jj; // [esp+A0h] [ebp-8h]
  unsigned int k; // [esp+A0h] [ebp-8h]
  unsigned int j; // [esp+A4h] [ebp-4h]
  unsigned int v36; // [esp+A4h] [ebp-4h]
  unsigned int v37; // [esp+A4h] [ebp-4h]

  v2 = 0;
  if ( this[2] )
  {
    while ( 1 )
    {
      v3 = *(_DWORD **)(this[5] + 4 * v2);
      v4 = *(_DWORD *)(this[4] + 4 * v3[1]);
      v3[12] = v3[5];
      v3[16] = v3[6];
      v5 = *(_DWORD *)(v4 + 4);
      if ( (v5 & 0x10) != 0 )
        break;
      if ( (v5 & 0x11028) == 0 )
      {
        v3[6] = 0;
        goto LABEL_6;
      }
LABEL_7:
      if ( (unsigned int)++v2 >= this[2] )
        goto LABEL_8;
    }
    v3[6] = 1;
LABEL_6:
    v3[5] = -1;
    goto LABEL_7;
  }
LABEL_8:
  v30 = this[3];
  while ( v30 )
  {
    --v30;
    v6 = *(int **)(this[6] + 4 * v30);
    if ( (*((_WORD *)v6 + 1) & 0xFFF0) != 0 )
    {
      for ( i = 1; i < v6[3]; ++i )
        sub_688F3E(
          this,
          *(_DWORD **)(this[5] + 4 * *(_DWORD *)v6[4]),
          *(_DWORD *)(this[5] + 4 * *(_DWORD *)(v6[4] + 4 * i)));
      for ( j = 1;
            j < v6[3];
            *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *(_DWORD *)(v11 + v6[4])) + 24) = *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *(_DWORD *)v6[4])
                                                                                              + 24) )
      {
        v8 = (_DWORD *)v6[4];
        v9 = this[5];
        v10 = *(_DWORD *)(v9 + 4 * *v8);
        v11 = 4 * j;
        v12 = *(_DWORD *)(v9 + 4 * v8[j++]);
        *(_DWORD *)(v12 + 20) = *(_DWORD *)(v10 + 20);
      }
      v13 = *v6;
      v14 = *v6 & 0xFFF00000;
      if ( v14 == 544210944 || v14 == 545259520 || v14 == 290455552 )
      {
        for ( k = 0;
              k < v6[3];
              *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *(_DWORD *)(v24 + v6[4])) + 24) = *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *(_DWORD *)(v24 + v6[2])) + 20))
                                                                                                + 24) )
        {
          v23 = this[5];
          v24 = 4 * k;
          v25 = *(_DWORD *)(*(_DWORD *)(v23 + 4 * *(_DWORD *)(*(_DWORD *)(v23 + 4 * *(_DWORD *)(4 * k + v6[2])) + 20))
                          + 20);
          v26 = *(_DWORD *)(v23 + 4 * *(_DWORD *)(4 * k++ + v6[4]));
          *(_DWORD *)(v26 + 20) = v25;
        }
      }
      else if ( v14 == 287309824 )
      {
        v36 = 0;
        for ( m = v6[1] / (v13 & 0xFFFFFu); v36 < v6[3]; ++v36 )
        {
          for ( n = 0; n < m; ++n )
          {
            for ( ii = *(_DWORD *)(v6[2] + 4 * (v36 + n * v6[3]));
                  ii != -1;
                  ii = *(_DWORD *)(*(_DWORD *)(v16 + this[5]) + 8) )
            {
              v16 = 4 * ii;
              sub_688F3E(
                this,
                *(_DWORD **)(4 * ii + this[5]),
                *(_DWORD *)(this[5] + 4 * *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *(_DWORD *)(v6[4] + 4 * v36)) + 20)));
            }
          }
        }
      }
      else if ( (v13 & 0xF0000000) < 0x10000000 || (v13 & 0xF0000000) > 0x40000000 )
      {
        if ( v6[3] )
        {
          for ( jj = 0; jj < v6[1]; ++jj )
          {
            for ( kk = *(_DWORD *)(v6[2] + 4 * jj); kk != -1; kk = *(_DWORD *)(*(_DWORD *)(this[5] + v20) + 8) )
            {
              v20 = 4 * kk;
              sub_688F3E(this, *(_DWORD **)(4 * kk + this[5]), *(_DWORD *)(this[5] + 4 * *(_DWORD *)v6[4]));
            }
          }
        }
        else
        {
          for ( mm = 0; mm < v6[1]; *(_DWORD *)(v22 + 24) = 1 )
          {
            *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *(_DWORD *)(v6[2] + 4 * mm)) + 20) = -1;
            v22 = *(_DWORD *)(this[5] + 4 * *(_DWORD *)(v6[2] + 4 * mm++));
          }
        }
      }
      else
      {
        v37 = 0;
        for ( nn = v6[1] / (v13 & 0xFFFFFu); v37 < v6[3]; ++v37 )
        {
          for ( i1 = 0; i1 < nn; ++i1 )
          {
            for ( i2 = *(_DWORD *)(v6[2] + 4 * (v37 + i1 * v6[3]));
                  i2 != -1;
                  i2 = *(_DWORD *)(*(_DWORD *)(v18 + this[5]) + 8) )
            {
              v18 = 4 * i2;
              sub_688F3E(this, *(_DWORD **)(4 * i2 + this[5]), *(_DWORD *)(this[5] + 4 * *(_DWORD *)(v6[4] + 4 * v37)));
            }
          }
        }
      }
    }
  }
  return off_16C92E4();
}
