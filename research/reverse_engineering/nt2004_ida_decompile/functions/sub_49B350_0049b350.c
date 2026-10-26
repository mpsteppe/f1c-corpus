LPVOID *__thiscall sub_49B350(LPVOID *this, char a2)
{
  LPVOID **v3; // esi
  LPVOID **v4; // ebp
  char v5; // al
  LPVOID *v6; // edi

  *this = &off_5E6010;
  if ( this[220] )
    sub_5BE8AE(this[220]);
  v3 = (LPVOID **)this[216];
  while ( v3 )
  {
    v4 = v3;
    v5 = *((_BYTE *)v3 + 12);
    v3 = (LPVOID **)v3[1];
    if ( v5 )
    {
      v6 = *v4;
      if ( *v4 )
      {
        if ( *v6 )
          sub_5BE8AE(*v6);
        sub_5BE8AE(v6);
      }
    }
    sub_5BE8AE(v4);
  }
  this[216] = 0;
  this[217] = 0;
  this[218] = 0;
  this[219] = 0;
  sub_4A2330(this);
  if ( (a2 & 1) != 0 )
    sub_5BE8AE(this);
  return this;
}
