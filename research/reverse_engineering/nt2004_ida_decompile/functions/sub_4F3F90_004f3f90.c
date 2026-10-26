void __thiscall sub_4F3F90(int this, float *a2, float a3)
{
  double v5; // st7
  double v6; // st7
  double v7; // st7
  double v8; // st7
  int v9; // ebx
  int v10; // eax
  double v11; // st7
  int v12; // ecx
  double v13; // st7
  double v14; // st7
  float v15; // [esp+10h] [ebp-Ch]
  float v16; // [esp+10h] [ebp-Ch]
  float v17; // [esp+14h] [ebp-8h]
  float v18; // [esp+20h] [ebp+4h]
  float v19; // [esp+24h] [ebp+8h]
  float v20; // [esp+24h] [ebp+8h]

  if ( *(int *)(this + 96) > 0 )
  {
    v5 = flt_7D4054[(unsigned __int8)dword_7D3C50++];
    *a2 = v5 + v5 + *a2;
    v6 = flt_7D4054[(unsigned __int8)dword_7D3C50++];
    a2[2] = v6 + v6 + a2[2];
    if ( dword_7D5DA4 == 2 )
      v7 = sub_4D9E20(&dword_7D5DAC);
    else
      v7 = dbl_7DA9D0;
    v18 = v7;
    sub_4F3E50((float *)this);
    v19 = sqrt(a3);
    if ( dword_7D5DA4 == 2 )
    {
      if ( sub_4DA080(&dword_7D5DAC) == 5 )
        v8 = 0.0;
      else
        v8 = sub_4D9E30(&dword_7D5DAC);
    }
    else
    {
      v8 = dbl_7DA9C8;
    }
    v15 = (double)*(int *)(this + 96) * v8 * v19 * 2.5263157;
    v9 = (int)v15 >> *(_DWORD *)(this + 8);
    v20 = v19 * 0.80000001;
    if ( v9 > 0 )
    {
      do
      {
        v10 = sub_4F2AE0((_DWORD *)this);
        *(float *)(v10 + 8) = v18;
        v17 = v18 + 0.39583334;
        *(float *)(v10 + 12) = v17;
        v11 = flt_7D6FD0[2 * (((_BYTE)dword_7D7420 + 1) & 0x7F)];
        dword_7D7420 = ((_BYTE)dword_7D7420 + 1) & 0x7F;
        v12 = 40 * *(_DWORD *)(v10 + 84) + 8219984;
        *(float *)(v10 + 44) = v11 + *a2;
        *(float *)(v10 + 48) = a2[1] + 8.0;
        v13 = flt_7D6FD4[2 * dword_7D7420] + a2[2];
        *(_DWORD *)(v10 + 56) = 0;
        *(float *)(v10 + 52) = v13;
        *(_DWORD *)(v10 + 60) = *(_DWORD *)(v12 + 12);
        v14 = v20 * *(float *)(v10 + 40);
        *(_DWORD *)(v10 + 64) = 0;
        v16 = v14;
        *(_DWORD *)(v10 + 96) = ((int)v16 << 24) + 0xFFFFFF;
        sub_4F3D10((float *)v10, (float *)(v12 + 16), (float *)(v12 + 28));
        --v9;
      }
      while ( v9 );
    }
  }
}
