int __thiscall sub_581880(int *this)
{
  int i; // esi
  _BYTE *v3; // edi
  int result; // eax

  for ( i = *this; i; result = FreeWrapper_7bcf(v3) )
  {
    v3 = (_BYTE *)i;
    i = *(_DWORD *)(i + 4);
    if ( v3[8] && *(_DWORD *)v3 )
      (***(void (__thiscall ****)(_DWORD, int))v3)(*(_DWORD *)v3, 1);
  }
  *this = 0;
  this[1] = 0;
  this[2] = 0;
  this[3] = 0;
  return result;
}

