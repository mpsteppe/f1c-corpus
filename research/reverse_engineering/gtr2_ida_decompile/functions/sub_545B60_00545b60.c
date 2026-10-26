int __cdecl sub_545B60(int a1, float a2, int *a3, float *a4, int a5, int a6)
{
  int v6; // ecx
  int v7; // esi
  int v8; // eax
  int v9; // ebx
  int v10; // eax
  double v11; // st7
  double v12; // st6
  int v13; // edx
  double v14; // st7
  float v15; // edx
  double v16; // st7
  int *v17; // eax
  int v18; // ecx
  int v19; // edx
  int v20; // eax
  double v21; // st7
  double v22; // st6
  int v23; // edx
  double v24; // st7
  float v25; // edx
  double v26; // st7
  int *v27; // eax
  int v28; // ecx
  int v29; // edx
  int v30; // eax
  double v31; // st7
  float v32; // ecx
  double v33; // st7
  char *v34; // ebx
  double v35; // st6
  float *v36; // eax
  float v37; // ecx
  float v38; // edx
  float v39; // eax
  float *v40; // eax
  float v41; // ecx
  float v42; // edx
  float *v43; // eax
  float v44; // ecx
  float v45; // edx
  float v46; // eax
  float *v47; // eax
  float v48; // ecx
  float v49; // edx
  float v50; // eax
  float *v51; // eax
  float v52; // ecx
  float v53; // edx
  double v54; // st7
  double v55; // st7
  double v56; // st7
  bool v57; // cc
  float v59; // [esp-8h] [ebp-E8h]
  float v60; // [esp-8h] [ebp-E8h]
  float v61; // [esp+0h] [ebp-E0h]
  float v62; // [esp+14h] [ebp-CCh]
  int v63; // [esp+18h] [ebp-C8h]
  int v64; // [esp+1Ch] [ebp-C4h]
  int v65; // [esp+20h] [ebp-C0h]
  int v66; // [esp+24h] [ebp-BCh] BYREF
  float v67; // [esp+28h] [ebp-B8h]
  float v68; // [esp+2Ch] [ebp-B4h]
  int *v69; // [esp+30h] [ebp-B0h]
  float v70; // [esp+34h] [ebp-ACh]
  int v71; // [esp+38h] [ebp-A8h]
  int v72; // [esp+3Ch] [ebp-A4h] BYREF
  int v73; // [esp+40h] [ebp-A0h]
  int v74; // [esp+44h] [ebp-9Ch]
  int v75; // [esp+48h] [ebp-98h]
  int v76; // [esp+4Ch] [ebp-94h]
  float v77; // [esp+50h] [ebp-90h]
  float v78; // [esp+54h] [ebp-8Ch]
  float v79; // [esp+58h] [ebp-88h]
  float v80[3]; // [esp+5Ch] [ebp-84h] BYREF
  float v81[3]; // [esp+68h] [ebp-78h] BYREF
  float v82[3]; // [esp+74h] [ebp-6Ch] BYREF
  float v83[3]; // [esp+80h] [ebp-60h] BYREF
  float v84[3]; // [esp+8Ch] [ebp-54h] BYREF
  float v85[3]; // [esp+98h] [ebp-48h] BYREF
  float v86[3]; // [esp+A4h] [ebp-3Ch] BYREF
  float v87[3]; // [esp+B0h] [ebp-30h] BYREF
  float v88[3]; // [esp+BCh] [ebp-24h] BYREF
  float v89[3]; // [esp+C8h] [ebp-18h] BYREF
  float v90[3]; // [esp+D4h] [ebp-Ch] BYREF

  v7 = v6;
  v76 = v6;
  if ( (unsigned __int8)sub_5210F0() )
  {
    v8 = *(_DWORD *)(v7 + 56);
    v71 = 0;
    if ( v8 > 0 )
    {
      v69 = (int *)(v7 + 60);
      while ( 1 )
      {
        v9 = *v69;
        v10 = *(_DWORD *)(*v69 + 4);
        v75 = *v69;
        switch ( v10 )
        {
          case 0:
            if ( *(float *)(a1 + 44) == 0.0 || dword_B7129C <= 2 && dword_BE1204 != 2 && dword_91E230 % 20 )
              goto LABEL_48;
            if ( fabs(a2 - *(float *)(a1 + 68)) <= 0.15000001 )
            {
              v12 = *((float *)a3 + 2) - *(float *)(a1 + 64);
              v11 = *(float *)a3 - *(float *)(a1 + 56);
              if ( v12 * v12 + v11 * v11 <= 1.0 )
                goto LABEL_48;
            }
            *(_DWORD *)(a1 + 56) = *a3;
            *(_DWORD *)(a1 + 60) = a3[1];
            v13 = a3[2];
            *(float *)(a1 + 68) = a2;
            *(_DWORD *)(a1 + 64) = v13;
            v14 = flt_BE0CA4[(unsigned __int8)dword_BE08A0++] * 0.25;
            v15 = *((float *)a3 + 1);
            *(float *)&v66 = v14 + *(float *)a3;
            v67 = v15;
            v16 = flt_BE0CA4[(unsigned __int8)dword_BE08A0++] * 0.25;
            v68 = v16 + *((float *)a3 + 2);
            v17 = (int *)sub_4012D0(a4, v89, 0.1);
            v18 = *v17;
            v19 = v17[1];
            v74 = v17[2];
            v72 = v18;
            v73 = v19;
            if ( !byte_B71410 )
            {
              if ( !byte_B71428 )
              {
                v20 = -1;
                goto LABEL_17;
              }
LABEL_15:
              v20 = a6;
              goto LABEL_17;
            }
            if ( !byte_B71428 )
              goto LABEL_15;
            v20 = 104;
LABEL_17:
            sub_543B10(v9, a2, (float *)&v66, (float *)&v72, *(float *)(a1 + 44), a5, 1, v20);
LABEL_48:
            v57 = ++v71 < *(_DWORD *)(v76 + 56);
            ++v69;
            if ( !v57 )
              return off_16C9870();
            break;
          case 2:
            if ( *(float *)(a1 + 40) == 0.0 || dword_B7129C <= 2 && dword_BE1204 != 2 && dword_91E230 % 20 )
              goto LABEL_48;
            if ( fabs(a2 - *(float *)(a1 + 68)) <= 0.15000001 )
            {
              v22 = *((float *)a3 + 2) - *(float *)(a1 + 64);
              v21 = *(float *)a3 - *(float *)(a1 + 56);
              if ( v22 * v22 + v21 * v21 <= 1.0 )
                goto LABEL_48;
            }
            *(_DWORD *)(a1 + 56) = *a3;
            *(_DWORD *)(a1 + 60) = a3[1];
            v23 = a3[2];
            *(float *)(a1 + 68) = a2;
            *(_DWORD *)(a1 + 64) = v23;
            v24 = flt_BE0CA4[(unsigned __int8)dword_BE08A0++] * 0.25;
            v25 = *((float *)a3 + 1);
            *(float *)&v66 = v24 + *(float *)a3;
            v67 = v25;
            v26 = flt_BE0CA4[(unsigned __int8)dword_BE08A0++] * 0.25;
            v68 = v26 + *((float *)a3 + 2);
            v27 = (int *)sub_4012D0(a4, v84, 0.1);
            v28 = *v27;
            v29 = v27[1];
            v74 = v27[2];
            v72 = v28;
            v73 = v29;
            if ( byte_B71410 )
            {
              if ( byte_B71428 )
              {
                v30 = 104;
LABEL_30:
                sub_543B10(v9, a2, (float *)&v66, (float *)&v72, *(float *)(a1 + 40), a5, 1, v30);
                goto LABEL_48;
              }
            }
            else if ( !byte_B71428 )
            {
              v30 = -1;
              goto LABEL_30;
            }
            v30 = a6;
            goto LABEL_30;
          case 6:
            if ( *(float *)(a1 + 48) != 0.0 && (dword_B7129C > 1 || dword_BE1204 == 2 || !(dword_91E230 % 20)) )
            {
              v31 = flt_BE0CA4[(unsigned __int8)dword_BE08A0++] * 0.25;
              v32 = *((float *)a3 + 1);
              *(float *)&v66 = v31 + *(float *)a3;
              v67 = v32;
              v33 = flt_BE0CA4[(unsigned __int8)dword_BE08A0++] * 0.25;
              v59 = *(float *)(a1 + 48);
              v68 = v33 + *((float *)a3 + 2);
              sub_5438E0(v9, a2, (float *)&v66, a4, v59, a5, a6);
            }
            goto LABEL_48;
          case 20:
            if ( *(float *)(a1 + 48) != 0.0 )
            {
              v34 = (char *)&unk_9204A0 + 22616 * a6;
              if ( sub_542540((float *)a3, (float *)v34 + 5649) )
              {
                if ( (dword_B7129C > 1 || dword_BE1204 == 2 || !(dword_91E230 % 20)) && !sub_542CD0((int)(v34 + 2704)) )
                {
                  v35 = *((float *)v34 + 5648);
                  v70 = *(float *)&dword_BE271C;
                  if ( v35 == 0.0 )
                  {
                    v63 = *a3;
                    v64 = a3[1];
                    v65 = a3[2];
                    v62 = 0.0;
                  }
                  else
                  {
                    v63 = *((int *)v34 + 5649);
                    v65 = *((int *)v34 + 5651);
                    v64 = *((int *)v34 + 5650);
                    v36 = sub_401290((float *)a3, (float *)v34 + 5649, v87);
                    v37 = *v36;
                    v38 = v36[1];
                    v39 = v36[2];
                    v80[0] = v37;
                    v80[1] = v38;
                    v80[2] = v39;
                    v62 = sub_401220(v80) + *((float *)v34 + 5648);
                  }
                  v40 = sub_401290((float *)a3, (float *)v34 + 5649, v85);
                  v41 = v40[1];
                  v81[0] = *v40;
                  v42 = v40[2];
                  v81[1] = v41;
                  v81[2] = v42;
                  v43 = sub_401290((float *)a3, (float *)v34 + 5649, v86);
                  v44 = *v43;
                  v45 = v43[1];
                  v46 = v43[2];
                  v82[0] = v44;
                  v82[1] = v45;
                  v82[2] = v46;
                  v47 = sub_4012D0(v82, v88, v70);
                  v48 = *v47;
                  v49 = v47[1];
                  v50 = v47[2];
                  v83[0] = v48;
                  v83[1] = v49;
                  v83[2] = v50;
                  v61 = sub_401220(v81);
                  v51 = sub_438380(v83, v90, v61);
                  v52 = v51[1];
                  v77 = *v51;
                  v53 = v51[2];
                  v78 = v52;
                  v79 = v53;
                  do
                  {
                    v54 = flt_BE0CA4[(unsigned __int8)dword_BE08A0++] * 0.80000001;
                    *(float *)&v66 = v54 + *(float *)&v63;
                    v67 = *(float *)&v64 + 0.1;
                    v55 = flt_BE0CA4[(unsigned __int8)dword_BE08A0++];
                    v60 = *(float *)(a1 + 48);
                    v68 = v55 * 0.80000001 + *(float *)&v65;
                    sub_5438E0(v75, a2, (float *)&v66, a4, v60, a5, a6);
                    *(float *)&v63 = v77 + *(float *)&v63;
                    *(float *)&v64 = v78 + *(float *)&v64;
                    *(float *)&v65 = v79 + *(float *)&v65;
                    v56 = v62 - v70;
                    v62 = v56;
                  }
                  while ( v56 > v70 );
                  *((float *)v34 + 5648) = v62;
                  sub_542D10(v34, v63, v64, v65);
                }
              }
            }
            goto LABEL_48;
          default:
            goto LABEL_48;
        }
      }
    }
  }
  return off_16C9870();
}
