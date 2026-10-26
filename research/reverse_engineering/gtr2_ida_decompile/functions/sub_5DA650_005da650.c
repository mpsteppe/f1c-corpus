char __thiscall sub_5DA650(_DWORD *this, int a2)
{
  if ( this[1] )
  {
    if ( (dword_FB2750 & this[1] & *(_DWORD *)(a2 + 144)) != this[1] )
      return 0;
  }
  else if ( byte_FB2764 )
  {
    return 0;
  }
  return 1;
}
