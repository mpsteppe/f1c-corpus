char __thiscall sub_4CEED0(_BYTE *this, const char *a2)
{
  unsigned __int8 v3; // cl
  unsigned __int8 v4; // al
  bool v5; // cf
  unsigned __int8 v6; // dl

  if ( !a2 || !strlen(a2) )
    return 0;
  sub_4BC0A0(a2, (bool *)&a2);
  v3 = (unsigned __int8)a2;
  v4 = this[22];
  v5 = (unsigned __int8)a2 < v4;
  v6 = this[23];
  this[20] = (_BYTE)a2;
  if ( v5 )
  {
    this[20] = v4;
    return 1;
  }
  else
  {
    if ( v3 > v6 )
      this[20] = v6;
    return 1;
  }
}
