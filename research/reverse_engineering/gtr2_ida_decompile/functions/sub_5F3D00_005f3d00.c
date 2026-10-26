void __userpurge sub_5F3D00(
        _DWORD *a1@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9)
{
  int v10; // ebx
  int v11; // eax
  int v12; // edx
  int v13; // eax
  _DWORD *v14; // eax
  int v15; // eax
  int v16; // esi
  char *v17; // edx
  int v18; // ebx
  int v19; // edi
  char *v20; // ecx
  float *v21; // edx
  float *v22; // esi
  int v23; // eax
  double v24; // st7
  double v25; // st7
  double v26; // st6
  double v27; // st7
  int v28; // eax
  bool v29; // cc
  int v30; // eax
  float *v31; // esi
  int v32; // eax
  int v33; // edi
  float *v34; // eax
  int v35; // ecx
  float *v36; // ecx
  double v37; // st7
  int v38; // edx
  double v39; // st7
  int v40; // esi
  int v41; // edi
  int v42; // eax
  int v43; // [esp+C8h] [ebp-288h]
  float *v44; // [esp+CCh] [ebp-284h]
  float *v45; // [esp+D0h] [ebp-280h]
  float v46; // [esp+D4h] [ebp-27Ch]
  _DWORD *v47; // [esp+D8h] [ebp-278h]
  _DWORD *v48; // [esp+DCh] [ebp-274h]
  int v49; // [esp+E0h] [ebp-270h]
  int v50; // [esp+E4h] [ebp-26Ch]
  int v51; // [esp+E8h] [ebp-268h]
  float v52[18]; // [esp+F4h] [ebp-25Ch] BYREF
  _DWORD v53[17]; // [esp+13Ch] [ebp-214h] BYREF
  _BYTE v54[96]; // [esp+180h] [ebp-1D0h] BYREF
  char v55[356]; // [esp+1E0h] [ebp-170h] BYREF
  int v56; // [esp+34Ch] [ebp-4h]

  sub_60AA20(&v55[100]);
  v10 = a6;
  v56 = 0;
  if ( a6 )
  {
    if ( (*(_BYTE *)(a6 + 468) & 0x3F) != 0 )
    {
      v11 = (*(int (__thiscall **)(_DWORD *, const char *, _DWORD, int, int))(*a1 + 632))(a1, "L0NOLIGHTING", 0, a2, a3);
      (*(void (__thiscall **)(_DWORD *, _DWORD, int, _DWORD, _DWORD))(*a1 + 40))(a1, 0, v11, 0, 0);
      sub_609BF0(0);
      sub_46F740();
      v12 = a1[2250];
      qmemcpy(v55, (const void *)(v12 + 344), 0x6Cu);
      memset(&v53[1], 0, 0x40u);
      v13 = *a1;
      qmemcpy(v53, (const void *)(v12 + 628), sizeof(v53));
      (*(void (__thiscall **)(_DWORD *, int, char *))(v13 + 580))(a1, 2, v55);
      (*(void (__thiscall **)(_DWORD *, int, _DWORD *))(*a1 + 580))(a1, 4, v53);
      (*(void (__thiscall **)(_DWORD *, int, _DWORD, _DWORD))(*a1 + 20))(a1, 256, 0, 0);
      v14 = *(_DWORD **)(a6 + 392);
      if ( (*v14 & 0x10) != 0 )
        (*(void (__thiscall **)(_DWORD *, int, _DWORD *))(*a1 + 580))(a1, 1, v14 + 45);
      else
        (*(void (__thiscall **)(_DWORD *, int, void *))(*a1 + 580))(a1, 1, dword_FB27A8);
      if ( !*((_BYTE *)a1 + 4844) )
      {
        v15 = a1[2387];
        *((_BYTE *)a1 + 4844) = 1;
        a1[2] = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)v15 + 228))(v15, 136, 1);
      }
      (*(void (__thiscall **)(_DWORD *, _DWORD, _DWORD))(*a1 + 28))(a1, 0, a1[164]);
      if ( (*(_DWORD *)(a6 + 468) & 2) != 0 && (v16 = 0, *(int *)(a9 + 8) > 0) )
      {
        while ( 1 )
        {
          (*(void (__thiscall **)(_DWORD *, _DWORD, _DWORD))(*a1 + 412))(a1, a1[164], 0);
          v17 = *(char **)(a1[164] + 76);
          if ( !v17 )
            break;
          memset(v17, 0, 0x10000u);
          v43 = v16 << 6;
          v18 = 88 * v16;
          v44 = (float *)(v17 + 320);
          v19 = 0;
          v47 = v17 + 256;
          v20 = v17;
          v51 = 0;
          v50 = 88 * v16;
          v45 = (float *)(v17 + 192);
          v48 = v17 + 128;
          while ( 1 )
          {
            v21 = 0;
            v22 = 0;
            if ( (*(_BYTE *)a7 & 8) != 0 )
            {
              v23 = *(_DWORD *)(a7 + 32) + v18;
              v21 = (float *)(v23 + 32);
              v22 = (float *)(v23 + 44);
            }
            else
            {
              v23 = v43 + *(_DWORD *)(a7 + 32);
            }
            *(_DWORD *)v20 = *(_DWORD *)v23;
            *((_DWORD *)v20 + 1) = *(_DWORD *)(v23 + 4);
            *((_DWORD *)v20 + 2) = *(_DWORD *)(v23 + 8);
            *((_DWORD *)v20 + 6) = &unk_A0A0A0;
            v46 = *(float *)(a4 + 88);
            *((float *)v20 + 16) = v46 * *(float *)(v23 + 12) + *(float *)v23;
            *((float *)v20 + 17) = v46 * *(float *)(v23 + 16) + *(float *)(v23 + 4);
            v24 = v46 * *(float *)(v23 + 20) + *(float *)(v23 + 8);
            *((_DWORD *)v20 + 22) = &unk_A0A0A0;
            *((float *)v20 + 18) = v24;
            if ( !v21 )
              goto LABEL_20;
            if ( v22 )
            {
              v25 = v46 * 0.5;
              *v48 = *(_DWORD *)v23;
              *((_DWORD *)v20 + 33) = *(_DWORD *)(v23 + 4);
              *((_DWORD *)v20 + 34) = *(_DWORD *)(v23 + 8);
              *((_DWORD *)v20 + 38) = dword_FF0000;
              *v45 = v25 * *v21 + *(float *)v23;
              *((float *)v20 + 49) = v25 * v21[1] + *(float *)(v23 + 4);
              v26 = v25 * v21[2] + *(float *)(v23 + 8);
              *((_DWORD *)v20 + 54) = dword_FF0000;
              *((float *)v20 + 50) = v26;
              *v47 = *(_DWORD *)v23;
              *((_DWORD *)v20 + 65) = *(_DWORD *)(v23 + 4);
              *((_DWORD *)v20 + 66) = *(_DWORD *)(v23 + 8);
              *((_DWORD *)v20 + 70) = 65280;
              *v44 = v25 * *v22 + *(float *)v23;
              v19 = v51 + 6;
              *((float *)v20 + 81) = v25 * v22[1] + *(float *)(v23 + 4);
              v27 = v25 * v22[2] + *(float *)(v23 + 8);
              v28 = 384;
              *((float *)v20 + 82) = v27;
              *((_DWORD *)v20 + 86) = 65280;
              v48 += 96;
              v45 += 96;
              v47 += 96;
            }
            else
            {
LABEL_20:
              v28 = 128;
              v19 += 2;
              v48 += 32;
              v45 += 32;
              v47 += 32;
            }
            v10 = a6;
            v20 += v28;
            v44 = (float *)((char *)v44 + v28);
            v43 += 64;
            v16 = v49 + 1;
            v50 += 88;
            v29 = v49 + 1 < *(_DWORD *)(a7 + 8);
            v51 = v19;
            ++v49;
            if ( !v29 || v19 >= 1018 )
              break;
            v18 = v50;
          }
          (*(void (__thiscall **)(_DWORD *, _DWORD, int, _DWORD, int))(*a1 + 416))(a1, a1[164], 4096, 0, 4096);
          a1[2] = (*(int (__stdcall **)(_DWORD, int, _DWORD, int))(*(_DWORD *)a1[2387] + 324))(a1[2387], 2, 0, v19 >> 1);
          if ( v16 >= *(_DWORD *)(a9 + 8) )
            goto LABEL_24;
        }
      }
      else
      {
LABEL_24:
        if ( (*(_BYTE *)(v10 + 468) & 1) == 0 )
          goto LABEL_38;
        (*(void (__thiscall **)(_DWORD *, _DWORD, _DWORD))(*a1 + 28))(a1, 0, a1[164]);
        if ( !*((_BYTE *)a1 + 4844) )
        {
          v30 = a1[2387];
          *((_BYTE *)a1 + 4844) = 1;
          a1[2] = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)v30 + 228))(v30, 136, 1);
        }
        v31 = *(float **)(v10 + 372);
        if ( *(int *)(v10 + 368) > 0 )
        {
          while ( 1 )
          {
            (*(void (__thiscall **)(_DWORD *, _DWORD, _DWORD))(*a1 + 412))(a1, a1[164], 0);
            v32 = *(_DWORD *)(a1[164] + 76);
            if ( !v32 )
              break;
            v33 = 0;
            v34 = (float *)(v32 + 4);
            do
            {
              if ( *((_DWORD *)v31 + 2) == a7 )
              {
                v35 = *((_DWORD *)v31 + 3);
                if ( v35 >= *(_DWORD *)(v10 + 376) )
                  v36 = 0;
                else
                  v36 = (float *)(*(_DWORD *)(v10 + 380) + 16 * v35);
                *(v34 - 1) = v31[5];
                *v34 = v31[6];
                v34[1] = v31[7];
                *((_DWORD *)v34 + 5) = 3158064;
                v33 += 2;
                v34 += 32;
                *(v34 - 17) = *v36 * *(float *)(a4 + 88) + *(v34 - 33);
                *(v34 - 16) = v36[1] * *(float *)(a4 + 88) + *(v34 - 32);
                v37 = v36[2] * *(float *)(a4 + 88);
                *((_DWORD *)v34 - 11) = 3158064;
                *(v34 - 15) = v37 + *(v34 - 31);
              }
              v31 += 9;
              ++v43;
            }
            while ( v43 < *(_DWORD *)(v10 + 368) && v33 < 1024 );
            (*(void (__thiscall **)(_DWORD *, _DWORD, int, _DWORD, int))(*a1 + 416))(a1, a1[164], 4096, 0, 4096);
            a1[2] = (*(int (__stdcall **)(_DWORD, int, _DWORD, int))(*(_DWORD *)a1[2387] + 324))(
                      a1[2387],
                      2,
                      0,
                      v33 >> 1);
            if ( *(int *)(v10 + 368) <= 0 )
              goto LABEL_38;
          }
        }
        else
        {
LABEL_38:
          if ( (*(_DWORD *)(v10 + 468) & 8) != 0 )
          {
            a1[2] = (*(int (__stdcall **)(_DWORD, int, int))(*(_DWORD *)a1[2387] + 228))(a1[2387], 23, 4);
            sub_5EC2A0((unsigned int *)v10, 0);
            v38 = *a1;
            qmemcpy(v54, (const void *)(v10 + 120), sizeof(v54));
            (*(void (__thiscall **)(_DWORD *, _DWORD, _BYTE *, unsigned int))(v38 + 504))(
              a1,
              0,
              v54,
              (unsigned int)byte_FFFFFF & v10);
            a1[2] = (*(int (__stdcall **)(_DWORD, int, int))(*(_DWORD *)a1[2387] + 228))(a1[2387], 23, 2);
          }
          if ( (*(_BYTE *)(v10 + 468) & 0x20) != 0 )
          {
            a1[2] = (*(int (__stdcall **)(_DWORD, int, int))(*(_DWORD *)a1[2387] + 228))(a1[2387], 23, 4);
            v39 = *(float *)(v10 + 20) * 1.1;
            v52[1] = 0.0;
            v52[2] = 0.0;
            memset(&v52[4], 0, 12);
            v52[0] = -v39;
            v52[8] = 0.0;
            v52[9] = 0.0;
            v52[3] = v39;
            memset(&v52[11], 0, 12);
            v52[7] = v52[0];
            v52[15] = 0.0;
            v52[10] = v39;
            v52[16] = 0.0;
            v40 = 0;
            v52[14] = v52[0];
            v52[17] = v39;
            do
            {
              sub_5D7810(&v52[v40], (float *)&v54[v40 * 4], (float *)(*(_DWORD *)(v10 + 392) + 184));
              v40 += 3;
            }
            while ( v40 < 18 );
            (*(void (__thiscall **)(_DWORD *, _DWORD, _BYTE *, unsigned int))(*a1 + 508))(
              a1,
              0,
              v54,
              (unsigned int)byte_FFFFFF & v10);
            a1[2] = (*(int (__stdcall **)(_DWORD, int, int))(*(_DWORD *)a1[2387] + 228))(a1[2387], 23, 2);
          }
          sub_5E80D0(*(_DWORD **)(a9 + 4), 0);
          v41 = *a1;
          v42 = sub_5E8830(*(_DWORD **)(a9 + 4), 0);
          (*(void (__thiscall **)(_DWORD *, int))(v41 + 20))(a1, v42);
          (*(void (__thiscall **)(_DWORD *, int, _DWORD, _DWORD, _DWORD))(*a1 + 40))(a1, a9, 0, 0, 0);
        }
      }
    }
    v56 = -1;
    sub_5E2BF0(&v55[100]);
  }
  else
  {
    v56 = -1;
    sub_5E2BF0(&v55[100]);
  }
}
