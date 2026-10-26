void __thiscall sub_51F1A0(int this, float *a2)
{
  float *v3; // edx
  int v4; // esi
  int v5; // eax
  double v6; // st7
  int v7; // eax
  int v8; // eax
  double v9; // st7
  long double v10; // st6
  int v11; // esi
  int v12; // edx
  long double v13; // st6
  float *v14; // edi
  long double v15; // st5
  int v16; // eax
  bool v17; // zf
  double v18[3]; // [esp+10h] [ebp-18h] BYREF
  float v19; // [esp+2Ch] [ebp+4h]

  *(float *)(this + 17544) = *a2;
  *(float *)(this + 17548) = a2[1];
  *(float *)(this + 17552) = a2[2];
  v3 = (float *)(this + 17740);
  v4 = 4;
  *(float *)(this + 17556) = *(float *)(this + 17508) * *(float *)(this + 17552)
                           + *(float *)(this + 17496) * *(float *)(this + 17548)
                           + *(float *)(this + 17544) * *(float *)(this + 17484);
  *(float *)(this + 17560) = *(float *)(this + 17488) * *(float *)(this + 17544)
                           + *(float *)(this + 17512) * *(float *)(this + 17552)
                           + *(float *)(this + 17500) * *(float *)(this + 17548);
  v5 = this + 17740;
  *(float *)(this + 17564) = *(float *)(this + 17492) * *(float *)(this + 17544)
                           + *(float *)(this + 17516) * *(float *)(this + 17552)
                           + *(float *)(this + 17504) * *(float *)(this + 17548);
  v6 = *(float *)(this + 17564);
  *(_DWORD *)(this + 17568) = 0;
  *(_DWORD *)(this + 17572) = 0;
  v19 = -v6;
  *(_DWORD *)(this + 17576) = 0;
  do
  {
    v5 += 248;
    --v4;
    *(float *)(v5 - 248) = -(v19 / *(float *)(v5 - 152));
  }
  while ( v4 );
  v7 = *(_DWORD *)(this + 18768);
  if ( v7 )
  {
    v8 = v7 - 1;
    if ( v8 )
    {
      if ( v8 == 1 )
        v9 = (*(float *)(this + 17988) + *v3) * 0.5;
      else
        v9 = v19;
    }
    else
    {
      v9 = (*(float *)(this + 18484) + *(float *)(this + 18236) + *(float *)(this + 17988) + *v3) * 0.25;
    }
  }
  else
  {
    v9 = (*(float *)(this + 18484) + *(float *)(this + 18236)) * 0.5;
  }
  v10 = fabs(v19) * 0.018 + 0.2;
  if ( v10 >= 0.0 )
  {
    if ( v10 > 0.80000001 )
      v10 = 0.80000001;
  }
  else
  {
    v10 = 0.0;
  }
  v11 = *(_DWORD *)(this + 18836);
  v12 = v11;
  *(float *)(this + 18736) = -(v9 * *(float *)(this + 4 * v11 + 18792));
  if ( v11 > 0 )
  {
    v13 = v10 * *(float *)(this + 18740);
    v14 = (float *)(this + 4 * v11 + 18792);
    do
    {
      v15 = -(v9 * *v14);
      if ( v15 < v13 )
      {
        *(float *)(this + 18736) = v15;
        v11 = v12;
      }
      --v12;
      --v14;
    }
    while ( v12 > 0 );
  }
  if ( *(float *)(this + 18736) < (double)*(float *)(this + 18744) )
  {
    v16 = *(_DWORD *)(this + 18744);
    *(_DWORD *)(this + 18828) = 0;
    *(_DWORD *)(this + 18736) = v16;
  }
  else
  {
    *(_DWORD *)(this + 18828) = v11;
  }
  v17 = *(_DWORD *)(this + 16500) == 0;
  *(_DWORD *)(this + 18832) = -2;
  if ( v17 )
  {
    v18[0] = *a2;
    v18[1] = a2[1];
    v18[2] = a2[2];
    sub_449EA0((int)&dbl_75E930, v18);
  }
}
