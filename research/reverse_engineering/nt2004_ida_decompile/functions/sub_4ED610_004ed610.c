int __thiscall sub_4ED610(void *this)
{
  int v1; // esi
  int *v2; // eax
  bool v3; // zf
  int v4; // edi
  const char *v5; // eax
  const char *v6; // ecx
  int v7; // eax
  int *v8; // eax
  int v10; // ecx

  v10 = sub_4ED8C0(this);
  v1 = v10;
  if ( !*(_DWORD *)(v10 + 96) )
    return 0;
  v2 = *(int **)v10;
  v3 = *(_DWORD *)v10 == 0;
  *(_DWORD *)(v10 + 8) = *(_DWORD *)v10;
  if ( v3 )
    return 0;
  v4 = *v2;
  if ( !*v2 )
    return 0;
  while ( 1 )
  {
    v5 = *(const char **)(*(_DWORD *)(v1 + 96) + 20);
    if ( !v5 )
      v5 = &byte_629120;
    v6 = *(const char **)v4;
    if ( !*(_DWORD *)v4 )
      v6 = &byte_629120;
    if ( !_strcmpi(v6, v5) )
      break;
    v7 = *(_DWORD *)(v1 + 8);
    if ( v7 )
    {
      v8 = *(int **)(v7 + 4);
      *(_DWORD *)(v1 + 8) = v8;
      if ( v8 )
      {
        v4 = *v8;
        if ( *v8 )
          continue;
      }
    }
    return 0;
  }
  return *(_DWORD *)(v4 + 20);
}
