void __thiscall sub_486660(_BYTE *this, int a2)
{
  _DWORD *i; // esi

  if ( (_BYTE)a2 != this[100] )
    (*(void (__thiscall **)(_BYTE *, int))(*(_DWORD *)this + 44))(this, 1);
  this[100] = a2;
  for ( i = (_DWORD *)*((_DWORD *)this + 36); i; i = (_DWORD *)StructFieldAccessor(i) )
    (*(void (__thiscall **)(_DWORD *, int))(*i + 56))(i, a2);
}
