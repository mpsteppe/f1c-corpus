void __thiscall sub_49CFB0(_DWORD *this, int a2)
{
  int v2; // edx
  int i; // eax

  v2 = this[63];
  if ( v2 )
  {
    for ( i = *(_DWORD *)(v2 + 24); i; i = *(_DWORD *)(i + 24) )
      v2 = i;
    *(_DWORD *)(v2 + 24) = a2;
  }
  else
  {
    this[63] = a2;
  }
}
