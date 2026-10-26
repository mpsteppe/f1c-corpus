double *__stdcall sub_52050E(double *a1, _DWORD *a2, const double *a3)
{
  __m128 v3; // xmm4
  __m128 v4; // xmm1
  __m128 v5; // xmm5
  __m128 v6; // xmm0
  __m128 v7; // xmm4
  __m128 v8; // xmm5
  __m128 v9; // xmm6
  __m128 v10; // xmm5
  __m128 v11; // xmm7
  __m128 v12; // xmm3
  __m128 v13; // xmm1
  __m128 v14; // xmm7
  __m128 v15; // xmm3
  __m128 v16; // xmm5
  __m128 v17; // xmm5
  __m128 v18; // xmm6
  __m128 v19; // xmm3
  __m128 v20; // xmm5
  __m128 v21; // xmm6
  __m128 v22; // xmm3
  __m128 v23; // xmm7
  __m128 v24; // xmm7
  __m128 v25; // xmm5
  __m128 v26; // xmm0
  __m128 v27; // xmm6
  __m128 v28; // xmm7
  __m128 v29; // xmm4
  __m128 v30; // xmm0
  __m128 v31; // xmm7
  __m128 v32; // xmm5
  __m128 v33; // xmm6
  __m128 v34; // xmm1
  __m128 v35; // xmm1
  __m128 v36; // xmm0
  __m128 v37; // xmm5
  __m128 v38; // xmm6
  __m128 v39; // xmm3
  __m128 v40; // xmm3
  __m128 v41; // xmm5
  __m128 v42; // xmm7
  __m128 v43; // xmm3
  __m128 v44; // xmm6
  __m128 v45; // xmm4
  __m128 v46; // xmm0
  __m128 v47; // xmm4
  __m128 v48; // xmm3
  __m128 v49; // xmm0
  __m128 v50; // xmm4
  __m128 v51; // xmm6
  __m128 v52; // xmm2
  __m128 v53; // xmm0
  double *result; // eax
  __m128 v55; // xmm5
  __m128 v56; // xmm5
  __m128 v57; // xmm1
  __m128 v58; // xmm4
  __m128 v59; // xmm6
  __m128 v60; // xmm5
  __m128 v61; // [esp+20h] [ebp-FCh]
  __m128 v62; // [esp+30h] [ebp-ECh]
  __m128 v63; // [esp+40h] [ebp-DCh]
  __m128 v64; // [esp+50h] [ebp-CCh]
  __m128 v65; // [esp+60h] [ebp-BCh]
  __m128 v66; // [esp+70h] [ebp-ACh]
  __m128 v67; // [esp+80h] [ebp-9Ch]
  __m128 v68; // [esp+90h] [ebp-8Ch]
  __m128 v69; // [esp+A0h] [ebp-7Ch]
  __m128 v70; // [esp+B0h] [ebp-6Ch]
  __m128 v71; // [esp+E0h] [ebp-3Ch]

  v3 = _mm_loadh_ps(a3 + 7);
  v4 = _mm_loadh_ps(a3 + 2);
  v5 = _mm_loadh_ps(a3 + 3);
  v6 = _mm_shuffle_ps(v5, v3, 136);
  v7 = _mm_shuffle_ps(v3, v5, 221);
  v8 = _mm_mul_ps(v7, v6);
  v9 = _mm_shuffle_ps(v8, v8, 177);
  v10 = _mm_shuffle_ps(v9, v9, 78);
  v11 = _mm_loadh_ps(a3 + 6);
  v12 = _mm_shuffle_ps(v11, v4, 221);
  v13 = _mm_shuffle_ps(v4, v11, 136);
  v14 = v12;
  v15 = _mm_mul_ps(v12, v10);
  v62 = _mm_mul_ps(v10, v13);
  v16 = _mm_mul_ps(v14, v6);
  v17 = _mm_shuffle_ps(v16, v16, 177);
  v63 = _mm_mul_ps(v9, v13);
  v18 = _mm_add_ps(_mm_mul_ps(v7, v17), _mm_sub_ps(v15, _mm_mul_ps(v14, v9)));
  v19 = v17;
  v20 = _mm_shuffle_ps(v17, v17, 78);
  v64 = _mm_mul_ps(v19, v13);
  v21 = _mm_sub_ps(v18, _mm_mul_ps(v7, v20));
  v22 = v14;
  v23 = _mm_mul_ps(_mm_shuffle_ps(v14, v14, 78), v7);
  v24 = _mm_shuffle_ps(v23, v23, 177);
  v65 = _mm_mul_ps(v20, v13);
  v25 = _mm_shuffle_ps(v6, v6, 78);
  v26 = _mm_add_ps(_mm_mul_ps(v25, v24), v21);
  v27 = v24;
  v28 = _mm_shuffle_ps(v24, v24, 78);
  v66 = v7;
  v29 = v25;
  v30 = _mm_sub_ps(v26, _mm_mul_ps(v25, v28));
  v31 = _mm_sub_ps(_mm_mul_ps(v28, v13), _mm_mul_ps(v27, v13));
  v32 = v13;
  v33 = _mm_mul_ps(v13, v30);
  v61 = v30;
  v34 = _mm_add_ps(_mm_shuffle_ps(v33, v33, 78), v33);
  v30.m128_i32[0] = v34.m128_i32[0];
  v35 = _mm_shuffle_ps(v34, v34, 177);
  v35.m128_f32[0] = v35.m128_f32[0] + v30.m128_f32[0];
  v36 = v32;
  v37 = _mm_mul_ps(v32, v22);
  v38 = _mm_shuffle_ps(v37, v37, 177);
  v67 = v29;
  v68 = v22;
  v39 = _mm_mul_ps(v66, v36);
  v40 = _mm_shuffle_ps(v39, v39, 177);
  v69 = _mm_shuffle_ps(v38, v38, 78);
  v70 = v38;
  v41 = _mm_add_ps(
          _mm_mul_ps(v68, v40),
          _mm_sub_ps(_mm_mul_ps(v66, v69), _mm_add_ps(_mm_mul_ps(v66, v38), _mm_shuffle_ps(v31, v31, 78))));
  v42 = v40;
  v43 = _mm_shuffle_ps(v40, v40, 78);
  v44 = _mm_sub_ps(v41, _mm_mul_ps(v68, v43));
  v45 = _mm_sub_ps(v62, v63);
  v46 = _mm_mul_ps(v36, v67);
  v47 = _mm_add_ps(_mm_sub_ps(_mm_shuffle_ps(v45, v45, 78), _mm_mul_ps(v42, v67)), _mm_mul_ps(v43, v67));
  v48 = _mm_shuffle_ps(v46, v46, 177);
  v49 = _mm_shuffle_ps(v48, v48, 78);
  v71 = v44;
  v50 = _mm_sub_ps(_mm_add_ps(v47, _mm_mul_ps(v66, v48)), _mm_mul_ps(v66, v49));
  v51 = _mm_sub_ps(v65, v64);
  v52 = _mm_add_ps(
          _mm_mul_ps(v68, v49),
          _mm_sub_ps(
            _mm_sub_ps(_mm_sub_ps(_mm_mul_ps(v70, v67), _mm_shuffle_ps(v51, v51, 78)), _mm_mul_ps(v67, v69)),
            _mm_mul_ps(v48, v68)));
  if ( v35.m128_f32[0] == 0.0 )
    return 0;
  if ( a2 )
    *a2 = v35.m128_i32[0];
  v53 = v35;
  result = a1;
  v53.m128_f32[0] = 1.0 / v35.m128_f32[0];
  v55 = v53;
  v55.m128_f32[0] = (float)(v55.m128_f32[0] + v55.m128_f32[0])
                  - (float)(v35.m128_f32[0] * (float)(v53.m128_f32[0] * v53.m128_f32[0]));
  v56 = _mm_shuffle_ps(v55, v55, 0);
  v57 = _mm_mul_ps(v61, v56);
  _mm_storel_ps(a1, v57);
  _mm_storeh_ps(a1 + 1, v57);
  v58 = _mm_mul_ps(v50, v56);
  _mm_storel_ps(a1 + 2, v58);
  _mm_storeh_ps(a1 + 3, v58);
  v59 = _mm_mul_ps(v71, v56);
  _mm_storel_ps(a1 + 4, v59);
  _mm_storeh_ps(a1 + 5, v59);
  v60 = _mm_mul_ps(v56, v52);
  _mm_storel_ps(a1 + 6, v60);
  _mm_storeh_ps(a1 + 7, v60);
  return result;
}

