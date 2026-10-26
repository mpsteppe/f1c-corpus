int __stdcall sub_6C656F(int a1, int a2, __int16 a3, int a4, const char *ArgList, int a6)
{
  int v6; // eax
  int v7; // eax
  int v8; // ecx
  int v10[8]; // [esp+4h] [ebp-20h] BYREF

  v6 = a2;
  if ( a2 == -1 )
  {
    v7 = *(_DWORD *)(a6 + 256);
    if ( !v7
      || (v8 = *(_DWORD *)(v7 + 60)) == 0
      || *(_DWORD *)(v8 + 4) != 13
      || (v6 = *(_DWORD *)(*(_DWORD *)(v7 + 60) + 68), a1 = *(_DWORD *)(v8 + 64), v6 == -1) )
    {
      v6 = 0;
    }
  }
  v10[5] = v6;
  v10[4] = a1;
  if ( a3 == 2 || a3 == 6 )
  {
    sub_65DD1F(*(_DWORD **)(a6 + 196), (int)v10, a4 + 5000, "%s", ArgList);
    *(_DWORD *)(a6 + 212) = 1;
  }
  return 0;
}
