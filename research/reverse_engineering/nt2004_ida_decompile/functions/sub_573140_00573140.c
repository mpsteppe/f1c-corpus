int __thiscall sub_573140(int *this)
{
  int i; // esi
  int v3; // edi
  int result; // eax

  for ( i = *this; i; result = sub_5BE8AE() )
  {
    v3 = i;
    i = *(_DWORD *)(i + 4);
    if ( *(_BYTE *)(v3 + 8) && *(_DWORD *)v3 )
      sub_5BE8AE();
  }
  *this = 0;
  this[1] = 0;
  this[2] = 0;
  this[3] = 0;
  return result;
}
