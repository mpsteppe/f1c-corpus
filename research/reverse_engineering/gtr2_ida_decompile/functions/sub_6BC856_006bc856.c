int __thiscall sub_6BC856(unsigned int *this)
{
  _DWORD *v2; // ecx
  unsigned int v3; // eax
  int v4; // edx
  unsigned int v5; // edi
  unsigned int v6; // ecx
  int v7; // eax
  int result; // eax
  int v9; // ebx
  int v10; // edi
  unsigned int v11; // eax
  unsigned int *v12; // ecx
  _DWORD *v13; // [esp+14h] [ebp-Ch]
  unsigned int v14; // [esp+18h] [ebp-8h]
  unsigned int v15; // [esp+1Ch] [ebp-4h]

  v2 = *(_DWORD **)(this[64] + 16);
  v3 = this[5];
  v4 = *(_DWORD *)(v3 + 4 * *v2);
  if ( (*(_BYTE *)(*(_DWORD *)(this[4] + 4 * *(_DWORD *)(v4 + 4)) + 4) & 1) == 0
    || *(_DWORD *)(v4 + 60)
    || *(_DWORD *)(*(_DWORD *)(v3 + 4 * v2[1]) + 60) )
  {
    v14 = 0;
    if ( this[2] )
    {
      v5 = this[2];
      do
      {
        if ( this[34] == *(_DWORD *)(*(_DWORD *)v3 + 4) )
        {
          v6 = *(_DWORD *)(*(_DWORD *)v3 + 12);
          if ( v6 >= v14 )
            v14 = v6 + 1;
        }
        v3 += 4;
        --v5;
      }
      while ( v5 );
    }
    v7 = sub_681B0A(this, 268435460, 4, 4);
    if ( v7 != -1 )
    {
      v13 = *(_DWORD **)(this[6] + 4 * v7);
      result = sub_680D22(v13, this[64]);
      if ( result < 0 )
        return result;
      v15 = 0;
      while ( 1 )
      {
        v9 = sub_681AAA(this, this[34], v14, v15, 0.0);
        if ( v9 == -1 )
          break;
        v10 = 4 * v15;
        result = sub_681692(
                   *(_DWORD **)(this[5] + 4 * v9),
                   *(_DWORD **)(this[5] + 4 * *(_DWORD *)(4 * v15 + *(_DWORD *)(this[64] + 16))));
        if ( result < 0 )
          return result;
        *(_DWORD *)(*(_DWORD *)(this[5] + 4 * v9) + 24) = *(_DWORD *)(*(_DWORD *)(this[5]
                                                                                + 4
                                                                                * *(_DWORD *)(v10
                                                                                            + *(_DWORD *)(this[64] + 16)))
                                                                    + 24);
        ++v15;
        *(_DWORD *)(*(_DWORD *)(this[5] + 4 * v9) + 20) = *(_DWORD *)(*(_DWORD *)(this[5]
                                                                                + 4
                                                                                * *(_DWORD *)(v10
                                                                                            + *(_DWORD *)(this[64] + 16)))
                                                                    + 20);
        *(_DWORD *)(v10 + v13[4]) = *(_DWORD *)(v10 + *(_DWORD *)(this[64] + 16));
        *(_DWORD *)(v10 + *(_DWORD *)(this[64] + 16)) = v9;
        *(_DWORD *)(v10 + v13[2]) = v9;
        if ( v15 >= 4 )
        {
          v11 = this[3] - 2;
          v12 = this + 63;
          while ( v11 > *v12 )
          {
            *(_DWORD *)(this[6] + 4 * v11 + 4) = *(_DWORD *)(this[6] + 4 * v11);
            --v11;
          }
          *(_DWORD *)(this[6] + 4 * *v12 + 4) = v13;
          goto LABEL_21;
        }
      }
    }
    return -2147024882;
  }
  else
  {
LABEL_21:
    this[99] = 1;
    return 0;
  }
}
