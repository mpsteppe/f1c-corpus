int sub_4EF370()
{
  int result; // eax

  if ( dword_7D6BB4 )
  {
    result = (**(int (__thiscall ***)(int, int))dword_7D6BB4)(dword_7D6BB4, 1);
    dword_7D6BB4 = 0;
  }
  if ( dword_7D6BB8 )
  {
    result = (**(int (__thiscall ***)(int, int))dword_7D6BB8)(dword_7D6BB8, 1);
    dword_7D6BB8 = 0;
  }
  if ( dword_7D6BBC )
  {
    result = (**(int (__thiscall ***)(int, int))dword_7D6BBC)(dword_7D6BBC, 1);
    dword_7D6BBC = 0;
  }
  if ( dword_7D6BC0 )
  {
    result = (**(int (__thiscall ***)(int, int))dword_7D6BC0)(dword_7D6BC0, 1);
    dword_7D6BC0 = 0;
  }
  if ( dword_7D6BB0 )
    result = (*(int (__thiscall **)(int))(*(_DWORD *)dword_7D6BB0 + 12))(dword_7D6BB0);
  dword_7D6BB0 = 0;
  return result;
}
