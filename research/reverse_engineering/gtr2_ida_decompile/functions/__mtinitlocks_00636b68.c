int _mtinitlocks()
{
  int v0; // esi
  char *v1; // edi

  v0 = 0;
  v1 = (char *)&unk_FB8200;
  while ( 1 )
  {
    if ( dword_912CB4[2 * v0] == 1 )
    {
      dword_912CB0[2 * v0] = (int)v1;
      v1 += 24;
      if ( !__crtInitCritSecAndSpinCount(dword_912CB0[2 * v0], 4000) )
        break;
    }
    if ( ++v0 >= 36 )
      return 1;
  }
  dword_912CB0[2 * v0] = 0;
  return 0;
}
