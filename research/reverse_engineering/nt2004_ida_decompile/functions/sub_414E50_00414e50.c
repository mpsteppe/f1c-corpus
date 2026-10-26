char __thiscall sub_414E50(_DWORD *this, char *String2)
{
  int v3; // ecx
  int v4; // eax

  v3 = this[29];
  if ( !v3 )
    return 0;
  this[28] = 0;
  *this = 1;
  sub_414620(v3);
  v4 = sub_57AE50(String2);
  this[28] = v4;
  if ( !v4 )
    return 0;
  *this = 2;
  if ( (unsigned __int8)sub_414F50(this) )
    return 1;
  *this = -1;
  return 0;
}
