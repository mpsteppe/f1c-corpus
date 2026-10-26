void __thiscall sub_421CA0(int this)
{
  int v2; // eax
  long double v3; // st7
  long double v4; // st7
  int v5; // eax
  int v6; // eax
  bool v7; // cc
  int v8; // eax
  unsigned __int8 v10; // c0
  unsigned __int8 v11; // c2
  double v12; // st7
  int v13; // eax
  int v14; // ecx

  if ( *(_DWORD *)(this + 24020) == 3 )
  {
    v2 = *(_DWORD *)(this + 23432);
    *(_DWORD *)(this + 23832) = 0;
    v3 = atan2(-(*(float *)(v2 + 196) - *(float *)(this + 17604)), -(*(float *)(v2 + 204) - *(float *)(this + 17612)))
       - *(float *)(this + 17620);
    if ( fabs(v3) >= 3.141592653589793 )
    {
      if ( v3 >= 0.0 )
        v3 = v3 - 6.283185307179586;
      else
        v3 = v3 + 6.283185307179586;
    }
    if ( fabs(v3) < 0.5 || *(float *)(this + 23848) < (double)*(float *)(this + 23852) )
    {
      *(float *)(this + 23788) = *(float *)(this + 23852) + 2.0;
      sub_42C0F0(4);
    }
    goto LABEL_24;
  }
  v4 = atan2(-*(float *)(this + 17628), -*(float *)(this + 17636)) - *(float *)(this + 17620);
  if ( fabs(v4) >= 3.141592653589793 )
  {
    if ( v4 >= 0.0 )
      v4 = v4 - 6.283185307179586;
    else
      v4 = v4 + 6.283185307179586;
  }
  if ( fabs(v4) <= 0.5 || *(float *)(this + 23764) <= 0.5 )
  {
    v6 = *(_DWORD *)(this + 23832);
    if ( v6 <= 0 )
      goto LABEL_19;
    v5 = v6 - 1;
  }
  else
  {
    v5 = *(_DWORD *)(this + 23832) + 5;
  }
  *(_DWORD *)(this + 23832) = v5;
LABEL_19:
  if ( *(_DWORD *)(this + 23832) > *(_DWORD *)(this + 24256) )
  {
    v7 = *(_DWORD *)(this + 18912) <= 2;
    *(_DWORD *)(this + 23832) = 0;
    if ( !v7 )
    {
      v8 = *(_DWORD *)(this + 18912);
      if ( v8 > 0 )
        sub_51BFD0(v8 - 1);
    }
    sub_42C0F0(0);
  }
LABEL_24:
  if ( *(float *)(this + 23848) < (double)*(float *)(this + 23852) )
  {
    if ( v10 | v11 )
    {
      if ( *(float *)(this + 23788) < (double)*(float *)(this + 23852) )
        sub_42C0F0(*(_DWORD *)(this + 24020) != 3 ? 3 : 6);
    }
    v12 = *(float *)(this + 23852) + 4.0;
    v13 = *(_DWORD *)(this + 17608);
    v14 = *(_DWORD *)(this + 17612);
    *(_DWORD *)(this + 23836) = *(_DWORD *)(this + 17604);
    *(float *)(this + 23848) = v12;
    *(_DWORD *)(this + 23840) = v13;
    *(_DWORD *)(this + 23844) = v14;
  }
}
