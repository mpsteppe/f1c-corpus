int __thiscall sub_690096(_DWORD *this)
{
  _DWORD *v1; // esi
  _DWORD *v2; // ebx
  int v3; // eax
  unsigned int v4; // ecx
  int v5; // ecx
  int v6; // eax
  int v7; // eax
  int v8; // edx
  int v9; // edx
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // edx
  int v14; // esi
  int v15; // edx
  int v16; // edx
  int v17; // edx
  int v18; // esi
  int v19; // edx
  int v20; // edx
  int v21; // edx
  int v22; // esi
  int v23; // edx
  int v24; // edx
  int v25; // eax
  int v26; // edx
  int v27; // eax
  int v28; // eax
  int v29; // edx
  int v30; // esi
  int v31; // edx
  int v32; // edx
  int v33; // edx
  int v34; // esi
  int v35; // edx
  int v36; // edx
  int v37; // edx
  int v38; // eax
  int v39; // eax
  int v40; // eax
  int v41; // edx
  int v42; // esi
  int v43; // edx
  int v44; // edx
  int v45; // edx
  int v46; // esi
  int v47; // edx
  int v48; // edx
  int v49; // edx
  int v50; // edx
  int v51; // edx
  int v52; // esi
  int v53; // eax
  int v54; // eax
  int v55; // edi
  int v56; // eax
  int v57; // edx
  int v58; // ecx
  unsigned int v59; // esi
  int v60; // ecx
  int v61; // eax
  int v62; // ebx
  int v63; // ecx
  unsigned int v64; // edi
  int v65; // edx
  int v67; // [esp+8h] [ebp-40h]
  BOOL v68; // [esp+Ch] [ebp-3Ch]
  int v69; // [esp+10h] [ebp-38h]
  int v70; // [esp+14h] [ebp-34h]
  int v71; // [esp+14h] [ebp-34h]
  int v72; // [esp+14h] [ebp-34h]
  int v73; // [esp+14h] [ebp-34h]
  unsigned int v74; // [esp+14h] [ebp-34h]
  unsigned int v75; // [esp+18h] [ebp-30h]
  _DWORD *v77; // [esp+20h] [ebp-28h]
  int v78; // [esp+24h] [ebp-24h]
  int v79; // [esp+28h] [ebp-20h]
  int v80; // [esp+28h] [ebp-20h]
  int v81; // [esp+2Ch] [ebp-1Ch]
  int v82; // [esp+2Ch] [ebp-1Ch]
  unsigned int v83; // [esp+30h] [ebp-18h]
  unsigned int v84; // [esp+34h] [ebp-14h]
  unsigned int v85; // [esp+38h] [ebp-10h]
  int v86; // [esp+3Ch] [ebp-Ch]
  unsigned int v87; // [esp+40h] [ebp-8h]
  unsigned int v88; // [esp+40h] [ebp-8h]
  unsigned int v89; // [esp+44h] [ebp-4h]

  v1 = this;
  v69 = 0;
  sub_686606(this);
  v75 = 0;
  if ( !v1[3] )
    return 1;
  do
  {
    v2 = *(_DWORD **)(v1[6] + 4 * v75);
    v3 = *v2;
    v4 = *v2 & 0xF0000000;
    v77 = v2;
    if ( v4 < 0x10000000 )
      goto LABEL_120;
    if ( v4 > 0x40000000 )
      goto LABEL_120;
    v85 = v3 & 0xFFFFF;
    v84 = v2[1] / (v3 & 0xFFFFFu);
    v68 = sub_680DDB(v2);
    v83 = v85;
    v87 = 1;
    if ( v85 <= 1 )
      goto LABEL_120;
    v78 = 4 * v85;
    v86 = 4;
    v79 = 4 * v85 + 4;
    do
    {
      v5 = v1[5];
      v67 = *(_DWORD *)(v2[4] + v86);
      if ( (*(_WORD *)(*(_DWORD *)(v1[4] + 4 * *(_DWORD *)(*(_DWORD *)(v5 + 4 * v67) + 4)) + 4) & 0x1020) == 0 )
      {
        v89 = 0;
        if ( v86 )
        {
          v81 = 4 * v85;
          do
          {
            v6 = *(_DWORD *)(v2[4] + 4 * v89);
            if ( v6 == -1
              || (*(_WORD *)(*(_DWORD *)(v1[4] + 4 * *(_DWORD *)(*(_DWORD *)(v5 + 4 * v6) + 4)) + 4) & 0x1020) != 0 )
            {
              goto LABEL_100;
            }
            if ( v84 == 1 )
            {
              v7 = v2[2];
              v8 = *(_DWORD *)(v7 + v86);
              v9 = v8 == -1 ? -1 : *(_DWORD *)(*(_DWORD *)(v5 + 4 * v8) + 48);
              v10 = *(_DWORD *)(v7 + 4 * v89);
              v11 = v10 == -1 ? -1 : *(_DWORD *)(*(_DWORD *)(v5 + 4 * v10) + 48);
              if ( v9 == v11 )
              {
LABEL_102:
                v1 = this;
                sub_688FBF(this, *(_DWORD *)(v2[4] + 4 * v89), v67);
                --v83;
                *(_DWORD *)(v86 + v2[4]) = -1;
                break;
              }
            }
            if ( v84 == 2 )
            {
              v12 = v2[2];
              v13 = *(_DWORD *)(v12 + v86);
              if ( v13 == -1 )
                v14 = -1;
              else
                v14 = *(_DWORD *)(*(_DWORD *)(v5 + 4 * v13) + 48);
              v15 = *(_DWORD *)(v12 + 4 * v89);
              v70 = v15;
              if ( v15 == -1 )
                v16 = -1;
              else
                v16 = *(_DWORD *)(*(_DWORD *)(v5 + 4 * v15) + 48);
              if ( v14 == v16 )
              {
                v17 = *(_DWORD *)(v12 + v79);
                v18 = v17 == -1 ? -1 : *(_DWORD *)(*(_DWORD *)(v5 + 4 * v17) + 48);
                v19 = *(_DWORD *)(v12 + v81);
                v20 = v19 == -1 ? -1 : *(_DWORD *)(*(_DWORD *)(v5 + 4 * v19) + 48);
                if ( v18 == v20 )
                  goto LABEL_102;
              }
              if ( !v68 )
                goto LABEL_100;
              v21 = *(_DWORD *)(v12 + v86);
              v22 = v21 == -1 ? -1 : *(_DWORD *)(*(_DWORD *)(v5 + 4 * v21) + 48);
              v23 = *(_DWORD *)(v12 + v81);
              v24 = v23 == -1 ? -1 : *(_DWORD *)(*(_DWORD *)(v5 + 4 * v23) + 48);
              if ( v22 != v24 )
                goto LABEL_100;
              v25 = *(_DWORD *)(v12 + v79);
              if ( v25 == -1 )
                v26 = -1;
              else
                v26 = *(_DWORD *)(*(_DWORD *)(v5 + 4 * v25) + 48);
              if ( v70 == -1 )
                v27 = -1;
              else
                v27 = *(_DWORD *)(*(_DWORD *)(v5 + 4 * v70) + 48);
              if ( v26 == v27 )
                goto LABEL_102;
            }
            if ( v84 == 3 )
            {
              v28 = v2[2];
              v29 = *(_DWORD *)(v28 + v86);
              if ( v29 == -1 )
                v30 = -1;
              else
                v30 = *(_DWORD *)(*(_DWORD *)(v5 + 4 * v29) + 48);
              v31 = *(_DWORD *)(v28 + 4 * v89);
              if ( v31 == -1 )
                v32 = -1;
              else
                v32 = *(_DWORD *)(*(_DWORD *)(v5 + 4 * v31) + 48);
              if ( v30 != v32 )
                goto LABEL_100;
              v33 = *(_DWORD *)(v28 + v79);
              v34 = v33 == -1 ? -1 : *(_DWORD *)(*(_DWORD *)(v5 + 4 * v33) + 48);
              v35 = *(_DWORD *)(v28 + v81);
              v36 = v35 == -1 ? -1 : *(_DWORD *)(*(_DWORD *)(v5 + 4 * v35) + 48);
              if ( v34 != v36 )
                goto LABEL_100;
              v37 = *(_DWORD *)(v28 + 4 * (2 * v85 + v87));
              if ( v37 == -1 )
                v71 = -1;
              else
                v71 = *(_DWORD *)(*(_DWORD *)(v5 + 4 * v37) + 48);
              v38 = *(_DWORD *)(v28 + 4 * (v89 + 2 * v85));
              if ( v38 == -1 )
                v39 = -1;
              else
                v39 = *(_DWORD *)(*(_DWORD *)(v5 + 4 * v38) + 48);
              if ( v71 == v39 )
                goto LABEL_102;
            }
            if ( v84 == 4 )
            {
              v40 = v2[2];
              v41 = *(_DWORD *)(v40 + v86);
              v42 = v41 == -1 ? -1 : *(_DWORD *)(*(_DWORD *)(v5 + 4 * v41) + 48);
              v43 = *(_DWORD *)(v40 + 4 * v89);
              v44 = v43 == -1 ? -1 : *(_DWORD *)(*(_DWORD *)(v5 + 4 * v43) + 48);
              if ( v42 == v44 )
              {
                v45 = *(_DWORD *)(v40 + v79);
                v46 = v45 == -1 ? -1 : *(_DWORD *)(*(_DWORD *)(v5 + 4 * v45) + 48);
                v47 = *(_DWORD *)(v40 + v81);
                v48 = v47 == -1 ? -1 : *(_DWORD *)(*(_DWORD *)(v5 + 4 * v47) + 48);
                if ( v46 == v48 )
                {
                  v49 = *(_DWORD *)(v40 + 4 * (2 * v85 + v87));
                  v72 = v49 == -1 ? -1 : *(_DWORD *)(*(_DWORD *)(v5 + 4 * v49) + 48);
                  v50 = *(_DWORD *)(v40 + 4 * (v89 + 2 * v85));
                  v51 = v50 == -1 ? -1 : *(_DWORD *)(*(_DWORD *)(v5 + 4 * v50) + 48);
                  if ( v72 == v51 )
                  {
                    v52 = *(_DWORD *)(v40 + 4 * (3 * v85 + v87));
                    v73 = v52 == -1 ? -1 : *(_DWORD *)(*(_DWORD *)(v5 + 4 * v52) + 48);
                    v53 = *(_DWORD *)(v40 + 4 * (v89 + 3 * v85));
                    v54 = v53 == -1 ? -1 : *(_DWORD *)(*(_DWORD *)(v5 + 4 * v53) + 48);
                    if ( v73 == v54 )
                      goto LABEL_102;
                  }
                }
              }
            }
LABEL_100:
            ++v89;
            v81 += 4;
            v1 = this;
          }
          while ( v89 < v87 );
        }
      }
      ++v87;
      v79 += 4;
      v86 += 4;
    }
    while ( v87 < v85 );
    if ( v83 < v85 )
    {
      v88 = 0;
      if ( v85 )
      {
        v55 = 0;
        do
        {
          v56 = v2[4];
          v57 = 4 * v88;
          v58 = *(_DWORD *)(v56 + 4 * v88);
          if ( v58 != -1 )
          {
            *(_DWORD *)(v56 + v55) = v58;
            if ( v84 )
            {
              v59 = v84;
              v60 = v55;
              do
              {
                v61 = v2[2];
                v62 = *(_DWORD *)(v61 + v57);
                v57 += v78;
                *(_DWORD *)(v61 + v60) = v62;
                v60 += v78;
                --v59;
                v2 = v77;
              }
              while ( v59 );
            }
            v55 += 4;
          }
          ++v88;
        }
        while ( v88 < v85 );
      }
      if ( v84 > 1 )
      {
        v63 = 4 * v85;
        v82 = 4 * v85;
        v80 = 4 * v83;
        v64 = v84 - 1;
        do
        {
          if ( v83 )
          {
            v65 = v80;
            v74 = v83;
            do
            {
              *(_DWORD *)(v2[2] + v65) = *(_DWORD *)(v2[2] + v63);
              v2 = v77;
              v63 += 4;
              v65 += 4;
              --v74;
            }
            while ( v74 );
          }
          v63 = v78 + v82;
          v80 += 4 * v83;
          --v64;
          v82 += v78;
        }
        while ( v64 );
      }
      *v2 ^= (v83 ^ *v2) & 0xFFFFF;
      v2[1] = v84 * v83;
      v2[3] = v83;
      v69 = 1;
    }
LABEL_120:
    ++v75;
    v1 = this;
  }
  while ( v75 < this[3] );
  if ( !v69 )
    return 1;
  sub_68661F(this);
  return 0;
}
