int __thiscall sub_5F81B0(_DWORD *this, int a2, int a3)
{
  int result; // eax
  int v4; // ebp
  int v5; // ebx
  int v6; // esi
  unsigned int v7; // edx
  int v8; // ebx
  int v9; // eax
  float *v10; // edi
  float *v11; // ebx
  int v12; // esi
  double v13; // st7
  int v14; // [esp+1Ch] [ebp-28h]
  int *v15; // [esp+1Ch] [ebp-28h]
  int v16; // [esp+20h] [ebp-24h]
  float v17; // [esp+24h] [ebp-20h]
  float v18; // [esp+28h] [ebp-1Ch] BYREF
  float v19; // [esp+2Ch] [ebp-18h] BYREF
  float v20; // [esp+30h] [ebp-14h] BYREF
  _DWORD v21[4]; // [esp+34h] [ebp-10h] BYREF
  char *v22; // [esp+4Ch] [ebp+8h]
  int v23; // [esp+4Ch] [ebp+8h]

  result = a3;
  v4 = *(_DWORD *)(*(_DWORD *)(a3 + 104) + 392);
  if ( v4 )
  {
    if ( this[84] == 3 )
    {
      v21[0] = *(_DWORD *)(v4 + 568);
      v21[1] = 0;
      v21[2] = 1;
      v21[3] = 0;
      v16 = 136;
      (*(void (__stdcall **)(int, _DWORD, _DWORD *, int))(*(_DWORD *)dword_FB40C8 + 384))(dword_FB40C8, 0, v21, 1);
    }
    else
    {
      v5 = *(_DWORD *)(v4 + 568);
      v16 = 84;
      if ( v5 < 8 )
      {
        v6 = 8 - v5;
        v7 = 16 * (8 - v5);
        v14 = v5 + 72;
        v22 = &byte_FB2EB8[16 * v5 + 1152];
        memset(v22, 0, 4 * (v7 >> 2));
        v8 = v5 + 84;
        memset(&byte_FB2EB8[16 * v8], 0, v7);
        (*(void (__stdcall **)(int, int, char *, int))(*(_DWORD *)dword_FB40C8 + 376))(dword_FB40C8, v14, v22, v6);
        (*(void (__stdcall **)(int, int, char *, int))(*(_DWORD *)dword_FB40C8 + 376))(
          dword_FB40C8,
          v8,
          &byte_FB2EB8[16 * v8],
          v6);
      }
    }
    v9 = *(_DWORD *)(v4 + 568);
    if ( v9 > 0 )
    {
      v23 = 0;
      v10 = (float *)&byte_FB2EB8[16 * v16];
      v11 = (float *)&unk_FB333C;
      v15 = (int *)(v4 + 572);
      do
      {
        if ( v23 >= v9 )
          v12 = 0;
        else
          v12 = *v15;
        sub_6007A0(v11 - 1, v11, v11 + 1);
        v17 = sub_6007E0(v12);
        v11[2] = sub_6007E0(v12) * v17;
        v10[3] = 1.0 / sub_6007E0(v12);
        sub_6006C0(2, &v18, &v19, &v20);
        v13 = sub_600770(2);
        *v10 = v18 * v13;
        v11 += 4;
        v10 += 4;
        ++v23;
        ++v15;
        *(v10 - 3) = v19 * v13;
        *(v10 - 2) = v13 * v20;
        v9 = *(_DWORD *)(v4 + 568);
      }
      while ( v23 < v9 );
      (*(void (__stdcall **)(int, int, void *, _DWORD))(*(_DWORD *)dword_FB40C8 + 376))(
        dword_FB40C8,
        72,
        &unk_FB3338,
        *(_DWORD *)(v4 + 568));
      (*(void (__stdcall **)(int, int, char *, _DWORD))(*(_DWORD *)dword_FB40C8 + 376))(
        dword_FB40C8,
        v16,
        &byte_FB2EB8[16 * v16],
        *(_DWORD *)(v4 + 568));
    }
    result = dword_FB27A4;
    *(_DWORD *)(dword_FB27A4 + 4) &= ~0x80000000;
  }
  return result;
}
