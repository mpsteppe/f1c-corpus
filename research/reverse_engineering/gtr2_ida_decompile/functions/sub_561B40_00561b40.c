int __thiscall sub_561B40(int *this)
{
  int result; // eax

  result = *this;
  if ( *this != -1 )
  {
    result = (*(int (__thiscall **)(int))(*(_DWORD *)this[result + 6] + 20))(this[result + 6]);
    if ( result == 1 )
      *this = -1;
  }
  return result;
}
