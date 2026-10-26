int __thiscall sub_4E0FF0(_DWORD *this)
{
  _DWORD *i; // esi
  int v3; // eax
  int v4; // edi

  for ( i = (_DWORD *)this[7]; i; i = (_DWORD *)i[35] )
    (*(void (__thiscall **)(_DWORD *))(*i + 156))(i);
  v3 = this[6];
  if ( v3 )
    (*(void (__stdcall **)(_DWORD, _DWORD))(*(_DWORD *)v3 + 28))(this[22], this[23]);
  v4 = this[6];
  if ( v4 )
  {
    sub_4E0EA0(v4);
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 36))(v4);
  }
  return 0;
}
