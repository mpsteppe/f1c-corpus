int __cdecl sub_595A1F(int a1)
{
  _BYTE *v1; // eax

  if ( a1 < uNumber )
  {
    v1 = (_BYTE *)(dword_8D4920[a1 >> 5] + 36 * (a1 & 0x1F));
    if ( (v1[4] & 1) != 0 )
      return *(_DWORD *)v1;
  }
  *(_DWORD *)TLSOffsetGetter() = 9;
  *(_DWORD *)TLSOffsetGetter_afd8() = 0;
  return -1;
}

