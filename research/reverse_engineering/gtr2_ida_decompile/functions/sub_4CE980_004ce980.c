int __thiscall sub_4CE980(_DWORD *this)
{
  int v2; // eax
  double v4; // st7
  unsigned __int8 v6; // c0
  unsigned __int8 v7; // c2
  unsigned __int64 v8; // rax
  int v9; // edi

  v2 = this[33];
  if ( v2 == 5 || v2 == 4 )
  {
    if ( *((_BYTE *)this + 100) || !*((_BYTE *)this + 817) )
      return -1;
    v4 = sub_4DE460(this[12]) + *((float *)this + 209);
    *((float *)this + 209) = v4;
    if ( v6 | v7 )
      return 0;
    *((float *)this + 209) = v4 - 0.5 * (v4 - 0.75);
    v8 = (unsigned __int64)(v4 - 0.75 + v4 - 0.75);
    if ( (int)v8 > 1 )
    {
      if ( (int)v8 >= 5 )
        LODWORD(v8) = 5;
    }
    else
    {
      LODWORD(v8) = 1;
    }
    if ( this[33] )
    {
      v9 = v8;
      do
      {
        (*(void (__thiscall **)(_DWORD *, bool))(*this + 180))(this, this[33] == 5);
        --v9;
      }
      while ( v9 );
    }
  }
  return 0;
}
