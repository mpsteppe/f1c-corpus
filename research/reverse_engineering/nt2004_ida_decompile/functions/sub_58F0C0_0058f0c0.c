BOOL __cdecl sub_58F0C0(int a1, int a2)
{
  int v2; // ecx

  v2 = *(_BYTE *)(a1 + 4) & 3;
  if ( v2 == 1 )
    return a2 == 2;
  if ( v2 == 2 )
    return a2 != 2;
  return v2 == 0;
}
