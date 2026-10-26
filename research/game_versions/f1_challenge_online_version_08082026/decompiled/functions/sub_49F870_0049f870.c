char __thiscall sub_49F870(_BYTE *this)
{
  int v1; // eax
  double v2; // st7
  int v3; // eax
  int v4; // esi
  int v5; // eax
  int *v6; // edi
  int v7; // edx
  double v8; // st7
  int v9; // ebp
  int v10; // eax
  int v11; // ebx
  int v12; // esi
  int v13; // eax
  float **v14; // eax
  float **v15; // edx
  float *i; // ecx
  int v17; // eax
  int v18; // ebx
  int v19; // edx
  float *v20; // ebp
  double v21; // st7
  double v22; // st7
  double v23; // st7
  int v24; // eax
  double v25; // st7
  int v26; // eax
  float **j; // esi
  LPVOID *v28; // edi
  char v29; // al
  int v31; // [esp+10h] [ebp-D4h] BYREF
  int v32; // [esp+14h] [ebp-D0h] BYREF
  float v33; // [esp+18h] [ebp-CCh]
  float **v34; // [esp+1Ch] [ebp-C8h] BYREF
  int v35; // [esp+20h] [ebp-C4h]
  float **v36; // [esp+24h] [ebp-C0h]
  int v37; // [esp+28h] [ebp-BCh]
  int v38; // [esp+2Ch] [ebp-B8h]
  float v39; // [esp+30h] [ebp-B4h]
  float v40; // [esp+34h] [ebp-B0h]
  int v41; // [esp+38h] [ebp-ACh]
  _BYTE *v42; // [esp+3Ch] [ebp-A8h]
  int v43; // [esp+40h] [ebp-A4h]
  int v44; // [esp+44h] [ebp-A0h]
  int v45[7]; // [esp+48h] [ebp-9Ch] BYREF
  char v46[128]; // [esp+64h] [ebp-80h] BYREF

  LOBYTE(v1) = byte_7CE254;
  v42 = this;
  if ( !byte_7CE254 )
  {
    if ( dword_7CC49C )
      this[8] = this[8] == 0;
    if ( this[8] || (v1 = sub_461CD0(dword_7CD25C)) != 0 )
    {
      v33 = 0.0;
      if ( flt_5EA4E8 > 0.0 )
      {
        v32 = dword_5D6D64;
        v33 = sub_408490(&flt_5EA4E8) * (double)v32;
      }
      v32 = dword_5D6D64;
      *(float *)&v31 = sub_45BE00((float **)&dword_7CD204, 4) * (double)v32;
      v2 = (double)dword_5D6D64;
      *(float *)&v38 = COERCE_FLOAT(sub_587BDC(v2));
      v39 = COERCE_FLOAT(sub_587BDC(v2));
      v3 = sub_587BDC(v2 * 0.050000001);
      v4 = dword_5D6D60 - v3;
      v41 = v3;
      LODWORD(v40) = dword_5D6D60 - v3;
      v5 = sub_40CD60(&dword_5EA510);
      if ( v5 < 5 || (v33 = 350.0, v5 > 6) )
        v33 = 175.0;
      v32 = sub_40C910(&dword_5EA510);
      v34 = 0;
      v35 = 0;
      v36 = 0;
      v37 = 0;
      v6 = dword_5EF9A0;
      do
      {
        if ( *v6 != -1 )
        {
          if ( *v6 )
          {
            if ( (v6[1405] & 2) != 0 )
            {
              v7 = *(v6 - 2783);
              v8 = *((float *)v6 - 2784) + 1.25;
              v45[4] = *(v6 - 2785);
              *(float *)&v45[5] = v8;
              v45[6] = v7;
              if ( (unsigned __int8)sub_4DC960((int)v45, (int)&v31, v33) )
              {
                v9 = sub_587BDC(*(float *)v45);
                v10 = sub_587BDC(*(float *)&v45[1]);
                v11 = v10;
                if ( v9 > v41 && v9 < v4 && v10 > v38 && v10 < SLODWORD(v39) && *(float *)&v31 > 3.0 )
                {
                  v12 = sub_587C03(16);
                  *(_DWORD *)v12 = v6 - 3250;
                  *(float *)(v12 + 4) = *(float *)&v31;
                  *(_DWORD *)(v12 + 8) = v9;
                  *(_DWORD *)(v12 + 12) = v11;
                  v13 = sub_587C03(12);
                  if ( v13 )
                  {
                    *(_DWORD *)v13 = v12;
                    *(_DWORD *)(v13 + 4) = 0;
                    *(_BYTE *)(v13 + 8) = 1;
                  }
                  else
                  {
                    v13 = 0;
                  }
                  if ( v34 )
                  {
                    *(_DWORD *)(v35 + 4) = v13;
                  }
                  else
                  {
                    v34 = (float **)v13;
                    v36 = (float **)v13;
                  }
                  v4 = LODWORD(v40);
                  v35 = v13;
                  ++v37;
                }
              }
            }
          }
        }
        v6 += 4656;
      }
      while ( (int)v6 < (int)dword_7C87A0 );
      if ( !v37 )
        goto LABEL_30;
      v14 = (float **)sub_49FEB0(v34);
      v34 = v14;
      v15 = v14;
      if ( v14 )
      {
        for ( i = v14[1]; i; i = (float *)*((_DWORD *)i + 1) )
          v15 = (float **)i;
      }
      v35 = (int)v15;
      v36 = v14;
      v17 = sub_53D1F0(off_5CCC10);
      v18 = v17;
      if ( v17 )
      {
        v19 = *(_DWORD *)(v17 + 92);
        v43 = *(_DWORD *)(v17 + 96);
        v40 = (double)dword_5D6D60 * 0.00125;
        v44 = v19;
        v32 = v38;
        *(float *)&v31 = 0.0;
        v36 = v34;
        v39 = (double)dword_5D6D64 * 0.0016666667;
        if ( v34 )
        {
          v20 = *v34;
          if ( *v34 )
          {
            do
            {
              if ( v31 >= 3 || (double)dword_5D6D64 * 0.33399999 < (double)v32 )
                break;
              if ( v42[8] || sub_4624E0(dword_7CD25C, *(_DWORD *)(*(_DWORD *)v20 + 18580), -1.0) )
              {
                v21 = v20[1];
                v46[0] = 0;
                v22 = v21 / v33;
                *(float *)&v38 = v22;
                v23 = 0.55000001 - v22 * 0.33399999;
                *(float *)(v18 + 92) = v40 * v23;
                *(float *)(v18 + 96) = v23 * v39;
                if ( dword_7C56A4 == 7 && (v24 = *(_DWORD *)v20, *(int *)(*(_DWORD *)v20 + 16444) > 0) )
                {
                  if ( dword_7D0398 )
                    sub_58815F(
                      v46,
                      "%d %s (%d)",
                      *(_DWORD *)(v24 + 18192),
                      (const char *)(v24 + 18168),
                      *(_DWORD *)(v24 + 16480));
                  else
                    sub_58815F(v46, "%s", v24 + 18168);
                }
                else
                {
                  sub_58815F(v46, "%s", *(_DWORD *)v20 + 18168);
                }
                if ( sub_461CD0(dword_7CD25C) && *(_DWORD *)(*(_DWORD *)v20 + 13000) == 2 )
                {
                  v25 = sub_462530(dword_7CD25C, *(float *)(*(_DWORD *)v20 + 18580));
                  v26 = sub_587BDC(fabs(v25 * 1000.0));
                  LOBYTE(v45[0]) = 0;
                  sub_58815F(v45, " [%d ms]", v26);
                  strcat(v46, (const char *)v45);
                }
                sub_49B370(v20, (int)v46, &v32, v18, v38, v42[8] == 0);
                ++v31;
              }
              if ( !v36 )
                break;
              v36 = (float **)v36[1];
              if ( !v36 )
                break;
              v20 = *v36;
            }
            while ( *v36 );
          }
        }
        v1 = v43;
        *(_DWORD *)(v18 + 92) = v44;
        *(_DWORD *)(v18 + 96) = v1;
        for ( j = v34; j; LOBYTE(v1) = sub_587BCF(v28) )
        {
          v28 = (LPVOID *)j;
          v29 = *((_BYTE *)j + 8);
          j = (float **)j[1];
          if ( v29 )
            sub_587BCF(*v28);
        }
      }
      else
      {
LABEL_30:
        LOBYTE(v1) = sub_49AF30((int *)&v34);
      }
    }
  }
  return v1;
}
