int __thiscall sub_407F10(_DWORD *this, const char *a2)
{
  int *v3; // eax
  int v4; // esi
  int v5; // eax
  int v6; // eax
  int *v7; // eax

  if ( !a2 )
    return -1;
  if ( !strcmp(a2, &byte_5EA438) )
    return -1;
  v3 = (int *)this[6];
  this[8] = v3;
  if ( !v3 )
    return -1;
  v4 = *v3;
  if ( !*v3 )
    return -1;
  while ( 1 )
  {
    if ( *(_DWORD *)(v4 + 92) != -1 )
    {
      v5 = StringPointerAccessor(v4);
      if ( !sub_588410(v5, a2) )
        break;
    }
    v6 = this[8];
    if ( v6 )
      this[8] = *(_DWORD *)(v6 + 4);
    v7 = (int *)this[8];
    if ( v7 )
    {
      v4 = *v7;
      if ( *v7 )
        continue;
    }
    return -1;
  }
  return *(_DWORD *)(v4 + 92);
}

