_UNKNOWN **__cdecl sub_591CA1(int a1)
{
  int v1; // ecx
  _DWORD *v2; // eax

  v1 = 0;
  v2 = &unk_5E7640;
  while ( *v2 != a1 )
  {
    v2 += 2;
    ++v1;
    if ( (int)v2 >= (int)&dbl_5E7718 )
      return 0;
  }
  return (&off_5E7644)[2 * v1];
}

