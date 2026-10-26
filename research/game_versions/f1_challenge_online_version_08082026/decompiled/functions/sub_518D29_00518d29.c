void __cdecl sub_518D29(int a1, unsigned int a2, unsigned int a3)
{
  int v3; // esi
  int v4; // eax
  unsigned int v5; // edi

  v3 = a1;
  v4 = *(_DWORD *)(a1 + 88);
  if ( (v4 & 1) != 0 )
  {
    if ( (v4 & 4) != 0 )
    {
      sub_511887(a1, (int)"Invalid sRGB after IDAT");
      goto LABEL_5;
    }
    if ( (v4 & 2) != 0 )
    {
      sub_511887(a1, (int)"Out of place sRGB chunk");
    }
    else if ( a2 && (*(_BYTE *)(a2 + 9) & 8) != 0 )
    {
      sub_511887(a1, (int)"Duplicate sRGB chunk");
      goto LABEL_5;
    }
  }
  else
  {
    sub_511869(a1, (int)"Missing IHDR before sRGB");
  }
  if ( a3 != 1 )
  {
    sub_511887(v3, (int)"Incorrect sRGB chunk length");
LABEL_5:
    sub_518828(v3, a3);
    return;
  }
  sub_517F58(v3, (int)&a1 + 3, 1);
  if ( !sub_518828(v3, 0) )
  {
    v5 = HIBYTE(a1);
    if ( HIBYTE(a1) < 4u )
    {
      if ( (*(_BYTE *)(a2 + 8) & 1) != 0 && fabs(*(float *)(v3 + 304) * 100000.0 + 0.5 - 45455.0) > 500.0 )
        sub_511887(v3, (int)"Ignoring incorrect gAMA value when sRGB is also present");
      sub_513B51(v3, __SPAIR64__(v5, a2));
    }
    else
    {
      sub_511887(v3, (int)"Unknown sRGB intent");
    }
  }
}
