int __thiscall sub_6A309B(_DWORD *this)
{
  _DWORD *v2; // eax
  char *v3; // edi
  int v5; // eax
  unsigned int i; // ecx
  int v7; // eax
  unsigned int j; // ebx
  int v9; // eax
  int v10; // eax
  int v11; // esi
  unsigned int v12; // eax
  int v13; // eax
  unsigned int v14; // ecx
  _DWORD *v15; // eax
  unsigned int v16; // [esp+14h] [ebp-14h]
  unsigned int v17; // [esp+18h] [ebp-10h]
  unsigned int k; // [esp+1Ch] [ebp-Ch]
  int v19; // [esp+20h] [ebp-8h]
  int v20; // [esp+24h] [ebp-4h]
  int v21; // [esp+24h] [ebp-4h]

  v17 = this[3];
  v2 = (_DWORD *)sub_681186(116);
  if ( v2 )
    v3 = (char *)sub_680CEC(v2);
  else
    v3 = 0;
  if ( !v3 )
    return -2147024882;
  v5 = sub_6811D1(v3, 268435460, 4, 4, 0);
  if ( v5 < 0 )
  {
LABEL_15:
    v11 = v5;
LABEL_16:
    sub_66238F(v3, 1);
    return v11;
  }
  else
  {
    v20 = -1;
    for ( i = 0; i < this[2]; ++i )
    {
      v7 = 4 * i;
      if ( *(_DWORD *)(*(_DWORD *)(4 * i + this[5]) + 4) == this[33] )
      {
        *(_DWORD *)(*((_DWORD *)v3 + 2) + 4 * *(_DWORD *)(*(_DWORD *)(v7 + this[5]) + 16)) = i;
        *(_DWORD *)(*(_DWORD *)(v7 + this[5]) + 4) = this[34];
        *(_DWORD *)(*(_DWORD *)(v7 + this[5]) + 12) = -1;
        v20 = *(_DWORD *)(*(_DWORD *)(v7 + this[5]) + 108);
      }
    }
    for ( j = 0; j < 4; ++j )
    {
      *(_DWORD *)(*((_DWORD *)v3 + 4) + 4 * j) = sub_681AAA(this, this[33], 0, j, 0.0);
      v9 = *((_DWORD *)v3 + 4);
      if ( *(_DWORD *)(v9 + 4 * j) == -1 )
      {
        v11 = -2147024882;
        goto LABEL_16;
      }
      v10 = *(_DWORD *)(this[5] + 4 * *(_DWORD *)(v9 + 4 * j));
      *(_DWORD *)(v10 + 60) = 0;
      *(_DWORD *)(v10 + 108) = v20;
    }
    v5 = sub_681997((int)this, v3);
    if ( v5 < 0 )
      goto LABEL_15;
    v12 = 0;
    for ( k = 0; k < v17; ++k )
    {
      v13 = *(_DWORD *)(this[6] + 4 * v12);
      v19 = v13;
      if ( v13 )
      {
        v16 = *(_DWORD *)(v13 + 12);
        if ( v16 )
        {
          if ( *(_DWORD *)(*(_DWORD *)(this[5] + 4 * **(_DWORD **)(v13 + 16)) + 4) == this[33] )
          {
            v21 = 0;
            while ( 1 )
            {
              v14 = 0;
              while ( 1 )
              {
                v15 = (_DWORD *)(*(_DWORD *)(v13 + 16) + 4 * v21);
                if ( *v15 == *(_DWORD *)(v14 + *((_DWORD *)v3 + 4)) )
                  *v15 = *(_DWORD *)(v14 + *((_DWORD *)v3 + 2));
                v14 += 4;
                if ( v14 >= 0x10 )
                  break;
                v13 = v19;
              }
              if ( ++v21 >= v16 )
                break;
              v13 = v19;
            }
          }
        }
      }
      v12 = k + 1;
    }
    return 0;
  }
}
