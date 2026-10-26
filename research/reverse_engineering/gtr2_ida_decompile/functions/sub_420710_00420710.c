void __thiscall sub_420710(int this)
{
  int v2; // eax
  double v3; // st6
  long double v4; // st7
  long double v5; // st7
  long double v6; // st6
  long double v7; // st7
  int v8; // eax
  int v9; // eax
  int v10; // eax
  unsigned __int8 v12; // c0
  unsigned __int8 v13; // c2
  int v14; // eax
  int v15; // ecx

  if ( *(_DWORD *)(this + 20768) == 6 )
  {
    v2 = *(_DWORD *)(this + 20184);
    v3 = *(float *)(v2 + 160) - *(float *)(this + 15996);
    if ( v3 == 0.0 )
      v4 = 1.570796326794897;
    else
      v4 = atan2(-(*(float *)(v2 + 152) - *(float *)(this + 15988)), -v3);
    v5 = v4 - *(float *)(this + 16004);
    if ( fabs(v5) >= 3.141592653589793 )
    {
      if ( v5 >= 0.0 )
        v5 = v5 - 6.2831855;
      else
        v5 = v5 + 6.2831855;
    }
    if ( fabs(v5) < 0.5 || dbl_FB1D18 > *(float *)(this + 20564) )
      *(_DWORD *)(this + 20768) = 7;
    goto LABEL_30;
  }
  if ( *(float *)(this + 16020) == 0.0 )
    v6 = 1.570796326794897;
  else
    v6 = atan2(-*(float *)(this + 16012), -*(float *)(this + 16020));
  v7 = v6 - *(float *)(this + 16004);
  if ( fabs(v7) >= 3.141592653589793 )
  {
    if ( v7 >= 0.0 )
      v7 = v7 - 6.2831855;
    else
      v7 = v7 + 6.2831855;
  }
  if ( fabs(v7) <= 0.5 || *(float *)(this + 20476) <= 0.5 )
  {
    v9 = *(_DWORD *)(this + 20548);
    if ( v9 <= 0 )
      goto LABEL_25;
    v8 = v9 - 1;
  }
  else
  {
    v8 = *(_DWORD *)(this + 20548) + 5;
  }
  *(_DWORD *)(this + 20548) = v8;
LABEL_25:
  if ( *(_DWORD *)(this + 20548) > *(_DWORD *)(this + 20856) )
  {
    if ( *(int *)(this + 17320) > 2 )
    {
      v10 = *(_DWORD *)(this + 17320);
      if ( v10 > 0 )
        sub_573480(v10 - 1);
    }
    *(_DWORD *)(this + 20548) = 0;
    sub_41FC20();
    *(_DWORD *)(this + 20768) = 1;
  }
LABEL_30:
  if ( dbl_FB1D18 > *(float *)(this + 20564) )
  {
    if ( v12 | v13 )
      *(_DWORD *)(this + 20768) = *(_DWORD *)(this + 20768) == 6 ? 0 : 6;
    v14 = *(_DWORD *)(this + 15992);
    v15 = *(_DWORD *)(this + 15996);
    *(_DWORD *)(this + 20552) = *(_DWORD *)(this + 15988);
    *(_DWORD *)(this + 20556) = v14;
    *(_DWORD *)(this + 20560) = v15;
    *(float *)(this + 20564) = dbl_FB1D18 + 4.0;
  }
}
