int __stdcall sub_540160(int a1)
{
  int result; // eax

  if ( dword_BE1D0C )
  {
    if ( a1 == 1 )
      return (*(int (__stdcall **)(int))(*(_DWORD *)dword_BE1D0C + 60))(1);
    else
      return (*(int (__stdcall **)(_DWORD))(*(_DWORD *)dword_BE1D0C + 60))(0);
  }
  return result;
}
