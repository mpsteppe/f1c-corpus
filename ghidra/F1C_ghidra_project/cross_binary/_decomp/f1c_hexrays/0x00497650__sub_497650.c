// f1c  0x00497650  size=102
int __thiscall sub_497650(_DWORD *this, int a2)
{
  int *v3; // eax
  int v4; // esi
  char *v5; // eax
  int v6; // eax
  int *v7; // eax

  v3 = (int *)this[1];
  this[3] = v3;
  if ( !v3 )
    return 0;
  v4 = *v3;
  if ( !*v3 )
    return 0;
  while ( 1 )
  {
    v5 = *(char **)(v4 + 52);
    if ( !v5 )
      v5 = byte_5EA438;
    if ( !sub_588410(v5, a2) )
      break;
    v6 = this[3];
    if ( v6 )
      this[3] = *(_DWORD *)(v6 + 4);
    v7 = (int *)this[3];
    if ( v7 )
    {
      v4 = *v7;
      if ( *v7 )
        continue;
    }
    return 0;
  }
  return v4;
}
