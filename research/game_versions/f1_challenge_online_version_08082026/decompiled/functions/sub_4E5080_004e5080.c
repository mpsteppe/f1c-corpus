void __fastcall sub_4E5080(int a1)
{
  double v1; // st7
  double v2; // st7
  int v3; // eax
  int v4; // eax
  double v5; // st7
  int v6; // eax
  double v7; // st7

  v1 = *(float *)(a1 + 14852) - *(float *)(a1 + 13480);
  *(float *)(a1 + 14852) = v1;
  if ( v1 > 0.0 )
  {
    if ( *(_BYTE *)(a1 + 14828) && *(_DWORD *)(a1 + 14856) == 1 )
    {
      v2 = *(float *)(a1 + 14736);
    }
    else
    {
      v3 = *(_DWORD *)(a1 + 14772);
      if ( v3 )
      {
        v4 = v3 - 1;
        if ( v4 )
        {
          if ( v4 == 1 )
            v5 = (*(float *)(a1 + 13992) + *(float *)(a1 + 13744)) * 0.5;
          else
            v5 = *(float *)&a1;
        }
        else
        {
          v5 = (*(float *)(a1 + 14488) + *(float *)(a1 + 14240) + *(float *)(a1 + 13992) + *(float *)(a1 + 13744))
             * 0.25;
        }
      }
      else
      {
        v5 = (*(float *)(a1 + 14488) + *(float *)(a1 + 14240)) * 0.5;
      }
      v6 = *(_DWORD *)(a1 + 14856) == -1 ? 0 : *(_DWORD *)(a1 + 14856);
      if ( v6 > 7 )
        v7 = v5 * *(float *)(a1 + 4 * v6 + 18464);
      else
        v7 = v5 * *(float *)(a1 + 4 * v6 + 14796);
      v2 = -v7;
    }
    *(float *)(a1 + 13680) = (v2 - *(float *)(a1 + 14740) + 50.0) * 0.0099999998;
    if ( *(float *)(a1 + 13680) >= 0.0 )
    {
      if ( *(float *)(a1 + 13680) > 1.0 )
        *(_DWORD *)(a1 + 13680) = 1065353216;
    }
    else
    {
      *(_DWORD *)(a1 + 13680) = 0;
    }
  }
  else
  {
    *(_DWORD *)(a1 + 14832) = *(_DWORD *)(a1 + 14856);
  }
}
