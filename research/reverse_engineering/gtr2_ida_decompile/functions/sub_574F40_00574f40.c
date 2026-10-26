void __thiscall sub_574F40(int this)
{
  double v2; // st6
  double v3; // st7
  double v4; // st7
  double v5; // st6
  double v6; // st7
  double v7; // st7
  double v8; // st7
  unsigned __int8 v10; // c0
  unsigned __int8 v11; // c2
  int v12; // eax
  int v13; // eax
  double v14; // st7
  double v15; // st7
  double v16; // st7
  float v17; // [esp+8h] [ebp-4h]

  v2 = *(float *)(this + 17212);
  *(_DWORD *)(this + 16232) = 0;
  *(_DWORD *)(this + 16484) = 0;
  *(_DWORD *)(this + 16736) = 0;
  *(_DWORD *)(this + 16988) = 0;
  if ( v2 == 0.0 )
  {
    v3 = *(float *)(this + 17248);
    *(_DWORD *)(this + 16140) = 1065353216;
    if ( v3 > 0.0 )
    {
      v4 = *(float *)(this + 17248);
      v5 = v4 - *(float *)(this + 15928);
      *(float *)(this + 17248) = v5;
      if ( v5 <= *(float *)(this + 17260)
        && v4 > *(float *)(this + 17260)
        && *(float *)(this + 17212) < (double)*(float *)(this + 17220) )
      {
        sub_43A120();
      }
      if ( *(float *)(this + 17248) <= 0.0 && *(float *)(this + 17212) < (double)*(float *)(this + 17220) )
        *(_DWORD *)(this + 17212) = *(_DWORD *)(this + 17220);
    }
  }
  v6 = *(float *)(this + 17368) * *(float *)(this + 16140) + *(float *)(this + 17372);
  *(float *)(this + 16236) = v6;
  *(float *)(this + 16488) = v6;
  v7 = *(float *)(this + 17388) * *(float *)(this + 16140) + *(float *)(this + 17392);
  *(float *)(this + 16740) = v7;
  *(float *)(this + 16992) = v7;
  if ( *(float *)(this + 17180) <= 0.0 )
    *(_DWORD *)(this + 16132) = 0;
  v17 = sub_439DB0((float *)(this + 17228), *(float *)(this + 17212), *(float *)(this + 16132));
  *(float *)(this + 17224) = v17;
  if ( *(_DWORD *)(this + 17304) && *(float *)(this + 17212) > 0.0 )
  {
    if ( *(float *)(this + 17160) == *(float *)(this + 17212) )
    {
LABEL_15:
      v8 = -(v17 * *(float *)(this + 17264));
      goto LABEL_21;
    }
    if ( v10 | v11 )
    {
      if ( v17 >= 0.0 )
        goto LABEL_15;
      v8 = -(0.0 * *(float *)(this + 17264));
    }
    else
    {
      if ( v17 <= 0.0 )
        goto LABEL_15;
      v8 = -(0.0 * *(float *)(this + 17264));
    }
LABEL_21:
    v12 = *(_DWORD *)(this + 17244);
    if ( v12 )
    {
      v13 = v12 - 1;
      if ( v13 )
      {
        if ( v13 == 1 )
        {
          v14 = v8 * 0.5;
          *(float *)(this + 16232) = v14;
          *(float *)(this + 16484) = v14;
        }
      }
      else
      {
        v15 = v8 * 0.25;
        *(float *)(this + 16232) = v15;
        *(float *)(this + 16484) = v15;
        *(float *)(this + 16736) = v15;
        *(float *)(this + 16988) = v15;
      }
    }
    else
    {
      v16 = v8 * 0.5;
      *(float *)(this + 16736) = v16;
      *(float *)(this + 16988) = v16;
    }
  }
}
