int __thiscall sub_52E6F0(_DWORD *this, int a2)
{
  int v3; // edx
  _DWORD *v5; // edx
  int *v6; // edi
  int v7; // eax
  int *v8; // eax
  int v9; // edx
  int *v10; // eax
  unsigned __int32 v11; // eax
  int v12; // ebx
  int v13; // ecx
  unsigned __int32 v14; // eax
  int v15; // ebx
  unsigned __int32 v16; // eax
  int *v17; // eax
  int v18; // ecx
  unsigned __int32 v19; // eax
  int v20; // ebx
  int v21; // eax
  int *v22; // ebx
  int *v23; // eax
  int *v24; // edi
  int v25; // edx
  int *v26; // eax
  int v27; // edx
  unsigned __int32 v28; // eax
  int v29; // ecx
  int v30; // edx
  int v31; // edx
  unsigned __int32 v32; // eax
  int v33; // ecx
  int *v34; // edx
  int *v35; // eax
  int v36; // ecx
  int *v37; // edx
  int v38; // edi
  int v39; // ecx
  double v40; // st7
  _DWORD *v41; // ecx
  int v42; // ecx
  int v43; // edi
  int v44; // ecx
  double v45; // st7
  int v46; // ecx
  int *v47; // ebx
  int *v48; // eax
  int v49; // edx
  int v50; // edx
  unsigned __int32 v51; // eax
  int v52; // ecx
  int *v53; // edx
  int v54; // eax
  int v55; // ecx
  int v56; // ebx
  int v57; // ecx
  bool v58; // zf
  int v59; // eax
  unsigned int v60; // ecx
  int v61; // eax
  int *v62; // edi
  char *v63; // edx
  unsigned __int8 v64; // bl
  int v65; // ecx
  unsigned __int32 v66; // eax
  bool v67; // cc
  _BYTE *v68; // edi
  int v69; // ebx
  int v70; // edi
  _BYTE *v71; // ebx
  signed int v72; // ebx
  int v73; // ecx
  unsigned __int32 *v74; // edi
  unsigned __int8 v75; // bl
  char v76; // dl
  char v77; // bl
  int v78; // edx
  int v79; // edx
  char *v80; // edi
  int v81; // ebx
  int v82; // eax
  unsigned __int32 v83; // eax
  int v84; // ebx
  unsigned __int32 v85; // eax
  int v86; // ebx
  unsigned __int32 v87; // eax
  int v88; // ebx
  unsigned __int32 v89; // eax
  int v90; // ebx
  unsigned __int32 v91; // eax
  int v92; // ebx
  unsigned __int32 v93; // eax
  int v94; // ebx
  unsigned __int32 v95; // eax
  int v96; // ebx
  unsigned __int32 v97; // eax
  int v98; // ebx
  unsigned __int32 v99; // eax
  int v100; // ebx
  unsigned __int32 v101; // eax
  int v102; // ebx
  unsigned __int32 v103; // eax
  int v104; // ebx
  unsigned __int32 v105; // eax
  int v106; // ebx
  unsigned __int32 v107; // eax
  int v108; // ebx
  unsigned __int32 v109; // eax
  int v110; // ebx
  unsigned __int32 v111; // eax
  int v112; // ebx
  unsigned __int32 v113; // eax
  int v114; // ebx
  unsigned __int32 v115; // eax
  int v116; // ebx
  unsigned __int32 v117; // eax
  int v118; // ebx
  unsigned __int32 v119; // eax
  int v120; // ebx
  unsigned __int32 v121; // eax
  int v122; // ebx
  unsigned __int32 v123; // eax
  int v124; // ebx
  unsigned __int32 v125; // eax
  int v126; // ebx
  unsigned __int32 v127; // eax
  int v128; // ebx
  unsigned __int32 v129; // eax
  int v130; // ebx
  unsigned __int32 v131; // eax
  int v132; // ebx
  unsigned __int32 v133; // eax
  int v134; // ebx
  unsigned __int32 v135; // eax
  int v136; // ebx
  unsigned __int32 v137; // eax
  int v138; // ecx
  int v139; // edx
  unsigned __int32 v140; // eax
  int v141; // ecx
  int v142; // ebx
  _DWORD *v143; // ecx
  int v144; // edx
  unsigned __int32 v145; // eax
  int v146; // ecx
  int v147; // ecx
  int v148; // edx
  unsigned __int32 v149; // eax
  int v150; // ecx
  int v151; // ecx
  int v152; // edx
  unsigned __int32 v153; // eax
  int v154; // ecx
  int v155; // edi
  char *v156; // ebx
  _BYTE v157[768]; // [esp+4h] [ebp-75Ch] BYREF
  char v158; // [esp+304h] [ebp-45Ch] BYREF
  char v159; // [esp+308h] [ebp-458h] BYREF
  _BYTE v160[128]; // [esp+604h] [ebp-15Ch] BYREF
  int v161; // [esp+684h] [ebp-DCh] BYREF
  _DWORD v162[31]; // [esp+688h] [ebp-D8h] BYREF
  char v163; // [esp+704h] [ebp-5Ch] BYREF
  char v164; // [esp+705h] [ebp-5Bh] BYREF
  char v165; // [esp+724h] [ebp-3Ch]
  _BYTE v166[31]; // [esp+725h] [ebp-3Bh]
  _DWORD *v167; // [esp+744h] [ebp-1Ch]
  unsigned int v168; // [esp+748h] [ebp-18h]
  int v169; // [esp+74Ch] [ebp-14h]
  int v170; // [esp+750h] [ebp-10h]
  int v171; // [esp+754h] [ebp-Ch]
  unsigned int v172; // [esp+758h] [ebp-8h]
  signed int v173; // [esp+75Ch] [ebp-4h]

  v3 = this[2345];
  if ( !v3 )
    return -1;
  if ( dword_8B0108 )
  {
    v59 = this[2346];
    if ( this[2355] == 2 )
    {
      v60 = v3 + (v59 >> 3);
      this[2346] = v59 + 256;
      v61 = 0;
      v62 = &v161;
      v172 = v60;
      v168 = 0;
      v171 = (int)&v161;
      v63 = &v164;
      do
      {
        v64 = *(_BYTE *)(v61 + v60);
        *(v63 - 1) = v64 >> 4;
        *v63 = v64 & 0xF;
        if ( *(v63 - 1) )
        {
          v173 = *(_DWORD *)(((int)this[2346] >> 3) + this[2345]);
          v65 = this[2346];
          *(v62 - 32) = (_byteswap_ulong(v173) >> (-6 - (this[2346] & 7))) & 0x3F;
          this[2346] = v65 + 6;
          v60 = v172;
        }
        if ( *v63 )
        {
          v173 = *(_DWORD *)(((int)this[2346] >> 3) + this[2345]);
          v66 = (_byteswap_ulong(v173) >> (-6 - (this[2346] & 7))) & 0x3F;
          v60 = v172;
          this[2346] += 6;
          v62 = (int *)v171;
          *(_DWORD *)v171 = v66;
        }
        v63 += 2;
        v61 = v168 + 1;
        ++v62;
        v67 = (int)++v168 < 32;
        v171 = (int)v62;
      }
      while ( v67 );
      v68 = v157;
      v69 = 12;
      do
      {
        sub_52E5E0(this, 0, (int)&v163, (int)v160, (int)v68, (int)&unk_5B2BA4);
        sub_52E5E0(this, 1, (int)&v163, (int)v160, (int)v68, (int)&unk_5B2BA4);
        sub_52E5E0(this, 2, (int)&v163, (int)v160, (int)v68, (int)&unk_5B2BA4);
        sub_52E5E0(this, 3, (int)&v163, (int)v160, (int)v68, (int)&unk_5B2BA4);
        sub_52E5E0(this, 4, (int)&v163, (int)v160, (int)v68, (int)&unk_5B2BA4);
        sub_52E5E0(this, 5, (int)&v163, (int)v160, (int)v68, (int)&unk_5B2BA4);
        sub_52E5E0(this, 6, (int)&v163, (int)v160, (int)v68, (int)&unk_5B2BA4);
        sub_52E5E0(this, 7, (int)&v163, (int)v160, (int)v68, (int)&unk_5B2BA4);
        sub_52E5E0(this, 8, (int)&v163, (int)v160, (int)v68, (int)&unk_5B2BA4);
        sub_52E5E0(this, 9, (int)&v163, (int)v160, (int)v68, (int)&unk_5B2BA4);
        sub_52E5E0(this, 10, (int)&v163, (int)v160, (int)v68, (int)&unk_5B2BA4);
        sub_52E5E0(this, 11, (int)&v163, (int)v160, (int)v68, (int)&unk_5B2BA4);
        sub_52E5E0(this, 12, (int)&v163, (int)v160, (int)v68, (int)&unk_5B2BA4);
        sub_52E5E0(this, 13, (int)&v163, (int)v160, (int)v68, (int)&unk_5B2BA4);
        sub_52E5E0(this, 14, (int)&v163, (int)v160, (int)v68, (int)&unk_5B2BA4);
        sub_52E5E0(this, 15, (int)&v163, (int)v160, (int)v68, (int)&unk_5B2BA4);
        sub_52E5E0(this, 16, (int)&v163, (int)v160, (int)v68, (int)&unk_5B2BA4);
        sub_52E5E0(this, 17, (int)&v163, (int)v160, (int)v68, (int)&unk_5B2BA4);
        sub_52E5E0(this, 18, (int)&v163, (int)v160, (int)v68, (int)&unk_5B2BA4);
        sub_52E5E0(this, 19, (int)&v163, (int)v160, (int)v68, (int)&unk_5B2BA4);
        sub_52E5E0(this, 20, (int)&v163, (int)v160, (int)v68, (int)&unk_5B2BA4);
        sub_52E5E0(this, 21, (int)&v163, (int)v160, (int)v68, (int)&unk_5B2BA4);
        sub_52E5E0(this, 22, (int)&v163, (int)v160, (int)v68, (int)&unk_5B2BA4);
        sub_52E5E0(this, 23, (int)&v163, (int)v160, (int)v68, (int)&unk_5B2BA4);
        sub_52E5E0(this, 24, (int)&v163, (int)v160, (int)v68, (int)&unk_5B2BA4);
        sub_52E5E0(this, 25, (int)&v163, (int)v160, (int)v68, (int)&unk_5B2BA4);
        sub_52E5E0(this, 26, (int)&v163, (int)v160, (int)v68, (int)&unk_5B2BA4);
        sub_52E5E0(this, 27, (int)&v163, (int)v160, (int)v68, (int)&unk_5B2BA4);
        sub_52E5E0(this, 28, (int)&v163, (int)v160, (int)v68, (int)&unk_5B2BA4);
        sub_52E5E0(this, 29, (int)&v163, (int)v160, (int)v68, (int)&unk_5B2BA4);
        sub_52E5E0(this, 30, (int)&v163, (int)v160, (int)v68, (int)&unk_5B2BA4);
        sub_52E5E0(this, 31, (int)&v163, (int)v160, (int)v68, (int)&unk_5B2BA4);
        v68 += 128;
        --v69;
      }
      while ( v69 );
      v70 = a2;
      v71 = v157;
      v172 = 12;
      do
      {
        sub_532AA0(v70, v71);
        v71 += 128;
        v70 += 2 * this[2356];
        --v172;
      }
      while ( v172 );
    }
    else
    {
      v72 = v3 + (v59 >> 3);
      v73 = 0;
      v74 = v162;
      v173 = v72;
      this[2346] = v59 + 128;
      v169 = 0;
      v172 = (unsigned int)v162;
      while ( 1 )
      {
        v75 = *(_BYTE *)((v73 >> 1) + v72);
        v76 = v75 >> 4;
        v77 = v75 & 0xF;
        v166[v73 - 1] = v76;
        v166[v73] = v77;
        if ( v166[v73 - 1] )
        {
          v168 = *(_DWORD *)(((int)this[2346] >> 3) + this[2345]);
          v78 = this[2346];
          v74 = (unsigned __int32 *)v172;
          v73 = v169;
          *(_DWORD *)(v172 - 4) = (_byteswap_ulong(v168) >> (-6 - (v78 & 7))) & 0x3F;
          this[2346] = v78 + 6;
        }
        if ( v77 )
        {
          v172 = *(_DWORD *)(((int)this[2346] >> 3) + this[2345]);
          v79 = this[2346];
          v73 = v169;
          *v74 = (_byteswap_ulong(v172) >> (-6 - (this[2346] & 7))) & 0x3F;
          this[2346] = v79 + 6;
        }
        v73 += 2;
        v74 += 2;
        v169 = v73;
        v172 = (unsigned int)v74;
        if ( v73 >= 32 )
          break;
        v72 = v173;
      }
      v80 = &v159;
      v169 = v166[27];
      v167 = (_DWORD *)v166[28];
      v172 = 12;
      v170 = v166[29];
      v171 = v166[30];
      do
      {
        v81 = v165;
        LOWORD(v82) = 0;
        if ( v165 )
        {
          v173 = *(_DWORD *)(((int)this[2346] >> 3) + this[2345]);
          v83 = dword_5B4788[v165 + 1] & (_byteswap_ulong(v173) >> -(char)(v165 + 1 + (this[2346] & 7)));
          this[2346] += v165 + 1;
          v82 = (int)((v83 + dword_5B4820[v81]) * dword_5B2CA4[64 * v81 + v161]) >> 12;
        }
        v84 = v166[0];
        *((_WORD *)v80 - 2) = v82;
        LOWORD(v82) = 0;
        if ( v84 )
        {
          v173 = *(_DWORD *)(((int)this[2346] >> 3) + this[2345]);
          v85 = dword_5B4788[v84 + 1] & (_byteswap_ulong(v173) >> -(char)(v84 + 1 + (this[2346] & 7)));
          this[2346] += v84 + 1;
          v82 = (int)((v85 + dword_5B4820[v84]) * dword_5B2CA4[64 * v84 + v162[0]]) >> 12;
        }
        v86 = v166[1];
        *((_WORD *)v80 - 1) = v82;
        LOWORD(v82) = 0;
        if ( v86 )
        {
          v173 = *(_DWORD *)(((int)this[2346] >> 3) + this[2345]);
          v87 = dword_5B4788[v86 + 1] & (_byteswap_ulong(v173) >> -(char)(v86 + 1 + (this[2346] & 7)));
          this[2346] += v86 + 1;
          v82 = (int)((v87 + dword_5B4820[v86]) * dword_5B2CA4[64 * v86 + v162[1]]) >> 12;
        }
        v88 = v166[2];
        *(_WORD *)v80 = v82;
        LOWORD(v82) = 0;
        if ( v88 )
        {
          v173 = *(_DWORD *)(((int)this[2346] >> 3) + this[2345]);
          v89 = dword_5B4788[v88 + 1] & (_byteswap_ulong(v173) >> -(char)(v88 + 1 + (this[2346] & 7)));
          this[2346] += v88 + 1;
          v82 = (int)((v89 + dword_5B4820[v88]) * dword_5B2CA4[64 * v88 + v162[2]]) >> 12;
        }
        v90 = v166[3];
        *((_WORD *)v80 + 1) = v82;
        LOWORD(v82) = 0;
        if ( v90 )
        {
          v173 = *(_DWORD *)(((int)this[2346] >> 3) + this[2345]);
          v91 = dword_5B4788[v90 + 1] & (_byteswap_ulong(v173) >> -(char)(v90 + 1 + (this[2346] & 7)));
          this[2346] += v90 + 1;
          v82 = (int)((v91 + dword_5B4820[v90]) * dword_5B2CA4[64 * v90 + v162[3]]) >> 12;
        }
        v92 = v166[4];
        *((_WORD *)v80 + 2) = v82;
        LOWORD(v82) = 0;
        if ( v92 )
        {
          v173 = *(_DWORD *)(((int)this[2346] >> 3) + this[2345]);
          v93 = dword_5B4788[v92 + 1] & (_byteswap_ulong(v173) >> -(char)(v92 + 1 + (this[2346] & 7)));
          this[2346] += v92 + 1;
          v82 = (int)((v93 + dword_5B4820[v92]) * dword_5B2CA4[64 * v92 + v162[4]]) >> 12;
        }
        v94 = v166[5];
        *((_WORD *)v80 + 3) = v82;
        LOWORD(v82) = 0;
        if ( v94 )
        {
          v173 = *(_DWORD *)(((int)this[2346] >> 3) + this[2345]);
          v95 = dword_5B4788[v94 + 1] & (_byteswap_ulong(v173) >> -(char)(v94 + 1 + (this[2346] & 7)));
          this[2346] += v94 + 1;
          v82 = (int)((v95 + dword_5B4820[v94]) * dword_5B2CA4[64 * v94 + v162[5]]) >> 12;
        }
        v96 = v166[6];
        *((_WORD *)v80 + 4) = v82;
        LOWORD(v82) = 0;
        if ( v96 )
        {
          v173 = *(_DWORD *)(((int)this[2346] >> 3) + this[2345]);
          v97 = dword_5B4788[v96 + 1] & (_byteswap_ulong(v173) >> -(char)(v96 + 1 + (this[2346] & 7)));
          this[2346] += v96 + 1;
          v82 = (int)((v97 + dword_5B4820[v96]) * dword_5B2CA4[64 * v96 + v162[6]]) >> 12;
        }
        v98 = v166[7];
        *((_WORD *)v80 + 5) = v82;
        LOWORD(v82) = 0;
        if ( v98 )
        {
          v173 = *(_DWORD *)(((int)this[2346] >> 3) + this[2345]);
          v99 = dword_5B4788[v98 + 1] & (_byteswap_ulong(v173) >> -(char)(v98 + 1 + (this[2346] & 7)));
          this[2346] += v98 + 1;
          v82 = (int)((v99 + dword_5B4820[v98]) * dword_5B2CA4[64 * v98 + v162[7]]) >> 12;
        }
        v100 = v166[8];
        *((_WORD *)v80 + 6) = v82;
        LOWORD(v82) = 0;
        if ( v100 )
        {
          v173 = *(_DWORD *)(((int)this[2346] >> 3) + this[2345]);
          v101 = dword_5B4788[v100 + 1] & (_byteswap_ulong(v173) >> -(char)(v100 + 1 + (this[2346] & 7)));
          this[2346] += v100 + 1;
          v82 = (int)((v101 + dword_5B4820[v100]) * dword_5B2CA4[64 * v100 + v162[8]]) >> 12;
        }
        v102 = v166[9];
        *((_WORD *)v80 + 7) = v82;
        LOWORD(v82) = 0;
        if ( v102 )
        {
          v173 = *(_DWORD *)(((int)this[2346] >> 3) + this[2345]);
          v103 = dword_5B4788[v102 + 1] & (_byteswap_ulong(v173) >> -(char)(v102 + 1 + (this[2346] & 7)));
          this[2346] += v102 + 1;
          v82 = (int)((v103 + dword_5B4820[v102]) * dword_5B2CA4[64 * v102 + v162[9]]) >> 12;
        }
        v104 = v166[10];
        *((_WORD *)v80 + 8) = v82;
        LOWORD(v82) = 0;
        if ( v104 )
        {
          v173 = *(_DWORD *)(((int)this[2346] >> 3) + this[2345]);
          v105 = dword_5B4788[v104 + 1] & (_byteswap_ulong(v173) >> -(char)(v104 + 1 + (this[2346] & 7)));
          this[2346] += v104 + 1;
          v82 = (int)((v105 + dword_5B4820[v104]) * dword_5B2CA4[64 * v104 + v162[10]]) >> 12;
        }
        v106 = v166[11];
        *((_WORD *)v80 + 9) = v82;
        LOWORD(v82) = 0;
        if ( v106 )
        {
          v173 = *(_DWORD *)(((int)this[2346] >> 3) + this[2345]);
          v107 = dword_5B4788[v106 + 1] & (_byteswap_ulong(v173) >> -(char)(v106 + 1 + (this[2346] & 7)));
          this[2346] += v106 + 1;
          v82 = (int)((v107 + dword_5B4820[v106]) * dword_5B2CA4[64 * v106 + v162[11]]) >> 12;
        }
        v108 = v166[12];
        *((_WORD *)v80 + 10) = v82;
        LOWORD(v82) = 0;
        if ( v108 )
        {
          v173 = *(_DWORD *)(((int)this[2346] >> 3) + this[2345]);
          v109 = dword_5B4788[v108 + 1] & (_byteswap_ulong(v173) >> -(char)(v108 + 1 + (this[2346] & 7)));
          this[2346] += v108 + 1;
          v82 = (int)((v109 + dword_5B4820[v108]) * dword_5B2CA4[64 * v108 + v162[12]]) >> 12;
        }
        v110 = v166[13];
        *((_WORD *)v80 + 11) = v82;
        LOWORD(v82) = 0;
        if ( v110 )
        {
          v173 = *(_DWORD *)(((int)this[2346] >> 3) + this[2345]);
          v111 = dword_5B4788[v110 + 1] & (_byteswap_ulong(v173) >> -(char)(v110 + 1 + (this[2346] & 7)));
          this[2346] += v110 + 1;
          v82 = (int)((v111 + dword_5B4820[v110]) * dword_5B2CA4[64 * v110 + v162[13]]) >> 12;
        }
        v112 = v166[14];
        *((_WORD *)v80 + 12) = v82;
        LOWORD(v82) = 0;
        if ( v112 )
        {
          v173 = *(_DWORD *)(((int)this[2346] >> 3) + this[2345]);
          v113 = dword_5B4788[v112 + 1] & (_byteswap_ulong(v173) >> -(char)(v112 + 1 + (this[2346] & 7)));
          this[2346] += v112 + 1;
          v82 = (int)((v113 + dword_5B4820[v112]) * dword_5B2CA4[64 * v112 + v162[14]]) >> 12;
        }
        v114 = v166[15];
        *((_WORD *)v80 + 13) = v82;
        LOWORD(v82) = 0;
        if ( v114 )
        {
          v173 = *(_DWORD *)(((int)this[2346] >> 3) + this[2345]);
          v115 = dword_5B4788[v114 + 1] & (_byteswap_ulong(v173) >> -(char)(v114 + 1 + (this[2346] & 7)));
          this[2346] += v114 + 1;
          v82 = (int)((v115 + dword_5B4820[v114]) * dword_5B2CA4[64 * v114 + v162[15]]) >> 12;
        }
        v116 = v166[16];
        *((_WORD *)v80 + 14) = v82;
        LOWORD(v82) = 0;
        if ( v116 )
        {
          v173 = *(_DWORD *)(((int)this[2346] >> 3) + this[2345]);
          v117 = dword_5B4788[v116 + 1] & (_byteswap_ulong(v173) >> -(char)(v116 + 1 + (this[2346] & 7)));
          this[2346] += v116 + 1;
          v82 = (int)((v117 + dword_5B4820[v116]) * dword_5B2CA4[64 * v116 + v162[16]]) >> 12;
        }
        v118 = v166[17];
        *((_WORD *)v80 + 15) = v82;
        LOWORD(v82) = 0;
        if ( v118 )
        {
          v173 = *(_DWORD *)(((int)this[2346] >> 3) + this[2345]);
          v119 = dword_5B4788[v118 + 1] & (_byteswap_ulong(v173) >> -(char)(v118 + 1 + (this[2346] & 7)));
          this[2346] += v118 + 1;
          v82 = (int)((v119 + dword_5B4820[v118]) * dword_5B2CA4[64 * v118 + v162[17]]) >> 12;
        }
        v120 = v166[18];
        *((_WORD *)v80 + 16) = v82;
        LOWORD(v82) = 0;
        if ( v120 )
        {
          v173 = *(_DWORD *)(((int)this[2346] >> 3) + this[2345]);
          v121 = dword_5B4788[v120 + 1] & (_byteswap_ulong(v173) >> -(char)(v120 + 1 + (this[2346] & 7)));
          this[2346] += v120 + 1;
          v82 = (int)((v121 + dword_5B4820[v120]) * dword_5B2CA4[64 * v120 + v162[18]]) >> 12;
        }
        v122 = v166[19];
        *((_WORD *)v80 + 17) = v82;
        LOWORD(v82) = 0;
        if ( v122 )
        {
          v173 = *(_DWORD *)(((int)this[2346] >> 3) + this[2345]);
          v123 = dword_5B4788[v122 + 1] & (_byteswap_ulong(v173) >> -(char)(v122 + 1 + (this[2346] & 7)));
          this[2346] += v122 + 1;
          v82 = (int)((v123 + dword_5B4820[v122]) * dword_5B2CA4[64 * v122 + v162[19]]) >> 12;
        }
        v124 = v166[20];
        *((_WORD *)v80 + 18) = v82;
        LOWORD(v82) = 0;
        if ( v124 )
        {
          v173 = *(_DWORD *)(((int)this[2346] >> 3) + this[2345]);
          v125 = dword_5B4788[v124 + 1] & (_byteswap_ulong(v173) >> -(char)(v124 + 1 + (this[2346] & 7)));
          this[2346] += v124 + 1;
          v82 = (int)((v125 + dword_5B4820[v124]) * dword_5B2CA4[64 * v124 + v162[20]]) >> 12;
        }
        v126 = v166[21];
        *((_WORD *)v80 + 19) = v82;
        LOWORD(v82) = 0;
        if ( v126 )
        {
          v173 = *(_DWORD *)(((int)this[2346] >> 3) + this[2345]);
          v127 = dword_5B4788[v126 + 1] & (_byteswap_ulong(v173) >> -(char)(v126 + 1 + (this[2346] & 7)));
          this[2346] += v126 + 1;
          v82 = (int)((v127 + dword_5B4820[v126]) * dword_5B2CA4[64 * v126 + v162[21]]) >> 12;
        }
        v128 = v166[22];
        *((_WORD *)v80 + 20) = v82;
        LOWORD(v82) = 0;
        if ( v128 )
        {
          v173 = *(_DWORD *)(((int)this[2346] >> 3) + this[2345]);
          v129 = dword_5B4788[v128 + 1] & (_byteswap_ulong(v173) >> -(char)(v128 + 1 + (this[2346] & 7)));
          this[2346] += v128 + 1;
          v82 = (int)((v129 + dword_5B4820[v128]) * dword_5B2CA4[64 * v128 + v162[22]]) >> 12;
        }
        v130 = v166[23];
        *((_WORD *)v80 + 21) = v82;
        LOWORD(v82) = 0;
        if ( v130 )
        {
          v173 = *(_DWORD *)(((int)this[2346] >> 3) + this[2345]);
          v131 = dword_5B4788[v130 + 1] & (_byteswap_ulong(v173) >> -(char)(v130 + 1 + (this[2346] & 7)));
          this[2346] += v130 + 1;
          v82 = (int)((v131 + dword_5B4820[v130]) * dword_5B2CA4[64 * v130 + v162[23]]) >> 12;
        }
        v132 = v166[24];
        *((_WORD *)v80 + 22) = v82;
        LOWORD(v82) = 0;
        if ( v132 )
        {
          v173 = *(_DWORD *)(((int)this[2346] >> 3) + this[2345]);
          v133 = dword_5B4788[v132 + 1] & (_byteswap_ulong(v173) >> -(char)(v132 + 1 + (this[2346] & 7)));
          this[2346] += v132 + 1;
          v82 = (int)((v133 + dword_5B4820[v132]) * dword_5B2CA4[64 * v132 + v162[24]]) >> 12;
        }
        v134 = v166[25];
        *((_WORD *)v80 + 23) = v82;
        LOWORD(v82) = 0;
        if ( v134 )
        {
          v173 = *(_DWORD *)(((int)this[2346] >> 3) + this[2345]);
          v135 = dword_5B4788[v134 + 1] & (_byteswap_ulong(v173) >> -(char)(v134 + 1 + (this[2346] & 7)));
          this[2346] += v134 + 1;
          v82 = (int)((v135 + dword_5B4820[v134]) * dword_5B2CA4[64 * v134 + v162[25]]) >> 12;
        }
        v136 = v166[26];
        *((_WORD *)v80 + 24) = v82;
        LOWORD(v82) = 0;
        if ( v136 )
        {
          v173 = *(_DWORD *)(((int)this[2346] >> 3) + this[2345]);
          v137 = dword_5B4788[v136 + 1] & (_byteswap_ulong(v173) >> -(char)(v136 + 1 + (this[2346] & 7)));
          this[2346] += v136 + 1;
          v82 = (int)((v137 + dword_5B4820[v136]) * dword_5B2CA4[64 * v136 + v162[26]]) >> 12;
        }
        v138 = v169;
        *((_WORD *)v80 + 25) = v82;
        LOWORD(v82) = 0;
        if ( v138 )
        {
          v139 = v138 + 1;
          v173 = *(_DWORD *)(((int)this[2346] >> 3) + this[2345]);
          v140 = _byteswap_ulong(v173) >> -(char)(v138 + 1 + (this[2346] & 7));
          v141 = dword_5B4788[v138 + 1];
          v142 = v162[27];
          this[2346] += v139;
          v82 = (int)(((v141 & v140) + dword_5B4820[v169]) * dword_5B2CA4[64 * v169 + v142]) >> 12;
        }
        v143 = v167;
        *((_WORD *)v80 + 26) = v82;
        LOWORD(v82) = 0;
        if ( v143 )
        {
          v144 = (int)v143 + 1;
          v173 = *(_DWORD *)(((int)this[2346] >> 3) + this[2345]);
          v145 = _byteswap_ulong(v173) >> -(char)((_BYTE)v143 + 1 + (this[2346] & 7));
          v146 = dword_5B4788[(_DWORD)v143 + 1];
          this[2346] += v144;
          v82 = (int)(((v146 & v145) + dword_5B4820[(_DWORD)v167]) * dword_5B2CA4[64 * (_DWORD)v167 + v162[28]]) >> 12;
        }
        v147 = v170;
        *((_WORD *)v80 + 27) = v82;
        LOWORD(v82) = 0;
        if ( v147 )
        {
          v148 = v147 + 1;
          v173 = *(_DWORD *)(((int)this[2346] >> 3) + this[2345]);
          v149 = _byteswap_ulong(v173) >> -(char)(v147 + 1 + (this[2346] & 7));
          v150 = dword_5B4788[v147 + 1];
          this[2346] += v148;
          v82 = (int)(((v150 & v149) + dword_5B4820[v170]) * dword_5B2CA4[64 * v170 + v162[29]]) >> 12;
        }
        v151 = v171;
        *((_WORD *)v80 + 28) = v82;
        LOWORD(v82) = 0;
        if ( v151 )
        {
          v152 = v151 + 1;
          v173 = *(_DWORD *)(((int)this[2346] >> 3) + this[2345]);
          v153 = _byteswap_ulong(v173) >> -(char)(v151 + 1 + (this[2346] & 7));
          v154 = dword_5B4788[v151 + 1];
          this[2346] += v152;
          v82 = (int)(((v154 & v153) + dword_5B4820[v171]) * dword_5B2CA4[64 * v171 + v162[30]]) >> 12;
        }
        *((_WORD *)v80 + 29) = v82;
        v80 += 64;
        --v172;
      }
      while ( v172 );
      v155 = a2;
      v156 = &v158;
      v172 = 12;
      do
      {
        sub_532AA0(v155, v156);
        v156 += 64;
        v58 = v172 == 1;
        v155 += 2 * this[2356];
        --v172;
      }
      while ( !v58 );
    }
    _m_empty();
    return 0;
  }
  else
  {
    v5 = &unk_8B0324;
    v6 = dword_8B0124;
    if ( this[2355] == 2 )
    {
      v171 = 32;
      do
      {
        v172 = *(_DWORD *)(((int)this[2346] >> 3) + this[2345]);
        v5 += 2;
        v7 = (unsigned __int8)(_byteswap_ulong(v172) >> (-8 - (this[2346] & 7)));
        this[2346] += 8;
        *(v5 - 2) = v7 >> 4;
        *(v5 - 1) = v7 & 0xF;
        --v171;
      }
      while ( v171 );
      v8 = (int *)&unk_8B0324;
      v171 = 32;
      do
      {
        v9 = *v8;
        v10 = v8 + 1;
        v170 = (int)v10;
        if ( v9 )
        {
          v172 = *(_DWORD *)(((int)this[2346] >> 3) + this[2345]);
          v11 = _byteswap_ulong(v172);
          v12 = this[2346] & 7;
          this[2346] += 6;
          *v6 = (v11 >> (-6 - v12)) & 0x3F;
          v10 = (int *)v170;
          ++v6;
        }
        v13 = *v10;
        v8 = v10 + 1;
        v170 = (int)v8;
        if ( v13 )
        {
          v172 = *(_DWORD *)(((int)this[2346] >> 3) + this[2345]);
          v14 = _byteswap_ulong(v172);
          v15 = this[2346] & 7;
          this[2346] += 6;
          *v6 = (v14 >> (-6 - v15)) & 0x3F;
          v8 = (int *)v170;
          ++v6;
        }
        --v171;
      }
      while ( v171 );
    }
    else
    {
      v171 = 32;
      do
      {
        v172 = *(_DWORD *)(((int)this[2346] >> 3) + this[2345]);
        ++v5;
        v16 = _byteswap_ulong(v172) >> (-4 - (this[2346] & 7));
        this[2346] += 4;
        *(v5 - 1) = v16 & 0xF;
        --v171;
      }
      while ( v171 );
      v17 = (int *)&unk_8B0324;
      v171 = 32;
      do
      {
        v18 = *v17++;
        v170 = (int)v17;
        if ( v18 )
        {
          v172 = *(_DWORD *)(((int)this[2346] >> 3) + this[2345]);
          v19 = _byteswap_ulong(v172);
          v20 = this[2346] & 7;
          this[2346] += 6;
          *v6 = (v19 >> (-6 - v20)) & 0x3F;
          v17 = (int *)v170;
          ++v6;
        }
        --v171;
      }
      while ( v171 );
    }
    v172 = 12;
    do
    {
      v21 = this[2355];
      v22 = dword_8B0124;
      v171 = (int)dword_8B0124;
      if ( v21 == 2 )
      {
        v169 = (int)&v161;
        v167 = v160;
        v23 = (int *)&unk_8B0324;
        v24 = dword_8B0224;
        v168 = 32;
        do
        {
          v25 = *v23;
          v26 = v23 + 1;
          v170 = (int)v26;
          if ( v25 )
          {
            v27 = v25 + 1;
            v173 = *(_DWORD *)(((int)this[2346] >> 3) + this[2345]);
            v28 = _byteswap_ulong(v173) >> -(char)(v27 + (this[2346] & 7));
            v29 = dword_5B4788[v27];
            v22 = (int *)v171;
            this[2346] += v27;
            *v24 = v29 & v28;
            v26 = (int *)v170;
            ++v24;
          }
          v30 = *v26;
          v23 = v26 + 1;
          v170 = (int)v23;
          if ( v30 )
          {
            v31 = v30 + 1;
            v173 = *(_DWORD *)(((int)this[2346] >> 3) + this[2345]);
            v32 = _byteswap_ulong(v173) >> -(char)(v31 + (this[2346] & 7));
            v33 = dword_5B4788[v31];
            v22 = (int *)v171;
            this[2346] += v31;
            *v24 = v33 & v32;
            v23 = (int *)v170;
            ++v24;
          }
          --v168;
        }
        while ( v168 );
        v34 = (int *)&unk_8B0324;
        v35 = dword_8B0224;
        v168 = 32;
        do
        {
          v36 = *v34;
          v37 = v34 + 1;
          v170 = (int)v37;
          if ( v36 )
          {
            ++v22;
            v38 = *v35 - (1 << v36) + 1;
            v39 = *(v22 - 1) + (v36 << 6);
            v173 = v38;
            v37 = (int *)v170;
            v40 = (double)v38 * flt_5B11A4[v39];
            ++v35;
            *((float *)++v167 - 1) = v40;
          }
          else
          {
            v41 = v167;
            *v167 = 0;
            v167 = v41 + 1;
          }
          v42 = *v37;
          v34 = v37 + 1;
          v170 = (int)v34;
          if ( v42 )
          {
            ++v22;
            v43 = *v35 - (1 << v42) + 1;
            v44 = *(v22 - 1) + (v42 << 6);
            v173 = v43;
            v34 = (int *)v170;
            v45 = (double)v43 * flt_5B11A4[v44];
            ++v35;
            v169 += 4;
            *(float *)(v169 - 4) = v45;
          }
          else
          {
            v46 = v169;
            *(_DWORD *)v169 = 0;
            v169 = v46 + 4;
          }
          --v168;
        }
        while ( v168 );
      }
      else
      {
        v47 = dword_8B0224;
        v169 = (int)v160;
        v48 = (int *)&unk_8B0324;
        v168 = 32;
        do
        {
          v49 = *v48++;
          v170 = (int)v48;
          if ( v49 )
          {
            v50 = v49 + 1;
            v173 = *(_DWORD *)(((int)this[2346] >> 3) + this[2345]);
            v51 = _byteswap_ulong(v173) >> -(char)(v50 + (this[2346] & 7));
            v52 = dword_5B4788[v50];
            this[2346] += v50;
            *v47 = v52 & v51;
            v48 = (int *)v170;
            ++v47;
          }
          --v168;
        }
        while ( v168 );
        v53 = (int *)&unk_8B0324;
        v54 = 0;
        v168 = 32;
        do
        {
          v55 = *v53++;
          if ( v55 )
          {
            v56 = (v55 << 6) + dword_8B0124[v54];
            v173 = dword_8B0224[v54++] - (1 << v55) + 1;
            v169 += 4;
            *(float *)(v169 - 4) = (double)v173 * flt_5B11A4[v56];
          }
          else
          {
            v57 = v169;
            *(_DWORD *)v169 = 0;
            v169 = v57 + 4;
          }
          --v168;
        }
        while ( v168 );
      }
      sub_531830(a2, v160);
      v58 = v172 == 1;
      a2 += 2 * this[2356];
      --v172;
    }
    while ( !v58 );
    return 0;
  }
}
