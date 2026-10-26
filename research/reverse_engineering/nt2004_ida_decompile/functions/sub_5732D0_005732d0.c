int __thiscall sub_5732D0(int *this)
{
  int i; // esi
  int v3; // edi
  int result; // eax

  for ( i = *this; i; result = sub_5BE8AE() )
  {
    v3 = i;
    i = *(_DWORD *)(i + 4);
    if ( *(_BYTE *)(v3 + 8) && *(_DWORD *)v3 )
      (***(void (__thiscall ****)(_DWORD, int))v3)(*(_DWORD *)v3, 1);
  }
  *this = 0;
  this[1] = 0;
  this[2] = 0;
  this[3] = 0;
  return result;
}
