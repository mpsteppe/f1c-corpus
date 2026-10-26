int __cdecl sub_58C331(int a1)
{
  int v1; // edi

  if ( a1 < uNumber && (*(_BYTE *)(dword_8D4920[a1 >> 5] + 36 * (a1 & 0x1F) + 4) & 1) != 0 )
  {
    sub_595A61(a1);
    v1 = sub_58C38E(a1);
    sub_595AC0(a1);
    return v1;
  }
  else
  {
    *(_DWORD *)sub_58AFCF() = 9;
    *(_DWORD *)sub_58AFD8() = 0;
    return -1;
  }
}
