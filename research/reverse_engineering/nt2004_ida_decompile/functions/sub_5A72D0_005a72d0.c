int __thiscall sub_5A72D0(int *this, _DWORD *a2, int a3, int a4, _DWORD *a5, int a6, int a7, int a8, int a9, int a10)
{
  int v10; // ebx
  int v11; // ebp
  int v13; // ecx
  int v14; // eax
  BOOL v15; // edi
  int v16; // eax
  int v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // eax
  int v25; // [esp+44h] [ebp-50h] BYREF
  int v26; // [esp+48h] [ebp-4Ch] BYREF
  int v27; // [esp+4Ch] [ebp-48h]
  int v28; // [esp+50h] [ebp-44h]
  BOOL v29; // [esp+54h] [ebp-40h] BYREF
  int v30; // [esp+58h] [ebp-3Ch]
  int v31; // [esp+5Ch] [ebp-38h]
  int v32; // [esp+60h] [ebp-34h]
  int v33; // [esp+64h] [ebp-30h] BYREF
  int v34; // [esp+68h] [ebp-2Ch]
  int v35; // [esp+6Ch] [ebp-28h]
  int v36; // [esp+70h] [ebp-24h]
  _DWORD v37[4]; // [esp+74h] [ebp-20h] BYREF
  _DWORD v38[4]; // [esp+84h] [ebp-10h] BYREF

  v10 = 0;
  v11 = 0;
  v33 = 0;
  v26 = 0;
  v25 = 0;
  v27 = 0;
  v28 = 0;
  v29 = a10 == -2;
  v13 = a2[12];
  if ( v13 > 8 || (int)a5[12] > 8 )
    v29 = 1;
  v14 = a2[14];
  if ( (v14 & 0xA) != 0 && (v14 & 5) == 0 )
    v29 = 1;
  if ( v13 == a5[12] )
  {
    v15 = v29;
  }
  else
  {
    v15 = 0;
    v33 = 1;
  }
  if ( (v14 & 1) != 0 )
  {
    v10 = a2[3];
  }
  else
  {
    if ( (v14 & 2) == 0 )
      goto LABEL_15;
    v10 = a2[4];
  }
  v26 = v10;
  if ( v10 )
    goto LABEL_23;
LABEL_15:
  if ( (v14 & 4) != 0 )
  {
    v27 = a2[5];
  }
  else
  {
    if ( (v14 & 8) == 0 )
      goto LABEL_23;
    v27 = a2[6];
  }
  if ( v27 )
  {
    v16 = (*(int (__stdcall **)(int, _DWORD, int *))(*(_DWORD *)v27 + 60))(v27, 0, &v26);
    *this = v16;
    if ( v16 )
      return -1;
    v10 = v26;
    v11 = v25;
  }
LABEL_23:
  v18 = a5[14];
  if ( (v18 & 1) != 0 )
  {
    v11 = a5[3];
  }
  else
  {
    if ( (v18 & 2) == 0 )
      goto LABEL_28;
    v11 = a5[4];
  }
  v25 = v11;
LABEL_28:
  if ( v11 )
    goto LABEL_37;
  if ( (v18 & 4) != 0 )
  {
    v28 = a5[5];
  }
  else
  {
    if ( (v18 & 8) == 0 )
      goto LABEL_37;
    v28 = a5[6];
  }
  if ( v28 )
  {
    v19 = (*(int (__stdcall **)(int, _DWORD, int *))(*(_DWORD *)v28 + 60))(v28, 0, &v25);
    *this = v19;
    if ( v19 )
      return -1;
    v10 = v26;
    v11 = v25;
  }
LABEL_37:
  if ( v15 )
  {
    v29 = a3;
    v34 = a7;
    v31 = a8 + a3;
    v30 = a4;
    v20 = this[1112];
    v32 = a9 + a4;
    v33 = a6;
    v21 = (*(int (__stdcall **)(int, int, BOOL *, int, int, int *))(*(_DWORD *)v20 + 112))(v20, v10, &v29, 1, v11, &v33);
    *this = v21;
    if ( v21 )
      return -1;
  }
  else if ( v33 )
  {
    v33 = a3;
    v34 = a4;
    v35 = a8 + a3;
    v36 = a9 + a4;
    v30 = a7;
    v29 = a6;
    v31 = a8 + a6;
    v32 = a9 + a7;
    v22 = sub_53D7A1(v11, 0, &v29, v10, 0, &v33, 1, 0);
    *this = v22;
    if ( v22 )
      return -1;
  }
  else
  {
    v37[0] = a3;
    v37[1] = a4;
    v37[2] = a8 + a3;
    v37[3] = a9 + a4;
    v23 = (*(int (__stdcall **)(int, BOOL *, _DWORD *, int))(*(_DWORD *)v10 + 36))(v10, &v29, v37, 16);
    *this = v23;
    if ( v23 )
      return -1;
    v38[1] = a7;
    v38[3] = a9 + a7;
    v38[0] = a6;
    v38[2] = a8 + a6;
    v24 = (*(int (__stdcall **)(int, int *, _DWORD *, _DWORD))(*(_DWORD *)v25 + 36))(v25, &v33, v38, 0);
    *this = v24;
    if ( v24 )
      return -1;
    sub_5A7220(v30, v29, v34, v33, a8, a9, a10, a2[12]);
    (*(void (__stdcall **)(int))(*(_DWORD *)v26 + 40))(v26);
    (*(void (__stdcall **)(int))(*(_DWORD *)v25 + 40))(v25);
  }
  if ( v27 )
    *this = (*(int (__stdcall **)(int))(*(_DWORD *)v26 + 8))(v26);
  if ( v28 )
    *this = (*(int (__stdcall **)(int))(*(_DWORD *)v25 + 8))(v25);
  a5[14] &= ~0x400u;
  return 0;
}
