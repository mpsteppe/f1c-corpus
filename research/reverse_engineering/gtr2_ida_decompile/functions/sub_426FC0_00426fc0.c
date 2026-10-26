char __thiscall sub_426FC0(_DWORD *this)
{
  float *v2; // ebx
  int v3; // eax
  _DWORD *v4; // eax
  int v5; // ecx
  double v6; // st7
  double v7; // st7
  int v8; // eax
  const char *v9; // eax
  int v10; // ebx
  char *v11; // eax
  int v12; // edx
  char v13; // cl
  const char *v14; // eax
  int v15; // edi
  int *v16; // ebp
  int v17; // edi
  int *v18; // ebp
  int i; // ecx
  _DWORD *v20; // edx
  int v21; // eax
  int v22; // ecx
  float *v23; // eax
  int v24; // eax
  int v25; // ebp
  _DWORD *v26; // edi
  double v27; // st7
  int v28; // ecx
  float *v29; // eax
  int v30; // eax
  int v31; // ebp
  _DWORD *v32; // edi
  double v33; // st7
  int v34; // ecx
  float *v35; // eax
  int v36; // edi
  char result; // al
  float v38; // [esp+10h] [ebp-408h]
  int v39; // [esp+10h] [ebp-408h]
  float v40; // [esp+10h] [ebp-408h]
  float v41; // [esp+10h] [ebp-408h]
  int v42; // [esp+14h] [ebp-404h]
  int v43; // [esp+14h] [ebp-404h]
  char v44[512]; // [esp+18h] [ebp-400h] BYREF
  _BYTE v45[512]; // [esp+218h] [ebp-200h] BYREF

  v2 = (float *)(this + 4);
  v3 = sub_578530(this + 4);
  this[5229] = sub_4FB6D0(v3);
  v4 = this + 5232;
  v5 = 36;
  do
  {
    *(v4 - 2) = dword_FADE18 + 2;
    *v4 = 1;
    *(v4 - 1) = 1176256410;
    v4[1] = 0;
    v4 += 4;
    --v5;
  }
  while ( v5 );
  if ( v2[4299] * v2[4298] * flt_91BDF4 >= 1.0 )
    v6 = v2[4299] * v2[4298] * flt_91BDF4;
  else
    v6 = 1.0;
  *((float *)this + 5376) = v6;
  v38 = (double)dword_B72E08 * 1.2;
  if ( v6 < v38 )
  {
    if ( v38 >= 1.0 )
      v7 = v38;
    else
      v7 = 1.0;
    *((float *)this + 5376) = v7;
  }
  this[5374] = 0;
  this[5378] = 1176255488;
  if ( *(_DWORD *)dword_B640C8 == 6 )
  {
    if ( sub_53A250(0) )
    {
      if ( sub_616630("PitStopStrategies") )
      {
        v8 = sub_616630((char *)(*this + 21568));
        if ( v8 )
        {
          strcpy(v44, (const char *)sub_48D380(v8));
          v9 = (const char *)sub_6331DF(v44, "-");
          v10 = atol(v9);
          if ( v10 >= 36 )
            v10 = 35;
          v11 = (char *)sub_6331DF(0, "/n");
          if ( v11 )
          {
            v12 = v45 - v11;
            do
            {
              v13 = *v11;
              v11[v12] = *v11;
              ++v11;
            }
            while ( v13 );
            v14 = (const char *)sub_6331DF(v45, ",");
            v15 = 0;
            if ( v14 )
            {
              v16 = this + 5230;
              do
              {
                if ( v15 >= v10 )
                  break;
                *v16 = atol(v14);
                ++v15;
                v16 += 4;
                v14 = (const char *)sub_6331DF(0, ",");
              }
              while ( v14 );
            }
            this[5228] = v15;
            this[4 * v15 + 5230] = dword_FADE18;
            v38 = (float)dword_B72E08;
          }
          v17 = 0;
          if ( (int)this[5228] > 0 )
          {
            v18 = this + 5230;
            do
            {
              if ( v38 != 0.0 )
                *v18 = (unsigned __int64)((double)*v18 / v38);
              ++v17;
              v18 += 4;
            }
            while ( v17 < this[5228] );
          }
          for ( i = 0; i < this[5228]; ++i )
          {
            v20 = &this[4 * i + 5230];
            if ( *v20 > dword_FADE18 - 5 )
            {
              this[5228] = i;
              if ( i < 36 )
              {
                v21 = 36 - i;
                i = 36;
                do
                {
                  *v20 = dword_FADE18;
                  v20 += 4;
                  --v21;
                }
                while ( v21 );
              }
            }
          }
          v22 = 0;
          if ( (int)this[5228] > 0 )
          {
            v23 = (float *)(this + 5230);
            do
            {
              v39 = *((_DWORD *)v23 + 4) - *(_DWORD *)v23;
              ++v22;
              v23 += 4;
              *(v23 - 3) = (double)v39 * *((float *)this + 5376);
            }
            while ( v22 < this[5228] );
          }
        }
      }
    }
    if ( !dword_B72E08 && !dword_B72F4C )
    {
      this[5228] = 0;
      this[5230] = dword_FADE18;
    }
    this[4 * this[5228] + 5233] = 8;
  }
  else
  {
    switch ( *(_DWORD *)dword_B640C8 )
    {
      case 0:
      case 1:
      case 2:
      case 5:
        v30 = (rand() % 2 != 0) + 3;
        v31 = 0;
        this[5228] = v30;
        v41 = 0.0;
        if ( v30 > 0 )
        {
          v32 = this + 5233;
          do
          {
            v33 = (double)(rand() % 15 + 5) + v41;
            v41 = v33;
            *(v32 - 3) = (unsigned __int64)v33;
            *v32 = 8;
            ++v31;
            v32 += 4;
          }
          while ( v31 < this[5228] );
        }
        v34 = 0;
        if ( (int)this[5228] > 0 )
        {
          v35 = (float *)(this + 5230);
          do
          {
            v43 = *((_DWORD *)v35 + 4) - *(_DWORD *)v35;
            ++v34;
            v35 += 4;
            *(v35 - 3) = ((double)v43 + 2.0) * *((float *)this + 5376);
          }
          while ( v34 < this[5228] );
        }
        break;
      case 3:
      case 4:
        v24 = (rand() % 2 != 0) + 3;
        v25 = 0;
        this[5228] = v24;
        v40 = 0.0;
        if ( v24 > 0 )
        {
          v26 = this + 5233;
          do
          {
            v27 = (double)(rand() % 4 + 6) + v40;
            v40 = v27;
            *(v26 - 3) = (unsigned __int64)v27;
            *v26 = 8;
            ++v25;
            v26 += 4;
          }
          while ( v25 < this[5228] );
        }
        v28 = 0;
        if ( (int)this[5228] > 0 )
        {
          v29 = (float *)(this + 5230);
          do
          {
            v42 = *((_DWORD *)v29 + 4) - *(_DWORD *)v29;
            ++v28;
            v29 += 4;
            *(v29 - 3) = ((double)v42 + 2.0) * *((float *)this + 5376);
          }
          while ( v28 < this[5228] );
        }
        break;
      default:
        break;
    }
  }
  if ( (int)this[5230] < 1 )
    this[5230] = 1;
  *((float *)this + 5378) = ((double)(int)this[5230] + 2.0) * *((float *)this + 5376);
  if ( !dword_B72E08 )
    this[5378] = 1065353216;
  if ( *((float *)this + 5378) > (double)*((float *)this + 4300) )
    this[5378] = this[4300];
  v36 = sub_421930(this);
  if ( *(_DWORD *)(*this + 22468) != *(_DWORD *)(dword_91E084 + 22468) )
  {
    sub_578550(this[5378]);
    return sub_57F2F0(v36, v36, 1);
  }
  result = byte_B6F118;
  if ( byte_B6F118 )
  {
    result = byte_B724C0;
    if ( byte_B724C0 )
    {
      sub_432AE0(&byte_B64150, 0, v36);
      sub_432AE0(&byte_B64150, 1, v36);
      return sub_57F2F0(v36, v36, 1);
    }
  }
  return result;
}
