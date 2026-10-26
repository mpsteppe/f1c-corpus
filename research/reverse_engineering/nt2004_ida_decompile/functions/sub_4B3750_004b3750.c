int __stdcall sub_4B3750(char *Buffer, int a2)
{
  int v2; // edi
  char *v3; // ebx
  double v4; // st7
  int v6; // [esp+14h] [ebp-4h] BYREF

  v2 = *(_DWORD *)(dword_75AAC4 + 20852) + 1;
  if ( *(_DWORD *)(dword_75AAC4 + 20852) == 2 )
    v2 = 0;
  v3 = strcpy(Buffer, asc_601524);
  v4 = *(float *)(dword_75AAC4 + 4 * v2 + 20972);
  Buffer = *(char **)(dword_75AAC4 + 4 * v2 + 20972);
  if ( v4 > 0.0 )
  {
    sub_4B2BD0(*(float *)&Buffer, &v6, (float *)&Buffer);
    sprintf(v3, "%.2d:%06.3f", v6, *(float *)&Buffer);
  }
  return 0;
}
