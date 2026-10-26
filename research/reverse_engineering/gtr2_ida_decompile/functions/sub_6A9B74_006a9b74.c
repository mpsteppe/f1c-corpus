int __thiscall sub_6A9B74(
        _DWORD *this,
        int a2,
        unsigned int a3,
        _DWORD *a4,
        _DWORD *a5,
        _DWORD *a6,
        _DWORD *a7,
        int a8,
        int a9)
{
  unsigned int v10; // esi
  int v11; // edi
  int v13; // eax
  unsigned int v14; // edx
  _DWORD *v15; // eax
  _DWORD *v16; // eax
  unsigned int v17; // ecx
  int v18; // eax
  unsigned int v19; // [esp+Ch] [ebp-8h]
  int v21; // [esp+24h] [ebp+10h]
  unsigned int v22; // [esp+24h] [ebp+10h]
  unsigned int v23; // [esp+38h] [ebp+24h]
  int v24; // [esp+38h] [ebp+24h]

  v10 = *a4 & 0xFFFFF;
  v11 = 0;
  *a7 = 0;
  *a6 = 0;
  *a5 = 0;
  if ( !v10 )
    return -2147467259;
  v13 = a4[1] / v10;
  v19 = v13;
  if ( !a9 )
  {
    v23 = 0;
    if ( v13 )
    {
      v21 = 0;
      do
      {
        v14 = 0;
        v15 = (_DWORD *)(v21 + a4[2]);
        do
        {
          if ( *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *v15) + 16) != v14 )
            return 1;
          ++v14;
          ++v15;
        }
        while ( v14 < v10 );
        v11 = 0;
        ++v23;
        v21 += 4 * v10;
        v13 = v19;
      }
      while ( v23 < v19 );
    }
  }
  v24 = 0;
  v22 = 0;
  if ( !v13 )
    return 0;
  while ( 1 )
  {
    v16 = (_DWORD *)sub_6A9A7C(this, a2, a3, a4[2] + 4 * v11, v10, a8);
    if ( !v16 )
      goto LABEL_26;
    v17 = *v16 & 0xFFF00000;
    if ( a8 )
      break;
    if ( v17 == 1913651200 )
      goto LABEL_21;
LABEL_26:
    ++v22;
    v11 += v10;
    if ( v22 >= v19 )
      return 0;
  }
  if ( v17 != 1610612736 && v17 != 1615855616 && v17 != 1621098496 && v17 != 1626341376 )
    goto LABEL_26;
LABEL_21:
  if ( !v24 )
  {
    *a7 = v16;
    v24 = 1;
    *a6 = v11;
    if ( a8 )
      v18 = *(_DWORD *)(v16[2] + 4 * (*v16 & 0xFFFFF));
    else
      v18 = *(_DWORD *)v16[2];
    *a5 = *(unsigned __int8 *)(*(_DWORD *)(this[5] + 4 * v18) + 109);
    goto LABEL_26;
  }
  *a6 = 0;
  *a5 = 0;
  *a7 = 0;
  return 1;
}
