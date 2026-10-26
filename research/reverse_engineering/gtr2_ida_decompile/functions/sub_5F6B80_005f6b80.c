int __fastcall sub_5F6B80(int a1, void *a2)
{
  float *v3; // eax
  float v4; // eax
  int result; // eax
  int v6; // [esp-4h] [ebp-28h]
  int v7; // [esp+0h] [ebp-24h]
  int v8; // [esp+4h] [ebp-20h]
  float v9; // [esp+10h] [ebp-14h]
  _DWORD v10[4]; // [esp+14h] [ebp-10h] BYREF

  dword_FB3EB8 = 0;
  dword_FB3EBC = 0;
  dword_FB2EB0 = 0;
  if ( a1 )
  {
    dword_FB40C0 = a1;
    if ( *(int *)(a1 + 764) > 0 && (v3 = *(float **)(a1 + 752)) != 0 )
      v4 = *v3;
    else
      v4 = 0.0;
    dword_FB40C4 = LODWORD(v4);
    sub_5D8A70(a1, v4, (float *)&dword_FB2F58);
    (*(void (__fastcall **)(int, _DWORD, unsigned int))(*(_DWORD *)dword_FB27A4 + 528))(
      dword_FB27A4,
      (unsigned __int64)(flt_FB2F64 * 255.0) >> 32,
      (unsigned int)(unsigned __int64)(flt_FB2F64 * 255.0) << 24);
    v9 = sub_5DCEC0((float *)dword_FB40C0);
    flt_FB2F48 = 1.0 / (v9 - sub_5DCEB0((float *)dword_FB40C0));
    flt_FB2F4C = sub_5DCEC0((float *)dword_FB40C0) * flt_FB2F48;
    (*(void (__stdcall **)(int, int, float *, int))(*(_DWORD *)dword_FB40C8 + 376))(dword_FB40C8, 9, &flt_FB2F48, 1);
    if ( !*(_DWORD *)(dword_FB40C0 + 768) )
    {
      v10[0] = 0;
      v10[1] = 0;
      v10[2] = 1;
      v10[3] = 0;
      (*(void (__stdcall **)(int, _DWORD, _DWORD *, int))(*(_DWORD *)dword_FB40C8 + 384))(dword_FB40C8, 0, v10, 1);
    }
  }
  if ( a2 )
  {
    dword_FB3EBC = (int)a2;
    sub_5E4D90(a2, (int)&dword_FB2F38, (int)&dword_FB2F3C, (int)&dword_FB2F40);
    (*(void (__stdcall **)(int, int, char *, int, int, int, int))(*(_DWORD *)dword_FB40C8 + 376))(
      dword_FB40C8,
      4,
      (char *)dword_FB27A8 + 4,
      4,
      v6,
      v7,
      v8);
    (*(void (__stdcall **)(int, _DWORD, int, int))(*(_DWORD *)dword_FB40C8 + 376))(
      dword_FB40C8,
      0,
      dword_FB3EBC + 700,
      4);
    (*(void (__stdcall **)(int, int, int *, int))(*(_DWORD *)dword_FB40C8 + 376))(dword_FB40C8, 8, &dword_FB2F38, 1);
    (*(void (__stdcall **)(int, int, char *))(*(_DWORD *)dword_FB40C8 + 176))(
      dword_FB40C8,
      256,
      (char *)dword_FB27A8 + 4);
    (*(void (__stdcall **)(int, int, int))(*(_DWORD *)dword_FB40C8 + 176))(dword_FB40C8, 2, dword_FB3EBC + 348);
    result = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)dword_FB40C8 + 176))(dword_FB40C8, 3, dword_FB3EBC + 632);
  }
  else
  {
    dword_FB2F40 = 0;
    dword_FB2F3C = 0;
    dword_FB2F38 = 0;
    (*(void (__stdcall **)(int, int, char *, int))(*(_DWORD *)dword_FB40C8 + 376))(
      dword_FB40C8,
      4,
      (char *)dword_FB27A8 + 4,
      4);
    (*(void (__stdcall **)(int, _DWORD, char *, int))(*(_DWORD *)dword_FB40C8 + 376))(
      dword_FB40C8,
      0,
      (char *)dword_FB27A8 + 4,
      4);
    (*(void (__stdcall **)(int, int, int *, int))(*(_DWORD *)dword_FB40C8 + 376))(dword_FB40C8, 8, &dword_FB2F38, 1);
    (*(void (__stdcall **)(int, int, char *))(*(_DWORD *)dword_FB40C8 + 176))(dword_FB40C8, 2, (char *)dword_FB27A8 + 4);
    result = (*(int (__stdcall **)(int, int, char *))(*(_DWORD *)dword_FB40C8 + 176))(
               dword_FB40C8,
               3,
               (char *)dword_FB27A8 + 4);
  }
  dword_FB2EB4 = 0;
  return result;
}
