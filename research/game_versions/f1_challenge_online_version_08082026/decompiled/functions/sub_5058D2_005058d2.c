int __usercall sub_5058D2@<eax>(int a1@<ebp>)
{
  _DWORD *v1; // ecx
  _DWORD *v2; // esi
  int v3; // eax
  unsigned int v5; // ebx
  unsigned int v6; // edi
  int *v7; // eax
  unsigned int v8; // edi
  int *v9; // eax
  unsigned int v10; // edi
  int *v11; // eax
  bool v12; // zf
  int v13; // edi
  int v14; // eax
  int v15; // eax
  int v16; // edi
  int v17; // eax
  int v18; // eax
  int v19; // edi
  int v20; // ecx
  int v21; // edi
  int v22; // eax
  int v23; // ebx
  int v24; // eax
  int v25; // ecx
  int v26; // ecx
  int v27; // eax
  int v28; // ecx
  int v29; // eax
  int v30; // ecx
  int v31; // eax
  double v32; // st7
  int v33; // ecx
  double v34; // st7
  double v35; // st6
  int v36; // edx
  float *v37; // esi
  double v38; // st5
  int v39; // edi
  double v40; // st7
  double v41; // st6
  double v42; // st7
  double v43; // st6
  double v44; // st6
  float *v45; // esi
  double v46; // st5
  int v47; // edi
  double v48; // st4
  double v49; // st6
  double v50; // st5
  double v51; // st7
  double v52; // st6
  double v53; // st7
  double v54; // st6
  float *v55; // esi
  double v56; // st6
  double v57; // st5
  float *v58; // esi
  double v59; // st4
  double v60; // st3
  int v61; // esi
  float *v62; // ecx
  double v63; // st6
  double v64; // st5
  double v65; // st6
  double v66; // st5
  double v67; // st5
  double v68; // st4
  double v69; // st3
  double v70; // st5
  double v71; // st4
  double v72; // st6
  double v73; // st5
  double v74; // st6
  double v75; // st5
  _DWORD *v76; // edi
  int v77; // ecx
  double v78; // st5
  unsigned int v79; // edx
  int v80; // eax
  int v81; // esi
  int v82; // [esp-1B0h] [ebp-1B0h]
  int v83; // [esp-1ACh] [ebp-1ACh]
  int v84; // [esp-1ACh] [ebp-1ACh]
  int v85; // [esp-1ACh] [ebp-1ACh]
  int v86; // [esp-1A8h] [ebp-1A8h]
  int v87; // [esp-1A8h] [ebp-1A8h]

  sub_58A5D8();
  *(_DWORD *)(a1 - 68) = 0;
  *(_DWORD *)(a1 - 48) = 0;
  v2 = v1;
  v3 = v1[2];
  *(_DWORD *)(a1 - 84) = v1;
  if ( (_BYTE)v3 != 3 )
    return -2147467259;
  *(_DWORD *)(a1 - 32) = (v3 & 0x40000) == 0;
  v5 = *(_DWORD *)(v1[1] + 4184);
  v6 = *(_DWORD *)(*v1 + 4184);
  *(_DWORD *)(a1 - 60) = (v3 & 0x20000) == 0;
  v7 = sub_5053EC(v5, v6, (v3 & 0x10000) == 0);
  v83 = *(_DWORD *)(a1 - 60);
  v8 = *(_DWORD *)(*v2 + 4188);
  *(_DWORD *)(a1 - 72) = v7;
  v9 = sub_5053EC(*(_DWORD *)(v2[1] + 4188), v8, v83);
  v82 = *(_DWORD *)(a1 - 32);
  v10 = *(_DWORD *)(*v2 + 4192);
  *(_DWORD *)(a1 - 76) = v9;
  v11 = sub_5053EC(*(_DWORD *)(v2[1] + 4192), v10, v82);
  v12 = *(_DWORD *)(a1 - 72) == 0;
  *(_DWORD *)(a1 - 60) = v11;
  if ( v12 || !*(_DWORD *)(a1 - 76) || !v11 )
    goto LABEL_31;
  v13 = *(_DWORD *)(v2[1] + 4184);
  v14 = sub_587C03(16 * v13);
  *(_DWORD *)(a1 - 68) = v14;
  *(_DWORD *)(a1 - 4) = 0;
  if ( v14 )
  {
    sub_5008C2(v14, 16, v13, (int (__thiscall *)(int))sub_5007EC);
    v15 = *(_DWORD *)(a1 - 68);
    *(_DWORD *)(a1 - 52) = v15;
  }
  else
  {
    *(_DWORD *)(a1 - 52) = 0;
    v15 = *(_DWORD *)(a1 - 52);
  }
  *(_DWORD *)(a1 - 4) = -1;
  *(_DWORD *)(a1 - 68) = v15;
  if ( !v15 )
    goto LABEL_31;
  v16 = 4 * *(_DWORD *)(*v2 + 4184);
  v17 = sub_587C03(*(_DWORD *)(*v2 + 4184) << 6);
  *(_DWORD *)(a1 - 48) = v17;
  *(_DWORD *)(a1 - 4) = 1;
  if ( v17 )
  {
    sub_5008C2(v17, 16, v16, (int (__thiscall *)(int))sub_5007EC);
    v18 = *(_DWORD *)(a1 - 48);
  }
  else
  {
    v18 = 0;
  }
  *(_DWORD *)(a1 - 4) = -1;
  *(_DWORD *)(a1 - 48) = v18;
  if ( v18 )
  {
    v19 = *(_DWORD *)(*v2 + 4184);
    *(_DWORD *)(a1 - 56) = 0;
    *(_DWORD *)(a1 - 28) = v18 + 16 * v19;
    v20 = v18 + 32 * v19;
    v21 = v18 + 48 * v19;
    *(_DWORD *)(a1 - 40) = v18;
    v22 = v2[1];
    v12 = *(_DWORD *)(v22 + 4192) == 0;
    *(_DWORD *)(a1 - 64) = v20;
    *(_DWORD *)(a1 - 44) = v21;
    if ( !v12 )
    {
      *(_DWORD *)(a1 - 16) = *(_DWORD *)(a1 - 60) + 8;
      do
      {
        *(_DWORD *)(a1 - 36) = 0;
        *(_DWORD *)(a1 - 24) = -1;
        *(_DWORD *)(a1 - 20) = -1;
        if ( *(_DWORD *)(v22 + 4188) )
        {
          v23 = *(_DWORD *)(a1 - 76) + 8;
          do
          {
            v24 = *(_DWORD *)(v23 - 8);
            *(_DWORD *)(a1 - 32) = 0;
            if ( v24 != *(_DWORD *)(a1 - 24) )
            {
              v25 = *(_DWORD *)(a1 - 20);
              if ( v24 == v25 )
              {
                v27 = *(_DWORD *)(a1 - 40);
                *(_DWORD *)(a1 - 20) = -1;
                *(_DWORD *)(a1 - 24) = v25;
                v28 = *(_DWORD *)(a1 - 28);
                *(_DWORD *)(a1 - 28) = v27;
                v29 = *(_DWORD *)(a1 - 64);
                *(_DWORD *)(a1 - 64) = v21;
                *(_DWORD *)(a1 - 40) = v28;
                *(_DWORD *)(a1 - 44) = v29;
                v21 = v29;
              }
              else
              {
                v86 = *(_DWORD *)(a1 - 40);
                v84 = *(_DWORD *)(*(_DWORD *)(a1 - 16) - 8);
                v26 = *v2;
                *(_DWORD *)(a1 - 24) = v24;
                (*(void (__thiscall **)(int, _DWORD, int, int))(*(_DWORD *)v26 + 4))(
                  v26,
                  *(_DWORD *)(a1 - 24),
                  v84,
                  v86);
                (*(void (__thiscall **)(_DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)*v2 + 4))(
                  *v2,
                  *(_DWORD *)(a1 - 24),
                  **(_DWORD **)(a1 - 16),
                  *(_DWORD *)(a1 - 64));
              }
            }
            if ( *(_DWORD *)v23 != *(_DWORD *)(a1 - 20) )
            {
              v87 = *(_DWORD *)(a1 - 28);
              v85 = *(_DWORD *)(*(_DWORD *)(a1 - 16) - 8);
              v30 = *v2;
              *(_DWORD *)(a1 - 20) = *(_DWORD *)v23;
              (*(void (__thiscall **)(int, _DWORD, int, int))(*(_DWORD *)v30 + 4))(v30, *(_DWORD *)(a1 - 20), v85, v87);
              (*(void (__thiscall **)(_DWORD, _DWORD, _DWORD, int))(*(_DWORD *)*v2 + 4))(
                *v2,
                *(_DWORD *)(a1 - 20),
                **(_DWORD **)(a1 - 16),
                v21);
            }
            if ( *(_DWORD *)(v2[1] + 4184) )
            {
              v31 = *(_DWORD *)(a1 - 72) + 8;
              *(_DWORD *)(a1 - 80) = *(_DWORD *)(a1 - 52);
              do
              {
                v32 = *(float *)(v31 + 4);
                v33 = 16 * *(_DWORD *)v31;
                *(float *)(a1 - 276) = v32 * *(float *)(v33 + v21);
                *(float *)(a1 - 272) = v32 * *(float *)(v33 + v21 + 4);
                *(float *)(a1 - 268) = v32 * *(float *)(v33 + v21 + 8);
                v34 = v32 * *(float *)(v33 + v21 + 12);
                v35 = *(float *)(v31 - 4);
                v36 = 16 * *(_DWORD *)(v31 - 8);
                v37 = (float *)(v36 + v21);
                v38 = v35 * *(float *)(v36 + v21);
                v39 = *(_DWORD *)(a1 - 64);
                *(float *)(a1 - 96) = v35 * v37[1];
                *(float *)(a1 - 92) = v35 * v37[2];
                *(float *)(a1 - 88) = v35 * v37[3];
                *(float *)(a1 - 148) = v38 + *(float *)(a1 - 276);
                *(float *)(a1 - 144) = *(float *)(a1 - 96) + *(float *)(a1 - 272);
                *(float *)(a1 - 140) = *(float *)(a1 - 92) + *(float *)(a1 - 268);
                v40 = *(float *)(a1 - 88) + v34;
                v41 = *(float *)(v23 + 4);
                *(float *)(a1 - 372) = *(float *)(a1 - 148) * v41;
                *(float *)(a1 - 368) = *(float *)(a1 - 144) * v41;
                *(float *)(a1 - 364) = *(float *)(a1 - 140) * v41;
                v42 = v40 * v41;
                v43 = *(float *)(v31 + 4);
                *(float *)(a1 - 404) = v43 * *(float *)(v33 + v39);
                *(float *)(a1 - 400) = v43 * *(float *)(v33 + v39 + 4);
                *(float *)(a1 - 396) = v43 * *(float *)(v33 + v39 + 8);
                v44 = v43 * *(float *)(v33 + v39 + 12);
                v45 = (float *)(v36 + v39);
                v46 = *(float *)(v31 - 4);
                v47 = *(_DWORD *)(a1 - 16);
                v48 = v46 * *v45;
                *(float *)(a1 - 176) = v46 * v45[1];
                *(float *)(a1 - 172) = v46 * v45[2];
                *(float *)(a1 - 168) = v46 * v45[3];
                *(float *)(a1 - 308) = v48 + *(float *)(a1 - 404);
                *(float *)(a1 - 304) = *(float *)(a1 - 176) + *(float *)(a1 - 400);
                *(float *)(a1 - 300) = *(float *)(a1 - 172) + *(float *)(a1 - 396);
                v49 = *(float *)(a1 - 168) + v44;
                v50 = *(float *)(v23 - 4);
                *(float *)(a1 - 212) = *(float *)(a1 - 308) * v50;
                *(float *)(a1 - 208) = *(float *)(a1 - 304) * v50;
                *(float *)(a1 - 204) = *(float *)(a1 - 300) * v50;
                *(float *)(a1 - 244) = *(float *)(a1 - 212) + *(float *)(a1 - 372);
                *(float *)(a1 - 240) = *(float *)(a1 - 208) + *(float *)(a1 - 368);
                *(float *)(a1 - 236) = *(float *)(a1 - 204) + *(float *)(a1 - 364);
                v51 = v49 * v50 + v42;
                v52 = *(float *)(v47 + 4);
                *(float *)(a1 - 388) = *(float *)(a1 - 244) * v52;
                *(float *)(a1 - 384) = *(float *)(a1 - 240) * v52;
                *(float *)(a1 - 380) = *(float *)(a1 - 236) * v52;
                v53 = v51 * v52;
                v54 = *(float *)(v31 + 4);
                v55 = (float *)(v33 + *(_DWORD *)(a1 - 28));
                *(float *)(a1 - 340) = v54 * *v55;
                *(float *)(a1 - 336) = v54 * v55[1];
                *(float *)(a1 - 332) = v54 * v55[2];
                v56 = v54 * v55[3];
                v57 = *(float *)(v31 - 4);
                v58 = (float *)(v36 + *(_DWORD *)(a1 - 28));
                v59 = v57 * *v58;
                *(float *)(a1 - 112) = v57 * v58[1];
                *(float *)(a1 - 108) = v57 * v58[2];
                v60 = v57 * v58[3];
                v61 = *(_DWORD *)(a1 - 40);
                v62 = (float *)(v61 + v33);
                *(float *)(a1 - 104) = v60;
                *(float *)(a1 - 132) = v59 + *(float *)(a1 - 340);
                *(float *)(a1 - 128) = *(float *)(a1 - 112) + *(float *)(a1 - 336);
                *(float *)(a1 - 124) = *(float *)(a1 - 108) + *(float *)(a1 - 332);
                v63 = *(float *)(a1 - 104) + v56;
                v64 = *(float *)(v23 + 4);
                *(float *)(a1 - 292) = *(float *)(a1 - 132) * v64;
                *(float *)(a1 - 288) = *(float *)(a1 - 128) * v64;
                *(float *)(a1 - 284) = *(float *)(a1 - 124) * v64;
                v65 = v63 * v64;
                v66 = *(float *)(v31 + 4);
                *(float *)(a1 - 164) = v66 * *v62;
                *(float *)(a1 - 160) = v66 * v62[1];
                *(float *)(a1 - 156) = v66 * v62[2];
                v67 = v66 * v62[3];
                v68 = *(float *)(v31 - 4);
                v69 = v68 * *(float *)(v36 + v61);
                *(float *)(a1 - 192) = v68 * *(float *)(v36 + v61 + 4);
                *(float *)(a1 - 188) = v68 * *(float *)(v36 + v61 + 8);
                *(float *)(a1 - 184) = v68 * *(float *)(v36 + v61 + 12);
                *(float *)(a1 - 228) = v69 + *(float *)(a1 - 164);
                *(float *)(a1 - 224) = *(float *)(a1 - 192) + *(float *)(a1 - 160);
                *(float *)(a1 - 220) = *(float *)(a1 - 188) + *(float *)(a1 - 156);
                v70 = *(float *)(a1 - 184) + v67;
                v71 = *(float *)(v23 - 4);
                *(float *)(a1 - 260) = *(float *)(a1 - 228) * v71;
                *(float *)(a1 - 256) = *(float *)(a1 - 224) * v71;
                *(float *)(a1 - 252) = *(float *)(a1 - 220) * v71;
                *(float *)(a1 - 324) = *(float *)(a1 - 260) + *(float *)(a1 - 292);
                *(float *)(a1 - 320) = *(float *)(a1 - 256) + *(float *)(a1 - 288);
                *(float *)(a1 - 316) = *(float *)(a1 - 252) + *(float *)(a1 - 284);
                v72 = v70 * v71 + v65;
                v73 = *(float *)(v47 - 4);
                *(float *)(a1 - 356) = *(float *)(a1 - 324) * v73;
                *(float *)(a1 - 352) = *(float *)(a1 - 320) * v73;
                *(float *)(a1 - 348) = *(float *)(a1 - 316) * v73;
                v74 = v72 * v73;
                v75 = *(float *)(a1 - 356) + *(float *)(a1 - 388);
                v76 = *(_DWORD **)(a1 - 80);
                v77 = *(_DWORD *)(a1 - 84);
                *(_DWORD *)(a1 - 80) = v76 + 4;
                *(float *)(a1 - 420) = v75;
                v31 += 16;
                v78 = *(float *)(a1 - 352) + *(float *)(a1 - 384);
                v79 = ++*(_DWORD *)(a1 - 32);
                *(float *)(a1 - 416) = v78;
                *(float *)(a1 - 412) = *(float *)(a1 - 348) + *(float *)(a1 - 380);
                *(float *)(a1 - 408) = v74 + v53;
                *v76++ = *(_DWORD *)(a1 - 420);
                *v76++ = *(_DWORD *)(a1 - 420 + 4);
                *v76 = *(_DWORD *)(a1 - 420 + 8);
                v76[1] = *(_DWORD *)(a1 - 420 + 12);
                v21 = *(_DWORD *)(a1 - 44);
              }
              while ( v79 < *(_DWORD *)(*(_DWORD *)(v77 + 4) + 4184) );
              v2 = *(_DWORD **)(a1 - 84);
            }
            (*(void (__thiscall **)(_DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v2[1] + 8))(
              v2[1],
              *(_DWORD *)(a1 - 36),
              *(_DWORD *)(a1 - 56),
              *(_DWORD *)(a1 - 52));
            v80 = v2[1];
            v23 += 16;
            ++*(_DWORD *)(a1 - 36);
          }
          while ( *(_DWORD *)(a1 - 36) < *(_DWORD *)(v80 + 4188) );
        }
        *(_DWORD *)(a1 - 16) += 16;
        ++*(_DWORD *)(a1 - 56);
        v22 = v2[1];
      }
      while ( *(_DWORD *)(a1 - 56) < *(_DWORD *)(v22 + 4192) );
    }
    v81 = 0;
  }
  else
  {
LABEL_31:
    v81 = -2147024882;
  }
  sub_587BCF(*(LPVOID *)(a1 - 72));
  sub_587BCF(*(LPVOID *)(a1 - 76));
  sub_587BCF(*(LPVOID *)(a1 - 60));
  sub_587BCF(*(LPVOID *)(a1 - 68));
  sub_587BCF(*(LPVOID *)(a1 - 48));
  return v81;
}
