char *__thiscall sub_4CE010(char *this, char *Destination, int a3)
{
  const char *v4; // eax
  char *result; // eax
  char *v6; // eax
  char *v7; // edx
  char v8; // cl
  char *v9; // esi
  char Source[256]; // [esp+Ch] [ebp-100h] BYREF

  v4 = (const char *)sub_465880(dword_764D70);
  if ( v4 )
  {
    result = strncpy(Destination, v4, a3 - 1);
    Destination[a3 - 1] = 0;
  }
  else
  {
    *Destination = 0;
    v6 = sub_4CE000(this);
    v7 = (char *)(Source - v6);
    do
    {
      v8 = *v6;
      v6[(_DWORD)v7] = *v6;
      ++v6;
    }
    while ( v8 );
    v9 = &Source[strlen(Source)];
    if ( v9 > Source )
    {
      while ( *v9 != 92 )
      {
        if ( --v9 <= Source )
          goto LABEL_10;
      }
      ++v9;
    }
LABEL_10:
    result = (char *)sub_579060(v9, aPlr);
    if ( result )
      *result = 0;
    if ( v9 )
    {
      result = strncpy(Destination, v9, a3 - 1);
      Destination[a3 - 1] = 0;
    }
  }
  return result;
}
