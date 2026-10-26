int __stdcall sub_436630(char *Destination, int a2)
{
  char *v2; // ecx
  char *v3; // eax
  int v4; // eax
  const char *v5; // eax
  CHAR *v6; // ecx
  char *v7; // esi
  CHAR v8; // dl
  char Source[256]; // [esp+Ch] [ebp-100h] BYREF

  *Destination = 0;
  if ( !sub_57AE50(off_5FE080) )
    return 1;
  v2 = dword_766594;
  if ( !dword_766594 )
    v2 = &byte_629120;
  v3 = sub_435430(v2);
  if ( !sub_57A720(v3) )
    return 1;
  v4 = sub_57A720(off_5FE090);
  if ( !v4 )
  {
    v4 = sub_57A720(off_5FE08C);
    if ( !v4 )
      return 1;
  }
  v5 = (const char *)sub_57A6D0(v4);
  if ( !v5 )
    return 1;
  v6 = *(CHAR **)dword_62A0D0;
  if ( !*(_DWORD *)dword_62A0D0 )
    v6 = &byte_629120;
  v7 = (char *)(Source - v6);
  do
  {
    v8 = *v6;
    v6[(_DWORD)v7] = *v6;
    ++v6;
  }
  while ( v8 );
  strcat(Source, v5);
  strncpy(Destination, Source, a2 - 1);
  Destination[a2 - 1] = 0;
  return 0;
}
