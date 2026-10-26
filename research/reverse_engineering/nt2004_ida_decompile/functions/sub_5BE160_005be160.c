int __thiscall sub_5BE160(LPVOID *lpMem)
{
  int i; // edi

  for ( i = 0; i < (int)*lpMem; ++i )
    sub_5BE190(lpMem, i);
  sub_5C1B88(lpMem[5]);
  return sub_5C1B88(lpMem);
}
