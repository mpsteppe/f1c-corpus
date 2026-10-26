unsigned __int8 __cdecl sub_554F5E(jmp_buf Buf, unsigned __int8 *a2)
{
  unsigned __int8 v2; // al
  unsigned __int8 v3; // al
  unsigned __int8 v4; // al
  unsigned __int8 result; // al

  v2 = *a2;
  if ( *a2 < 0x29u
    || v2 > 0x7Au
    || v2 > 0x5Au && v2 < 0x61u
    || (v3 = a2[1], v3 < 0x29u)
    || v3 > 0x7Au
    || v3 > 0x5Au && v3 < 0x61u
    || (v4 = a2[2], v4 < 0x29u)
    || v4 > 0x7Au
    || v4 > 0x5Au && v4 < 0x61u
    || (result = a2[3], result < 0x29u)
    || result > 0x7Au
    || result > 0x5Au && result < 0x61u )
  {
    sub_54E82F(Buf, "invalid chunk type");
  }
  return result;
}
