_DWORD *__thiscall sub_59C3F0(int this, float a2)
{
  _DWORD *result; // eax
  int v4; // ebp
  _DWORD *v5; // edx
  int v6; // eax
  int v7; // ecx
  int v8; // ebx
  int v9; // edi
  float v10; // edx
  float v11; // eax
  int v12; // eax
  int v13; // eax
  double v14; // st7
  int v15; // ecx
  bool v16; // zf
  int v17; // edx
  _DWORD *v18; // ebx
  int v19; // edi
  int v20; // ebp
  int v21; // eax
  double v22; // st7
  int v23; // eax
  int v24; // eax
  bool v25; // cc
  float v26; // [esp+10h] [ebp-48h]
  float v27; // [esp+14h] [ebp-44h]
  float v28; // [esp+18h] [ebp-40h]
  float v29; // [esp+1Ch] [ebp-3Ch]
  float v30; // [esp+20h] [ebp-38h]
  float v31; // [esp+24h] [ebp-34h]
  int v32; // [esp+28h] [ebp-30h]
  int v33; // [esp+2Ch] [ebp-2Ch]
  int v34; // [esp+2Ch] [ebp-2Ch]
  int v35; // [esp+30h] [ebp-28h]
  int v36; // [esp+30h] [ebp-28h]
  int v37; // [esp+34h] [ebp-24h]
  float v38; // [esp+38h] [ebp-20h]
  int v39; // [esp+3Ch] [ebp-1Ch]
  int v40; // [esp+3Ch] [ebp-1Ch]
  float v41; // [esp+40h] [ebp-18h] BYREF
  float v42; // [esp+44h] [ebp-14h]
  float v43; // [esp+48h] [ebp-10h]
  float v44; // [esp+4Ch] [ebp-Ch] BYREF
  float v45; // [esp+50h] [ebp-8h]
  float v46; // [esp+54h] [ebp-4h]

  result = *(_DWORD **)(this + 316);
  v4 = 0;
  if ( result )
  {
    v5 = *(_DWORD **)(this + 316);
    v32 = (int)v5;
    while ( 1 )
    {
      if ( (v5[1] & 0x18000) == 0 )
        goto LABEL_73;
      v6 = *(_DWORD *)(this + 20);
      v31 = 1.0e12;
      v29 = 1.0e12;
      v27 = 1.0e12;
      v30 = -1.0e12;
      v28 = -1.0e12;
      v26 = -1.0e12;
      if ( ((unsigned int)&unk_800000 & v6) == 0 )
      {
        v39 = v5[6] + 4;
        v35 = 0;
        if ( *(int *)(this + 280) > 0 )
        {
          do
          {
            unknown_libname_158(v4 + *(_DWORD *)(this + 284), 4);
            v7 = *(_DWORD *)(this + 284);
            v8 = *(_DWORD *)(v7 + v4 + 12);
            v9 = *(_DWORD *)(v7 + v4 + 32);
            v33 = 0;
            if ( *(int *)(v7 + v4 + 8) > 0 )
            {
              do
              {
                (*(void (__cdecl **)(int, int, float *, int))(*(_DWORD *)dword_7E8E58 + 4))(dword_7E8E58, v8, &v44, v39);
                if ( v44 >= (double)v27 )
                {
                  if ( v44 > (double)v26 )
                    v26 = v44;
                }
                else
                {
                  v27 = v44;
                }
                if ( v45 >= (double)v29 )
                {
                  if ( v45 > (double)v28 )
                    v28 = v45;
                }
                else
                {
                  v29 = v45;
                }
                if ( v46 >= (double)v31 )
                {
                  if ( v46 > (double)v30 )
                    v30 = v46;
                }
                else
                {
                  v31 = v46;
                }
                v10 = v44;
                v11 = v45;
                *(float *)(v9 + 8) = v46;
                *(float *)v9 = v10;
                *(float *)(v9 + 4) = v11;
                (**(void (__cdecl ***)(int, int, int, int))dword_7E8E58)(dword_7E8E58, v8 + 12, v9 + 12, v39);
                *(_DWORD *)(v9 + 32) = *(_DWORD *)(v8 + 32);
                *(_DWORD *)(v9 + 36) = *(_DWORD *)(v8 + 36);
                v8 += 48;
                v9 += 64;
                ++v33;
              }
              while ( v33 < *(_DWORD *)(*(_DWORD *)(this + 284) + v4 + 8) );
            }
            v12 = *(_DWORD *)(*(_DWORD *)(this + 284) + v4);
            if ( (v12 & 2) != 0 )
            {
              sub_5B6930(LODWORD(a2));
            }
            else if ( (v12 & 1) != 0 )
            {
              sub_5B6060(LODWORD(a2));
            }
            else
            {
              sub_5B5F10(LODWORD(a2));
            }
            if ( (*(_DWORD *)(this + 20) & 0x400000) != 0 )
              sub_5B7170(v4 + *(_DWORD *)(this + 284));
            unknown_libname_159(v4 + *(_DWORD *)(this + 284), 4);
            v4 += 64;
            ++v35;
          }
          while ( v35 < *(_DWORD *)(this + 280) );
LABEL_71:
          v5 = (_DWORD *)v32;
          v4 = 0;
          goto LABEL_72;
        }
        goto LABEL_72;
      }
      if ( (v6 & 0x80010000) != 0 )
        break;
LABEL_43:
      v36 = 0;
      if ( *(int *)(this + 280) > 0 )
      {
        v37 = 0;
        do
        {
          unknown_libname_158(v4 + *(_DWORD *)(this + 284), 4);
          v17 = *(_DWORD *)(this + 284);
          v18 = *(_DWORD **)(v17 + v4 + 12);
          v19 = *(_DWORD *)(v17 + v4 + 32);
          v34 = 0;
          if ( *(int *)(v17 + v4 + 8) > 0 )
          {
            v40 = 0;
            do
            {
              v20 = 136 * (unsigned __int8)v18[6];
              (*(void (__cdecl **)(int, _DWORD *, float *, int))(*(_DWORD *)dword_7E8E58 + 4))(
                dword_7E8E58,
                v18,
                &v41,
                *(_DWORD *)(v32 + 24) + v20 + 4);
              if ( (*(_DWORD *)(this + 20) & 0x80010000) != 0 )
              {
                v21 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 324) + 12) + 284) + v37 + 12);
                v22 = *(float *)(v21 + v40);
                v23 = v40 + v21;
                v41 = (v22 - v41) * v38 + v41;
                v42 = (*(float *)(v23 + 4) - v42) * v38 + v42;
                v43 = (*(float *)(v23 + 8) - v43) * v38 + v43;
              }
              if ( v41 >= (double)v27 )
              {
                if ( v41 > (double)v26 )
                  v26 = v41;
              }
              else
              {
                v27 = v41;
              }
              if ( v42 >= (double)v29 )
              {
                if ( v42 > (double)v28 )
                  v28 = v42;
              }
              else
              {
                v29 = v42;
              }
              if ( v43 >= (double)v31 )
              {
                if ( v43 > (double)v30 )
                  v30 = v43;
              }
              else
              {
                v31 = v43;
              }
              *(float *)v19 = v41;
              *(float *)(v19 + 4) = v42;
              *(float *)(v19 + 8) = v43;
              (**(void (__cdecl ***)(int, int, int, int))dword_7E8E58)(
                dword_7E8E58,
                (int)(v18 + 7),
                v19 + 12,
                *(_DWORD *)(v32 + 24) + v20 + 4);
              *(_DWORD *)(v19 + 32) = v18[12];
              *(_DWORD *)(v19 + 36) = v18[13];
              v40 += 48;
              v18 += 16;
              v19 += 64;
              ++v34;
            }
            while ( v34 < *(_DWORD *)(v37 + *(_DWORD *)(this + 284) + 8) );
            v4 = v37;
          }
          v24 = *(_DWORD *)(*(_DWORD *)(this + 284) + v4);
          if ( (v24 & 2) != 0 )
          {
            sub_5B6930(LODWORD(a2));
          }
          else if ( (v24 & 1) != 0 )
          {
            sub_5B6060(LODWORD(a2));
          }
          else
          {
            sub_5B5F10(LODWORD(a2));
          }
          if ( (*(_DWORD *)(this + 20) & 0x400000) != 0 )
            sub_5B7170(v4 + *(_DWORD *)(this + 284));
          unknown_libname_159(v4 + *(_DWORD *)(this + 284), 4);
          v4 += 64;
          v25 = ++v36 < *(_DWORD *)(this + 280);
          v37 = v4;
        }
        while ( v25 );
        goto LABEL_71;
      }
