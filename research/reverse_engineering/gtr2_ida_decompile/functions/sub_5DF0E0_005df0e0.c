int __thiscall sub_5DF0E0(int this, char *EndPtr, char *String, char *a4, int *a5, int *a6, char *a7)
{
  int v8; // edx
  int v9; // ecx
  char v10; // al
  int v11; // eax
  const char *v12; // eax
  const char *v13; // eax
  char *v14; // eax
  int *v15; // esi
  int *v16; // esi
  char *v17; // eax
  char *v18; // esi
  char *v19; // eax
  char *v21; // [esp-8h] [ebp-Ch]
  char *v22; // [esp-8h] [ebp-Ch]

  v8 = 0;
  if ( !*(_BYTE *)(this + 12) )
    goto LABEL_8;
  v9 = this + 12;
  do
  {
    v10 = *(_BYTE *)++v9;
    if ( v10 == 61 )
      ++v8;
  }
  while ( v10 );
  if ( v8 == 1 )
    v11 = sub_5DEF00((_DWORD *)this, EndPtr);
  else
LABEL_8:
    v11 = sub_5DEF70();
  if ( !v11 )
    return 0;
  strcpy((char *)(this + 1036), *(const char **)(this + 2060));
  v12 = (const char *)sub_6331DF(this + 1036, &unk_72B858);
  if ( v12 )
  {
    v21 = String;
    *String = 0;
    sub_5DF010(v12, v21);
    v13 = (const char *)sub_6331DF(0, ",");
    if ( v13 )
    {
      v22 = a4;
      *a4 = 0;
      sub_5DF010(v13, v22);
      v14 = (char *)sub_6331DF(0, ",");
      EndPtr = v14;
      if ( v14 )
      {
        v15 = a5;
        if ( a5 )
        {
          *v15 = strtol(v14, &EndPtr, 10);
          v16 = a6;
          if ( a6 )
            *a6 = 0;
          v17 = (char *)sub_6331DF(0, ",");
          EndPtr = v17;
          if ( v17 && v16 )
          {
            *v16 = strtol(v17, &EndPtr, 10);
            v18 = a7;
            if ( a7 )
              *a7 = 0;
            v19 = (char *)sub_6331DF(0, ",");
            EndPtr = v19;
            if ( v19 )
            {
              if ( v18 )
              {
                *v18 = 0;
                sub_5DF010(v19, v18);
              }
            }
          }
        }
      }
    }
  }
  return 1;
}
