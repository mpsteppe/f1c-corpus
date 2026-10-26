int __thiscall sub_4F4090(int this, int a2)
{
  int v3; // eax
  int v4; // esi
  double v5; // st7
  int v6; // esi
  double v7; // st7
  bool v9; // zf
  int *v10; // esi
  int v11; // eax
  float *v12; // eax
  double v13; // st7
  int v14; // ebp
  float *v15; // eax
  int v16; // edx
  float v17; // ecx
  int v18; // edx
  float v19; // eax
  float *v20; // eax
  int v21; // edx
  float v22; // ecx
  int v23; // edx
  double v24; // st7
  double v25; // st7
  double v26; // st6
  int v27; // ecx
  int v28; // [esp+Ch] [ebp-D8h]
  float v29; // [esp+Ch] [ebp-D8h]
  float v30; // [esp+10h] [ebp-D4h]
  float v31; // [esp+10h] [ebp-D4h]
  float v32; // [esp+14h] [ebp-D0h]
  float v33; // [esp+14h] [ebp-D0h]
  int v34; // [esp+18h] [ebp-CCh] BYREF
  int v35; // [esp+1Ch] [ebp-C8h]
  float v36; // [esp+20h] [ebp-C4h]
  int v37; // [esp+24h] [ebp-C0h]
  float v38; // [esp+28h] [ebp-BCh]
  int v39; // [esp+2Ch] [ebp-B8h] BYREF
  float v40; // [esp+30h] [ebp-B4h]
  float v41; // [esp+34h] [ebp-B0h]
  float v42[3]; // [esp+3Ch] [ebp-A8h] BYREF
  float v43[3]; // [esp+48h] [ebp-9Ch] BYREF
  int v44[4]; // [esp+54h] [ebp-90h] BYREF
  float v45[16]; // [esp+64h] [ebp-80h] BYREF
  float v46[16]; // [esp+A4h] [ebp-40h] BYREF

  v3 = *(_DWORD *)(this + 28);
  switch ( v3 )
  {
    case 1:
      v4 = *(_DWORD *)(this + 32);
      if ( v4 && (unsigned __int8)sub_405250() )
      {
        v5 = 1.0 - *(double *)v4 / *(float *)(*(_DWORD *)(v4 + 60) + 20);
        *(float *)(this + 24) = 1.0 - v5 * v5;
        break;
      }
      *(_DWORD *)(this + 28) = 3;
      *(_DWORD *)(this + 32) = 0;
      goto LABEL_12;
    case 2:
      v6 = *(_DWORD *)(this + 32);
      if ( v6 && (unsigned __int8)sub_405250() )
      {
        v7 = 1.0 - *(double *)v6 / *(float *)(*(_DWORD *)(v6 + 60) + 20);
        *(float *)(this + 24) = v7 * v7;
      }
      else
      {
        *(_DWORD *)(this + 28) = 0;
        *(_DWORD *)(this + 24) = 0;
        *(_DWORD *)(this + 32) = 0;
      }
      break;
    case 3:
LABEL_12:
      *(_DWORD *)(this + 24) = 1065353216;
      break;
  }
  if ( *(float *)(this + 24) == 0.0 )
  {
    (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(this + 36) + 20))(*(_DWORD *)(this + 36), 0);
    return (*(int (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(this + 40) + 20))(*(_DWORD *)(this + 40), 0);
  }
  else
  {
    v9 = **(_DWORD **)(this + 20) == 5;
    v38 = 0.0;
    if ( !v9 )
      v38 = 3.1415927;
    v10 = *(int **)(this + 16);
    v11 = *v10;
    v36 = *(float *)(this + 56);
    sub_416420((float *)(v11 + 15952), (float *)(v11 + 15988), (float *)(this + 44), v43);
    sub_5D7810(v43, v42, v10 + 56);
    v12 = *(float **)(this + 20);
    v13 = v42[0] - v12[21];
    v12 += 21;
    *(float *)&v39 = v13;
    v28 = v39;
    v40 = v42[1] - v12[1];
    v30 = v40;
    v41 = v42[2] - v12[2];
    v32 = v41;
    sub_4F21D0((float *)&v39, 0.0, v38, v36);
    v14 = *(_DWORD *)(this + 12);
    qmemcpy(v45, (const void *)(v14 + 68), sizeof(v45));
    v15 = sub_4F1560((float *)v44, v45);
    v16 = *((_DWORD *)v15 + 1);
    v34 = *(_DWORD *)v15;
    v17 = v15[2];
    v35 = v16;
    v18 = *((_DWORD *)v15 + 3);
    v19 = *(float *)(this + 24);
    v36 = v17;
    v37 = v18;
    v20 = sub_4F2480((float *)&v34, (float *)v44, (float *)&v39, v19);
    v21 = *((_DWORD *)v20 + 1);
    v34 = *(_DWORD *)v20;
    v22 = v20[2];
    v35 = v21;
    v23 = *((_DWORD *)v20 + 3);
    v36 = v22;
    v37 = v23;
    sub_4F2340((float *)&v34, v46);
    v24 = *(float *)(this + 24);
    *(float *)&v39 = *(float *)&v28 * v24;
    v40 = v30 * v24;
    v25 = v24 * v32;
    v26 = 1.0 - *(float *)(this + 24);
    v29 = v45[12] * v26;
    v31 = v45[13] * v26;
    v33 = v45[14] * v26;
    v36 = v33 + v25;
    v46[14] = v36;
    v46[12] = v29 + *(float *)&v39;
    v46[13] = v31 + v40;
    sub_5C0560(v14, v46);
    v27 = *(_DWORD *)(this + 36);
    *(float *)(this + 60) = atan2(v45[4], v45[5]) - atan2(v46[4], v46[5]);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v27 + 20))(v27, 1);
    return (*(int (__thiscall **)(_DWORD, int))(**(_DWORD **)(this + 40) + 20))(*(_DWORD *)(this + 40), 1);
  }
}
