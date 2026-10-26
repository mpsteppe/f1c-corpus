int __stdcall sub_410560(unsigned __int8 a1)
{
  int v1; // eax
  const char *v2; // eax

  (**(void (__thiscall ***)(int))dword_76BB24)(dword_76BB24);
  if ( !sub_57AE50(aSponsorvalues) )
    return 0;
  v1 = sub_57A700(a1);
  if ( !v1 )
    return 0;
  v2 = (const char *)sub_57A6D0(v1);
  return atoi(v2);
}
