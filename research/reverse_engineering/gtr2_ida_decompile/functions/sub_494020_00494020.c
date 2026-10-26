_DWORD *__thiscall sub_494020(_DWORD *this, int a2)
{
  int v3; // eax
  _DWORD *result; // eax
  bool v5; // zf

  sub_4D9E90();
  *this = &off_6FC8F8;
  this[70] = a2;
  if ( a2 == 744 )
  {
    v3 = (*(int (__thiscall **)(int, int))(*(_DWORD *)dword_B6E090 + 28))(dword_B6E090, 42);
    if ( v3 )
      this[69] = v3 + 608;
    return this;
  }
  else
  {
    v5 = (*(int (__thiscall **)(int, int))(*(_DWORD *)dword_B6E090 + 28))(dword_B6E090, 18) == 0;
    result = this;
    if ( !v5 )
      this[69] = &dword_B6E088;
  }
  return result;
}
