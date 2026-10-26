char *__cdecl _strupr(char *String)
{
  char *result; // eax
  char *j; // edx
  char v3; // cl
  char *i; // edx
  char v5; // cl
  size_t v6; // eax
  int v7; // ebx
  CHAR *v8; // eax
  char *Source; // [esp+8h] [ebp-8h]
  int v10; // [esp+Ch] [ebp-4h]

  Source = 0;
  if ( dword_7FF1E8 )
  {
    InterlockedIncrement(&dword_80151C);
    if ( dword_801518 )
    {
      InterlockedDecrement(&dword_80151C);
      _lock(19);
      v10 = 1;
    }
    else
    {
      v10 = 0;
    }
    if ( dword_7FF1E8 )
    {
      v6 = __crtLCMapStringA(dword_7FF1E8, 0x200u, String, -1, 0, 0, 0, 1);
      v7 = v6;
      if ( v6 )
      {
        v8 = (CHAR *)malloc(v6);
        Source = v8;
        if ( v8 )
        {
          if ( __crtLCMapStringA(dword_7FF1E8, 0x200u, String, -1, v8, v7, 0, 1) )
            strcpy(String, Source);
        }
      }
      if ( v10 )
        _unlock(19);
      else
        InterlockedDecrement(&dword_80151C);
      sub_5C1B88(Source);
      return String;
    }
    else
    {
      if ( v10 )
        _unlock(19);
      else
        InterlockedDecrement(&dword_80151C);
      result = String;
      for ( i = String; *i; ++i )
      {
        v5 = *i;
        if ( *i >= 97 && v5 <= 122 )
          *i = v5 - 32;
      }
    }
  }
  else
  {
    result = String;
    for ( j = String; *j; ++j )
    {
      v3 = *j;
      if ( *j >= 97 && v3 <= 122 )
        *j = v3 - 32;
    }
  }
  return result;
}
