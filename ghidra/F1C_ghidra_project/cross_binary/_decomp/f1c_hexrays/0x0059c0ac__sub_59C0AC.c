// f1c  0x0059c0ac  size=123
unsigned int __cdecl sub_59C0AC(unsigned int SrcStr)
{
  unsigned int v1; // ebx
  CHAR DestStr[4]; // [esp+4h] [ebp-4h] BYREF

  v1 = SrcStr;
  if ( SrcStr <= 0xFF )
  {
    if ( (byte_8D47E1[SrcStr] & 0x20) == 0x20 )
      return (unsigned __int8)byte_8D46E0[SrcStr];
  }
  else
  {
    BYTE2(SrcStr) = BYTE1(SrcStr);
    HIBYTE(SrcStr) = SrcStr;
    if ( (byte_8D47E1[BYTE1(v1)] & 4) != 0
      && sub_591FA1(dword_8D48E4, 0x200u, (LPCSTR)&SrcStr + 2, 2, DestStr, 2, dword_8D46BC, 1) )
    {
      return (unsigned __int8)DestStr[1] + ((unsigned __int8)DestStr[0] << 8);
    }
  }
  return v1;
}
