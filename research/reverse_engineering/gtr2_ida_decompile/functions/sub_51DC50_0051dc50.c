_DWORD *__thiscall sub_51DC50(_DWORD *this, int a2, int a3)
{
  int *v3; // eax
  int v4; // ecx
  double v5; // st7
  float *v6; // eax
  int v7; // esi
  float *v8; // edi
  int v9; // eax
  int v10; // ecx
  int v11; // eax
  int v12; // eax
  int v13; // eax
  _DWORD *v14; // ebx
  float *v15; // ebp
  _DWORD *result; // eax
  double v17; // st7
  double v18; // st7
  _DWORD *v19; // ecx
  int v20; // [esp+10h] [ebp-A4h]
  float v21; // [esp+14h] [ebp-A0h] BYREF
  float v22; // [esp+18h] [ebp-9Ch]
  float v23; // [esp+1Ch] [ebp-98h]
  _DWORD *v24; // [esp+20h] [ebp-94h]
  float v25; // [esp+24h] [ebp-90h] BYREF
  float v26; // [esp+28h] [ebp-8Ch]
  float v27; // [esp+2Ch] [ebp-88h]
  int v28; // [esp+30h] [ebp-84h]
  _DWORD v29[3]; // [esp+34h] [ebp-80h] BYREF
  float v30[3]; // [esp+40h] [ebp-74h] BYREF
  int v31; // [esp+4Ch] [ebp-68h] BYREF
  _DWORD v32[16]; // [esp+50h] [ebp-64h] BYREF
  char v33[8]; // [esp+90h] [ebp-24h] BYREF
  char v34; // [esp+98h] [ebp-1Ch] BYREF
  char v35[12]; // [esp+9Ch] [ebp-18h] BYREF
  char v36[12]; // [esp+A8h] [ebp-Ch] BYREF

  memset(v32, 0, sizeof(v32));
  v3 = (int *)this[7];
  v32[15] = 1065353216;
  v32[10] = 1065353216;
  v32[5] = 1065353216;
  v32[0] = 1065353216;
  v31 = 1;
  v4 = *v3;
  v5 = *(float *)(a3 + 36);
  v28 = v3[26];
  v25 = v5 * *(float *)(a3 + 32) + *(float *)(a3 + 4);
  v20 = (v4 & 8) != 0 ? 0x8000 : 4096;
  v26 = *(float *)(a3 + 40) * *(float *)(a3 + 32) + *(float *)(a3 + 8);
  v6 = *(float **)(a3 + 276);
  v27 = *(float *)(a3 + 44) * *(float *)(a3 + 32) + *(float *)(a3 + 12);
  v21 = v6[9] * v6[8] + v6[1];
  v22 = v6[10] * v6[8] + v6[2];
  v23 = v6[11] * v6[8] + v6[3];
  sub_51D2B0(&v25, &v21, (int)&v31);
  sub_5EB210(a2, v33, v35, v36);
  v7 = 0;
  v8 = (float *)&v34;
  do
  {
    if ( a2 >= *(_DWORD *)(v28 + 368) )
      v9 = 0;
    else
      v9 = *(_DWORD *)(v28 + 372) + 36 * a2;
    if ( v7 < 0 )
    {
      v13 = 0;
    }
    else
    {
      v10 = *(_DWORD *)(v9 + 8);
      v11 = *(unsigned __int16 *)(v7 + v9);
      if ( (*(_BYTE *)v10 & 8) != 0 )
        v12 = 88 * v11;
      else
        v12 = v11 << 6;
      v13 = *(_DWORD *)(v10 + 32) + v12;
    }
    if ( v20 == 4096 )
    {
      v14 = (_DWORD *)(v13 + 32);
      v15 = (float *)(v13 + 48);
      result = (_DWORD *)(v13 + 52);
    }
    else
    {
      v14 = (_DWORD *)(v13 + 56);
      v15 = (float *)(v13 + 72);
      result = (_DWORD *)(v13 + 76);
    }
    v24 = result;
    if ( *v14 == 1036831949 )
    {
      v21 = *(v8 - 2) - v25;
      v17 = *(v8 - 1);
      *(float *)v29 = v21;
      v22 = v17 - v26;
      v18 = *v8;
      *(float *)&v29[1] = v22;
      v23 = v18 - v27;
      *(float *)&v29[2] = v23;
      result = (_DWORD *)sub_5D77B0(v29, v30, v32);
      v19 = v24;
      *v15 = v30[0] * 0.1 + 0.5;
      *v19 = 953267991;
      *v14 = 1050253722;
    }
    v7 += 2;
    v8 += 3;
  }
  while ( v7 < 6 );
  return result;
}
