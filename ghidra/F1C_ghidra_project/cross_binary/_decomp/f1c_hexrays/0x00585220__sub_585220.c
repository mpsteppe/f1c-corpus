// f1c  0x00585220  size=69
BOOL __thiscall sub_585220(_BYTE *this, _BYTE *a2, bool *a3)
{
  bool v4; // al

  if ( a2 )
    *a2 = this[93];
  v4 = (*(int (__thiscall **)(_BYTE *))(*(_DWORD *)this + 164))(this) < *((_DWORD *)this + 24);
  if ( a3 )
    *a3 = v4;
  return this[93] && v4;
}