LABEL_72:
      *(float *)(this + 28) = v26;
      *(float *)(this + 32) = v29;
      *(float *)(this + 220) = (v26 + v27) * 0.5;
      *(float *)(this + 36) = v31;
      *(float *)(this + 40) = v26;
      *(float *)(this + 44) = v29;
      *(float *)(this + 48) = v30;
      *(float *)(this + 224) = (v28 + v29) * 0.5;
      *(float *)(this + 52) = v27;
      *(float *)(this + 56) = v29;
      *(float *)(this + 60) = v30;
      *(float *)(this + 64) = v27;
      *(float *)(this + 228) = (v30 + v31) * 0.5;
      *(float *)(this + 68) = v29;
      *(float *)(this + 72) = v31;
      *(float *)(this + 76) = v26;
      *(float *)(this + 80) = v28;
      *(float *)(this + 84) = v31;
      *(float *)(this + 88) = v26;
      *(float *)(this + 92) = v28;
      *(float *)(this + 96) = v30;
      *(float *)(this + 100) = v27;
      *(float *)(this + 104) = v28;
      *(float *)(this + 108) = v30;
      *(float *)(this + 112) = v27;
      *(float *)(this + 116) = v28;
      *(float *)(this + 120) = v31;
      *(float *)(this + 24) = sqrt(
                                (v30 - v31) * 0.5 * ((v30 - v31) * 0.5)
                              + (v28 - v29) * 0.5 * ((v28 - v29) * 0.5)
                              + (v26 - v27) * 0.5 * ((v26 - v27) * 0.5));
