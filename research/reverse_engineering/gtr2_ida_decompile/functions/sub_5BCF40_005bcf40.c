int (__thiscall ***__thiscall sub_5BCF40(_DWORD *this))(_DWORD, int)
{
  int (__thiscall ***result)(_DWORD, int); // eax

  *this = off_7296E8;
  result = (int (__thiscall ***)(_DWORD, int))sub_4FB7D0(this);
  if ( result )
  {
    result = (int (__thiscall ***)(_DWORD, int))(*(int (__thiscall **)(_DWORD *))(*this + 12))(this);
    if ( result )
      result = (int (__thiscall ***)(_DWORD, int))(**result)(result, 1);
  }
  *this = off_72967C;
  return result;
}
