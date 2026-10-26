double __thiscall sub_4E88B0(int this)
{
  int v1; // eax
  int v2; // eax
  double v3; // st7
  double result; // st7
  double v5; // st6
  double v6; // st5
  double v7; // st7
  double v8; // st6
  double v9; // st5
  double v10; // st7
  double v11; // st6
  double v12; // st6
  double v13; // st5
  float v14; // [esp+0h] [ebp-Ch]
  float v15; // [esp+4h] [ebp-8h]
  float v16; // [esp+4h] [ebp-8h]
  float v17; // [esp+4h] [ebp-8h]
  float v18; // [esp+8h] [ebp-4h]

  v1 = *(_DWORD *)(this + 14772);
  if ( v1 )
  {
    v2 = v1 - 1;
    if ( v2 )
    {
      if ( v2 == 1 )
      {
        v3 = *(float *)(this + 14792) * *(float *)(this + 14760) * 0.5;
        v18 = *(float *)(this + 14592) * *(float *)(this + 14584) * *(float *)(this + 14516);
        v15 = *(float *)(this + 14344) * *(float *)(this + 14336) * *(float *)(this + 14268);
        v14 = (*(float *)(this + 14088) * *(float *)(this + 14020) + v3) * *(float *)(this + 14096);
        result = (v3 + *(float *)(this + 13840) * *(float *)(this + 13772)) * *(float *)(this + 13848);
        if ( result <= v14 )
          v5 = v14;
        else
          v5 = result;
        if ( v15 <= (double)v18 )
          v6 = v18;
        else
          v6 = v15;
        if ( v5 > v6 )
          goto LABEL_11;
        if ( v15 > (double)v18 )
        {
          result = v15;
          goto LABEL_24;
        }
      }
      goto LABEL_23;
    }
    v7 = *(float *)(this + 14792) * *(float *)(this + 14760) * 0.25;
    v14 = (*(float *)(this + 14584) * *(float *)(this + 14516) + v7) * *(float *)(this + 14592);
    v16 = (*(float *)(this + 14336) * *(float *)(this + 14268) + v7) * *(float *)(this + 14344);
    v18 = (*(float *)(this + 14088) * *(float *)(this + 14020) + v7) * *(float *)(this + 14096);
    result = (v7 + *(float *)(this + 13840) * *(float *)(this + 13772)) * *(float *)(this + 13848);
    if ( result <= v18 )
      v8 = v18;
    else
      v8 = result;
    if ( v16 <= (double)v14 )
      v9 = v14;
    else
      v9 = v16;
    if ( v8 > v9 )
    {
      if ( result > v18 )
        goto LABEL_24;
      goto LABEL_23;
    }
    if ( v16 <= (double)v14 )
    {
LABEL_12:
      result = v14;
      goto LABEL_24;
    }
    result = v16;
  }
  else
  {
    v10 = *(float *)(this + 14792) * *(float *)(this + 14760) * 0.5;
    v14 = (*(float *)(this + 14584) * *(float *)(this + 14516) + v10) * *(float *)(this + 14592);
    result = (v10 + *(float *)(this + 14336) * *(float *)(this + 14268)) * *(float *)(this + 14344);
    v17 = *(float *)(this + 14096) * *(float *)(this + 14088) * *(float *)(this + 14020);
    v11 = *(float *)(this + 13848) * *(float *)(this + 13840) * *(float *)(this + 13772);
    v18 = v11;
    if ( v11 <= v17 )
      v12 = v17;
    else
      v12 = v18;
    if ( result <= v14 )
      v13 = v14;
    else
      v13 = result;
    if ( v12 <= v13 )
    {
LABEL_11:
      if ( result > v14 )
        goto LABEL_24;
      goto LABEL_12;
    }
    if ( v18 > (double)v17 )
    {
LABEL_23:
      result = v18;
      goto LABEL_24;
    }
    result = v17;
  }
LABEL_24:
  if ( result < 0.0 )
    return 0.0;
  if ( result > 1.0 )
    return 1.0;
  return result;
}

