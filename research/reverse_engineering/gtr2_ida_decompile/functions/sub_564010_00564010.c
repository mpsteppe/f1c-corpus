int sub_564010()
{
  int v0; // eax
  char *v1; // eax
  char *v2; // eax
  int v3; // esi
  double v4; // st7
  char Buffer[3]; // [esp+8h] [ebp-8h] BYREF
  char v7; // [esp+Bh] [ebp-5h]
  float v8; // [esp+Ch] [ebp-4h]

  v0 = *((_DWORD *)dword_91E07C + 4330);
  if ( v0 >= 0 )
  {
    if ( v0 )
    {
      sprintf(Buffer, "%d", *((_DWORD *)dword_91E07C + 4330));
    }
    else
    {
      v2 = sub_41D840(&byte_91CC38, "N");
      sub_630FE0(Buffer, v2, 3);
      v7 = 0;
    }
  }
  else
  {
    v1 = sub_41D840(&byte_91CC38, "R");
    sub_630FE0(Buffer, v1, 3);
    v7 = 0;
  }
  if ( dword_B710D4 )
  {
    if ( dword_B710D4 == 1 )
    {
      v3 = 545;
      goto LABEL_12;
    }
    if ( dword_B710D4 == 2 )
    {
      v3 = 1090;
      goto LABEL_12;
    }
  }
  v3 = 0;
LABEL_12:
  sub_562B70((int)Buffer, v3, 910, 16688384, 0, 4, 1.0, 1.0);
  v4 = *((float *)dword_91E07C + 4307) / *((float *)dword_91E07C + 4308);
  v8 = v4;
  if ( v4 > 0.84 )
    sub_562B70((int)";", v3 + 80, 910, (int)dword_FFFF00, 0, 4, 1.0, 1.0);
  if ( v8 > 0.88 )
    sub_562B70((int)";", v3 + 100, 910, (int)dword_FFFF00, 0, 4, 1.0, 1.0);
  if ( v8 > 0.92 )
    sub_562B70((int)";", v3 + 120, 910, (int)sub_FFAA00, 0, 4, 1.0, 1.0);
  if ( v8 > 0.95 )
    sub_562B70((int)";", v3 + 140, 910, (int)sub_FFAA00, 0, 4, 1.0, 1.0);
  if ( v8 > 0.97 )
    sub_562B70((int)";", v3 + 160, 910, (int)dword_FF0000, 0, 4, 1.0, 1.0);
  return 0;
}
