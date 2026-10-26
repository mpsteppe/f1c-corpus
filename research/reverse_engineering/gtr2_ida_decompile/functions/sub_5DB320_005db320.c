void __thiscall sub_5DB320(unsigned int *this, int a2, int a3, int a4)
{
  _DWORD *v5; // eax
  unsigned int v6; // eax
  _DWORD *v7; // eax
  unsigned int v8; // eax

  if ( a4 == 1 )
  {
    v5 = (_DWORD *)this[157];
    this[159] = (unsigned int)v5;
    if ( v5 )
    {
      if ( *v5 )
      {
        this[159] = (unsigned int)v5;
        if ( *v5 )
        {
          do
          {
            sub_5DB320(a2, a3, 1);
            v6 = this[159];
            if ( !v6 )
              break;
            v7 = *(_DWORD **)(v6 + 4);
            this[159] = (unsigned int)v7;
            if ( !v7 )
              break;
          }
          while ( *v7 );
        }
      }
    }
  }
  if ( a2 == 1 )
  {
    v8 = *this & 0xFFFFFFFD;
  }
  else
  {
    if ( a2 )
      goto LABEL_14;
    v8 = *this | 6;
  }
  *this = v8;
LABEL_14:
  if ( a3 == 1 )
  {
    *this &= ~4u;
  }
  else if ( !a3 )
  {
    *this |= 4u;
  }
}
