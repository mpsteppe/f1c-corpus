void __thiscall sub_42CC80(int this)
{
  int v2; // eax
  double v3; // st7
  int v4; // ecx
  int v5; // edx
  double v6; // st6
  int v7; // ecx
  int v8; // ecx
  int v9; // eax
  double v10; // st7
  int v11; // edx
  long double v12; // st7
  int v13; // ecx
  double v14; // st7
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // eax
  unsigned int v21; // eax
  bool v22; // cl
  float v23; // [esp+0h] [ebp-14h]
  float v24; // [esp+0h] [ebp-14h]
  float v25; // [esp+0h] [ebp-14h]
  float v26; // [esp+10h] [ebp-4h]

  v2 = *(_DWORD *)(this + 23644);
  v3 = *(float *)(this + 23676);
  v4 = *(_DWORD *)(this + 23648);
  *(float *)(this + 23644) = v3;
  v5 = *(_DWORD *)(this + 23828);
  v6 = *(float *)(this + 23680) - 2.0;
  *(_DWORD *)(this + 23656) = v4;
  v7 = *(_DWORD *)(this + 21892);
  *(_DWORD *)(this + 23652) = v2;
  *(float *)(this + 23648) = v6;
  *(float *)(this + 23636) = v3 - *(float *)(this + 23716);
  *(float *)(this + 23640) = v6 - *(float *)(this + 23716);
  if ( v7 == *(_DWORD *)(*(_DWORD *)(this + 4 * v5 + 23432) + 328) )
  {
    sub_427C20(this, *(float *)(this + 23696), 1);
    sub_427B90(v8, *(float *)(this + 23692), 1);
  }
  if ( *(_DWORD *)(this + 24024) == 19 )
  {
    v23 = sub_529A00(0) + 0.5;
    sub_427B90(this, v23, 0);
  }
  if ( *(float *)(this + 24732) >= (double)*(float *)(this + 24736) )
  {
    v21 = *(_DWORD *)(this + 24020);
    *(_BYTE *)(this + 57) = 0;
    if ( v21 >= 2 && (*(_DWORD *)(this + 19804) != 2 || *(float *)(this + 18792) < 0.001) )
    {
      v22 = 0;
      if ( *(float *)(this + 23728) < 0.0 )
        v22 = *(float *)(this + 23728) + 2.0 > *(float *)(this + 23688);
      if ( (*(float *)(this + 23728) > 0.0 && *(float *)(this + 23728) - 2.0 < *(float *)(this + 23684) || v22)
        && *(float *)(this + 24728) < (double)*(float *)(this + 23852) )
      {
        sub_427C20(this, *(float *)(this + 23688), 0);
        sub_427B90(this, *(float *)(this + 23684), 0);
      }
    }
  }
  else
  {
    v9 = *(_DWORD *)(this + 23600);
    *(_BYTE *)(this + 57) = 1;
    if ( v9 )
    {
      v10 = sub_42D720(v9);
      if ( *(float *)(*(_DWORD *)(this + 23600) + 160) < (double)*(float *)(this + 24736) )
        *(float *)(this + 24736) = *(float *)(this + 24736) + 100.0;
    }
    else
    {
      v10 = *(float *)(this + 23728);
    }
    v11 = *(_DWORD *)(this + 23804);
    v26 = *(float *)(this + 24732) - v10;
    v12 = *(float *)(this + 24736) - v10;
    if ( !v11 )
      v12 = v12 + 2.0;
    v13 = *(_DWORD *)(this + 23800);
    if ( !v13 )
      v26 = v26 - 2.0;
    if ( fabs(v12) <= fabs(v26) )
    {
      if ( !v11 )
        v12 = v12 - 2.0;
      if ( *(_BYTE *)(this + 16) )
        v12 = v12 + 2.0;
      v18 = *(_DWORD *)(this + 24072);
      if ( v18 != -1 )
        *(_BYTE *)(*(_DWORD *)((v18 << 7) + this + 21256) + 16) = 1;
      v19 = *(_DWORD *)(this + 24080);
      if ( v19 != -1 )
        *(_BYTE *)(*(_DWORD *)((v19 << 7) + this + 21256) + 16) = 1;
      v20 = *(_DWORD *)(this + 24088);
      if ( v20 != -1 )
        *(_BYTE *)(*(_DWORD *)((v20 << 7) + this + 21256) + 16) = 1;
      v25 = v12 + *(float *)(this + 23716);
      sub_427C20(this, v25, 0);
    }
    else
    {
      v14 = v26;
      if ( !v13 )
        v14 = v14 + 2.0;
      if ( *(_BYTE *)(this + 16) )
        v14 = v14 - 2.0;
      v15 = *(_DWORD *)(this + 24068);
      if ( v15 != -1 )
        *(_BYTE *)(*(_DWORD *)((v15 << 7) + this + 21256) + 16) = 1;
      v16 = *(_DWORD *)(this + 24076);
      if ( v16 != -1 )
        *(_BYTE *)(*(_DWORD *)((v16 << 7) + this + 21256) + 16) = 1;
      v17 = *(_DWORD *)(this + 24084);
      if ( v17 != -1 )
        *(_BYTE *)(*(_DWORD *)((v17 << 7) + this + 21256) + 16) = 1;
      v24 = v14 + *(float *)(this + 23716);
      sub_427B90(this, v24, 0);
    }
  }
}
