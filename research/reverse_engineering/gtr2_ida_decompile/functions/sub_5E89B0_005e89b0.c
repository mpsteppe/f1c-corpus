void __stdcall sub_5E89B0(const char *a1)
{
  char *v1; // esi
  signed int v2; // edi
  unsigned int v3; // eax
  signed int v4; // eax
  signed int v5; // edi
  char v6; // cl

  v1 = (char *)operator new(strlen(a1) + 1);
  v2 = strlen(a1);
  sub_630FE0(v1);
  if ( v2 >= (int)strlen(a1) )
    v3 = strlen(a1);
  else
    v3 = v2;
  v1[v3] = 0;
  v4 = strlen(v1) - 1;
  if ( v4 >= 0 )
  {
    while ( v1[v4] != 46 )
    {
      if ( --v4 < 0 )
        goto LABEL_11;
    }
    v1[v4] = 0;
    do
    {
      if ( v1[v4] == 92 )
        break;
      --v4;
    }
    while ( v4 >= 0 );
  }
LABEL_11:
  v5 = strlen(v1);
  sub_630FE0(a1);
  if ( v5 >= (int)strlen(v1) )
    a1[strlen(v1)] = 0;
  else
    a1[v5] = v6;
  j__free(v1);
}
