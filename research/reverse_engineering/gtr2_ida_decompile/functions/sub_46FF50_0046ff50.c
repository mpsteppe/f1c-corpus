_DWORD *__thiscall sub_46FF50(int this, _DWORD *a2)
{
  _DWORD *v3; // edi
  int v4; // edx
  double v5; // st7
  int v6; // ecx
  double v7; // st7
  int v8; // edx
  double v9; // st7
  int v10; // ecx
  double v11; // st7
  int v12; // edx
  int v13; // eax
  int v14; // edx
  int v15; // eax
  int v16; // edx
  int v17; // eax
  int v18; // ecx
  int v19; // edx
  _DWORD *v20; // esi
  _DWORD *result; // eax
  int v22; // ecx
  double v23; // [esp+Ch] [ebp-48h] BYREF
  double v24; // [esp+14h] [ebp-40h]
  double v25; // [esp+1Ch] [ebp-38h]
  double v26; // [esp+24h] [ebp-30h]
  double v27; // [esp+2Ch] [ebp-28h]
  double v28; // [esp+34h] [ebp-20h]
  double v29[3]; // [esp+3Ch] [ebp-18h] BYREF

  if ( *(_DWORD *)(this + 216) )
  {
    sub_5DB2B0(
      *(_DWORD *)(this + 8),
      *(_DWORD *)(this + 12),
      *(_DWORD *)(this + 16),
      *(float *)(this + 20),
      *(float *)(this + 24),
      *(float *)(this + 28));
    sub_5ED990(0x8000000);
  }
  v3 = (_DWORD *)(this + 8);
  v26 = *(float *)(this + 8);
  v4 = HIDWORD(v26);
  v27 = *(float *)(this + 12);
  v5 = *(float *)(this + 16);
  *(_DWORD *)(this + 232) = LODWORD(v26);
  v6 = LODWORD(v27);
  v28 = v5;
  v7 = *(float *)(this + 20);
  *(_DWORD *)(this + 236) = v4;
  v8 = HIDWORD(v27);
  v29[0] = v7;
  v9 = *(float *)(this + 24);
  *(_DWORD *)(this + 240) = v6;
  v10 = LODWORD(v28);
  v29[1] = v9;
  v11 = *(float *)(this + 28);
  *(_DWORD *)(this + 244) = v8;
  v12 = HIDWORD(v28);
  v29[2] = v11;
  *(_DWORD *)(this + 248) = v10;
  v23 = 0.0;
  *(_DWORD *)(this + 252) = v12;
  v24 = 0.0;
  v25 = 0.0;
  sub_61B6E0(v29);
  v13 = HIDWORD(v23);
  *(_DWORD *)(this + 328) = LODWORD(v23);
  v14 = LODWORD(v24);
  *(_DWORD *)(this + 332) = v13;
  v15 = HIDWORD(v24);
  *(_DWORD *)(this + 336) = v14;
  v16 = LODWORD(v25);
  *(_DWORD *)(this + 340) = v15;
  v17 = HIDWORD(v25);
  *(_DWORD *)(this + 344) = v16;
  *(_DWORD *)(this + 348) = v17;
  sub_61B710(&v23);
  v18 = *(_DWORD *)(this + 12);
  v19 = *(_DWORD *)(this + 16);
  v20 = (_DWORD *)(this + 200);
  *v20 = *v3;
  result = a2;
  v20[1] = v18;
  v22 = *v3;
  v20[2] = v19;
  *a2 = v22;
  a2[1] = v3[1];
  a2[2] = v3[2];
  return result;
}
