int __stdcall sub_4C8D90(int a1)
{
  int result; // eax

  if ( dword_8AC4C4 )
  {
    if ( a1 == 1 )
      return (*(int (__stdcall **)(int))(*(_DWORD *)dword_8AC4C4 + 60))(1);
    else
      return (*(int (__stdcall **)(_DWORD))(*(_DWORD *)dword_8AC4C4 + 60))(0);
  }
  return result;
}

