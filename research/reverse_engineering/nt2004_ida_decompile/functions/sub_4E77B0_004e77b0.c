int __stdcall sub_4E77B0(char *Str, const char *a2, const char *a3, int a4)
{
  FILE *v4; // eax
  const char *v5; // ecx
  const char *v6; // eax
  const char *v7; // eax
  char Buffer[256]; // [esp+4h] [ebp-100h] BYREF

  if ( !strstr(Str, word_5FC804) )
    strcat(Str, a2);
  if ( a3 )
  {
    sprintf(Buffer, "%s%s", a3, Str);
    v4 = fopen(Buffer, aR);
    if ( v4 )
      goto LABEL_13;
  }
  v5 = (const char *)dword_62A0B8;
  if ( !dword_62A0B8 )
    v5 = &byte_629120;
  v6 = *(const char **)dword_62A068;
  if ( !*(_DWORD *)dword_62A068 )
    v6 = &byte_629120;
  sprintf(Buffer, "%s%s%s", v6, v5, Str);
  v4 = fopen(Buffer, aR);
  if ( v4 )
    goto LABEL_13;
  v7 = *(const char **)dword_62A068;
  if ( !*(_DWORD *)dword_62A068 )
    v7 = &byte_629120;
  sprintf(Buffer, "%scommon\\%s", v7, Str);
  v4 = fopen(Buffer, aR);
  if ( v4 )
  {
LABEL_13:
    fclose(v4);
    sub_578600(Buffer);
    return 0;
  }
  else
  {
    if ( dword_75CBA8 != 5 )
    {
      if ( (unsigned __int8)sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_18, 724) )
        sub_500FE0((int)&unk_7D7920, aCouldNotFindS, (char)Str);
    }
    return -1;
  }
}
