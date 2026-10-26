int __stdcall sub_4B3270(char *Buffer, int a2)
{
  char *v2; // edi
  double v3; // st7
  int v4; // eax
  int v6; // [esp+10h] [ebp-4h] BYREF

  v2 = strcpy(Buffer, asc_601524);
  if ( dword_768498 )
  {
    v4 = sub_4FA870(0);
    if ( v4 == 255 )
      return 0;
    v3 = flt_631154[6326 * v4];
  }
  else
  {
    v3 = *(float *)(dword_75AAC4 + 20972);
  }
  *(float *)&Buffer = v3;
  if ( v3 > 0.0 )
  {
    sub_4B2BD0(*(float *)&Buffer, &v6, (float *)&Buffer);
    sprintf(v2, "%.2d:%06.3f", v6, *(float *)&Buffer);
  }
  return 0;
}
