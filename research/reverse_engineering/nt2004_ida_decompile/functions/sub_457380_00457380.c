void __thiscall sub_457380(int this, float a2, _DWORD *a3, _DWORD *a4, _DWORD *a5, _DWORD *a6, _DWORD *a7, _DWORD *a8)
{
  double v8; // st7
  double v9; // st7
  double v10; // st7
  double v11; // st7
  double v12; // st7
  double v13; // st7
  double v14; // st7
  double v15; // st7
  int v16; // eax
  double v17; // st7
  char v18; // fps^1
  double v19; // st6
  bool v20; // c0
  char v21; // c2
  bool v22; // c3
  bool v23; // zf
  char v24; // ah
  double v25; // st7
  double v26; // st7
  double v27; // st7
  double v28; // st7
  double v29; // st7

  if ( *(_DWORD *)(this + 6952) == 2 )
  {
    *(float *)(this + 10124) = *(float *)(this + 6992);
  }
  else
  {
    v8 = flt_769D1C * a2 * 10.0;
    if ( *(_DWORD *)(this + 6988) )
    {
      v9 = v8 + *(float *)(this + 10124);
      *(float *)(this + 10124) = v9;
      if ( v9 > 1.0 )
        *(_DWORD *)(this + 10124) = 1065353216;
    }
    else
    {
      if ( *(_DWORD *)(this + 7032) )
        *(float *)(this + 10124) = *(float *)(this + 10124) - v8 * 1.5;
      else
        *(float *)(this + 10124) = *(float *)(this + 10124) - v8;
      if ( *(float *)(this + 10124) < 0.0 )
        *(_DWORD *)(this + 10124) = 0;
    }
  }
  *a4 = *(_DWORD *)(this + 10124);
  if ( *(_DWORD *)(this + 6996) == 2 )
  {
    *(float *)(this + 10128) = *(float *)(this + 7036);
  }
  else
  {
    v10 = flt_769D40 * a2 * 10.0;
    if ( *(_DWORD *)(this + 7032) )
    {
      v11 = v10 + *(float *)(this + 10128);
      *(float *)(this + 10128) = v11;
      if ( v11 > 1.0 )
        *(_DWORD *)(this + 10128) = 1065353216;
    }
    else
    {
      v12 = *(float *)(this + 10128) - v10;
      *(float *)(this + 10128) = v12;
      if ( v12 < 0.0 )
        *(_DWORD *)(this + 10128) = 0;
    }
  }
  *a5 = *(_DWORD *)(this + 10128);
  if ( *(_DWORD *)(this + 9152) == 2 )
  {
    *(float *)(this + 10132) = *(float *)(this + 9192);
  }
  else
  {
    v13 = flt_769D40 * a2 * 10.0;
    if ( *(_DWORD *)(this + 9188) )
    {
      v14 = v13 + *(float *)(this + 10132);
      *(float *)(this + 10132) = v14;
      if ( v14 > 1.0 )
        *(_DWORD *)(this + 10132) = 1065353216;
    }
    else
    {
      v15 = *(float *)(this + 10132) - v13;
      *(float *)(this + 10132) = v15;
      if ( v15 < 0.0 )
        *(_DWORD *)(this + 10132) = 0;
    }
  }
  *a6 = *(_DWORD *)(this + 10132);
  if ( *(_DWORD *)(this + 7040) == 2 && *(_DWORD *)(this + 7084) == 2 )
  {
    if ( *(float *)(this + 7080) <= 0.0 )
      *(float *)(this + 10136) = *(float *)(this + 7124);
    else
      *(float *)(this + 10136) = -*(float *)(this + 7080);
    goto LABEL_46;
  }
  v16 = *(_DWORD *)(this + 7120);
  v17 = flt_769CF8 * a2 * 10.0;
  v19 = *(float *)(this + 10136);
  v20 = v19 < 0.0;
  v21 = 0;
  v22 = v19 == 0.0;
  if ( *(_DWORD *)(this + 7076) )
  {
    v23 = v16 == 0;
    v24 = v18;
    if ( v23 )
    {
      if ( !v20 && !v22 )
        *(float *)(this + 10136) = *(float *)(this + 10136) - 3.0 * v17;
      v26 = *(float *)(this + 10136) - v17;
      *(float *)(this + 10136) = v26;
      if ( v26 < -1.0 )
        *(_DWORD *)(this + 10136) = -1082130432;
      goto LABEL_46;
    }
  }
  else
  {
    v23 = v16 == 0;
    v24 = v18;
    if ( !v23 )
    {
      if ( v19 < 0.0 )
        *(float *)(this + 10136) = 3.0 * v17 + *(float *)(this + 10136);
      v27 = v17 + *(float *)(this + 10136);
      *(float *)(this + 10136) = v27;
      if ( v27 > 1.0 )
        *(_DWORD *)(this + 10136) = 1065353216;
      goto LABEL_46;
    }
  }
  if ( (v24 & 0x41) != 0 )
  {
    v28 = v17 + *(float *)(this + 10136);
    *(float *)(this + 10136) = v28;
    if ( v28 <= 0.0 )
      goto LABEL_46;
  }
  else
  {
    v25 = *(float *)(this + 10136) - v17;
    *(float *)(this + 10136) = v25;
    if ( v25 >= 0.0 )
      goto LABEL_46;
  }
  *(_DWORD *)(this + 10136) = 0;
LABEL_46:
  *a3 = *(_DWORD *)(this + 10136);
  if ( *(_BYTE *)(this + 10148) )
  {
    v23 = *(_DWORD *)(this + 8748) == 0;
    *(_DWORD *)(this + 10144) = -2;
    if ( v23 )
    {
      if ( *(_DWORD *)(this + 8704) )
      {
        *(_DWORD *)(this + 10144) = 6;
      }
      else if ( *(_DWORD *)(this + 8660) )
      {
        *(_DWORD *)(this + 10144) = 5;
      }
      else if ( *(_DWORD *)(this + 8616) )
      {
        *(_DWORD *)(this + 10144) = 4;
      }
      else if ( *(_DWORD *)(this + 8572) )
      {
        *(_DWORD *)(this + 10144) = 3;
      }
      else if ( *(_DWORD *)(this + 8528) )
      {
        *(_DWORD *)(this + 10144) = 2;
      }
      else if ( *(_DWORD *)(this + 8484) )
      {
        *(_DWORD *)(this + 10144) = 1;
      }
      else if ( *(_DWORD *)(this + 8440) )
      {
        *(_DWORD *)(this + 10144) = -1;
      }
    }
    else
    {
      *(_DWORD *)(this + 10144) = 7;
    }
    if ( *(_DWORD *)(this + 10144) == -2 && byte_769DC4 == 1 )
      *(_DWORD *)(this + 10144) = 0;
  }
  *a8 = *(_DWORD *)(this + 10144);
  if ( *(_DWORD *)(this + 7216) == 2 )
  {
    *(float *)(this + 10140) = *(float *)(this + 7256);
LABEL_68:
    *a7 = *(_DWORD *)(this + 10140);
    return;
  }
  if ( *(_DWORD *)(this + 7252) )
  {
    *(_DWORD *)(this + 10140) = 1065353216;
    *a7 = 1065353216;
  }
  else
  {
    v29 = *(float *)(this + 10140) - flt_769D64 * a2 * 10.0;
    *(float *)(this + 10140) = v29;
    if ( v29 >= 0.0 )
      goto LABEL_68;
    *(_DWORD *)(this + 10140) = 0;
    *a7 = 0;
  }
}
