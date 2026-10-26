int __thiscall sub_40EBD0(const char **this)
{
  unsigned __int8 v1; // bl
  int v3; // eax
  int v4; // esi
  const char *v5; // eax

  v1 = 0;
  if ( (int)NumOfElements <= 0 )
    return 0;
  v3 = 0;
  while ( 1 )
  {
    v4 = dword_75AAD0[v3];
    v5 = *this;
    if ( !*this )
      v5 = &byte_629120;
    if ( !_strcmpi((const char *)(v4 + 24992), v5) )
      break;
    v3 = ++v1;
    if ( v1 >= (int)NumOfElements )
      return 0;
  }
  return v4;
}
