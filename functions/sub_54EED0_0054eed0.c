int __thiscall sub_54EED0(_DWORD *this, int a2, _DWORD *a3, int a4)
{
  int result; // eax
  float *v6; // edi
  float *v7; // eax
  float *v8; // ecx
  int v9; // esi
  int v10; // eax
  int v11; // edx
  _DWORD *v12; // ecx
  float *v13; // esi
  double v14; // st7
  double v15; // st7
  double v16; // st7
  double v17; // st7
  __int16 v18; // ax
  float v19; // ecx
  float v20; // edx
  float v21; // ecx
  double v22; // st7
  double v23; // st6
  double v24; // st5
  bool v25; // cc
  _DWORD *v26; // [esp+20h] [ebp-70h]
  float v27; // [esp+24h] [ebp-6Ch]
  int v28; // [esp+24h] [ebp-6Ch]
  int v29; // [esp+28h] [ebp-68h]
  float v30; // [esp+2Ch] [ebp-64h]
  double v31; // [esp+2Ch] [ebp-64h]
  int v32; // [esp+34h] [ebp-5Ch]
  int v33; // [esp+38h] [ebp-58h]
  float v34; // [esp+3Ch] [ebp-54h] BYREF
  float v35; // [esp+40h] [ebp-50h]
  float v36; // [esp+44h] [ebp-4Ch]
  float v37; // [esp+48h] [ebp-48h] BYREF
  float v38; // [esp+4Ch] [ebp-44h]
  float v39; // [esp+50h] [ebp-40h]
  float v40[3]; // [esp+54h] [ebp-3Ch] BYREF
  float *v41[3]; // [esp+60h] [ebp-30h] BYREF
  _BYTE v42[12]; // [esp+6Ch] [ebp-24h] BYREF
  _DWORD v43[3]; // [esp+78h] [ebp-18h] BYREF
  _BYTE v44[12]; // [esp+84h] [ebp-Ch] BYREF

  result = 0;
  v33 = a3[75];
  v6 = (float *)a3[73];
  v29 = 0;
  v32 = 0;
  if ( (int)a3[72] > 0 )
  {
    while ( 1 )
    {
      (*(void (__cdecl **)(int, unsigned __int16 *, float *, int))(*(_DWORD *)dword_8B8F24 + 4))(
        dword_8B8F24,
        (unsigned __int16 *)v6 + 8,
        &v34,
        a2 + 276);
      v7 = (float *)this[129];
      v8 = (float *)this[120];
      v40[0] = v7[58] - v34;
      v40[1] = v7[59] - v35;
      v40[2] = v7[60] - v36;
      v27 = v6[7] + *v8;
      if ( v27 * v27 >= ((double (__thiscall *)(int, float *, float *))*(_DWORD *)(*(_DWORD *)dword_8B8F24 + 32))(
                          dword_8B8F24,
                          v40,
                          v40) )
      {
        v9 = *((_DWORD *)v6 + 2);
        (*(void (__cdecl **)(int, int, _BYTE *, int))(*(_DWORD *)dword_8B8F24 + 4))(
          dword_8B8F24,
          *(_DWORD *)(v9 + 12) + 48 * *(unsigned __int16 *)v6,
          v42,
          a2 + 416);
        (*(void (__cdecl **)(int, int, _DWORD *, int))(*(_DWORD *)dword_8B8F24 + 4))(
          dword_8B8F24,
          *(_DWORD *)(v9 + 12) + 48 * *((unsigned __int16 *)v6 + 1),
          v43,
          a2 + 416);
        (*(void (__cdecl **)(int, int, _BYTE *, int))(*(_DWORD *)dword_8B8F24 + 4))(
          dword_8B8F24,
          *(_DWORD *)(v9 + 12) + 48 * *((unsigned __int16 *)v6 + 2),
          v44,
          a2 + 416);
        v41[0] = (float *)v42;
        v10 = this[120];
        v41[2] = (float *)v44;
        v11 = *(_DWORD *)(v10 + 4);
        v41[1] = (float *)v43;
        v12 = *(_DWORD **)(v10 + 8);
        v26 = v12;
        v28 = 0;
        if ( v11 > 0 )
          break;
      }
LABEL_19:
      v6 += 9;
      if ( ++v32 >= a3[72] )
        return v29;
    }
    v13 = (float *)(v12 + 6);
    while ( 1 )
    {
      if ( *v12 == 6 )
        goto LABEL_18;
      (**(void (__cdecl ***)(int, int, float *, int))dword_8B8F24)(
        dword_8B8F24,
        v33 + 16 * *((_DWORD *)v6 + 3),
        &v34,
        a2 + 276);
      v6[8] = ((double (__thiscall *)(int, float *, _BYTE *))*(_DWORD *)(*(_DWORD *)dword_8B8F24 + 32))(
                dword_8B8F24,
                &v34,
                v42);
      v14 = ((double (__thiscall *)(int, float *, float *))*(_DWORD *)(*(_DWORD *)dword_8B8F24 + 32))(
              dword_8B8F24,
              &v34,
              v13 - 2);
      v30 = v14;
      if ( v14 <= v6[8] )
        goto LABEL_18;
      v15 = ((double (__thiscall *)(int, float *, float *))*(_DWORD *)(*(_DWORD *)dword_8B8F24 + 32))(
              dword_8B8F24,
              &v34,
              v13 + 4);
      if ( v15 >= v6[8] )
        goto LABEL_18;
      v16 = (v6[8] - v30) / (v15 - v30);
      v37 = (v13[4] - *(v13 - 2)) * v16 + *(v13 - 2);
      v38 = (v13[5] - *(v13 - 1)) * v16 + *(v13 - 1);
      v39 = (v13[6] - *v13) * v16 + *v13;
      v17 = fabs(v34);
      v31 = fabs(v35);
      if ( v17 <= v31 )
        break;
      if ( v17 <= fabs(v36) )
        goto LABEL_14;
      v18 = v34 <= 0.0;
LABEL_16:
      *((_WORD *)v6 + 3) = v18;
      if ( F_2D3DTrianglePointTest(v18, v41, &v37) )
      {
        *v26 = 1;
        *((_DWORD *)v13 + 9) = a2;
        *((_DWORD *)v13 + 10) = a3;
        v13[8] = 0.0;
        *((_DWORD *)v13 + 7) = this;
        v13[11] = *(float *)(*((_DWORD *)v6 + 2) + 4);
        v13[14] = 0.0;
        v19 = v37;
        *((_DWORD *)v13 + 12) = v28;
        v20 = v38;
        v13[19] = v19;
        v21 = v39;
        v13[20] = v20;
        v13[21] = v21;
        *((_DWORD *)v13 + 13) = v6;
        v13[16] = v34;
        v13[17] = v35;
        v13[18] = v36;
        v22 = v13[4] - v37;
        v23 = v13[5] - v38;
        v24 = v13[6] - v39;
        ++v29;
        v13[22] = sqrt(v24 * v24 + v23 * v23 + v22 * v22);
        SingleFunctionCallWrapper_9a30(v13 + 7);
      }
LABEL_18:
      v12 = v26 + 29;
      v13 += 29;
      v25 = v28 + 1 < *(_DWORD *)(this[120] + 4);
      v26 += 29;
      ++v28;
      if ( !v25 )
        goto LABEL_19;
    }
    if ( fabs(v36) < v31 )
    {
      v18 = 2;
      if ( v35 <= 0.0 )
        v18 = 3;
      goto LABEL_16;
    }
LABEL_14:
    v18 = 4;
    if ( v36 <= 0.0 )
      v18 = 5;
    goto LABEL_16;
  }
  return result;
}
