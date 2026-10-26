int __thiscall sub_5426D8(_DWORD *this)
{
  _DWORD *v1; // esi
  int v2; // eax
  int *v4; // eax
  int v5; // edi
  void *v6; // eax
  void *v7; // eax
  int v8; // edi
  char *v9; // eax
  char *v10; // eax
  int v11; // edi
  char *v12; // ecx
  char *v13; // edi
  int v14; // eax
  int *v15; // ebx
  int v16; // eax
  int v17; // ecx
  char *v18; // ecx
  char *v19; // eax
  int *v20; // eax
  double v21; // st7
  int v22; // ecx
  double v23; // st6
  int v24; // edx
  double v25; // st6
  double v26; // st7
  double v27; // st6
  double v28; // st5
  double v29; // st5
  double v30; // st7
  double v31; // st6
  double v32; // st7
  double v33; // st6
  double v34; // st6
  double v35; // st5
  float *v36; // ecx
  double v37; // st5
  double v38; // st6
  double v39; // st5
  double v40; // st4
  double v41; // st4
  double v42; // st3
  double v43; // st5
  float *v44; // edi
  int v45; // esi
  float v46; // [esp+4h] [ebp-1A4h]
  float v47; // [esp+8h] [ebp-1A0h]
  float v48; // [esp+Ch] [ebp-19Ch]
  float v49; // [esp+10h] [ebp-198h]
  float v50; // [esp+14h] [ebp-194h]
  float v51; // [esp+18h] [ebp-190h]
  float v52; // [esp+1Ch] [ebp-18Ch]
  float v53; // [esp+24h] [ebp-184h]
  float v54; // [esp+28h] [ebp-180h]
  float v55; // [esp+2Ch] [ebp-17Ch]
  float v56; // [esp+34h] [ebp-174h]
  float v57; // [esp+38h] [ebp-170h]
  float v58; // [esp+3Ch] [ebp-16Ch]
  float v59; // [esp+44h] [ebp-164h]
  float v60; // [esp+48h] [ebp-160h]
  float v61; // [esp+4Ch] [ebp-15Ch]
  float v62; // [esp+54h] [ebp-154h]
  float v63; // [esp+58h] [ebp-150h]
  float v64; // [esp+5Ch] [ebp-14Ch]
  float v65; // [esp+64h] [ebp-144h]
  float v66; // [esp+68h] [ebp-140h]
  float v67; // [esp+6Ch] [ebp-13Ch]
  float v68; // [esp+74h] [ebp-134h]
  float v69; // [esp+78h] [ebp-130h]
  float v70; // [esp+7Ch] [ebp-12Ch]
  float v71; // [esp+84h] [ebp-124h]
  float v72; // [esp+88h] [ebp-120h]
  float v73; // [esp+8Ch] [ebp-11Ch]
  float v74; // [esp+94h] [ebp-114h]
  float v75; // [esp+98h] [ebp-110h]
  float v76; // [esp+9Ch] [ebp-10Ch]
  float v77; // [esp+A4h] [ebp-104h]
  float v78; // [esp+A8h] [ebp-100h]
  float v79; // [esp+ACh] [ebp-FCh]
  float v80; // [esp+B4h] [ebp-F4h]
  float v81; // [esp+B8h] [ebp-F0h]
  float v82; // [esp+BCh] [ebp-ECh]
  float v83; // [esp+C4h] [ebp-E4h]
  float v84; // [esp+C8h] [ebp-E0h]
  float v85; // [esp+CCh] [ebp-DCh]
  float v86; // [esp+D4h] [ebp-D4h]
  float v87; // [esp+D8h] [ebp-D0h]
  float v88; // [esp+DCh] [ebp-CCh]
  float v89; // [esp+E8h] [ebp-C0h]
  float v90; // [esp+ECh] [ebp-BCh]
  float v91; // [esp+F0h] [ebp-B8h]
  float v92; // [esp+F8h] [ebp-B0h]
  float v93; // [esp+FCh] [ebp-ACh]
  float v94; // [esp+100h] [ebp-A8h]
  float v95; // [esp+104h] [ebp-A4h]
  float v96; // [esp+108h] [ebp-A0h]
  float v97; // [esp+10Ch] [ebp-9Ch]
  float v98; // [esp+114h] [ebp-94h]
  float v99; // [esp+118h] [ebp-90h]
  float v100; // [esp+11Ch] [ebp-8Ch]
  float v101; // [esp+124h] [ebp-84h]
  float v102; // [esp+128h] [ebp-80h]
  float v103; // [esp+12Ch] [ebp-7Ch]
  float v104; // [esp+138h] [ebp-70h]
  float v105; // [esp+13Ch] [ebp-6Ch]
  float v106; // [esp+140h] [ebp-68h]
  float v107; // [esp+148h] [ebp-60h]
  float v108; // [esp+14Ch] [ebp-5Ch]
  float v109; // [esp+150h] [ebp-58h]
  float *v111; // [esp+158h] [ebp-50h]
  int *v112; // [esp+15Ch] [ebp-4Ch]
  int *v113; // [esp+160h] [ebp-48h]
  void *v114; // [esp+164h] [ebp-44h]
  char *v115; // [esp+168h] [ebp-40h]
  BOOL v116; // [esp+16Ch] [ebp-3Ch]
  int *v117; // [esp+16Ch] [ebp-3Ch]
  unsigned int v118; // [esp+170h] [ebp-38h]
  float *v119; // [esp+174h] [ebp-34h]
  char *v120; // [esp+178h] [ebp-30h]
  char *v121; // [esp+17Ch] [ebp-2Ch]
  char *v122; // [esp+180h] [ebp-28h]
  unsigned int v123; // [esp+184h] [ebp-24h]
  BOOL v124; // [esp+188h] [ebp-20h]
  unsigned int v125; // [esp+188h] [ebp-20h]
  char *v126; // [esp+18Ch] [ebp-1Ch]
  int v127; // [esp+190h] [ebp-18h]
  int v128; // [esp+194h] [ebp-14h]
  float *v129; // [esp+198h] [ebp-10h]

  v1 = this;
  v2 = this[2];
  if ( (_BYTE)v2 != 3 )
    return -2147467259;
  v124 = (v2 & 0x40000) == 0;
  v116 = (v2 & 0x20000) == 0;
  v113 = sub_5421F2(*(_DWORD *)(this[1] + 4184), *(_DWORD *)(*this + 4184), (v2 & 0x10000) == 0);
  v112 = sub_5421F2(*(_DWORD *)(v1[1] + 4188), *(_DWORD *)(*v1 + 4188), v116);
  v4 = sub_5421F2(*(_DWORD *)(v1[1] + 4192), *(_DWORD *)(*v1 + 4192), v124);
  v117 = v4;
  if ( !v113 || !v112 || !v4 )
    goto LABEL_31;
  v5 = *(_DWORD *)(v1[1] + 4184);
  v6 = operator new(16 * v5);
  v114 = v6;
  if ( v6 )
  {
    sub_53D688((int)v6, 16, v5, (int (__thiscall *)(int))sub_53D5B2);
    v7 = v114;
    v119 = (float *)v114;
  }
  else
  {
    v119 = 0;
    v7 = 0;
  }
  if ( v7
    && ((v8 = 4 * *(_DWORD *)(*v1 + 4184), v9 = (char *)operator new(*(_DWORD *)(*v1 + 4184) << 6), (v120 = v9) == 0)
      ? (v10 = 0)
      : (sub_53D688((int)v9, 16, v8, (int (__thiscall *)(int))sub_53D5B2), v10 = v120),
        v10) )
  {
    v11 = *(_DWORD *)(*v1 + 4184);
    v118 = 0;
    v126 = &v10[16 * v11];
    v12 = &v10[32 * v11];
    v13 = &v10[48 * v11];
    v122 = v10;
    v14 = v1[1];
    v115 = v12;
    v121 = v13;
    if ( *(_DWORD *)(v14 + 4192) )
    {
      v129 = (float *)(v117 + 2);
      do
      {
        v123 = 0;
        v127 = -1;
        v128 = -1;
        if ( *(_DWORD *)(v14 + 4188) )
        {
          v15 = v112 + 2;
          do
          {
            v16 = *(v15 - 2);
            v125 = 0;
            if ( v16 != v127 )
            {
              v17 = v128;
              if ( v16 == v128 )
              {
                v128 = -1;
                v127 = v17;
                v18 = v126;
                v126 = v122;
                v19 = v115;
                v115 = v13;
                v122 = v18;
                v121 = v19;
                v13 = v19;
              }
              else
              {
                v127 = *(v15 - 2);
                (*(void (__thiscall **)(_DWORD, int, _DWORD, char *))(*(_DWORD *)*v1 + 4))(
                  *v1,
                  v16,
                  *((_DWORD *)v129 - 2),
                  v122);
                (*(void (__thiscall **)(_DWORD, int, _DWORD, char *))(*(_DWORD *)*v1 + 4))(
                  *v1,
                  v127,
                  *(_DWORD *)v129,
                  v115);
              }
            }
            if ( *v15 != v128 )
            {
              v128 = *v15;
              (*(void (__thiscall **)(_DWORD, int, _DWORD, char *))(*(_DWORD *)*v1 + 4))(
                *v1,
                *v15,
                *((_DWORD *)v129 - 2),
                v126);
              (*(void (__thiscall **)(_DWORD, int, _DWORD, char *))(*(_DWORD *)*v1 + 4))(
                *v1,
                v128,
                *(_DWORD *)v129,
                v13);
            }
            if ( *(_DWORD *)(v1[1] + 4184) )
            {
              v20 = v113 + 2;
              v111 = v119;
              do
              {
                v21 = *((float *)v20 + 1);
                v22 = 16 * *v20;
                v74 = v21 * *(float *)&v13[v22];
                v75 = v21 * *(float *)&v13[v22 + 4];
                v76 = v21 * *(float *)&v13[v22 + 8];
                v23 = *((float *)v20 - 1);
                v24 = 16 * *(v20 - 2);
                v107 = v23 * *(float *)&v13[v24 + 4];
                v108 = v23 * *(float *)&v13[v24 + 8];
                v109 = v23 * *(float *)&v13[v24 + 12];
                v98 = v23 * *(float *)&v13[v24] + v74;
                v99 = v107 + v75;
                v100 = v108 + v76;
                v25 = *((float *)v15 + 1);
                v56 = v98 * v25;
                v57 = v99 * v25;
                v58 = v100 * v25;
                v26 = (v109 + v21 * *(float *)&v13[v22 + 12]) * v25;
                v27 = *((float *)v20 + 1);
                v50 = v27 * *(float *)&v115[v22];
                v51 = v27 * *(float *)&v115[v22 + 4];
                v52 = v27 * *(float *)&v115[v22 + 8];
                v28 = *((float *)v20 - 1);
                v92 = v28 * *(float *)&v115[v24 + 4];
                v93 = v28 * *(float *)&v115[v24 + 8];
                v94 = v28 * *(float *)&v115[v24 + 12];
                v68 = v28 * *(float *)&v115[v24] + v50;
                v69 = v92 + v51;
                v70 = v93 + v52;
                v29 = *((float *)v15 - 1);
                v86 = v68 * v29;
                v87 = v69 * v29;
                v88 = v70 * v29;
                v80 = v86 + v56;
                v81 = v87 + v57;
                v82 = v88 + v58;
                v30 = (v94 + v27 * *(float *)&v115[v22 + 12]) * v29 + v26;
                v31 = v129[1];
                v53 = v80 * v31;
                v54 = v81 * v31;
                v55 = v82 * v31;
                v32 = v30 * v31;
                v33 = *((float *)v20 + 1);
                v62 = v33 * *(float *)&v126[v22];
                v63 = v33 * *(float *)&v126[v22 + 4];
                v64 = v33 * *(float *)&v126[v22 + 8];
                v34 = v33 * *(float *)&v126[v22 + 12];
                v35 = *((float *)v20 - 1);
                v104 = v35 * *(float *)&v126[v24 + 4];
                v105 = v35 * *(float *)&v126[v24 + 8];
                v36 = (float *)&v122[v22];
                v106 = v35 * *(float *)&v126[v24 + 12];
                v101 = v35 * *(float *)&v126[v24] + v62;
                v102 = v104 + v63;
                v103 = v105 + v64;
                v37 = *((float *)v15 + 1);
                v71 = v101 * v37;
                v72 = v102 * v37;
                v73 = v103 * v37;
                v38 = (v106 + v34) * v37;
                v39 = *((float *)v20 + 1);
                v95 = v39 * *v36;
                v96 = v39 * v36[1];
                v97 = v39 * v36[2];
                v40 = *((float *)v20 - 1);
                v89 = v40 * *(float *)&v122[v24 + 4];
                v90 = v40 * *(float *)&v122[v24 + 8];
                v91 = v40 * *(float *)&v122[v24 + 12];
                v83 = v40 * *(float *)&v122[v24] + v95;
                v84 = v89 + v96;
                v85 = v90 + v97;
                v41 = *((float *)v15 - 1);
                v77 = v83 * v41;
                v78 = v84 * v41;
                v79 = v85 * v41;
                v42 = (v91 + v39 * v36[3]) * v41;
                v65 = v77 + v71;
                v66 = v78 + v72;
                v67 = v79 + v73;
                v43 = *(v129 - 1);
                v59 = v65 * v43;
                v60 = v66 * v43;
                v61 = v67 * v43;
                v44 = v111;
                v111 += 4;
                v46 = v59 + v53;
                v20 += 4;
                ++v125;
                v47 = v60 + v54;
                v48 = v61 + v55;
                v49 = (v42 + v38) * v43 + v32;
                *v44++ = v46;
                *v44++ = v47;
                *v44 = v48;
                v44[1] = v49;
                v13 = v121;
              }
              while ( v125 < *(_DWORD *)(this[1] + 4184) );
              v1 = this;
            }
            (*(void (__thiscall **)(_DWORD, unsigned int, unsigned int, float *))(*(_DWORD *)v1[1] + 8))(
              v1[1],
              v123,
              v118,
              v119);
            v15 += 4;
            ++v123;
          }
          while ( v123 < *(_DWORD *)(v1[1] + 4188) );
        }
        v129 += 4;
        ++v118;
        v14 = v1[1];
      }
      while ( v118 < *(_DWORD *)(v14 + 4192) );
    }
    v45 = 0;
  }
  else
  {
LABEL_31:
    v45 = -2147024882;
  }
  sub_5BE8AE();
  sub_5BE8AE();
  sub_5BE8AE();
  sub_5BE8AE();
  sub_5BE8AE();
  return v45;
}
