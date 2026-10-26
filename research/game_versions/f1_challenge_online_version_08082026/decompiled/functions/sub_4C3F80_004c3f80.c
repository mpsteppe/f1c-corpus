void __stdcall sub_4C3F80(int a1)
{
  int v1; // edi
  int i; // esi
  char *v3; // eax

  if ( a1 )
  {
    v1 = 0;
    if ( dword_8AC390 > 0 )
    {
      for ( i = 0; ; i += 1060 )
      {
        v3 = *(char **)(i + dword_8AC394);
        if ( !v3 )
          v3 = byte_5EA438;
        if ( !sub_588410(v3, a1) )
          break;
        if ( ++v1 >= dword_8AC390 )
          return;
      }
      dword_8AC38C = v1;
    }
  }
}
