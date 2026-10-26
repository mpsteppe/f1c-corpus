char sub_6177C0()
{
  int v0; // ecx
  char v1; // al
  int v2; // esi
  char String1[8]; // [esp+0h] [ebp-64h] BYREF
  char *String2[23]; // [esp+8h] [ebp-5Ch]

  String2[0] = (char *)&off_72EB80;
  String2[1] = (char *)&off_72EB7C;
  String2[2] = "AUX";
  String2[3] = "CLOCK$";
  String2[4] = "COM1";
  String2[5] = "COM2";
  String2[6] = "COM3";
  String2[7] = "COM4";
  String2[8] = "COM5";
  String2[9] = "COM6";
  String2[10] = "COM7";
  String2[11] = "COM8";
  String2[12] = "COM9";
  String2[13] = "LPT1";
  String2[14] = "LPT2";
  String2[15] = "LPT3";
  String2[16] = "LPT4";
  String2[17] = "LPT5";
  String2[18] = "LPT6";
  String2[19] = "LPT7";
  String2[20] = "LPT8";
  String2[21] = "LPT9";
  String2[22] = (char *)&off_72EAE0;
  sub_630FE0(String1);
  String1[7] = 0;
  v0 = 0;
  while ( 1 )
  {
    v1 = String1[v0];
    if ( v1 == 92 || v1 == 47 || v1 == 58 || v1 == 46 )
      break;
    if ( (unsigned int)++v0 >= 8 )
      goto LABEL_9;
  }
  String1[v0] = 0;
LABEL_9:
  v2 = 0;
  while ( _stricmp(String1, String2[v2]) )
  {
    if ( ++v2 >= 23 )
      return 0;
  }
  return 1;
}
