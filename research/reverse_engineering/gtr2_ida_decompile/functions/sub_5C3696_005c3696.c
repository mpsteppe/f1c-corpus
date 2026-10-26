void __userpurge sub_5C3696(int a1@<eax>, int a2@<ecx>, int a3@<edi>, int a4@<esi>, int a5)
{
  int v6; // eax
  _DWORD *v7; // esi
  char *v8; // eax
  int v9; // edi
  int v10; // ecx
  int v11; // ebx
  int v12; // eax
  int *v13; // ebx
  int v14; // ecx
  int v15; // edx
  int v16; // ebx
  int v17; // ebx
  bool v18; // cc
  _DWORD *v19; // ebx
  int v20; // edi
  int v21; // eax
  double v22; // st7
  long double v23; // st7
  long double v24; // st7
  double v25; // st6
  long double v26; // st7
  long double v27; // st6
  long double v28; // st5
  long double v29; // st4
  long double v30; // st3
  long double v31; // st3
  long double v32; // st7
  long double v33; // st7
  double v34; // st6
  int v35; // [esp-10h] [ebp-F4h]
  int *i; // [esp+0h] [ebp-E4h]
  float v38; // [esp+0h] [ebp-E4h]
  float v39; // [esp+0h] [ebp-E4h]
  float v40; // [esp+0h] [ebp-E4h]
  int v41; // [esp+4h] [ebp-E0h]
  float v42; // [esp+4h] [ebp-E0h]
  float v43; // [esp+8h] [ebp-DCh]
  float v44; // [esp+8h] [ebp-DCh]
  float v45; // [esp+8h] [ebp-DCh]
  float v46; // [esp+Ch] [ebp-D8h]
  float v47; // [esp+10h] [ebp-D4h]
  float v48; // [esp+14h] [ebp-D0h]
  float v49; // [esp+18h] [ebp-CCh]
  float v50; // [esp+1Ch] [ebp-C8h]
  float v51; // [esp+20h] [ebp-C4h]
  int v52; // [esp+24h] [ebp-C0h]
  int v53; // [esp+30h] [ebp-B4h]
  float *v54; // [esp+30h] [ebp-B4h]
  int v55; // [esp+34h] [ebp-B0h]
  float v56; // [esp+38h] [ebp-ACh]
  float v57; // [esp+3Ch] [ebp-A8h]
  float v58; // [esp+40h] [ebp-A4h]
  float *v59; // [esp+44h] [ebp-A0h]
  float *v60; // [esp+48h] [ebp-9Ch]
  int v61; // [esp+4Ch] [ebp-98h]
  int v62; // [esp+50h] [ebp-94h]
  float v63; // [esp+54h] [ebp-90h]
  float v64; // [esp+58h] [ebp-8Ch]
  float v65; // [esp+5Ch] [ebp-88h]
  int v66; // [esp+60h] [ebp-84h]
  int v67; // [esp+64h] [ebp-80h]
  float v68; // [esp+6Ch] [ebp-78h]
  float v69; // [esp+70h] [ebp-74h]
  float v70[3]; // [esp+74h] [ebp-70h] BYREF
  float v71[3]; // [esp+80h] [ebp-64h] BYREF
  float v72; // [esp+8Ch] [ebp-58h]
  float v73; // [esp+98h] [ebp-4Ch]
  float v74; // [esp+9Ch] [ebp-48h]
  float v75; // [esp+A0h] [ebp-44h]
  int v76; // [esp+D8h] [ebp-Ch]
  void *v77; // [esp+DCh] [ebp-8h]
  int v78; // [esp+E0h] [ebp-4h]

  v78 = -1;
  v77 = &loc_6EB06B;
  v76 = a1;
  v6 = sub_5C2BB0((_DWORD *)a2, 2, a5);
  if ( v6 != -1 )
  {
    v7 = 0;
    v53 = *(_DWORD *)(*(_DWORD *)(a2 + 72) + 4 * v6);
    if ( v53 )
    {
      if ( *(_DWORD *)(a2 + 24) )
      {
        sub_4F14D0(a4);
        sub_5A8D10(*(void **)(a2 + 24));
      }
      sub_4F14D0(a3);
      v8 = (char *)sub_5A8CE0(32 * *(_DWORD *)(a2 + 40), 202, 100, 0);
      v9 = 0;
      *(_DWORD *)(a2 + 24) = v8;
      v52 = 0;
      v10 = *(_DWORD *)(a2 + 40);
      v67 = *(_DWORD *)(a2 + 16) + 12 * v10;
      v62 = *(_DWORD *)(a2 + 32);
      v11 = *(_DWORD *)(v53 + 4);
      v78 = 0;
      v61 = v11;
      v55 = 0;
      if ( v10 > 0 )
      {
        v59 = (float *)(v8 + 12);
        v54 = (float *)&v8[16 * v10 + 8];
        v60 = (float *)(*(_DWORD *)(a2 + 20) + 8);
        v66 = -4 * v10;
        while ( 1 )
        {
          v12 = 0;
          v41 = 0;
          if ( *(int *)(a2 + 44) > 0 )
            break;
LABEL_20:
          v20 = 0;
          v49 = 0.0;
          v50 = 0.0;
          v51 = 0.0;
          v46 = 0.0;
          v47 = 0.0;
          v48 = 0.0;
          if ( v52 > 0 )
          {
            do
            {
              v21 = v7[v20];
              sub_5C2810(
                (float *)(v67 + 12 * *(_DWORD *)(v62 + 4 * v21)),
                (float *)(v67 + 12 * *(_DWORD *)(v62 + 4 * v21 + 4)),
                (float *)(v67 + 12 * *(_DWORD *)(v62 + 4 * v21 + 8)),
                (float *)(v61 + 8 * *(_DWORD *)(v62 + 4 * v21)),
                (float *)(v61 + 8 * *(_DWORD *)(v62 + 4 * v21 + 4)),
                (float *)(v61 + 8 * *(_DWORD *)(v62 + 4 * v21 + 8)),
                v71,
                v70);
              ++v20;
              v49 = v49 + v70[0];
              v50 = v70[1] + v50;
              v51 = v70[2] + v51;
              v46 = v46 + v71[0];
              v47 = v71[1] + v47;
              v48 = v71[2] + v48;
            }
            while ( v20 < v52 );
            v22 = 1.0 / (double)v52;
            v46 = v46 * v22;
            v47 = v47 * v22;
            v48 = v48 * v22;
            v49 = v49 * v22;
            v50 = v50 * v22;
            v51 = v51 * v22;
          }
          v23 = 1.0 / sqrt(*(v60 - 2) * *(v60 - 2) + *(v60 - 1) * *(v60 - 1) + *v60 * *v60);
          v38 = v23;
          v24 = v23 * *(v60 - 2);
          *(v60 - 2) = v24;
          v25 = v38 * *(v60 - 1);
          *(v60 - 1) = v25;
          v43 = v38 * *v60;
          *v60 = v43;
          v58 = v43;
          v56 = v24;
          v57 = v25;
          v26 = 1.0 / sqrt(v46 * v46 + v48 * v48 + v47 * v47);
          v27 = v46 * v26;
          v28 = v47 * v26;
          v29 = v48 * v26;
          v30 = 1.0 / sqrt(v49 * v49 + v51 * v51 + v50 * v50);
          v63 = v49 * v30;
          v64 = v50 * v30;
          v65 = v51 * v30;
          v73 = v27;
          v74 = v28;
          v75 = v29;
          v31 = v57 * v28 + v43 * v29 + v56 * v27;
          v44 = v43 * v31;
          v39 = v57 * v31;
          v72 = v31 * v56;
          v42 = v29 - v44;
          v40 = v28 - v39;
          v32 = v27 - v72;
          v45 = 1.0 / sqrt(v32 * v32 + v40 * v40 + v42 * v42);
          v33 = v32 * v45;
          v68 = v40 * v45;
          v69 = v42 * v45;
          if ( v74 * v65 * v56 + v75 * v57 * v63 + v64 * v58 * v73 - v75 * v64 * v56 - v74 * v58 * v63 - v65 * v57 * v73 >= 0.0 )
            v34 = 1.0;
          else
            v34 = -1.0;
          *(v54 - 2) = v33;
          v54[1] = v34;
          *v54 = v69;
          *(v54 - 1) = v68;
          *(v59 - 3) = v33;
          v9 = 0;
          v54[v66] = v69;
          *(v59 - 2) = v68;
          v52 = 0;
          *v59 = v34;
          sub_4F14D0(v35);
          sub_5A8D10(v7);
          v7 = 0;
          v60 += 3;
          v18 = ++v55 < *(_DWORD *)(a2 + 40);
          v54 += 4;
          v59 += 4;
          if ( !v18 )
            goto LABEL_27;
        }
        v13 = (int *)(v62 + 8);
        for ( i = (int *)(v62 + 8); ; v13 = i )
        {
          v14 = *(v13 - 2);
          v15 = *(v13 - 1);
          v16 = *v13;
          if ( v14 == v55 )
            goto LABEL_15;
          if ( v15 != v55 )
            break;
          v17 = v52 + 1;
          v18 = v9 < ++v52;
          if ( !v18 )
            goto LABEL_17;
LABEL_16:
          v9 = v17 + 1;
          sub_4F14D0(v35);
          v7 = sub_5A8CF0(v7, 4 * (v17 + 1), 2, 16, 2);
          v12 = v41;
LABEL_17:
          v19 = &v7[v17 - 1];
          if ( v19 )
            *v19 = v12;
LABEL_19:
          v12 += 3;
          v41 = v12;
          i += 3;
          if ( v12 >= *(_DWORD *)(a2 + 44) )
            goto LABEL_20;
        }
        if ( v16 != v55 )
          goto LABEL_19;
LABEL_15:
        v17 = v52 + 1;
        v18 = v9 < ++v52;
        if ( !v18 )
          goto LABEL_17;
        goto LABEL_16;
      }
LABEL_27:
      v78 = -1;
      sub_4F14D0(v35);
      sub_5A8D10(0);
    }
  }
}
