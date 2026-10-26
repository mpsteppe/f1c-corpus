int __thiscall sub_5545E0(_DWORD *this, int a2)
{
  int result; // eax

  if ( a2 != -1 && a2 != this[11] )
  {
    result = (*(int (__stdcall **)(int, _DWORD, int, int))(*(_DWORD *)dword_8B89A0 + 252))(dword_8B89A0, *this, 11, a2);
    this[11] = a2;
  }
  return result;
}
