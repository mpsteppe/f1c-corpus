void __stdcall sub_6114C0(char *a1, int a2, int a3, int a4)
{
  int v4; // edx
  int v5; // eax

  v4 = 0;
  if ( a1 )
  {
    v5 = *(_DWORD *)a1;
    if ( (*(_DWORD *)a1 & 1) != 0 )
      v4 = 16;
    if ( (v5 & 4) != 0 )
    {
      if ( (v5 & 8) != 0 )
      {
        sub_60B640(a1, v4 | 0x2000, a2, a3, a4);
        return;
      }
      v4 |= 0x1000u;
    }
    sub_60B640(a1, v4, a2, a3, a4);
  }
}
