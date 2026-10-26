BOOL __thiscall sub_5A3C50(_BYTE *this, _BYTE *a2, bool *a3)
{
  bool v4; // al

  if ( a2 )
    *a2 = this[97];
  v4 = (*(int (__thiscall **)(_BYTE *))(*(_DWORD *)this + 164))(this) < *((_DWORD *)this + 25);
  if ( a3 )
    *a3 = v4;
  return this[97] && v4;
}
