_DWORD *__thiscall sub_54D9F0(int this)
{
  _DWORD *result; // eax
  int v3; // ebp
  _DWORD *v4; // edx
  int v5; // eax
  int v6; // ecx
  int v7; // ebx
  int v8; // edi
  float v9; // edx
  float v10; // eax
  int v11; // eax
  int v12; // eax
  double v13; // st7
  int v14; // ecx
  bool v15; // zf
  int v16; // edx
  _DWORD *v17; // ebx
  int v18; // edi
  int v19; // ebp
  int v20; // eax
  double v21; // st7
  int v22; // eax
  int v23; // eax
  bool v24; // cc
  float v25; // [esp+8h] [ebp-48h]
  float v26; // [esp+Ch] [ebp-44h]
  float v27; // [esp+10h] [ebp-40h]
  float v28; // [esp+14h] [ebp-3Ch]
  float v29; // [esp+18h] [ebp-38h]
  float v30; // [esp+1Ch] [ebp-34h]
  _DWORD *v31; // [esp+20h] [ebp-30h]
  int v32; // [esp+24h] [ebp-2Ch]
  int v33; // [esp+24h] [ebp-2Ch]
  int v34; // [esp+28h] [ebp-28h]
  int v35; // [esp+28h] [ebp-28h]
  int v36; // [esp+2Ch] [ebp-24h]
  float v37; // [esp+30h] [ebp-20h]
  int v38; // [esp+34h] [ebp-1Ch]
  int v39; // [esp+34h] [ebp-1Ch]
  float v40; // [esp+38h] [ebp-18h] BYREF
  float v41; // [esp+3Ch] [ebp-14h]
  float v42; // [esp+40h] [ebp-10h]
  float v43; // [esp+44h] [ebp-Ch] BYREF
  float v44; // [esp+48h] [ebp-8h]
  float v45; // [esp+4Ch] [ebp-4h]

  result = *(_DWORD **)(this + 316);
  v3 = 0;
  if ( result )
  {
    v4 = *(_DWORD **)(this + 316);
    v31 = v4;
    while ( 1 )
    {
      if ( (v4[1] & 0x18000) == 0 )
        goto LABEL_73;
      v5 = *(_DWORD *)(this + 20);
      v30 = 1.0e12;
      v28 = 1.0e12;
      v26 = 1.0e12;
      v29 = -1.0e12;
      v27 = -1.0e12;
      v25 = -1.0e12;
      if ( ((unsigned int)&unk_800000 & v5) == 0 )
      {
        v38 = v4[6] + 4;
        v34 = 0;
        if ( *(int *)(this + 280) > 0 )
        {
          do
          {
            sub_54E0E0(v3 + *(_DWORD *)(this + 284), 4);
            v6 = *(_DWORD *)(this + 284);
            v7 = *(_DWORD *)(v6 + v3 + 12);
            v8 = *(_DWORD *)(v6 + v3 + 32);
            v32 = 0;
            if ( *(int *)(v6 + v3 + 8) > 0 )
            {
              do
              {
                (*(void (__cdecl **)(int, int, float *, int))(*(_DWORD *)dword_8B8F24 + 4))(dword_8B8F24, v7, &v43, v38);
                if ( v43 >= (double)v26 )
                {
                  if ( v43 > (double)v25 )
                    v25 = v43;
                }
                else
                {
                  v26 = v43;
                }
                if ( v44 >= (double)v28 )
                {
                  if ( v44 > (double)v27 )
                    v27 = v44;
                }
                else
                {
                  v28 = v44;
                }
                if ( v45 >= (double)v30 )
                {
                  if ( v45 > (double)v29 )
                    v29 = v45;
                }
                else
                {
                  v30 = v45;
                }
                v9 = v43;
                v10 = v44;
                *(float *)(v8 + 8) = v45;
                *(float *)v8 = v9;
                *(float *)(v8 + 4) = v10;
                (**(void (__cdecl ***)(int, int, int, int))dword_8B8F24)(dword_8B8F24, v7 + 12, v8 + 12, v38);
                *(_DWORD *)(v8 + 32) = *(_DWORD *)(v7 + 32);
                *(_DWORD *)(v8 + 36) = *(_DWORD *)(v7 + 36);
                v7 += 48;
                v8 += 64;
                ++v32;
              }
              while ( v32 < *(_DWORD *)(*(_DWORD *)(this + 284) + v3 + 8) );
            }
            v11 = *(_DWORD *)(*(_DWORD *)(this + 284) + v3);
            if ( (v11 & 2) != 0 )
            {
              sub_55E320(0);
            }
            else if ( (v11 & 1) != 0 )
            {
              sub_55DA50(0);
            }
            else
            {
              sub_55D900(0);
            }
            if ( (*(_DWORD *)(this + 20) & 0x400000) != 0 )
              sub_55EB30(v3 + *(_DWORD *)(this + 284));
            sub_54E0F0(v3 + *(_DWORD *)(this + 284), 4);
            v3 += 64;
            ++v34;
          }
          while ( v34 < *(_DWORD *)(this + 280) );
LABEL_71:
          v4 = v31;
          v3 = 0;
          goto LABEL_72;
        }
        goto LABEL_72;
      }
      if ( (v5 & 0x80010000) != 0 )
        break;
LABEL_43:
      v35 = 0;
      if ( *(int *)(this + 280) > 0 )
      {
        v36 = 0;
        do
        {
          sub_54E0E0(v3 + *(_DWORD *)(this + 284), 4);
          v16 = *(_DWORD *)(this + 284);
          v17 = *(_DWORD **)(v16 + v3 + 12);
          v18 = *(_DWORD *)(v16 + v3 + 32);
          v33 = 0;
          if ( *(int *)(v16 + v3 + 8) > 0 )
          {
            v39 = 0;
            do
            {
              v19 = 136 * (unsigned __int8)v17[6];
              (*(void (__cdecl **)(int, _DWORD *, float *, int))(*(_DWORD *)dword_8B8F24 + 4))(
                dword_8B8F24,
                v17,
                &v40,
                v31[6] + v19 + 4);
              if ( (*(_DWORD *)(this + 20) & 0x80010000) != 0 )
              {
                v20 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 324) + 12) + 284) + v36 + 12);
                v21 = *(float *)(v20 + v39);
                v22 = v39 + v20;
                v40 = (v21 - v40) * v37 + v40;
                v41 = (*(float *)(v22 + 4) - v41) * v37 + v41;
                v42 = (*(float *)(v22 + 8) - v42) * v37 + v42;
              }
              if ( v40 >= (double)v26 )
              {
                if ( v40 > (double)v25 )
                  v25 = v40;
              }
              else
              {
                v26 = v40;
              }
              if ( v41 >= (double)v28 )
              {
                if ( v41 > (double)v27 )
                  v27 = v41;
              }
              else
              {
                v28 = v41;
              }
              if ( v42 >= (double)v30 )
              {
                if ( v42 > (double)v29 )
                  v29 = v42;
              }
              else
              {
                v30 = v42;
              }
              *(float *)v18 = v40;
              *(float *)(v18 + 4) = v41;
              *(float *)(v18 + 8) = v42;
              (**(void (__cdecl ***)(int, int, int, int))dword_8B8F24)(
                dword_8B8F24,
                (int)(v17 + 7),
                v18 + 12,
                v31[6] + v19 + 4);
              *(_DWORD *)(v18 + 32) = v17[12];
              *(_DWORD *)(v18 + 36) = v17[13];
              v39 += 48;
              v17 += 16;
              v18 += 64;
              ++v33;
            }
            while ( v33 < *(_DWORD *)(*(_DWORD *)(this + 284) + v36 + 8) );
            v3 = v36;
          }
          v23 = *(_DWORD *)(*(_DWORD *)(this + 284) + v3);
          if ( (v23 & 2) != 0 )
          {
            sub_55E320(0);
          }
          else if ( (v23 & 1) != 0 )
          {
            sub_55DA50(0);
          }
          else
          {
            sub_55D900(0);
          }
          if ( (*(_DWORD *)(this + 20) & 0x400000) != 0 )
            sub_55EB30(v3 + *(_DWORD *)(this + 284));
          sub_54E0F0(v3 + *(_DWORD *)(this + 284), 4);
          v3 += 64;
          v24 = ++v35 < *(_DWORD *)(this + 280);
          v36 = v3;
        }
        while ( v24 );
        goto LABEL_71;
      }
