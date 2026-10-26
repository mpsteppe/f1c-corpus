char **sub_4AA360()
{
  char **result; // eax
  char *v1; // eax
  int v2; // [esp+0h] [ebp-84h]
  int v3[32]; // [esp+4h] [ebp-80h] BYREF

  sub_4D0AC0(v2);
  result = (char **)dword_B76240;
  dword_B76248 = dword_B76240;
  if ( dword_B76240 )
  {
    result = *(char ***)dword_B76240;
    if ( *(_DWORD *)dword_B76240 )
    {
      do
      {
        v1 = *result;
        if ( !v1 )
          v1 = (char *)WindowName;
        sub_53A2B0((int)v3, 127, "VenueName", v1);
        sub_4D93B0(v3, 0, 0, 0, 0, 0, -1, -1, -1, -1);
        result = (char **)dword_B76248;
        if ( !dword_B76248 )
          break;
        dword_B76248 = *(_DWORD *)(dword_B76248 + 4);
        result = (char **)dword_B76248;
        if ( !dword_B76248 )
          break;
        result = *(char ***)dword_B76248;
      }
      while ( *(_DWORD *)dword_B76248 );
    }
  }
  return result;
}
