int __thiscall sub_541090(int *this, int a2, int a3, int a4, int a5)
{
  int v6; // ecx
  int v7; // eax
  int v8; // eax
  int v10; // [esp+14h] [ebp-4h] BYREF

  v6 = 2048;
  v10 = 0;
  if ( a2 )
  {
    v7 = *(_DWORD *)(a2 + 24);
    if ( v7 )
    {
      if ( (*(_BYTE *)a2 & 1) != 0 )
        v6 = 2064;
      v8 = (*(int (__stdcall **)(int, int, int, int *, int))(*(_DWORD *)v7 + 44))(v7, 2 * a4, 2 * a5, &v10, v6);
      *this = v8;
      if ( v8 )
        return 0;
      ++*(_DWORD *)(a2 + 12);
    }
  }
  return v10;
}
