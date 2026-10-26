int __thiscall sub_5A06B0(_DWORD *this, int a2, _DWORD *a3, int a4)
{
  int result; // eax
  float *v6; // edi
  float *v7; // eax
  float *v8; // ecx
  int v9; // esi
  int v10; // eax
  int v11; // edx
  _BYTE *v12; // ecx
  float *v13; // esi
  double v14; // st7
  float *v15; // ebx
  double v16; // st7
  double v17; // st6
  __int16 v18; // ax
  double v19; // st6
  double v20; // st7
  float v21; // ecx
  float v22; // edx
  float v23; // ecx
  double v24; // st6
  double v25; // st5
  bool v26; // cc
  float v27; // [esp+20h] [ebp-74h]
  _DWORD *v28; // [esp+24h] [ebp-70h]
  float v29; // [esp+28h] [ebp-6Ch]
  int v30; // [esp+28h] [ebp-6Ch]
  int v31; // [esp+2Ch] [ebp-68h]
  int v32; // [esp+30h] [ebp-64h]
  int v33; // [esp+34h] [ebp-60h]
  double v34; // [esp+38h] [ebp-5Ch]
  float v35; // [esp+40h] [ebp-54h] BYREF
  float v36; // [esp+44h] [ebp-50h]
  float v37; // [esp+48h] [ebp-4Ch]
  float v38; // [esp+4Ch] [ebp-48h] BYREF
  float v39; // [esp+50h] [ebp-44h]
  float v40; // [esp+54h] [ebp-40h]
  float v41[3]; // [esp+58h] [ebp-3Ch] BYREF
  float *v42[3]; // [esp+64h] [ebp-30h] BYREF
  _BYTE v43[12]; // [esp+70h] [ebp-24h] BYREF
  _DWORD v44[3]; // [esp+7Ch] [ebp-18h] BYREF
  _BYTE v45[12]; // [esp+88h] [ebp-Ch] BYREF

  result = 0;
  v33 = a3[75];
  v6 = (float *)a3[73];
  v31 = 0;
  v32 = 0;
  if ( (int)a3[72] > 0 )
  {
    while ( 1 )
    {
      (*(void (__cdecl **)(int, unsigned __int16 *, float *, int))(*(_DWORD *)dword_7E8E58 + 4))(
        dword_7E8E58,
        (unsigned __int16 *)v6 + 8,
        &v35,
        a2 + 276);
      v7 = (float *)this[129];
      v8 = (float *)this[120];
      v41[0] = v7[58] - v35;
      v41[1] = v7[59] - v36;
      v41[2] = v7[60] - v37;
      v29 = v6[7] + *v8;
      if ( v29 * v29 >= ((double (__thiscall *)(int, float *, float *))*(_DWORD *)(*(_DWORD *)dword_7E8E58 + 32))(
                          dword_7E8E58,
                          v41,
                          v41) )
      {
        v9 = *((_DWORD *)v6 + 2);
        (*(void (__cdecl **)(int, int, _BYTE *, int))(*(_DWORD *)dword_7E8E58 + 4))(
          dword_7E8E58,
          *(_DWORD *)(v9 + 12) + 48 * *(unsigned __int16 *)v6,
          v43,
          a2 + 416);
        (*(void (__cdecl **)(int, int, _DWORD *, int))(*(_DWORD *)dword_7E8E58 + 4))(
          dword_7E8E58,
          *(_DWORD *)(v9 + 12) + 48 * *((unsigned __int16 *)v6 + 1),
          v44,
          a2 + 416);
        (*(void (__cdecl **)(int, int, _BYTE *, int))(*(_DWORD *)dword_7E8E58 + 4))(
          dword_7E8E58,
          *(_DWORD *)(v9 + 12) + 48 * *((unsigned __int16 *)v6 + 2),
          v45,
          a2 + 416);
        v42[0] = (float *)v43;
        v10 = this[120];
        v42[2] = (float *)v45;
        v11 = *(_DWORD *)(v10 + 4);
        v42[1] = (float *)v44;
        v12 = *(_BYTE **)(v10 + 8);
        v28 = v12;
        v30 = 0;
        if ( v11 > 0 )
          break;
      }
LABEL_19:
      v6 += 9;
      if ( ++v32 >= a3[72] )
        return v31;
    }
    v13 = (float *)(v12 + 24);
    while ( 1 )
    {
      if ( (*v12 & 6) != 0 )
        goto LABEL_18;
      (**(void (__cdecl ***)(int, int, float *, int))dword_7E8E58)(
        dword_7E8E58,
        v33 + 16 * *((_DWORD *)v6 + 3),
        &v35,
        a2 + 276);
      v6[8] = ((double (__thiscall *)(int, float *, _BYTE *))*(_DWORD *)(*(_DWORD *)dword_7E8E58 + 32))(
                dword_7E8E58,
                &v35,
                v43);
      v14 = ((double (__thiscall *)(int, float *, float *))*(_DWORD *)(*(_DWORD *)dword_7E8E58 + 32))(
              dword_7E8E58,
              &v35,
              v13 - 2);
      v27 = v14;
      if ( v14 <= v6[8] )
        goto LABEL_18;
      v15 = v13 + 4;
      v16 = ((double (__thiscall *)(int, float *, float *))*(_DWORD *)(*(_DWORD *)dword_7E8E58 + 32))(
              dword_7E8E58,
              &v35,
              v13 + 4);
      if ( v16 >= v6[8] )
        goto LABEL_18;
      v17 = fabs(v35);
      v34 = fabs(v36);
      if ( v17 <= v34 )
        break;
      if ( v17 <= fabs(v37) )
        goto LABEL_14;
      v18 = v35 <= 0.0;
LABEL_16:
      v19 = v6[8];
      *((_WORD *)v6 + 3) = v18;
      v20 = (v19 - v27) / (v16 - v27);
      v38 = (*v15 - *(v13 - 2)) * v20 + *(v13 - 2);
      v39 = (v13[5] - *(v13 - 1)) * v20 + *(v13 - 1);
      v40 = (v13[6] - *v13) * v20 + *v13;
      if ( sub_5A0320(v18, v42, &v38) )
      {
        *v28 = 1;
        *((_DWORD *)v13 + 9) = a2;
        *((_DWORD *)v13 + 10) = a3;
        v13[8] = 0.0;
        *((_DWORD *)v13 + 7) = this;
        v13[11] = *(float *)(*((_DWORD *)v6 + 2) + 4);
        v13[14] = 0.0;
        v21 = v38;
        *((_DWORD *)v13 + 12) = v30;
        v22 = v39;
        v13[19] = v21;
        v23 = v40;
        v13[20] = v22;
        v13[21] = v23;
        *((_DWORD *)v13 + 13) = v6;
        v13[16] = v35;
        v13[17] = v36;
        v13[18] = v37;
        v24 = v13[5] - v39;
        v25 = v13[6] - v40;
        ++v31;
        v13[22] = sqrt(v25 * v25 + v24 * v24 + (*v15 - v38) * (*v15 - v38));
        sub_5B19D0(v13 + 7);
      }
LABEL_18:
      v12 = v28 + 29;
      v13 += 29;
      v26 = v30 + 1 < *(_DWORD *)(this[120] + 4);
      v28 += 29;
      ++v30;
      if ( !v26 )
        goto LABEL_19;
    }
    if ( fabs(v37) < v34 )
    {
      v18 = 2;
      if ( v36 <= 0.0 )
        v18 = 3;
      goto LABEL_16;
    }
LABEL_14:
    v18 = 4;
    if ( v37 <= 0.0 )
      v18 = 5;
    goto LABEL_16;
  }
  return result;
}
