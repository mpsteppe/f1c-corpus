int __thiscall sub_4E4F40(int this)
{
  int result; // eax
  int v3; // eax
  double v4; // st7
  int v5; // eax
  double v6; // st7
  double v7; // st7
  int v8; // ecx
  double v9; // st6
  double v10; // st7
  int v11; // edx

  *(_DWORD *)(this + 13644) = 0;
  *(_DWORD *)(this + 13648) = 0;
  *(_DWORD *)(this + 13652) = 0;
  *(_DWORD *)(this + 13656) = 0;
  *(_DWORD *)(this + 13660) = 0;
  *(_DWORD *)(this + 13664) = 0;
  if ( *(float *)(this + 14852) > 0.0 )
    BrakeCoolingPostTreatment();
  result = *(_DWORD *)(this + 14832);
  if ( result != *(_DWORD *)(this + 14836) )
  {
    *(_DWORD *)(this + 14836) = result;
    if ( result )
    {
      v3 = result == -1 ? 0 : result;
      if ( v3 > 7 )
        v11 = *(_DWORD *)(this + 4 * v3 + 18464);
      else
        v11 = *(_DWORD *)(this + 4 * v3 + 14796);
      *(_DWORD *)(this + 14792) = v11;
    }
    else
    {
      *(_DWORD *)(this + 14792) = 0;
    }
    result = *(_DWORD *)(this + 14772);
    v4 = *(float *)(this + 14792) * (*(float *)(this + 14792) * *(float *)(this + 14728));
    if ( result )
    {
      v5 = result - 1;
      if ( v5 )
      {
        result = v5 - 1;
        if ( !result )
        {
          v6 = v4 * 0.5 + *(float *)(this + 13796);
          *(float *)(this + 13800) = v6;
          *(float *)(this + 13804) = 1.0 / v6;
          *(float *)(this + 14048) = v6;
          *(float *)(this + 14052) = 1.0 / v6;
        }
      }
      else
      {
        v7 = v4 * 0.25;
        result = this + 13800;
        v8 = 4;
        do
        {
          result += 248;
          --v8;
          v9 = v7 + *(float *)(result - 252);
          *(float *)(result - 248) = v9;
          *(float *)(result - 244) = 1.0 / v9;
        }
        while ( v8 );
      }
    }
    else
    {
      v10 = v4 * 0.5 + *(float *)(this + 14292);
      *(float *)(this + 14296) = v10;
      *(float *)(this + 14300) = 1.0 / v10;
      *(float *)(this + 14544) = v10;
      *(float *)(this + 14548) = 1.0 / v10;
    }
  }
  return result;
}

