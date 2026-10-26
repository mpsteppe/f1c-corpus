char __fastcall sub_468300(char *Source, int a2)
{
  unsigned int v3; // kr04_4
  size_t v5; // esi
  float v7; // [esp+0h] [ebp-E8h]
  _BYTE v8[8]; // [esp+18h] [ebp-D0h] BYREF
  char Destination[200]; // [esp+20h] [ebp-C8h] BYREF

  v3 = strlen(Source) + 1;
  v5 = v3 - 1;
  if ( (int)(v3 - 1) >= 0 )
  {
    if ( (int)(v3 - 1) > 127 )
      v5 = 127;
  }
  else
  {
    v5 = 0;
  }
  v7 = dbl_7DA9D0;
  sub_4D0D00(4, 6, v5, 0, LODWORD(v7), 3);
  strncpy(Destination, Source, v5);
  Destination[v5] = 0;
  return sub_463A40(dword_764D70, (int)v8, 0, a2, -1);
}
