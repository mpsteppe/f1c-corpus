int __thiscall sub_48B1D0(_DWORD *this)
{
  int result; // eax
  int v3; // ecx
  _DWORD *v4; // [esp-8h] [ebp-1Ch]
  int (*v5)(); // [esp-4h] [ebp-18h]

  *this = &off_72B55C;
  v5 = sub_48B20D;
  v4 = this;
  for ( result = this[5]; result; result = this[5] )
  {
    v3 = this[5] - 1;
    this[5] = v3;
    (**(void (__thiscall ***)(int, _DWORD, _DWORD *, int (*)()))(this[7] + 8 * v3))(this[7] + 8 * v3, 0, v4, v5);
  }
  return result;
}
