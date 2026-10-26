// f1c  0x0048fdf0  size=54
int __thiscall sub_48FDF0(_DWORD *this, int a2, int a3)
{
  _DWORD *v4; // ecx
  int result; // eax

  v4 = (_DWORD *)this[12];
  if ( v4 )
  {
    sub_486460(v4, v4[33]);
    sub_49AA30(a2, a3);
    return (*(int (__thiscall **)(_DWORD, int))(*(_DWORD *)this[12] + 44))(this[12], 1);
  }
  return result;
}
