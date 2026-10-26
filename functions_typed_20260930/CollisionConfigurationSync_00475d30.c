void sub_475D30()
{
  float v0; // [esp+0h] [ebp-24h]
  int v1; // [esp+1Ch] [ebp-8h] BYREF
  int v2; // [esp+20h] [ebp-4h] BYREF

  if ( dword_7CD614 != dword_7CE250 )
  {
    dword_7CD614 = dword_7CE250;
    ShortComputation_5bd0((float *)&ppvOut);
    v0 = dbl_8AFE90;
    sub_454DA0((int)&ppvOut, v0, &flt_7CD458, &flt_7CD45C, &flt_7CD2B0, &v2, &flt_7CD610, &v1);
  }
}

