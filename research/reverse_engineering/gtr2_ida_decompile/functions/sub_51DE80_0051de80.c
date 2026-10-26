int __thiscall sub_51DE80(_DWORD *this, int a2, int a3)
{
  _DWORD *v3; // eax
  double v4; // st7
  int v5; // ebx
  int v6; // ebp
  int v7; // edi
  unsigned __int16 *v8; // eax
  int v9; // ecx
  int v10; // esi
  int v11; // esi
  float *v12; // esi
  unsigned __int16 *v13; // eax
  int v14; // edi
  int v15; // ecx
  int v16; // ecx
  int v17; // ecx
  int v18; // edi
  int v19; // esi
  int v20; // ebx
  int v21; // ecx
  double v22; // st7
  int result; // eax
  double v24; // st6
  int v25; // ecx
  int v26; // edx
  unsigned __int16 *v27; // eax
  int v28; // ecx
  int v29; // eax
  int v30; // eax
  int v31; // eax
  _DWORD *v32; // ecx
  float *v33; // edi
  int v34; // eax
  int v35; // ecx
  int v36; // eax
  int v37; // eax
  int v38; // eax
  _DWORD *v39; // ecx
  float *v40; // esi
  int v41; // eax
  int v42; // ecx
  int v43; // eax
  int v44; // eax
  int v45; // eax
  _DWORD *v46; // ebx
  float *v47; // ebp
  int v48; // ecx
  bool v49; // cc
  bool v50; // [esp+1Bh] [ebp-6Dh]
  float v51; // [esp+1Ch] [ebp-6Ch]
  int i; // [esp+1Ch] [ebp-6Ch]
  int v53; // [esp+20h] [ebp-68h]
  float v54; // [esp+24h] [ebp-64h]
  int v55; // [esp+24h] [ebp-64h]
  int v56; // [esp+28h] [ebp-60h]
  float v57; // [esp+2Ch] [ebp-5Ch]
  float v58; // [esp+30h] [ebp-58h]
  double v59; // [esp+34h] [ebp-54h]
  _DWORD *v60; // [esp+34h] [ebp-54h]
  _DWORD *v61; // [esp+38h] [ebp-50h]
  _DWORD *v62; // [esp+3Ch] [ebp-4Ch]
  float v63; // [esp+40h] [ebp-48h]
  float v64; // [esp+4Ch] [ebp-3Ch]
  float v65; // [esp+60h] [ebp-28h]
  float v66; // [esp+6Ch] [ebp-1Ch]
  _DWORD *v67; // [esp+70h] [ebp-18h]
  _DWORD *v68; // [esp+74h] [ebp-14h]

  v3 = (_DWORD *)this[7];
  v57 = flt_91BDE4;
  v59 = flt_91BDE4;
  v53 = v3[26];
  v56 = (*v3 & 8) != 0 ? 0x8000 : 4096;
  v4 = floor(flt_91BDE4 * 0.005);
  v5 = a2;
  v63 = 9999999.0;
  v64 = -9999999.0;
  v65 = 9999999.0;
  v66 = -9999999.0;
  v58 = 1.0 / ((flt_91BDE4 - v4 * 200.0) / v4 + 200.0);
  if ( a2 < a3 )
  {
    v6 = 36 * a2;
    do
    {
      v7 = *(_DWORD *)(v53 + 368);
      if ( v5 >= v7 )
        v8 = 0;
      else
        v8 = (unsigned __int16 *)(v6 + *(_DWORD *)(v53 + 372));
      v9 = *((_DWORD *)v8 + 2);
      v10 = *v8;
      if ( (*(_BYTE *)v9 & 8) != 0 )
        v11 = 88 * v10;
      else
        v11 = v10 << 6;
      v12 = (float *)(*(_DWORD *)(v9 + 32) + v11);
      if ( v5 >= v7 )
        v13 = 0;
      else
        v13 = (unsigned __int16 *)(v6 + *(_DWORD *)(v53 + 372));
      v14 = *((_DWORD *)v13 + 2);
      v15 = *v13;
      if ( (*(_BYTE *)v14 & 8) != 0 )
        v16 = 88 * v15;
      else
        v16 = v15 << 6;
      v17 = *(_DWORD *)(v14 + 32) + v16;
      if ( *v12 < (double)v63 )
        v63 = *v12;
      if ( *v12 > (double)v64 )
        v64 = *v12;
      if ( *(float *)(v17 + 8) < (double)v65 )
        v65 = *(float *)(v17 + 8);
      if ( *(float *)(v17 + 8) > (double)v66 )
        v66 = *(float *)(v17 + 8);
      ++v5;
      v6 += 36;
    }
    while ( v5 < a3 );
  }
  v18 = sub_4031C0();
  v19 = sub_4031C0();
  v20 = sub_4031C0();
  v21 = sub_4031C0();
  v51 = *(float *)(v18 + 76);
  v54 = v51;
  if ( v51 >= (double)*(float *)(v19 + 76) )
    v54 = *(float *)(v19 + 76);
  if ( v54 >= (double)*(float *)(v20 + 76) )
    v54 = *(float *)(v20 + 76);
  if ( v54 >= (double)*(float *)(v21 + 76) )
    v54 = *(float *)(v21 + 76);
  if ( v51 <= (double)*(float *)(v19 + 76) )
    v51 = *(float *)(v19 + 76);
  if ( v51 <= (double)*(float *)(v20 + 76) )
    v51 = *(float *)(v20 + 76);
  if ( v51 <= (double)*(float *)(v21 + 76) )
    v51 = *(float *)(v21 + 76);
  v22 = v59 * 0.5;
  v50 = v51 - v54 > v59 * 0.5;
  result = a2;
  v55 = a2;
  if ( a2 < a3 )
  {
    v24 = v58;
    v25 = 36 * a2;
    for ( i = 36 * a2; ; v25 = i )
    {
      v26 = *(_DWORD *)(v53 + 368);
      if ( v55 >= v26 )
        v27 = 0;
      else
        v27 = (unsigned __int16 *)(v25 + *(_DWORD *)(v53 + 372));
      v28 = *((_DWORD *)v27 + 2);
      v29 = *v27;
      if ( (*(_BYTE *)v28 & 8) != 0 )
        v30 = 88 * v29;
      else
        v30 = v29 << 6;
      v31 = *(_DWORD *)(v28 + 32) + v30;
      if ( v56 == 4096 )
      {
        v60 = (_DWORD *)(v31 + 32);
        v32 = (_DWORD *)(v31 + 36);
        v33 = (float *)(v31 + 52);
      }
      else
      {
        v60 = (_DWORD *)(v31 + 56);
        v32 = (_DWORD *)(v31 + 60);
        v33 = (float *)(v31 + 76);
      }
      v67 = v32;
      if ( v55 >= v26 )
        v34 = 0;
      else
        v34 = i + *(_DWORD *)(v53 + 372);
      v35 = *(_DWORD *)(v34 + 8);
      v36 = *(unsigned __int16 *)(v34 + 2);
      if ( (*(_BYTE *)v35 & 8) != 0 )
        v37 = 88 * v36;
      else
        v37 = v36 << 6;
      v38 = *(_DWORD *)(v35 + 32) + v37;
      if ( v56 == 4096 )
      {
        v61 = (_DWORD *)(v38 + 32);
        v39 = (_DWORD *)(v38 + 36);
        v40 = (float *)(v38 + 52);
      }
      else
      {
        v61 = (_DWORD *)(v38 + 56);
        v39 = (_DWORD *)(v38 + 60);
        v40 = (float *)(v38 + 76);
      }
      v68 = v39;
      if ( v55 >= v26 )
        v41 = 0;
      else
        v41 = i + *(_DWORD *)(v53 + 372);
      v42 = *(_DWORD *)(v41 + 8);
      v43 = *(unsigned __int16 *)(v41 + 4);
      if ( (*(_BYTE *)v42 & 8) != 0 )
        v44 = 88 * v43;
      else
        v44 = v43 << 6;
      v45 = *(_DWORD *)(v42 + 32) + v44;
      if ( v56 == 4096 )
      {
        v62 = (_DWORD *)(v45 + 32);
        v46 = (_DWORD *)(v45 + 36);
        v47 = (float *)(v45 + 52);
      }
      else
      {
        v62 = (_DWORD *)(v45 + 56);
        v46 = (_DWORD *)(v45 + 60);
        v47 = (float *)(v45 + 76);
      }
      v48 = 0;
      if ( *v60 == 1045220557 )
      {
        if ( *v67 == -998637732 )
        {
          if ( v50 && *v33 > v22 )
            *v33 = *v33 - v57;
          *v33 = v58 * *v33;
          *v67 = -1025623982;
        }
        v48 = 1;
      }
      if ( *v61 == 1045220557 )
      {
        if ( *v68 == -998637732 )
        {
          if ( v50 && *v40 > v22 )
            *v40 = *v40 - v57;
          *v40 = v58 * *v40;
          *v68 = -1025623982;
        }
        ++v48;
      }
      if ( *v62 == 1045220557 )
      {
        if ( *v46 == -998637732 )
        {
          if ( v50 && *v47 > v22 )
            *v47 = *v47 - v57;
          *v47 = v58 * *v47;
          *v46 = -1025623982;
        }
        ++v48;
      }
      if ( v48 && v48 != 3 )
      {
        if ( *(_DWORD *)v33 == 953267991 )
        {
          if ( *(_DWORD *)v40 == 953267991 )
          {
            if ( *(_DWORD *)v47 != 953267991 )
              v24 = *v47;
          }
          else
          {
            v24 = *v40;
          }
        }
        else
        {
          v24 = *v33;
        }
        *v47 = v24;
        *v40 = v24;
        *v33 = v24;
      }
      result = v55 + 1;
      v49 = ++v55 < a3;
      i += 36;
      if ( !v49 )
        break;
    }
  }
  return result;
}
