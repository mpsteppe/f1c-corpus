// positive sp value has been detected, the output may be wrong!
int __userpurge sub_40214A@<eax>(
        __int32 a1@<ebx>,
        __int32 a2@<ebp>,
        int a3@<edi>,
        __int32 a4@<esi>,
        double a5@<st0>,
        float a6)
{
  int v6; // esi
  __int32 v7; // ebp
  float v8; // ecx
  float v9; // edx
  double v10; // st6
  double v11; // st7
  float v12; // edx
  double v13; // st6
  float *v14; // esi
  float v15; // ecx
  double v16; // st7
  int v17; // ecx
  int result; // eax
  unsigned int v19; // kr00_4
  __int32 v20; // ebp
  __int32 v21[3]; // [esp-6Ch] [ebp-7Ch] BYREF
  float v22; // [esp-60h] [ebp-70h]
  float v23; // [esp-5Ch] [ebp-6Ch]
  float v24; // [esp-58h] [ebp-68h]
  float v25; // [esp-54h] [ebp-64h]
  float v26; // [esp-50h] [ebp-60h]
  float v27; // [esp-4Ch] [ebp-5Ch]
  float v28; // [esp-48h] [ebp-58h]
  float v29; // [esp-44h] [ebp-54h]
  float v30; // [esp-40h] [ebp-50h]
  float v31; // [esp-3Ch] [ebp-4Ch]
  float v32; // [esp-38h] [ebp-48h]
  float v33; // [esp-34h] [ebp-44h]
  float v34; // [esp-30h] [ebp-40h]
  float v35; // [esp-2Ch] [ebp-3Ch]
  float v36; // [esp-28h] [ebp-38h]
  float v37; // [esp-24h] [ebp-34h]
  float v38; // [esp-14h] [ebp-24h]
  float v39; // [esp-10h] [ebp-20h]
  float v40; // [esp-Ch] [ebp-1Ch]
  float v41; // [esp-8h] [ebp-18h]
  float v42; // [esp-4h] [ebp-14h]
  float v43; // [esp+0h] [ebp-10h]
  float v44; // [esp+4h] [ebp-Ch]
  float v45; // [esp+8h] [ebp-8h]
  float v46; // [esp+Ch] [ebp-4h]

  while ( 1 )
  {
    sub_4018C0();
    sub_575AD0(*(float *)(a1 + 120), a1 + 124, *(float *)(a1 + 116), 16.0);
    v26 = a5;
    v21[2] = a2;
    sub_4018C0();
    sub_575AD0(*(float *)(a2 + 120), a2 + 124, *(float *)(a2 + 116), 16.0);
    v13 = v25 >= a5 ? a5 : v25;
    if ( v27 >= v13 )
    {
      if ( v25 < a5 )
        a5 = v25;
    }
    else
    {
      a5 = v27;
    }
    if ( a5 > v28 )
    {
      v28 = a5;
      v29 = v26;
    }
    v26 = v26 + 0.0099999998;
    if ( *(float *)(a4 + 28) + 0.050000001 <= v26 )
      break;
LABEL_24:
    v35 = v23 * *(float *)(a4 + 36);
    v32 = v35;
    v36 = v23 * *(float *)(a4 + 40);
    v33 = v36;
    v37 = v23 * *(float *)(a4 + 44);
    v34 = v37;
    v29 = v35 + *(float *)(a4 + 4);
    v30 = v36 + *(float *)(a4 + 8);
    v12 = v30;
    a5 = v37 + *(float *)(a4 + 12);
    *(float *)(a4 + 152) = v29;
    *(float *)(a4 + 156) = v12;
    v31 = a5;
    *(float *)(a4 + 160) = v31;
    sub_4018C0();
    sub_575AD0(*(float *)(a4 + 120), a4 + 124, *(float *)(a4 + 116), 16.0);
    v23 = a5;
  }
LABEL_11:
  v14 = (float *)(a4 + 152);
  v38 = v29 * *(v14 - 29);
  v41 = v38;
  v39 = v29 * *(v14 - 28);
  v42 = v39;
  v40 = v29 * *(v14 - 27);
  v43 = v40;
  v44 = v38 + *(v14 - 37);
  v45 = v39 + *(v14 - 36);
  v15 = v45;
  v16 = v40 + *(v14 - 35);
  *v14 = v44;
  v14[1] = v15;
  v46 = v16;
  v14[2] = v46;
  while ( 1 )
  {
    v17 = *(_DWORD *)(a3 + 312);
    result = LODWORD(v31) + 1;
    v31 = *(float *)&result;
    LODWORD(v30) += 320;
    if ( result >= v17 )
      return result;
    v6 = *(_DWORD *)(a3 + 316);
    a1 = *(_DWORD *)(v6 + LODWORD(v30) + 272);
    v7 = *(_DWORD *)(v6 + LODWORD(v30) + 276);
    a4 = LODWORD(v30) + v6;
    if ( a1 && v7 )
    {
      v21[1] = a4;
      sub_4018C0();
      v8 = *(float *)(a4 + 116);
      v9 = *(float *)(a4 + 120);
      v21[0] = v7;
      v19 = __readeflags();
      v20 = dword_16C6D7C + 71535873;
      __writeeflags(v19);
      a2 = _InterlockedExchange(v21, v20);
      sub_575AD0(v9, a4 + 124, v8, *(float *)v21);
      v26 = v16;
      v21[0] = a1;
      sub_4018C0();
      sub_575AD0(*(float *)(a1 + 120), a1 + 124, *(float *)(a1 + 116), 16.0);
      v23 = v16;
      sub_4018C0();
      sub_575AD0(*(float *)(a2 + 120), a2 + 124, *(float *)(a2 + 116), 16.0);
      if ( v22 >= v16 )
        v10 = v16;
      else
        v10 = v22;
      if ( v24 >= v10 )
      {
        if ( v22 >= v16 )
          v25 = v16;
        else
          v25 = v22;
      }
      else
      {
        v25 = v24;
      }
      v11 = *(float *)(a4 + 28) - 0.045000002;
      v26 = *(float *)(a4 + 28);
      v23 = v11;
      if ( *(float *)(a4 + 28) + 0.050000001 <= v23 )
        goto LABEL_11;
      goto LABEL_24;
    }
  }
}
