void __thiscall sub_4F8BD0(int this)
{
  int v2; // eax
  int v3; // ecx
  int v4; // eax
  double v5; // st7
  float v6; // edx
  float *v7; // ebp
  double v8; // st6
  long double v9; // st5
  double v10; // st7
  char v12; // c0
  int v13; // eax
  double v14; // st6
  double v15; // st7
  float v16; // edx
  int v17; // eax
  int v18; // edx
  float *v19; // eax
  float v20; // ecx
  int v21; // edx
  int v22; // ebp
  int v23; // edi
  int v24; // eax
  int v25; // eax
  int v26; // ecx
  _BYTE *v27; // ecx
  int v28; // edi
  double v29; // st7
  float *v30; // edx
  int v31; // eax
  int v32; // ecx
  double v33; // st7
  float v34; // ecx
  float v35; // eax
  float *v36; // edx
  float *v37; // edi
  _DWORD *v38; // eax
  float *v39; // eax
  int v40; // edx
  float *v41; // eax
  float v42; // ecx
  int v43; // edx
  float v44; // ecx
  float v45; // edx
  float v46; // [esp+10h] [ebp-94h]
  float v47; // [esp+14h] [ebp-90h]
  float v48; // [esp+28h] [ebp-7Ch]
  int v49; // [esp+30h] [ebp-74h]
  int v50; // [esp+34h] [ebp-70h]
  int v51; // [esp+40h] [ebp-64h] BYREF
  float v52; // [esp+44h] [ebp-60h]
  float v53; // [esp+48h] [ebp-5Ch]
  float v54; // [esp+4Ch] [ebp-58h] BYREF
  float v55; // [esp+50h] [ebp-54h]
  float v56; // [esp+54h] [ebp-50h]
  float v57; // [esp+58h] [ebp-4Ch] BYREF
  float v58; // [esp+5Ch] [ebp-48h]
  float v59; // [esp+60h] [ebp-44h]
  int v60[3]; // [esp+64h] [ebp-40h] BYREF
  int v61; // [esp+70h] [ebp-34h] BYREF
  int v62; // [esp+74h] [ebp-30h]
  float v63; // [esp+78h] [ebp-2Ch]
  int v64; // [esp+7Ch] [ebp-28h]
  float v65[9]; // [esp+80h] [ebp-24h] BYREF

  if ( *(_BYTE *)(this + 240) )
  {
    v2 = *(_DWORD *)(this + 160);
    if ( !v2 || *(_DWORD *)(v2 + 88) )
    {
      v3 = *(_DWORD *)(this + 140);
      v4 = *(_DWORD *)(v3 + 8) + 228;
      v57 = *(float *)v4;
      v5 = v57 - *(float *)(this + 252);
      v6 = *(float *)(v4 + 4);
      v7 = (float *)(this + 252);
      v59 = *(float *)(v4 + 8);
      v8 = v59 - *(float *)(this + 260);
      v58 = v6;
      v9 = sqrt(v8 * v8 + v5 * v5);
      if ( v9 != 0.0 )
      {
        v10 = v9 + *(float *)(this + 248);
        v49 = *(_DWORD *)(this + 248);
        *(float *)(this + 248) = v10;
        if ( v12 )
        {
          v50 = *(_DWORD *)(this + 264);
          v28 = 60 * v50 + this + 272;
          if ( v10 > *(float *)(60 * v50 + this + 276) + *(float *)v28 )
          {
            do
            {
              v28 += 60;
              ++*(_DWORD *)(this + 264);
            }
            while ( *(float *)(v28 + 4) + *(float *)v28 < *(float *)(this + 248) );
          }
          v29 = (v10 - *(float *)v28) / *(float *)(v28 + 4);
          v48 = v29;
          if ( v29 >= 0.0 )
          {
            if ( v48 > 1.0 )
              v48 = 1.0;
          }
          else
          {
            v48 = 0.0;
          }
          sub_5A988B((int)&v51, v28 + 8, v28 + 20, v28 + 32, v28 + 44, v48);
          v30 = *(float **)(this + 4);
          v31 = *((_DWORD *)v30 + 73);
          if ( v31 == this )
          {
LABEL_31:
            if ( !*(_BYTE *)(v28 + 56) )
              goto LABEL_38;
            v54 = v30[49];
            v34 = v30[50];
            v35 = v30[51];
            v36 = v30 + 52;
            v55 = v34;
            v57 = *v36;
            v56 = v35;
            v58 = v36[1];
            v59 = v36[2];
            sub_614A90(&v57, v65);
            sub_4F09D0(v65, &v54, (float *)(**(_DWORD **)(this + 4) + 15988), (float *)&v61);
            if ( v63 >= -0.1 )
            {
LABEL_38:
              v39 = (float *)(*(_DWORD *)(*(_DWORD *)(this + 140) + 8) + 228);
              *v39 = *(float *)&v51;
              v39[1] = v52;
              v47 = v48 + 0.0099999998;
              v39[2] = v53;
              sub_5A988B((int)v60, v28 + 8, v28 + 20, v28 + 32, v28 + 44, v47);
              v57 = *(float *)v60 - *(float *)&v51;
              v54 = v57;
              v58 = *(float *)&v60[1] - v52;
              v55 = v58;
              v59 = *(float *)&v60[2] - v53;
              v56 = v59;
              v46 = atan2(-v57, -v59);
              sub_4F21D0((float *)&v61, 0.0, v46, 0.0);
              v40 = v62;
              v41 = (float *)(*(_DWORD *)(*(_DWORD *)(this + 140) + 8) + 212);
              *(_DWORD *)v41 = v61;
              v42 = v63;
              *((_DWORD *)v41 + 1) = v40;
              v43 = v64;
              v41[2] = v42;
              *((_DWORD *)v41 + 3) = v43;
              v44 = v52;
              v45 = v53;
              *v7 = *(float *)&v51;
              *(float *)(this + 256) = v44;
              *(float *)(this + 260) = v45;
              return;
            }
            if ( v48 * *(float *)(v28 + 4) >= 0.5 )
            {
              ++*(_DWORD *)(this + 264);
              v28 += 60;
            }
            *(_DWORD *)(this + 248) = *(_DWORD *)v28;
            v37 = (float *)(v28 + 8);
            *v7 = *v37;
            *(float *)(this + 256) = v37[1];
            *(float *)(this + 260) = v37[2];
          }
          else
          {
            v32 = 0;
            while ( 1 )
            {
              if ( *(_BYTE *)(v31 + 240) )
              {
                v57 = *(float *)(v31 + 252) - *(float *)&v51;
                v58 = *(float *)(v31 + 256) - v52;
                v33 = *(float *)(v31 + 260);
                v54 = v57;
                v55 = v58;
                v59 = v33 - v53;
                v56 = v59;
                if ( v59 * v59 + v58 * v58 + v57 * v57 < 0.25 )
                  break;
              }
              v32 += 768;
              v31 = v32 + *(_DWORD *)(*(_DWORD *)(this + 4) + 292);
              if ( v31 == this )
                goto LABEL_31;
            }
            *(_DWORD *)(this + 248) = v49;
            *(_DWORD *)(this + 264) = v50;
          }
          v38 = (_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 140) + 8) + 228);
          *v38 = *(_DWORD *)v7;
          v38[1] = *(_DWORD *)(this + 256);
          v38[2] = *(_DWORD *)(this + 260);
          return;
        }
        v13 = 60 * *(_DWORD *)(this + 268);
        v14 = *(float *)(v13 + this + 244);
        v15 = *(float *)(v13 + this + 248);
        v16 = *(float *)(v13 + this + 252);
        v17 = *(_DWORD *)(v3 + 8) + 228;
        *(float *)(v17 + 8) = v16;
        *(float *)v17 = v14;
        v59 = v16;
        *(float *)(v17 + 4) = v15;
        sub_4F21D0((float *)&v61, 0.0, *(float *)(this + 752), 0.0);
        v18 = v62;
        v19 = (float *)(*(_DWORD *)(*(_DWORD *)(this + 140) + 8) + 212);
        *(_DWORD *)v19 = v61;
        v20 = v63;
        *((_DWORD *)v19 + 1) = v18;
        v21 = v64;
        v19[2] = v20;
        *((_DWORD *)v19 + 3) = v21;
        v22 = *(_DWORD *)(*(_DWORD *)(this + 140) + 8);
        v23 = *(_DWORD *)(this + 168);
        if ( (unsigned __int8)sub_405250() )
          sub_5BC080(v22, v23, 0);
        v24 = *(_DWORD *)(this + 160);
        *(_DWORD *)(this + 168) = 0;
        *(_BYTE *)(this + 240) = 0;
        if ( v24 )
        {
          v25 = *(_DWORD *)(v24 + 88);
          if ( v25 >= 10 )
          {
            if ( v25 == 11 && **(_DWORD **)(this + 4) == ((_BYTE)dword_757C1C != 0 ? dword_91E084 : 0) )
            {
              sub_4F7DD0((_DWORD *)this, 0);
            }
            else
            {
              v26 = *(_DWORD *)(this + 136);
              *(_BYTE *)(this + 8) = 0;
              if ( v26 )
              {
                if ( *(_BYTE *)(this + 9) )
                {
                  sub_4F7BF0();
                  *(_BYTE *)(this + 14) = 1;
                }
                else
                {
                  sub_5DB5A0();
                  v27 = *(_BYTE **)(this + 140);
                  if ( v27 )
                    sub_405F00(v27, 0);
                  off_16C9414();
                }
              }
            }
          }
        }
      }
    }
  }
}
