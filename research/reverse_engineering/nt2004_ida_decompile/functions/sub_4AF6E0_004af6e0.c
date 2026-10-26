int __thiscall sub_4AF6E0(_DWORD *this)
{
  _DWORD *i; // esi
  _DWORD *j; // esi

  for ( i = this; sub_4AF450(i); i = (_DWORD *)sub_4AF450(i) )
    ;
  for ( j = (_DWORD *)i[13]; j; j = (_DWORD *)j[35] )
    (*(void (__thiscall **)(_DWORD *))(*j + 156))(j);
  return 0;
}
