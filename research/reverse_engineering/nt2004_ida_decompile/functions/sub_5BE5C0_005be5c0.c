char __fastcall sub_5BE5C0(int a1, unsigned int a2, int a3, unsigned __int8 a4, _BYTE *a5, _DWORD *a6)
{
  unsigned int v6; // eax
  unsigned int v7; // ebx
  int i; // ecx

  if ( a2 )
  {
    v7 = 1;
    for ( i = 0; v7 < a2; v7 = 2 * v7 + 1 )
      ;
    do
    {
      *a5 = *(_BYTE *)(*a6 + a3) + *(_BYTE *)((unsigned __int8)*a5 + a1);
      if ( ++*a6 >= (unsigned int)a4 )
      {
        *a6 = 0;
        *a5 += a4;
      }
      v6 = v7 & *a5;
      if ( (unsigned int)++i > 0xB )
        v6 %= a2;
    }
    while ( v6 > a2 );
  }
  else
  {
    LOBYTE(v6) = 0;
  }
  return v6;
}
