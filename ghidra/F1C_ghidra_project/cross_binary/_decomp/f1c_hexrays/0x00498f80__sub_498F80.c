// f1c  0x00498f80  size=46
void __thiscall sub_498F80(_DWORD *this)
{
  _DWORD *i; // esi
  _DWORD *j; // esi

  for ( i = (_DWORD *)this[19]; i; i = (_DWORD *)sub_486320(i) )
    (*(void (__thiscall **)(_DWORD *))(*i + 112))(i);
  for ( j = *(_DWORD **)(this[20] + 68); j; j = (_DWORD *)sub_486320(j) )
    (*(void (__thiscall **)(_DWORD *))(*j + 112))(j);
}
