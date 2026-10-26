int __thiscall sub_578FE0(int this)
{
  int result; // eax
  double v3; // st7
  double v4; // st7
  double v5; // st7
  double v6; // st6
  double v7; // st6
  double v8; // st6
  double v9; // st7
  double v10; // st7

  *(_DWORD *)(this + 16096) = 0;
  *(_DWORD *)(this + 16100) = 0;
  *(_DWORD *)(this + 16104) = 0;
  *(_DWORD *)(this + 16108) = 0;
  *(_DWORD *)(this + 16112) = 0;
  *(_DWORD *)(this + 16116) = 0;
  if ( *(float *)(this + 17324) > 0.0 )
    sub_574E20(this);
  result = *(_DWORD *)(this + 17304);
  if ( result != *(_DWORD *)(this + 17308) )
  {
    *(_DWORD *)(this + 17308) = result;
    if ( result )
      *(_DWORD *)(this + 17264) = *(_DWORD *)(this + 4 * (result == -1 ? 0 : result) + 17268);
    else
      *(_DWORD *)(this + 17264) = 0;
    result = *(_DWORD *)(this + 17244);
    v3 = *(float *)(this + 17264) * (*(float *)(this + 17264) * *(float *)(this + 17200));
    if ( result )
    {
      if ( --result )
      {
        if ( !--result )
        {
          v4 = v3 * 0.5 + *(float *)(this + 16248);
          *(float *)(this + 16252) = v4;
          *(float *)(this + 16256) = 1.0 / v4;
          *(float *)(this + 16504) = v4;
          *(float *)(this + 16508) = 1.0 / v4;
        }
      }
      else
      {
        v5 = v3 * 0.25;
        v6 = v5 + *(float *)(this + 16248);
        *(float *)(this + 16252) = v6;
        *(float *)(this + 16256) = 1.0 / v6;
        v7 = v5 + *(float *)(this + 16500);
        *(float *)(this + 16504) = v7;
        *(float *)(this + 16508) = 1.0 / v7;
        v8 = v5 + *(float *)(this + 16752);
        *(float *)(this + 16756) = v8;
        *(float *)(this + 16760) = 1.0 / v8;
        v9 = v5 + *(float *)(this + 17004);
        *(float *)(this + 17008) = v9;
        *(float *)(this + 17012) = 1.0 / v9;
      }
    }
    else
    {
      v10 = v3 * 0.5 + *(float *)(this + 16752);
      *(float *)(this + 16756) = v10;
      *(float *)(this + 16760) = 1.0 / v10;
      *(float *)(this + 17008) = v10;
      *(float *)(this + 17012) = 1.0 / v10;
    }
  }
  return result;
}
