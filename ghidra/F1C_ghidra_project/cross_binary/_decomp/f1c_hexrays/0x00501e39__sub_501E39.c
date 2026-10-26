// f1c  0x00501e39  size=646
unsigned int __thiscall sub_501E39(_DWORD *this, _BYTE *a2, unsigned int a3)
{
  _BYTE *v5; // edi
  bool v6; // zf
  int v7; // ebx
  int v8; // ecx
  _BYTE *v9; // eax
  unsigned __int8 *v10; // edi
  unsigned __int8 v11; // al
  int v12; // [esp+8h] [ebp-18h]
  int v13; // [esp+Ch] [ebp-14h]
  _BYTE *v14; // [esp+10h] [ebp-10h]
  _BYTE *v15; // [esp+14h] [ebp-Ch]
  unsigned int v16; // [esp+18h] [ebp-8h]
  int v17; // [esp+1Ch] [ebp-4h]
  unsigned int v18; // [esp+2Ch] [ebp+Ch]
  unsigned int v19; // [esp+2Ch] [ebp+Ch]

  if ( a3 < 2 )
    return -2147467259;
  if ( *a2 != 80 )
    return -2147467259;
  if ( a2[1] == 51 )
  {
    v12 = 1;
  }
  else
  {
    if ( a2[1] != 54 )
      return -2147467259;
    v12 = 0;
  }
  v5 = a2 + 2;
  v6 = a3 == 2;
  v18 = a3 - 2;
  v7 = 0;
  v15 = a2 + 2;
  v17 = 0;
  v13 = 0;
  v16 = 255;
  if ( v6 )
    return -2147467259;
  while ( v12 || v17 != 3 )
  {
    if ( !sub_589BF3((unsigned __int8)*v5) )
    {
      if ( *v5 != 35 )
      {
        if ( v18 )
        {
          do
          {
            if ( sub_589BF3((unsigned __int8)*v5) )
              break;
            if ( !sub_589B9E((unsigned __int8)*v5) )
              return -2147467259;
            v8 = (unsigned __int8)*v5++;
            v6 = v18-- == 1;
            v7 = v8 + 10 * v7 - 48;
            v15 = v5;
          }
          while ( !v6 );
        }
        if ( v17 )
        {
          if ( v17 == 1 )
          {
            if ( !v7 )
              return -2147467259;
            v9 = (_BYTE *)sub_587C03(4 * v13 * v7);
            this[1] = v9;
            if ( !v9 )
              return -2147024882;
            a2 = v9;
            this[13] = 0;
            v14 = &v9[4 * v13 * v7];
            v5 = v15;
            this[14] = 1;
            *this = 22;
            this[12] = 4 * v13;
            this[3] = v13;
            this[4] = v7;
            this[5] = 1;
            goto LABEL_39;
          }
          if ( v17 != 2 )
          {
            switch ( v17 )
            {
              case 3:
                if ( a2 >= v14 )
                  return -2147467259;
                *(_DWORD *)a2 = ((255 * v7 / v16) | 0xFFFFFF00) << 16;
                break;
              case 4:
                *(_DWORD *)a2 |= (255 * v7 / v16) << 8;
                break;
              case 5:
                *(_DWORD *)a2 |= 255 * v7 / v16;
                a2 += 4;
                if ( a2 == v14 )
                  return 0;
                v17 = 2;
                break;
            }
            goto LABEL_39;
          }
          v16 = v7;
        }
        else
        {
          v13 = v7;
        }
        if ( !v7 )
          return -2147467259;
LABEL_39:
        ++v17;
        goto LABEL_40;
      }
      for ( ; v18; --v18 )
      {
        if ( *v5 == 10 )
          break;
        ++v5;
      }
    }
    ++v5;
    --v18;
    v15 = v5;
LABEL_40:
    v7 = 0;
    if ( !v18 )
      return -2147467259;
  }
  if ( v16 > 0xFF )
    return -2147467259;
  if ( v18 > 1 && *v5 == 13 )
  {
    ++v5;
    --v18;
  }
  v10 = v5 + 1;
  v19 = v18 - 1;
  if ( v19 )
  {
    do
    {
      if ( a2 >= v14 )
        break;
      v11 = 255 * (unsigned int)*v10 / v16;
      v10 += 3;
      *(_DWORD *)a2 = (255 * (unsigned int)*(v10 - 1) / v16)
                    | (((255 * (unsigned int)*(v10 - 2) / v16) | ((v11 | 0xFFFFFF00) << 8)) << 8);
      v6 = v19 == 3;
      v19 -= 3;
      a2 += 4;
    }
    while ( !v6 );
  }
  return v14 != a2 ? 0x80004005 : 0;
}
