int __stdcall sub_489E00(int a1)
{
  int v1; // ebx
  int v2; // edi
  int v3; // esi
  const char *v4; // ebp
  const char *v5; // eax
  int v6; // eax
  int v7; // eax

  v1 = 0;
  v2 = sub_4ED6A0(&dword_7D6B74);
  v3 = 0;
  v4 = (const char *)sub_4ED720(&dword_7D6B74);
  if ( v2 > 0 )
  {
    while ( 1 )
    {
      v5 = (const char *)sub_4ED6B0(v3);
      if ( !_strcmpi(v4, v5) )
        break;
      if ( ++v3 >= v2 )
        goto LABEL_6;
    }
    v1 = v3;
  }
LABEL_6:
  if ( a1 )
  {
    if ( v1 == v2 - 1 )
      v6 = 0;
    else
      v6 = v1 + 1;
  }
  else if ( v1 )
  {
    v6 = v1 - 1;
  }
  else
  {
    v6 = v2 - 1;
  }
  if ( v1 == v6 )
    return 0;
  v7 = sub_4ED6B0(v6);
  sub_4ED810(v7);
  return 1;
}
