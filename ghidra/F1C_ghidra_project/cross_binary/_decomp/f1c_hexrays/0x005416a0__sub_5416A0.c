// f1c  0x005416a0  size=356
int __thiscall sub_5416A0(int *this, int a2, int a3, int a4)
{
  int v5; // eax
  int v6; // ecx
  int v7; // ecx
  int v8; // eax
  int v9; // edx
  int v10; // ecx
  double v11; // st7
  int v12; // eax
  double v13; // st7
  double v14; // st7
  int v15; // edx
  int v16; // eax
  double v17; // st7
  int v18; // eax
  _DWORD v20[26]; // [esp+Ch] [ebp-68h] BYREF

  if ( this[1270] && a4 != 1 )
  {
    memset(v20, 0, sizeof(v20));
    switch ( *(_DWORD *)a2 & 7 )
    {
      case 1:
        v20[0] = 3;
        v20[19] = 1399379109;
        break;
      case 2:
        v6 = *(_DWORD *)(a2 + 80);
        v20[0] = 1;
        v20[19] = v6;
        break;
      case 4:
        v5 = *(_DWORD *)(a2 + 80);
        v20[0] = 1;
        v20[19] = v5;
        break;
    }
    v7 = *(_DWORD *)(a2 + 76);
    v8 = *(_DWORD *)(a2 + 72);
    v9 = *(_DWORD *)(a2 + 68);
    *(float *)&v20[9] = *(float *)(a2 + 8) * *(float *)(a2 + 20);
    v20[18] = v7;
    v10 = *(_DWORD *)(a2 + 64);
    v11 = *(float *)(a2 + 12) * *(float *)(a2 + 20);
    v20[17] = v8;
    v12 = *(_DWORD *)(a2 + 60);
    v20[15] = v10;
    *(float *)&v20[10] = v11;
    v13 = *(float *)(a2 + 16);
    v20[16] = v9;
    v14 = v13 * *(float *)(a2 + 20);
    v15 = *(_DWORD *)(a2 + 56);
    v20[14] = v12;
    *(float *)&v20[11] = v14;
    v16 = this[1088];
    v17 = *(float *)(a2 + 24) * *(float *)(a2 + 36);
    v20[13] = v15;
    v20[21] = 1065353216;
    v20[22] = 0;
    *(float *)&v20[1] = v17;
    v20[23] = 0;
    *(float *)&v20[2] = *(float *)(a2 + 28) * *(float *)(a2 + 36);
    *(float *)&v20[3] = *(float *)(a2 + 32) * *(float *)(a2 + 36);
    *(float *)&v20[5] = *(float *)(a2 + 40) * *(float *)(a2 + 52);
    *(float *)&v20[6] = *(float *)(a2 + 44) * *(float *)(a2 + 52);
    *(float *)&v20[7] = *(float *)(a2 + 48) * *(float *)(a2 + 52);
    v18 = (*(int (__stdcall **)(int, int, _DWORD *))(*(_DWORD *)v16 + 176))(v16, a3, v20);
    *this = v18;
    if ( v18 )
      return -1;
    if ( (*(_BYTE *)a2 & 1) != 0 )
      *this = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)this[1088] + 184))(this[1088], a3, 1);
  }
  return 0;
}
