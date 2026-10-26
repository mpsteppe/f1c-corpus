int __cdecl sub_58C9B4(int a1, LPVOID lpBuffer, DWORD nNumberOfBytesToRead)
{
  int v3; // edi

  if ( a1 < uNumber && (*(_BYTE *)(dword_8D4920[a1 >> 5] + 36 * (a1 & 0x1F) + 4) & 1) != 0 )
  {
    sub_595A61(a1);
    v3 = sub_58CA19(a1, lpBuffer, nNumberOfBytesToRead);
    sub_595AC0(a1);
    return v3;
  }
  else
  {
    *(_DWORD *)sub_58AFCF() = 9;
    *(_DWORD *)sub_58AFD8() = 0;
    return -1;
  }
}
