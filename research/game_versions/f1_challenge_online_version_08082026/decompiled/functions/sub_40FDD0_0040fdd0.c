_DWORD *__thiscall sub_40FDD0(_DWORD *this, char a2)
{
  int v3; // eax
  _DWORD *v4; // ebp
  _DWORD *v5; // esi
  int v6; // eax
  int v7; // edi

  if ( (a2 & 2) != 0 )
  {
    v3 = *(this - 1);
    v4 = this - 1;
    v5 = &this[198 * v3];
    v6 = v3 - 1;
    if ( v6 >= 0 )
    {
      v7 = v6 + 1;
      do
      {
        v5 -= 198;
        *v5 = &off_59E720;
        sub_568E60(v5 + 53);
        --v7;
      }
      while ( v7 );
    }
    if ( (a2 & 1) != 0 )
      sub_587BCF(v4);
    return v4;
  }
  else
  {
    *this = &off_59E720;
    sub_568E60(this + 53);
    if ( (a2 & 1) != 0 )
      sub_587BCF(this);
    return this;
  }
}
