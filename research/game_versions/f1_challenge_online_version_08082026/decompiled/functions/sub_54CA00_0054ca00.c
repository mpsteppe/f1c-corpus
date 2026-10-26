int __thiscall sub_54CA00(_DWORD *this)
{
  bool v2; // zf
  int v3; // eax
  int v4; // ebp
  int v5; // edx
  int v6; // edi
  _DWORD *v7; // esi
  int v8; // eax
  int v9; // ecx
  int v10; // edi
  int v11; // edx
  int v12; // ecx
  _DWORD *v13; // esi
  int *v14; // eax
  int v15; // edi
  int v16; // eax
  int v17; // edx
  int v18; // esi
  float *v19; // esi
  int v20; // edx
  float *v21; // ecx
  int v22; // eax
  int v23; // ecx
  int v24; // edx
  int v25; // eax
  int v26; // edi
  int v27; // ecx
  int v28; // eax
  double v29; // st7
  int v30; // edx
  int v31; // edi
  int v32; // ecx
  int v33; // eax
  double v34; // st7
  int v35; // edi
  int v36; // ecx
  int v37; // eax
  double v38; // st7
  int v39; // edi
  int v40; // ecx
  int v41; // eax
  double v42; // st7
  int v43; // edx
  _DWORD *v44; // eax
  int v45; // ecx
  int v46; // eax
  int v47; // esi
  float *v48; // esi
  int v49; // ecx
  int v50; // edi
  float *v51; // edx
  int v52; // edi
  int v53; // ecx
  int v54; // eax
  int v55; // edx
  int v56; // ecx
  int v57; // edi
  int v58; // ecx
  int v59; // eax
  double v60; // st7
  int v61; // edx
  int v62; // edi
  int v63; // ecx
  int v64; // eax
  double v65; // st7
  int v66; // edi
  int v67; // ecx
  int v68; // eax
  double v69; // st7
  int v70; // edi
  int v71; // ecx
  int v72; // eax
  double v73; // st7
  int v74; // edx
  void *v75; // edi
  int v76; // ecx
  int v78; // [esp+10h] [ebp-1Ch]
  int v79; // [esp+10h] [ebp-1Ch]
  int v80; // [esp+14h] [ebp-18h]
  int v81; // [esp+18h] [ebp-14h]
  int v82; // [esp+18h] [ebp-14h]
  int v83; // [esp+1Ch] [ebp-10h] BYREF
  int v84; // [esp+20h] [ebp-Ch]
  int v85; // [esp+24h] [ebp-8h]
  int v86; // [esp+28h] [ebp-4h]

  v2 = (this[5] & 0x8000000) == 0;
  v85 = 18;
  if ( !v2 )
    return 0;
  if ( (*(_BYTE *)(this[78] + 60) & 0x10) != 0 )
    v85 = 34;
  v3 = this[70];
  v4 = 0;
  v86 = 0;
  if ( v3 <= 0 )
  {
LABEL_74:
    this[5] |= 0x9000020u;
    return 0;
  }
  while ( 1 )
  {
    *(_DWORD *)(this[71] + v4 + 56) = v85;
    if ( sub_540940(dword_8B78A0, (_DWORD *)(v4 + this[71])) )
      return -1;
    sub_54E0E0(v4 + this[71], 12);
    v5 = this[71];
    if ( *(_DWORD *)(v5 + v4 + 32) )
    {
      v6 = *(_DWORD *)(v5 + v4 + 4);
      v7 = *(_DWORD **)(v5 + v4 + 32);
      v80 = v6;
      sub_5472D0((float *)v6, 2, &v83);
      v8 = this[5];
      v83 <<= 24;
      if ( ((unsigned int)&unk_800000 & v8) != 0 )
      {
        v9 = this[71];
        v10 = *(_DWORD *)(v9 + v4 + 8);
        v11 = *(_DWORD *)(v9 + v4 + 12);
        v12 = 0;
        if ( v10 > 0 )
        {
          v13 = v7 + 7;
          v14 = (int *)(v11 + 40);
          do
          {
            v15 = v83 | *v14;
            *v14 = v15;
            *(v13 - 1) = v15;
            *v13 = 0;
            v14 += 16;
            v13 += 16;
            ++v12;
          }
          while ( v12 < *(_DWORD *)(this[71] + v4 + 8) );
        }
        v16 = v80;
        v17 = *(_DWORD *)(v80 + 164);
        v18 = *(_DWORD *)(v80 + 168);
        v84 = v18;
        v81 = 0;
        v78 = 0;
        if ( v17 > 0 )
        {
          v19 = (float *)(v18 + 120);
          while ( 1 )
          {
            v20 = 0;
            if ( v78 > 0 )
            {
              v21 = (float *)(*(_DWORD *)(v16 + 168) + 120);
              while ( *(v19 - 2) == *(v21 - 2) && *(v19 - 1) == *(v21 - 1) && *v19 == *v21 )
              {
                ++v20;
                v21 += 37;
                if ( v20 >= v78 )
                  goto LABEL_22;
              }
              sub_54FC70(++v81);
            }
LABEL_22:
            v22 = this[71];
            v23 = *(_DWORD *)(v22 + v4 + 32);
            v24 = v22 + v4;
            v25 = *(_DWORD *)(v22 + v4 + 12);
            switch ( v81 )
            {
              case 0:
                v26 = 0;
                if ( *(int *)(v24 + 8) > 0 )
                {
                  v27 = v23 + 36;
                  v28 = v25 + 48;
                  do
                  {
                    v29 = *(float *)(v28 + 8);
                    v28 += 64;
                    v27 += 64;
                    ++v26;
                    *(float *)(v28 - 64) = v29 * *v19 + *(v19 - 2);
                    v30 = *(_DWORD *)(v28 - 64);
                    *(float *)(v28 - 60) = v19[1] * *(float *)(v28 - 52) + *(v19 - 1);
                    *(_DWORD *)(v27 - 68) = v30;
                    *(_DWORD *)(v27 - 64) = *(_DWORD *)(v28 - 60);
                  }
                  while ( v26 < *(_DWORD *)(this[71] + v4 + 8) );
                }
                break;
              case 1:
                v31 = 0;
                if ( *(int *)(v24 + 8) > 0 )
                {
                  v32 = v23 + 44;
                  v33 = v25 + 60;
                  do
                  {
                    v34 = *(float *)(v33 - 4);
                    v33 += 64;
                    v32 += 64;
                    ++v31;
                    *(float *)(v32 - 68) = v34 * *v19 + *(v19 - 2);
                    *(float *)(v32 - 64) = v19[1] * *(float *)(v33 - 64) + *(v19 - 1);
                  }
                  while ( v31 < *(_DWORD *)(this[71] + v4 + 8) );
                }
                break;
              case 2:
                v35 = 0;
                if ( *(int *)(v24 + 8) > 0 )
                {
                  v36 = v23 + 52;
                  v37 = v25 + 60;
                  do
                  {
                    v38 = *(float *)(v37 - 4);
                    v37 += 64;
                    v36 += 64;
                    ++v35;
                    *(float *)(v36 - 68) = v38 * *v19 + *(v19 - 2);
                    *(float *)(v36 - 64) = v19[1] * *(float *)(v37 - 64) + *(v19 - 1);
                  }
                  while ( v35 < *(_DWORD *)(this[71] + v4 + 8) );
                }
                break;
              case 3:
                v39 = 0;
                if ( *(int *)(v24 + 8) > 0 )
                {
                  v40 = v23 + 60;
                  v41 = v25 + 60;
                  do
                  {
                    v42 = *(float *)(v41 - 4);
                    v41 += 64;
                    v40 += 64;
                    ++v39;
                    *(float *)(v40 - 68) = v42 * *v19 + *(v19 - 2);
                    *(float *)(v40 - 64) = v19[1] * *(float *)(v41 - 64) + *(v19 - 1);
                  }
                  while ( v39 < *(_DWORD *)(this[71] + v4 + 8) );
                }
                break;
              default:
                break;
            }
            v84 += 148;
            v19 += 37;
            if ( ++v78 >= *(_DWORD *)(v80 + 164) )
              break;
            v16 = v80;
          }
        }
      }
      else
      {
        v43 = this[71];
        v44 = *(_DWORD **)(v43 + v4 + 12);
        v45 = 0;
        if ( *(int *)(v4 + v43 + 8) > 0 )
        {
          do
          {
            *v7 = *v44;
            v7[1] = v44[1];
            v7[2] = v44[2];
            v7[3] = v44[3];
            v7[4] = v44[4];
            v7[5] = v44[5];
            v44[6] |= v83;
            v7[6] = v44[6];
            v7[7] = 0;
            v44 += 12;
            v7 += 16;
            ++v45;
          }
          while ( v45 < *(_DWORD *)(this[71] + v4 + 8) );
        }
        v46 = *(_DWORD *)(v6 + 164);
        v47 = *(_DWORD *)(v6 + 168);
        v82 = v47;
        v84 = -1;
        v79 = 0;
        if ( v46 > 0 )
        {
          v48 = (float *)(v47 + 112);
          do
          {
            v49 = v79;
            v50 = 0;
            if ( v79 > 0 )
            {
              v51 = (float *)(*(_DWORD *)(v80 + 168) + 116);
              while ( *v48 != *(v51 - 1) || v48[1] != *v51 || v48[2] != v51[1] || v48[3] != v51[2] )
              {
                ++v50;
                v51 += 37;
                if ( v50 >= v79 )
                  goto LABEL_53;
              }
              sub_54FC70(v50);
              v49 = v79;
            }
LABEL_53:
            if ( v50 == v49 )
            {
              v52 = ++v84;
              sub_54FC70(v84);
              v53 = this[71];
              v54 = *(_DWORD *)(v53 + v4 + 12);
              v55 = v53 + v4;
              v56 = *(_DWORD *)(v53 + v4 + 32);
              switch ( v52 )
              {
                case 0:
                  v57 = 0;
                  if ( *(int *)(v55 + 8) > 0 )
                  {
                    v58 = v56 + 36;
                    v59 = v54 + 32;
                    do
                    {
                      v60 = *(float *)(v59 + 8);
                      v59 += 48;
                      v58 += 64;
                      ++v57;
                      *(float *)(v59 - 48) = v60 * v48[2] + *v48;
                      v61 = *(_DWORD *)(v59 - 48);
                      *(float *)(v59 - 44) = *(float *)(v59 - 36) * v48[3] + v48[1];
                      *(_DWORD *)(v58 - 68) = v61;
                      *(_DWORD *)(v58 - 64) = *(_DWORD *)(v59 - 44);
                    }
                    while ( v57 < *(_DWORD *)(this[71] + v4 + 8) );
                  }
                  break;
                case 1:
                  v62 = 0;
                  if ( *(int *)(v55 + 8) > 0 )
                  {
                    v63 = v56 + 44;
                    v64 = v54 + 44;
                    do
                    {
                      v65 = *(float *)(v64 - 4);
                      v64 += 48;
                      v63 += 64;
                      ++v62;
                      *(float *)(v63 - 68) = v65 * v48[2] + *v48;
                      *(float *)(v63 - 64) = v48[3] * *(float *)(v64 - 48) + v48[1];
                    }
                    while ( v62 < *(_DWORD *)(this[71] + v4 + 8) );
                  }
                  break;
                case 2:
                  v66 = 0;
                  if ( *(int *)(v55 + 8) > 0 )
                  {
                    v67 = v56 + 52;
                    v68 = v54 + 44;
                    do
                    {
                      v69 = *(float *)(v68 - 4);
                      v68 += 48;
                      v67 += 64;
                      ++v66;
                      *(float *)(v67 - 68) = v69 * v48[2] + *v48;
                      *(float *)(v67 - 64) = *(float *)(v68 - 48) * v48[3] + v48[1];
                    }
                    while ( v66 < *(_DWORD *)(this[71] + v4 + 8) );
                  }
                  break;
                case 3:
                  v70 = 0;
                  if ( *(int *)(v55 + 8) > 0 )
                  {
                    v71 = v56 + 60;
                    v72 = v54 + 44;
                    do
                    {
                      v73 = *(float *)(v72 - 4);
                      v72 += 48;
                      v71 += 64;
                      ++v70;
                      *(float *)(v71 - 68) = v73 * v48[2] + *v48;
                      *(float *)(v71 - 64) = v48[3] * *(float *)(v72 - 48) + v48[1];
                    }
                    while ( v70 < *(_DWORD *)(this[71] + v4 + 8) );
                  }
                  break;
                default:
                  break;
              }
            }
            v82 += 148;
            v48 += 37;
            ++v79;
          }
          while ( v79 < *(_DWORD *)(v80 + 164) );
        }
      }
    }
    v74 = this[71];
    v75 = *(void **)(v74 + v4 + 40);
    if ( v75 )
      qmemcpy(v75, *(const void **)(v74 + v4 + 20), 2 * *(_DWORD *)(v74 + v4 + 16));
    sub_55D720(*(_DWORD *)(dword_8B8F28 + 248), 0);
    sub_54E0F0(v4 + this[71], 12);
    *(_DWORD *)(this[71] + v4 + 56) |= 0x200u;
    v76 = this[70];
    v4 += 64;
    if ( ++v86 >= v76 )
      goto LABEL_74;
  }
}
