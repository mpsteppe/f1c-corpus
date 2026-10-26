int __thiscall sub_502100(_DWORD *this)
{
  int result; // eax

  result = this[4];
  if ( result != -1 )
  {
    result = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)this[result + 9] + 20))(this[result + 9]);
    if ( result == 1 )
      this[4] = -1;
  }
  return result;
}
