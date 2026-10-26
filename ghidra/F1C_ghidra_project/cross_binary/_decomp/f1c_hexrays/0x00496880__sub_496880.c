// f1c  0x00496880  size=164
int __thiscall sub_496880(_DWORD *this)
{
  _DWORD *i; // esi
  int v3; // ecx
  _DWORD *v4; // esi
  char *v5; // eax
  char *v6; // eax

  for ( i = (_DWORD *)this[7]; i; i = (_DWORD *)i[35] )
    (*(void (__thiscall **)(_DWORD *))(*i + 164))(i);
  v3 = this[6];
  if ( v3 )
    (*(void (__thiscall **)(int, _DWORD, _DWORD))(*(_DWORD *)v3 + 56))(v3, this[23], this[24]);
  v4 = (_DWORD *)this[6];
  if ( v4 )
  {
    if ( sub_498E40(this[6]) )
    {
      v5 = *(char **)(sub_498E40(v4) + 52);
      if ( !v5 )
        v5 = byte_5EA438;
      sub_49A490(aCurrentPage, v5);
    }
    if ( sub_498E40(v4) )
    {
      v6 = (char *)v4[13];
      if ( !v6 )
        v6 = byte_5EA438;
      sub_49A490(aCurrentLayer, v6);
    }
    (*(void (__thiscall **)(_DWORD *))(*v4 + 64))(v4);
  }
  return 0;
}
