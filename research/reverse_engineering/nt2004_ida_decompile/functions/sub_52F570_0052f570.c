int __thiscall sub_52F570(_BYTE *this, int a2)
{
  int v3; // edi

  v3 = 0;
  if ( (*(int (__thiscall **)(_BYTE *))(*(_DWORD *)this + 8))(this) )
    return -1;
  if ( this[9360] == 1 )
    return sub_52FD50(a2);
  if ( this[9360] == 2 )
    return sub_5328B0(a2);
  return v3;
}
