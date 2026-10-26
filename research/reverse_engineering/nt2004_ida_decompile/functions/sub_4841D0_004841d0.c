void __thiscall sub_4841D0(_DWORD *this)
{
  int v2; // ecx
  int *v3; // eax
  int v4; // eax
  CHAR **v5; // esi
  CHAR *v6; // eax

  v2 = this[216];
  if ( v2 >= 0 && v2 < this[220] )
  {
    v3 = (int *)this[217];
    if ( v2 <= 0 )
    {
LABEL_6:
      if ( v3 )
      {
        v4 = *v3;
        if ( v4 )
        {
          v5 = *(CHAR ***)(v4 + 84);
          if ( v5 )
          {
            v6 = *v5;
            if ( !*v5 )
              v6 = &byte_629120;
            sub_578600(v6);
            sub_578600((char *)v5 + 246);
          }
        }
      }
    }
    else
    {
      while ( v3 )
      {
        v3 = (int *)v3[1];
        if ( --v2 <= 0 )
          goto LABEL_6;
      }
    }
  }
  sub_484090(this);
}
