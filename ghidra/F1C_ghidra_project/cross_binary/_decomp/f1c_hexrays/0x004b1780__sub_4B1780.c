// f1c  0x004b1780  size=45
int __thiscall sub_4B1780(_DWORD *this)
{
  int v1; // esi
  int result; // eax

  v1 = this[2658];
  if ( !sub_461DC0(dword_7CD25C) )
    return v1;
  if ( v1 < -1 )
    return -1;
  result = 1;
  if ( v1 <= 1 )
    return v1;
  return result;
}
