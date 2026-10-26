int __cdecl __ld12mul(int a1, int a2)
{
  __int16 v3; // cx
  __int16 v5; // ax
  __int16 v6; // di
  int v7; // ecx
  __int16 v8; // di
  int result; // eax
  int v10; // edi
  unsigned __int16 v11; // dx
  int v12; // ebx
  int v13; // [esp+Ch] [ebp-28h]
  unsigned __int16 *v14; // [esp+10h] [ebp-24h]
  unsigned __int16 *v15; // [esp+14h] [ebp-20h]
  int v16; // [esp+18h] [ebp-1Ch]
  int v17; // [esp+1Ch] [ebp-18h]
  int *v18; // [esp+20h] [ebp-14h]
  int v19[4]; // [esp+24h] [ebp-10h] BYREF
  int v20; // [esp+3Ch] [ebp+8h]
  int v21; // [esp+3Ch] [ebp+8h]
  int i; // [esp+40h] [ebp+Ch]

  v19[3] = dword_912B08;
  v3 = *(_WORD *)(a2 + 10);
  v16 = 0;
  memset(v19, 0, 12);
  v5 = *(_WORD *)(a1 + 10);
  v6 = v3;
  v7 = v3 & 0x7FFF;
  v8 = v5 ^ v6;
  result = v5 & 0x7FFF;
  v10 = v8 & 0x8000;
  v11 = v7 + result;
  v20 = v7 + result;
  if ( (unsigned __int16)result < 0x7FFFu && (unsigned __int16)v7 < 0x7FFFu && v11 <= 0xBFFDu )
  {
    if ( v11 <= 0x3FBFu )
    {
      result = 0;
LABEL_16:
      *(_DWORD *)(a1 + 8) = 0;
      *(_DWORD *)(a1 + 4) = 0;
      *(_DWORD *)a1 = 0;
      return result;
    }
    if ( (_WORD)result )
    {
      result = 0;
    }
    else
    {
      ++v20;
      result = 0;
      if ( (*(_DWORD *)(a1 + 8) & 0x7FFFFFFF) == 0 && !*(_DWORD *)(a1 + 4) && !*(_DWORD *)a1 )
        goto LABEL_45;
    }
    if ( !(_WORD)v7 )
    {
      ++v20;
      if ( (*(_DWORD *)(a2 + 8) & 0x7FFFFFFF) == 0 && !*(_DWORD *)(a2 + 4) && !*(_DWORD *)a2 )
        goto LABEL_16;
    }
    v17 = 0;
    v18 = &v19[1];
    for ( i = 5; i > 0; --i )
    {
      v14 = (unsigned __int16 *)(a1 + 2 * v17);
      v15 = (unsigned __int16 *)(a2 + 8);
      v13 = i;
      do
      {
        if ( __addl(*(v18 - 1), *v14 * *v15, (unsigned int *)v18 - 1) )
          ++*(_WORD *)v18;
        ++v14;
        --v15;
        --v13;
      }
      while ( v13 );
      v18 = (int *)((char *)v18 + 2);
      ++v17;
    }
    v21 = v20 + 49154;
    if ( (__int16)v21 <= 0 )
      goto LABEL_49;
    do
    {
      if ( v19[2] < 0 )
        break;
      __shl_12(v19);
      v21 += 0xFFFF;
    }
    while ( (__int16)v21 > 0 );
    if ( (__int16)v21 <= 0 )
    {
LABEL_49:
      v21 += 0xFFFF;
      if ( (v21 & 0x8000u) != 0 )
      {
        v12 = (unsigned __int16)-(__int16)v21;
        v21 += v12;
        do
        {
          if ( (v19[0] & 1) != 0 )
            ++v16;
          __shr_12(v19);
          --v12;
        }
        while ( v12 );
        if ( v16 )
          LOBYTE(v19[0]) |= 1u;
      }
    }
    if ( LOWORD(v19[0]) > 0x8000u || (v19[0] & 0x1FFFF) == 0x18000 )
    {
      if ( *(int *)((char *)v19 + 2) == -1 )
      {
        *(int *)((char *)v19 + 2) = 0;
        if ( *(int *)((char *)&v19[1] + 2) == -1 )
        {
          *(int *)((char *)&v19[1] + 2) = 0;
          if ( HIWORD(v19[2]) == 0xFFFF )
          {
            ++v21;
            HIWORD(v19[2]) = 0x8000;
          }
          else
          {
            ++HIWORD(v19[2]);
          }
        }
        else
        {
          ++*(int *)((char *)&v19[1] + 2);
        }
      }
      else
      {
        ++*(int *)((char *)v19 + 2);
      }
    }
    result = v21;
    if ( (unsigned __int16)v21 < 0x7FFFu )
    {
      *(_WORD *)a1 = HIWORD(v19[0]);
      *(_DWORD *)(a1 + 2) = v19[1];
      *(_DWORD *)(a1 + 6) = v19[2];
      result = v10 | v21;
LABEL_45:
      *(_WORD *)(a1 + 10) = result;
      return result;
    }
  }
  *(_DWORD *)(a1 + 4) = 0;
  *(_DWORD *)a1 = 0;
  *(_DWORD *)(a1 + 8) = (_WORD)v10 != 0 ? -32768 : 2147450880;
  return result;
}
