int __thiscall sub_4F7D60(_DWORD *this, int a2)
{
  int v2; // edx
  int v3; // ecx
  int v4; // eax

  v2 = sub_4F7D30(this, a2) - 1;
  if ( v2 < 0 )
    return -2;
  while ( 1 )
  {
    v4 = 6326 * *(_DWORD *)(v3 + 8 * v2);
    if ( byte_6311E9[v4 * 4] )
    {
      if ( dword_630030[v4] != 2 || fabs(*((float *)&unk_632230 + 6326 * *(_DWORD *)(v3 + 8 * v2)) - dbl_7DA9D0) < 3.0 )
        break;
    }
    if ( --v2 < 0 )
      return -2;
  }
  if ( v2 < 0 )
    return -2;
  else
    return *(_DWORD *)(v3 + 8 * v2);
}
