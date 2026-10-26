const double *__userpurge sub_5B0BA0@<eax>(
        int a1@<ebp>,
        const double *a2,
        unsigned int *a3,
        int a4,
        __m128 *a5,
        const double *a6,
        const double *a7,
        const double *a8,
        unsigned int a9)
{
  __m128 v9; // xmm0
  const double *result; // eax
  __m128 v11; // xmm0
  __m128 v12; // xmm0
  __m128 v13; // xmm0
  __m128 v14; // xmm0
  __m128 v15; // xmm1
  __m128 v16; // xmm3
  __m128 v17; // xmm2
  __m128 v18; // xmm7
  __m128 v19; // xmm6
  __m128 v20; // xmm5
  __m128 v21; // xmm6
  __m128 v22; // xmm5
  __m128 v23; // xmm3
  __m128 v24; // xmm4
  __m128 v25; // xmm6
  __m128 v26; // xmm1
  __m128 v27; // xmm7
  __m128 v28; // xmm6
  __m128 v29; // xmm1
  __m128 v30; // xmm4
  __m128 v31; // xmm3
  __m128 v32; // xmm3
  __m128 v33; // xmm7
  __m128 v34; // xmm0
  __m128 v35; // xmm4
  __m128 v36; // xmm3
  __m128 v37; // xmm6
  __m128 v38; // xmm0
  __m128 v39; // xmm5
  __m128 v40; // xmm2
  __m128 v41; // xmm0
  __m128 v42; // xmm1
  __m128 v43; // xmm1
  __m128 v44; // xmm2
  __m128 v45; // xmm3
  __m128 v46; // xmm5
  __m128 v47; // xmm1
  __m128 v48; // xmm7
  __m128 v49; // xmm5
  __m128 v50; // xmm1
  __m128 v51; // xmm7
  __m128 v52; // xmm1
  unsigned int v53; // eax
  const double *v54; // esi
  const double *v55; // edi
  __m128 v56; // [esp+Ch] [ebp-2CCh]
  __m128 v57; // [esp+1Ch] [ebp-2BCh]
  __m128 v58; // [esp+2Ch] [ebp-2ACh]
  __m128 v59; // [esp+3Ch] [ebp-29Ch]
  __m128 v60; // [esp+4Ch] [ebp-28Ch]
  __m128 v61; // [esp+5Ch] [ebp-27Ch]
  __m128 v62; // [esp+6Ch] [ebp-26Ch]
  __m128 v63; // [esp+7Ch] [ebp-25Ch]
  __m128 v64; // [esp+8Ch] [ebp-24Ch]
  __m128 v65; // [esp+9Ch] [ebp-23Ch]
  __m128 v66; // [esp+ACh] [ebp-22Ch]
  float v67; // [esp+DCh] [ebp-1FCh]
  float v68; // [esp+ECh] [ebp-1ECh]
  float v69; // [esp+FCh] [ebp-1DCh]
  __m128 v70; // [esp+10Ch] [ebp-1CCh] BYREF
  unsigned int v71; // [esp+21Ch] [ebp-BCh]
  float v72; // [esp+220h] [ebp-B8h]
  unsigned int v73; // [esp+224h] [ebp-B4h]
  const double *v74; // [esp+228h] [ebp-B0h]
  const double *v75; // [esp+22Ch] [ebp-ACh]
  unsigned int v76; // [esp+230h] [ebp-A8h]
  const double *v77; // [esp+234h] [ebp-A4h]
  const double *v78; // [esp+238h] [ebp-A0h]
  __m128 *v79; // [esp+23Ch] [ebp-9Ch]
  unsigned int *v80; // [esp+240h] [ebp-98h]
  __m128 v81; // [esp+24Ch] [ebp-8Ch]
  __m128 v82; // [esp+25Ch] [ebp-7Ch]
  __m128 v83; // [esp+26Ch] [ebp-6Ch]
  __m128 v84; // [esp+27Ch] [ebp-5Ch]
  __m128 v85; // [esp+28Ch] [ebp-4Ch]
  __m128 v86; // [esp+29Ch] [ebp-3Ch]
  __m128 v87; // [esp+2ACh] [ebp-2Ch]
  int v88; // [esp+2CCh] [ebp-Ch]
  void *v89; // [esp+2D0h] [ebp-8h]
  void *retaddr; // [esp+2D8h] [ebp+0h]

  v88 = a1;
  v89 = retaddr;
  v74 = a6;
  v9 = _mm_loadh_ps(a6);
  result = a2;
  v73 = a9;
  v79 = a5;
  v56 = _mm_shuffle_ps(v9, v9, 78);
  v80 = a3;
  v11 = _mm_loadh_ps(a7);
  v62 = _mm_shuffle_ps(v11, v11, 78);
  v12 = _mm_loadh_ps(a8);
  v65 = _mm_shuffle_ps(v12, v12, 78);
  v13 = _mm_loadh_ps(a2);
  v66 = _mm_shuffle_ps(v13, v13, 78);
  v14 = _mm_loadh_ps((const double *)((char *)a2 + 12));
  v15 = _mm_loadh_ps(a2 + 3);
  v16 = _mm_mul_ps(_mm_sub_ps(v56, v62), (__m128)xmmword_905E90);
  v17 = _mm_mul_ps(v66, v16);
  v18 = _mm_mul_ps(_mm_sub_ps(v56, v65), (__m128)xmmword_905E90);
  v86 = _mm_shuffle_ps(v14, v14, 78);
  v19 = _mm_mul_ps(v66, v18);
  v87 = v86;
  v20 = _mm_movehl_ps(v17, v19);
  v21 = _mm_movelh_ps(v19, v17);
  v22 = _mm_add_ps(_mm_add_ps(v20, v21), _mm_shuffle_ps(v21, v21, 245));
  v57 = _mm_add_ps(_mm_sub_ps(v56, v16), _mm_mul_ps(_mm_shuffle_ps(v22, v22, 170), v66));
  v84 = _mm_shuffle_ps(v15, v15, 78);
  v83 = v84;
  v58 = _mm_add_ps(_mm_sub_ps(v56, v18), _mm_mul_ps(_mm_shuffle_ps(v22, v22, 0), v66));
  v82 = v84;
  v81 = _mm_sub_ps(v62, v56);
  v23 = _mm_mul_ps(v81, (__m128)xmmword_905E90);
  v24 = _mm_mul_ps(_mm_sub_ps(v62, v65), (__m128)xmmword_905E90);
  v25 = _mm_mul_ps(v86, v24);
  v85 = v84;
  v26 = _mm_mul_ps(v86, v23);
  v27 = _mm_movehl_ps(v26, v25);
  v28 = _mm_movelh_ps(v25, v26);
  v29 = _mm_sub_ps(v62, v24);
  v30 = _mm_sub_ps(v62, v23);
  v31 = _mm_add_ps(_mm_add_ps(v27, v28), _mm_shuffle_ps(v28, v28, 245));
  v63 = _mm_add_ps(v29, _mm_mul_ps(_mm_shuffle_ps(v31, v31, 0), v86));
  v59 = _mm_add_ps(v30, _mm_mul_ps(_mm_shuffle_ps(v31, v31, 170), v86));
  v32 = _mm_mul_ps(_mm_sub_ps(v65, v56), (__m128)xmmword_905E90);
  v33 = _mm_mul_ps(_mm_sub_ps(v65, v62), (__m128)xmmword_905E90);
  v34 = _mm_mul_ps(v84, v33);
  v35 = _mm_sub_ps(v65, v32);
  v36 = _mm_mul_ps(v84, v32);
  v37 = _mm_movehl_ps(v36, v34);
  v38 = _mm_movelh_ps(v34, v36);
  v39 = _mm_add_ps(_mm_add_ps(v37, v38), _mm_shuffle_ps(v38, v38, 245));
  v61 = _mm_add_ps(v35, _mm_mul_ps(_mm_shuffle_ps(v39, v39, 170), v84));
  v64 = _mm_add_ps(_mm_sub_ps(v65, v33), _mm_mul_ps(_mm_shuffle_ps(v39, v39, 0), v84));
  v60 = _mm_sub_ps(
          _mm_mul_ps(
            _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_add_ps(v57, v58), v59), v61), v63), v64),
            (__m128)xmmword_905EC0),
          _mm_mul_ps(_mm_add_ps(_mm_add_ps(v56, v62), v65), (__m128)xmmword_905ED0));
  if ( a4 )
  {
    v78 = a8;
    v77 = a7;
    v76 = 4 * v73;
    v75 = (const double *)&a3[2 * a4];
    do
    {
      v71 = *v80;
      v72 = *((float *)v80 + 1);
      v40 = (__m128)(unsigned int)dword_905EA0;
      v41 = (__m128)v71;
      v67 = *(float *)&v71;
      v68 = v72;
      v42 = _mm_unpacklo_ps((__m128)LODWORD(v72), (__m128)v71);
      v41.m128_f32[0] = *(float *)&v71 * v42.m128_f32[0];
      v40.m128_f32[0] = (float)(*(float *)&dword_905EA0 - *(float *)&v71) - v42.m128_f32[0];
      v69 = v40.m128_f32[0];
      v43 = _mm_movelh_ps(v42, v40);
      v41.m128_f32[0] = v41.m128_f32[0] * (float)(*(float *)&dword_905EB0 * v40.m128_f32[0]);
      v44 = _mm_shuffle_ps(v43, v43, 201);
      v45 = _mm_shuffle_ps(v43, v43, 210);
      v46 = _mm_mul_ps(v43, v43);
      v47 = _mm_mul_ps(v43, v46);
      v48 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(v60, _mm_shuffle_ps(v41, v41, 0)), _mm_mul_ps(_mm_shuffle_ps(v47, v47, 0), v56)),
                _mm_mul_ps(_mm_shuffle_ps(v47, v47, 85), v65)),
              _mm_mul_ps(_mm_shuffle_ps(v47, v47, 170), v62));
      v49 = _mm_mul_ps(v46, (__m128)xmmword_905E80);
      v50 = _mm_mul_ps(v49, v44);
      v51 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(v48, _mm_mul_ps(_mm_shuffle_ps(v50, v50, 0), v58)),
                _mm_mul_ps(_mm_shuffle_ps(v50, v50, 85), v64)),
              _mm_mul_ps(_mm_shuffle_ps(v50, v50, 170), v59));
      v52 = _mm_mul_ps(v49, v45);
      v70 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(v51, _mm_mul_ps(_mm_shuffle_ps(v52, v52, 0), v57)),
                _mm_mul_ps(_mm_shuffle_ps(v52, v52, 85), v61)),
              _mm_mul_ps(_mm_shuffle_ps(v52, v52, 170), v63));
      v53 = 3;
      if ( v73 > 3 )
      {
        v54 = v78;
        v55 = v77;
        do
        {
          v70.m128_f32[v53] = (float)((float)(*((float *)v74 + v53) * v68) + (float)(*((float *)v55 + v53) * v69))
                            + (float)(*((float *)v54 + v53) * v67);
          ++v53;
        }
        while ( v53 < v73 );
        v77 = v55;
        v78 = v54;
      }
      qmemcpy(v79, &v70, v76);
      v79 = (__m128 *)((char *)v79 + 4 * v73);
      result = v75;
      v80 += 2;
    }
    while ( v80 < (unsigned int *)v75 );
  }
  return result;
}
