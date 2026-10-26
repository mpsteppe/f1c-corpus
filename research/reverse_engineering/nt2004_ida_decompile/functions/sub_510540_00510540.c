void __thiscall sub_510540(int this)
{
  double v2; // st7
  float *v3; // ebx
  double v4; // st7
  double v5; // st7
  double v6; // st7
  double v7; // st7
  double X; // st7
  double v9; // st7
  int v10; // eax
  int v11; // ecx
  double v12; // st7
  int v13; // eax
  double v14; // st7
  unsigned __int8 v16; // c0
  unsigned __int8 v17; // c2
  int v18; // eax
  int v19; // eax
  double v20; // st7
  double v21; // st7
  float *v22; // eax
  int v23; // ecx
  double v24; // st7
  float v25; // [esp+14h] [ebp-10h]
  float v26; // [esp+14h] [ebp-10h]
  float v27; // [esp+18h] [ebp-Ch]
  float v28; // [esp+20h] [ebp-4h]

  v2 = *(float *)(this + 18736);
  v3 = (float *)(this + 17776);
  *(_DWORD *)(this + 17776) = 0;
  *(_DWORD *)(this + 18024) = 0;
  *(_DWORD *)(this + 18272) = 0;
  *(_DWORD *)(this + 18520) = 0;
  if ( v2 == 0.0 )
  {
    v4 = *(float *)(this + 18772);
    *(_DWORD *)(this + 17684) = 1065353216;
    if ( v4 > 0.0 )
    {
      v5 = *(float *)(this + 18772) - *(float *)(this + 17476);
      *(float *)(this + 18772) = v5;
      if ( v5 <= 0.0 && *(float *)(this + 18736) < (double)*(float *)(this + 18744) )
        *(_DWORD *)(this + 18736) = *(_DWORD *)(this + 18744);
    }
  }
  v6 = *(float *)(this + 18892) * *(float *)(this + 17684) + *(float *)(this + 18896);
  *(float *)(this + 17780) = v6;
  *(float *)(this + 18028) = v6;
  v7 = *(float *)(this + 18912) * *(float *)(this + 17684) + *(float *)(this + 18916);
  *(float *)(this + 18276) = v7;
  *(float *)(this + 18524) = v7;
  if ( *(float *)(this + 18708) <= 0.0 )
    *(_DWORD *)(this + 17676) = 0;
  X = *(float *)(this + 18736) * 0.03125;
  v28 = *(float *)(this + 17676);
  v25 = X;
  v27 = floor(X);
  v9 = v25 - v27;
  v10 = *(_DWORD *)(this + 18752);
  v11 = (int)v27;
  *(float *)(this + 18756) = (*(float *)(v10 + 8 * v11 + 8) - *(float *)(v10 + 8 * v11)) * v9
                           + *(float *)(v10 + 8 * v11);
  v12 = v9 * (*(float *)(v10 + 8 * v11 + 12) - *(float *)(v10 + 8 * v11 + 4)) + *(float *)(v10 + 8 * v11 + 4);
  *(float *)(this + 18760) = v12;
  v13 = *(_DWORD *)(this + 18828);
  v26 = v12 * v28 + *(float *)(this + 18756);
  *(float *)(this + 18748) = v26;
  if ( v13 && *(float *)(this + 18736) > 0.0 )
  {
    if ( *(float *)(this + 18688) == *(float *)(this + 18736) )
    {
LABEL_11:
      v14 = -(v26 * *(float *)(this + 18788));
      goto LABEL_17;
    }
    if ( v16 | v17 )
    {
      if ( v26 >= 0.0 )
        goto LABEL_11;
      v14 = -(0.0 * *(float *)(this + 18788));
    }
    else
    {
      if ( v26 <= 0.0 )
        goto LABEL_11;
      v14 = -(0.0 * *(float *)(this + 18788));
    }
LABEL_17:
    v18 = *(_DWORD *)(this + 18768);
    if ( v18 )
    {
      v19 = v18 - 1;
      if ( v19 )
      {
        if ( v19 == 1 )
        {
          v20 = v14 * 0.5;
          *v3 = v20;
          *(float *)(this + 18024) = v20;
        }
      }
      else
      {
        v21 = v14 * 0.25;
        v22 = v3;
        v23 = 4;
        do
        {
          *v22 = v21;
          v22 += 62;
          --v23;
        }
        while ( v23 );
      }
    }
    else
    {
      v24 = v14 * 0.5;
      *(float *)(this + 18272) = v24;
      *(float *)(this + 18520) = v24;
    }
  }
}
