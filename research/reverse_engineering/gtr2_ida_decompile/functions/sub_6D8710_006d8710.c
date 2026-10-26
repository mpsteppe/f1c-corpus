unsigned int __stdcall sub_6D8710(int a1, _BYTE **a2, _DWORD *a3, int a4, int a5)
{
  unsigned int v5; // edi
  unsigned int result; // eax
  int *v7; // edx
  _BYTE *v8; // ecx
  int v9; // esi
  int v10; // [esp+4h] [ebp-4h]
  int v11; // [esp+10h] [ebp+8h]

  v5 = *(_DWORD *)(a1 + 28);
  v10 = *(_DWORD *)(a1 + 36);
  result = a5 - 1;
  if ( a5 - 1 >= 0 )
  {
    v7 = (int *)(*a3 + 4 * a4);
    v11 = a5;
    do
    {
      v8 = *a2;
      v9 = *v7;
      ++a2;
      ++v7;
      for ( result = 0; result < v5; ++result )
      {
        *(_BYTE *)(result + v9) = *v8;
        v8 += v10;
      }
      --v11;
    }
    while ( v11 );
  }
  return result;
}
