char __thiscall sub_4CD870(_DWORD *this, char *Destination, int a3)
{
  const char *v3; // edx
  const char *v4; // ecx

  v3 = (const char *)this[126];
  if ( !v3 )
    v3 = &byte_629120;
  v4 = &v3[strlen(v3)];
  if ( v4 > v3 )
  {
    while ( *v4 != 92 )
    {
      if ( --v4 <= v3 )
        goto LABEL_8;
    }
    ++v4;
  }
LABEL_8:
  strncpy(Destination, v4, a3 - 1);
  Destination[a3 - 1] = 0;
  return 1;
}
