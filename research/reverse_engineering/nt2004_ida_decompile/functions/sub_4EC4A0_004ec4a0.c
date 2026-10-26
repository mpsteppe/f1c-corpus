int __thiscall sub_4EC4A0(_DWORD *this)
{
  int v2; // edi
  int *v3; // eax
  int v4; // ecx
  const char *v5; // eax
  const char *v6; // ecx
  int v7; // eax
  int *v8; // eax

  v2 = 0;
  if ( this[24] )
  {
    v3 = (int *)this[8];
    this[10] = v3;
    if ( v3 )
    {
      v4 = *v3;
      if ( *v3 )
      {
        do
        {
          v5 = *(const char **)(this[24] + 20);
          if ( !v5 )
            v5 = &byte_629120;
          v6 = *(const char **)(v4 + 28);
          if ( !v6 )
            v6 = &byte_629120;
          if ( !_strcmpi(v6, v5) )
            ++v2;
          v7 = this[10];
          if ( !v7 )
            break;
          v8 = *(int **)(v7 + 4);
          this[10] = v8;
          if ( !v8 )
            break;
          v4 = *v8;
        }
        while ( *v8 );
      }
    }
  }
  return v2;
}
