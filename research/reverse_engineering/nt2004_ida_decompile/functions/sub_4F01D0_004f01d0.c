int __stdcall sub_4F01D0(int a1)
{
  int result; // eax

  if ( dword_7D6BB0 )
  {
    if ( a1 == 1 )
      return (*(int (__stdcall **)(int))(*(_DWORD *)dword_7D6BB0 + 64))(1);
    else
      return (*(int (__stdcall **)(_DWORD))(*(_DWORD *)dword_7D6BB0 + 64))(0);
  }
  return result;
}
