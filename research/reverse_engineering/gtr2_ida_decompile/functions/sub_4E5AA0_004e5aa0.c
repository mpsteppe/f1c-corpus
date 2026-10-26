int __stdcall sub_4E5AA0(char *a1, int a2)
{
  double v2; // st7
  double v3; // st6
  float v5; // [esp+Ch] [ebp-14h]
  char Buffer[16]; // [esp+10h] [ebp-10h] BYREF

  v2 = *((float *)dword_91E07C + 4299);
  v5 = *((float *)dword_91E07C + 4299);
  v3 = *((float *)dword_91E07C + 3892);
  if ( v3 <= 0.0 )
  {
    strcpy(Buffer, "/-");
  }
  else
  {
    sprintf(Buffer, "/%d", (unsigned int)(unsigned __int64)(v3 * v2));
    v2 = v5;
  }
  if ( dword_B72454 == 1 )
    v2 = v2 * 0.26417205;
  if ( v2 < 99.900002 )
    sprintf(a1, " %.1f%s", v2, Buffer);
  else
    sprintf(a1, " %.0f%s", v2, Buffer);
  return 0;
}
