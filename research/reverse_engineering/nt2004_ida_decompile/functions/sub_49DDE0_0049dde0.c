int __thiscall sub_49DDE0(_BYTE *this)
{
  _DWORD *v2; // ecx

  if ( !sub_49DDD0(this) )
    return -1;
  sub_49D9C0(v2, 1);
  if ( (*(int (__thiscall **)(_BYTE *))(*(_DWORD *)this + 144))(this) )
    return -1;
  sub_49D0F0(this);
  return 0;
}
