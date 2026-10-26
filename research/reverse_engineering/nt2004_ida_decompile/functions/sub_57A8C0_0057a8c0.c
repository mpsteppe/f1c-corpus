char __stdcall sub_57A8C0(int *a1, int a2)
{
  int v2; // esi
  char *v3; // eax
  char *v4; // ecx
  char *v5; // eax
  char *v6; // eax
  char v8; // [esp+Fh] [ebp-401h]
  char Str[512]; // [esp+10h] [ebp-400h] BYREF
  char Buffer[512]; // [esp+210h] [ebp-200h] BYREF

  v2 = 0;
  memset(Buffer, 0, sizeof(Buffer));
  memset(Str, 0, sizeof(Str));
  v8 = 0;
  while ( sub_57A490(a1, Buffer, 512) )
  {
    v8 = 1;
    if ( sub_57A820((unsigned __int8 *)Buffer, Str) )
    {
      if ( Str[0] == 123 )
      {
        sub_57A8C0(a1, v2);
      }
      else
      {
        if ( Str[0] == 125 )
          return v8;
        v3 = strstr(Str, Delimiter);
        if ( v3 )
        {
          *v3 = 0;
          v4 = (char *)a1[1];
          v5 = v3 + 1;
          if ( !v4 )
            v4 = &byte_629120;
          v2 = sub_57ACC0(Str, v5, v4, a2);
        }
        else
        {
          v6 = (char *)a1[1];
          if ( !v6 )
            v6 = &byte_629120;
          v2 = sub_57ACC0(Str, 0, v6, a2);
        }
      }
    }
  }
  return v8;
}
