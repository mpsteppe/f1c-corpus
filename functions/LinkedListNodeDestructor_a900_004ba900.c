LPVOID **__thiscall sub_4BA900(LPVOID **this, char a2)
{
  LPVOID *v3; // esi

  if ( *((_BYTE *)this + 12) )
  {
    v3 = *this;
    if ( *this )
    {
      if ( v3[1] )
        FreeWrapper_7bcf(v3[1]);
      FreeWrapper_7bcf(v3);
    }
  }
  if ( (a2 & 1) != 0 )
    FreeWrapper_7bcf(this);
  return this;
}
