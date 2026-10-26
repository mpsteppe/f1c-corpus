int __thiscall sub_4D88B0(int *this)
{
  int result; // eax

  result = *this;
  if ( *this != -1 )
  {
    result = (*(int (__thiscall **)(int))(*(_DWORD *)this[result + 4] + 20))(this[result + 4]);
    if ( result == 1 )
      *this = -1;
  }
  return result;
}
