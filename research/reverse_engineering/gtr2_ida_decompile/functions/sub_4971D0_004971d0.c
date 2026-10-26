int __thiscall sub_4971D0(_DWORD **this)
{
  int v2; // eax
  bool v4; // [esp+4h] [ebp-4h]

  v4 = 1;
  v2 = (*(int (__thiscall **)(_DWORD *, _DWORD *))(*this[12] + 28))(this[12], this[70]);
  if ( v2 )
    v4 = sub_4CE170(v2) == 0;
  ((void (__thiscall *)(_DWORD **, bool))(*this)[9])(this, v4);
  return 0;
}
