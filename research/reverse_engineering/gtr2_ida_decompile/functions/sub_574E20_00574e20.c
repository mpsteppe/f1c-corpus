void __fastcall sub_574E20(int a1)
{
  double v1; // st7
  double v2; // st7
  int v3; // eax
  int v4; // eax
  double v5; // st7

  v1 = *(float *)(a1 + 17324) - *(float *)(a1 + 15928);
  *(float *)(a1 + 17324) = v1;
  if ( v1 > 0.0 )
  {
    if ( *(_BYTE *)(a1 + 17301) && *(_DWORD *)(a1 + 17328) == 1 )
    {
      v2 = *(float *)(a1 + 17208);
    }
    else
    {
      v3 = *(_DWORD *)(a1 + 17244);
      if ( v3 )
      {
        v4 = v3 - 1;
        if ( v4 )
        {
          if ( v4 == 1 )
            v5 = (*(float *)(a1 + 16448) + *(float *)(a1 + 16196)) * 0.5;
          else
            v5 = *(float *)&a1;
        }
        else
        {
          v5 = (*(float *)(a1 + 16952) + *(float *)(a1 + 16700) + *(float *)(a1 + 16448) + *(float *)(a1 + 16196))
             * 0.25;
        }
      }
      else
      {
        v5 = (*(float *)(a1 + 16952) + *(float *)(a1 + 16700)) * 0.5;
      }
      v2 = -(v5 * *(float *)(a1 + 4 * (*(_DWORD *)(a1 + 17328) == -1 ? 0 : *(_DWORD *)(a1 + 17328)) + 17268));
    }
    *(float *)(a1 + 16132) = (v2 - *(float *)(a1 + 17212) + 50.0) * 0.0099999998;
    if ( *(float *)(a1 + 16132) >= 0.0 )
    {
      if ( *(float *)(a1 + 16132) > 1.0 )
        *(_DWORD *)(a1 + 16132) = 1065353216;
    }
    else
    {
      *(_DWORD *)(a1 + 16132) = 0;
    }
  }
  else
  {
    *(_DWORD *)(a1 + 17304) = *(_DWORD *)(a1 + 17328);
  }
}
