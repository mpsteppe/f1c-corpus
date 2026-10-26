char __thiscall sub_4CD7E0(_DWORD *this, char *Destination)
{
  const char *v2; // edx
  const char *v3; // ecx
  const char *v4; // eax
  char *v5; // edx
  char v6; // cl
  char Source[28]; // [esp+4h] [ebp-1Ch] BYREF

  v2 = (const char *)this[126];
  if ( !v2 )
    v2 = &byte_629120;
  v3 = &v2[strlen(v2)];
  if ( v3 > v2 )
  {
    while ( *v3 != 92 )
    {
      if ( --v3 <= v2 )
        goto LABEL_8;
    }
    ++v3;
  }
LABEL_8:
  v4 = v3;
  v5 = (char *)(Source - v3);
  do
  {
    v6 = *v4;
    v4[(_DWORD)v5] = *v4;
    ++v4;
  }
  while ( v6 );
  if ( !strlen(Source) )
    return 0;
  strncpy(Destination, Source, 4u);
  Destination[4] = 0;
  return 1;
}
