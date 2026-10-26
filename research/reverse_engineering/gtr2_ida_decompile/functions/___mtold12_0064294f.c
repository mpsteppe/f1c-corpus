__int16 __cdecl __mtold12(char *a1, int a2, int a3)
{
  unsigned int v4; // eax
  unsigned int v5; // kr00_4
  __int16 result; // ax
  __int16 v7; // [esp+Ch] [ebp-14h]
  unsigned int v8; // [esp+10h] [ebp-10h] BYREF
  int v9; // [esp+14h] [ebp-Ch]
  int v10; // [esp+18h] [ebp-8h]
  int v11; // [esp+1Ch] [ebp-4h]
  int v12; // [esp+30h] [ebp+10h]

  v11 = dword_912B08;
  v7 = 16462;
  *(_DWORD *)a3 = 0;
  *(_DWORD *)(a3 + 4) = 0;
  *(_DWORD *)(a3 + 8) = 0;
  if ( a2 )
  {
    v12 = a2;
    do
    {
      v8 = *(_DWORD *)a3;
      v9 = *(_DWORD *)(a3 + 4);
      v10 = *(_DWORD *)(a3 + 8);
      __shl_12((_DWORD *)a3);
      __shl_12((_DWORD *)a3);
      __add_12((unsigned int *)a3, &v8);
      __shl_12((_DWORD *)a3);
      v4 = *a1;
      v9 = 0;
      v10 = 0;
      v8 = v4;
      __add_12((unsigned int *)a3, &v8);
      ++a1;
      --v12;
    }
    while ( v12 );
  }
  if ( !*(_DWORD *)(a3 + 8) )
  {
    do
    {
      v7 -= 16;
      v5 = *(_DWORD *)(a3 + 4);
      *(_QWORD *)a3 <<= 16;
    }
    while ( is_mul_ok(0x10000u, v5) );
    *(_DWORD *)(a3 + 8) = (unsigned __int64)v5 >> 16;
  }
  while ( (*(_DWORD *)(a3 + 8) & 0x8000) == 0 )
  {
    __shl_12((_DWORD *)a3);
    --v7;
  }
  result = v7;
  *(_WORD *)(a3 + 10) = v7;
  return result;
}
