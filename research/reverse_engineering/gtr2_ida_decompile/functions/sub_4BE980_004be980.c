int sub_4BE980()
{
  int result; // eax
  int v1; // ebp
  const char *v2; // ebx
  int v3; // edi
  int v4; // esi
  const char *v5; // eax
  const CHAR *v6; // [esp+0h] [ebp-8h]

  result = dword_BE1BD8;
  if ( dword_BE1BD8 )
  {
    v6 = *(const CHAR **)dword_BE1BD8;
    if ( !*(_DWORD *)dword_BE1BD8 )
      v6 = WindowName;
    result = dword_757C10;
    if ( dword_757C10 > 0 )
    {
      v1 = 0;
      do
      {
        v2 = (const char *)(dword_B763DC + v1 + 22084);
        v3 = 0;
        if ( dword_BE1BD4 <= 0 )
        {
LABEL_12:
          if ( v6 )
            sub_53FE50(dword_B763DC + v1, 0);
        }
        else
        {
          v4 = 0;
          while ( 1 )
          {
            v5 = *(const char **)(v4 + dword_BE1BD8);
            if ( !v5 )
              v5 = WindowName;
            if ( !_stricmp(v2, v5) )
              break;
            ++v3;
            v4 += 2824;
            if ( v3 >= dword_BE1BD4 )
              goto LABEL_12;
          }
        }
        v1 += 22616;
        result = (int)--v6;
      }
      while ( v6 );
    }
  }
  return result;
}
