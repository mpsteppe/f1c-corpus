int __usercall sub_604F60@<eax>(_DWORD *a1@<ecx>, int a2@<ebx>, int a3@<ebp>, int a4@<edi>)
{
  int v6; // edx
  int v7; // eax
  int v8; // edx
  int v9; // eax
  int v10; // edi
  _DWORD *v11; // ebp
  _DWORD *v12; // ebx
  int v13; // eax
  int v14; // ecx
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  _DWORD *v20; // ebx
  int v21; // eax
  _DWORD *v22; // eax
  int v23; // ecx
  _DWORD *v24; // ebx
  _DWORD *v25; // ebx
  _WORD *v26; // eax
  int v27; // [esp+F4h] [ebp-58h]
  int v28; // [esp+F8h] [ebp-54h]
  int v29; // [esp+F8h] [ebp-54h]
  int v30; // [esp+FCh] [ebp-50h]
  _DWORD v31[2]; // [esp+108h] [ebp-44h] BYREF
  int v32; // [esp+110h] [ebp-3Ch]
  int v33; // [esp+114h] [ebp-38h]
  int v34; // [esp+118h] [ebp-34h]
  int v35; // [esp+11Ch] [ebp-30h]
  int v36; // [esp+120h] [ebp-2Ch]
  int v37; // [esp+124h] [ebp-28h]
  int v38; // [esp+128h] [ebp-24h]
  int v39; // [esp+12Ch] [ebp-20h]
  int v40; // [esp+130h] [ebp-1Ch]
  int v41; // [esp+134h] [ebp-18h]
  int v42; // [esp+138h] [ebp-14h]
  int v43; // [esp+13Ch] [ebp-10h]
  int v44; // [esp+140h] [ebp-Ch]
  int v45; // [esp+144h] [ebp-8h]
  int v46; // [esp+148h] [ebp-4h]

  if ( (a1[1] & 0x10000000) != 0 )
    return 0;
  memset(a1 + 1219, 0xFFu, 0x400u);
  (*(void (__thiscall **)(_DWORD *, int, int, int, int, int))(*a1 + 44))(a1, 8, 3, a4, a3, a2);
  (*(void (__thiscall **)(_DWORD *, int, _DWORD))(*a1 + 44))(a1, 22, a1[1202]);
  (*(void (__thiscall **)(_DWORD *, int, int))(*a1 + 44))(a1, 26, 1);
  (*(void (__thiscall **)(_DWORD *, int, _DWORD))(*a1 + 44))(a1, 28, 0);
  v6 = *a1;
  *((_BYTE *)a1 + 4844) = 1;
  (*(void (__thiscall **)(_DWORD *, int, int))(v6 + 44))(a1, 136, 1);
  (*(void (__thiscall **)(_DWORD *, int, _DWORD))(*a1 + 44))(a1, 143, 0);
  (*(void (__thiscall **)(_DWORD *, int, _DWORD))(*a1 + 44))(a1, 7, a1[1208]);
  (*(void (__thiscall **)(_DWORD *, int, int))(*a1 + 44))(a1, 23, 2);
  (*(void (__thiscall **)(_DWORD *, int))(*a1 + 76))(a1, 1);
  (*(void (__thiscall **)(_DWORD *, int, _DWORD))(*a1 + 44))(a1, 60, a1[1212]);
  (*(void (__thiscall **)(_DWORD *, int, _DWORD))(*a1 + 44))(a1, 15, 0);
  (*(void (__thiscall **)(_DWORD *, int, int))(*a1 + 44))(a1, 25, 7);
  (*(void (__thiscall **)(_DWORD *, int, int))(*a1 + 44))(a1, 24, 63);
  v7 = *a1;
  a1[1210] = 63;
  (*(void (__thiscall **)(_DWORD *, int, _DWORD))(v7 + 44))(a1, 29, 0);
  (*(void (__thiscall **)(_DWORD *, int, _DWORD))(*a1 + 44))(a1, 27, 0);
  (*(void (__thiscall **)(_DWORD *, int, int))(*a1 + 44))(a1, 19, 2);
  (*(void (__thiscall **)(_DWORD *, int, int))(*a1 + 44))(a1, 20, 1);
  (*(void (__thiscall **)(_DWORD *, int, int))(*a1 + 44))(a1, 9, 2);
  v8 = *a1;
  a1[1209] = 65538;
  (*(void (__thiscall **)(_DWORD *, int, void *))(v8 + 580))(a1, 2, dword_FB27A8);
  (*(void (__thiscall **)(_DWORD *, int, void *))(*a1 + 580))(a1, 4, dword_FB27A8);
  v9 = (*(int (__stdcall **)(_DWORD, int, char *))(*(_DWORD *)a1[2387] + 176))(a1[2387], 256, (char *)dword_FB27A8 + 4);
  v30 = a1[1210];
  v28 = a1[1209];
  a1[2] = v9;
  (*(void (__thiscall **)(_DWORD *, int, int, int))(*a1 + 20))(a1, 256, v28, v30);
  v10 = 0;
  v11 = a1 + 2402;
  v32 = (int)(a1 + 705);
  v12 = a1 + 193;
  do
  {
    sub_60A680(v10);
    sub_60ABB0(v10, a1[1] & 1);
    a1[2] = (*(int (__stdcall **)(_DWORD, int, int, int))(*(_DWORD *)a1[2387] + 276))(a1[2387], v10, 6, 2);
    a1[2] = (*(int (__stdcall **)(_DWORD, int, int, int))(*(_DWORD *)a1[2387] + 276))(a1[2387], v10, 5, 2);
    *v11 = 0;
    v13 = (*(int (__stdcall **)(_DWORD, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)a1[2387] + 400))(
            a1[2387],
            v10++,
            0,
            0,
            0);
    v14 = v32 + 248;
    ++v11;
    v12 += 64;
    a1[2] = v13;
    v32 = v14;
  }
  while ( v10 < 8 );
  v15 = a1[2387];
  a1[2410] = 0;
  a1[2] = (*(int (__stdcall **)(int))(*(_DWORD *)v15 + 416))(v15);
  v16 = a1[2387];
  a1[2411] = 0;
  a1[2413] = 0;
  a1[2414] = 324;
  a1[2] = (*(int (__cdecl **)(int, _DWORD))(*(_DWORD *)v16 + 368))(v16, 0);
  a1[2] = (*(int (__stdcall **)(_DWORD, int))(*(_DWORD *)a1[2387] + 356))(a1[2387], 324);
  v17 = a1[2387];
  a1[2412] = 0;
  a1[2] = (*(int (__stdcall **)(int, _DWORD))(*(_DWORD *)v17 + 428))(v17, 0);
  v18 = a1[2387];
  v31[0] = 1065353216;
  v31[1] = 1065353216;
  v32 = 1065353216;
  v33 = 0;
  v34 = 1065353216;
  v35 = 1065353216;
  v36 = 1065353216;
  v37 = 0;
  v38 = 0;
  v39 = 0;
  v40 = 0;
  v41 = 1065353216;
  v42 = 0;
  v43 = 0;
  v44 = 0;
  v45 = 0;
  v46 = 0;
  a1[2] = (*(int (__stdcall **)(int, _DWORD *))(*(_DWORD *)v18 + 196))(v18, v31);
  (*(void (__thiscall **)(_DWORD *, int, _DWORD))(*a1 + 44))(a1, 141, 0);
  (*(void (__thiscall **)(_DWORD *, int, int))(*a1 + 44))(a1, 145, 1);
  (*(void (__thiscall **)(_DWORD *, int, int))(*a1 + 44))(a1, 147, 1);
  (*(void (__thiscall **)(_DWORD *, int, int))(*a1 + 44))(a1, 146, 2);
  (*(void (__thiscall **)(_DWORD *, int, _DWORD))(*a1 + 44))(a1, 148, 0);
  (*(void (__thiscall **)(_DWORD *, int, _DWORD))(*a1 + 44))(a1, 137, 0);
  v19 = *a1;
  v20 = a1 + 165;
  a1[1213] = 0;
  if ( (*(int (__thiscall **)(_DWORD *, _DWORD *, int, int, int))(v19 + 404))(a1, a1 + 165, 64, 0x2000, 14) )
    return -1;
  (*(void (__thiscall **)(_DWORD *, _DWORD, _DWORD, _DWORD, int, int, int, _DWORD))(*a1 + 412))(
    a1,
    *v20,
    0,
    0,
    0x2000,
    v27,
    v29,
    0);
  v21 = *(_DWORD *)(*v20 + 76);
  if ( v21 )
  {
    v22 = (_DWORD *)(v21 + 12);
    v23 = 64;
    do
    {
      *(v22 - 1) = 1065353216;
      *v22 = 1065353216;
      v22 += 7;
      --v23;
    }
    while ( v23 );
    (*(void (__thiscall **)(_DWORD *, _DWORD, int))(*a1 + 416))(a1, *v20, 0x2000);
  }
  v24 = a1 + 164;
  if ( (*(int (__thiscall **)(_DWORD *, _DWORD *))(*a1 + 404))(a1, a1 + 164) )
    return -1;
  (*(void (__thiscall **)(_DWORD *, _DWORD, _DWORD, _DWORD, int))(*a1 + 412))(a1, *v24, 0, 0, 4096);
  (*(void (__thiscall **)(_DWORD *, _DWORD, int))(*a1 + 416))(a1, *v24, 4096);
  v25 = a1 + 166;
  if ( (*(int (__thiscall **)(_DWORD *, _DWORD *, int, int))(*a1 + 444))(a1, a1 + 166, 24, 2) )
    return -1;
  (*(void (__thiscall **)(_DWORD *, _DWORD, _DWORD, _DWORD))(*a1 + 452))(a1, *v25, 0, 0);
  v26 = *(_WORD **)(*v25 + 32);
  if ( v26 )
  {
    v26[1] = 1;
    v26[2] = 1;
    v26[5] = 3;
    v26[6] = 3;
    v26[3] = 2;
    v26[4] = 2;
    v26[13] = 7;
    v26[14] = 7;
    v26[23] = 7;
    *v26 = 0;
    v26[7] = 0;
    v26[8] = 4;
    v26[9] = 5;
    v26[10] = 5;
    v26[11] = 6;
    v26[12] = 6;
    v26[15] = 4;
    v26[16] = 0;
    v26[17] = 4;
    v26[18] = 1;
    v26[19] = 5;
    v26[20] = 2;
    v26[21] = 6;
    v26[22] = 3;
    (*(void (__thiscall **)(_DWORD *, _DWORD))(*a1 + 456))(a1, *v25);
  }
  sub_5E4C80(flt_FB29E8, 0.0, 0.0, 150.0);
  sub_5E4CC0(flt_FB29E8, 0.0, 0.0, 0.0);
  sub_5E53E0((int)flt_FB29E8, 0.0, 0.0, 1.0, 1.0, 0x4000);
  sub_5E54E0((int)flt_FB29E8, 1036831949, 1065353216);
  sub_5E5240((int)flt_FB29E8, 1119092736, 90.0, 0);
  sub_5E5050((char *)flt_FB29E8, 14);
  a1[1] |= 0x10000000u;
  return 0;
}
