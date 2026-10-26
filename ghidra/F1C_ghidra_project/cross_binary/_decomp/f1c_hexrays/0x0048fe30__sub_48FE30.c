// f1c  0x0048fe30  size=44
int __thiscall sub_48FE30(_DWORD *this, int a2)
{
  int v3; // ecx
  int v4; // eax
  int result; // eax

  v3 = this[12];
  if ( v3 )
  {
    v4 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v3 + 60))(v3, a2);
    LOBYTE(v4) = (_BYTE)a2 == 0;
    return (*(int (__thiscall **)(_DWORD, int))(*(_DWORD *)this[12] + 56))(this[12], v4);
  }
  return result;
}
