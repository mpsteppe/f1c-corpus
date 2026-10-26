_DWORD *__thiscall sub_49D720(_DWORD *this)
{
  int *v2; // eax
  int i; // eax
  char *v4; // eax
  int v5; // eax
  int *v6; // eax

  v2 = (int *)this[21];
  this[23] = v2;
  if ( v2 )
  {
    for ( i = *v2; i; i = *v6 )
    {
      v4 = *(char **)(i + 4);
      if ( !v4 )
        v4 = &byte_629120;
      sub_4ADC00(v4);
      v5 = this[23];
      if ( !v5 )
        break;
      v6 = *(int **)(v5 + 4);
      this[23] = v6;
      if ( !v6 )
        break;
    }
  }
  return sub_49D6E0(this);
}
