int __thiscall sub_64BDEE(_DWORD *this)
{
  _DWORD *v1; // ebx
  _DWORD *v2; // eax
  _DWORD *v3; // ecx
  const void *v5; // esi
  const void *v6; // edi
  _DWORD *v7; // ecx
  int v8; // esi
  unsigned int v9; // edi
  char *v10; // eax
  char *v11; // edx
  unsigned int v12; // ebx
  char *v13; // edi
  char *v14; // esi
  char v15; // cl
  _DWORD *v16; // [esp+8h] [ebp-Ch]
  unsigned int i; // [esp+Ch] [ebp-8h]
  unsigned int v18; // [esp+10h] [ebp-4h]

  v1 = this;
  v2 = (_DWORD *)this[1];
  v3 = (_DWORD *)*this;
  v16 = v1;
  if ( v2[1] != v3[1] || v3[6] )
    return -2147467259;
  if ( v2[26] != v3[26] || v2[27] != v3[27] || v2[28] != v3[28] || v2[4] != v3[4] )
    return -2147467259;
  if ( !v2[3] )
    return sub_64ADF1(v1);
  if ( v2[7] )
  {
    v5 = (const void *)v2[14];
    v6 = (const void *)v3[14];
    if ( v5 != v6 )
    {
      if ( memcmp(v5, v6, 0x400u) )
        return -2147467259;
    }
  }
  v2[4] = 0;
  *(_DWORD *)(*v1 + 16) = 0;
  v7 = (_DWORD *)v1[1];
  v18 = 0;
  if ( v7[28] )
  {
    v8 = *v1;
    v9 = v7[27];
    do
    {
      v10 = (char *)(*(_DWORD *)(v1[1] + 32) + v18 * *(_DWORD *)(v1[1] + 100));
      v11 = (char *)(*(_DWORD *)(v8 + 32) + v18 * *(_DWORD *)(v8 + 100));
      for ( i = 0; i < v9; v9 = v7[27] )
      {
        v12 = v7[29];
        qmemcpy(v10, v11, 4 * (v12 >> 2));
        v14 = &v11[4 * (v12 >> 2)];
        v13 = &v10[4 * (v12 >> 2)];
        v15 = v12;
        v1 = v16;
        qmemcpy(v13, v14, v15 & 3);
        v7 = (_DWORD *)v16[1];
        v8 = *v16;
        v10 += v7[24];
        v11 += *(_DWORD *)(*v16 + 96);
        ++i;
      }
      ++v18;
      v7 = (_DWORD *)v1[1];
    }
    while ( v18 < v7[28] );
  }
  return 0;
}
