void __thiscall sub_425670(int this)
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

  if ( *(_DWORD *)(this + 17680) == 6 )
  {
    v2 = *(_DWORD *)(this + 17236);
    v3 = *(float *)(v2 + 156) - *(float *)(this + 13544);
    if ( v3 == 0.0 )
      v4 = 1.570796326794897;
    else
      v4 = atan2(-(*(float *)(v2 + 148) - *(float *)(this + 13536)), -v3);
    v5 = v4 - *(float *)(this + 13552);
    if ( fabs(v5) >= 3.141592653589793 )
    {
      if ( v5 >= 0.0 )
        v5 = v5 - 6.2831855;
      else
        v5 = v5 + 6.2831855;
    }
    if ( fabs(v5) < 0.5 || dbl_8AFEA0 > *(float *)(this + 17532) )
      *(_DWORD *)(this + 17680) = 7;
    goto LABEL_30;
  }
  if ( *(float *)(this + 13568) == 0.0 )
    v6 = 1.570796326794897;
  else
    v6 = atan2(-*(float *)(this + 13560), -*(float *)(this + 13568));
  v7 = v6 - *(float *)(this + 13552);
  if ( fabs(v7) >= 3.141592653589793 )
  {
    if ( v7 >= 0.0 )
      v7 = v7 - 6.2831855;
    else
      v7 = v7 + 6.2831855;
  }
  if ( fabs(v7) <= 0.5 || *(float *)(this + 17472) <= 0.5 )
  {
    v9 = *(_DWORD *)(this + 17516);
    if ( v9 <= 0 )
      goto LABEL_25;
    v8 = v9 - 1;
  }
  else
  {
    v8 = *(_DWORD *)(this + 17516) + 5;
  }
  *(_DWORD *)(this + 17516) = v8;
LABEL_25:
  if ( *(_DWORD *)(this + 17516) > *(_DWORD *)(this + 17752) )
  {
    if ( *(int *)(this + 14844) > 2 )
    {
      v10 = *(_DWORD *)(this + 14844);
      if ( v10 > 0 )
        RaceStartCountdownStateUpdate(v10 - 1);
    }
    *(_DWORD *)(this + 17516) = 0;
    AIClearStateFlags(this);
    *(_DWORD *)(this + 17680) = 1;
  }
LABEL_30:
  if ( dbl_8AFEA0 > *(float *)(this + 17532) )
  {
    if ( v12 | v13 )
      *(_DWORD *)(this + 17680) = *(_DWORD *)(this + 17680) == 6 ? 0 : 6;
    v14 = *(_DWORD *)(this + 13540);
    v15 = *(_DWORD *)(this + 13544);
    *(_DWORD *)(this + 17520) = *(_DWORD *)(this + 13536);
    *(_DWORD *)(this + 17524) = v14;
    *(_DWORD *)(this + 17528) = v15;
    *(float *)(this + 17532) = dbl_8AFEA0 + 4.0;
  }
}
