int __cdecl __dtold(int a1, int *a2)
{
  unsigned __int16 v3; // ax
  int v4; // ecx
  int v5; // eax
  unsigned int v6; // edx
  int v7; // eax
  __int16 v8; // di
  int result; // eax
  int v10; // ecx
  int v11; // edx
  int v12; // ecx
  unsigned int v13; // [esp+Ch] [ebp-4h]
  __int16 v14; // [esp+1Ch] [ebp+Ch]

  v3 = *((_WORD *)a2 + 3);
  v13 = 0x80000000;
  v4 = (v3 >> 4) & 0x7FF;
  v14 = v3 & 0x8000;
  v5 = a2[1];
  v6 = *a2;
  v7 = v5 & 0xFFFFF;
  if ( (_WORD)v4 )
  {
    if ( (unsigned __int16)v4 == 2047 )
      v8 = 0x7FFF;
    else
      v8 = v4 + 15360;
  }
  else
  {
    if ( !v7 && !v6 )
    {
      result = a1;
      *(_DWORD *)(a1 + 4) = 0;
      *(_DWORD *)a1 = 0;
      *(_WORD *)(a1 + 8) = 0;
      return result;
    }
    v8 = v4 + 15361;
    v13 = 0;
  }
  v10 = v13 | (v7 << 11) | (v6 >> 21);
  result = a1;
  *(_DWORD *)(a1 + 4) = v10;
  *(_DWORD *)a1 = v6 << 11;
  if ( (v10 & 0x80000000) == 0 )
  {
    do
    {
      v11 = *(__int64 *)a1 >> 31;
      v12 = 2 * *(_DWORD *)a1;
      --v8;
      *(_DWORD *)(a1 + 4) = v11;
      *(_DWORD *)a1 = v12;
    }
    while ( (v11 & 0x80000000) == 0 );
  }
  *(_WORD *)(a1 + 8) = v8 | v14;
  return result;
}
