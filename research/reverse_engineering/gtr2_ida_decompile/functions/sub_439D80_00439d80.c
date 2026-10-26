void __thiscall sub_439D80(double *this)
{
  int i; // edi
  int v2; // eax
  double v3; // st7

  if ( this[1126] > 2.225073858507201e-308 )
  {
    this[1126] = 2.225073858507201e-308;
    unk_B6F348 = 2139095039;
    unk_B6F34C = 2139095039;
    unk_B6F350 = 2139095039;
    unk_B6F354 = 2139095039;
    unk_B6F358 = 2139095039;
    unk_B6F35C = 2139095039;
    unk_B6F360 = 2139095039;
    unk_B6F364 = 2139095039;
    unk_B6F368 = 2139095039;
    unk_B6F36C = 2139095039;
    for ( i = 0; i < 93; ++i )
    {
      v2 = dword_B6F1C8[i];
      if ( v2 )
        (*(void (**)(void))(*(_DWORD *)v2 + 8))();
    }
    v3 = flt_BE08A4[(unsigned __int8)dword_BE08A0++] * 30.0;
    flt_B6F370 = v3 + dbl_FB1D18;
  }
}
