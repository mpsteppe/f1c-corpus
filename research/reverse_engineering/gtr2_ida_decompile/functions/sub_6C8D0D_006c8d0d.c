int __thiscall sub_6C8D0D(_DWORD *this)
{
  int *v2; // eax
  int v3; // ecx
  _DWORD *v4; // edx
  _DWORD *v5; // esi
  double v6; // st7
  int v7; // esi
  char *v8; // eax
  int v9; // edx
  int v10; // ecx
  unsigned int v11; // esi
  int v12; // ecx
  int *v13; // eax
  _DWORD *v14; // ecx
  _DWORD *v15; // edx
  int *v16; // esi
  int result; // eax
  int v18; // [esp+Ch] [ebp-10h]
  char *v19; // [esp+10h] [ebp-Ch]
  int v20; // [esp+14h] [ebp-8h]
  unsigned int v21; // [esp+14h] [ebp-8h]
  int v22; // [esp+18h] [ebp-4h]
  int v23; // [esp+18h] [ebp-4h]

  this[87] = 0;
  v2 = (int *)this[64];
  if ( (*v2 & 0xFFF00000) != 0x20400000 )
    return 1;
  v3 = *v2 & 0xFFFFF;
  v22 = 1;
  if ( !v3 )
    goto LABEL_8;
  v4 = (_DWORD *)v2[2];
  v5 = &v4[v3];
  v20 = *v2 & 0xFFFFF;
  do
  {
    if ( *v4 != *v5 )
      v22 = 0;
    ++v5;
    ++v4;
    --v20;
  }
  while ( v20 );
  if ( !v22 )
  {
    v6 = -0.5;
  }
  else
  {
LABEL_8:
    v2 = sub_6C5028(this, v3 | 0x20400000, (int)v2, 0, 2, 1);
    v6 = -1.0;
    if ( !v2 )
      return 1;
    v18 = (int)v2;
  }
  v7 = *v2;
  v8 = (char *)v2[2];
  v9 = this[5];
  v10 = this[4];
  v11 = v7 & 0xFFFFF;
  if ( (*(_BYTE *)(*(_DWORD *)(v10 + 4 * *(_DWORD *)(*(_DWORD *)(v9 + 4 * *(_DWORD *)&v8[4 * v11]) + 4)) + 5) & 1) != 0 )
  {
    v19 = v8;
    v8 += 4 * v11;
  }
  else
  {
    if ( (*(_BYTE *)(*(_DWORD *)(v10 + 4 * *(_DWORD *)(*(_DWORD *)(v9 + 4 * *(_DWORD *)v8) + 4)) + 5) & 1) == 0 )
      return 1;
    v19 = &v8[4 * v11];
  }
  v12 = 0;
  if ( v11 )
  {
    while ( *(double *)(*(_DWORD *)(v9 + 4 * *(_DWORD *)&v8[4 * v12]) + 32) == v6 )
    {
      if ( ++v12 >= v11 )
        goto LABEL_18;
    }
    return 1;
  }
LABEL_18:
  if ( !v22 )
  {
    v13 = sub_6C5028(this, *(_DWORD *)this[64] & 0xFFFFF | 0x20400000, this[64], 0, 2, 2);
    if ( v13 )
    {
      v23 = 1;
      if ( !v11 )
        goto LABEL_26;
      v14 = (_DWORD *)v13[2];
      v15 = &v14[v11];
      v21 = v11;
      do
      {
        if ( *v14 != *v15 )
          v23 = 0;
        ++v15;
        ++v14;
        --v21;
      }
      while ( v21 );
      if ( v23 )
      {
LABEL_26:
        v16 = v13;
        result = sub_6C73E9((int)this, 393216, 0, v19, 393216, (int)v13, 0);
        goto LABEL_28;
      }
    }
    return 1;
  }
  v16 = (int *)v18;
  result = sub_6C73E9((int)this, 393216, 0, *(char **)(this[64] + 8), 393216, v18, 0);
LABEL_28:
  if ( !result )
    *v16 = 0;
  return result;
}
