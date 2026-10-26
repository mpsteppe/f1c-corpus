// f1c  0x00564740  size=51
int __thiscall sub_564740(LPVOID *lpMem)
{
  int i; // edi

  for ( i = 0; i < (int)lpMem[1]; ++i )
    sub_564860(*((LPVOID *)*lpMem + i));
  sub_58AA6F(*lpMem);
  return sub_58AA6F(lpMem);
}
