int __stdcall sub_501810(int a1)
{
  int v1; // ecx
  int v2; // eax
  CHAR **v3; // eax
  CHAR *v4; // eax

  v1 = a1;
  if ( a1 < 0 || a1 >= dword_7D7984 )
    return 0;
  v2 = dword_7D7978;
  if ( a1 > 0 )
  {
    while ( v2 )
    {
      v2 = *(_DWORD *)(v2 + 4);
      if ( --v1 <= 0 )
        goto LABEL_6;
    }
    return 0;
  }
LABEL_6:
  if ( !v2 )
    return 0;
  v3 = *(CHAR ***)v2;
  if ( !v3 )
    return 0;
  v4 = *v3;
  if ( !v4 )
    v4 = &byte_629120;
  return sub_592CD0(v4);
}
