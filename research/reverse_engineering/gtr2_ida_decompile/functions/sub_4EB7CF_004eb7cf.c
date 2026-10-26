int sub_4EB7CF()
{
  void **v0; // esi
  int result; // eax

  v0 = &dword_B6E4C0;
  while ( !*v0 )
  {
    if ( (int)++v0 >= (int)&dword_B6E4D0 )
      return result;
  }
  return sub_567D00(*v0);
}
