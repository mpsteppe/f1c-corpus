int __thiscall sub_4A2630(_BYTE *this)
{
  _DWORD *v3; // ecx

  if ( sub_49D1D0(this) )
    return -1;
  if ( sub_49D1E0(this) == 4 || sub_49D1E0(v3) == 3 )
    (*(void (__thiscall **)(_BYTE *, int))(*(_DWORD *)this + 44))(this, 1);
  else
    (*(void (__stdcall **)(int))(*(_DWORD *)this + 44))(2);
  if ( !(*(int (__thiscall **)(_BYTE *))(*(_DWORD *)this + 148))(this) )
    sub_49D120(this);
  return 0;
}
