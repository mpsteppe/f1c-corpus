int __stdcall sub_48D650(const char *a1, int a2)
{
  int v2; // eax
  const char *v3; // eax
  int v4; // edx
  char v5; // bl

  if ( !a1 )
    return sub_4D3CF0(a2, -1);
  v2 = strlen(a1);
  if ( v2 > 27 )
  {
    v4 = v2 - 28;
    if ( v2 - 28 < v2 )
    {
      do
        v5 = a1[v4++];
      while ( v5 != 32 && v4 < v2 );
    }
    v3 = &a1[v4];
  }
  else
  {
    v3 = a1;
  }
  if ( v3 && *v3 )
    return sub_4D3CF0(v3, -1);
  else
    return sub_4D3CF0(a2, -1);
}
