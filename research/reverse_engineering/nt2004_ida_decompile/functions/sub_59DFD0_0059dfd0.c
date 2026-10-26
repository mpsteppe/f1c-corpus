void __thiscall sub_59DFD0(_DWORD *this, int a2, int a3, int a4)
{
  int v6; // eax
  int i; // eax

  while ( 1 )
  {
    this[15] &= ~a2;
    if ( a3 )
    {
      v6 = this[129];
      if ( v6 )
      {
        *(_DWORD *)(v6 + 20) &= ~a3;
        for ( i = *(_DWORD *)(this[129] + 16); i; i = *(_DWORD *)(i + 16) )
          *(_DWORD *)(i + 20) &= ~a3;
      }
    }
    if ( this[17] )
      sub_59DFD0(a2, a3, 1);
    if ( !a4 )
      break;
    this = (_DWORD *)this[19];
    if ( !this )
      break;
    a4 = 1;
  }
}
