// f1c  0x00518c1e  size=267
void __cdecl sub_518C1E(int a1, int a2, unsigned int a3)
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
  if ( (v4 & 1) != 0 )
  {
    if ( (v4 & 4) != 0 )
    {
      sub_511887(a1, (int)"Invalid gAMA after IDAT");
      goto LABEL_5;
    }
    if ( (v4 & 2) != 0 )
    {
      sub_511887(a1, (int)"Out of place gAMA chunk");
    }
    else if ( a2 )
    {
      v6 = *(_DWORD *)(a2 + 8);
      if ( (v6 & 1) != 0 && (v6 & 0x800) == 0 )
      {
        sub_511887(a1, (int)"Duplicate gAMA chunk");
        goto LABEL_5;
      }
    }
  }
  else
  {
    sub_511869(a1, (int)"Missing IHDR before gAMA");
  }
  if ( a3 != 4 )
  {
    sub_511887(v3, (int)"Incorrect gAMA chunk length");
LABEL_5:
    sub_518828(v3, a3);
    return;
  }
  sub_517F58(v3, (int)&a1, 4);
  if ( !sub_518828(v3, 0) )
  {
    v7 = sub_517F35((unsigned __int8 *)&a1);
    if ( v7 )
    {
      if ( (*(_DWORD *)(v5 + 8) & 0x800) != 0 && fabs((double)(unsigned int)v7 - 45455.0) > 500.0 )
      {
        sub_511887(v3, (int)"Ignoring incorrect gAMA value when sRGB is also present");
      }
      else
      {
        v8 = (double)(unsigned int)v7 * 0.0000099999997;
        *(float *)(v3 + 304) = v8;
        sub_513A56(v3, v5, v8);
      }
    }
  }
}
