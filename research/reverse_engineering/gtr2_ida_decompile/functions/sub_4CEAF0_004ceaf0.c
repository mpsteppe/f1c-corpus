int __thiscall sub_4CEAF0(_BYTE *this)
{
  int v3; // eax

  if ( this[100] )
    return -1;
  v3 = *((_DWORD *)this + 33);
  if ( v3 == 5 || v3 == 4 )
    (*(void (__thiscall **)(_BYTE *, int))(*(_DWORD *)this + 44))(this, 1);
  else
    (*(void (__thiscall **)(_BYTE *))(*(_DWORD *)this + 52))(this);
  if ( !(*(int (__thiscall **)(_BYTE *))(*(_DWORD *)this + 148))(this) )
    sub_4CD5A0(this, 0);
  return 0;
}
