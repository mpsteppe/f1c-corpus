int __thiscall sub_564860(LPVOID *lpMem)
{
  int i; // edi

  for ( i = 0; i < (int)*lpMem; ++i )
    sub_564890(lpMem, i);
  sub_58AA6F(lpMem[5]);
  return sub_58AA6F(lpMem);
}
