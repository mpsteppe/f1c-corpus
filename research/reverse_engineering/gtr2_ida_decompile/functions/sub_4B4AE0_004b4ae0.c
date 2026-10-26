int __thiscall sub_4B4AE0(int *this)
{
  bool *v2; // eax
  unsigned __int8 v3; // al
  char v4; // cl
  char v5; // cl
  char v6; // cl

  if ( this[70] && !(unsigned __int8)sub_4CD650(this) )
  {
    v2 = (bool *)this[70];
    if ( v2 )
      *v2 = !*v2;
    if ( this[69] == 766 )
    {
      v3 = *(_BYTE *)this[70];
      v4 = byte_B70776;
      byte_B70774 = v3;
      if ( v3 < (unsigned __int8)byte_B70776 || (v4 = byte_B70777, v3 > (unsigned __int8)byte_B70777) )
        byte_B70774 = v4;
      v5 = byte_B707A6;
      byte_B707A4 = *(_BYTE *)this[70];
      if ( (unsigned __int8)byte_B707A4 < (unsigned __int8)byte_B707A6
        || (v5 = byte_B707A7, (unsigned __int8)byte_B707A4 > (unsigned __int8)byte_B707A7) )
      {
        byte_B707A4 = v5;
      }
      v6 = byte_B70806;
      byte_B70804 = *(_BYTE *)this[70];
      if ( (unsigned __int8)byte_B70804 < (unsigned __int8)byte_B70806
        || (v6 = byte_B70807, (unsigned __int8)byte_B70804 > (unsigned __int8)byte_B70807) )
      {
        byte_B70804 = v6;
      }
    }
    sub_4A7340(this);
  }
  return 0;
}
