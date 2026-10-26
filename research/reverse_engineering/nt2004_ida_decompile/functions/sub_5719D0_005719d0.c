int __thiscall sub_5719D0(int *this)
{
  int i; // esi
  _BYTE *v3; // edi
  int result; // eax

  for ( i = *this; i; result = sub_5BE8AE() )
  {
    v3 = (_BYTE *)i;
    i = *(_DWORD *)(i + 4);
    if ( v3[8] && *(_DWORD *)v3 )
      (*(void (__thiscall **)(_DWORD, int))(**(_DWORD **)v3 + 4))(*(_DWORD *)v3, 1);
  }
  *this = 0;
  this[1] = 0;
  this[2] = 0;
  this[3] = 0;
  return result;
}
