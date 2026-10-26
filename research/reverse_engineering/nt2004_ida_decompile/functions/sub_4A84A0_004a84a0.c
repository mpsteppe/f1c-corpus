int __thiscall sub_4A84A0(_DWORD *this)
{
  int v2; // eax

  if ( !sub_57A490(Str, 256) )
    return 0;
  while ( 1 )
  {
    ++this[117];
    v2 = sub_577B60(byte_7656E8);
    if ( v2 != 1 && (v2 <= 2 || v2 > 4) )
      break;
    ++this[118];
    if ( !sub_57A490(Str, 256) )
      return 0;
  }
  return 1;
}
