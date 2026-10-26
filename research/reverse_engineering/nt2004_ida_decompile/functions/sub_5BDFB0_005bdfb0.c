int __thiscall sub_5BDFB0(LPVOID *lpMem)
{
  int i; // edi

  for ( i = 0; i < (int)lpMem[1]; ++i )
    sub_5BE160(*((LPVOID *)*lpMem + i));
  sub_5C1B88(*lpMem);
  return sub_5C1B88(lpMem);
}
