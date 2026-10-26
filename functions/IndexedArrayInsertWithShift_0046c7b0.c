char __stdcall IndexedArrayInsertWithShift(char a1, int a2, int a3)
{
  int *v3; // edx
  int v4; // ecx
  int i; // eax
  int v6; // eax
  int v8; // esi
  int v9; // eax
  int v10; // ecx

  v3 = &dword_7CD2B8;
  if ( !a1 )
    v3 = &dword_7CD470;
  v4 = 0;
  for ( i = 0; i < 104; ++i )
  {
    if ( v3[i] == -1 )
      break;
    ++v4;
  }
  v6 = a3;
  if ( a3 < 0 )
  {
    v3[v4] = a2;
    return 1;
  }
  if ( a3 > v4 )
    v6 = v4;
  v8 = v3[v6];
  v3[v6] = a2;
  v9 = v6 + 1;
  if ( v9 < 104 )
  {
    while ( 1 )
    {
      v10 = v3[v9];
      v3[v9] = v8;
      if ( v10 == -1 )
        break;
      ++v9;
      v8 = v10;
      if ( v9 >= 104 )
        return 0;
    }
    return 1;
  }
  return 0;
}
