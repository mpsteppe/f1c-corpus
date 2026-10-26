int __stdcall sub_4B30B0(char *Buffer, int a2)
{
  bool v2; // zf
  int v4; // [esp+8h] [ebp-8h] BYREF
  int v5; // [esp+Ch] [ebp-4h] BYREF

  v2 = *(_DWORD *)(dword_75AAC4 + 20952) == 2;
  *(float *)&v4 = dbl_7DA9D0 - *(float *)(dword_75AAC4 + 20956);
  if ( !v2
    || *(float *)&v4 < 0.0
    || *(_DWORD *)(dword_75AAC4 + 20892)
    || *(_BYTE *)(dword_75AAC4 + 20872)
    || dword_75CBB4 <= 3 )
  {
    strcpy(Buffer, asc_601524);
    return 0;
  }
  else
  {
    sub_4B2BD0(*(float *)&v4, &v5, (float *)&v4);
    sprintf(Buffer, "%.2d:%06.3f", v5, *(float *)&v4);
    return 0;
  }
}
