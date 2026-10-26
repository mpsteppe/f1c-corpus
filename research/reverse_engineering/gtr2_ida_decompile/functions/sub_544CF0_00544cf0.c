int __thiscall sub_544CF0(int this, int a2, int a3)
{
  int result; // eax
  int v5; // ebx
  double v6; // st7
  double v8; // st7
  double v9; // st7
  float v10; // [esp+0h] [ebp-20h]
  float v11; // [esp+14h] [ebp-Ch]
  float v12; // [esp+14h] [ebp-Ch]
  float v13; // [esp+14h] [ebp-Ch]
  float v14; // [esp+14h] [ebp-Ch]
  float v15; // [esp+18h] [ebp-8h]
  float v16; // [esp+18h] [ebp-8h]
  float v17; // [esp+18h] [ebp-8h]
  float v18; // [esp+18h] [ebp-8h]
  float v19; // [esp+1Ch] [ebp-4h]
  float v20; // [esp+1Ch] [ebp-4h]
  float v21; // [esp+1Ch] [ebp-4h]
  float v22; // [esp+1Ch] [ebp-4h]
  float v23; // [esp+28h] [ebp+8h]

  result = *(_DWORD *)(this + 96);
  if ( result > 0 )
  {
    v5 = sub_5424A0();
    if ( dword_BE1204 == 2 )
      v6 = sub_5210A0(&dword_BE120C);
    else
      v6 = dbl_FB1D18;
    *(float *)(v5 + 8) = v6;
    if ( *(_DWORD *)(this + 4) == 9 )
    {
      *(float *)(v5 + 12) = v6 + *(float *)(this + 48);
      *(float *)(v5 + 96) = (double)(unsigned __int8)*(_DWORD *)(a3 + 24) * 0.0039370079;
      v23 = (double)(unsigned __int8)*(_DWORD *)(a2 + 24) * 0.0039370079;
      if ( dword_BE1204 == 2 )
      {
        if ( sub_5210D0(&dword_BE120C) == 5 )
          v8 = 0.0;
        else
          v8 = sub_5210C0(&dword_BE120C);
      }
      else
      {
        v8 = dbl_FB1D10;
      }
      v9 = v23 - v8 * *(float *)(this + 72);
      if ( v9 >= 0.0 )
      {
        if ( v9 > 1.0 )
          v9 = 1.0;
      }
      else
      {
        v9 = 0.0;
      }
      *(float *)(v5 + 100) = v9;
      v10 = v9 * 63.5;
      *(_DWORD *)(a2 + 24) = sub_4015C0(v10);
    }
    else
    {
      *(_DWORD *)(v5 + 12) = 2139095039;
    }
    v11 = *(float *)(a2 + 12) + *(float *)a2;
    v15 = *(float *)(a2 + 16) + *(float *)(a2 + 4);
    v19 = *(float *)(a2 + 20) + *(float *)(a2 + 8);
    sub_5FCE00(*(_DWORD *)v5, 0, v11, v15, v19, *(_DWORD *)(a2 + 24));
    v12 = *(float *)(a3 + 12) + *(float *)a3;
    v16 = *(float *)(a3 + 16) + *(float *)(a3 + 4);
    v20 = *(float *)(a3 + 20) + *(float *)(a3 + 8);
    sub_5FCE00(*(_DWORD *)v5, 1, v12, v16, v20, *(_DWORD *)(a3 + 24));
    v13 = *(float *)a3 - *(float *)(a3 + 12);
    v17 = *(float *)(a3 + 4) - *(float *)(a3 + 16);
    v21 = *(float *)(a3 + 8) - *(float *)(a3 + 20);
    sub_5FCE00(*(_DWORD *)v5, 2, v13, v17, v21, *(_DWORD *)(a3 + 24));
    v14 = *(float *)a2 - *(float *)(a2 + 12);
    v18 = *(float *)(a2 + 4) - *(float *)(a2 + 16);
    v22 = *(float *)(a2 + 8) - *(float *)(a2 + 20);
    return sub_5FCE00(*(_DWORD *)v5, 3, v14, v18, v22, *(_DWORD *)(a2 + 24));
  }
  return result;
}
