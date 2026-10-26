char __thiscall sub_4AFD40(_DWORD *this)
{
  char *v2; // eax
  int v3; // eax
  int v4; // edi
  const char *v6; // esi

  if ( *this )
  {
    if ( ((int (*)(void))sub_5772B0)() )
    {
      v2 = (char *)this[1];
      if ( !v2 )
        v2 = &byte_629120;
      v3 = sub_4ADBB0((_DWORD *)dword_7655CC, v2);
      if ( v3 )
      {
        v4 = sub_4B07C0(v3);
        if ( sub_5772B0(*this) == v4 )
          return 1;
      }
    }
    else
    {
      v6 = (const char *)this[1];
      if ( !v6 )
        v6 = &byte_629120;
      if ( !strlen(v6) )
        return 1;
    }
  }
  return 0;
}
