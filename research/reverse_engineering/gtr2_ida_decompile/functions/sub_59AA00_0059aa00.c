char __userpurge sub_59AA00@<al>(int a1@<ecx>, int a2@<edi>, int a3, _DWORD *a4, float a5)
{
  unsigned int v6; // ecx
  signed int v7; // edx
  int v8; // eax
  unsigned int v9; // ecx
  int v10; // ecx
  char v12; // bl
  int v13; // [esp+Ch] [ebp-140h]
  float v14; // [esp+10h] [ebp-13Ch]
  float v15; // [esp+10h] [ebp-13Ch]
  float v16; // [esp+14h] [ebp-138h]
  float v17; // [esp+14h] [ebp-138h]
  float v18; // [esp+14h] [ebp-138h]
  float v19; // [esp+18h] [ebp-134h]
  float v20; // [esp+18h] [ebp-134h]
  float v21; // [esp+1Ch] [ebp-130h]
  float v22; // [esp+20h] [ebp-12Ch] BYREF
  float v23; // [esp+24h] [ebp-128h]
  float v24; // [esp+28h] [ebp-124h] BYREF
  float v25; // [esp+2Ch] [ebp-120h]
  float v26; // [esp+30h] [ebp-11Ch]
  float v27; // [esp+34h] [ebp-118h]
  _DWORD v28[3]; // [esp+44h] [ebp-108h] BYREF
  float v29[9]; // [esp+50h] [ebp-FCh] BYREF
  float v30[18]; // [esp+74h] [ebp-D8h] BYREF
  _BYTE v31[12]; // [esp+BCh] [ebp-90h] BYREF
  _BYTE v32[8]; // [esp+C8h] [ebp-84h] BYREF
  _BYTE v33[124]; // [esp+D0h] [ebp-7Ch] BYREF

  v6 = *(_DWORD *)(a1 + 856);
  if ( (v6 & 0xFC0000) != 0 )
  {
    sub_51B2A0(a4, v6 >> 29, (v6 >> 18) & 0x3F, (v6 >> 8) & 0x3FF, (unsigned __int8)v6, a3, 0);
    v23 = *(float *)(a1 + 12) - *(float *)(a1 + 860);
    if ( v23 == 0.0 )
    {
      v14 = 0.0;
      v16 = 1.0;
    }
    else
    {
      v14 = (*(float *)&a3 - *(float *)(a1 + 860)) / v23;
      v16 = 1.0 - v14;
    }
    v7 = (*(_DWORD *)(a1 + 22) & 0xFFC00000) + ((*(_DWORD *)(a1 + 18) >> 10) & 0x3FF000);
    v8 = *(_DWORD *)(a1 + 870);
    v9 = (v8 & 0xFFC00000) + ((*(_DWORD *)(a1 + 866) >> 10) & 0x3FF000);
    v24 = (double)(int)(*(_DWORD *)(a1 + 866) << 10) * 0.000015258789 * v16
        + (double)(int)(*(_DWORD *)(a1 + 18) << 10) * 0.000015258789 * v14;
    v13 = v9;
    v10 = *(_DWORD *)(a1 + 22) << 10;
    v25 = (double)v7 * 0.0000019073486 * v14 + (double)v13 * 0.0000019073486 * v16;
    v26 = (double)(v8 << 10) * 0.000015258789 * v16 + (double)v10 * 0.000015258789 * v14;
    sub_51A3B0((_DWORD *)((char *)a4 + 10), &v24);
    sub_51A6F0((int *)(a1 + 874));
    v17 = (double)*(__int16 *)(a1 + 884) * 0.0078125;
    v19 = (double)*(__int16 *)(a1 + 886) * 0.0078125;
    v21 = (double)*(__int16 *)(a1 + 888) * 0.0078125;
    sub_51A6F0((int *)(a1 + 26));
    sub_614CE0(v32, v29, v31, v33, a2);
    qmemcpy(v30, v29, 0x24u);
    v25 = v29[6] * v19 + v29[3] * v17 + v29[0] * v14;
    v26 = v29[7] * v19 + v29[4] * v17 + v29[1] * v14;
    v27 = v29[8] * v19 + v29[5] * v17 + v29[2] * v14;
    v15 = v25 * v21;
    *(float *)v28 = v15;
    v18 = v26 * v21;
    *(float *)&v28[1] = v18;
    v20 = v27 * v21;
    *(float *)&v28[2] = v20;
    sub_614F40(v28);
    sub_40D5D0(v30, (int)&v22);
    return off_16C9548(a3, a4, LODWORD(a5));
  }
  else
  {
    v12 = sub_59A1A0((_DWORD *)a1, a3, a1 + 856, a1 + 8, (int)a4);
    if ( v12 )
      sub_599C10((float *)a4, a5);
    return v12;
  }
}
