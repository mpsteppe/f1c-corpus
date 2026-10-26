// f1c  0x0040c720  size=94
char __thiscall sub_40C720(_DWORD *this, int a2)
{
  char result; // al

  result = 1;
  if ( *(_DWORD *)(dword_7C54F0[dword_7C54DC] + 18580) != *(_DWORD *)(dword_7C54F0[dword_7C54E4] + 18580) )
  {
    if ( !byte_7CFE88 && *(_BYTE *)(dword_7C54E0 + 13388) && a2 == 3 )
      return 0;
    else
      this[5] = -1;
  }
  return result;
}
