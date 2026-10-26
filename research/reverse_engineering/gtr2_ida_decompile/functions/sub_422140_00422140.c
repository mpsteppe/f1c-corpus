char __thiscall sub_422140(_DWORD *this)
{
  char *v2; // edi
  _DWORD *v3; // eax
  int v4; // ecx
  int v5; // eax
  double v6; // st7
  double v7; // st7
  double v8; // st6
  unsigned __int8 v10; // c0
  unsigned __int8 v11; // c3
  double v12; // st6
  double v13; // st6
  int v14; // ebp
  int v15; // eax
  _DWORD *v16; // ecx
  int v17; // edx
  int v18; // eax
  int v19; // edx
  int v20; // eax
  int v21; // edx
  int v22; // eax
  int v23; // edx
  int v24; // eax
  int v25; // edx
  int v26; // eax
  int v27; // edx
  int v28; // eax
  int v29; // edx
  int v30; // eax
  int v31; // edx
  int v32; // edx
  int v33; // eax
  int *v34; // edx
  int v35; // ebx
  int v36; // edi
  int v37; // eax
  _DWORD *v38; // ecx
  _DWORD *v39; // ecx
  char result; // al
  unsigned int v41; // kr00_4
  float v42; // [esp+10h] [ebp-24h]
  int v43; // [esp+14h] [ebp-20h]
  float v44; // [esp+18h] [ebp-1Ch]
  float v45; // [esp+1Ch] [ebp-18h]
  float v46; // [esp+24h] [ebp-10h]
  float v47; // [esp+28h] [ebp-Ch]
  float v48; // [esp+30h] [ebp-4h]

  v2 = (char *)(this + 4926);
  this[4939] = 1232348144;
  this[5012] = 0;
  this[4942] = -1;
  this[4926] = 0;
  this[4956] = 1232348144;
  this[5019] = 0;
  this[4959] = -1;
  this[4943] = 0;
  this[4973] = 1232348144;
  this[5026] = 0;
  this[4976] = -1;
  this[4960] = 0;
  this[4990] = 1232348144;
  this[5033] = 0;
  this[4993] = -1;
  this[4977] = 0;
  this[5007] = 1232348144;
  this[5040] = 0;
  this[5010] = -1;
  this[4994] = 0;
  v3 = (_DWORD *)sub_4FB0E0(this[1]);
  if ( v3 )
  {
    this[4939] = 1065353216;
    *(_DWORD *)v2 = *v3;
  }
  else
  {
    v4 = 0;
    v42 = 100.0;
    v43 = -1;
    if ( dword_757C10 > 0 )
    {
      v44 = *(float *)this;
      do
      {
        v5 = *(&dword_91E088 + v4);
        if ( LODWORD(v44) != v5 && *(_DWORD *)(v5 + 20852) < dword_91BCB0 )
        {
          v47 = *(float *)(v5 + 15988) - *((float *)this + 3997);
          v6 = *(float *)(v5 + 15996) - *((float *)this + 3999);
          v48 = v6;
          v7 = v6 * v48 + v47 * v47;
          if ( *(_DWORD *)dword_B640C8 == 6 && *(_DWORD *)(v5 + 19284) > this[4821] && v7 < 10000.0 )
          {
            v8 = v48 * *((float *)this + 5148) + v47 * *((float *)this + 5146);
            v45 = *((float *)this + 5146) * v8;
            v46 = *((float *)this + 5148) * v8;
            v12 = sqrt(v46 * v46 + v45 * v45);
            if ( !(v10 | v11) )
              v12 = -v12;
            if ( v12 > 0.0 && v12 < v42 )
            {
              v42 = v12;
              v43 = v4;
            }
          }
          if ( v7 >= *((float *)this + 5007)
            || (v13 = *((float *)this + 5146) * *((float *)this + 5146)
                    + *((float *)this + 5148) * *((float *)this + 5148),
                v13 == 0.0)
            || (v47 * *((float *)this + 5146) + v48 * *((float *)this + 5148)) / v13 >= -5.5 )
          {
            if ( v7 >= *((float *)this + 4939) )
            {
              if ( v7 >= *((float *)this + 4956) )
              {
                if ( v7 >= *((float *)this + 4973) )
                {
                  if ( v7 >= *((float *)this + 4990) )
                  {
                    if ( v7 < *((float *)this + 5007) )
                    {
                      *((float *)this + 5007) = v7;
                      this[4994] = *(&dword_91E088 + v4);
                    }
                  }
                  else
                  {
                    v32 = this[4990];
                    *((float *)this + 4990) = v7;
                    v33 = this[4977];
                    this[5007] = v32;
                    this[4994] = v33;
                    this[4977] = *(&dword_91E088 + v4);
                  }
                }
                else
                {
                  v29 = this[4977];
                  this[5007] = this[4990];
                  v30 = this[4973];
                  *((float *)this + 4973) = v7;
                  this[4994] = v29;
                  v31 = this[4960];
                  this[4990] = v30;
                  this[4977] = v31;
                  this[4960] = *(&dword_91E088 + v4);
                }
              }
              else
              {
                v24 = this[4977];
                this[5007] = this[4990];
                v25 = this[4973];
                this[4994] = v24;
                v26 = this[4960];
                this[4990] = v25;
                v27 = this[4956];
                *((float *)this + 4956) = v7;
                this[4977] = v26;
                v28 = this[4943];
                this[4973] = v27;
                this[4960] = v28;
                this[4943] = *(&dword_91E088 + v4);
              }
            }
            else
            {
              v17 = this[4977];
              this[5007] = this[4990];
              v18 = this[4973];
              this[4994] = v17;
              v19 = this[4960];
              this[4990] = v18;
              v20 = this[4956];
              this[4977] = v19;
              v21 = this[4943];
              this[4973] = v20;
              v22 = this[4939];
              *((float *)this + 4939) = v7;
              this[4960] = v21;
              v23 = *(_DWORD *)v2;
              this[4956] = v22;
              this[4943] = v23;
              *(_DWORD *)v2 = *(&dword_91E088 + v4);
            }
          }
        }
        v41 = __readeflags();
        __writeeflags(v41);
        ++v4;
      }
      while ( v4 < *(_DWORD *)(~dword_16C6D14 ^ 0xB56825FF) );
      if ( v43 != -1 )
      {
        this[5381] = *(&dword_91E088 + v43);
        *((float *)this + 5158) = v42;
        this[5157] = 160;
      }
    }
  }
  v14 = 5;
  do
  {
    if ( *(_DWORD *)v2 && *((float *)v2 + 13) < 999998.0 )
    {
      v15 = 0;
      v16 = this + 5013;
      while ( *(_DWORD *)(*(_DWORD *)v2 + 22468) != *v16 )
      {
        ++v15;
        v16 += 7;
        if ( v15 >= 5 )
          goto LABEL_40;
      }
      this[7 * v15 + 5012] = 1;
      *((_DWORD *)v2 + 16) = v15;
    }
LABEL_40:
    v2 += 68;
    --v14;
  }
  while ( v14 );
  v34 = this + 4942;
  v35 = 5;
  do
  {
    if ( *((float *)v34 - 3) <= 999998.0 && *v34 == -1 )
    {
      v36 = *(_DWORD *)(*(v34 - 16) + 22468);
      v37 = 0;
      v38 = this + 5012;
      while ( *v38 )
      {
        ++v37;
        v38 += 7;
        if ( v37 >= 5 )
          goto LABEL_49;
      }
      v39 = &this[7 * v37];
      v39[5015] = -971228160;
      v39[5011] = -1;
      v39[5016] = 0;
      v39[5013] = v36;
      this[7 * v37 + 5012] = 1;
      *v34 = v37;
    }
LABEL_49:
    v34 += 17;
    --v35;
  }
  while ( v35 );
  result = *((_BYTE *)this + 20888);
  if ( result )
  {
    result = 0;
    *((_BYTE *)this + 20888) = 0;
    this[5016] = 1140457472;
    this[5023] = 1140457472;
    this[5030] = 1140457472;
    this[5037] = 1140457472;
    this[5044] = 1140457472;
  }
  return result;
}
