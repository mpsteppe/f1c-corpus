int __stdcall sub_4B35A0(char *Buffer, int a2)
{
  char *v2; // esi
  char *v3; // ecx
  int v4; // eax

  v2 = strcpy(Buffer, asc_609460);
  if ( dword_768498 )
  {
    v4 = sub_4FA870(0);
    if ( v4 == 255 )
      return 0;
    v3 = (char *)&unk_62BF68 + 25304 * v4;
  }
  else
  {
    v3 = (char *)dword_75AAC4;
  }
  if ( v3 && *(float *)&v3[4 * *(_DWORD *)(dword_75AAC4 + 20852) + 20972] > 0.0 )
  {
    sprintf(v2, off_5FD810, v3 + 24972);
    _strupr(v2);
  }
  return 0;
}
