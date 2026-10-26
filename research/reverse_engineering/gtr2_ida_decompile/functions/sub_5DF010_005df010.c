void __stdcall sub_5DF010(const char *a1, char *String)
{
  int v2; // eax

  if ( String )
  {
    strcpy(String, a1);
    _strupr(String);
    v2 = 0;
    if ( *String )
    {
      while ( String[v2] != 41 )
      {
        if ( !String[++v2] )
          return;
      }
      String[v2] = 0;
    }
  }
}
