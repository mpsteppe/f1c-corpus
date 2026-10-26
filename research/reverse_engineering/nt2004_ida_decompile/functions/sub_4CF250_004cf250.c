char __thiscall sub_4CF250(_WORD *this, char *String)
{
  unsigned __int16 v3; // cx
  unsigned __int16 v4; // ax
  bool v5; // cf
  unsigned __int16 v6; // dx

  if ( !String || !strlen(String) )
    return 0;
  sub_4BC080(String, &String);
  v3 = (unsigned __int16)String;
  v4 = this[12];
  v5 = (unsigned __int16)String < v4;
  v6 = this[13];
  this[10] = (_WORD)String;
  if ( v5 )
  {
    this[10] = v4;
    return 1;
  }
  else
  {
    if ( v3 > v6 )
      this[10] = v6;
    return 1;
  }
}
