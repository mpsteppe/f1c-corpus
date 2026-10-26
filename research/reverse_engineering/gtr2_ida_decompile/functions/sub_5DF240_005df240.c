int __thiscall sub_5DF240(
        int this,
        char *String2,
        char *String,
        char *a4,
        char *a5,
        char *a6,
        char *a7,
        char *a8,
        char *a9,
        char *a10)
{
  int v11; // edi
  int v12; // edx
  int v13; // ecx
  char v14; // al
  int v15; // eax
  const char *v16; // eax
  const char *v17; // eax
  const char *v18; // eax
  const char *v19; // eax
  const char *v20; // eax
  const char *v21; // eax
  const char *v22; // eax
  const char *v23; // eax

  v11 = 0;
  v12 = 0;
  if ( !*(_BYTE *)(this + 12) )
    goto LABEL_8;
  v13 = this + 12;
  do
  {
    v14 = *(_BYTE *)++v13;
    if ( v14 == 61 )
      ++v12;
  }
  while ( v14 );
  if ( v12 == 1 )
    v15 = sub_5DEF00((_DWORD *)this, String2);
  else
LABEL_8:
    v15 = sub_5DEF70();
  if ( !v15 )
    return 0;
  strcpy((char *)(this + 1036), *(const char **)(this + 2060));
  v16 = (const char *)sub_6331DF(this + 1036, &unk_72B858);
  if ( v16 )
  {
    v11 = 1;
    sub_5DF010(v16, String);
    v17 = (const char *)sub_6331DF(0, ",");
    if ( v17 )
    {
      v11 = 2;
      sub_5DF010(v17, a4);
      v18 = (const char *)sub_6331DF(0, ",");
      if ( v18 )
      {
        v11 = 3;
        sub_5DF010(v18, a5);
        v19 = (const char *)sub_6331DF(0, ",");
        if ( v19 )
        {
          v11 = 4;
          sub_5DF010(v19, a6);
          v20 = (const char *)sub_6331DF(0, ",");
          if ( v20 )
          {
            v11 = 5;
            sub_5DF010(v20, a7);
            v21 = (const char *)sub_6331DF(0, ",");
            if ( v21 )
            {
              v11 = 6;
              sub_5DF010(v21, a8);
              v22 = (const char *)sub_6331DF(0, ",");
              if ( v22 )
              {
                v11 = 7;
                sub_5DF010(v22, a9);
                v23 = (const char *)sub_6331DF(0, ",");
                if ( v23 )
                {
                  v11 = 8;
                  sub_5DF010(v23, a10);
                }
              }
            }
          }
        }
      }
    }
  }
  return v11;
}
