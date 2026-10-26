void __thiscall sub_498FB0(_DWORD *this)
{
  _DWORD *i; // esi
  _DWORD *j; // esi

  for ( i = (_DWORD *)this[19]; i; i = (_DWORD *)StructFieldAccessor(i) )
    (*(void (__thiscall **)(_DWORD *))(*i + 116))(i);
  for ( j = *(_DWORD **)(this[20] + 68); j; j = (_DWORD *)StructFieldAccessor(j) )
    (*(void (__thiscall **)(_DWORD *))(*j + 116))(j);
}
