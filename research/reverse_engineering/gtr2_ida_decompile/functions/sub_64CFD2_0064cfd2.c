int __thiscall sub_64CFD2(_DWORD *this)
{
  int v2; // eax
  float *v4; // eax
  int v5; // esi
  float *v6; // eax
  int v7; // esi
  char *v8; // eax
  int v9; // eax
  int v10; // esi
  int v11; // eax
  char *v12; // esi
  float *v13; // edi
  int v14; // eax
  int v15; // ecx
  char *v16; // ecx
  char *v17; // eax
  float *v18; // eax
  double v19; // st7
  int v20; // esi
  double v21; // st7
  double v22; // st6
  int v23; // ecx
  float *v24; // esi
  double v25; // st6
  double v26; // st7
  double v27; // st6
  double v28; // st5
  double v29; // st5
  double v30; // st7
  double v31; // st6
  int v32; // edx
  double v33; // st7
  double v34; // st6
  double v35; // st6
  double v36; // st5
  float *v37; // edx
  float *v38; // ecx
  double v39; // st5
  double v40; // st6
  double v41; // st5
  double v42; // st4
  double v43; // st4
  double v44; // st3
  double v45; // st5
  float *v46; // edi
  int v47; // esi
  float v48; // [esp+4h] [ebp-194h]
  float v49; // [esp+8h] [ebp-190h]
  float v50; // [esp+Ch] [ebp-18Ch]
  float v51; // [esp+10h] [ebp-188h]
  float v52; // [esp+14h] [ebp-184h]
  float v53; // [esp+18h] [ebp-180h]
  float v54; // [esp+1Ch] [ebp-17Ch]
  float v55; // [esp+24h] [ebp-174h]
  float v56; // [esp+28h] [ebp-170h]
  float v57; // [esp+2Ch] [ebp-16Ch]
  float v58; // [esp+34h] [ebp-164h]
  float v59; // [esp+38h] [ebp-160h]
  float v60; // [esp+3Ch] [ebp-15Ch]
  float v61; // [esp+44h] [ebp-154h]
  float v62; // [esp+48h] [ebp-150h]
  float v63; // [esp+4Ch] [ebp-14Ch]
  float v64; // [esp+54h] [ebp-144h]
  float v65; // [esp+58h] [ebp-140h]
  float v66; // [esp+5Ch] [ebp-13Ch]
  float v67; // [esp+64h] [ebp-134h]
  float v68; // [esp+68h] [ebp-130h]
  float v69; // [esp+6Ch] [ebp-12Ch]
  float v70; // [esp+74h] [ebp-124h]
  float v71; // [esp+78h] [ebp-120h]
  float v72; // [esp+7Ch] [ebp-11Ch]
  float v73; // [esp+84h] [ebp-114h]
  float v74; // [esp+88h] [ebp-110h]
  float v75; // [esp+8Ch] [ebp-10Ch]
  float v76; // [esp+94h] [ebp-104h]
  float v77; // [esp+98h] [ebp-100h]
  float v78; // [esp+9Ch] [ebp-FCh]
  float v79; // [esp+A4h] [ebp-F4h]
  float v80; // [esp+A8h] [ebp-F0h]
  float v81; // [esp+ACh] [ebp-ECh]
  float v82; // [esp+B4h] [ebp-E4h]
  float v83; // [esp+B8h] [ebp-E0h]
  float v84; // [esp+BCh] [ebp-DCh]
  float v85; // [esp+C4h] [ebp-D4h]
  float v86; // [esp+C8h] [ebp-D0h]
  float v87; // [esp+CCh] [ebp-CCh]
  float v88; // [esp+D4h] [ebp-C4h]
  float v89; // [esp+D8h] [ebp-C0h]
  float v90; // [esp+DCh] [ebp-BCh]
  float v91; // [esp+E8h] [ebp-B0h]
  float v92; // [esp+ECh] [ebp-ACh]
  float v93; // [esp+F0h] [ebp-A8h]
  float v94; // [esp+F8h] [ebp-A0h]
  float v95; // [esp+FCh] [ebp-9Ch]
  float v96; // [esp+100h] [ebp-98h]
  float v97; // [esp+104h] [ebp-94h]
  float v98; // [esp+108h] [ebp-90h]
  float v99; // [esp+10Ch] [ebp-8Ch]
  float v100; // [esp+114h] [ebp-84h]
  float v101; // [esp+118h] [ebp-80h]
  float v102; // [esp+11Ch] [ebp-7Ch]
  float v103; // [esp+124h] [ebp-74h]
  float v104; // [esp+128h] [ebp-70h]
  float v105; // [esp+12Ch] [ebp-6Ch]
  float v106; // [esp+138h] [ebp-60h]
  float v107; // [esp+13Ch] [ebp-5Ch]
  float v108; // [esp+140h] [ebp-58h]
  float v109; // [esp+148h] [ebp-50h]
  float v110; // [esp+14Ch] [ebp-4Ch]
  float v111; // [esp+150h] [ebp-48h]
  unsigned int v112; // [esp+154h] [ebp-44h]
  float *Block; // [esp+158h] [ebp-40h]
  float *v114; // [esp+15Ch] [ebp-3Ch]
  float *v115; // [esp+160h] [ebp-38h]
  char *v116; // [esp+164h] [ebp-34h]
  BOOL v117; // [esp+168h] [ebp-30h]
  float *v118; // [esp+168h] [ebp-30h]
  char *v119; // [esp+16Ch] [ebp-2Ch]
  char *v120; // [esp+170h] [ebp-28h]
  char *v121; // [esp+174h] [ebp-24h]
  unsigned int v122; // [esp+178h] [ebp-20h]
  unsigned int v123; // [esp+17Ch] [ebp-1Ch]
  int v124; // [esp+180h] [ebp-18h]
  char *v125; // [esp+184h] [ebp-14h]
  int v126; // [esp+188h] [ebp-10h]
  float *v127; // [esp+18Ch] [ebp-Ch]
  float *v128; // [esp+190h] [ebp-8h]
  BOOL v129; // [esp+194h] [ebp-4h]
  float *v130; // [esp+194h] [ebp-4h]
  char *v131; // [esp+194h] [ebp-4h]
  float *v132; // [esp+194h] [ebp-4h]

  v127 = 0;
  v121 = 0;
  v2 = this[2];
  if ( (_BYTE)v2 != 3 )
    return -2147467259;
  v129 = (v2 & 0x40000) == 0;
  v117 = (v2 & 0x20000) == 0;
  Block = sub_64CB44(*(_DWORD *)(this[1] + 104), *(_DWORD *)(*this + 104), (v2 & 0x10000) == 0);
  v114 = sub_64CB44(*(_DWORD *)(this[1] + 108), *(_DWORD *)(*this + 108), v117);
  v4 = sub_64CB44(*(_DWORD *)(this[1] + 112), *(_DWORD *)(*this + 112), v129);
  v118 = v4;
  if ( !Block || !v114 || !v4 )
    goto LABEL_31;
  v5 = *(_DWORD *)(this[1] + 104);
  v6 = (float *)operator new(16 * v5);
  v130 = v6;
  if ( v6 )
  {
    sub_41D1B0((int)v6, 16, v5, (int)sub_681563);
    v127 = v130;
  }
  else
  {
    v127 = 0;
  }
  if ( v127
    && ((v7 = 4 * *(_DWORD *)(*this + 104), v8 = (char *)operator new(*(_DWORD *)(*this + 104) << 6), (v131 = v8) == 0)
      ? (v121 = 0)
      : (sub_41D1B0((int)v8, 16, v7, (int)sub_681563), v121 = v131),
        v121) )
  {
    v9 = *(_DWORD *)(*this + 104);
    v122 = 0;
    v125 = &v121[16 * v9];
    v10 = 3 * v9;
    v11 = this[1];
    v12 = &v121[16 * v10];
    v116 = v121;
    v120 = &v121[32 * *(_DWORD *)(*this + 104)];
    v119 = v12;
    if ( *(_DWORD *)(v11 + 112) )
    {
      v128 = v118 + 2;
      do
      {
        v123 = 0;
        v124 = -1;
        v126 = -1;
        if ( *(_DWORD *)(v11 + 108) )
        {
          v13 = v114 + 2;
          v132 = v114 + 2;
          do
          {
            v14 = *((_DWORD *)v13 - 2);
            v112 = 0;
            if ( v14 != v124 )
            {
              v15 = v126;
              if ( v14 == v126 )
              {
                v126 = -1;
                v124 = v15;
                v16 = v125;
                v125 = v116;
                v17 = v120;
                v120 = v12;
                v116 = v16;
                v119 = v17;
                v12 = v17;
              }
              else
              {
                v124 = *((_DWORD *)v13 - 2);
                (*(void (__thiscall **)(_DWORD, int, _DWORD, char *))(*(_DWORD *)*this + 4))(
                  *this,
                  v14,
                  *((_DWORD *)v128 - 2),
                  v116);
                (*(void (__thiscall **)(_DWORD, int, _DWORD, char *))(*(_DWORD *)*this + 4))(
                  *this,
                  v124,
                  *(_DWORD *)v128,
                  v120);
              }
            }
            if ( *(_DWORD *)v13 != v126 )
            {
              v126 = *(_DWORD *)v13;
              (*(void (__thiscall **)(_DWORD, _DWORD, _DWORD, char *))(*(_DWORD *)*this + 4))(
                *this,
                *(_DWORD *)v13,
                *((_DWORD *)v128 - 2),
                v125);
              (*(void (__thiscall **)(_DWORD, int, _DWORD, char *))(*(_DWORD *)*this + 4))(
                *this,
                v126,
                *(_DWORD *)v128,
                v12);
            }
            if ( *(_DWORD *)(this[1] + 104) )
            {
              v18 = Block + 2;
              v115 = v127;
              do
              {
                v19 = v18[1];
                v20 = 16 * *(_DWORD *)v18;
                v76 = v19 * *(float *)&v119[v20];
                v77 = v19 * *(float *)&v119[v20 + 4];
                v78 = v19 * *(float *)&v119[v20 + 8];
                v21 = v19 * *(float *)&v119[v20 + 12];
                v22 = *(v18 - 1);
                v23 = 16 * *((_DWORD *)v18 - 2);
                v109 = v22 * *(float *)&v119[v23 + 4];
                v110 = v22 * *(float *)&v119[v23 + 8];
                v24 = (float *)&v120[v20];
                v111 = v22 * *(float *)&v119[v23 + 12];
                v100 = v22 * *(float *)&v119[v23] + v76;
                v101 = v109 + v77;
                v102 = v110 + v78;
                v25 = v13[1];
                v58 = v100 * v25;
                v59 = v101 * v25;
                v60 = v102 * v25;
                v26 = (v21 + v111) * v25;
                v27 = v18[1];
                v52 = v27 * *v24;
                v53 = v27 * v24[1];
                v54 = v27 * v24[2];
                v28 = *(v18 - 1);
                v94 = v28 * *(float *)&v120[v23 + 4];
                v95 = v28 * *(float *)&v120[v23 + 8];
                v96 = v28 * *(float *)&v120[v23 + 12];
                v70 = v28 * *(float *)&v120[v23] + v52;
                v71 = v94 + v53;
                v72 = v95 + v54;
                v29 = *(v13 - 1);
                v88 = v70 * v29;
                v89 = v71 * v29;
                v90 = v72 * v29;
                v82 = v88 + v58;
                v83 = v89 + v59;
                v84 = v90 + v60;
                v30 = v26 + (v27 * v24[3] + v96) * v29;
                v31 = v128[1];
                v32 = 16 * *(_DWORD *)v18;
                v55 = v82 * v31;
                v56 = v83 * v31;
                v57 = v84 * v31;
                v33 = v30 * v31;
                v34 = v18[1];
                v64 = v34 * *(float *)&v125[v32];
                v65 = v34 * *(float *)&v125[v32 + 4];
                v66 = v34 * *(float *)&v125[v32 + 8];
                v35 = v34 * *(float *)&v125[v32 + 12];
                v36 = *(v18 - 1);
                v106 = v36 * *(float *)&v125[v23 + 4];
                v107 = v36 * *(float *)&v125[v23 + 8];
                v108 = v36 * *(float *)&v125[v23 + 12];
                v103 = v36 * *(float *)&v125[v23] + v64;
                v37 = (float *)&v116[v32];
                v38 = (float *)&v116[v23];
                v104 = v106 + v65;
                v105 = v107 + v66;
                v39 = v13[1];
                v73 = v103 * v39;
                v74 = v104 * v39;
                v75 = v105 * v39;
                v40 = (v35 + v108) * v39;
                v41 = v18[1];
                v97 = v41 * *v37;
                v98 = v41 * v37[1];
                v99 = v41 * v37[2];
                v42 = *(v18 - 1);
                v91 = v42 * v38[1];
                v92 = v42 * v38[2];
                v93 = v42 * v38[3];
                v85 = v42 * *v38 + v97;
                v86 = v91 + v98;
                v87 = v92 + v99;
                v43 = *(v13 - 1);
                v79 = v85 * v43;
                v80 = v86 * v43;
                v81 = v87 * v43;
                v44 = (v41 * v37[3] + v93) * v43;
                v67 = v79 + v73;
                v68 = v80 + v74;
                v69 = v81 + v75;
                v45 = *(v128 - 1);
                v46 = v115;
                v115 += 4;
                v18 += 4;
                ++v112;
                v61 = v67 * v45;
                v62 = v68 * v45;
                v63 = v69 * v45;
                v48 = v61 + v55;
                v49 = v62 + v56;
                v50 = v63 + v57;
                v51 = (v40 + v44) * v45 + v33;
                *v46++ = v48;
                *v46++ = v49;
                *v46 = v50;
                v46[1] = v51;
                v13 = v132;
              }
              while ( v112 < *(_DWORD *)(this[1] + 104) );
              v12 = v119;
            }
            (*(void (__thiscall **)(_DWORD, unsigned int, unsigned int, float *))(*(_DWORD *)this[1] + 8))(
              this[1],
              v123,
              v122,
              v127);
            v13 += 4;
            ++v123;
            v132 = v13;
          }
          while ( v123 < *(_DWORD *)(this[1] + 108) );
        }
        v128 += 4;
        ++v122;
        v11 = this[1];
      }
      while ( v122 < *(_DWORD *)(v11 + 112) );
    }
    v47 = 0;
  }
  else
  {
LABEL_31:
    v47 = -2147024882;
  }
  j__free(Block);
  j__free(v114);
  j__free(v118);
  j__free(v127);
  j__free(v121);
  return v47;
}
