int __thiscall sub_401360(_DWORD *this, int a2)
{
  int v2; // esi
  int result; // eax
  int v4; // edi
  float *v5; // ebx
  int v6; // ecx
  float *v7; // ecx
  int v8; // eax
  double v9; // st7
  double v10; // st6
  double v11; // st5
  long double v12; // st7
  long double v13; // st7
  long double v14; // st7
  long double v15; // st6
  long double v16; // st5
  double v17; // st4
  double v18; // st3
  double v19; // st3
  double v20; // st2
  double v21; // st3
  long double v22; // st2
  double v23; // st7
  long double v24; // st7
  long double v25; // st7
  bool v26; // zf
  float v27; // [esp+40h] [ebp-D0h] BYREF
  float v28; // [esp+44h] [ebp-CCh]
  float v29; // [esp+48h] [ebp-C8h]
  float v30; // [esp+4Ch] [ebp-C4h]
  float v31; // [esp+50h] [ebp-C0h]
  float v32; // [esp+54h] [ebp-BCh]
  float v33; // [esp+58h] [ebp-B8h] BYREF
  float v34; // [esp+5Ch] [ebp-B4h]
  float v35; // [esp+60h] [ebp-B0h]
  float v36; // [esp+64h] [ebp-ACh] BYREF
  float v37; // [esp+68h] [ebp-A8h]
  float v38; // [esp+6Ch] [ebp-A4h]
  int v39; // [esp+70h] [ebp-A0h]
  float v40; // [esp+74h] [ebp-9Ch] BYREF
  float v41; // [esp+78h] [ebp-98h]
  float v42; // [esp+7Ch] [ebp-94h]
  float v43; // [esp+80h] [ebp-90h]
  float v44; // [esp+84h] [ebp-8Ch]
  float v45; // [esp+88h] [ebp-88h]
  int v46; // [esp+8Ch] [ebp-84h]
  int v47; // [esp+90h] [ebp-80h]
  float v48; // [esp+94h] [ebp-7Ch]
  float v49; // [esp+98h] [ebp-78h]
  float v50; // [esp+9Ch] [ebp-74h]
  float v51; // [esp+A0h] [ebp-70h]
  float v52; // [esp+A4h] [ebp-6Ch]
  float v53; // [esp+A8h] [ebp-68h]
  double v54; // [esp+ACh] [ebp-64h] BYREF
  double v55; // [esp+B4h] [ebp-5Ch]
  double v56; // [esp+BCh] [ebp-54h]
  int v57; // [esp+C4h] [ebp-4Ch]
  int v58; // [esp+C8h] [ebp-48h]
  int v59; // [esp+CCh] [ebp-44h]
  int v60; // [esp+D0h] [ebp-40h]
  double v61; // [esp+D4h] [ebp-3Ch]
  int v62; // [esp+DCh] [ebp-34h]
  _DWORD *v63; // [esp+E0h] [ebp-30h]
  int v64; // [esp+E4h] [ebp-2Ch]
  int v65; // [esp+E8h] [ebp-28h]
  int v66; // [esp+ECh] [ebp-24h]
  int v67; // [esp+F0h] [ebp-20h]
  int v68; // [esp+F4h] [ebp-1Ch]
  float v69; // [esp+100h] [ebp-10h]
  float v70; // [esp+10Ch] [ebp-4h]

  v2 = a2;
  v63 = this;
  v64 = 0;
  v65 = -1055066685;
  v66 = 0;
  if ( a2 )
    result = 1;
  else
    result = this[89];
  v4 = 0;
  if ( result > 0 )
  {
    v46 = 0;
    v47 = result;
    while ( 1 )
    {
      if ( !v2 )
        v2 = v46 + this[90];
      v5 = *(float **)(v2 + 296);
      v6 = *(_DWORD *)(v2 + 292);
      *(_DWORD *)(v2 + 164) = 0;
      *(_DWORD *)(v2 + 168) = 0;
      *(_DWORD *)(v2 + 172) = v64;
      *(_DWORD *)(v2 + 176) = v65;
      v67 = v6;
      *(_DWORD *)(v2 + 180) = v66;
      if ( v5 )
      {
        if ( v6 )
        {
          v39 = 0;
          v68 = 2 * (a2 == 0) + 1;
          if ( v68 > 0 )
          {
            while ( 1 )
            {
              if ( v39 )
              {
                if ( v39 == 1 )
                {
                  sub_5299C0(&v33, 0);
                  sub_5299C0(&v36, 0);
                  sub_5299C0(&v40, 0);
                }
                else if ( v39 == 2 )
                {
                  sub_5299C0(&v33, 1);
                  sub_5299C0(&v36, 1);
                  sub_5299C0(&v40, 1);
                }
              }
              else
              {
                v7 = (float *)(v6 + 196);
                v33 = *v7;
                v34 = v7[1];
                v35 = v7[2];
                v36 = *(float *)(v2 + 196);
                v37 = *(float *)(v2 + 200);
                v38 = *(float *)(v2 + 204);
                v40 = v5[49];
                v41 = v5[50];
                v42 = v5[51];
              }
              v54 = v33;
              v55 = v34;
              v56 = v35;
              v57 = 0;
              v58 = 1072693248;
              v59 = 0x40000000;
              v60 = 1201543096;
              v62 = v4;
              v8 = sub_44E900(&v54);
              v4 = v8;
              if ( v8 )
              {
                v34 = v61;
                v54 = v36;
                v55 = v37;
                v56 = v38;
                v57 = 0;
                v58 = 1072693248;
                v59 = 0x40000000;
                v60 = 1201543096;
                v62 = v8;
                v4 = sub_44E990(&v54, &v27);
                if ( v4 )
                {
                  v37 = v61;
                  v54 = v40;
                  v55 = v41;
                  v57 = 0;
                  v56 = v42;
                  v58 = 1072693248;
                  v59 = 0x40000000;
                  v60 = 1201543096;
                  v62 = v4;
                  v4 = sub_44E900(&v54);
                  if ( v4 )
                  {
                    v41 = v61;
                    v9 = v33 - v40;
                    v10 = v34 - v41;
                    v11 = v35 - v42;
                    if ( sqrt(v11 * v11 + v10 * v10 + v9 * v9) != 0.0 )
                    {
                      v43 = v28 * v11 - v29 * v10;
                      v30 = v43;
                      v44 = v29 * v9 - v27 * v11;
                      v31 = v44;
                      v45 = v27 * v10 - v28 * v9;
                      v32 = v45;
                      v12 = v45 * v45 + v44 * v44 + v43 * v43;
                      if ( sqrt(v12) != 0.0 )
                      {
                        v13 = 1.0 / sqrt(v12);
                        v30 = v43 * v13;
                        v31 = v31 * v13;
                        v14 = v13 * v32;
                        v15 = v31 * v29 - v14 * v28;
                        v16 = v14 * v27 - v29 * v30;
                        v17 = v28 * v30 - v31 * v27;
                        v18 = v29 * 0.0 + v28 * -9.8100004 + v27 * 0.0;
                        *(float *)(v2 + 172) = v14 * 0.0 + v31 * -9.8100004 + v30 * 0.0;
                        *(float *)(v2 + 176) = v18;
                        *(float *)(v2 + 180) = 0.0 * v17 + v16 * -9.8100004 + v15 * 0.0;
                        v19 = v33 - v36;
                        v20 = v34 - v37;
                        v69 = v35 - v38;
                        v51 = v14 * v69 + v31 * v20 + v19 * v30;
                        v52 = v29 * v69 + v28 * v20 + v19 * v27;
                        v53 = v69 * v17 + v20 * v16 + v19 * v15;
                        v21 = v40 - v36;
                        v70 = v42 - v38;
                        v22 = v14;
                        v23 = v41 - v37;
                        v48 = v22 * v70 + v31 * v23 + v21 * v30;
                        v49 = v29 * v70 + v28 * v23 + v21 * v27;
                        v50 = v70 * v17 + v23 * v16 + v21 * v15;
                        v24 = sub_4011A0(v52, v53, 0.0, 0.0, v49, v50);
                        *(float *)(v2 + 168) = v24;
                        if ( v52 + v49 > 0.0 )
                          *(float *)(v2 + 168) = -v24;
                        v25 = sub_4011A0(v51, v53, 0.0, 0.0, v48, v50);
                        if ( v51 + v48 < 0.0 )
                          v25 = -v25;
                        if ( v39 )
                        {
                          if ( v39 == 1 )
                          {
                            *(float *)(v2 + 240) = v25;
                          }
                          else if ( v39 == 2 )
                          {
                            *(float *)(v2 + 236) = v25;
                          }
                        }
                        else
                        {
                          *(float *)(v2 + 164) = v25;
                        }
                      }
                    }
                  }
                }
              }
              if ( ++v39 >= v68 )
                break;
              v6 = v67;
            }
          }
        }
      }
      result = v47 - 1;
      v26 = v47 == 1;
      v46 += 348;
      --v47;
      if ( v26 )
        break;
      v2 = a2;
      this = v63;
    }
  }
  return result;
}
