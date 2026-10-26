// f1c  0x00595f11  size=113
int __cdecl sub_595F11(int a1, int a2, int a3, DWORD dwMoveMethod)
{
  int v4; // edi

  if ( a1 < uNumber && (*(_BYTE *)(dword_8D4920[a1 >> 5] + 36 * (a1 & 0x1F) + 4) & 1) != 0 )
  {
    sub_595A61(a1);
    v4 = sub_595F82(a1, a2, a3, dwMoveMethod);
    sub_595AC0(a1);
    return v4;
  }
  else
  {
    *(_DWORD *)sub_58AFCF() = 9;
    *(_DWORD *)sub_58AFD8() = 0;
    return -1;
  }
}
