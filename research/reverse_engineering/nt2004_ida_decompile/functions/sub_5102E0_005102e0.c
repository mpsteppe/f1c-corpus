int __thiscall sub_5102E0(int this)
{
  int result; // eax
  double v3; // st7
  int v4; // eax
  double v5; // st7
  double v6; // st7
  int v7; // ecx
  double v8; // st6
  double v9; // st7

  *(_DWORD *)(this + 17640) = 0;
  *(_DWORD *)(this + 17644) = 0;
  *(_DWORD *)(this + 17648) = 0;
  *(_DWORD *)(this + 17652) = 0;
  *(_DWORD *)(this + 17656) = 0;
  *(_DWORD *)(this + 17660) = 0;
  if ( *(float *)(this + 18848) > 0.0 )
    sub_510420();
  result = *(_DWORD *)(this + 18828);
  if ( result != *(_DWORD *)(this + 18832) )
  {
    *(_DWORD *)(this + 18832) = result;
    if ( result )
      *(_DWORD *)(this + 18788) = *(_DWORD *)(this + 4 * (result == -1 ? 0 : result) + 18792);
    else
      *(_DWORD *)(this + 18788) = 0;
    result = *(_DWORD *)(this + 18768);
    v3 = *(float *)(this + 18788) * (*(float *)(this + 18788) * *(float *)(this + 18724));
    if ( result )
    {
      v4 = result - 1;
      if ( v4 )
      {
        result = v4 - 1;
        if ( !result )
        {
          v5 = v3 * 0.5 + *(float *)(this + 17792);
          *(float *)(this + 17796) = v5;
          *(float *)(this + 17800) = 1.0 / v5;
          *(float *)(this + 18044) = v5;
          *(float *)(this + 18048) = 1.0 / v5;
        }
      }
      else
      {
        v6 = v3 * 0.25;
        result = this + 17796;
        v7 = 4;
        do
        {
          result += 248;
          --v7;
          v8 = v6 + *(float *)(result - 252);
          *(float *)(result - 248) = v8;
          *(float *)(result - 244) = 1.0 / v8;
        }
        while ( v7 );
      }
    }
    else
    {
      v9 = v3 * 0.5 + *(float *)(this + 18288);
      *(float *)(this + 18292) = v9;
      *(float *)(this + 18296) = 1.0 / v9;
      *(float *)(this + 18540) = v9;
      *(float *)(this + 18544) = 1.0 / v9;
    }
  }
  return result;
}
