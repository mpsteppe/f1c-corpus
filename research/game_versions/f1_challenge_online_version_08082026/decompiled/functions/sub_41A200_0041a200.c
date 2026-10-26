void __stdcall sub_41A200(_DWORD *a1)
{
  int v1; // eax
  bool v2; // zf
  int v3; // eax
  float v4[8]; // [esp+0h] [ebp-20h] BYREF

  if ( dword_7D0308 && flt_7CF3C8 != 0.0 && dword_7C56A8 != 8 && *(_DWORD *)(dword_7C54E8 + 18580) == a1[4645] )
  {
    if ( a1[3348] == 1 )
    {
      v1 = a1[4112];
      if ( v1 == 2 || (v2 = v1 == -1, v3 = 42, v2) )
        v3 = 52;
      sub_4144F0(v4, v3, -1, -1, -1, -1, -2.0, -2.0);
      sub_418560(flt_5EA618, v4);
    }
    else
    {
      sub_418A20(flt_5EA618, 42);
    }
  }
}
