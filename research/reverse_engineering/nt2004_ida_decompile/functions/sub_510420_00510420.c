void __fastcall sub_510420(int a1)
{
  double v1; // st7
  double v2; // st7
  int v3; // eax
  int v4; // eax
  double v5; // st7

  v1 = *(float *)(a1 + 18848) - *(float *)(a1 + 17476);
  *(float *)(a1 + 18848) = v1;
  if ( v1 > 0.0 )
  {
    if ( *(_BYTE *)(a1 + 18825) && *(_DWORD *)(a1 + 18852) == 1 )
    {
      v2 = *(float *)(a1 + 18732);
    }
    else
    {
      v3 = *(_DWORD *)(a1 + 18768);
      if ( v3 )
      {
        v4 = v3 - 1;
        if ( v4 )
        {
          if ( v4 == 1 )
            v5 = (*(float *)(a1 + 17988) + *(float *)(a1 + 17740)) * 0.5;
          else
            v5 = *(float *)&a1;
        }
        else
        {
          v5 = (*(float *)(a1 + 18484) + *(float *)(a1 + 18236) + *(float *)(a1 + 17988) + *(float *)(a1 + 17740))
             * 0.25;
        }
      }
      else
      {
        v5 = (*(float *)(a1 + 18484) + *(float *)(a1 + 18236)) * 0.5;
      }
      v2 = -(v5 * *(float *)(a1 + 4 * (*(_DWORD *)(a1 + 18852) == -1 ? 0 : *(_DWORD *)(a1 + 18852)) + 18792));
    }
    *(float *)(a1 + 17676) = (v2 - *(float *)(a1 + 18736) + 50.0) * 0.0099999998;
    if ( *(float *)(a1 + 17676) >= 0.0 )
    {
      if ( *(float *)(a1 + 17676) > 1.0 )
        *(_DWORD *)(a1 + 17676) = 1065353216;
    }
    else
    {
      *(_DWORD *)(a1 + 17676) = 0;
    }
  }
  else
  {
    *(_DWORD *)(a1 + 18828) = *(_DWORD *)(a1 + 18852);
  }
}
