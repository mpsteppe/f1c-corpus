int __thiscall sub_429960(_DWORD *this)
{
  int v2; // eax
  _DWORD *v3; // eax
  int v4; // ecx
  double v5; // st7
  double v6; // st7
  int v7; // eax
  int v8; // ebp
  int *v9; // edi
  int i; // ecx
  int v11; // edx
  int v12; // edi
  _DWORD *v13; // edx
  int v14; // eax
  int v15; // ecx
  float *v16; // eax
  int v17; // edx
  int v18; // edi
  double v19; // st7
  int v20; // eax
  char *v21; // ecx
  int v22; // edx
  double v23; // st6
  int v24; // ecx
  float *v25; // eax
  int v26; // eax
  int v27; // ecx
  int v28; // ebp
  _DWORD *v29; // edi
  double v30; // st7
  int v31; // ecx
  float *v32; // eax
  int result; // eax
  int v34; // eax
  float v35; // [esp+8h] [ebp-28h]
  float v36; // [esp+8h] [ebp-28h]
  int v37; // [esp+8h] [ebp-28h]
  float v38; // [esp+8h] [ebp-28h]
  int v39; // [esp+8h] [ebp-28h]
  float v40; // [esp+8h] [ebp-28h]
  int v41; // [esp+Ch] [ebp-24h]
  char v42[3]; // [esp+10h] [ebp-20h] BYREF
  _BYTE v43[29]; // [esp+13h] [ebp-1Dh] BYREF

  v2 = sub_4F1630(this + 3);
  this[4451] = sub_4A4830(v2);
  v3 = this + 4454;
  v4 = 5;
  do
  {
    *(v3 - 2) = dword_8ACF8C;
    *v3 = 1;
    *(v3 - 1) = 1176256410;
    v3[1] = 0;
    v3 += 4;
    --v4;
  }
  while ( v4 );
  v5 = *((float *)this + 3684) * flt_5EA40C;
  if ( v5 < 1.0 )
    v5 = 1.0;
  *((float *)this + 4474) = v5;
  v35 = (double)dword_7D0B64 * 1.2;
  if ( v5 < v35 )
  {
    if ( v35 >= 1.0 )
      v6 = v35;
    else
      v6 = 1.0;
    *((float *)this + 4474) = v6;
  }
  this[4472] = 0;
  this[4476] = 1176255488;
  if ( dword_7C56A4 == 7 )
  {
    if ( sub_4C5840(0) )
    {
      if ( sub_5679C0(aPitstopstrateg) )
      {
        v7 = sub_5679C0(*this + 17952);
        if ( v7 )
        {
          strcpy(v42, (const char *)sub_567970(v7));
          v36 = (float)dword_7D0B64;
          switch ( v42[0] )
          {
            case '1':
              this[4450] = v42[0] - 48;
              sub_5887ED(v43, "%d", this + 4452);
              this[4456] = dword_8ACF8C;
              break;
            case '2':
              this[4450] = 2;
              sub_5887ED(v43, "%d,%d", this + 4452, this + 4456);
              this[4460] = dword_8ACF8C;
              break;
            case '3':
              this[4450] = 3;
              sub_5887ED(v43, "%d,%d,%d", this + 4452, this + 4456, this + 4460);
              this[4464] = dword_8ACF8C;
              break;
            default:
              this[4450] = 4;
              sub_5887ED(v43, "%d,%d,%d,%d", this + 4452, this + 4456, this + 4460, this + 4464);
              this[4468] = dword_8ACF8C;
              break;
          }
          v8 = 0;
          if ( (int)this[4450] > 0 )
          {
            v9 = this + 4452;
            do
            {
              if ( v36 == 0.0 )
                *v9 = 0;
              else
                *v9 = sub_587BDC((double)*v9 / v36);
              ++v8;
              v9 += 4;
            }
            while ( v8 < this[4450] );
          }
          for ( i = 0; i < this[4450]; ++i )
          {
            v11 = 4 * (i + 1113);
            v12 = this[v11];
            v13 = &this[v11];
            if ( v12 > dword_8ACF8C - 5 )
            {
              this[4450] = i;
              if ( i < 5 )
              {
                v14 = 5 - i;
                i = 5;
                do
                {
                  *v13 = dword_8ACF8C;
                  v13 += 4;
                  --v14;
                }
                while ( v14 );
              }
            }
          }
          v15 = 0;
          if ( (int)this[4450] > 0 )
          {
            v16 = (float *)(this + 4452);
            do
            {
              v37 = *((_DWORD *)v16 + 4) - *(_DWORD *)v16;
              ++v15;
              v16 += 4;
              *(v16 - 3) = (double)v37 * *((float *)this + 4474);
            }
            while ( v15 < this[4450] );
          }
        }
      }
    }
    if ( !dword_7D0B64 && !dword_7D0C60 )
    {
      this[4450] = 0;
      this[4452] = dword_8ACF8C;
    }
    this[4 * this[4450] + 4455] = 8;
  }
  else
  {
    switch ( dword_7C56A4 )
    {
      case 0:
      case 1:
      case 2:
      case 6:
        v26 = (sub_5884ED(0) % 2 != 0) + 3;
        v28 = 0;
        this[4450] = v26;
        v40 = 0.0;
        if ( v26 > 0 )
        {
          v29 = this + 4455;
          do
          {
            v30 = (double)(sub_5884ED(v27) % 5 + 3) + v40;
            v40 = v30;
            *(v29 - 3) = sub_587BDC(v30);
            *v29 = 8;
            ++v28;
            v29 += 4;
          }
          while ( v28 < this[4450] );
        }
        v31 = 0;
        if ( (int)this[4450] > 0 )
        {
          v32 = (float *)(this + 4452);
          do
          {
            v41 = *((_DWORD *)v32 + 4) - *(_DWORD *)v32;
            ++v31;
            v32 += 4;
            *(v32 - 3) = ((double)v41 + 2.0) * *((float *)this + 4474);
          }
          while ( v31 < this[4450] );
        }
        break;
      case 3:
      case 4:
      case 5:
        v17 = (sub_5884ED(0) % 21 != 0) + 3;
        v18 = 0;
        this[4450] = v17;
        if ( v17 > 0 )
        {
          v38 = 12.0 / (double)v17;
          v19 = v38 + 2.0;
          v20 = sub_587BDC(v19);
          v21 = (char *)(this + 4453);
          v22 = v20 - 1;
          do
          {
            *((_DWORD *)v21 - 1) = v22;
            v23 = v19 * *((float *)this + 4474);
            *((_DWORD *)v21 + 2) = 8;
            ++v18;
            v22 += v20;
            *(float *)v21 = v23;
            v21 += 16;
          }
          while ( v18 < this[4450] );
        }
        v24 = 0;
        if ( (int)this[4450] > 0 )
        {
          v25 = (float *)(this + 4452);
          do
          {
            v39 = *((_DWORD *)v25 + 4) - *(_DWORD *)v25;
            ++v24;
            v25 += 4;
            *(v25 - 3) = ((double)v39 + 2.0) * *((float *)this + 4474);
          }
          while ( v24 < this[4450] );
        }
        break;
      default:
        break;
    }
  }
  if ( (int)this[4452] < 1 )
    this[4452] = 1;
  *((float *)this + 4476) = ((double)(int)this[4452] + 2.0) * *((float *)this + 4474);
  if ( !dword_7D0B64 )
    this[4476] = 1065353216;
  if ( *((float *)this + 3682) < (double)*((float *)this + 4476) )
    *((float *)this + 4476) = *((float *)this + 3682);
  result = *this;
  if ( *(_DWORD *)(*this + 13000) == 1 )
  {
    sub_4F1890(this[4476]);
    v34 = sub_429FD0(this);
    return sub_4F1A60(v34, 1);
  }
  return result;
}