LABEL_73:
      result = (_DWORD *)v5[9];
      v5[1] &= ~0x10000u;
      v32 = (int)result;
      if ( !result )
        return result;
      v5 = result;
    }
    if ( (v6 & 0x10000) != 0 )
    {
      v13 = *(_DWORD *)(this + 324);
      v14 = *(float *)(dword_7E8E5C + 244) + *(float *)(v13 + 8);
    }
    else
    {
      if ( v6 >= 0 )
        goto LABEL_36;
      v13 = *(_DWORD *)(this + 324);
      v14 = *(float *)(v13 + 8) - *(float *)(dword_7E8E5C + 244);
    }
    *(float *)(v13 + 8) = v14;
LABEL_36:
    v15 = *(_DWORD *)(this + 324);
    if ( *(float *)(v15 + 8) <= (double)*(float *)(v15 + 4) )
    {
      if ( *(float *)(v15 + 8) >= 0.0 )
      {
LABEL_42:
        v38 = *(float *)(*(_DWORD *)(this + 324) + 8) / *(float *)(*(_DWORD *)(this + 324) + 4);
        goto LABEL_43;
      }
    }
    else if ( *(_DWORD *)v15 != 1 )
    {
      v16 = *(_DWORD *)v15 == 2;
      *(_DWORD *)(v15 + 8) = *(_DWORD *)(v15 + 4);
      if ( !v16 )
        *(_DWORD *)(this + 20) = *(_DWORD *)(this + 20) & 0x7FFEFFFF | 0x80000000;
      goto LABEL_42;
    }
    *(_DWORD *)(v15 + 8) = 0;
    *(_DWORD *)(this + 20) &= 0x7FFEFFFFu;
    goto LABEL_42;
  }
  return result;
}
