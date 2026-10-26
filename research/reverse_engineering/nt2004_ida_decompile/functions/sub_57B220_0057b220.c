char __thiscall sub_57B220(char *Source)
{
  int v1; // ecx
  char v2; // al
  int v3; // esi
  char Destination[8]; // [esp+0h] [ebp-64h] BYREF
  char *String2[23]; // [esp+8h] [ebp-5Ch]

  String2[0] = (char *)&off_61B428;
  String2[1] = (char *)&unk_61B424;
  String2[2] = (char *)&off_61B420;
  String2[3] = aClock;
  String2[4] = aCom1;
  String2[5] = aCom2;
  String2[6] = aCom3;
  String2[7] = aCom4;
  String2[8] = aCom5;
  String2[9] = aCom6;
  String2[10] = aCom7;
  String2[11] = aCom8;
  String2[12] = aCom9;
  String2[13] = aLpt1;
  String2[14] = aLpt2;
  String2[15] = aLpt3;
  String2[16] = aLpt4;
  String2[17] = aLpt5;
  String2[18] = aLpt6;
  String2[19] = aLpt7;
  String2[20] = aLpt8;
  String2[21] = aLpt9;
  String2[22] = (char *)&off_61B384;
  strncpy(Destination, Source, 7u);
  Destination[7] = 0;
  v1 = 0;
  while ( 1 )
  {
    v2 = Destination[v1];
    if ( v2 == 92 || v2 == 47 || v2 == 58 || v2 == 46 )
      break;
    if ( (unsigned int)++v1 >= 8 )
      goto LABEL_9;
  }
  Destination[v1] = 0;
LABEL_9:
  v3 = 0;
  while ( _strcmpi(Destination, String2[v3]) )
  {
    if ( ++v3 >= 23 )
      return 0;
  }
  return 1;
}
