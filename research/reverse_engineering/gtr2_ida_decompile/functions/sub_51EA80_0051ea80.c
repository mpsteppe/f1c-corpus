void __thiscall sub_51EA80(int *this)
{
  int *v1; // ebx
  float *v2; // ebp
  int v3; // eax
  int v4; // ecx
  int v5; // edi
  int v6; // ebx
  _DWORD *v7; // eax
  float *v8; // esi
  float v9; // edx
  float v10; // ecx
  double *v11; // eax
  double v12; // st7
  float v13; // ecx
  float v14; // edx
  _DWORD *v15; // eax
  int v16[17]; // [esp-44h] [ebp-184h] BYREF
  int v17; // [esp+14h] [ebp-12Ch]
  char v18[4]; // [esp+18h] [ebp-128h] BYREF
  _DWORD *v19; // [esp+1Ch] [ebp-124h]
  float v20[2]; // [esp+20h] [ebp-120h] BYREF
  float v21; // [esp+28h] [ebp-118h]
  int *v22; // [esp+2Ch] [ebp-114h]
  int v23; // [esp+30h] [ebp-110h]
  int v24; // [esp+34h] [ebp-10Ch]
  int v25; // [esp+38h] [ebp-108h]
  float v26; // [esp+3Ch] [ebp-104h] BYREF
  char v27[4]; // [esp+40h] [ebp-100h] BYREF
  float v28[3]; // [esp+44h] [ebp-FCh] BYREF
  float v29[14]; // [esp+50h] [ebp-F0h] BYREF
  _DWORD v30[18]; // [esp+88h] [ebp-B8h] BYREF
  _DWORD v31[17]; // [esp+D0h] [ebp-70h] BYREF
  float v32[6]; // [esp+118h] [ebp-28h] BYREF
  char v33[16]; // [esp+130h] [ebp-10h] BYREF

  v1 = this;
  memset(&v30[1], 0, 0x40u);
  memset(&v31[1], 0, 0x40u);
  dword_BE10A8 = dword_FB2750;
  v22 = this;
  v30[16] = 1065353216;
  v30[11] = 1065353216;
  v30[6] = 1065353216;
  v30[1] = 1065353216;
  v30[0] = 1;
  v31[16] = 1065353216;
  v31[11] = 1065353216;
  v31[6] = 1065353216;
  v31[1] = 1065353216;
  v31[0] = 1;
  dword_FB2750 = (int)&dword_1000000;
  byte_FB2764 = 1;
  v25 = dword_757C10;
  v17 = 0;
  if ( dword_757C10 > 0 )
  {
    v2 = (float *)(this + 5);
    do
    {
      v3 = *(&dword_91E088 + v17);
      v4 = *(_DWORD *)(v3 + 2712) + 72;
      v23 = v3;
      v5 = 0;
      v6 = v3 + 16164;
      v7 = (_DWORD *)(v3 + 3168);
      v24 = v4;
      v8 = v29;
      v19 = v7;
      do
      {
        if ( *v7
          && (sub_5DA610(&v26, v27, v28, v18, v18, v18), sub_5D7810(&v26, v20, v24 + 4), v26 <= 100.0)
          && v28[0] <= 100.0 )
        {
          v9 = v21;
          *(v2 - 2) = v20[0];
          *v2 = v9;
        }
        else
        {
          v10 = *v2;
          v20[0] = *(v2 - 2);
          v21 = v10;
        }
        if ( v6 && (v11 = *(double **)(v6 + 236)) != 0 )
        {
          v12 = (v21 * v11[2] + v20[0] * *v11 + v11[3]) * v20[0] + (v21 * v11[1] + v11[4]) * v21 + v11[5];
          v29[v5 + 10] = v12;
          *(v2 - 1) = v12;
        }
        else
        {
          v29[v5 + 10] = *(v2 - 1);
        }
        v13 = v29[v5 + 10];
        v14 = v21;
        *(v8 - 2) = v20[0];
        v15 = v19;
        *(v8 - 1) = v13;
        *v8 = v14;
        ++v5;
        v7 = v15 + 74;
        v6 += 252;
        v2 += 3;
        v8 += 3;
        v19 = v7;
      }
      while ( v5 < 4 );
      sub_51C9F0(v32, v28[1], v28[2], v29[0], v29[1], v29[2], v29[3], v29[4], v29[5], v29[6]);
      sub_51D750(*(signed int **)(v23 + 2712), (int)v33, 1);
      ++v17;
    }
    while ( v17 < v25 );
    v1 = v22;
  }
  sub_5D7280(*v1 + 628, &unk_BE1144);
  sub_5D7280(*v1 + 344, v30);
  qmemcpy(v16, v31, sizeof(v16));
  sub_51C970(
    *v1,
    v16[0],
    v16[1],
    v16[2],
    v16[3],
    v16[4],
    v16[5],
    v16[6],
    v16[7],
    v16[8],
    v16[9],
    v16[10],
    v16[11],
    v16[12],
    v16[13],
    v16[14],
    v16[15],
    v16[16]);
}
