int sub_4B67D0()
{
  int v0; // eax
  int v2; // eax

  if ( *(_DWORD *)dword_B72314 == 4 )
  {
    v0 = dword_B71CD4;
    dword_B71CCC = 0;
    if ( dword_B71CD4 > 0 || (v0 = dword_B71CD8, dword_B71CD8 < 0) )
    {
      dword_B71CCC = v0;
      return 0;
    }
  }
  else
  {
    v2 = dword_B71D40;
    dword_B71D38 = 0;
    if ( dword_B71D40 > 0 || (v2 = dword_B71D44, dword_B71D44 < 0) )
      dword_B71D38 = v2;
  }
  return 0;
}
