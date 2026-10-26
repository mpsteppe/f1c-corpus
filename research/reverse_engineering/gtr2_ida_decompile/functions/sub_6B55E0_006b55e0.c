int __stdcall sub_6B55E0(int *a1, unsigned int a2, int a3, signed int a4)
{
  signed int v4; // edi
  int v5; // eax
  int result; // eax
  unsigned int v7; // esi
  _DWORD *v8; // eax
  signed int v9; // ecx
  int v10; // [esp+Ch] [ebp-4h]
  int v11; // [esp+Ch] [ebp-4h]

  v10 = a1[1];
  v4 = 0x3B9AC9F0u / (a3 << 7);
  if ( v4 <= 0 )
  {
    v5 = *a1;
    *(_DWORD *)(v5 + 20) = 70;
    (*(void (__stdcall **)(int *))v5)(a1);
  }
  if ( v4 >= a4 )
    v4 = a4;
  *(_DWORD *)(v10 + 80) = v4;
  result = sub_6B5340(a1, a2, 4 * a4);
  v7 = 0;
  v11 = result;
  if ( a4 )
  {
    do
    {
      if ( v4 >= a4 - v7 )
        v4 = a4 - v7;
      v8 = sub_6B5480(a1, a2, (a3 * v4) << 7);
      if ( v4 )
      {
        v9 = v4;
        do
        {
          *(_DWORD *)(v11 + 4 * v7++) = v8;
          v8 += 32 * a3;
          --v9;
        }
        while ( v9 );
      }
    }
    while ( v7 < a4 );
    return v11;
  }
  return result;
}
