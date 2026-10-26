unsigned int __cdecl _mbctoupper(unsigned int Ch)
{
  unsigned int v1; // ebx
  CHAR DestStr[4]; // [esp+4h] [ebp-4h] BYREF

  v1 = Ch;
  if ( Ch <= 0xFF )
  {
    if ( (byte_8002A1[Ch] & 0x20) == 0x20 )
      return (unsigned __int8)byte_8001A0[Ch];
  }
  else
  {
    BYTE2(Ch) = BYTE1(Ch);
    HIBYTE(Ch) = Ch;
    if ( (byte_8002A1[BYTE1(v1)] & 4) != 0
      && __crtLCMapStringA(dword_8003A4, 0x200u, (LPCSTR)&Ch + 2, 2, DestStr, 2, dword_800180, 1) )
    {
      return (unsigned __int8)DestStr[1] + ((unsigned __int8)DestStr[0] << 8);
    }
  }
  return v1;
}
