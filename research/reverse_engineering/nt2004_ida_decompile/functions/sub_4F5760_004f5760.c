int __stdcall sub_4F5760(char *a1, char *String2, float *a3, int a4)
{
  int v4; // ebp
  int v6; // edi
  char String[128]; // [esp+10h] [ebp-80h] BYREF

  v4 = sub_577ED0(a1, String2, String, 0);
  if ( !v4 )
    return v4;
  if ( String[0] >= 48 && String[0] <= 57 || String[0] == 46 )
  {
    *a3 = atof(String);
    return v4;
  }
  v6 = a4;
  if ( a4 )
  {
    while ( strcmp(String, (const char *)v6) )
    {
      v6 = *(_DWORD *)(v6 + 36);
      if ( !v6 )
        goto LABEL_10;
    }
    *a3 = *(float *)(v6 + 32);
    return v4;
  }
  else
  {
LABEL_10:
    if ( (unsigned __int8)sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_20, 2483) )
      sub_500FE0((int)&unk_7D7920, aCouldNotFindTr, (char)String);
    return 0;
  }
}
