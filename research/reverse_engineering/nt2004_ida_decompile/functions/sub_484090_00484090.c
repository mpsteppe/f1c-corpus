void __thiscall sub_484090(_DWORD *this)
{
  int v1; // edx
  int *v2; // eax
  int v3; // eax
  char *v4; // eax

  v1 = this[216];
  if ( v1 >= 0 && v1 < this[220] )
  {
    v2 = (int *)this[217];
    if ( v1 <= 0 )
    {
LABEL_6:
      if ( v2 )
      {
        v3 = *v2;
        if ( v3 )
        {
          v4 = *(char **)(v3 + 64);
          if ( !v4 )
            v4 = &byte_629120;
          sub_4A1AC0(v4);
        }
      }
    }
    else
    {
      while ( v2 )
      {
        v2 = (int *)v2[1];
        if ( --v1 <= 0 )
          goto LABEL_6;
      }
    }
  }
}
