int __usercall sub_5054EC@<eax>(int a1@<ebp>)
{
  int **v1; // ecx
  int **v2; // esi
  int *v3; // eax
  int *v5; // eax
  unsigned int v6; // edi
  int *v7; // eax
  bool v8; // zf
  int v9; // ebx
  int v10; // eax
  int v11; // eax
  int v12; // ebx
  int v13; // eax
  int v14; // eax
  int v15; // ebx
  int v16; // ebx
  int v17; // edi
  int v18; // eax
  int v19; // ecx
  int *v20; // ecx
  int v21; // eax
  int v22; // eax
  int *v23; // ecx
  int v24; // edx
  int v25; // eax
  double v26; // st7
  int v27; // ecx
  double v28; // st7
  double v29; // st6
  int v30; // edx
  double v31; // st5
  int v32; // esi
  float *v33; // ecx
  double v34; // st7
  double v35; // st6
  double v36; // st7
  double v37; // st6
  double v38; // st6
  float *v39; // ecx
  double v40; // st5
  double v41; // st4
  unsigned int v42; // edx
  double v43; // st3
  int v44; // ecx
  double v45; // st6
  double v46; // st5
  _DWORD *v47; // edi
  double v48; // st4
  int *v49; // eax
  bool v50; // cf
  int v51; // esi
  int v52; // [esp-D8h] [ebp-D8h]
  int v53; // [esp-D4h] [ebp-D4h]

  sub_58A5D8();
  *(_DWORD *)(a1 - 20) = 0;
  *(_DWORD *)(a1 - 28) = 0;
  v2 = v1;
  v3 = v1[2];
  *(_DWORD *)(a1 - 64) = v1;
  if ( (_BYTE)v3 != 3 )
    return -2147467259;
  *(_DWORD *)(a1 - 16) = ((unsigned int)v3 & 0x20000) == 0;
  v5 = sub_5053EC(v1[1][1046], (*v1)[1046], (BYTE2(v3) & 1) == 0);
  v52 = *(_DWORD *)(a1 - 16);
  v6 = (*v2)[1047];
  *(_DWORD *)(a1 - 48) = v5;
  v7 = sub_5053EC(v2[1][1047], v6, v52);
  v8 = *(_DWORD *)(a1 - 48) == 0;
  *(_DWORD *)(a1 - 16) = v7;
  if ( v8 || !v7 )
    goto LABEL_27;
  v9 = v2[1][1046];
  v10 = sub_587C03(16 * v9);
  *(_DWORD *)(a1 - 20) = v10;
  *(_DWORD *)(a1 - 4) = 0;
  if ( v10 )
  {
    sub_5008C2(v10, 16, v9, (int (__thiscall *)(int))sub_5007EC);
    v11 = *(_DWORD *)(a1 - 20);
    *(_DWORD *)(a1 - 32) = v11;
  }
  else
  {
    *(_DWORD *)(a1 - 32) = 0;
    v11 = *(_DWORD *)(a1 - 32);
  }
  *(_DWORD *)(a1 - 4) = -1;
  *(_DWORD *)(a1 - 20) = v11;
  if ( !v11 )
    goto LABEL_27;
  v12 = 2 * (*v2)[1046];
  v13 = sub_587C03(32 * (*v2)[1046]);
  *(_DWORD *)(a1 - 28) = v13;
  *(_DWORD *)(a1 - 4) = 1;
  if ( v13 )
  {
    sub_5008C2(v13, 16, v12, (int (__thiscall *)(int))sub_5007EC);
    v14 = *(_DWORD *)(a1 - 28);
  }
  else
  {
    v14 = 0;
  }
  *(_DWORD *)(a1 - 4) = -1;
  *(_DWORD *)(a1 - 28) = v14;
  if ( v14 )
  {
    v15 = (*v2)[1046];
    *(_DWORD *)(a1 - 40) = 0;
    *(_DWORD *)(a1 - 36) = -1;
    *(_DWORD *)(a1 - 24) = -1;
    v16 = v14 + 16 * v15;
    *(_DWORD *)(a1 - 44) = v14;
    if ( v2[1][1047] )
    {
      v17 = *(_DWORD *)(a1 - 16) + 8;
      *(_DWORD *)(a1 - 56) = v17;
      do
      {
        v18 = *(_DWORD *)(v17 - 8);
        *(_DWORD *)(a1 - 52) = 0;
        if ( v18 != *(_DWORD *)(a1 - 36) )
        {
          v19 = *(_DWORD *)(a1 - 24);
          if ( v18 == v19 )
          {
            v21 = *(_DWORD *)(a1 - 44);
            *(_DWORD *)(a1 - 24) = -1;
            *(_DWORD *)(a1 - 44) = v16;
            *(_DWORD *)(a1 - 36) = v19;
            v16 = v21;
          }
          else
          {
            v53 = *(_DWORD *)(a1 - 44);
            v20 = *v2;
            *(_DWORD *)(a1 - 36) = v18;
            (*(void (__thiscall **)(int *, _DWORD, _DWORD, int))(*v20 + 4))(v20, *(_DWORD *)(a1 - 36), 0, v53);
          }
        }
        v22 = *(_DWORD *)v17;
        if ( *(_DWORD *)v17 != *(_DWORD *)(a1 - 24) )
        {
          v23 = *v2;
          v24 = **v2;
          *(_DWORD *)(a1 - 24) = v22;
          (*(void (__thiscall **)(int *, int, _DWORD, int))(v24 + 4))(v23, v22, 0, v16);
        }
        if ( v2[1][1046] )
        {
          v25 = *(_DWORD *)(a1 - 48) + 8;
          *(_DWORD *)(a1 - 60) = *(_DWORD *)(a1 - 32);
          do
          {
            v26 = *(float *)(v25 + 4);
            v27 = 16 * *(_DWORD *)v25;
            *(float *)(a1 - 80) = v26 * *(float *)(v27 + v16);
            *(float *)(a1 - 76) = v26 * *(float *)(v27 + v16 + 4);
            *(float *)(a1 - 72) = v26 * *(float *)(v27 + v16 + 8);
            v28 = v26 * *(float *)(v27 + v16 + 12);
            v29 = *(float *)(v25 - 4);
            v30 = 16 * *(_DWORD *)(v25 - 8);
            v31 = v29 * *(float *)(v30 + v16);
            *(float *)(a1 - 156) = v29 * *(float *)(v30 + v16 + 4);
            *(float *)(a1 - 152) = v29 * *(float *)(v30 + v16 + 8);
            v32 = *(_DWORD *)(a1 - 44);
            v33 = (float *)(v32 + v27);
            *(float *)(a1 - 148) = v29 * *(float *)(v30 + v16 + 12);
            *(float *)(a1 - 128) = v31 + *(float *)(a1 - 80);
            *(float *)(a1 - 124) = *(float *)(a1 - 156) + *(float *)(a1 - 76);
            *(float *)(a1 - 120) = *(float *)(a1 - 152) + *(float *)(a1 - 72);
            v34 = *(float *)(a1 - 148) + v28;
            v35 = *(float *)(v17 + 4);
            *(float *)(a1 - 176) = *(float *)(a1 - 128) * v35;
            *(float *)(a1 - 172) = *(float *)(a1 - 124) * v35;
            *(float *)(a1 - 168) = *(float *)(a1 - 120) * v35;
            v36 = v34 * v35;
            v37 = *(float *)(v25 + 4);
            *(float *)(a1 - 192) = v37 * *v33;
            *(float *)(a1 - 188) = v37 * v33[1];
            *(float *)(a1 - 184) = v37 * v33[2];
            v38 = v37 * v33[3];
            v39 = (float *)(v30 + v32);
            v40 = *(float *)(v25 - 4);
            v25 += 16;
            v41 = v40 * *(float *)(v30 + v32);
            v42 = ++*(_DWORD *)(a1 - 52);
            *(float *)(a1 - 92) = v40 * v39[1];
            *(float *)(a1 - 88) = v40 * v39[2];
            v43 = v40 * v39[3];
            v44 = *(_DWORD *)(a1 - 64);
            *(float *)(a1 - 84) = v43;
            *(float *)(a1 - 112) = v41 + *(float *)(a1 - 192);
            *(float *)(a1 - 108) = *(float *)(a1 - 92) + *(float *)(a1 - 188);
            *(float *)(a1 - 104) = *(float *)(a1 - 88) + *(float *)(a1 - 184);
            v45 = *(float *)(a1 - 84) + v38;
            v46 = *(float *)(v17 - 4);
            v47 = *(_DWORD **)(a1 - 60);
            v48 = *(float *)(a1 - 112);
            *(_DWORD *)(a1 - 60) = v47 + 4;
            *(float *)(a1 - 144) = v48 * v46;
            *(float *)(a1 - 140) = *(float *)(a1 - 108) * v46;
            *(float *)(a1 - 136) = *(float *)(a1 - 104) * v46;
            *(float *)(a1 - 208) = *(float *)(a1 - 144) + *(float *)(a1 - 176);
            *(float *)(a1 - 204) = *(float *)(a1 - 140) + *(float *)(a1 - 172);
            *(float *)(a1 - 200) = *(float *)(a1 - 136) + *(float *)(a1 - 168);
            *(float *)(a1 - 196) = v45 * v46 + v36;
            *v47++ = *(_DWORD *)(a1 - 208);
            *v47++ = *(_DWORD *)(a1 - 208 + 4);
            *v47 = *(_DWORD *)(a1 - 208 + 8);
            v47[1] = *(_DWORD *)(a1 - 208 + 12);
            v17 = *(_DWORD *)(a1 - 56);
          }
          while ( v42 < *(_DWORD *)(*(_DWORD *)(v44 + 4) + 4184) );
          v2 = *(int ***)(a1 - 64);
        }
        (*(void (__thiscall **)(int *, _DWORD, _DWORD, _DWORD))(*v2[1] + 8))(
          v2[1],
          *(_DWORD *)(a1 - 40),
          0,
          *(_DWORD *)(a1 - 32));
        v49 = v2[1];
        v17 += 16;
        v50 = ++*(_DWORD *)(a1 - 40) < (unsigned int)v49[1047];
        *(_DWORD *)(a1 - 56) = v17;
      }
      while ( v50 );
    }
    v51 = 0;
  }
  else
  {
LABEL_27:
    v51 = -2147024882;
  }
  sub_587BCF(*(LPVOID *)(a1 - 48));
  sub_587BCF(*(LPVOID *)(a1 - 16));
  sub_587BCF(*(LPVOID *)(a1 - 20));
  sub_587BCF(*(LPVOID *)(a1 - 28));
  return v51;
}
