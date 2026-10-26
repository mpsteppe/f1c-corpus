int __thiscall sub_4A2A30(_BYTE *this)
{
  double v2; // st6
  double v4; // st7
  double v5; // st7
  char *v6; // eax
  int v7; // esi
  char *v8; // eax
  int v9; // [esp+10h] [ebp-88h] BYREF
  int v10; // [esp+14h] [ebp-84h] BYREF
  char Buffer[126]; // [esp+18h] [ebp-80h] BYREF
  __int16 v12; // [esp+96h] [ebp-2h]

  strcpy(Buffer, "--:--");
  memset(&Buffer[6], 0, 0x78u);
  v12 = 0;
  this[280] = 0;
  if ( !*(_DWORD *)dword_B640C8 )
    goto LABEL_28;
  if ( *(_DWORD *)dword_B640C8 != 6 )
  {
    if ( byte_B6413C )
    {
      strcpy(Buffer, sub_41D840(&byte_91CC38, "Paused"));
    }
    else
    {
      v2 = flt_FADE20 - dbl_FB1D18;
      *(float *)&v9 = v2;
      if ( v2 > 0.0 && flt_FADE1C < dbl_FB1D18 )
      {
        sub_4E42B0(*(float *)&v9, (int)&v10, (int)&v9);
        sprintf(Buffer, "%.2d:%.2d", v10, (unsigned int)(unsigned __int64)*(float *)&v9);
        sub_4CE020(Buffer);
        return 0;
      }
      if ( *(float *)&v9 <= 0.0 )
      {
        strcpy(Buffer, "00:00");
        sub_4CE020(Buffer);
        return 0;
      }
    }
    goto LABEL_28;
  }
  if ( !(unsigned __int8)sub_4735A0() )
  {
    if ( !byte_B722E4 )
    {
      if ( dword_FADE18 > 1 )
        goto LABEL_20;
      goto LABEL_21;
    }
    goto LABEL_27;
  }
  if ( dword_B64134 )
  {
    if ( dword_B64134 != 4 )
      goto LABEL_18;
    v4 = 122.5 - dbl_FB1D18;
  }
  else
  {
    v4 = flt_FADE1C - dbl_FB1D18;
  }
  if ( v4 >= 0.0 )
  {
    v5 = v4 + 1.0;
    *(float *)&v9 = v5;
    sprintf(
      Buffer,
      "%02d:%02d",
      (unsigned int)(unsigned __int64)(v5 * 0.016666668),
      (unsigned int)(unsigned __int64)(*(float *)&v9 - (double)(int)(unsigned __int64)(v5 * 0.016666668) * 60.0));
    if ( *(float *)&v9 < 11.0 )
    {
      this[280] = 1;
      sub_4CE020(Buffer);
      return 0;
    }
    goto LABEL_28;
  }
LABEL_18:
  if ( !byte_B722E4 )
  {
    if ( dword_FADE18 > 1 )
    {
LABEL_20:
      v6 = sub_41D840(&byte_91CC38, "laps");
LABEL_22:
      v7 = dword_FADE18;
      v8 = sub_41D840(&byte_91CC38, v6);
      sprintf(Buffer, "%d %s", v7, v8);
      sub_4CE020(Buffer);
      return 0;
    }
LABEL_21:
    v6 = sub_41D840(&byte_91CC38, (const char *)&off_6F3FC4);
    goto LABEL_22;
  }
LABEL_27:
  sprintf(Buffer, WindowName);
LABEL_28:
  sub_4CE020(Buffer);
  return 0;
}
