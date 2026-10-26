int __stdcall sub_4B3380(char *Buffer, int a2)
{
  char *v2; // edi
  int v3; // esi
  double v4; // st7
  double v5; // st7
  long double v6; // st7
  float v8; // [esp+0h] [ebp-1Ch]
  int v9; // [esp+18h] [ebp-4h] BYREF

  v2 = strcpy(Buffer, asc_601524);
  if ( *(_DWORD *)(dword_75AAC4 + 20952) != 2 )
    return 0;
  v3 = *(_DWORD *)(dword_75AAC4 + 20852);
  v4 = *(float *)(dword_75AAC4 + 4 * v3 + 20972);
  Buffer = *(char **)(dword_75AAC4 + 4 * v3 + 20972);
  if ( v4 <= 0.0 )
    return 0;
  v5 = *(float *)(dword_75AAC4 + 4 * v3 + 20860);
  if ( v5 <= 0.0 )
    return 0;
  v6 = v5 - *(float *)&Buffer;
  v8 = fabs(v6);
  sub_4B2BD0(v8, &v9, (float *)&Buffer);
  if ( v6 < 0.0 )
    sprintf(v2, "-%.2d:%06.3f", v9, *(float *)&Buffer);
  else
    sprintf(v2, "+%.2d:%06.3f", v9, *(float *)&Buffer);
  return 0;
}
