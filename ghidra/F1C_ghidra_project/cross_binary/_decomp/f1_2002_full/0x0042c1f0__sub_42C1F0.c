// f1_2002_full  0x0042c1f0  size=64
LPVOID **__thiscall sub_42C1F0(LPVOID **this, char a2)
{
  LPVOID *v3; // esi

  if ( *((_BYTE *)this + 8) )
  {
    v3 = *this;
    if ( *this )
    {
      if ( *v3 )
        sub_56BEF1(*v3);
      sub_56BEF1(v3);
    }
  }
  if ( (a2 & 1) != 0 )
    sub_56BEF1(this);
  return this;
}
