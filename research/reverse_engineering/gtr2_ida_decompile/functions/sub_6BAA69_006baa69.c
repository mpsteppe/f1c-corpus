void __stdcall sub_6BAA69(int a1, int a2, unsigned int a3)
{
  int v3; // esi
  int v4; // eax
  int v5; // edi
  int v6; // eax
  int v7; // eax
  double v8; // st7

  v3 = a1;
  v4 = *(_DWORD *)(a1 + 88);
  v5 = a2;
  if ( (v4 & 1) == 0 )
    sub_679F05(a1, (int)"Missing IHDR before gAMA");
  if ( (v4 & 4) != 0 )
  {
    sub_679F26(a1, (int)"Invalid gAMA after IDAT");
    goto LABEL_5;
  }
  if ( (v4 & 2) != 0 )
  {
    sub_679F26(a1, (int)"Out of place gAMA chunk");
  }
  else if ( a2 )
  {
    v6 = *(_DWORD *)(a2 + 8);
    if ( (v6 & 1) != 0 && (v6 & 0x800) == 0 )
    {
      sub_679F26(a1, (int)"Duplicate gAMA chunk");
      goto LABEL_5;
    }
  }
  if ( a3 != 4 )
  {
    sub_679F26(v3, (int)"Incorrect gAMA chunk length");
LABEL_5:
    sub_6BA69B(v3, a3);
    return;
  }
  sub_6B9DC1(v3, (int)&a1, 4);
  if ( !sub_6BA69B(v3, 0) )
  {
    v7 = sub_6B9D7D((unsigned __int8 *)&a1);
    if ( v7 )
    {
      if ( (*(_DWORD *)(v5 + 8) & 0x800) != 0 && (a3 = v7, fabs((double)(unsigned int)v7 - 45455.0) > 500.0) )
      {
        sub_679F26(v3, (int)"Ignoring incorrect gAMA value when sRGB is also present");
      }
      else
      {
        a3 = v7;
        v8 = (double)(unsigned int)v7 * 0.0000099999997;
        *(float *)(v3 + 304) = v8;
        sub_67A883(v3, v5, v8);
      }
    }
  }
}
