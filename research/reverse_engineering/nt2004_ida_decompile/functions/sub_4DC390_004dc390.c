void __thiscall sub_4DC390(_DWORD *this)
{
  int v2; // ecx

  if ( this[14] != 3 )
  {
    if ( (unsigned __int8)sub_4EED40(*this) && (unsigned __int8)sub_4DEB10(this) )
      sub_4DF490(0.0, 2);
    v2 = *this;
    this[14] = 1;
    if ( (unsigned __int8)sub_4EED40(v2) )
    {
      if ( *(_DWORD *)(*this + 16584) == 1 )
        sub_51F3D0(0, 4);
    }
  }
}
