int sub_4A2650()
{
  char *v1; // [esp+8h] [ebp-8Ch]
  char *v2; // [esp+8h] [ebp-8Ch]
  float v3; // [esp+10h] [ebp-84h]
  char v4; // [esp+14h] [ebp-80h] BYREF
  int v5; // [esp+15h] [ebp-7Fh]
  int v6; // [esp+19h] [ebp-7Bh]
  int v7; // [esp+1Dh] [ebp-77h]
  int v8; // [esp+21h] [ebp-73h]
  int v9; // [esp+25h] [ebp-6Fh]
  int v10; // [esp+29h] [ebp-6Bh]
  int v11; // [esp+2Dh] [ebp-67h]
  __int16 v12; // [esp+31h] [ebp-63h]
  char v13; // [esp+33h] [ebp-61h]
  char Buffer[32]; // [esp+34h] [ebp-60h] BYREF
  char v15[64]; // [esp+54h] [ebp-40h] BYREF

  v5 = 0;
  v6 = 0;
  v7 = 0;
  v8 = 0;
  v9 = 0;
  v10 = 0;
  v11 = 0;
  v12 = 0;
  v13 = 0;
  v4 = 0;
  if ( (flt_FB1F28 + flt_FB1F24) * 0.5 > 0.050000001 )
  {
    if ( sub_41F7F0((int)off_6FE418, (int)Buffer) && sub_41F7F0((int)"Wet Compound", (int)Buffer) )
      sprintf(Buffer, off_6FE418);
    sprintf(&v4, " (%s)", Buffer);
  }
  v3 = flt_FB1F30;
  if ( dword_B72454 )
  {
    v2 = sub_41D840(&byte_91CC38, "F.");
    sprintf(v15, "%d %s", (unsigned int)(unsigned __int64)((v3 - -40.0) * 1.8 - 40.0 + 0.5), v2);
  }
  else
  {
    v1 = sub_41D840(&byte_91CC38, "C.");
    sprintf(v15, "%d %s", (unsigned int)(unsigned __int64)(v3 + 0.5), v1);
  }
  sub_4CE020(v15);
  return 0;
}
