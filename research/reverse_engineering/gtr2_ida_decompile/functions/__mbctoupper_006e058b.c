unsigned int __cdecl _mbctoupper(unsigned int Ch)
{
  _DWORD *v1; // eax
  char *v3; // eax
  _BYTE v4[4]; // [esp+0h] [ebp-8h] BYREF
  _BYTE v5[4]; // [esp+4h] [ebp-4h] BYREF

  v1 = (_DWORD *)_getptd()[24];
  if ( v1 != dword_FBB260 )
    v1 = (_DWORD *)sub_640F4B();
  if ( Ch <= 0xFF )
  {
    v3 = (char *)v1 + Ch;
    if ( (v3[29] & 0x20) != 0 )
      return v3[285];
  }
  else
  {
    v5[0] = BYTE1(Ch);
    v5[1] = Ch;
    if ( (*((_BYTE *)v1 + BYTE1(Ch) + 29) & 4) != 0 && __crtLCMapStringA(v1[3], 512, v5, 2, v4, 2, v1[1], 1) )
      return v4[1] + (v4[0] << 8);
  }
  return Ch;
}
