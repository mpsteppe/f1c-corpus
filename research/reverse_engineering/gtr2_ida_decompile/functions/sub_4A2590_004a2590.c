int sub_4A2590()
{
  char *v1; // [esp-4h] [ebp-2Ch]
  char *v2; // [esp-4h] [ebp-2Ch]
  float v3; // [esp+4h] [ebp-24h]
  char Buffer[32]; // [esp+8h] [ebp-20h] BYREF

  v3 = flt_FB1F2C;
  Buffer[0] = 0;
  if ( dword_B72454 )
  {
    v2 = sub_41D840(&byte_91CC38, "F.");
    sprintf(Buffer, "%d %s", (unsigned int)(unsigned __int64)((v3 - -40.0) * 1.8 - 40.0 + 0.5), v2);
  }
  else
  {
    v1 = sub_41D840(&byte_91CC38, "C.");
    sprintf(Buffer, "%d %s", (unsigned int)(unsigned __int64)(v3 + 0.5), v1);
  }
  sub_4CE020(Buffer);
  return 0;
}
