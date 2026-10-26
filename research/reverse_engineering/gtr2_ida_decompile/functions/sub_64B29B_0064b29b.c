int sub_64B29B()
{
  if ( sub_5AE78A() )
  {
    off_91433C = (_DWORD (*)())sub_64B181;
    off_914340 = (int (__stdcall *)(int, int, int, int, int, int))sub_64B181;
  }
  else
  {
    off_91433C = (_DWORD (*)())sub_64AF49;
    off_914340 = (int (__stdcall *)(int, int, int, int, int, int))sub_64B095;
  }
  return off_91433C();
}
