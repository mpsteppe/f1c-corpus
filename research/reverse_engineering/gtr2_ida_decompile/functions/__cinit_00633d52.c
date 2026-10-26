int __cdecl _cinit(int a1)
{
  int result; // eax
  int (**v2)(void); // esi
  void (**v3)(void); // esi

  if ( off_912858 )
    off_912858(a1);
  result = 0;
  v2 = (int (**)(void))&unk_7574B0;
  if ( &unk_7574B0 >= (_UNKNOWN *)&dword_7574C8 )
  {
LABEL_9:
    atexit(sub_63DAB9);
    v3 = (void (**)(void))&unk_757000;
    if ( &unk_757000 < (_UNKNOWN *)&dword_7574AC )
    {
      do
      {
        if ( *v3 )
          (*v3)();
        ++v3;
      }
      while ( v3 < &dword_7574AC );
    }
    return 0;
  }
  else
  {
    while ( !result )
    {
      if ( *v2 )
        result = (*v2)();
      if ( ++v2 >= &dword_7574C8 )
      {
        if ( result )
          return result;
        goto LABEL_9;
      }
    }
  }
  return result;
}
