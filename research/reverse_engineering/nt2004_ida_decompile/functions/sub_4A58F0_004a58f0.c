int __thiscall sub_4A58F0(_DWORD *this, int a2)
{
  int v3; // ecx
  int v4; // eax
  int result; // eax

  v3 = this[13];
  if ( v3 )
  {
    v4 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v3 + 40))(v3, a2);
    LOBYTE(v4) = (_BYTE)a2 == 0;
    return (*(int (__thiscall **)(_DWORD, int))(*(_DWORD *)this[13] + 36))(this[13], v4);
  }
  return result;
}
