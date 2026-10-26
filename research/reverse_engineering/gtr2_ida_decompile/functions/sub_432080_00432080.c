void __thiscall sub_432080(_DWORD *this, int a2, int a3)
{
  int v3; // edx
  int v5; // eax
  int v6; // ebx
  int v7; // edi
  int v8; // eax
  int v9; // ecx
  int v10; // ecx
  int v11; // ecx
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // eax
  char v24; // al
  char v25; // al
  char v26; // al
  char v27; // al
  int v28; // ebx
  int v29; // edi
  char v30; // al
  char v31; // al
  int v32; // edi
  int v33; // ecx
  int v34; // eax
  int v35; // eax
  int v36; // ecx
  int v37; // eax
  int *v38; // edi
  int v39; // ebx
  int v40; // ecx
  int v41; // eax
  int v42; // eax
  int v43; // eax
  int v44; // ecx
  int v45; // eax
  int v46; // eax
  bool v47; // bl
  char v48; // cl
  char *v49; // ecx
  int v50; // edx
  int v51; // ecx
  int v52; // edx
  int v53; // ecx
  long double v54; // st7
  char v55; // [esp+Fh] [ebp-79h]
  double v56; // [esp+10h] [ebp-78h]
  double k; // [esp+10h] [ebp-78h]
  double v58; // [esp+10h] [ebp-78h]
  double i; // [esp+10h] [ebp-78h]
  double v60; // [esp+10h] [ebp-78h]
  int v61; // [esp+10h] [ebp-78h]
  double v62; // [esp+18h] [ebp-70h]
  double v63; // [esp+18h] [ebp-70h]
  double j; // [esp+18h] [ebp-70h]
  double v65; // [esp+20h] [ebp-68h]
  char String[32]; // [esp+28h] [ebp-60h] BYREF
  char String1[64]; // [esp+48h] [ebp-40h] BYREF

  v3 = a3;
  if ( a2 == -1 || a3 == -1 )
  {
    v55 = 1;
    v5 = 45;
    v6 = 51;
  }
  else
  {
    v55 = 0;
    if ( a2 != 4 || a3 < 45 || a3 > 51 )
      goto LABEL_19;
    v5 = a3;
    v6 = a3;
  }
  v7 = v5;
  if ( v5 <= v6 )
  {
    v8 = (int)&this[16 * v5 + 753];
    do
    {
      if ( v7 < 51 )
      {
        if ( *(_BYTE *)(v8 + 72) )
        {
          v9 = *(_DWORD *)(v8 + 64);
          if ( *(_DWORD *)v8 >= v9 )
          {
            v3 = a3;
            *(_DWORD *)v8 = v9 - 1 < 0 ? 0 : v9 - 1;
          }
        }
      }
      if ( v7 > 45 )
      {
        v10 = *(_DWORD *)(v8 - 64);
        if ( *(_DWORD *)v8 <= v10 )
        {
          v11 = v10 + 1;
          if ( *(_DWORD *)(v8 - 4) - 1 < v11 )
            v11 = *(_DWORD *)(v8 - 4) - 1;
          v3 = a3;
          *(_DWORD *)v8 = v11;
        }
      }
      ++v7;
      v8 += 64;
    }
    while ( v7 <= v6 );
  }
LABEL_19:
  if ( *((_BYTE *)this + 6921) )
  {
    if ( this[1040] == this[1056] )
    {
      v12 = this[1041];
      if ( this[1057] != v12 )
      {
        this[1057] = v12;
        *((_BYTE *)this + 6952) = 1;
        *(_BYTE *)this = 1;
      }
    }
    if ( this[1072] == this[1088] )
    {
      v13 = this[1073];
      if ( this[1089] != v13 )
      {
        this[1089] = v13;
        *((_BYTE *)this + 6952) = 1;
        *(_BYTE *)this = 1;
      }
    }
    if ( this[1136] == this[1152] )
    {
      v14 = this[1137];
      if ( this[1153] != v14 )
      {
        this[1153] = v14;
        *((_BYTE *)this + 6952) = 1;
        *(_BYTE *)this = 1;
      }
    }
    if ( this[1168] == this[1184] )
    {
      v15 = this[1169];
      if ( this[1185] != v15 )
      {
        this[1185] = v15;
        *((_BYTE *)this + 6952) = 1;
        *(_BYTE *)this = 1;
      }
    }
    if ( this[128] == this[144] )
    {
      v16 = this[129];
      if ( this[145] != v16 )
      {
        this[145] = v16;
        *((_BYTE *)this + 6952) = 1;
        *(_BYTE *)this = 1;
      }
    }
    if ( this[160] == this[176] )
    {
      v17 = this[161];
      if ( this[177] != v17 )
      {
        this[177] = v17;
        *((_BYTE *)this + 6952) = 1;
        *(_BYTE *)this = 1;
      }
    }
    if ( this[304] == this[320] )
    {
      v18 = this[305];
      if ( this[321] != v18 )
      {
        this[321] = v18;
        *((_BYTE *)this + 6952) = 1;
        *(_BYTE *)this = 1;
      }
    }
    if ( this[336] == this[352] )
    {
      v19 = this[337];
      if ( this[353] != v19 )
      {
        this[353] = v19;
        *((_BYTE *)this + 6952) = 1;
        *(_BYTE *)this = 1;
      }
    }
    if ( this[480] == this[496] )
    {
      v20 = this[481];
      if ( this[497] != v20 )
      {
        this[497] = v20;
        *((_BYTE *)this + 6952) = 1;
        *(_BYTE *)this = 1;
      }
    }
    if ( this[512] == this[528] )
    {
      v21 = this[513];
      if ( this[529] != v21 )
      {
        this[529] = v21;
        *((_BYTE *)this + 6952) = 1;
        *(_BYTE *)this = 1;
      }
    }
    if ( this[656] == this[672] )
    {
      v22 = this[657];
      if ( this[673] != v22 )
      {
        this[673] = v22;
        *((_BYTE *)this + 6952) = 1;
        *(_BYTE *)this = 1;
      }
    }
    if ( this[688] == this[704] )
    {
      v23 = this[689];
      if ( this[705] != v23 )
      {
        this[705] = v23;
        *((_BYTE *)this + 6952) = 1;
        *(_BYTE *)this = 1;
      }
    }
  }
  else
  {
    v24 = a2 == -1 && v3 == 18;
    sub_432000((int)(this + 1036), (int)(this + 1052), v24);
    v25 = a2 == -1 && a3 == 20;
    sub_432000((int)(this + 1068), (int)(this + 1084), v25);
    v26 = a2 == -1 && a3 == 24;
    sub_432000((int)(this + 1132), (int)(this + 1148), v26);
    v27 = a2 == -1 && a3 == 26;
    sub_432000((int)(this + 1164), (int)(this + 1180), v27);
    v28 = 0;
    v29 = (int)(this + 124);
    do
    {
      v30 = a2 == v28 && a3 == 5;
      sub_432000(v29, v29 + 64, v30);
      v31 = a2 == v28 && a3 == 7;
      sub_432000(v29 + 128, v29 + 192, v31);
      ++v28;
      v29 += 704;
    }
    while ( v28 < 4 );
  }
  if ( this[1732] == 1 )
  {
    v32 = a2;
    if ( !v55 )
    {
      if ( a2 != 4 )
      {
LABEL_97:
        if ( a2 != 2 && a2 != 3 || a3 != 4 )
        {
LABEL_117:
          if ( v32 != 4 )
            goto LABEL_140;
LABEL_118:
          if ( a3 != 3 )
            goto LABEL_125;
          goto LABEL_119;
        }
LABEL_100:
        if ( a2 == 2 || a2 == 3 )
          v36 = a2;
        else
          v36 = 2;
        if ( a2 == 2 || a2 == 3 )
          v37 = a2;
        else
          v37 = 3;
        if ( v36 <= v37 )
        {
          v38 = &this[176 * v36 + 113];
          v39 = v37 - v36 + 1;
          do
          {
            if ( !sub_53A2B0((int)String, 32, "MinRearSpring", 0) )
            {
              v58 = atof(String);
              if ( (double)*v38 * *(double *)(v38 - 3) + *(double *)(v38 - 5) <= v58 )
              {
                v40 = *(v38 - 1) - 1;
                do
                {
                  if ( *v38 >= v40 )
                    break;
                  ++*v38;
                }
                while ( (double)*v38 * *(double *)(v38 - 3) + *(double *)(v38 - 5) <= v58 );
              }
            }
            v38 += 176;
            --v39;
          }
          while ( v39 );
        }
        v32 = a2;
        if ( v55 )
        {
LABEL_119:
          if ( !sub_53A2B0((int)String, 32, "MaxRearWeight", 0) )
          {
            for ( i = atof(String);
                  (double)(int)this[801] * *((double *)this + 399) + *((double *)this + 398) >= i;
                  this[801] = v41 - 1 )
            {
              v41 = this[801];
              if ( v41 <= 0 )
                break;
            }
          }
          if ( v55 )
            goto LABEL_126;
          if ( v32 != 4 )
          {
LABEL_140:
            v47 = 0;
            if ( !sub_53A2B0((int)String1, 64, "Track Type", 0) )
              v47 = _stricmp(String1, "Road Course") == 0;
            v48 = v55;
            if ( v55 )
              goto LABEL_145;
            if ( v32 == 4 )
            {
LABEL_161:
              if ( (unsigned int)a3 > 1 )
                return;
              goto LABEL_162;
            }
            if ( a3 == 2 )
            {
LABEL_145:
              if ( v47 )
              {
                v49 = (char *)(this + 428);
                v63 = (double)(int)this[433] * *((double *)this + 215) + *((double *)this + 214);
                if ( v63 < 0.1523746 )
                {
                  v60 = (double)(int)this[609] * *((double *)this + 303) + *((double *)this + 302);
                  if ( v60 < 0.1523746 )
                  {
                    if ( v32 != 2 && (v32 == 3 || v63 <= v60) )
                      v49 = (char *)(this + 604);
                    if ( *((_DWORD *)v49 + 5) < *((_DWORD *)v49 + 4) )
                    {
                      do
                      {
                        v50 = *((_DWORD *)v49 + 5);
                        if ( (double)v50 * *((double *)v49 + 1) + *(double *)v49 >= 0.1523746 )
                          break;
                        *((_DWORD *)v49 + 5) = v50 + 1;
                      }
                      while ( v50 + 1 < *((_DWORD *)v49 + 4) );
                    }
                  }
                }
              }
              else if ( this[609] < this[608] )
              {
                do
                {
                  if ( (double)(int)this[609] * *((double *)this + 303) + *((double *)this + 302) >= 0.1523746 )
                    break;
                  v51 = this[609] + 1;
                  this[609] = v51;
                }
                while ( v51 < this[608] );
              }
              v48 = v55;
              if ( v55 )
              {
LABEL_162:
                if ( !v47 )
                {
                  this[753] = 0;
                  this[769] = 0;
                }
                if ( v48 )
                {
LABEL_167:
                  v52 = this[257];
                  v53 = 0;
                  v61 = 0;
                  v65 = (double)(int)this[81] * *((double *)this + 39)
                      + *((double *)this + 38)
                      - ((double)(int)this[433] * *((double *)this + 215)
                       + *((double *)this + 214))
                      + (double)(int)this[609] * *((double *)this + 303)
                      + *((double *)this + 302);
                  for ( j = 1.797693134862316e308; v53 < this[256]; v61 = v53 )
                  {
                    this[257] = v53;
                    v54 = fabs((double)v61 * *((double *)this + 127) + *((double *)this + 126) - v65);
                    if ( v54 < j )
                    {
                      j = v54;
                      v52 = v53;
                    }
                    ++v53;
                  }
                  this[257] = v52;
                  return;
                }
                if ( v32 == 4 )
                  return;
LABEL_166:
                if ( a3 != 2 )
                  return;
                goto LABEL_167;
              }
            }
            if ( v32 != 4 )
              goto LABEL_166;
            goto LABEL_161;
          }
LABEL_125:
          if ( a3 == 5 )
          {
LABEL_126:
            if ( !sub_53A2B0((int)String, 32, "MaxFuelCapacity", 0) )
            {
              v62 = atof(String);
              if ( (double)(this[832] - 1) * *((double *)this + 415) + *((double *)this + 414) >= v62 )
              {
                do
                {
                  v42 = this[832];
                  if ( v42 <= 1 )
                    break;
                  v43 = v42 - 1;
                  this[832] = v43;
                }
                while ( (double)(v43 - 1) * *((double *)this + 415) + *((double *)this + 414) >= v62 );
              }
              v44 = this[833];
              v45 = this[832] - 1;
              if ( v44 >= 0 )
              {
                if ( v44 > v45 )
                  this[833] = v45;
              }
              else
              {
                this[833] = 0;
              }
            }
            if ( v55 || v32 == 4 && a3 == 5 )
            {
              if ( *(_DWORD *)dword_B640C8 )
              {
                v46 = this[832];
                if ( v46 >= 1 )
                  this[833] = v46 - 1;
              }
            }
            goto LABEL_140;
          }
          goto LABEL_140;
        }
        goto LABEL_117;
      }
      if ( a3 != 29 )
        goto LABEL_118;
    }
    if ( !sub_53A2B0((int)String, 32, "MinRearSpoilerAngle", 0) )
    {
      v56 = atof(String);
      if ( (double)(int)this[1217] * *((double *)this + 607) + *((double *)this + 606) <= v56 )
      {
        v33 = this[1216] - 1;
        do
        {
          v34 = this[1217];
          if ( v34 >= v33 )
            break;
          this[1217] = v34 + 1;
        }
        while ( (double)(int)this[1217] * *((double *)this + 607) + *((double *)this + 606) <= v56 );
      }
    }
    if ( !sub_53A2B0((int)String, 32, "MaxRearSpoilerAngle", 0) )
    {
      for ( k = atof(String);
            (double)(int)this[1217] * *((double *)this + 607) + *((double *)this + 606) >= k;
            this[1217] = v35 - 1 )
      {
        v35 = this[1217];
        if ( v35 <= 0 )
          break;
      }
    }
    if ( v55 )
      goto LABEL_100;
    goto LABEL_97;
  }
}
