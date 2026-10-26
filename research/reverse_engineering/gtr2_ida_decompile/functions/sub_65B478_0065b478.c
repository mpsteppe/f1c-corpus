int __thiscall sub_65B478(char *this, const char **a2)
{
  const char **v2; // edi
  const char ***v3; // esi
  const char **v4; // ecx
  int v5; // eax
  const char **v6; // ecx

  v2 = a2;
  v3 = (const char ***)&this[4 * sub_65AE66(*a2) + 108];
  if ( *v3 )
  {
    do
    {
      v4 = *v3;
      v5 = strcmp(*v2, **v3);
      v2 = a2;
      if ( v5 < 0 )
        break;
      if ( !v5 )
      {
        if ( !sub_65AE9D((int)*v3, (int)a2) )
          sub_65DDE6((int)(this + 24), (int)(this + 632), 1519, "'%s' : macro redefinition", (char)*a2);
        v6 = *v3;
        *v3 = (const char **)(*v3)[3];
        v6[3] = 0;
        sub_65B2FE(v6, 1);
        break;
      }
      v3 = (const char ***)(v4 + 3);
    }
    while ( v4[3] );
  }
  v2[3] = (const char *)*v3;
  *v3 = v2;
  return 0;
}
