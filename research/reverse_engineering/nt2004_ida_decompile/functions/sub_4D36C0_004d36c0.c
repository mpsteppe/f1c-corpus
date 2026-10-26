char __stdcall sub_4D36C0(int a1, int a2)
{
  bool v2; // zf
  char result; // al

  if ( a1 )
    return 0;
  if ( (*(_BYTE *)(a2 + 2) & 0x3F) != 0 )
    return 0;
  if ( (*(_DWORD *)a2 & 0x3Fu) >= 0x31 )
    return 0;
  v2 = sub_4D37A0(0, *(_DWORD *)a2 & 0x3F, &a1) == 0;
  result = 1;
  if ( v2 )
    return 0;
  return result;
}
