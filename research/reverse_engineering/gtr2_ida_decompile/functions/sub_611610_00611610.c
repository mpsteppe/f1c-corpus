void __stdcall sub_611610(char *a1, int a2, int a3)
{
  int v3; // edx
  int v4; // eax

  v3 = 2048;
  if ( a1 && *((_DWORD *)a1 + 7) )
  {
    v4 = *(_DWORD *)a1;
    if ( (*(_DWORD *)a1 & 1) != 0 )
      v3 = 2064;
    if ( (v4 & 4) != 0 )
    {
      if ( (v4 & 8) != 0 )
      {
        sub_60B970(a1, v3 | 0x2000, a2, a3);
        return;
      }
      v3 |= 0x1000u;
    }
    sub_60B970(a1, v3, a2, a3);
  }
}
