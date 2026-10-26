// f1c  0x00564c40  size=42
char __fastcall sub_564C40(unsigned __int8 a1)
{
  if ( a1 < 0x1Au )
    return a1 + 65;
  if ( a1 < 0x34u )
    return a1 + 71;
  if ( a1 < 0x3Eu )
    return a1 - 4;
  if ( a1 == 62 )
    return 43;
  return a1 != 63 ? 0 : 0x2F;
}
