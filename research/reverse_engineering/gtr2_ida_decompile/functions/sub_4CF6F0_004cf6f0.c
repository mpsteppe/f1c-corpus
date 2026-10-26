int __thiscall sub_4CF6F0(_DWORD *this, int a2)
{
  int result; // eax
  int v4; // eax

  result = this[13];
  if ( result )
  {
    v4 = (*(int (__thiscall **)(int, int))(*(_DWORD *)result + 40))(result, a2);
    LOBYTE(v4) = (_BYTE)a2 == 0;
    return (*(int (__thiscall **)(_DWORD, int))(*(_DWORD *)this[13] + 36))(this[13], v4);
  }
  return result;
}
