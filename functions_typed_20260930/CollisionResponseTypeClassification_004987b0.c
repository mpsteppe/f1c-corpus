int __thiscall sub_4987B0(float *this)
{
  int v1; // ecx
  double v2; // st7
  double v3; // st7
  int v4; // eax
  int v5; // edx
  int v6; // eax
  int v7; // eax
  int v8; // ecx

  v2 = FloatFieldAccessor(this);
  v3 = v2 + *(float *)(v1 + 200);
  v4 = *(_DWORD *)(v1 + 100);
  *(float *)(v1 + 200) = v3;
  if ( v4 )
  {
    if ( *(_DWORD *)(v1 + 132) )
    {
      v5 = 5;
    }
    else
    {
      v5 = 1;
      if ( v3 > 0.55000001 )
      {
        *(_DWORD *)(v1 + 200) = 0;
      }
      else
      {
        v5 = 2;
        *(_DWORD *)(v1 + 200) = 1059481191;
      }
    }
  }
  else
  {
    v5 = 4 - (*(_DWORD *)(v1 + 132) != 0);
  }
  v6 = *(_DWORD *)(v1 + 136);
  if ( *(_DWORD *)(v1 + 104) )
  {
    v5 = 2 * (v6 != 0) + 9;
  }
  else if ( v6 )
  {
    v5 = 10;
  }
  v7 = *(_DWORD *)(v1 + 140);
  if ( *(_DWORD *)(v1 + 108) )
  {
    v5 = 2 * (v7 != 0) + 6;
  }
  else if ( v7 )
  {
    v5 = 7;
  }
  v8 = *(_DWORD *)(v1 + 112);
  if ( v8 )
    return (v8 <= 0) + 12;
  else
    return v5;
}

