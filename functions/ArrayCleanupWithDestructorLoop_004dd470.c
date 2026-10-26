int __thiscall sub_4DD470(int this)
{
  int result; // eax
  int v3; // ecx
  int v4; // eax
  void *v5; // ebx
  int v6; // edx
  int v7; // eax
  int v8; // esi
  int v9; // edi

  result = *(_DWORD *)(this + 8);
  if ( result )
    result = FreeWrapper_7bcf(*(LPVOID *)(this + 8));
  v3 = *(_DWORD *)(this + 16);
  if ( v3 )
  {
    v4 = *(_DWORD *)(v3 - 4);
    v5 = (void *)(v3 - 4);
    v6 = 3 * v4;
    v7 = v4 - 1;
    v8 = v3 + 8 * v6;
    if ( v7 >= 0 )
    {
      v9 = v7 + 1;
      do
      {
        v8 -= 24;
        ShortComputation_d4d0(v8);
        --v9;
      }
      while ( v9 );
    }
    return FreeWrapper_7bcf(v5);
  }
  return result;
}