LABEL_72:
      *(float *)(this + 28) = v25;
      *(float *)(this + 32) = v28;
      *(float *)(this + 220) = (v25 + v26) * 0.5;
      *(float *)(this + 36) = v30;
      *(float *)(this + 40) = v25;
      *(float *)(this + 44) = v28;
      *(float *)(this + 48) = v29;
      *(float *)(this + 224) = (v27 + v28) * 0.5;
      *(float *)(this + 52) = v26;
      *(float *)(this + 56) = v28;
      *(float *)(this + 60) = v29;
      *(float *)(this + 64) = v26;
      *(float *)(this + 228) = (v29 + v30) * 0.5;
      *(float *)(this + 68) = v28;
      *(float *)(this + 72) = v30;
      *(float *)(this + 76) = v25;
      *(float *)(this + 80) = v27;
      *(float *)(this + 84) = v30;
      *(float *)(this + 88) = v25;
      *(float *)(this + 92) = v27;
      *(float *)(this + 96) = v29;
      *(float *)(this + 100) = v26;
      *(float *)(this + 104) = v27;
      *(float *)(this + 108) = v29;
      *(float *)(this + 112) = v26;
      *(float *)(this + 116) = v27;
      *(float *)(this + 120) = v30;
      *(float *)(this + 24) = sqrt(
                                (v29 - v30) * 0.5 * ((v29 - v30) * 0.5)
                              + (v27 - v28) * 0.5 * ((v27 - v28) * 0.5)
                              + (v25 - v26) * 0.5 * ((v25 - v26) * 0.5));
