int __thiscall sub_60A360(_DWORD *this, int a2)
{
  int result; // eax

  result = this[63];
  if ( a2 != result && a2 != -1 )
  {
    result = (*(int (__stdcall **)(int, _DWORD, int, int))(*(_DWORD *)dword_FB40C8 + 268))(
               dword_FB40C8,
               this[60],
               11,
               a2);
    this[63] = a2;
  }
  return result;
}
