void __thiscall sub_454DA0(int this, float a2, _DWORD *a3, _DWORD *a4, _DWORD *a5, _DWORD *a6, _DWORD *a7, _DWORD *a8)
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

  if ( *(_DWORD *)(this + 6944) == 2 )
  {
    *(float *)(this + 9232) = *(float *)(this + 6984);
  }
  else
  {
    v8 = flt_7D12C8 * a2 * 10.0;
    if ( *(_DWORD *)(this + 6980) )
    {
      v9 = v8 + *(float *)(this + 9232);
      *(float *)(this + 9232) = v9;
      if ( v9 > 1.0 )
        *(_DWORD *)(this + 9232) = 1065353216;
    }
    else
    {
      if ( *(_DWORD *)(this + 7024) )
        *(float *)(this + 9232) = *(float *)(this + 9232) - v8 * 1.5;
      else
        *(float *)(this + 9232) = *(float *)(this + 9232) - v8;
      if ( *(float *)(this + 9232) < 0.0 )
        *(_DWORD *)(this + 9232) = 0;
    }
  }
  *a4 = *(_DWORD *)(this + 9232);
  if ( *(_DWORD *)(this + 6988) == 2 )
  {
    *(float *)(this + 9236) = *(float *)(this + 7028);
  }
  else
  {
    v10 = flt_7D12EC * a2 * 10.0;
    if ( *(_DWORD *)(this + 7024) )
    {
      v11 = v10 + *(float *)(this + 9236);
      *(float *)(this + 9236) = v11;
      if ( v11 > 1.0 )
        *(_DWORD *)(this + 9236) = 1065353216;
    }
    else
    {
      v12 = *(float *)(this + 9236) - v10;
      *(float *)(this + 9236) = v12;
      if ( v12 < 0.0 )
        *(_DWORD *)(this + 9236) = 0;
    }
  }
  *a5 = *(_DWORD *)(this + 9236);
  if ( *(_DWORD *)(this + 8660) == 2 )
  {
    *(float *)(this + 9240) = *(float *)(this + 8700);
  }
  else
  {
    v13 = flt_7D12EC * a2 * 10.0;
    if ( *(_DWORD *)(this + 8696) )
    {
      v14 = v13 + *(float *)(this + 9240);
      *(float *)(this + 9240) = v14;
      if ( v14 > 1.0 )
        *(_DWORD *)(this + 9240) = 1065353216;
    }
    else
    {
      v15 = *(float *)(this + 9240) - v13;
      *(float *)(this + 9240) = v15;
      if ( v15 < 0.0 )
        *(_DWORD *)(this + 9240) = 0;
    }
  }
  *a6 = *(_DWORD *)(this + 9240);
  if ( *(_DWORD *)(this + 7032) == 2 && *(_DWORD *)(this + 7076) == 2 )
  {
    if ( *(float *)(this + 7072) <= 0.0 )
      *(float *)(this + 9244) = *(float *)(this + 7116);
    else
      *(float *)(this + 9244) = -*(float *)(this + 7072);
    goto LABEL_46;
  }
  v16 = *(_DWORD *)(this + 7112);
  v17 = flt_7D12A4 * a2 * 10.0;
  v19 = *(float *)(this + 9244);
  v20 = v19 < 0.0;
  v21 = 0;
  v22 = v19 == 0.0;
  if ( *(_DWORD *)(this + 7068) )
  {
    v23 = v16 == 0;
    v24 = v18;
    if ( v23 )
    {
      if ( !v20 && !v22 )
        *(float *)(this + 9244) = *(float *)(this + 9244) - 3.0 * v17;
      v26 = *(float *)(this + 9244) - v17;
      *(float *)(this + 9244) = v26;
      if ( v26 < -1.0 )
        *(_DWORD *)(this + 9244) = -1082130432;
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
        *(float *)(this + 9244) = 3.0 * v17 + *(float *)(this + 9244);
      v27 = v17 + *(float *)(this + 9244);
      *(float *)(this + 9244) = v27;
      if ( v27 > 1.0 )
        *(_DWORD *)(this + 9244) = 1065353216;
      goto LABEL_46;
    }
  }
  if ( (v24 & 0x41) != 0 )
  {
    v28 = v17 + *(float *)(this + 9244);
    *(float *)(this + 9244) = v28;
    if ( v28 <= 0.0 )
      goto LABEL_46;
  }
  else
  {
    v25 = *(float *)(this + 9244) - v17;
    *(float *)(this + 9244) = v25;
    if ( v25 >= 0.0 )
      goto LABEL_46;
  }
  *(_DWORD *)(this + 9244) = 0;
LABEL_46:
  *a3 = *(_DWORD *)(this + 9244);
  if ( *(_BYTE *)(this + 9256) )
  {
    v23 = *(_DWORD *)(this + 8432) == 0;
    *(_DWORD *)(this + 9252) = -2;
    if ( v23 )
    {
      if ( *(_DWORD *)(this + 8388) )
      {
        *(_DWORD *)(this + 9252) = 6;
      }
      else if ( *(_DWORD *)(this + 8344) )
      {
        *(_DWORD *)(this + 9252) = 5;
      }
      else if ( *(_DWORD *)(this + 8300) )
      {
        *(_DWORD *)(this + 9252) = 4;
      }
      else if ( *(_DWORD *)(this + 8256) )
      {
        *(_DWORD *)(this + 9252) = 3;
      }
      else if ( *(_DWORD *)(this + 8212) )
      {
        *(_DWORD *)(this + 9252) = 2;
      }
      else if ( *(_DWORD *)(this + 8168) )
      {
        *(_DWORD *)(this + 9252) = 1;
      }
      else if ( *(_DWORD *)(this + 8124) )
      {
        *(_DWORD *)(this + 9252) = -1;
      }
    }
    else
    {
      *(_DWORD *)(this + 9252) = 7;
    }
    if ( *(_DWORD *)(this + 9252) == -2 && byte_7D1370 == 1 )
      *(_DWORD *)(this + 9252) = 0;
  }
  *a8 = *(_DWORD *)(this + 9252);
  if ( *(_DWORD *)(this + 7252) == 2 )
  {
    *(float *)(this + 9248) = *(float *)(this + 7292);
LABEL_68:
    *a7 = *(_DWORD *)(this + 9248);
    return;
  }
  if ( *(_DWORD *)(this + 7288) )
  {
    *(_DWORD *)(this + 9248) = 1065353216;
    *a7 = 1065353216;
  }
  else
  {
    v29 = *(float *)(this + 9248) - flt_7D1310 * a2 * 10.0;
    *(float *)(this + 9248) = v29;
    if ( v29 >= 0.0 )
      goto LABEL_68;
    *(_DWORD *)(this + 9248) = 0;
    *a7 = 0;
  }
}
