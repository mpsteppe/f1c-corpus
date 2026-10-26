char __stdcall sub_4EB370(char *Source, char *a2, char *a3)
{
  char *v3; // ebp
  char *v4; // esi
  int v5; // eax
  char v6; // bl
  _BYTE v8[28]; // [esp+14h] [ebp-434h] BYREF
  char v9[256]; // [esp+30h] [ebp-418h] BYREF
  char String[384]; // [esp+130h] [ebp-318h] BYREF
  int v11; // [esp+2B0h] [ebp-198h]
  char v12; // [esp+2B4h] [ebp-194h]
  int v13; // [esp+2BCh] [ebp-18Ch]
  int v14; // [esp+2C0h] [ebp-188h]
  int v15; // [esp+2C4h] [ebp-184h]
  char Buffer[384]; // [esp+2C8h] [ebp-180h] BYREF

  sub_57A080(v8);
  v3 = strcpy(a2, &byte_629120);
  v4 = strcpy(a3, &byte_629120);
  if ( (unsigned __int8)sub_57A2F0(Source, 1) )
  {
    memset(Buffer, 0, sizeof(Buffer));
    v9[0] = byte_629120;
    memset(&v9[1], 0, 255);
    v11 = 0;
    v15 = 0;
    v13 = 0;
    v14 = 0;
    v12 = 1;
    while ( sub_57A490(Buffer, 383) )
    {
      v5 = sub_577B60(String);
      if ( v5 )
      {
        if ( v5 == 2 || v5 == 4 )
          break;
      }
      else if ( sub_577E50(String, aSkin, (int)v9) )
      {
        strcpy(v4, v9);
      }
      else if ( sub_577E50(String, aModel, (int)v9) )
      {
        strcpy(v3, v9);
      }
    }
    sub_57A360(v8);
  }
  if ( !strlen(v3) || (v6 = 1, !strlen(v4)) )
    v6 = 0;
  sub_57A0A0(v8);
  return v6;
}
