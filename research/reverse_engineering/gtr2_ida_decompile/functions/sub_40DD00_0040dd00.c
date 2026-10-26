int __thiscall sub_40DD00(_DWORD **this, int a2)
{
  int result; // eax

  result = 0;
  if ( a2 )
  {
    result = (*(int (__thiscall **)(_DWORD *, int))(*this[8] + 28))(this[8], a2);
    if ( !result )
    {
      result = (*(int (__thiscall **)(_DWORD *, int))(*this[9] + 28))(this[9], a2);
      if ( !result )
      {
        result = (*(int (__thiscall **)(_DWORD *, int))(*this[10] + 28))(this[10], a2);
        if ( !result )
          return (*(int (__thiscall **)(_DWORD *, int))(*this[11] + 28))(this[11], a2);
      }
    }
  }
  return result;
}
