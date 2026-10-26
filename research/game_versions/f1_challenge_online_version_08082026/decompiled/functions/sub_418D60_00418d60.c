LPVOID **__thiscall sub_418D60(LPVOID **this, char a2)
{
  LPVOID *v3; // esi

  if ( *((_BYTE *)this + 8) )
  {
    v3 = *this;
    if ( *this )
    {
      if ( *v3 )
        sub_587BCF(*v3);
      sub_587BCF(v3);
    }
  }
  if ( (a2 & 1) != 0 )
    sub_587BCF(this);
  return this;
}
