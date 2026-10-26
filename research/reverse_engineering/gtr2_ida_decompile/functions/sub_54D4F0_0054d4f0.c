int __thiscall sub_54D4F0(int this, float a2)
{
  int result; // eax
  double v4; // st7
  long double v5; // st6
  double v6; // st7
  double v7; // st6
  double v8; // st7
  double v9; // st5
  float *v10; // esi
  float v11; // [esp+0h] [ebp-14h]
  float v12; // [esp+10h] [ebp-4h]

  result = *(_DWORD *)(this + 64);
  if ( !*(_BYTE *)(result + 82) && !*(_BYTE *)(result + 81) )
  {
    v4 = a2 + *(float *)(this + 228);
    *(float *)(this + 228) = v4;
    if ( v4 > 0.30000001 )
    {
      v5 = *(float *)(this + 12);
      v6 = flt_BE08A4[(unsigned __int8)dword_BE08A0++];
      v11 = fabs(v5) * 0.14999998 + v6 * 0.050000001 + 0.30000001;
      sub_5BC080(*(_DWORD *)(*(_DWORD *)(this + 48) + 8), *(_DWORD *)(this + 64), LODWORD(v11));
    }
    result = *(_DWORD *)(this + 68);
    if ( result )
    {
      v7 = *(float *)(this + 244);
      v8 = *(float *)(this + 248);
      v9 = *(float *)(this + 228) * 0.33333331 + *(float *)(this + 252);
      v10 = (float *)(*(_DWORD *)(this + 72) + 12);
      v12 = v9;
      v10[2] = v12;
      *v10 = v7;
      v10[1] = v8;
    }
  }
  return result;
}
