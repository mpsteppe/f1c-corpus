int (__thiscall ***__thiscall sub_5BC100(void *this))(_DWORD, int)
{
  int (__thiscall ***result)(_DWORD, int); // eax

  result = (int (__thiscall ***)(_DWORD, int))(*(int (__thiscall **)(void *))(*(_DWORD *)this + 12))(this);
  if ( result )
  {
    result = (int (__thiscall ***)(_DWORD, int))(*(int (__thiscall **)(void *))(*(_DWORD *)this + 12))(this);
    if ( result )
      return (int (__thiscall ***)(_DWORD, int))(**result)(result, 1);
  }
  return result;
}
