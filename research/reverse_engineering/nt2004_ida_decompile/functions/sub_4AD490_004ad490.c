int __thiscall sub_4AD490(_DWORD *this, char *String2)
{
  int *v3; // eax
  int v4; // ebx
  int v5; // eax
  int i; // esi
  const char *v8; // eax
  int v9; // eax
  int *v10; // eax

  v3 = (int *)this[1];
  v4 = 0;
  this[3] = v3;
  if ( v3 )
    v5 = *v3;
  else
    v5 = 0;
  if ( !String2 )
    return 0;
  for ( ; v5; v5 = *v10 )
  {
    for ( i = sub_4AEF80(v5); i; i = *(_DWORD *)(i + 56) )
    {
      v8 = *(const char **)(i + 36);
      if ( !v8 )
        v8 = &byte_629120;
      if ( !_strcmpi(v8, String2) )
        v4 = i;
    }
    v9 = this[3];
    if ( !v9 )
      break;
    v10 = *(int **)(v9 + 4);
    this[3] = v10;
    if ( !v10 )
      break;
  }
  return v4;
}
