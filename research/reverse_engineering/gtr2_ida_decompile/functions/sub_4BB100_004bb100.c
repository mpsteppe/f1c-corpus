int __thiscall sub_4BB100(_DWORD **this)
{
  int v2; // edi
  int v3; // esi

  v2 = (*(int (__thiscall **)(_DWORD *, int))(*this[12] + 28))(this[12], 42);
  v3 = (*(int (__thiscall **)(_DWORD *, int))(*this[12] + 28))(this[12], 44);
  if ( v2 )
    sub_4B8110();
  if ( v3 )
    sub_4B8110();
  return 0;
}
