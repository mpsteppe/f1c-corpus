int __stdcall sub_4B34E0(char *Buffer, int a2)
{
  int v2; // esi
  char *v3; // edi
  double v4; // st7
  int v5; // eax
  int v7; // [esp+14h] [ebp-4h] BYREF

  v2 = *(_DWORD *)(dword_75AAC4 + 20852) + 1;
  if ( *(_DWORD *)(dword_75AAC4 + 20852) == 2 )
    v2 = 0;
  v3 = strcpy(Buffer, asc_601524);
  if ( dword_768498 )
  {
    v5 = sub_4FA870(0);
    if ( v5 == 255 )
      return 0;
    v4 = flt_631154[6326 * v5 + v2];
  }
  else
  {
    v4 = *(float *)(dword_75AAC4 + 4 * v2 + 20972);
  }
  *(float *)&Buffer = v4;
  if ( v4 > 0.0 )
  {
    sub_4B2BD0(*(float *)&Buffer, &v7, (float *)&Buffer);
    sprintf(v3, "%.2d:%06.3f", v7, *(float *)&Buffer);
  }
  return 0;
}
