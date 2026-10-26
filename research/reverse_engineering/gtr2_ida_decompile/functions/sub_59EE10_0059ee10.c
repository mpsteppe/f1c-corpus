int __thiscall sub_59EE10(_DWORD *this, char a2)
{
  char **v2; // eax
  void *v3; // ecx

  v2 = (char **)this[6];
  v3 = this + 6;
  if ( v2 )
  {
    while ( !*v2 || *v2 != &a2 )
    {
      v2 = (char **)v2[1];
      if ( !v2 )
        return 1;
    }
    if ( *v2 )
      sub_524660(v3, (int)&a2, 1);
  }
  return 1;
}
