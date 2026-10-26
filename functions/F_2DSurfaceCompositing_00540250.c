int __thiscall sub_540250(int *this, _DWORD *a2, int a3, int a4, _DWORD *a5, int a6, int a7, int a8, int a9, int a10)
{
  int v10; // edx
  BOOL v12; // edi
  _DWORD *v13; // ecx
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v18; // eax
  int v19; // ecx
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // eax
  int v25; // [esp+44h] [ebp-48h] BYREF
  int v26; // [esp+48h] [ebp-44h] BYREF
  int v27; // [esp+4Ch] [ebp-40h]
  int v28; // [esp+50h] [ebp-3Ch]
  int v29; // [esp+54h] [ebp-38h] BYREF
  int v30; // [esp+58h] [ebp-34h]
  int v31; // [esp+5Ch] [ebp-30h] BYREF
  int v32; // [esp+60h] [ebp-2Ch]
  int v33; // [esp+64h] [ebp-28h]
  int v34; // [esp+68h] [ebp-24h]
  _DWORD v35[4]; // [esp+6Ch] [ebp-20h] BYREF
  _DWORD v36[4]; // [esp+7Ch] [ebp-10h] BYREF

  v10 = 0;
  v26 = 0;
  v25 = 0;
  v27 = 0;
  v28 = 0;
  v12 = a10 == -2;
  v13 = a5;
  if ( (int)a2[12] > 8 || (int)a5[12] > 8 )
    v12 = 1;
  v14 = a2[6];
  if ( (v14 & 1) != 0 )
  {
    v10 = a2[2];
  }
  else
  {
    if ( (v14 & 2) == 0 )
      goto LABEL_9;
    v10 = a2[3];
  }
  v26 = v10;
  if ( v10 )
    goto LABEL_17;
LABEL_9:
  if ( (v14 & 4) != 0 )
  {
    v15 = a2[4];
  }
  else
  {
    if ( (v14 & 8) == 0 )
      goto LABEL_17;
    v15 = a2[5];
  }
  v27 = v15;
  if ( v15 )
  {
    v16 = (*(int (__stdcall **)(int, _DWORD, int *))(*(_DWORD *)v15 + 60))(v15, 0, &v26);
    *this = v16;
    if ( v16 )
      return -1;
    v10 = v26;
    v13 = a5;
  }
LABEL_17:
  v18 = v13[6];
  if ( (v18 & 1) != 0 )
  {
    v19 = v13[2];
  }
  else
  {
    if ( (v18 & 2) == 0 )
      goto LABEL_22;
    v19 = v13[3];
  }
  v25 = v19;
  v13 = a5;
LABEL_22:
  if ( v25 )
    goto LABEL_31;
  if ( (v18 & 4) != 0 )
  {
    v28 = v13[4];
  }
  else
  {
    if ( (v18 & 8) == 0 )
      goto LABEL_31;
    v28 = v13[5];
  }
  if ( v28 )
  {
    v20 = (*(int (__stdcall **)(int, _DWORD, int *))(*(_DWORD *)v28 + 60))(v28, 0, &v25);
    *this = v20;
    if ( v20 )
      return -1;
    v10 = v26;
  }
LABEL_31:
  if ( v12 )
  {
    v31 = a3;
    v33 = a8 + a3;
    v32 = a4;
    v34 = a9 + a4;
    v30 = a7;
    v21 = this[1088];
    v29 = a6;
    v22 = (*(int (__stdcall **)(int, int, int *, int, int, int *))(*(_DWORD *)v21 + 112))(v21, v10, &v31, 1, v25, &v29);
    *this = v22;
    if ( v22 )
      return -1;
  }
  else
  {
    v35[1] = a4;
    v35[3] = a9 + a4;
    v35[0] = a3;
    v35[2] = a8 + a3;
    v23 = (*(int (__stdcall **)(int, int *, _DWORD *, int))(*(_DWORD *)v10 + 36))(v10, &v31, v35, 16);
    *this = v23;
    if ( v23 )
      return -1;
    v36[1] = a7;
    v36[3] = a9 + a7;
    v36[0] = a6;
    v36[2] = a8 + a6;
    v24 = (*(int (__stdcall **)(int, int *, _DWORD *, _DWORD))(*(_DWORD *)v25 + 36))(v25, &v29, v36, 0);
    *this = v24;
    if ( v24 )
      return -1;
    AudioPlaybackDispatcher(v32, v31, v30, v29, a8, a9, a10, a2[12]);
    (*(void (__stdcall **)(int))(*(_DWORD *)v26 + 40))(v26);
    (*(void (__stdcall **)(int))(*(_DWORD *)v25 + 40))(v25);
  }
  if ( v27 )
    *this = (*(int (__stdcall **)(int))(*(_DWORD *)v26 + 8))(v26);
  if ( v28 )
    *this = (*(int (__stdcall **)(int))(*(_DWORD *)v25 + 8))(v25);
  a5[6] &= ~0x400u;
  return 0;
}
