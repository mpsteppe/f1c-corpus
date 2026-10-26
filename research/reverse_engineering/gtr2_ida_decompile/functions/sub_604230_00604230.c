int __cdecl sub_604230(int a1, int a2, int a3, int a4, int a5)
{
  _DWORD *v5; // ecx
  _DWORD *v6; // ebp
  int v7; // eax
  _DWORD *v8; // ebx
  int v9; // edi
  int v10; // ecx
  int *v11; // eax
  int v12; // edx
  int v13; // esi
  int v14; // edx
  int *v15; // eax
  int v16; // ecx
  int v17; // ecx
  int *v18; // eax
  int v19; // edx
  int v20; // ecx
  int *v21; // eax
  int v22; // edx
  int v23; // ecx
  int *v24; // eax
  int v25; // edx
  BOOL v26; // edi
  int v27; // ecx
  int *v28; // eax
  int v29; // edx
  BOOL v30; // esi
  int v31; // ecx
  int *v32; // eax
  int v33; // edx
  BOOL v34; // edi
  int v35; // eax
  int v36; // eax
  int v37; // edx
  int v38; // eax
  int v39; // ecx
  _DWORD v41[33]; // [esp+5Ch] [ebp-718h] BYREF
  int v42; // [esp+E0h] [ebp-694h]
  int v43; // [esp+E4h] [ebp-690h]
  int v44; // [esp+114h] [ebp-660h]
  int v45; // [esp+130h] [ebp-644h]
  int v46; // [esp+134h] [ebp-640h]
  int v47; // [esp+138h] [ebp-63Ch]
  int v48; // [esp+168h] [ebp-60Ch]
  int v49; // [esp+1A4h] [ebp-5D0h]
  int v50; // [esp+1BCh] [ebp-5B8h]
  int v51; // [esp+1C0h] [ebp-5B4h]
  _BYTE v52[8]; // [esp+1D4h] [ebp-5A0h] BYREF
  int v53; // [esp+1DCh] [ebp-598h]
  int v54; // [esp+1E4h] [ebp-590h]
  int v55; // [esp+5E8h] [ebp-18Ch]
  int v56; // [esp+5ECh] [ebp-188h]
  _DWORD *v57; // [esp+770h] [ebp-4h]

  v6 = v5;
  v7 = *v5;
  v54 = 0;
  (*(void (__thiscall **)(_DWORD *, int))(v7 + 128))(v5, a2);
  if ( !v6[2387] )
  {
    (*(void (__thiscall **)(_DWORD *, int))(*v6 + 112))(v6, a5);
    v53 = 1;
  }
  v8 = v57;
  sub_5FAFF0(v57);
  memset(v6 + 2388, 0, 0x38u);
  v9 = 0;
  (*(void (__thiscall **)(_DWORD *, _DWORD *, int, _DWORD))(*v6 + 168))(v6, v6 + 2390, a3, 0);
  (*(void (__thiscall **)(_DWORD *, _DWORD, _BYTE *, _DWORD))(*v6 + 172))(v6, v6[2390], v52, 0);
  v10 = v8[67];
  v11 = (int *)v6[2386];
  v12 = *v11;
  v51 = 0;
  v50 = 0;
  v13 = 0;
  if ( !(*(int (__cdecl **)(int *, int, int, int, int, int, int))(v12 + 40))(v11, v10, 1, 23, 1, 3, 23) )
    v49 = 1;
  if ( !(*(int (__cdecl **)(_DWORD, _DWORD, int, int, int, int, int))(*(_DWORD *)v6[2386] + 40))(
          v6[2386],
          v8[67],
          1,
          23,
          1,
          3,
          26) )
    v9 = 1;
  if ( !(*(int (__cdecl **)(_DWORD, _DWORD, int, int, int, int, int))(*(_DWORD *)v6[2386] + 40))(
          v6[2386],
          v8[67],
          1,
          23,
          1,
          3,
          25) )
    v48 = 1;
  if ( !(*(int (__cdecl **)(_DWORD, _DWORD, int, int, int, int, int))(*(_DWORD *)v6[2386] + 40))(
          v6[2386],
          v8[67],
          1,
          23,
          1,
          3,
          21) )
    v13 = 1;
  v14 = v8[67];
  v15 = (int *)v6[2386];
  v16 = *v15;
  v47 = 22;
  v46 = 3;
  v45 = 1;
  (*(void (__cdecl **)(int *, int, int, int))(v16 + 40))(v15, v14, 1, 23);
  if ( v9 )
  {
    v6[2416] = 26;
  }
  else if ( v13 )
  {
    v6[2416] = 21;
  }
  else
  {
    v6[2416] = 23;
  }
  v17 = v8[67];
  v18 = (int *)v6[2386];
  v19 = *v18;
  v45 = 0;
  if ( !(*(int (__cdecl **)(int *, int, int, int, int, int, int))(v19 + 40))(v18, v17, 1, 22, 1, 3, 21) )
    v44 = 1;
  (*(int (__cdecl **)(_DWORD, _DWORD, int, int, int, int, int))(*(_DWORD *)v6[2386] + 40))(
    v6[2386],
    v8[67],
    1,
    22,
    1,
    3,
    22);
  v20 = v8[67];
  v21 = (int *)v6[2386];
  v22 = *v21;
  v43 = 23;
  v42 = 3;
  v41[32] = 1;
  (*(int (__cdecl **)(int *, int, int, int))(v22 + 40))(v21, v20, 1, 22);
  v6[2417] = 21;
  v23 = v8[67];
  v24 = (int *)v6[2386];
  v25 = *v24;
  v42 = 0;
  if ( !(*(int (__cdecl **)(int *, int, int, int, _DWORD, int, int))(v25 + 40))(v24, v23, 1, 23, 0, 3, 23) )
    v41[26] = 1;
  v26 = (*(int (__cdecl **)(_DWORD, _DWORD, int, int, _DWORD, int, int))(*(_DWORD *)v6[2386] + 40))(
          v6[2386],
          v8[67],
          1,
          23,
          0,
          3,
          24) == 0;
  v27 = v8[67];
  v28 = (int *)v6[2386];
  v29 = *v28;
  v41[13] = 25;
  v41[12] = 3;
  v30 = (*(int (__cdecl **)(int *, int, int, int, _DWORD))(v29 + 40))(v28, v27, 1, 23, 0) == 0;
  v6[2422] = 23;
  if ( v30 )
  {
    v6[2423] = 25 - v26;
  }
  else if ( v26 )
  {
    v6[2423] = 24;
  }
  v31 = v8[67];
  v32 = (int *)v6[2386];
  v33 = *v32;
  v41[6] = 21;
  v41[5] = 3;
  v41[4] = 0;
  v41[3] = 22;
  v41[2] = 1;
  v41[1] = v31;
  v41[0] = v32;
  v34 = (*(int (**)(void))(v33 + 40))() == 0;
  v35 = (*(int (__cdecl **)(_DWORD, _DWORD, int, int, _DWORD, int, int))(*(_DWORD *)v6[2386] + 40))(
          v6[2386],
          v8[67],
          1,
          22,
          0,
          3,
          22);
  if ( v34 )
    v6[2419] = 21;
  if ( !v35 )
    v6[2418] = 22;
  if ( v41[0] == 16 )
  {
    v6[2415] = 23;
    v36 = v8[65];
    if ( (v36 & 0x8000000) != 0 )
    {
      v37 = v6[2416];
      v6[2390] = 25;
    }
    else if ( (v36 & 0x10000000) != 0 )
    {
      v37 = v6[2416];
      v6[2390] = 24;
    }
    else
    {
      if ( (v36 & 0x4000000) != 0 )
        v6[2390] = 23;
      v37 = v6[2416];
    }
LABEL_45:
    (*(void (__thiscall **)(_DWORD *, int, _DWORD, _DWORD *))(*v6 + 172))(v6, v37, 0, v6 + 2362);
    goto LABEL_46;
  }
  if ( v41[0] == 24 || v41[0] == 32 )
  {
    v6[2415] = 22;
    v38 = v8[65];
    if ( (v38 & 0x40000000) != 0 )
    {
      v6[2390] = 21;
    }
    else if ( v38 >= 0 )
    {
      if ( (v38 & 0x20000000) != 0 )
        v6[2390] = 20;
    }
    else
    {
      v6[2390] = 22;
    }
    v37 = v6[2417];
    goto LABEL_45;
  }
LABEL_46:
  (*(void (__thiscall **)(_DWORD *, _DWORD, _DWORD, _DWORD *))(*v6 + 172))(v6, v6[2390], 0, v41);
  if ( ((unsigned int)dword_FF0000 & v56) != 0 && ((unsigned int)dword_FF0000 & v8[66]) != 0 )
  {
    if ( !(*(int (__cdecl **)(_DWORD, _DWORD, int, _DWORD))(*(_DWORD *)v6[2386] + 44))(v6[2386], v8[67], 1, v6[2390]) )
      return off_16C9344(0);
  }
  else
  {
    v39 = 0x7FFF;
    if ( (v55 & 0x7FFF) != 0 && (v8[66] & 0x7FFF) != 0 )
    {
      if ( (v56 & 1) != 0 )
      {
        if ( !(*(int (__cdecl **)(_DWORD, _DWORD, int, _DWORD, _DWORD, int, _DWORD))(*(_DWORD *)v6[2386] + 44))(
                v6[2386],
                v8[67],
                1,
                v6[2390],
                0,
                2,
                0) )
        {
          v6[2392] = 2;
          v6[2393] = 0;
        }
      }
      else if ( (v56 & 4) != 0 )
      {
        if ( !(*(int (__cdecl **)(_DWORD, _DWORD, int, _DWORD, _DWORD, int, _DWORD))(*(_DWORD *)v6[2386] + 44))(
                v6[2386],
                v8[67],
                1,
                v6[2390],
                0,
                3,
                0) )
        {
          v6[2392] = 3;
          v6[2393] = 0;
        }
      }
      else if ( (v56 & 2) != 0 )
      {
        if ( !(*(int (__cdecl **)(_DWORD, _DWORD, int, _DWORD, _DWORD, int, _DWORD))(*(_DWORD *)v6[2386] + 44))(
                v6[2386],
                v8[67],
                1,
                v6[2390],
                0,
                4,
                0) )
        {
          v6[2392] = 4;
          v6[2393] = 0;
        }
      }
      else if ( (v56 & 0x10) != 0 )
      {
        if ( !(*(int (__cdecl **)(_DWORD, _DWORD, int, _DWORD, _DWORD, int, _DWORD))(*(_DWORD *)v6[2386] + 44))(
                v6[2386],
                v8[67],
                1,
                v6[2390],
                0,
                6,
                0) )
        {
          v6[2392] = 6;
          v6[2393] = 0;
        }
      }
      else if ( (v56 & 0x4000) != 0
             && !(*(int (__cdecl **)(_DWORD, _DWORD, int, _DWORD, _DWORD, int, _DWORD))(*(_DWORD *)v6[2386] + 44))(
                   v6[2386],
                   v8[67],
                   1,
                   v6[2390],
                   0,
                   16,
                   0) )
      {
        v6[2392] = 16;
        v6[2393] = 0;
      }
    }
  }
  return off_16C9344(v39);
}
