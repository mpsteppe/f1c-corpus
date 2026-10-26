int __thiscall sub_65D773(const char **this, _DWORD *a2)
{
  const char *v3; // eax
  int result; // eax
  char *v5; // eax
  const char *i; // edx
  unsigned int v7; // ecx

  if ( a2 )
  {
    v3 = this[1];
    if ( v3 )
    {
      result = sub_677265(v3 + 1, a2);
      if ( result < 0 )
        return result;
      v5 = (char *)&this[1][(*(int (__stdcall **)(_DWORD))(*(_DWORD *)*a2 + 12))(*a2)];
      *v5 = 0;
      for ( i = *this; i; i = *(const char **)i )
      {
        v7 = strlen(i + 4);
        v5 -= v7;
        qmemcpy(v5, i + 4, v7);
      }
    }
    else
    {
      *a2 = 0;
    }
  }
  return 0;
}
