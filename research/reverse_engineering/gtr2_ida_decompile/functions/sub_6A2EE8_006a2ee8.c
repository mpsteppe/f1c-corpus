int __thiscall sub_6A2EE8(_DWORD *this)
{
  int *v2; // edx
  int v3; // ecx
  unsigned int v4; // eax
  _DWORD *v5; // eax
  char *v6; // edi
  int v7; // eax
  int v8; // ebx
  int v9; // eax
  int v10; // edx
  bool v11; // cf
  unsigned int v12; // ecx
  int v14; // esi
  int v15; // [esp+14h] [ebp-10h]
  int v16; // [esp+18h] [ebp-Ch]
  unsigned int v17; // [esp+1Ch] [ebp-8h]
  int v18; // [esp+20h] [ebp-4h]

  v18 = 0;
  if ( !this[19] )
    return 0;
  while ( 1 )
  {
    v2 = *(int **)(this[140] + 4 * v18);
    if ( v2 )
    {
      v3 = *v2;
      v4 = *v2 & 0xFFF00000;
      if ( v4 != 1913651200 )
      {
        if ( v4 )
        {
          v17 = v3 & 0xFFFFF;
          v16 = 4 * (v4 != 285212672 ? v3 & 0xFFFFF : 0);
          if ( (*(_BYTE *)(*(_DWORD *)(this[4] + 4
                                               * *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *(_DWORD *)(v16 + v2[2])) + 4))
                         + 5)
              & 2) != 0 )
          {
            v5 = (_DWORD *)sub_681186(116);
            if ( v5 )
              v6 = (char *)sub_680CEC(v5);
            else
              v6 = 0;
            if ( !v6 )
              return -2147024882;
            v7 = sub_6811D1(v6, v17 & 0xFFFFF | 0x10000000, v17, v17, 0);
            if ( v7 < 0 )
              break;
            v7 = sub_680D22(v6, *(_DWORD *)(this[140] + 4 * v18));
            if ( v7 < 0 )
              break;
            v8 = 0;
            v15 = 0;
            if ( v17 )
            {
              do
              {
                v9 = sub_681AAA(this, this[34], 0, v8, 0.0);
                *(_DWORD *)(*(_DWORD *)(this[5] + 4 * v9) + 60) = 0;
                *(_DWORD *)(*((_DWORD *)v6 + 4) + 4 * v8) = v9;
                *(_DWORD *)(*((_DWORD *)v6 + 2) + 4 * v15) = *(_DWORD *)(v16
                                                                       + *(_DWORD *)(*(_DWORD *)(this[140] + 4 * v18) + 8));
                v10 = v16;
                v16 += 4;
                v8 = v15 + 1;
                v11 = v15 + 1 < v17;
                *(_DWORD *)(v10 + *(_DWORD *)(*(_DWORD *)(this[140] + 4 * v18) + 8)) = v9;
                ++v15;
              }
              while ( v11 );
            }
            v12 = this[136];
            if ( v12 >= 0x200 )
            {
              v14 = -2147024882;
              goto LABEL_21;
            }
            *(_DWORD *)(this[139] + 4 * v12) = v6;
            ++this[136];
            v7 = sub_681997((int)this, v6);
            if ( v7 < 0 )
              break;
          }
        }
      }
    }
    if ( (unsigned int)++v18 >= this[19] )
      return 0;
  }
  v14 = v7;
LABEL_21:
  sub_66238F(v6, 1);
  return v14;
}
