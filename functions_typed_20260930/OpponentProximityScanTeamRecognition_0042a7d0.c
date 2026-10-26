char __thiscall sub_42A7D0(char *this)
{
  _DWORD *v2; // eax
  _DWORD *v3; // ecx
  int v4; // edx
  _DWORD *v5; // eax
  int i; // edi
  int v7; // ecx
  float v8; // edx
  int v9; // eax
  double v10; // st7
  int v11; // eax
  int v12; // eax
  int v13; // ecx
  int v14; // edx
  int v15; // eax
  int v16; // ecx
  int v17; // edx
  int v18; // eax
  int v19; // ecx
  int v20; // edx
  int v21; // eax
  int v22; // ecx
  int v23; // edx
  int v24; // eax
  int v25; // ecx
  int v26; // edx
  int v27; // eax
  char *v28; // edi
  int v29; // ebp
  int v30; // eax
  _DWORD *v31; // ecx
  int *v32; // edx
  int v33; // ebx
  int v34; // edi
  int v35; // ecx
  _DWORD *v36; // eax
  char *v37; // eax
  _DWORD *v38; // eax
  int v39; // ecx
  float v41; // [esp+8h] [ebp-10h]
  float v42[2]; // [esp+Ch] [ebp-Ch] BYREF
  float v43; // [esp+14h] [ebp-4h]

  v2 = this + 16820;
  v3 = this + 17100;
  v4 = 5;
  do
  {
    *(v2 - 3) = 1232348144;
    *v3 = 0;
    *v2 = -1;
    *(v2 - 16) = 0;
    v3 += 7;
    v2 += 17;
    --v4;
  }
  while ( v4 );
  v5 = (_DWORD *)FindNearestVehicle(*((_DWORD *)this + 1));
  if ( v5 )
  {
    *((_DWORD *)this + 4202) = 1065353216;
    *((_DWORD *)this + 4189) = *v5;
  }
  else
  {
    for ( i = 0; i < dword_5C329C; ++i )
    {
      v7 = dword_7C54F0[i];
      if ( *(_DWORD *)this != v7 )
      {
        v42[0] = *(float *)(v7 + 13536);
        v8 = *(float *)(v7 + 13544);
        v42[1] = *(float *)(v7 + 13540);
        v9 = *(_DWORD *)(v7 + 17744);
        v43 = v8;
        if ( v9 < dword_5EA2CC )
        {
          v42[0] = v42[0] - *((float *)this + 3384);
          v10 = v43 - *((float *)this + 3386);
          v43 = v10;
          v41 = v10 * v43 + v42[0] * v42[0];
          if ( (unsigned __int8)sub_4C7BD0(v7) )
          {
            if ( v41 < 625.0 && dword_7C56A4 == 7 )
            {
              v11 = dword_7C54F0[i];
              if ( *(_DWORD *)(v11 + 16444) > *((_DWORD *)this + 4111) )
              {
                *((_DWORD *)this + 4479) = v11;
                if ( (*(float *)(dword_7C54F0[i] + 13544) - *((float *)this + 3386)) * *((float *)this + 4387)
                   - (*(float *)(dword_7C54F0[i] + 13536) - *((float *)this + 3384)) * *((float *)this + 4389) <= 0.0 )
                  *((_DWORD *)this + 4360) = -1071644672;
                else
                  *((_DWORD *)this + 4360) = 1075838976;
              }
            }
          }
          if ( v41 >= (double)*((float *)this + 4270)
            || F_2DVectorDirectionProjection((float *)this + 4387, v42) >= -5.5 )
          {
            if ( v41 >= (double)*((float *)this + 4202) )
            {
              if ( v41 >= (double)*((float *)this + 4219) )
              {
                if ( v41 >= (double)*((float *)this + 4236) )
                {
                  if ( v41 >= (double)*((float *)this + 4253) )
                  {
                    if ( v41 < (double)*((float *)this + 4270) )
                    {
                      *((float *)this + 4270) = v41;
                      *((_DWORD *)this + 4257) = dword_7C54F0[i];
                    }
                  }
                  else
                  {
                    v27 = *((_DWORD *)this + 4240);
                    *((_DWORD *)this + 4270) = *((_DWORD *)this + 4253);
                    *((_DWORD *)this + 4257) = v27;
                    *((float *)this + 4253) = v41;
                    *((_DWORD *)this + 4240) = dword_7C54F0[i];
                  }
                }
                else
                {
                  v24 = *((_DWORD *)this + 4240);
                  v25 = *((_DWORD *)this + 4236);
                  *((_DWORD *)this + 4270) = *((_DWORD *)this + 4253);
                  v26 = *((_DWORD *)this + 4223);
                  *((_DWORD *)this + 4257) = v24;
                  *((_DWORD *)this + 4253) = v25;
                  *((_DWORD *)this + 4240) = v26;
                  *((float *)this + 4236) = v41;
                  *((_DWORD *)this + 4223) = dword_7C54F0[i];
                }
              }
              else
              {
                v19 = *((_DWORD *)this + 4240);
                v20 = *((_DWORD *)this + 4236);
                *((_DWORD *)this + 4270) = *((_DWORD *)this + 4253);
                v21 = *((_DWORD *)this + 4223);
                *((_DWORD *)this + 4257) = v19;
                v22 = *((_DWORD *)this + 4219);
                *((_DWORD *)this + 4253) = v20;
                v23 = *((_DWORD *)this + 4206);
                *((_DWORD *)this + 4240) = v21;
                *((_DWORD *)this + 4236) = v22;
                *((_DWORD *)this + 4223) = v23;
                *((float *)this + 4219) = v41;
                *((_DWORD *)this + 4206) = dword_7C54F0[i];
              }
            }
            else
            {
              v12 = *((_DWORD *)this + 4240);
              v13 = *((_DWORD *)this + 4236);
              *((_DWORD *)this + 4270) = *((_DWORD *)this + 4253);
              v14 = *((_DWORD *)this + 4223);
              *((_DWORD *)this + 4257) = v12;
              v15 = *((_DWORD *)this + 4219);
              *((_DWORD *)this + 4253) = v13;
              v16 = *((_DWORD *)this + 4206);
              *((_DWORD *)this + 4240) = v14;
              v17 = *((_DWORD *)this + 4202);
              *((_DWORD *)this + 4236) = v15;
              v18 = *((_DWORD *)this + 4189);
              *((_DWORD *)this + 4223) = v16;
              *((_DWORD *)this + 4219) = v17;
              *((_DWORD *)this + 4206) = v18;
              *((float *)this + 4202) = v41;
              *((_DWORD *)this + 4189) = dword_7C54F0[i];
            }
          }
        }
      }
    }
  }
  v28 = this + 16756;
  v29 = 5;
  do
  {
    if ( *(_DWORD *)v28 && *((float *)v28 + 13) < 999998.0 )
    {
      v30 = 0;
      v31 = this + 17104;
      while ( *(_DWORD *)(*(_DWORD *)v28 + 18580) != *v31 )
      {
        ++v30;
        v31 += 7;
        if ( v30 >= 5 )
          goto LABEL_36;
      }
      *(_DWORD *)&this[28 * v30 + 17100] = 1;
      *((_DWORD *)v28 + 16) = v30;
    }
LABEL_36:
    v28 += 68;
    --v29;
  }
  while ( v29 );
  v32 = (int *)(this + 16820);
  v33 = 5;
  do
  {
    if ( *((float *)v32 - 3) <= 999998.0 && *v32 == -1 )
    {
      v34 = *(_DWORD *)(*(v32 - 16) + 18580);
      v35 = 0;
      v36 = this + 17100;
      while ( *v36 )
      {
        ++v35;
        v36 += 7;
        if ( v35 >= 5 )
          goto LABEL_45;
      }
      v37 = &this[28 * v35];
      *((_DWORD *)v37 + 4278) = -971228160;
      *((_DWORD *)v37 + 4274) = -1;
      *((_DWORD *)v37 + 4279) = 0;
      *((_DWORD *)v37 + 4276) = v34;
      *((_DWORD *)v37 + 4275) = 1;
      *v32 = v35;
    }
LABEL_45:
    v32 += 17;
    --v33;
  }
  while ( v33 );
  LOBYTE(v38) = this[17784];
  if ( (_BYTE)v38 )
  {
    this[17784] = 0;
    v38 = this + 17116;
    v39 = 5;
    do
    {
      *v38 = 1140457472;
      v38 += 7;
      --v39;
    }
    while ( v39 );
  }
  return (char)v38;
}

