int __thiscall sub_6A554C(_DWORD *this, int a2, unsigned int a3, int a4, _DWORD *a5)
{
  _DWORD *v6; // esi
  int v7; // edx
  int v8; // eax
  int v9; // ecx
  unsigned int v10; // edi
  int result; // eax
  unsigned int v12; // ecx
  unsigned int v13; // eax
  _DWORD *v14; // ecx
  unsigned int v15; // [esp+Ch] [ebp-1Ch]
  unsigned int v16; // [esp+Ch] [ebp-1Ch]
  int v17; // [esp+10h] [ebp-18h]
  unsigned int v18; // [esp+14h] [ebp-14h]
  int v19; // [esp+18h] [ebp-10h]
  unsigned int v20; // [esp+1Ch] [ebp-Ch]
  int v21; // [esp+20h] [ebp-8h]
  int v22; // [esp+24h] [ebp-4h]

  v22 = 0;
  if ( !this[3] )
    return 0;
  while ( 1 )
  {
    v6 = *(_DWORD **)(this[6] + 4 * v22);
    if ( v6 )
    {
      if ( v6[9] != 1 )
      {
        if ( *v6 )
        {
          v17 = 0;
          v20 = 0;
          if ( v6[3] )
            break;
        }
      }
    }
LABEL_30:
    if ( (unsigned int)++v22 >= this[3] )
      return 0;
  }
  do
  {
    v21 = 0;
    if ( a3 )
    {
      while ( 1 )
      {
        v7 = *(_DWORD *)(a2 + 4 * v21);
        v8 = *(_DWORD *)(this[5] + 4 * v7);
        if ( *(_DWORD *)(v8 + 4) == this[32] && *(_BYTE *)(v8 + 108) != 3 )
        {
          sub_686791(
            (int)this,
            v6[15],
            4513,
            "cannot perform dependent texture read which in any way is based on color inputs");
          return -2147467259;
        }
        v9 = *(_DWORD *)(v6[4] + 4 * v20);
        if ( v9 == v7 || v9 == *(_DWORD *)(v8 + 56) )
        {
          v10 = *v6 & 0xFFFFF;
          v18 = 0;
          v15 = v6[1] / v10;
          if ( v15 )
            break;
        }
LABEL_15:
        if ( ++v21 >= a3 )
          goto LABEL_16;
      }
      v19 = 0;
      while ( 1 )
      {
        result = sub_6A554C(v19 + v6[2], v10, a4, a5);
        if ( result < 0 )
          return result;
        ++v18;
        v19 += 4 * v10;
        v17 = 1;
        if ( v18 >= v15 )
          goto LABEL_15;
      }
    }
LABEL_16:
    ++v20;
  }
  while ( v20 < v6[3] );
  if ( !v17 )
    goto LABEL_30;
  v12 = *v6 & 0xFFF00000;
  if ( v12 != 1610612736
    && v12 != 1615855616
    && v12 != 1621098496
    && v12 != 1626341376
    && v12 != 1925185536
    && v12 != 1926234112
    && v12 != 285212672
    || (v13 = *v6 & 0xFFFFF, v16 = 2 * v13, v13 >= 2 * v13) )
  {
LABEL_29:
    *(_DWORD *)(a4 + 4 * *a5) = v6;
    *(_DWORD *)(*(_DWORD *)(this[6] + 4 * v22) + 36) = 1;
    ++*a5;
    goto LABEL_30;
  }
  v14 = (_DWORD *)(v6[2] + 4 * v13);
  while ( *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *v14) + 4) != this[34] )
  {
    ++v13;
    ++v14;
    if ( v13 >= v16 )
      goto LABEL_29;
  }
  sub_686791((int)this, v6[15], 4534, "cannot perform double dependent texture read in ps_1_x");
  return -2147467259;
}
