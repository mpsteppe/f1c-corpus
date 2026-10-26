unsigned __int8 __cdecl sub_517FD0(int a1, unsigned __int8 *a2)
{
  unsigned __int8 v2; // al
  unsigned __int8 v3; // al
  unsigned __int8 v4; // al
  unsigned __int8 result; // al

  v2 = *a2;
  if ( *a2 < 0x29u || v2 > 0x7Au || v2 > 0x5Au && v2 < 0x61u )
    return DoubleBufferInit(a1, "invalid chunk type");
  v3 = a2[1];
  if ( v3 < 0x29u || v3 > 0x7Au || v3 > 0x5Au && v3 < 0x61u )
    return DoubleBufferInit(a1, "invalid chunk type");
  v4 = a2[2];
  if ( v4 < 0x29u || v4 > 0x7Au || v4 > 0x5Au && v4 < 0x61u )
    return DoubleBufferInit(a1, "invalid chunk type");
  result = a2[3];
  if ( result < 0x29u || result > 0x7Au || result > 0x5Au && result < 0x61u )
    return DoubleBufferInit(a1, "invalid chunk type");
  return result;
}

