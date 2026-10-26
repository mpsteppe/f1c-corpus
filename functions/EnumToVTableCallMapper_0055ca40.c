int __thiscall sub_55CA40(int *this, int a2, int a3)
{
  int result; // eax

  if ( a2 == 1 )
  {
    result = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)this[1088] + 148))(this[1088], 256, a3);
  }
  else if ( a2 == 2 )
  {
    result = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)this[1088] + 148))(this[1088], 2, a3);
  }
  else
  {
    result = a2 - 4;
    if ( a2 != 4 )
      return result;
    result = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)this[1088] + 148))(this[1088], 3, a3);
  }
  *this = result;
  return result;
}
