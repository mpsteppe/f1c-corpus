char __thiscall sub_4BBFC0(_BYTE **this, int a2)
{
  char result; // al
  _BYTE *v4; // ecx
  int v5; // edx
  int v6; // [esp-4h] [ebp-8h]

  result = a2;
  if ( (_UNKNOWN *)(*(_DWORD *)a2 & 0xFC0000) == &unk_680000 )
  {
    if ( !this[12] )
    {
      v4 = this[13];
      this[12] = (_BYTE *)2;
      if ( !v4 )
        this[13] = (_BYTE *)*(char *)(a2 + 8);
      if ( (*this)[4189] )
      {
        v6 = *((_DWORD *)*this + 1045);
        (*this)[4189] = 0;
        sub_4E0ED0(v6);
      }
      return sub_42AF40(*this);
    }
  }
  else
  {
    if ( this[12] == (_BYTE *)2 )
      this[12] = 0;
    result = 1;
    if ( (*this)[4189] != 1 )
    {
      v5 = *((_DWORD *)*this + 1045);
      (*this)[4189] = 1;
      return sub_4E0ED0(v5);
    }
  }
  return result;
}
