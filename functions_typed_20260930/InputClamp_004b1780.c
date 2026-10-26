int __thiscall sub_4B1780(_DWORD *this)
{
  int v1; // esi
  int result; // eax

  v1 = this[2658];
  if ( !StateCheckWrapper(dword_7CD25C) )
    return v1;
  if ( v1 < -1 )
    return -1;
  result = 1;
  if ( v1 <= 1 )
    return v1;
  return result;
}

