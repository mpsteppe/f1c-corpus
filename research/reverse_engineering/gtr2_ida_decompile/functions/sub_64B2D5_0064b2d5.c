int __stdcall sub_64B2D5(int a1, int a2, int a3, int a4, int a5, int a6)
{
  int (__stdcall *v6)(int, int, int, int, int, int); // eax

  if ( sub_5AE78A() )
  {
    v6 = (int (__stdcall *)(int, int, int, int, int, int))sub_64B181;
    off_91433C = (_DWORD (*)())sub_64B181;
  }
  else
  {
    off_91433C = (_DWORD (*)())sub_64AF49;
    v6 = (int (__stdcall *)(int, int, int, int, int, int))sub_64B095;
  }
  off_914340 = v6;
  return v6(a1, a2, a3, a4, a5, a6);
}
