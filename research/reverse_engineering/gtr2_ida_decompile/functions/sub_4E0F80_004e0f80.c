int __thiscall sub_4E0F80(_DWORD *this)
{
  _DWORD *v2; // ecx
  _DWORD *v3; // esi

  v2 = (_DWORD *)this[17];
  v3 = (_DWORD *)this[16];
  if ( v2 )
    sub_4E0CD0(v2);
  for ( ; v3; v3 = (_DWORD *)v3[35] )
    (*(void (__thiscall **)(_DWORD *))(*v3 + 156))(v3);
  return 0;
}
