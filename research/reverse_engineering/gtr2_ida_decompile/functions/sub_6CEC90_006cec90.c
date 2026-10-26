int __stdcall sub_6CEC90(_DWORD *a1, int a2)
{
  int v2; // ecx
  int v3; // eax
  int v4; // eax
  _DWORD *v5; // ebx
  unsigned int v6; // esi
  unsigned int v7; // ecx
  int v8; // eax
  _DWORD *v10; // esi
  unsigned __int16 *v11; // eax
  int v12; // edx
  int v13; // ecx
  int v14; // edx
  int v15; // ecx
  int v16; // edx
  int v17; // eax
  void (__stdcall *v18)(_DWORD *, _DWORD *, _BYTE *, int, int); // ecx
  __int16 *v19; // eax
  __int16 *v20; // ecx
  int v21; // esi
  int v22; // edi
  int v23; // edx
  int v24; // ecx
  int v25; // edx
  int v26; // ebx
  int v27; // eax
  int v28; // eax
  int v29; // eax
  int v30; // ecx
  int v31; // edx
  int v32; // ebx
  int v33; // eax
  int v34; // eax
  int v35; // eax
  int v36; // ecx
  int v37; // edx
  int v38; // ebx
  int v39; // eax
  int v40; // eax
  int v41; // eax
  int v42; // ecx
  int v43; // edx
  int v44; // edi
  int v45; // eax
  int v46; // eax
  int v47; // eax
  int v48; // ecx
  int v49; // edx
  int v50; // edi
  int v51; // eax
  int v52; // eax
  int v53; // eax
  int v54; // edx
  bool v55; // cc
  unsigned int v56; // edx
  unsigned int v57; // esi
  int v58; // [esp-Ch] [ebp-120h]
  _BYTE v59[2]; // [esp+Ch] [ebp-108h] BYREF
  __int16 v60; // [esp+Eh] [ebp-106h]
  __int16 v61; // [esp+10h] [ebp-104h]
  __int16 v62; // [esp+1Ch] [ebp-F8h]
  __int16 v63; // [esp+1Eh] [ebp-F6h]
  __int16 v64; // [esp+2Ch] [ebp-E8h]
  int v65; // [esp+8Ch] [ebp-88h]
  void (__stdcall *v66)(_DWORD *, _DWORD *, _BYTE *, int, int); // [esp+90h] [ebp-84h]
  unsigned int v67; // [esp+94h] [ebp-80h]
  int v68; // [esp+98h] [ebp-7Ch]
  int v69; // [esp+9Ch] [ebp-78h]
  int v70; // [esp+A0h] [ebp-74h]
  int v71; // [esp+A4h] [ebp-70h]
  unsigned int v72; // [esp+A8h] [ebp-6Ch]
  int v73; // [esp+ACh] [ebp-68h]
  int v74; // [esp+B0h] [ebp-64h]
  int v75; // [esp+B4h] [ebp-60h]
  int v76; // [esp+B8h] [ebp-5Ch]
  int v77; // [esp+BCh] [ebp-58h]
  int v78; // [esp+C0h] [ebp-54h]
  int v79; // [esp+C4h] [ebp-50h]
  int v80; // [esp+C8h] [ebp-4Ch]
  int v81; // [esp+CCh] [ebp-48h]
  __int16 *v82; // [esp+D0h] [ebp-44h]
  int v83; // [esp+D4h] [ebp-40h]
  __int16 *v84; // [esp+D8h] [ebp-3Ch]
  int v85; // [esp+DCh] [ebp-38h]
  int v86; // [esp+E0h] [ebp-34h]
  unsigned int v87; // [esp+E4h] [ebp-30h]
  int v88; // [esp+E8h] [ebp-2Ch]
  _DWORD *v89; // [esp+ECh] [ebp-28h]
  int v90; // [esp+F0h] [ebp-24h]
  _DWORD *v91; // [esp+F4h] [ebp-20h]
  int v92; // [esp+F8h] [ebp-1Ch]
  int v93; // [esp+FCh] [ebp-18h]
  int v94; // [esp+100h] [ebp-14h]
  __int16 *v95; // [esp+104h] [ebp-10h]
  int v96; // [esp+108h] [ebp-Ch]
  _DWORD *v97; // [esp+10Ch] [ebp-8h]
  int v98; // [esp+110h] [ebp-4h]

  v2 = a1[37];
  v75 = a1[108];
  v67 = a1[81] - 1;
  if ( v2 <= a1[39] )
  {
    do
    {
      v3 = a1[110];
      if ( *(_DWORD *)(v3 + 20)
        || a1[37] == a1[39] && __PAIR64__(a1[38], a1[101]) >= __PAIR64__(a1[40], 1) && a1[38] != a1[40] + (a1[101] == 0) )
      {
        break;
      }
      if ( !(*(int (__stdcall **)(_DWORD *))v3)(a1) )
        return 0;
    }
    while ( a1[37] <= a1[39] );
  }
  v4 = a1[9];
  v5 = (_DWORD *)a1[55];
  v81 = 0;
  v89 = v5;
  if ( v4 > 0 )
  {
    v91 = (_DWORD *)(v75 + 72);
    v79 = 0;
    v65 = -72 - v75;
    do
    {
      if ( v5[12] )
      {
        v6 = a1[40];
        v7 = v5[3];
        if ( v6 >= v67 )
        {
          v98 = v5[8] % v7;
          if ( !v98 )
            v98 = v7;
          v8 = v98;
          v69 = 1;
        }
        else
        {
          v98 = v5[3];
          v8 = 2 * v7;
          v69 = 0;
        }
        if ( v6 )
        {
          v58 = v7 * (v6 - 1);
          v10 = v91;
          v68 = (*(int (__stdcall **)(_DWORD *, _DWORD, int, unsigned int, _DWORD))(a1[1] + 32))(
                  a1,
                  *v91,
                  v58,
                  v7 + v8,
                  0)
              + 4 * v5[3];
          v78 = 0;
        }
        else
        {
          v10 = v91;
          v68 = (*(int (__stdcall **)(_DWORD *, _DWORD, _DWORD, int, _DWORD))(a1[1] + 32))(a1, *v91, 0, v8, 0);
          v78 = 1;
        }
        v97 = (_DWORD *)(v79 + *(_DWORD *)(v75 + 112));
        v11 = (unsigned __int16 *)v5[19];
        v12 = v11[1];
        v96 = *v11;
        v13 = v11[8];
        v73 = v12;
        v14 = v11[16];
        v70 = v13;
        v15 = v11[9];
        v71 = v14;
        v16 = v11[2];
        v17 = a1[113];
        v77 = v15;
        v18 = *(void (__stdcall **)(_DWORD *, _DWORD *, _BYTE *, int, int))((char *)v10 + v65 + v17 + 4);
        v76 = v16;
        v66 = v18;
        v85 = *(_DWORD *)(a2 + 4 * v81);
        v88 = 0;
        if ( v98 > 0 )
        {
          do
          {
            v19 = *(__int16 **)(v68 + 4 * v88);
            v95 = v19;
            if ( !v78 || (v20 = v19, v88) )
              v20 = *(__int16 **)(v68 + 4 * v88 - 4);
            if ( !v69 || v88 != v98 - 1 )
              v19 = *(__int16 **)(v68 + 4 * v88 + 4);
            v21 = *v95;
            v22 = *v20;
            v90 = *v19;
            v93 = v90;
            v74 = v90;
            v23 = v5[7] - 1;
            v83 = v22;
            v94 = v22;
            v92 = v21;
            v86 = v21;
            v80 = 0;
            v72 = v23;
            v87 = 0;
            v84 = v19 + 64;
            v82 = v20 + 64;
            do
            {
              sub_6B6040(v95, v59, 1);
              if ( v87 < v72 )
              {
                v21 = v95[64];
                v83 = *v82;
                v90 = *v84;
              }
              v24 = v97[1];
              if ( v24 && !v60 )
              {
                v25 = 36 * v96 * (v86 - v21);
                v26 = v73 << 8;
                v27 = v73 << 7;
                if ( v25 < 0 )
                {
                  v29 = (v27 - v25) / v26;
                  if ( v24 > 0 && v29 >= 1 << v24 )
                    v29 = (1 << v24) - 1;
                  v28 = -v29;
                }
                else
                {
                  v28 = (v25 + v27) / v26;
                  if ( v24 > 0 && v28 >= 1 << v24 )
                    v28 = (1 << v24) - 1;
                }
                v5 = v89;
                v60 = v28;
              }
              v30 = v97[2];
              if ( v30 && !v62 )
              {
                v31 = 36 * v96 * (v94 - v93);
                v32 = v70 << 8;
                v33 = v70 << 7;
                if ( v31 < 0 )
                {
                  v35 = (v33 - v31) / v32;
                  if ( v30 > 0 && v35 >= 1 << v30 )
                    v35 = (1 << v30) - 1;
                  v34 = -v35;
                }
                else
                {
                  v34 = (v31 + v33) / v32;
                  if ( v30 > 0 && v34 >= 1 << v30 )
                    v34 = (1 << v30) - 1;
                }
                v5 = v89;
                v62 = v34;
              }
              v36 = v97[3];
              if ( v36 && !v64 )
              {
                v37 = 9 * v96 * (v94 + v93 - 2 * v92);
                v38 = v71 << 8;
                v39 = v71 << 7;
                if ( v37 < 0 )
                {
                  v41 = (v39 - v37) / v38;
                  if ( v36 > 0 && v41 >= 1 << v36 )
                    v41 = (1 << v36) - 1;
                  v40 = -v41;
                }
                else
                {
                  v40 = (v37 + v39) / v38;
                  if ( v36 > 0 && v40 >= 1 << v36 )
                    v40 = (1 << v36) - 1;
                }
                v5 = v89;
                v64 = v40;
              }
              v42 = v97[4];
              if ( v42 && !v63 )
              {
                v43 = 5 * v96 * (v22 + v90 - v74 - v83);
                v44 = v77 << 8;
                v45 = v77 << 7;
                if ( v43 < 0 )
                {
                  v47 = (v45 - v43) / v44;
                  if ( v42 > 0 && v47 >= 1 << v42 )
                    v47 = (1 << v42) - 1;
                  v46 = -v47;
                }
                else
                {
                  v46 = (v43 + v45) / v44;
                  if ( v42 > 0 && v46 >= 1 << v42 )
                    v46 = (1 << v42) - 1;
                }
                v63 = v46;
              }
              v48 = v97[5];
              if ( v48 && !v61 )
              {
                v49 = 9 * v96 * (v86 + v21 - 2 * v92);
                v50 = v76 << 8;
                v51 = v76 << 7;
                if ( v49 < 0 )
                {
                  v53 = (v51 - v49) / v50;
                  if ( v48 > 0 && v53 >= 1 << v48 )
                    v53 = (1 << v48) - 1;
                  v52 = -v53;
                }
                else
                {
                  v52 = (v49 + v51) / v50;
                  if ( v48 > 0 && v52 >= 1 << v48 )
                    v52 = (1 << v48) - 1;
                }
                v61 = v52;
              }
              v66(a1, v5, v59, v85, v80);
              v22 = v94;
              v94 = v83;
              v74 = v93;
              v93 = v90;
              v86 = v92;
              v95 += 64;
              v82 += 64;
              v54 = v5[9];
              v80 += v54;
              v84 += 64;
              v55 = v87 + 1 <= v72;
              v92 = v21;
              ++v87;
            }
            while ( v55 );
            v55 = v88 + 1 < v98;
            v85 += 4 * v54;
            ++v88;
          }
          while ( v55 );
        }
      }
      v79 += 24;
      v5 += 21;
      v55 = ++v81 < a1[9];
      ++v91;
      v89 = v5;
    }
    while ( v55 );
  }
  v56 = a1[81];
  v57 = a1[40] + 1;
  a1[40] = v57;
  return 4 - (v57 < v56);
}
