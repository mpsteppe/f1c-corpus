int __cdecl sub_596007(int a1)
{
  if ( a1 < uNumber )
    return *(_BYTE *)(dword_8D4920[a1 >> 5] + 36 * (a1 & 0x1F) + 4) & 0x40;
  else
    return 0;
}

