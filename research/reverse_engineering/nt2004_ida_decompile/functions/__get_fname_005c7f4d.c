_UNKNOWN **__cdecl _get_fname(int a1)
{
  int v1; // ecx
  _DWORD *v2; // eax

  v1 = 0;
  v2 = &unk_6261A8;
  while ( *v2 != a1 )
  {
    v2 += 2;
    ++v1;
    if ( (int)v2 >= (int)&dbl_626280 )
      return 0;
  }
  return (&off_6261AC)[2 * v1];
}
