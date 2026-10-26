const char *__stdcall sub_5FDF20(const char *a1)
{
  int v1; // ebp
  const char *v2; // edi

  v1 = dword_FB285C;
  dword_FB2864 = dword_FB285C;
  if ( !dword_FB285C )
    return 0;
  v2 = *(const char **)dword_FB285C;
  if ( !*(_DWORD *)dword_FB285C )
    return 0;
  while ( strcmp(v2, a1) )
  {
    v1 = *(_DWORD *)(v1 + 4);
    dword_FB2864 = v1;
    if ( v1 )
    {
      v2 = *(const char **)v1;
      if ( *(_DWORD *)v1 )
        continue;
    }
    return 0;
  }
  return v2;
}
