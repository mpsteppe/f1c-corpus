int __cdecl sub_58A55A(int a1, int a2, int a3, unsigned int *a4, unsigned int *a5)
{
  unsigned int v6; // esi
  int v7; // ebx
  unsigned int v8; // eax
  unsigned int v9; // esi
  unsigned int v11; // [esp+Ch] [ebp-4h]
  unsigned int v12; // [esp+18h] [ebp+8h]

  v6 = *(_DWORD *)(a1 + 12);
  v7 = *(_DWORD *)(a1 + 16);
  v8 = v6;
  v12 = v6;
  v11 = v6;
  if ( a2 >= 0 )
  {
    do
    {
      if ( v6 == -1 )
        SEHGuardedFunctionPointerCall();
      --v6;
      if ( *(_DWORD *)(v7 + 20 * v6 + 4) < a3 && a3 <= *(_DWORD *)(v7 + 20 * v6 + 8) || v6 == -1 )
      {
        --a2;
        v11 = v12;
        v12 = v6;
      }
    }
    while ( a2 >= 0 );
    v8 = v11;
  }
  v9 = v6 + 1;
  *a4 = v9;
  *a5 = v8;
  if ( v8 > *(_DWORD *)(a1 + 12) || v9 > v8 )
    SEHGuardedFunctionPointerCall();
  return v7 + 20 * v9;
}
