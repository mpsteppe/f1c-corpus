char __thiscall sub_572690(int this, float a2)
{
  double v3; // st7
  int v4; // edi
  int v5; // ecx
  _DWORD *v6; // ecx
  double v7; // st7
  double v8; // st7
  int v9; // eax
  int v10; // ebx
  int *v11; // edi
  int *v12; // ebp
  _BYTE *v13; // eax
  int v14; // ecx
  int v16; // [esp+10h] [ebp-14h]
  int v17; // [esp+10h] [ebp-14h]
  float v18; // [esp+28h] [ebp+4h]

  *(_BYTE *)(this + 3056) = 0;
  sub_41F350();
  sub_41F350();
  v3 = flt_BE08A4[(unsigned __int8)dword_BE08A0++] * 0.14;
  *(_BYTE *)(this + 3061) = 0;
  *(_BYTE *)(this + 3062) = 0;
  *(float *)(this + 2980) = v3 + 0.0099999998;
  sub_572420();
  if ( LOBYTE(a2) )
  {
    sub_570D10();
  }
  else if ( *(_DWORD *)(*(_DWORD *)this + 14820) <= 1u )
  {
    v4 = off_9034A4;
    if ( dword_82F4A0 < 1023 )
    {
      ++dword_82F4A0;
      off_9034A4 += 848;
    }
    *(float *)&v16 = dbl_FB1D18;
    sub_51B2A0((_DWORD *)v4, 2, 8, 4, *(_DWORD *)(*(_DWORD *)this + 22468), v16, 0);
    *(float *)(v4 + 8) = dbl_FB1D18;
  }
  v17 = *(_DWORD *)(this + 3040);
  *(_BYTE *)(this + 3049) = 1;
  *(_BYTE *)(this + 3050) = 1;
  sub_56AE80((_DWORD *)this, v17, 1);
  v5 = *(_DWORD *)(this + 3052);
  *(_BYTE *)(this + 3072) = 0;
  if ( v5 != 1065353216 )
  {
    v6 = *(_DWORD **)(this + 8);
    v7 = 1.0 / *(float *)(this + 3052);
    *(_DWORD *)(this + 3052) = 1065353216;
    v18 = v7;
    sub_56FC30(v6, v18, 1);
  }
  *(_DWORD *)(this + 2956) = 0;
  *(_DWORD *)(this + 2960) = 0;
  *(_DWORD *)(this + 2964) = 0;
  *(_DWORD *)(this + 2968) = 0;
  *(_DWORD *)(this + 2972) = 0;
  *(_WORD *)(this + 2976) = 0;
  *(_DWORD *)(this + 3064) = -1;
  *(_DWORD *)(this + 3080) = -1;
  *(_DWORD *)(this + 3084) = -8388609;
  if ( flt_B71020 >= 1.0 )
    v8 = flt_B71020;
  else
    v8 = 1.0;
  v9 = *(_DWORD *)(this + 2452);
  *(float *)(this + 3088) = 32.0 / v8;
  if ( v9 )
  {
    v10 = 0;
    if ( *(int *)(this + 2500) > 0 )
    {
      v11 = (int *)(this + 2504);
      v12 = (int *)(this + 2516);
      do
      {
        sub_5F1530(*v11, *v12, 1065353216);
        ++v10;
        ++v11;
        v12 += 4;
      }
      while ( v10 < *(_DWORD *)(this + 2500) );
    }
  }
  if ( *(_DWORD *)(this + 2552) )
    sub_54DF00();
  LOBYTE(v13) = *(_BYTE *)(this + 3092);
  if ( (_BYTE)v13 )
  {
    *(_BYTE *)(this + 3092) = 0;
    v13 = (_BYTE *)(this + 3096);
    v14 = 25;
    do
    {
      *v13 = 0;
      v13 += 28;
      --v14;
    }
    while ( v14 );
  }
  return (char)v13;
}
