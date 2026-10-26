char __thiscall sub_52BE90(_DWORD *this, int a2)
{
  char result; // al
  int v4; // ecx
  int v5; // ecx
  int v6; // [esp-8h] [ebp-Ch]
  int v7; // [esp-8h] [ebp-Ch]

  result = a2;
  if ( (_UNKNOWN *)(*(_DWORD *)a2 & 0xFC0000) == &loc_600000 )
  {
    if ( !this[27] )
    {
      v4 = this[28];
      this[27] = 2;
      if ( !v4 )
        this[28] = *(char *)(a2 + 8);
      if ( *(_BYTE *)(*this + 5754) )
      {
        v6 = *(_DWORD *)(*this + 5744);
        *(_BYTE *)(*this + 5754) = 0;
        sub_56AE80(v6, 1);
      }
      result = sub_422830();
    }
    if ( (dword_B640C4 & 1) != 0 )
      return sub_54F160(&byte_FADF20, *this);
  }
  else
  {
    if ( this[27] == 2 )
      this[27] = 0;
    result = *(_BYTE *)(*this + 5754);
    v5 = *this + 2704;
    if ( result != 1 )
    {
      v7 = *(_DWORD *)(*this + 5744);
      *(_BYTE *)(v5 + 3050) = 1;
      return sub_56AE80(v7, 1);
    }
  }
  return result;
}
