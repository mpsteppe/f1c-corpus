char __thiscall std::string::_Freeze(_DWORD *this)
{
  int v2; // eax
  int v3; // esi

  v2 = this[1];
  if ( v2 )
  {
    LOBYTE(v2) = *(_BYTE *)(v2 - 1);
    if ( (_BYTE)v2 )
    {
      if ( (_BYTE)v2 != 0xFF )
        LOBYTE(v2) = std::string::_Grow(this[2], 0);
    }
  }
  v3 = this[1];
  if ( v3 )
    *(_BYTE *)(v3 - 1) = -1;
  return v2;
}
