int __init_numeric()
{
  LCID v0; // edi
  int v1; // esi
  int v2; // esi
  int v3; // esi
  char v5; // al
  _BYTE *v6; // eax
  _BYTE *v7; // eax
  char v8; // al

  v0 = (unsigned __int16)word_7FF23E;
  if ( dword_7FF1F0 )
  {
    v1 = __getlocaleinfo(1, (unsigned __int16)word_7FF23E, 0xEu, (int)&dword_7FF20C);
    v2 = __getlocaleinfo(1, v0, 0xFu, (int)&dword_7FF210) | v1;
    v3 = __getlocaleinfo(1, v0, 0x10u, (int)&dword_7FF214) | v2;
    fix_grouping(dword_7FF214);
    if ( v3 )
    {
      sub_5C1B88(dword_7FF20C);
      sub_5C1B88(dword_7FF210);
      sub_5C1B88(dword_7FF214);
      dword_7FF20C = 0;
      dword_7FF210 = 0;
      dword_7FF214 = 0;
      return -1;
    }
    if ( *off_628760 != &unk_628728 )
    {
      sub_5C1B88(*off_628760);
      sub_5C1B88(off_628760[1]);
      sub_5C1B88(off_628760[2]);
    }
    *off_628760 = dword_7FF20C;
    off_628760[1] = dword_7FF210;
    off_628760[2] = dword_7FF214;
    v5 = *(_BYTE *)*off_628760;
    dword_625894 = 1;
    byte_625890 = v5;
  }
  else
  {
    sub_5C1B88(dword_7FF20C);
    sub_5C1B88(dword_7FF210);
    sub_5C1B88(dword_7FF214);
    dword_7FF20C = 0;
    dword_7FF210 = 0;
    dword_7FF214 = 0;
    *off_628760 = malloc(2u);
    if ( !*off_628760 )
      return -1;
    strcpy((char *)*off_628760, word_5FC804);
    off_628760[1] = malloc(2u);
    v6 = off_628760[1];
    if ( !v6 )
      return -1;
    *v6 = 0;
    off_628760[2] = malloc(2u);
    v7 = off_628760[2];
    if ( !v7 )
      return -1;
    *v7 = 0;
    v8 = *(_BYTE *)*off_628760;
    dword_625894 = 1;
    byte_625890 = v8;
  }
  return 0;
}
