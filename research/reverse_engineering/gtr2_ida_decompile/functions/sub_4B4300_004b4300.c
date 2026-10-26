int __thiscall sub_4B4300(_DWORD *this)
{
  unsigned __int8 v1; // al
  char v2; // dl
  unsigned __int8 v3; // al
  char v4; // al

  if ( byte_B722CC )
  {
    v1 = byte_B70900 == 0;
    byte_B70900 = byte_B70900 == 0;
    if ( (unsigned __int8)byte_B70900 >= (unsigned __int8)byte_B70902 )
    {
      if ( v1 > (unsigned __int8)byte_B70903 )
        byte_B70900 = byte_B70903;
    }
    else
    {
      byte_B70900 = byte_B70902;
    }
  }
  else
  {
    v2 = byte_B7091A;
    v3 = byte_B70918 == 0;
    byte_B70918 = byte_B70918 == 0;
    if ( (unsigned __int8)byte_B70918 < (unsigned __int8)byte_B7091A
      || (v2 = byte_B7091B, v3 > (unsigned __int8)byte_B7091B) )
    {
      byte_B70918 = v2;
    }
  }
  this[67] = 1;
  v4 = byte_B70900;
  if ( !byte_B722CC )
    v4 = byte_B70918;
  if ( v4 )
    this[67] = 0;
  (*(void (__thiscall **)(_DWORD *, _DWORD))(*this + 44))(this, this[67]);
  return 0;
}
