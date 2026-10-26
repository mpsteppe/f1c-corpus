int __thiscall sub_4976C0(_DWORD *this, int a2)
{
  int *v3; // eax
  int v4; // ebx
  int v5; // eax
  int i; // esi
  char *v8; // eax
  int v9; // eax
  int *v10; // eax

  v3 = (int *)this[1];
  v4 = 0;
  this[3] = v3;
  if ( v3 )
    v5 = *v3;
  else
    v5 = 0;
  if ( !a2 )
    return 0;
  for ( ; v5; v5 = *v10 )
  {
    for ( i = FieldGetter_8e30(v5); i; i = *(_DWORD *)(i + 72) )
    {
      v8 = *(char **)(i + 52);
      if ( !v8 )
        v8 = byte_5EA438;
      if ( !sub_588410(v8, a2) )
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

