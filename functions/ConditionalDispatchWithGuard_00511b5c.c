int __cdecl sub_511B5C(int a1, int a2)
{
  if ( (*(_BYTE *)(a1 + 92) & 0x40) == 0 )
    AudioBufferSizeCalc(a1);
  return PacketFieldEncoding(a1, a2);
}
