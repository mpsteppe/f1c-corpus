int __stdcall sub_4E5370(char *Buffer, int a2)
{
  double v3; // st7
  int v4; // eax
  char *Buffera; // [esp+14h] [ebp+4h]

  strcpy(Buffer, " -:--.-");
  if ( (byte_B71DC8 & 1) != 0 || *(_DWORD *)dword_B72314 == 7 || *(_DWORD *)dword_B72314 == 8 )
  {
    v4 = sub_5511F0(&unk_FADD40, 0);
    if ( v4 == 255 )
      return 0;
    v3 = *(float *)&dword_925098[5654 * v4];
  }
  else
  {
    v3 = *((float *)dword_91E07C + 4862);
  }
  if ( v3 > 0.0 )
  {
    Buffera = (char *)(unsigned __int64)((double)(int)(unsigned __int64)v3 * 0.016666668);
    sprintf(Buffer, " %.1d:%04.1f", Buffera, v3 - (double)(int)Buffera * 60.0);
    return 0;
  }
  return 0;
}
