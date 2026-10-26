void __thiscall sub_4F5C10(int *this, int a2, float *a3, float *a4)
{
  float v6; // edx
  float v7; // eax
  float *v8; // edi
  double v9; // st7
  double v10; // st7
  long double v11; // st7
  double v13; // st6
  double v14; // st5
  double v15; // rt0
  int *v16; // esi
  int v17; // ecx
  int v18; // edx
  int v19; // eax
  int v20; // edx
  int v21; // eax
  int v22; // [esp+Ch] [ebp-50h]
  float v23; // [esp+Ch] [ebp-50h]
  float v25; // [esp+20h] [ebp-3Ch]
  float v26; // [esp+20h] [ebp-3Ch]
  float v27; // [esp+24h] [ebp-38h]
  float v28; // [esp+24h] [ebp-38h]
  float v29; // [esp+28h] [ebp-34h]
  float v30; // [esp+28h] [ebp-34h]
  float v31; // [esp+34h] [ebp-28h]
  float v32[9]; // [esp+38h] [ebp-24h] BYREF
  int v33; // [esp+60h] [ebp+4h]
  float v34; // [esp+60h] [ebp+4h]
  float v35; // [esp+64h] [ebp+8h]
  int v36; // [esp+64h] [ebp+8h]
  int v37; // [esp+68h] [ebp+Ch]
  float v38; // [esp+68h] [ebp+Ch]

  if ( sub_4DA2C0(&dword_7D5DA4) )
  {
    v6 = a3[1];
    v7 = a3[2];
    v8 = (float *)(a2 + 72);
    v32[0] = *a3;
    v9 = v32[0] - *(float *)(a2 + 72);
    v32[1] = v6;
    v32[2] = v7;
    v25 = v9;
    v27 = v6 - *(float *)(a2 + 76);
    v10 = v7 - *(float *)(a2 + 80);
    v29 = v10;
    v11 = v10 * v29 + v27 * v27 + v25 * v25;
    if ( v11 > 0.010000001 )
    {
      v13 = v29 * a4[1];
      v33 = 0xFFFFFF;
      v37 = 0xFFFFFF;
      v14 = v27 * a4[2];
      v22 = 0xFFFFFF;
      v32[8] = 2.3509886e-38;
      v31 = v27 * *a4 - v25 * a4[1];
      v35 = 1.0 / sqrt(v11) * *(float *)(a2 + 24);
      v15 = v25 * a4[2] - v29 * *a4;
      v26 = (v13 - v14) * v35;
      v32[3] = v26;
      v28 = v15 * v35;
      v32[4] = v28;
      v30 = v31 * v35;
      v32[5] = v30;
      if ( v11 < 400.0 )
      {
        v36 = 0;
        if ( this[14] > 0 )
        {
          v16 = this + 15;
          while ( 1 )
          {
            v17 = *v16;
            if ( *(_DWORD *)(*v16 + 4) == 6 )
              break;
            if ( *(_DWORD *)(*v16 + 4) == 7 )
            {
              v38 = *(float *)(a2 + 32) * 254.0;
              v20 = *(_DWORD *)(a2 + 112);
              v21 = ((int)v38 << 24) + 0xFFFFFF;
              *(_DWORD *)(a2 + 104) = v20;
              LODWORD(v32[8]) = v21;
              v37 = v21;
              if ( v20 == 0xFFFFFF && v21 == 0xFFFFFF )
                goto LABEL_17;
              goto LABEL_16;
            }
            if ( *(_DWORD *)(*v16 + 4) == 8 )
            {
              v23 = *(float *)(a2 + 36) * 63.5;
              v18 = *(_DWORD *)(a2 + 116);
              v19 = ((int)v23 << 24) + 0xFFFFFF;
              v22 = v19;
              goto LABEL_14;
            }
LABEL_17:
            ++v16;
            if ( ++v36 >= this[14] )
              goto LABEL_18;
          }
          v34 = *(float *)(a2 + 28) * 254.0;
          v18 = *(_DWORD *)(a2 + 108);
          v19 = ((int)v34 << 24) + 0xFFFFFF;
          v33 = v19;
LABEL_14:
          *(_DWORD *)(a2 + 104) = v18;
          LODWORD(v32[8]) = v19;
          if ( v18 == 0xFFFFFF && v19 == 0xFFFFFF )
            goto LABEL_17;
LABEL_16:
          sub_4F4D30(v17, (int)v8, (int)v32);
          goto LABEL_17;
        }
      }
LABEL_18:
      qmemcpy(v8, v32, 0x24u);
      *(_DWORD *)(a2 + 108) = v33;
      *(_DWORD *)(a2 + 112) = v37;
      *(_DWORD *)(a2 + 116) = v22;
    }
  }
}
