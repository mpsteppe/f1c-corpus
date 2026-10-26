void __thiscall sub_6178E0(char *this)
{
  char *v1; // edx
  char v2; // al
  char *v4; // esi

  if ( this )
  {
    v1 = this;
    if ( *this )
    {
      do
      {
        v2 = *v1;
        if ( *v1 >= 46 && (v2 <= 47 || v2 == 92) )
          *v1 = 95;
      }
      while ( *++v1 );
    }
    v4 = this;
    if ( *this )
    {
      do
      {
        if ( sub_617750((int)v4) )
          *v4 = 45;
      }
      while ( *++v4 );
    }
  }
}
