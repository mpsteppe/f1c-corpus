unsigned int __usercall sub_6B8DC8@<eax>(int a1@<ebx>)
{
  unsigned int v1; // edx
  unsigned int v2; // ecx
  int v3; // esi
  unsigned int result; // eax
  int v5; // ecx
  int v6; // eax
  _WORD *v7; // eax
  unsigned int v8; // esi
  _WORD *v9; // eax
  const void **v10; // esi
  char *v11; // ecx
  void *v12; // edi
  unsigned int v13; // ecx
  _DWORD *v14; // eax
  const void *v15; // eax
  unsigned int v16; // edi
  unsigned __int8 *v17; // esi
  int v18; // eax
  int v19; // ecx
  const void **v20; // [esp+8h] [ebp-Ch]
  unsigned int v21; // [esp+Ch] [ebp-8h]
  unsigned int v22; // [esp+10h] [ebp-4h]
  unsigned int v23; // [esp+10h] [ebp-4h]

  v1 = *(_DWORD *)(a1 + 36);
  v21 = v1;
  do
  {
    v2 = *(_DWORD *)(a1 + 100);
    v3 = *(_DWORD *)(a1 + 108);
    result = *(_DWORD *)(a1 + 52) - v2 - v3;
    v22 = result;
    if ( result )
    {
      if ( result == -1 )
      {
        result = -2;
        goto LABEL_14;
      }
    }
    else if ( !v2 && !v3 )
    {
      result = v1;
      goto LABEL_14;
    }
    if ( v2 >= v1 + *(_DWORD *)(a1 + 36) - 262 )
    {
      qmemcpy(*(void **)(a1 + 48), (const void *)(*(_DWORD *)(a1 + 48) + v1), v1);
      v5 = *(_DWORD *)(a1 + 68);
      v6 = *(_DWORD *)(a1 + 60);
      *(_DWORD *)(a1 + 104) -= v1;
      *(_DWORD *)(a1 + 100) -= v1;
      *(_DWORD *)(a1 + 84) -= v1;
      v7 = (_WORD *)(v6 + 2 * v5);
      do
      {
        --v7;
        --v5;
        *v7 = (*v7 - v1) & ~(unsigned __int16)(((unsigned __int16)*v7 - (unsigned __int64)v1) >> 32);
      }
      while ( v5 );
      v8 = v1;
      v9 = (_WORD *)(*(_DWORD *)(a1 + 56) + 2 * v1);
      do
      {
        --v9;
        --v8;
        *v9 = (*v9 - v1) & ~(unsigned __int16)(((unsigned __int16)*v9 - (unsigned __int64)v1) >> 32);
      }
      while ( v8 );
      result = v1 + v22;
    }
LABEL_14:
    v10 = *(const void ***)a1;
    v20 = *(const void ***)a1;
    if ( !*(_DWORD *)(*(_DWORD *)a1 + 4) )
      break;
    v11 = (char *)v10[1];
    v12 = (void *)(*(_DWORD *)(a1 + 48) + *(_DWORD *)(a1 + 100) + *(_DWORD *)(a1 + 108));
    v23 = (unsigned int)v11;
    if ( (unsigned int)v11 > result )
      v23 = result;
    if ( v23 )
    {
      v14 = v10[7];
      v10[1] = &v11[-v23];
      if ( !v14[6] )
      {
        v15 = (const void *)sub_6D9497(v10[12], *v10, v23);
        v1 = v21;
        v10[12] = v15;
      }
      qmemcpy(v12, *v10, v23);
      v13 = v23;
      result = (unsigned int)v20;
      *v20 = (char *)*v20 + v23;
      v20[2] = (char *)v20[2] + v23;
    }
    else
    {
      v13 = 0;
    }
    *(_DWORD *)(a1 + 108) += v13;
    v16 = *(_DWORD *)(a1 + 108);
    if ( v16 >= 3 )
    {
      v17 = (unsigned __int8 *)(*(_DWORD *)(a1 + 100) + *(_DWORD *)(a1 + 48));
      v18 = *v17;
      v19 = *(_DWORD *)(a1 + 80);
      *(_DWORD *)(a1 + 64) = v18;
      result = *(_DWORD *)(a1 + 76) & (v17[1] ^ (v18 << v19));
      *(_DWORD *)(a1 + 64) = result;
    }
    if ( v16 >= 0x106 )
      break;
    result = *(_DWORD *)a1;
  }
  while ( *(_DWORD *)(*(_DWORD *)a1 + 4) );
  return result;
}
