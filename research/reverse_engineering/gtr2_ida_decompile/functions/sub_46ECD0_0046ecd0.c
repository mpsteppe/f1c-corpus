void __thiscall sub_46ECD0(float *this, float a2)
{
  float *v2; // ebx
  double v3; // st7
  int v4; // eax
  double v5; // st7
  float *v6; // esi
  double v7; // st7
  double v8; // st7
  char *v9; // edi
  double v10; // st7
  double v11; // st7
  double v12; // st6
  double v13; // st6
  double v14; // st7
  double v15; // st7
  float v16; // [esp+8h] [ebp-BCh]
  float v17; // [esp+8h] [ebp-BCh]
  float v18; // [esp+8h] [ebp-BCh]
  float v19; // [esp+8h] [ebp-BCh]
  float v20; // [esp+Ch] [ebp-B8h]
  float v21; // [esp+10h] [ebp-B4h]
  float v22; // [esp+18h] [ebp-ACh]
  float v23; // [esp+1Ch] [ebp-A8h]
  float v24; // [esp+1Ch] [ebp-A8h]
  float v25; // [esp+1Ch] [ebp-A8h]
  float v26; // [esp+20h] [ebp-A4h]
  float v27; // [esp+20h] [ebp-A4h]
  float v28; // [esp+20h] [ebp-A4h]
  float v29; // [esp+24h] [ebp-A0h]
  float v30; // [esp+28h] [ebp-9Ch]
  float v31; // [esp+28h] [ebp-9Ch]
  float v32; // [esp+2Ch] [ebp-98h]
  float v33; // [esp+2Ch] [ebp-98h]
  float v34; // [esp+30h] [ebp-94h]
  float v35; // [esp+30h] [ebp-94h]
  float v36; // [esp+34h] [ebp-90h]
  float v37; // [esp+38h] [ebp-8Ch]
  float v38; // [esp+44h] [ebp-80h]
  float v39; // [esp+48h] [ebp-7Ch]
  int v40; // [esp+50h] [ebp-74h]
  float v41; // [esp+54h] [ebp-70h]
  float v42; // [esp+58h] [ebp-6Ch]
  float v43; // [esp+5Ch] [ebp-68h]
  float v44; // [esp+60h] [ebp-64h]
  float v45; // [esp+64h] [ebp-60h]
  float v46; // [esp+68h] [ebp-5Ch]
  float v47; // [esp+68h] [ebp-5Ch]
  int v48; // [esp+70h] [ebp-54h]
  float v50; // [esp+78h] [ebp-4Ch]
  float v51; // [esp+88h] [ebp-3Ch]
  float v52; // [esp+8Ch] [ebp-38h]
  float v53; // [esp+94h] [ebp-30h]
  float v54; // [esp+98h] [ebp-2Ch]
  float v55; // [esp+A0h] [ebp-24h]
  float v56; // [esp+B0h] [ebp-14h]
  float v57; // [esp+BCh] [ebp-8h]
  float v58; // [esp+C8h] [ebp+4h]

  v2 = this;
  if ( (!dword_91E07C
     || *((_DWORD *)dword_91E07C + 1436) != 1
     || dword_91BF28 == dword_91BF40 && *(_DWORD *)(dword_91BF40 + 64)
     || byte_B711AC)
    && 0.0 == sub_592960(&dword_FB1EF8) )
  {
    v3 = (v2[393] + v2[394] + v2[395]) * 0.33333334;
    if ( v3 > 0.0 )
    {
      v48 = 0;
      if ( byte_B722FC )
      {
        v4 = sub_5E5670("REARVIEW", 0);
        v48 = v4;
        if ( v4 )
        {
          if ( (*(_BYTE *)v4 & 8) != 0 )
          {
            v41 = (float)(*(_DWORD *)(v4 + 120) - 2);
            v20 = (float)(*(_DWORD *)(v4 + 116) - 2);
            v44 = (double)*(int *)(v4 + 100) + v41 + 4.0;
            v21 = (double)*(int *)(v4 + 104) + v20 + 4.0;
          }
          else
          {
            v48 = 0;
          }
        }
      }
      v30 = v3;
      v58 = v30 * v2[397];
      v45 = v2[385] - v2[382];
      v46 = v2[386] - v2[383];
      v56 = v46;
      v5 = 1.0 - (1.0 - v2[372]) / flt_759E34;
      if ( v5 < 0.0 )
        v5 = 0.0;
      v40 = 0;
      v50 = v5 * v58 * 255.0;
      if ( *((int *)v2 + 370) > 0 )
      {
        v6 = v2 + 274;
        do
        {
          if ( !*(_DWORD *)v6 )
            goto LABEL_65;
          v7 = v6[3];
          v53 = v45 * v7;
          v54 = v56 * v7;
          v52 = v54 + v2[383];
          v8 = v50 * v6[4];
          if ( v8 == 0.0 )
            goto LABEL_65;
          if ( v8 >= 255.0 )
            v8 = 255.0;
          v9 = &byte_FFFFFF[0x1000000 * (unsigned int)(unsigned __int64)v8];
          if ( v6[3] != 0.0 )
            goto LABEL_25;
          v10 = v58;
          if ( v58 < 0.40000001 )
          {
            v10 = 0.40000001;
            goto LABEL_26;
          }
          if ( v58 > 1.0 )
LABEL_25:
            v10 = 1.0;
LABEL_26:
          v42 = v10 * (v6[2] * v2[371]) * 128.0;
          v51 = v53 + v2[382];
          v11 = v51 - v42 * 0.5;
          v47 = v52 - v42 * 0.5;
          if ( v11 >= (double)*((int *)v2 + 375) )
          {
            v55 = v11;
            v31 = 0.0;
            v38 = v11;
          }
          else
          {
            v12 = (double)*((int *)v2 + 375);
            v31 = (v12 - v11) / v42;
            v55 = v12;
            v38 = v12;
          }
          if ( (double)*((int *)v2 + 376) <= v47 )
          {
            v57 = v52 - v42 * 0.5;
            v39 = v57;
            v29 = 0.0;
          }
          else
          {
            v13 = (double)*((int *)v2 + 376);
            v29 = (v13 - v47) / v42;
            v57 = v13;
            v39 = v13;
          }
          v16 = v11 + v42;
          if ( (double)(*((_DWORD *)v2 + 375) + *((_DWORD *)v2 + 373)) >= v16 )
          {
            v36 = v11 + v42;
            v43 = 1.0;
          }
          else
          {
            v14 = (double)(*((_DWORD *)v2 + 375) + *((_DWORD *)v2 + 373));
            v43 = 1.0 - (v16 - v14) / v42;
            v36 = v14;
          }
          v17 = v47 + v42;
          if ( (double)(*((_DWORD *)v2 + 376) + *((_DWORD *)v2 + 374)) >= v17 )
          {
            v37 = v47 + v42;
            v22 = 1.0;
          }
          else
          {
            v15 = (double)(*((_DWORD *)v2 + 374) + *((_DWORD *)v2 + 376));
            v22 = 1.0 - (v17 - v15) / v42;
            v37 = v15;
          }
          if ( v48 && v36 > (double)v41 && v38 < (double)v44 && v37 > (double)v20 && v39 < (double)v21 )
          {
            if ( v39 < (double)v20 )
            {
              v23 = v22 - (v37 - v20) / v42;
              Concurrency::details::ExternalStatistics::MarkInactive(*(Concurrency::details::ExternalStatistics **)v6);
              sub_5EDF20(*(_DWORD *)v6, 0, v38, v39, 1.0, v31, v29, (int)v9);
              sub_5EDF20(*(_DWORD *)v6, 1, v55, v20, 1.0, v31, v23, (int)v9);
              sub_5EDF20(*(_DWORD *)v6, 2, v36, v20, 1.0, v43, v23, (int)v9);
              sub_5EDF20(*(_DWORD *)v6, 3, v36, v57, 1.0, v43, v29, (int)v9);
              sub_5EDDD0(dword_FB2790, 0);
            }
            if ( v38 < (double)v41 )
            {
              v18 = v43 - (v36 - v41) / v42;
              if ( v39 >= (double)v20 )
              {
                v32 = v39;
                v26 = v29;
              }
              else
              {
                v32 = v20;
                v26 = (v20 - v39) / v42 + v29;
              }
              if ( v37 <= (double)v21 )
              {
                v34 = v37;
                v24 = v22;
              }
              else
              {
                v34 = v21;
                v24 = v22 - (v37 - v21) / v42;
              }
              Concurrency::details::ExternalStatistics::MarkInactive(*(Concurrency::details::ExternalStatistics **)v6);
              sub_5EDF20(*(_DWORD *)v6, 0, v38, v32, 1.0, v31, v26, (int)v9);
              sub_5EDF20(*(_DWORD *)v6, 1, v55, v34, 1.0, v31, v24, (int)v9);
              sub_5EDF20(*(_DWORD *)v6, 2, v41, v34, 1.0, v18, v24, (int)v9);
              sub_5EDF20(*(_DWORD *)v6, 3, v41, v32, 1.0, v18, v26, (int)v9);
              sub_5EDDD0(dword_FB2790, 0);
            }
            if ( v36 > (double)v44 )
            {
              v19 = (v44 - v38) / v42 + v31;
              if ( v39 >= (double)v20 )
              {
                v33 = v39;
                v27 = v29;
              }
              else
              {
                v33 = v20;
                v27 = (v20 - v39) / v42 + v29;
              }
              if ( v37 <= (double)v21 )
              {
                v35 = v37;
                v25 = v22;
              }
              else
              {
                v35 = v21;
                v25 = v22 - (v37 - v21) / v42;
              }
              Concurrency::details::ExternalStatistics::MarkInactive(*(Concurrency::details::ExternalStatistics **)v6);
              sub_5EDF20(*(_DWORD *)v6, 0, v44, v33, 1.0, v19, v27, (int)v9);
              sub_5EDF20(*(_DWORD *)v6, 1, v44, v35, 1.0, v19, v25, (int)v9);
              sub_5EDF20(*(_DWORD *)v6, 2, v36, v35, 1.0, v43, v25, (int)v9);
              sub_5EDF20(*(_DWORD *)v6, 3, v36, v33, 1.0, v43, v27, (int)v9);
              sub_5EDDD0(dword_FB2790, 0);
            }
            if ( v37 <= (double)v21 )
              goto LABEL_64;
            v28 = (v21 - v39) / v42 + v29;
            Concurrency::details::ExternalStatistics::MarkInactive(*(Concurrency::details::ExternalStatistics **)v6);
            sub_5EDF20(*(_DWORD *)v6, 0, v38, v21, 1.0, v31, v28, (int)v9);
            sub_5EDF20(*(_DWORD *)v6, 1, v55, v37, 1.0, v31, v22, (int)v9);
            sub_5EDF20(*(_DWORD *)v6, 2, v36, v37, 1.0, v43, v22, (int)v9);
            sub_5EDF20(*(_DWORD *)v6, 3, v36, v21, 1.0, v43, v28, (int)v9);
          }
          else
          {
            Concurrency::details::ExternalStatistics::MarkInactive(*(Concurrency::details::ExternalStatistics **)v6);
            sub_5EDF20(*(_DWORD *)v6, 0, v38, v39, 1.0, v31, v29, (int)v9);
            sub_5EDF20(*(_DWORD *)v6, 1, v55, v37, 1.0, v31, v22, (int)v9);
            sub_5EDF20(*(_DWORD *)v6, 2, v36, v37, 1.0, v43, v22, (int)v9);
            sub_5EDF20(*(_DWORD *)v6, 3, v36, v57, 1.0, v43, v29, (int)v9);
          }
          sub_5EDDD0(dword_FB2790, 0);
LABEL_64:
          v2 = this;
LABEL_65:
          v6 += 6;
          ++v40;
        }
        while ( v40 < *((_DWORD *)v2 + 370) );
      }
    }
  }
}
