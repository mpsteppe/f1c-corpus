int __thiscall sub_5DF3F0(
        _DWORD *this,
        char *EndPtr,
        int *a3,
        char *String,
        char *a5,
        char *a6,
        char *a7,
        char *a8,
        char *a9,
        char *a10,
        char *a11)
{
  int *v12; // ebx
  char *v13; // eax
  int v14; // edi
  const char *v15; // eax
  const char *v16; // eax
  const char *v17; // eax
  const char *v18; // eax
  const char *v19; // eax
  const char *v20; // eax
  const char *v21; // eax
  const char *v22; // eax

  if ( !sub_5DEF70() )
    return 0;
  v12 = a3;
  v13 = (char *)(this[515] + 1);
  v14 = 1;
  EndPtr = v13;
  if ( a3 )
  {
    *v12 = strtol(v13, &EndPtr, 10);
    v13 = EndPtr + 1;
  }
  v15 = (const char *)sub_6331DF(v13, ",");
  if ( v15 )
  {
    v14 = 2;
    sub_5DF010(v15, String);
    v16 = (const char *)sub_6331DF(0, ",");
    if ( v16 )
    {
      v14 = 3;
      sub_5DF010(v16, a5);
      v17 = (const char *)sub_6331DF(0, ",");
      if ( v17 )
      {
        v14 = 4;
        sub_5DF010(v17, a6);
        v18 = (const char *)sub_6331DF(0, ",");
        if ( v18 )
        {
          v14 = 5;
          sub_5DF010(v18, a7);
          v19 = (const char *)sub_6331DF(0, ",");
          if ( v19 )
          {
            v14 = 6;
            sub_5DF010(v19, a8);
            v20 = (const char *)sub_6331DF(0, ",");
            if ( v20 )
            {
              v14 = 7;
              sub_5DF010(v20, a9);
              v21 = (const char *)sub_6331DF(0, ",");
              if ( v21 )
              {
                v14 = 8;
                sub_5DF010(v21, a10);
                v22 = (const char *)sub_6331DF(0, ",");
                if ( v22 )
                  sub_5DF010(v22, a11);
              }
            }
          }
        }
      }
    }
  }
  return v14;
}
