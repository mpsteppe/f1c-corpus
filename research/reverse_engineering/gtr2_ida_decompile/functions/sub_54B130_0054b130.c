char __thiscall sub_54B130(int this, int a2, _DWORD *a3, _DWORD *a4)
{
  char result; // al
  int *v6; // edi
  int v7; // eax
  int v8; // ecx
  int v9; // eax
  double v10; // st7
  double v11; // st7

  result = sub_407400(a2, (int)a3);
  if ( result )
  {
    if ( a3 )
      a3[1] |= 0x20u;
    if ( (int)a3[136] > 0 )
    {
      v6 = (int *)a3[133];
      if ( v6 )
      {
        v7 = *v6;
        if ( *v6 )
        {
          *(_DWORD *)(v7 + 240) = 0;
          *(_DWORD *)(v7 + 244) = 1125515264;
        }
      }
    }
    v8 = a4[1];
    if ( !v8 || !((a4[2] - v8) >> 2) )
      sub_42F9A0(a4);
    sub_4090E0();
    *(_DWORD *)(this + 76) = this;
    **(_DWORD **)(this + 72) = 1058642330;
    v9 = a4[1];
    if ( !v9 || (unsigned int)((a4[2] - v9) >> 2) <= 1 )
      sub_42F9A0(a4);
    sub_4090E0();
    *(_DWORD *)(this + 96) = this;
    v10 = flt_BE0CA4[(unsigned __int8)dword_BE08A0++] * 0.15000001;
    *(float *)(this + 100) = v10 + 0.60000002;
    v11 = flt_BE0CA4[(unsigned __int8)dword_BE08A0++] * 0.15000001;
    *(float *)(this + 104) = v11 + 0.2;
    sub_54B280(this + 60);
    return 1;
  }
  return result;
}
