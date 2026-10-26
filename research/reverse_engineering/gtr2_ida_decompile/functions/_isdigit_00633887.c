int __cdecl isdigit(int C)
{
  int *v1; // eax

  v1 = *(int **)(_getptd() + 100);
  if ( v1 != off_91290C )
    v1 = (int *)__updatetlocinfo();
  if ( v1[10] <= 1 )
    return *(_BYTE *)(v1[18] + 2 * C) & 4;
  else
    return __isctype_mt(v1, C, 4);
}
