void __thiscall sub_57A7F0(float *this, int a2, int a3, double *a4)
{
  float v5; // ecx
  float v6; // eax
  double v7; // st7
  double v8; // st7
  double v9; // st7
  double v10; // st7
  double v11; // st7
  double v12; // st7
  int v13; // ecx
  int *v14; // eax
  int v15; // edi
  int v16; // esi
  float *v17; // eax
  float v18; // ecx
  float v19; // edx
  float v20; // eax
  double v21; // st7
  char *v22; // esi
  long double v23; // st7
  int v24; // ecx
  long double v25; // st6
  double v26; // st7
  double v27; // st6
  double v28; // st6
  double v30; // st6
  unsigned __int8 v31; // c0
  unsigned __int8 v32; // c2
  float *v33; // edi
  long double v34; // st7
  double v35; // st7
  double v36; // st7
  double v37; // st7
  long double v38; // st7
  float *v39; // eax
  int v40; // ecx
  int v41; // edx
  int v42; // eax
  _DWORD *v43; // esi
  float v44; // [esp+10h] [ebp-D0h] BYREF
  float v45; // [esp+14h] [ebp-CCh]
  float v46; // [esp+18h] [ebp-C8h]
  float v47; // [esp+1Ch] [ebp-C4h] BYREF
  float v48; // [esp+20h] [ebp-C0h] BYREF
  float v49; // [esp+24h] [ebp-BCh]
  float v50; // [esp+28h] [ebp-B8h]
  float v51; // [esp+2Ch] [ebp-B4h] BYREF
  float v52; // [esp+30h] [ebp-B0h]
  float v53; // [esp+34h] [ebp-ACh]
  float v54; // [esp+38h] [ebp-A8h] BYREF
  float v55; // [esp+3Ch] [ebp-A4h]
  float v56; // [esp+40h] [ebp-A0h]
  float v57; // [esp+44h] [ebp-9Ch] BYREF
  float v58; // [esp+48h] [ebp-98h]
  float v59; // [esp+4Ch] [ebp-94h]
  float v60; // [esp+50h] [ebp-90h]
  float v61[9]; // [esp+54h] [ebp-8Ch] BYREF
  double v62; // [esp+78h] [ebp-68h] BYREF
  int v63[4]; // [esp+80h] [ebp-60h] BYREF
  double v64; // [esp+90h] [ebp-50h] BYREF
  double v65[3]; // [esp+98h] [ebp-48h] BYREF
  double v66[3]; // [esp+B0h] [ebp-30h] BYREF
  double v67[3]; // [esp+C8h] [ebp-18h] BYREF

  v5 = *(float *)(a2 + 16);
  v6 = *(float *)(a2 + 24);
  v45 = *(float *)(a2 + 20);
  v46 = v6;
  v44 = v5;
  sub_4F09D0(this + 3984, this + 3993, &v44, &v48);
  v51 = this[697] + this[691];
  v7 = this[698];
  v58 = v51;
  v52 = v7 + this[692];
  v8 = this[699];
  v59 = v52;
  v53 = v8 + this[693];
  v9 = this[700];
  v60 = v53;
  v54 = v9 + this[691];
  v10 = this[701];
  v51 = v54;
  v55 = v10 + this[692];
  v11 = this[702];
  v52 = v55;
  v56 = v11 + this[693];
  v53 = v56;
  if ( v58 - *(float *)(a2 + 28) <= v48
    && v51 + *(float *)(a2 + 28) >= v48
    && v59 - *(float *)(a2 + 28) <= v49
    && v52 + *(float *)(a2 + 28) >= v49
    && v60 - *(float *)(a2 + 28) <= v50
    && v53 + *(float *)(a2 + 28) >= v50 )
  {
    v12 = a4[1];
    v47 = 3.4028235e38;
    v44 = v12;
    v45 = a4[2];
    v46 = a4[3];
    v61[0] = a4[4];
    v61[1] = a4[5];
    v61[2] = a4[6];
    v61[3] = a4[7];
    v61[4] = a4[8];
    v61[5] = a4[9];
    v61[6] = a4[10];
    v61[7] = a4[11];
    v13 = *(_DWORD *)(a3 + 544);
    v61[8] = a4[12];
    if ( v13 <= 0 )
      goto LABEL_9;
    v14 = *(int **)(a3 + 532);
    if ( v14 )
      v15 = *v14;
    else
LABEL_9:
      v15 = 0;
    v16 = 0;
    v57 = COERCE_FLOAT(sub_5EA5B0(v15));
    if ( SLODWORD(v57) > 0 )
    {
      do
      {
        v17 = (float *)sub_5EB140(v16, 1);
        v18 = *v17;
        v19 = v17[1];
        v20 = v17[2];
        v48 = v18;
        v49 = v19;
        v50 = v20;
        sub_416420(v61, &v44, &v48, (float *)v63);
        sub_4F09D0(this + 3984, this + 3993, (float *)v63, &v48);
        if ( v48 > (double)v58
          && v48 < (double)v51
          && v49 > (double)v59
          && v49 < (double)v52
          && v50 > (double)v60
          && v50 < (double)v53 )
        {
          v21 = sub_401200(&v48);
          if ( v21 < v47 )
          {
            v47 = v21;
            v54 = v48;
            v55 = v49;
            v56 = v50;
          }
        }
        ++v16;
      }
      while ( v16 < SLODWORD(v57) );
      if ( v47 != 3.4028235e38 )
      {
        if ( dword_FAF5C0 >= 32 )
          v22 = (char *)&unk_FAF578;
        else
          v22 = (char *)(72 * dword_FAF5C0++ + 16444608);
        v23 = sqrt(v47);
        *(_DWORD *)v22 = -1;
        v24 = *(_DWORD *)(a2 + 32);
        *((_DWORD *)v22 + 4) = a2;
        *((_DWORD *)v22 + 3) = v24;
        v25 = this[4422] - v23;
        if ( v25 < 0.0 )
          v25 = 0.0;
        v44 = -v54;
        v48 = v44;
        v45 = -v55;
        v49 = v45;
        v46 = -v56;
        v50 = v46;
        if ( v23 <= 0.0 )
        {
          v26 = v49;
        }
        else
        {
          v47 = v25 / v23;
          v48 = v48 * v47;
          v26 = v49 * v47;
          v50 = v50 * v47;
        }
        if ( v54 >= 0.0 )
          v27 = v51 - v54;
        else
          v27 = v54 - v58;
        v44 = v27;
        if ( v56 >= 0.0 )
          v28 = v53 - v56;
        else
          v28 = v56 - v60;
        if ( v44 >= v28 )
        {
          if ( v56 >= 0.0 )
            v28 = -v28;
          v44 = 0.0;
        }
        else
        {
          v30 = v44;
          if ( !(v31 | v32) )
            v30 = -v30;
          v44 = v30;
          v28 = 0.0;
        }
        v33 = (float *)(v22 + 60);
        v44 = v44 + v48;
        v51 = v44;
        v45 = v26;
        v52 = v45;
        v46 = v28 + v50;
        v53 = v46;
        v44 = v44 * 0.1;
        v48 = v44;
        v45 = v45 * 0.1;
        v49 = v45;
        v46 = v46 * 0.1;
        v50 = v46;
        v34 = sqrt(v44 * v44 + v46 * v46 + v45 * v45);
        *((float *)v22 + 2) = v34;
        if ( v34 <= 0.0 )
        {
          *v33 = 0.0;
          *((_DWORD *)v22 + 16) = 1065353216;
          *((_DWORD *)v22 + 17) = 0;
        }
        else
        {
          sub_407380(this + 3984, &v48, (float *)v22 + 15);
          v35 = 1.0 / *((float *)v22 + 2);
          *v33 = v35 * *v33;
          *((float *)v22 + 16) = v35 * *((float *)v22 + 16);
          *((float *)v22 + 17) = v35 * *((float *)v22 + 17);
        }
        v44 = v54 - v48;
        v51 = v44;
        v45 = v55 - v49;
        v52 = v45;
        v46 = v56 - v50;
        v53 = v46;
        sub_416420(this + 3984, this + 3993, &v51, (float *)v22 + 6);
        *((_DWORD *)v22 + 9) = *((_DWORD *)v22 + 6);
        *((_DWORD *)v22 + 10) = *((_DWORD *)v22 + 7);
        *((_DWORD *)v22 + 11) = *((_DWORD *)v22 + 8);
        sub_576B50(this, (float *)v22 + 9, (float *)v22 + 15, &v57, &v47, &v54);
        v67[0] = *((float *)v22 + 9);
        v67[1] = *((float *)v22 + 10);
        v67[2] = *((float *)v22 + 11);
        v65[0] = *v33;
        v65[1] = *((float *)v22 + 16);
        v65[2] = *((float *)v22 + 17);
        sub_618F40(v67, v65, &v62, &v64, v66);
        v36 = v57 - v62;
        v47 = v64 + v47;
        v54 = v54 - v66[0];
        v55 = v55 - v66[1];
        v56 = v56 - v66[2];
        if ( v36 > 0.0 )
          v36 = 0.0;
        v47 = -1.0 / v47 * v36;
        if ( v54 * v54 + v55 * v55 + v56 * v56 > 1.0 )
          sub_401380(&v54);
        v37 = v47 * 0.2;
        v44 = v54 * v37;
        v58 = v44;
        v45 = v55 * v37;
        v59 = v45;
        v46 = v37 * v56;
        v60 = v46;
        v44 = v47 * *v33;
        v51 = v44;
        v45 = v47 * *((float *)v22 + 16);
        v52 = v45;
        v46 = v47 * *((float *)v22 + 17);
        v44 = v44 - v58;
        v51 = v44;
        v45 = v45 - v59;
        v52 = v45;
        v46 = v46 - v60;
        v53 = v46;
        v38 = sqrt(v44 * v44 + v46 * v46 + v45 * v45);
        *((float *)v22 + 1) = v38;
        v57 = v38;
        if ( v38 <= 0.0 )
        {
          *((_DWORD *)v22 + 12) = 0;
          *((_DWORD *)v22 + 13) = 0;
          *((_DWORD *)v22 + 14) = 0;
        }
        else
        {
          v39 = sub_438380(&v51, (float *)v63, v57);
          v40 = *(_DWORD *)v39;
          v41 = *((_DWORD *)v39 + 1);
          v42 = *((_DWORD *)v39 + 2);
          v43 = v22 + 48;
          *v43 = v40;
          v43[1] = v41;
          v43[2] = v42;
        }
      }
    }
  }
}
