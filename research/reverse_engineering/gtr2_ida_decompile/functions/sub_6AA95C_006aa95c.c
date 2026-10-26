int __thiscall sub_6AA95C(_DWORD *this)
{
  _DWORD *v2; // ecx
  _DWORD *v3; // edi
  unsigned int i; // eax
  int v5; // eax
  int result; // eax
  int j; // eax
  int v8; // eax
  int v9; // ecx
  _DWORD *v10; // eax
  _DWORD v11[4]; // [esp+14h] [ebp-44h] BYREF
  _DWORD v12[4]; // [esp+24h] [ebp-34h] BYREF
  _BYTE v13[16]; // [esp+34h] [ebp-24h] BYREF
  _DWORD *v14; // [esp+44h] [ebp-14h]
  _BYTE *v15; // [esp+48h] [ebp-10h]
  int v16; // [esp+4Ch] [ebp-Ch]
  _DWORD *v17; // [esp+50h] [ebp-8h]
  int v18; // [esp+54h] [ebp-4h]

  v2 = (_DWORD *)this[64];
  v3 = (_DWORD *)v2[4];
  v18 = v2[3];
  v14 = v3;
  for ( i = 0; i < 4; ++i )
  {
    v11[i] = *(_DWORD *)(v2[2] + 12);
    v12[i] = *(_DWORD *)(v2[2] + 28);
  }
  v5 = *(_DWORD *)(this[5] + 4 * *v3);
  if ( *(_DWORD *)(v5 + 4) == this[33] )
  {
    if ( *(_DWORD *)(v5 + 108) != 1 )
    {
      sub_686791((int)this, *(_DWORD *)(this[64] + 60), 4813, "internal error: unexpected output register");
      return -2147467259;
    }
    for ( j = v18; j; *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *v3) + 4) = this[34] )
    {
      --j;
      *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *v3) + 12) = 0;
    }
  }
  if ( v18 )
  {
    v17 = v3;
    v15 = (_BYTE *)(v13 - (_BYTE *)v3);
    v16 = v18;
    while ( 1 )
    {
      v8 = sub_681AAA(this, 0, 0, 0, 0.0);
      ++v17;
      *(_DWORD *)((char *)v3 + (_DWORD)v15) = v8;
      v9 = this[5];
      v10 = *(_DWORD **)(v9 + 4 * v8);
      qmemcpy(v10, *(const void **)(v9 + 4 * *v3), 0x80u);
      v10[15] = 0;
      if ( !--v16 )
        break;
      v3 = v17;
    }
    v3 = v14;
  }
  result = sub_6CB29C(8, v13, v18, *(_DWORD *)(this[64] + 8), *(_DWORD *)(this[64] + 8) + 16, 0, 2, 0, 0, 0, 0);
  if ( result >= 0 )
    return sub_6CB29C(4, v3, v18, v11, v12, v13, v18, 0, 0, 0, 0);
  return result;
}
