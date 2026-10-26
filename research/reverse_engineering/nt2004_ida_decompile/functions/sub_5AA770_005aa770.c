int __thiscall sub_5AA770(_DWORD *this, int a2)
{
  int result; // eax

  if ( a2 != -1 && a2 != this[11] )
  {
    result = (*(int (__stdcall **)(int, _DWORD, int, int))(*(_DWORD *)dword_7E7CA8 + 252))(dword_7E7CA8, *this, 11, a2);
    this[11] = a2;
  }
  return result;
}
