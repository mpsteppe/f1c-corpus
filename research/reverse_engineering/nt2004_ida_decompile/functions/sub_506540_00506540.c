void __thiscall sub_506540(_BYTE *this)
{
  int i; // esi

  if ( *(_DWORD *)this )
    sub_59ECC0(1, 1, 1, 0);
  if ( *((_DWORD *)this + 1) )
  {
    if ( this[8] )
    {
      if ( sub_5AD940() )
      {
        for ( i = sub_59EFF0(0); i; i = *(_DWORD *)(i + 16) )
          sub_5AD8A0(i);
      }
      else if ( *(_DWORD *)this )
      {
        sub_59ECC0(0, 0, 0, 0);
      }
    }
    else
    {
      sub_5AD860();
      this[8] = 1;
    }
  }
}
