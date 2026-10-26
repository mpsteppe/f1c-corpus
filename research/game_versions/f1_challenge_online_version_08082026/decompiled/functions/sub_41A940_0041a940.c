void __stdcall sub_41A940(int a1, const char *a2)
{
  int v2; // esi
  float v3[8]; // [esp+Ch] [ebp-20h] BYREF

  if ( dword_7D0308 && flt_7CF3C8 != 0.0 && a1 )
  {
    if ( dword_7C54E8 && dword_7C54E8 == a1 )
    {
      if ( a2 && !strcmp(aIgnoredStopGoP, a2) )
      {
        v2 = 149;
LABEL_12:
        sub_4144D0(v3);
        sub_4144F0(v3, v2, *(_DWORD *)(a1 + 18588), -1, -1, -1, -2.0, -2.0);
        sub_418560(flt_5EA618, v3);
      }
    }
    else if ( a2 && !strcmp(aIgnoredStopGoP, a2) )
    {
      v2 = 243;
      goto LABEL_12;
    }
  }
}
