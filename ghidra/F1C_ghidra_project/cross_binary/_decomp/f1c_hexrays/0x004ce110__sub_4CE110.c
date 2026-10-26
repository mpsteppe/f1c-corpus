// f1c  0x004ce110  size=613
void __thiscall sub_4CE110(int *this, int a2, float *a3, float *a4)
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
  double v18; // st7
  int v19; // edx
  int v20; // eax
  int v21; // edx
  int v22; // eax
  int v23; // [esp+Ch] [ebp-48h]
  float v24; // [esp+Ch] [ebp-48h]
  float v26; // [esp+20h] [ebp-34h]
  float v27; // [esp+20h] [ebp-34h]
  float v28; // [esp+24h] [ebp-30h]
  float v29; // [esp+24h] [ebp-30h]
  float v30; // [esp+28h] [ebp-2Ch]
  float v31; // [esp+28h] [ebp-2Ch]
  float v32; // [esp+34h] [ebp-20h]
  float v33[7]; // [esp+38h] [ebp-1Ch] BYREF
  int v34; // [esp+58h] [ebp+4h]
  float v35; // [esp+58h] [ebp+4h]
  float v36; // [esp+5Ch] [ebp+8h]
  int v37; // [esp+5Ch] [ebp+8h]
  int v38; // [esp+60h] [ebp+Ch]
  float v39; // [esp+60h] [ebp+Ch]

  if ( sub_4B9FB0(&dword_8AB6E4) )
  {
    v6 = a3[1];
    v7 = a3[2];
    v8 = (float *)(a2 + 72);
    v33[0] = *a3;
    v9 = v33[0] - *(float *)(a2 + 72);
    v33[1] = v6;
    v33[2] = v7;
    v26 = v9;
    v28 = v6 - *(float *)(a2 + 76);
    v10 = v7 - *(float *)(a2 + 80);
    v30 = v10;
    v11 = v10 * v30 + v28 * v28 + v26 * v26;
    if ( v11 > 0.010000001 )
    {
      v13 = v30 * a4[1];
      v34 = 0xFFFFFF;
      v38 = 0xFFFFFF;
      v14 = v28 * a4[2];
      v23 = 0xFFFFFF;
      v33[6] = 2.3509886e-38;
      v32 = v28 * *a4 - v26 * a4[1];
      v36 = 1.0 / sqrt(v11) * *(float *)(a2 + 24);
      v15 = v26 * a4[2] - v30 * *a4;
      v27 = (v13 - v14) * v36;
      v33[3] = v27;
      v29 = v15 * v36;
      v33[4] = v29;
      v31 = v32 * v36;
      v33[5] = v31;
      if ( v11 < 400.0 )
      {
        v37 = 0;
        if ( this[15] > 0 )
        {
          v16 = this + 16;
          while ( 1 )
          {
            v17 = *v16;
            if ( *(_DWORD *)(*v16 + 4) == 6 )
              break;
            if ( *(_DWORD *)(*v16 + 4) == 7 )
            {
              v39 = *(float *)(a2 + 32) * 254.0;
              v18 = v39;
              v21 = *(_DWORD *)(a2 + 104);
              v22 = ((int)v39 << 24) + 0xFFFFFF;
              *(_DWORD *)(a2 + 96) = v21;
              LODWORD(v33[6]) = v22;
              v38 = v22;
              if ( v21 == 0xFFFFFF && v22 == 0xFFFFFF )
                goto LABEL_17;
              goto LABEL_16;
            }
            if ( *(_DWORD *)(*v16 + 4) == 8 )
            {
              v24 = *(float *)(a2 + 36) * 63.5;
              v18 = v24;
              v19 = *(_DWORD *)(a2 + 108);
              v20 = ((int)v24 << 24) + 0xFFFFFF;
              v23 = v20;
              goto LABEL_14;
            }
LABEL_17:
            ++v16;
            if ( ++v37 >= this[15] )
              goto LABEL_18;
          }
          v35 = *(float *)(a2 + 28) * 254.0;
          v18 = v35;
          v19 = *(_DWORD *)(a2 + 100);
          v20 = ((int)v35 << 24) + 0xFFFFFF;
          v34 = v20;
LABEL_14:
          *(_DWORD *)(a2 + 96) = v19;
          LODWORD(v33[6]) = v20;
          if ( v19 == 0xFFFFFF && v20 == 0xFFFFFF )
            goto LABEL_17;
LABEL_16:
          sub_4CD6C0(v17, v18, (int)v8, (int)v33);
          goto LABEL_17;
        }
      }
LABEL_18:
      qmemcpy(v8, v33, 0x1Cu);
      *(_DWORD *)(a2 + 100) = v34;
      *(_DWORD *)(a2 + 104) = v38;
      *(_DWORD *)(a2 + 108) = v23;
    }
  }
}
