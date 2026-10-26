int __thiscall sub_4830E0(_DWORD *this, int a2)
{
  int v2; // eax
  int result; // eax

  if ( a2 == 1 )
    v2 = dword_769134 + 1;
  else
    v2 = dword_769134 - 1;
  if ( v2 >= this[212] )
  {
    if ( v2 > this[211] )
      v2 = this[212];
  }
  else
  {
    v2 = this[211];
  }
  dword_769134 = v2;
  if ( v2 >= dword_76913C )
  {
    if ( v2 > dword_769140 )
      dword_769134 = dword_769140;
  }
  else
  {
    dword_769134 = dword_76913C;
  }
  result = dword_7683BC;
  dword_7683B4 = 0;
  if ( dword_7683BC <= 0 )
  {
    if ( dword_7683C0 < 0 )
      dword_7683B4 = dword_7683C0;
  }
  else
  {
    dword_7683B4 = dword_7683BC;
  }
  return result;
}
