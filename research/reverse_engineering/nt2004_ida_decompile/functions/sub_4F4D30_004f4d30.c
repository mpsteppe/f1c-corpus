int __thiscall sub_4F4D30(int this, int a2, int a3)
{
  int result; // eax
  float *v5; // ebx
  double v6; // st7
  int v8; // eax
  double v9; // st7
  double v10; // st7
  float v11; // [esp+4h] [ebp-Ch]
  float v12; // [esp+4h] [ebp-Ch]
  float v13; // [esp+4h] [ebp-Ch]
  float v14; // [esp+4h] [ebp-Ch]
  float v15; // [esp+8h] [ebp-8h]
  float v16; // [esp+8h] [ebp-8h]
  float v17; // [esp+8h] [ebp-8h]
  float v18; // [esp+8h] [ebp-8h]
  float v19; // [esp+Ch] [ebp-4h]
  float v20; // [esp+Ch] [ebp-4h]
  float v21; // [esp+Ch] [ebp-4h]
  float v22; // [esp+Ch] [ebp-4h]
  float v23; // [esp+18h] [ebp+8h]
  float v24; // [esp+18h] [ebp+8h]

  result = *(_DWORD *)(this + 96);
  if ( result > 0 )
  {
    v5 = (float *)sub_4F2AE0((_DWORD *)this);
    if ( dword_7D5DA4 == 2 )
      v6 = sub_4D9E20(&dword_7D5DAC);
    else
      v6 = dbl_7DA9D0;
    v5[2] = v6;
    v8 = *(_DWORD *)(this + 4);
    if ( v8 == 8 )
    {
      v5[3] = v6 + *(float *)(this + 48);
      v5[24] = (double)(unsigned __int8)*(_DWORD *)(a3 + 32) * 0.0039370079;
      v23 = (double)(unsigned __int8)*(_DWORD *)(a2 + 32) * 0.0039370079;
      if ( dword_7D5DA4 == 2 )
      {
        if ( sub_4DA080(&dword_7D5DAC) == 5 )
          v9 = 0.0;
        else
          v9 = sub_4D9E30(&dword_7D5DAC);
      }
      else
      {
        v9 = dbl_7DA9C8;
      }
      v10 = v23 - v9 * *(float *)(this + 72);
      if ( v10 >= 0.0 )
      {
        if ( v10 > 1.0 )
          v10 = 1.0;
      }
      else
      {
        v10 = 0.0;
      }
      v5[25] = v10;
      v24 = v10 * 63.5;
      *(_DWORD *)(a2 + 32) = (int)v24;
    }
    else
    {
      if ( v8 == 9 )
        *(_DWORD *)(this + 48) = 0;
      v5[3] = 3.4028235e38;
    }
    v11 = *(float *)a2 + *(float *)(a2 + 12);
    v15 = *(float *)(a2 + 16) + *(float *)(a2 + 4);
    v19 = *(float *)(a2 + 20) + *(float *)(a2 + 8);
    sub_5B0D50(*(_DWORD *)v5, 0, LODWORD(v11), LODWORD(v15), LODWORD(v19), *(_DWORD *)(a2 + 32));
    sub_5B0DB0(*(_DWORD *)v5, 0, *(_DWORD *)(a2 + 28), 0);
    v12 = *(float *)(a3 + 12) + *(float *)a3;
    v16 = *(float *)(a3 + 16) + *(float *)(a3 + 4);
    v20 = *(float *)(a3 + 20) + *(float *)(a3 + 8);
    sub_5B0D50(*(_DWORD *)v5, 1, LODWORD(v12), LODWORD(v16), LODWORD(v20), *(_DWORD *)(a3 + 32));
    sub_5B0DB0(*(_DWORD *)v5, 1, *(_DWORD *)(a3 + 28), 1065353216);
    v13 = *(float *)a3 - *(float *)(a3 + 12);
    v17 = *(float *)(a3 + 4) - *(float *)(a3 + 16);
    v21 = *(float *)(a3 + 8) - *(float *)(a3 + 20);
    sub_5B0D50(*(_DWORD *)v5, 2, LODWORD(v13), LODWORD(v17), LODWORD(v21), *(_DWORD *)(a3 + 32));
    sub_5B0DB0(*(_DWORD *)v5, 2, *(_DWORD *)(a3 + 24), 1065353216);
    v14 = *(float *)a2 - *(float *)(a2 + 12);
    v18 = *(float *)(a2 + 4) - *(float *)(a2 + 16);
    v22 = *(float *)(a2 + 8) - *(float *)(a2 + 20);
    sub_5B0D50(*(_DWORD *)v5, 3, LODWORD(v14), LODWORD(v18), LODWORD(v22), *(_DWORD *)(a2 + 32));
    return sub_5B0DB0(*(_DWORD *)v5, 3, *(_DWORD *)(a2 + 24), 0);
  }
  return result;
}
