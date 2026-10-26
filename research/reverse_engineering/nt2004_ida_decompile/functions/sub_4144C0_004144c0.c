LPVOID **__thiscall sub_4144C0(LPVOID **this, char a2)
{
  LPVOID *v3; // esi

  if ( *((_BYTE *)this + 8) )
  {
    v3 = *this;
    if ( *this )
    {
      if ( v3[2] )
        sub_5BE8AE(v3[2]);
      sub_5BE8AE(v3);
    }
  }
  if ( (a2 & 1) != 0 )
    sub_5BE8AE(this);
  return this;
}
