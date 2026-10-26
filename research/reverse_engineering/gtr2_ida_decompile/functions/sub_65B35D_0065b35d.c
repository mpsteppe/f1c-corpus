int __thiscall sub_65B35D(char *this, char *a2)
{
  const char ***v2; // eax
  const char **v3; // ecx
  int v4; // edx
  const char **v5; // ecx

  v2 = (const char ***)&this[4 * sub_65AE66(a2) + 108];
  if ( *v2 )
  {
    do
    {
      v3 = *v2;
      v4 = strcmp(a2, **v2);
      if ( v4 < 0 )
        break;
      if ( !v4 )
      {
        v5 = *v2;
        *v2 = (const char **)(*v2)[3];
        v5[3] = 0;
        sub_65B2FE(v5, 1);
        return 0;
      }
      v2 = (const char ***)(v3 + 3);
    }
    while ( v3[3] );
  }
  return 0;
}