LABEL_73:
      result = (_DWORD *)v4[9];
      v4[1] &= ~0x10000u;
      v31 = result;
      if ( !result )
        return result;
      v4 = result;
    }
    if ( (v5 & 0x10000) != 0 )
    {
      v12 = *(_DWORD *)(this + 324);
      v13 = *(float *)(dword_8B8F28 + 240) + *(float *)(v12 + 8);
    }
    else
    {
      if ( v5 >= 0 )
        goto LABEL_36;
      v12 = *(_DWORD *)(this + 324);
      v13 = *(float *)(v12 + 8) - *(float *)(dword_8B8F28 + 240);
    }
    *(float *)(v12 + 8) = v13;
LABEL_36:
    v14 = *(_DWORD *)(this + 324);
    if ( *(float *)(v14 + 8) <= (double)*(float *)(v14 + 4) )
    {
      if ( *(float *)(v14 + 8) >= 0.0 )
      {
LABEL_42:
        v37 = *(float *)(*(_DWORD *)(this + 324) + 8) / *(float *)(*(_DWORD *)(this + 324) + 4);
        goto LABEL_43;
      }
    }
    else if ( *(_DWORD *)v14 != 1 )
    {
      v15 = *(_DWORD *)v14 == 2;
      *(_DWORD *)(v14 + 8) = *(_DWORD *)(v14 + 4);
      if ( !v15 )
        *(_DWORD *)(this + 20) = *(_DWORD *)(this + 20) & 0x7FFEFFFF | 0x80000000;
      goto LABEL_42;
    }
    *(_DWORD *)(v14 + 8) = 0;
    *(_DWORD *)(this + 20) &= 0x7FFEFFFFu;
    goto LABEL_42;
  }
  return result;
}
