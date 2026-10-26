double *__stdcall sub_5AFD5B(double *a1, _DWORD *a2, const double *a3)
{
  __m128 v3; // xmm2
  __m128 v4; // xmm4
  __m128 v5; // xmm1
  __m128 v6; // xmm5
  __m128 v7; // xmm4
  __m128 v8; // xmm2
  __m128 v9; // xmm2
  __m128 v10; // xmm6
  __m128 v11; // xmm7
  __m128 v12; // xmm3
  __m128 v13; // xmm1
  __m128 v14; // xmm7
  __m128 v15; // xmm3
  __m128 v16; // xmm6
  __m128 v17; // xmm3
  __m128 v18; // xmm7
  __m128 v19; // xmm7
  __m128 v20; // xmm2
  __m128 v21; // xmm3
  __m128 v22; // xmm7
  __m128 v23; // xmm2
  __m128 v24; // xmm3
  __m128 v25; // xmm3
  __m128 v26; // xmm7
  __m128 v27; // xmm5
  __m128 v28; // xmm2
  __m128 v29; // xmm3
  __m128 v30; // xmm4
  __m128 v31; // xmm5
  __m128 v32; // xmm3
  __m128 v33; // xmm2
  __m128 v34; // xmm7
  __m128 v35; // xmm1
  __m128 v36; // xmm1
  __m128 v37; // xmm5
  __m128 v38; // xmm7
  __m128 v39; // xmm6
  __m128 v40; // xmm6
  __m128 v41; // xmm7
  __m128 v42; // xmm3
  __m128 v43; // xmm4
  __m128 v44; // xmm6
  __m128 v45; // xmm5
  __m128 v46; // xmm2
  __m128 v47; // xmm2
  __m128 v48; // xmm5
  __m128 v49; // xmm3
  __m128 v50; // xmm4
  __m128 v51; // xmm5
  __m128 v52; // xmm2
  __m128 v53; // xmm0
  double *result; // eax
  __m128 v55; // xmm5
  __m128 v56; // xmm5
  __m128 v57; // xmm1
  __m128 v58; // xmm4
  __m128 v59; // xmm6
  __m128 v60; // xmm5
  __m128 v61; // [esp-E0h] [ebp-ECh]
  __m128 v62; // [esp-D0h] [ebp-DCh]
  __m128 v63; // [esp-C0h] [ebp-CCh]
  __m128 v64; // [esp-B0h] [ebp-BCh]
  __m128 v65; // [esp-A0h] [ebp-ACh]
  __m128 v66; // [esp-90h] [ebp-9Ch]
  __m128 v67; // [esp-80h] [ebp-8Ch]
  __m128 v68; // [esp-70h] [ebp-7Ch]
  __m128 v69; // [esp-60h] [ebp-6Ch]
  __m128 v70; // [esp-50h] [ebp-5Ch]

  v3 = _mm_loadh_ps(a3 + 3);
  v4 = _mm_loadh_ps(a3 + 7);
  v5 = _mm_loadh_ps(a3 + 2);
  v6 = _mm_shuffle_ps(v3, v4, 136);
  v7 = _mm_shuffle_ps(v4, v3, 221);
  v8 = _mm_mul_ps(v7, v6);
  v9 = _mm_shuffle_ps(v8, v8, 177);
  v10 = _mm_shuffle_ps(v9, v9, 78);
  v11 = _mm_loadh_ps(a3 + 6);
  v12 = _mm_shuffle_ps(v11, v5, 221);
  v13 = _mm_shuffle_ps(v5, v11, 136);
  v14 = v12;
  v15 = _mm_mul_ps(v12, v10);
  v62 = _mm_mul_ps(v10, v13);
  v16 = v14;
  v17 = _mm_sub_ps(v15, _mm_mul_ps(v14, v9));
  v18 = _mm_mul_ps(v14, v6);
  v19 = _mm_shuffle_ps(v18, v18, 177);
  v63 = _mm_mul_ps(v9, v13);
  v20 = _mm_add_ps(_mm_mul_ps(v7, v19), v17);
  v21 = v19;
  v22 = _mm_shuffle_ps(v19, v19, 78);
  v64 = _mm_mul_ps(v21, v13);
  v23 = _mm_sub_ps(v20, _mm_mul_ps(v7, v22));
  v24 = _mm_mul_ps(_mm_shuffle_ps(v16, v16, 78), v7);
  v25 = _mm_shuffle_ps(v24, v24, 177);
  v65 = _mm_mul_ps(v22, v13);
  v26 = _mm_shuffle_ps(v6, v6, 78);
  v27 = _mm_add_ps(_mm_mul_ps(v26, v25), v23);
  v28 = v25;
  v29 = _mm_shuffle_ps(v25, v25, 78);
  v66 = v7;
  v30 = v26;
  v31 = _mm_sub_ps(v27, _mm_mul_ps(v26, v29));
  v32 = _mm_sub_ps(_mm_mul_ps(v29, v13), _mm_mul_ps(v28, v13));
  v33 = v13;
  v34 = _mm_mul_ps(v13, v31);
  v61 = v31;
  v35 = _mm_add_ps(_mm_shuffle_ps(v34, v34, 78), v34);
  v31.m128_i32[0] = v35.m128_i32[0];
  v36 = _mm_shuffle_ps(v35, v35, 177);
  v36.m128_f32[0] = v36.m128_f32[0] + v31.m128_f32[0];
  v37 = _mm_mul_ps(v16, v33);
  v38 = _mm_shuffle_ps(v37, v37, 177);
  v67 = v30;
  v68 = v16;
  v39 = _mm_mul_ps(v66, v33);
  v40 = _mm_shuffle_ps(v39, v39, 177);
  v69 = _mm_shuffle_ps(v38, v38, 78);
  v70 = v38;
  v41 = _mm_add_ps(
          _mm_mul_ps(v40, v68),
          _mm_sub_ps(_mm_mul_ps(v66, v69), _mm_add_ps(_mm_mul_ps(v66, v38), _mm_shuffle_ps(v32, v32, 78))));
  v42 = _mm_shuffle_ps(v40, v40, 78);
  v43 = v40;
  v44 = _mm_sub_ps(v41, _mm_mul_ps(v68, v42));
  v45 = _mm_sub_ps(v62, v63);
  v46 = _mm_mul_ps(v33, v67);
  v47 = _mm_shuffle_ps(v46, v46, 177);
  v48 = _mm_add_ps(
          _mm_mul_ps(v66, v47),
          _mm_add_ps(_mm_mul_ps(v42, v67), _mm_sub_ps(_mm_shuffle_ps(v45, v45, 78), _mm_mul_ps(v43, v67))));
  v49 = _mm_shuffle_ps(v47, v47, 78);
  v50 = _mm_sub_ps(v48, _mm_mul_ps(v66, v49));
  v51 = _mm_sub_ps(v65, v64);
  v52 = _mm_add_ps(
          _mm_mul_ps(v68, v49),
          _mm_sub_ps(
            _mm_sub_ps(_mm_sub_ps(_mm_mul_ps(v70, v67), _mm_shuffle_ps(v51, v51, 78)), _mm_mul_ps(v67, v69)),
            _mm_mul_ps(v47, v68)));
  if ( v36.m128_f32[0] == 0.0 )
    return 0;
  if ( a2 )
    *a2 = v36.m128_i32[0];
  v53 = v36;
  result = a1;
  v53.m128_f32[0] = 1.0 / v36.m128_f32[0];
  v55 = v53;
  v55.m128_f32[0] = (float)(v55.m128_f32[0] + v55.m128_f32[0])
                  - (float)(v36.m128_f32[0] * (float)(v53.m128_f32[0] * v53.m128_f32[0]));
  v56 = _mm_shuffle_ps(v55, v55, 0);
  v57 = _mm_mul_ps(v61, v56);
  _mm_storel_ps(a1, v57);
  _mm_storeh_ps(a1 + 1, v57);
  v58 = _mm_mul_ps(v50, v56);
  _mm_storel_ps(a1 + 2, v58);
  _mm_storeh_ps(a1 + 3, v58);
  v59 = _mm_mul_ps(v44, v56);
  _mm_storel_ps(a1 + 4, v59);
  _mm_storeh_ps(a1 + 5, v59);
  v60 = _mm_mul_ps(v56, v52);
  _mm_storel_ps(a1 + 6, v60);
  _mm_storeh_ps(a1 + 7, v60);
  return result;
}
