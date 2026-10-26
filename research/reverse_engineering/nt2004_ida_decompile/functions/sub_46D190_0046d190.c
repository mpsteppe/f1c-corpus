int *__thiscall sub_46D190(int **this, int a2, int a3)
{
  _DWORD *v4; // esi
  _DWORD *v5; // edi
  void *v6; // ebp
  int v7; // eax
  int v8; // ebp
  int *v9; // esi
  unsigned int v10; // eax
  _DWORD **v11; // ecx
  _DWORD *v12; // edi
  _DWORD *v13; // esi
  _DWORD *v14; // eax
  int v15; // ecx
  int v16; // ecx
  int v17; // eax
  _DWORD **v18; // eax
  int v19; // edx
  _DWORD *v20; // edi
  _DWORD *v21; // esi
  void *v22; // ebp
  int v23; // edi
  int *v24; // esi
  int v25; // ebp
  int *v26; // eax
  bool v27; // cc
  unsigned int v28; // edx
  float **v29; // ecx
  float *v30; // ecx
  float *v31; // esi
  int v32; // ecx
  int v33; // eax
  float **v34; // eax
  _DWORD *v35; // esi
  int v36; // eax
  int v37; // ecx
  int i; // edx
  int *v39; // ecx
  int v40; // eax
  int v41; // edx
  int v42; // ecx
  int v43; // eax
  int *v44; // eax
  int v45; // eax
  int *v46; // ecx
  bool v47; // zf
  int v48; // edi
  _DWORD *v49; // esi
  _DWORD *v50; // eax
  int v51; // ecx
  int v52; // eax
  int *v53; // eax
  _DWORD *v54; // eax
  int j; // ecx
  int v56; // eax
  _BYTE ***v57; // ecx
  _BYTE **v58; // ebp
  int v59; // ecx
  int v60; // eax
  _BYTE ***v61; // eax
  int v62; // eax
  int v63; // edi
  _DWORD *v64; // esi
  _DWORD *v65; // eax
  _DWORD *v66; // eax
  _DWORD *v67; // esi
  _DWORD *v68; // edi
  _DWORD *v69; // esi
  _DWORD *v70; // eax
  int v71; // ecx
  int v72; // eax
  _BYTE ***v73; // eax
  _DWORD **v74; // eax
  _DWORD *v75; // edi
  _DWORD *v76; // esi
  _DWORD *v77; // eax
  LPVOID *v78; // esi
  LPVOID *v79; // edi
  char v80; // al
  int *result; // eax
  float v82; // [esp+0h] [ebp-44h]
  int v83; // [esp+18h] [ebp-2Ch]
  float v84; // [esp+1Ch] [ebp-28h]
  int v85; // [esp+20h] [ebp-24h]
  _DWORD *v86; // [esp+20h] [ebp-24h]
  int v87; // [esp+24h] [ebp-20h]
  int v88; // [esp+24h] [ebp-20h]
  int v89; // [esp+24h] [ebp-20h]
  int v90; // [esp+28h] [ebp-1Ch]
  float v91; // [esp+2Ch] [ebp-18h]
  int v92; // [esp+30h] [ebp-14h]
  _DWORD *v93; // [esp+34h] [ebp-10h]
  _DWORD *v94; // [esp+34h] [ebp-10h]
  _DWORD *v95; // [esp+38h] [ebp-Ch]
  _DWORD *v96; // [esp+3Ch] [ebp-8h]
  int v97; // [esp+40h] [ebp-4h]

  v4 = *this + 3568;
  v5 = (_DWORD *)*v4;
  if ( *v4 )
  {
    do
    {
      v6 = v5;
      v5 = (_DWORD *)v5[1];
      sub_4A82F0(v6);
      sub_5BE8AE(v6);
    }
    while ( v5 );
  }
  *v4 = 0;
  v4[1] = 0;
  v4[2] = 0;
  v4[3] = 0;
  v7 = sub_46CC70(*this, a2);
  v8 = 71 * a2;
  v9 = *this;
  v87 = v7;
  v90 = v8 * 4;
  v91 = (float)v7;
  v10 = LOWORD(v9[71 * a2 + 104]) + (unsigned int)(__int64)(*((float *)v9 + 25) * *((float *)v9 + 24) * v91);
  LOWORD(v9[v8 + 104]) = 0;
  v83 = v10;
  v11 = (_DWORD **)(*this)[27];
  (*this)[29] = (int)v11;
  if ( v11 )
  {
    v12 = *v11;
    if ( *v11 )
    {
      do
      {
        if ( v12[51] != a3 )
        {
          v13 = *this + 3568;
          v14 = operator new(0xCu);
          if ( v14 )
          {
            *v14 = v12;
            v14[1] = 0;
            *((_BYTE *)v14 + 8) = 0;
          }
          else
          {
            v14 = 0;
          }
          if ( *v13 )
          {
            *(_DWORD *)(v13[1] + 4) = v14;
          }
          else
          {
            *v13 = v14;
            v13[2] = v14;
          }
          v15 = v13[3] + 1;
          v13[1] = v14;
          v13[3] = v15;
          v83 += -8 - ((*v12 >> 6) & 0x3FF);
        }
        v16 = (*this)[29];
        v17 = (int)(*this + 27);
        if ( v16 )
          (*this)[29] = *(_DWORD *)(v16 + 4);
        v18 = *(_DWORD ***)(v17 + 8);
        if ( !v18 )
          break;
        v12 = *v18;
      }
      while ( *v18 );
    }
  }
  switch ( sub_46CCB0(v87) )
  {
    case 1:
      v84 = 0.125;
      break;
    case 2:
      v84 = 0.083333336;
      break;
    case 3:
      v84 = 0.0625;
      break;
    case 4:
      v84 = 0.015625;
      break;
    default:
      v84 = 0.16666667;
      break;
  }
  v82 = dbl_7DA9C0;
  if ( sub_46C8D0((float *)(v19 + v8 * 4 + 140), v82, v84) && v83 > 0 )
  {
    sub_46C8F0((float *)&(*this)[v8 + 35], v84);
    v92 = v83 / 48;
    if ( v83 / 48 > 0 )
    {
      v20 = (_DWORD *)(*this)[3564];
      v21 = *this + 3564;
      while ( v20 )
      {
        v22 = v20;
        v20 = (_DWORD *)v20[1];
        sub_4A82F0(v22);
        sub_5BE8AE(v22);
      }
      *v21 = 0;
      v21[1] = 0;
      v21[2] = 0;
      v21[3] = 0;
      v85 = 0;
      v23 = 0;
      v88 = 3515;
      do
      {
        (*this)[v88] = -1;
        v24 = *this;
        if ( LOBYTE((*this)[v23 + 49]) )
        {
          if ( v85 != a2 )
          {
            if ( sub_46C7E0((int)&v24[v23 + 35]) )
            {
              v25 = v24[v23 + 105];
              if ( v25 )
              {
                v26 = (int *)operator new(0xCu);
                if ( v26 )
                {
                  *v26 = v25;
                  v26[1] = 0;
                  *((_BYTE *)v26 + 8) = 0;
                }
                else
                {
                  v26 = 0;
                }
                if ( v24[3564] )
                {
                  *(_DWORD *)(v24[3565] + 4) = v26;
                }
                else
                {
                  v24[3564] = (int)v26;
                  v24[3566] = (int)v26;
                }
                v24[3565] = (int)v26;
                ++v24[3567];
              }
            }
          }
        }
        v23 += 71;
        v27 = v88 * 4 + 4 < 14256;
        ++v85;
        ++v88;
      }
      while ( v27 );
      v28 = word_632224[12652 * a2];
      if ( v28 > 0x30 || dword_630030[6326 * v28] == -1 )
        v28 = a2;
      v29 = (float **)(*this)[3564];
      (*this)[3566] = (int)v29;
      if ( v29 )
      {
        v30 = *v29;
        if ( v30 )
        {
          v31 = (float *)((char *)&unk_62BF68 + 25304 * v28);
          do
          {
            sub_46C660(v30, v31);
            v32 = (*this)[3566];
            v33 = (int)(*this + 3564);
            if ( v32 )
              (*this)[3566] = *(_DWORD *)(v32 + 4);
            v34 = *(float ***)(v33 + 8);
            if ( !v34 )
              break;
            v30 = *v34;
          }
          while ( *v34 );
        }
      }
      v35 = *this + 3564;
      v36 = sub_46D9B0(*v35);
      v37 = v36;
      *v35 = v36;
      if ( v36 )
      {
        for ( i = *(_DWORD *)(v36 + 4); i; i = *(_DWORD *)(i + 4) )
          v37 = i;
      }
      v35[2] = v36;
      v35[1] = v37;
      v39 = (int *)(*this)[3564];
      (*this)[3566] = (int)v39;
      if ( v39 )
        v40 = *v39;
      else
        v40 = 0;
      if ( v40 )
      {
        v41 = 3515;
        do
        {
          (*this)[v41] = *(_DWORD *)(*(_DWORD *)v40 + 57) & 0x3F;
          v42 = (*this)[3566];
          v43 = (int)(*this + 3564);
          ++v41;
          if ( v42 )
            (*this)[3566] = *(_DWORD *)(v42 + 4);
          v44 = *(int **)(v43 + 8);
          if ( !v44 )
            break;
          v40 = *v44;
        }
        while ( v40 );
      }
      dword_7652DC = (int)*this;
      v45 = (int)(*this + 31);
      v93 = 0;
      v95 = 0;
      v97 = 0;
      v46 = *(int **)v45;
      v47 = *(_DWORD *)v45 == 0;
      *(_DWORD *)(v45 + 8) = *(_DWORD *)v45;
      if ( !v47 )
      {
        v48 = *v46;
        if ( *v46 )
        {
          do
          {
            if ( *(_DWORD *)(v48 + 204) != a3 )
            {
              v49 = operator new(4u);
              *v49 = v48;
              v50 = operator new(0xCu);
              if ( v50 )
              {
                *v50 = v49;
                v50[1] = 0;
                *((_BYTE *)v50 + 8) = 1;
              }
              else
              {
                v50 = 0;
              }
              if ( v93 )
                v95[1] = v50;
              else
                v93 = v50;
              v95 = v50;
              ++v97;
            }
            v51 = (*this)[33];
            v52 = (int)(*this + 31);
            if ( v51 )
              (*this)[33] = *(_DWORD *)(v51 + 4);
            v53 = *(int **)(v52 + 8);
            if ( !v53 )
              break;
            v48 = *v53;
          }
          while ( *v53 );
        }
      }
      v54 = (_DWORD *)sub_46DAB0(v93);
      v94 = v54;
      if ( v54 )
      {
        for ( j = v54[1]; j; j = *(_DWORD *)(j + 4) )
          ;
      }
      v56 = v83 / 48;
      if ( v92 > 1 )
        v56 = v92 / 2;
      v89 = v56;
      v57 = (_BYTE ***)(*this)[3564];
      (*this)[3566] = (int)v57;
      if ( v57 )
        v58 = *v57;
      else
        v58 = 0;
      v96 = v94;
      if ( v94 )
        v86 = (_DWORD *)*v94;
      else
        v86 = 0;
      do
      {
        if ( v58 )
        {
          while ( !(*v58)[56] || !sub_46C7B0(*v58, a2, *((unsigned __int8 *)*this + v90 + 418)) )
          {
            v59 = (*this)[3566];
            v60 = (int)(*this + 3564);
            if ( v59 )
              (*this)[3566] = *(_DWORD *)(v59 + 4);
            v61 = *(_BYTE ****)(v60 + 8);
            if ( !v61 )
              goto LABEL_120;
            v58 = *v61;
            if ( !*v61 )
              goto LABEL_121;
          }
          sub_46C7A0(*v58, a2);
          v62 = (int)*v58;
          if ( *(_DWORD *)(*v58 + 261) != a3 )
          {
            if ( --v89 < 0 )
            {
              v66 = operator new(0xD0u);
              v67 = *v58 + 57;
              v68 = v66;
              sub_4D0D00(1, 7, 14, *v67 & 0x3F, *(float *)(*v58 + 61), 0);
              sub_4D0840(v67 + 2);
              v69 = *this + 3568;
              if ( v68 )
              {
                v70 = operator new(0xCu);
                if ( v70 )
                {
                  *v70 = v68;
                  v70[1] = 0;
                  *((_BYTE *)v70 + 8) = 1;
                }
                else
                {
                  v70 = 0;
                }
                if ( *v69 )
                {
                  *(_DWORD *)(v69[1] + 4) = v70;
                }
                else
                {
                  *v69 = v70;
                  v69[2] = v70;
                }
                v69[1] = v70;
                ++v69[3];
              }
              v83 += -8 - ((*v68 >> 6) & 0x3FF);
            }
            else
            {
              v63 = v62 + 57;
              v64 = *this + 3568;
              if ( v62 != -57 )
              {
                v65 = operator new(0xCu);
                if ( v65 )
                {
                  *v65 = v63;
                  v65[1] = 0;
                  *((_BYTE *)v65 + 8) = 0;
                }
                else
                {
                  v65 = 0;
                }
                if ( *v64 )
                {
                  *(_DWORD *)(v64[1] + 4) = v65;
                }
                else
                {
                  *v64 = v65;
                  v64[2] = v65;
                }
                v64[1] = v65;
                ++v64[3];
              }
              v83 -= 48;
            }
          }
          v71 = (*this)[3566];
          v72 = (int)(*this + 3564);
          if ( v71 )
            (*this)[3566] = *(_DWORD *)(v71 + 4);
          v73 = *(_BYTE ****)(v72 + 8);
          if ( v73 )
          {
            v58 = *v73;
            goto LABEL_121;
          }
LABEL_120:
          v58 = 0;
        }
LABEL_121:
        if ( v83 <= 0 )
          break;
        v74 = (_DWORD **)v86;
        if ( v86 )
        {
          v75 = (_DWORD *)*v86;
          v76 = *this + 3568;
          if ( *v86 )
          {
            v77 = operator new(0xCu);
            if ( v77 )
            {
              *v77 = v75;
              v77[1] = 0;
              *((_BYTE *)v77 + 8) = 0;
            }
            else
            {
              v77 = 0;
            }
            if ( *v76 )
            {
              *(_DWORD *)(v76[1] + 4) = v77;
            }
            else
            {
              *v76 = v77;
              v76[2] = v77;
            }
            v76[1] = v77;
            ++v76[3];
            v74 = (_DWORD **)v86;
          }
          v83 += -8 - ((unsigned __int16)**v74 >> 6);
          if ( v96 && (v96 = (_DWORD *)v96[1]) != 0 )
            v86 = (_DWORD *)*v96;
          else
            v86 = 0;
        }
        else if ( !v58 )
        {
          break;
        }
      }
      while ( v83 > 0 );
      v78 = (LPVOID *)v94;
      if ( v94 )
      {
        do
        {
          v79 = v78;
          v80 = *((_BYTE *)v78 + 8);
          v78 = (LPVOID *)v78[1];
          if ( v80 )
            sub_5BE8AE(*v79);
          sub_5BE8AE(v79);
        }
        while ( v78 );
      }
    }
  }
  result = *this + 3568;
  (*this)[3570] = *result;
  if ( v83 > 0 )
  {
    result = (int)(__int64)(v91 * v84) < 0 ? 0 : (int *)(__int64)(v91 * v84);
    if ( (int)result >= v83 )
      result = (int *)v83;
    *(_WORD *)((char *)*this + v90 + 416) = (_WORD)result;
  }
  return result;
}
