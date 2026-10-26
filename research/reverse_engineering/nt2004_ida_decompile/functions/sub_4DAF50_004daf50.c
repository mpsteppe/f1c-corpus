LPVOID **__thiscall sub_4DAF50(LPVOID **this, char a2)
{
  LPVOID *v3; // esi

  if ( *((_BYTE *)this + 12) )
  {
    v3 = *this;
    if ( *this )
    {
      if ( v3[1] )
        sub_5BE8AE(v3[1]);
      sub_5BE8AE(v3);
    }
  }
  if ( (a2 & 1) != 0 )
    sub_5BE8AE(this);
  return this;
}
