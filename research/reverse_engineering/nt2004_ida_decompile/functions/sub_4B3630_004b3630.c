int __stdcall sub_4B3630(char *Destination, int a2)
{
  int v2; // eax
  int v3; // eax
  const char *v4; // esi
  const char *v5; // esi
  size_t v6; // esi

  v2 = *(_DWORD *)(dword_75AAC4 + 20852) + 1;
  if ( *(_DWORD *)(dword_75AAC4 + 20852) == 2 )
    v2 = 0;
  if ( !v2 )
    goto LABEL_6;
  v3 = v2 - 1;
  if ( !v3 )
  {
    v5 = off_6090E8;
    if ( sub_41F230(dword_62A170, off_6090E8, ::Destination) )
    {
      if ( v5 )
        goto LABEL_11;
      ::Destination[0] = 0;
    }
    v6 = a2 - 1;
    goto LABEL_20;
  }
  if ( v3 == 1 )
  {
    v5 = off_6090EC;
    if ( sub_41F230(dword_62A170, off_6090EC, ::Destination) )
    {
      if ( v5 )
      {
LABEL_11:
        strncpy(::Destination, v5, 0x1FFu);
        byte_62A37B = 0;
        v6 = a2 - 1;
        goto LABEL_20;
      }
      ::Destination[0] = 0;
    }
    v6 = a2 - 1;
    goto LABEL_20;
  }
LABEL_6:
  v4 = off_6090F0;
  if ( sub_41F230(dword_62A170, off_6090F0, ::Destination) )
  {
    if ( v4 )
    {
      strncpy(::Destination, v4, 0x1FFu);
      byte_62A37B = 0;
    }
    else
    {
      ::Destination[0] = 0;
    }
  }
  v6 = a2 - 1;
LABEL_20:
  strncpy(Destination, ::Destination, v6);
  Destination[v6] = 0;
  return 0;
}
