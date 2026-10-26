int __thiscall sub_61AE30(int this)
{
  int result; // eax
  int v2; // ebp
  int v3; // edi
  int v4; // eax
  double v5; // st7
  int v6; // eax
  int v7; // esi
  unsigned __int8 v8; // bl
  double *v9; // edx
  double *v10; // edx
  double *v11; // edx
  int v12; // edx
  int v13; // eax
  double v14; // st7
  int v15; // eax
  int v16; // edi
  double v17; // st7
  double v18; // st6
  double v19; // st5
  bool v20; // zf
  int v21; // eax
  double *v22; // eax
  int v23; // eax
  int v24; // eax
  double v25; // st7
  double *v26; // eax
  double v27; // st7
  double *v28; // eax
  int v29; // eax
  int v30; // eax
  int v31; // eax
  int v32; // eax
  int v33; // eax
  int v34; // eax
  int v35; // edx
  int v36; // ebp
  int v37; // eax
  double v38; // st7
  int v39; // eax
  int v40; // edi
  double v41; // st7
  double v42; // st6
  double v43; // st5
  int v44; // eax
  double *v45; // eax
  double v46; // st7
  int v47; // [esp+10h] [ebp-58h]
  int v48; // [esp+14h] [ebp-54h]
  double v49; // [esp+18h] [ebp-50h]
  double v50; // [esp+20h] [ebp-48h]
  double v51; // [esp+28h] [ebp-40h]
  double v52; // [esp+30h] [ebp-38h]
  double v53; // [esp+38h] [ebp-30h]
  double v54; // [esp+40h] [ebp-28h]
  double v55; // [esp+50h] [ebp-18h]
  double v56; // [esp+50h] [ebp-18h]
  double v57; // [esp+58h] [ebp-10h]
  double v58; // [esp+60h] [ebp-8h]

  result = *(_DWORD *)(this + 568);
  if ( result > 0 )
  {
    v2 = 1;
    v3 = 0;
    v47 = 1;
    v48 = 0;
    do
    {
      v4 = *(_DWORD *)(this + 572);
      v5 = *(double *)(this + 256) * *(double *)(v4 + v3 + 88);
      v6 = v3 + v4;
      v7 = *(_DWORD *)(v6 + 124);
      v8 = *(_BYTE *)(v6 + 128);
      v9 = (double *)(*(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v7) + 8 * v7);
      v52 = v5 + *(double *)(this + 248) * *(double *)(v6 + 80) + *(double *)(this + 240) * *(double *)(v6 + 72);
      v53 = *(double *)(this + 280) * *(double *)(v6 + 88)
          + *(double *)(this + 272) * *(double *)(v6 + 80)
          + *(double *)(this + 264) * *(double *)(v6 + 72);
      v54 = *(double *)(this + 304) * *(double *)(v6 + 88)
          + *(double *)(this + 296) * *(double *)(v6 + 80)
          + *(double *)(this + 288) * *(double *)(v6 + 72);
      v49 = *(double *)(v6 + 96) * *(double *)(this + 240)
          + *(double *)(this + 256) * *(double *)(v6 + 112)
          + *(double *)(this + 248) * *(double *)(v6 + 104);
      v50 = *(double *)(this + 264) * *(double *)(v6 + 96)
          + *(double *)(this + 272) * *(double *)(v6 + 104)
          + *(double *)(this + 280) * *(double *)(v6 + 112);
      v51 = *(double *)(this + 296) * *(double *)(v6 + 104)
          + *(double *)(v6 + 96) * *(double *)(this + 288)
          + *(double *)(this + 304) * *(double *)(v6 + 112);
      *v9 = v54 * *(double *)(v6 + 88) + v53 * *(double *)(v6 + 80) + v52 * *(double *)(v6 + 72) + *v9;
      v10 = (double *)(*(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v7 + 4) + 8 * v7);
      *v10 = v51 * *(double *)(v6 + 88) + v50 * *(double *)(v6 + 80) + v49 * *(double *)(v6 + 72) + *v10;
      v11 = (double *)(*(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v7 + 4) + 8 * v7 + 8);
      *v11 = v51 * *(double *)(v6 + 112) + v50 * *(double *)(v6 + 104) + v49 * *(double *)(v6 + 96) + *v11;
      if ( v2 < *(_DWORD *)(this + 568) )
      {
        v12 = v3 + 136;
        do
        {
          v13 = *(_DWORD *)(this + 572);
          v14 = v54 * *(double *)(v13 + v12 + 88);
          v15 = v12 + v13;
          v16 = *(_DWORD *)(v15 + 124);
          v17 = v14 + v52 * *(double *)(v15 + 72) + v53 * *(double *)(v15 + 80);
          v57 = v51 * *(double *)(v15 + 88) + v49 * *(double *)(v15 + 72) + v50 * *(double *)(v15 + 80);
          v58 = v51 * *(double *)(v15 + 112) + v49 * *(double *)(v15 + 96) + v50 * *(double *)(v15 + 104);
          v18 = v54 * *(double *)(v15 + 112) + v52 * *(double *)(v15 + 96);
          v19 = v53 * *(double *)(v15 + 104);
          v20 = v8 == *(_BYTE *)(v15 + 128);
          v21 = *(_DWORD *)(this + 556);
          v55 = v18 + v19;
          if ( v20 )
          {
            if ( v7 <= v16 )
            {
              *(double *)(*(_DWORD *)(v21 + 4 * v16) + 8 * v7) = v17 + *(double *)(*(_DWORD *)(v21 + 4 * v16) + 8 * v7);
              v33 = *(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v16);
              *(double *)(v33 + 8 * v7 + 8) = v57 + *(double *)(v33 + 8 * v7 + 8);
              v34 = *(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v16 + 4);
              *(double *)(v34 + 8 * v7) = v55 + *(double *)(v34 + 8 * v7);
              v26 = (double *)(*(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v16 + 4) + 8 * v7 + 8);
            }
            else
            {
              *(double *)(*(_DWORD *)(v21 + 4 * v7) + 8 * v16) = v17 + *(double *)(*(_DWORD *)(v21 + 4 * v7) + 8 * v16);
              v31 = *(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v7);
              *(double *)(v31 + 8 * v16 + 8) = v55 + *(double *)(v31 + 8 * v16 + 8);
              v32 = *(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v7 + 4);
              *(double *)(v32 + 8 * v16) = v57 + *(double *)(v32 + 8 * v16);
              v26 = (double *)(*(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v7 + 4) + 8 * v16 + 8);
            }
            v27 = v58 + *v26;
          }
          else
          {
            if ( v7 <= v16 )
            {
              *(double *)(*(_DWORD *)(v21 + 4 * v16) + 8 * v7) = *(double *)(*(_DWORD *)(v21 + 4 * v16) + 8 * v7) - v17;
              v28 = (double *)(*(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v16) + 8 * v7 + 8);
              *v28 = *v28 - v57;
              v29 = *(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v16 + 4);
              *(double *)(v29 + 8 * v7) = *(double *)(v29 + 8 * v7) - v55;
              v30 = *(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v16 + 4);
              v25 = *(double *)(v30 + 8 * v7 + 8);
              v26 = (double *)(v30 + 8 * v7 + 8);
            }
            else
            {
              *(double *)(*(_DWORD *)(v21 + 4 * v7) + 8 * v16) = *(double *)(*(_DWORD *)(v21 + 4 * v7) + 8 * v16) - v17;
              v22 = (double *)(*(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v7) + 8 * v16 + 8);
              *v22 = *v22 - v55;
              v23 = *(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v7 + 4);
              *(double *)(v23 + 8 * v16) = *(double *)(v23 + 8 * v16) - v57;
              v24 = *(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v7 + 4);
              v25 = *(double *)(v24 + 8 * v16 + 8);
              v26 = (double *)(v24 + 8 * v16 + 8);
            }
            v27 = v25 - v58;
          }
          *v26 = v27;
          ++v2;
          v12 += 136;
        }
        while ( v2 < *(_DWORD *)(this + 568) );
        v2 = v47;
      }
      v35 = 0;
      if ( *(int *)(this + 576) > 0 )
      {
        v36 = 0;
        do
        {
          v37 = *(_DWORD *)(this + 580);
          v38 = v53 * *(double *)(v37 + v36 + 40);
          v39 = v36 + v37;
          v40 = *(_DWORD *)(v39 + 48);
          v41 = (v52 * *(double *)(v39 + 32) - v53 * *(double *)(v39 + 24)) * *(double *)(v39 + 80)
              + (v54 * *(double *)(v39 + 24) - v52 * *(double *)(v39 + 40)) * *(double *)(v39 + 72)
              + (v38 - v54 * *(double *)(v39 + 32)) * *(double *)(v39 + 64);
          v42 = (v51 * *(double *)(v39 + 24) - v49 * *(double *)(v39 + 40)) * *(double *)(v39 + 72)
              + (v49 * *(double *)(v39 + 32) - v50 * *(double *)(v39 + 24)) * *(double *)(v39 + 80);
          v43 = (v50 * *(double *)(v39 + 40) - v51 * *(double *)(v39 + 32)) * *(double *)(v39 + 64);
          v20 = v8 == *(_BYTE *)(v39 + 52);
          v44 = *(_DWORD *)(this + 556);
          v56 = v42 + v43;
          if ( v20 )
          {
            if ( v7 <= v40 )
            {
              *(double *)(*(_DWORD *)(v44 + 4 * v40) + 8 * v7) = v41 + *(double *)(*(_DWORD *)(v44 + 4 * v40) + 8 * v7);
              v45 = (double *)(*(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v40) + 8 * v7 + 8);
            }
            else
            {
              *(double *)(*(_DWORD *)(v44 + 4 * v7) + 8 * v40) = v41 + *(double *)(*(_DWORD *)(v44 + 4 * v7) + 8 * v40);
              v45 = (double *)(*(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v7 + 4) + 8 * v40);
            }
            v46 = v56 + *v45;
          }
          else
          {
            if ( v7 <= v40 )
            {
              *(double *)(*(_DWORD *)(v44 + 4 * v40) + 8 * v7) = *(double *)(*(_DWORD *)(v44 + 4 * v40) + 8 * v7) - v41;
              v45 = (double *)(*(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v40) + 8 * v7 + 8);
            }
            else
            {
              *(double *)(*(_DWORD *)(v44 + 4 * v7) + 8 * v40) = *(double *)(*(_DWORD *)(v44 + 4 * v7) + 8 * v40) - v41;
              v45 = (double *)(*(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v7 + 4) + 8 * v40);
            }
            v46 = *v45 - v56;
          }
          *v45 = v46;
          ++v35;
          v36 += 88;
        }
        while ( v35 < *(_DWORD *)(this + 576) );
        v2 = v47;
      }
      result = *(_DWORD *)(this + 568);
      v3 = v48 + 136;
      ++v2;
      v48 += 136;
      v47 = v2;
    }
    while ( v2 - 1 < result );
  }
  return result;
}
