int __stdcall sub_4B3160(char *Buffer, int a2)
{
  int v2; // eax
  double v3; // st7
  int v5; // [esp+Ch] [ebp-8h] BYREF
  int v6; // [esp+10h] [ebp-4h] BYREF

  v2 = *(_DWORD *)(dword_75AAC4 + 20848);
  if ( v2 <= 0 || (v3 = sub_4DD0C0(v2 - 1), *(float *)&v5 = v3, v3 <= 0.0) )
  {
    strcpy(Buffer, asc_601524);
    return 1;
  }
  else
  {
    sub_4B2BD0(*(float *)&v5, &v6, (float *)&v5);
    sprintf(Buffer, "%.2d:%06.3f", v6, *(float *)&v5);
    return 0;
  }
}
