// f1c  0x004ba900  size=65
LPVOID **__thiscall sub_4BA900(LPVOID **this, char a2)
{
  LPVOID *v3; // esi

  if ( *((_BYTE *)this + 12) )
  {
    v3 = *this;
    if ( *this )
    {
      if ( v3[1] )
        sub_587BCF(v3[1]);
      sub_587BCF(v3);
    }
  }
  if ( (a2 & 1) != 0 )
    sub_587BCF(this);
  return this;
}
