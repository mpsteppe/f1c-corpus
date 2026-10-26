int __thiscall sub_6A0C81(_DWORD *this, _DWORD *a2, int a3, int a4, _DWORD *a5)
{
  if ( (*(int (__thiscall **)(_DWORD *, _DWORD))(*this + 84))(this, *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *a2) + 108)) != 17 )
    return sub_6C6121(a2, a3, a4, a5);
  *a5 = &unk_E40000;
  return 0;
}
