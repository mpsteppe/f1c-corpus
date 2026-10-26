int __cdecl sub_58F8C0(int a1)
{
  int *v1; // esi
  int v2; // ebp
  bool v3; // sf
  int v4; // ebx
  int v5; // edi

  v1 = &dword_7FFAB4[24 * a1];
  v2 = sub_58E570(v1);
  v3 = v2 < 0;
  if ( !v2 )
  {
    if ( !dword_7FFA10 )
      return v2;
    v4 = 0;
    while ( 1 )
    {
      v5 = dword_7FFA10(v4, v1);
      if ( v5 >= 0 )
        v2 = sub_58E570(v1);
      ++v4;
      v3 = v2 < 0;
      if ( v2 )
        break;
      if ( v5 <= 0 )
        return v2;
    }
  }
  if ( !v3 )
    return v2;
  return 0;
}
