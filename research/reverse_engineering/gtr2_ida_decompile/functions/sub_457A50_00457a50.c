char __thiscall sub_457A50(int this, float a2)
{
  char result; // al
  double i; // st7
  long double *v5; // esi
  int v6; // ebx
  double v7; // st7
  int v8; // ecx
  double *v9; // esi
  int v10; // ebx
  int v11; // ebx
  double *v12; // eax
  double *v13; // ecx
  double v14; // st7
  int v15; // eax
  double *v16; // ecx
  int v17; // [esp+14h] [ebp-118h]
  double v18; // [esp+1Ch] [ebp-110h]
  int v19; // [esp+1Ch] [ebp-110h]
  double v20; // [esp+24h] [ebp-108h]
  double v21; // [esp+34h] [ebp-F8h]
  double v22; // [esp+3Ch] [ebp-F0h]
  __int64 v23; // [esp+44h] [ebp-E8h]
  __int64 v24; // [esp+4Ch] [ebp-E0h]
  int v25; // [esp+54h] [ebp-D8h]
  int v26; // [esp+58h] [ebp-D4h]
  double v27; // [esp+64h] [ebp-C8h]
  double v28; // [esp+64h] [ebp-C8h]
  double v29; // [esp+6Ch] [ebp-C0h]
  double v30; // [esp+6Ch] [ebp-C0h]
  double v31; // [esp+7Ch] [ebp-B0h]
  double v32; // [esp+84h] [ebp-A8h]
  double v33; // [esp+8Ch] [ebp-A0h]
  double v34; // [esp+9Ch] [ebp-90h]
  _BYTE v35[72]; // [esp+CCh] [ebp-60h] BYREF

  if ( dbl_903EC8 == 1.0 || (result = byte_B6F118) == 0 )
  {
    sub_615460(512);
    sub_450EF0((char *)this);
    for ( i = *(double *)(this + 136); ; i = v34 - v18 )
    {
      sub_4506A0();
      v21 = i * 0.5;
      sub_446B00(this, v21);
      *(double *)(this + 128) = v21 + *(double *)(this + 128);
      sub_4506A0();
      sub_439B70((double *)this);
      sub_4445D0();
      sub_61DD30(this + 6244);
      sub_61DE90(this + 6244);
      sub_61E0D0(v20);
      sub_446A80();
      v22 = v20;
      if ( v20 < 1.0 )
      {
        if ( dword_B6FC28 && v20 != *(double *)(this + 136) )
          v22 = *(double *)(this + 136) / v20 * v20;
        if ( v22 < 1.0 )
        {
          if ( v22 <= 0.5 )
            i = v22 * 0.999 * v20;
          v20 = i;
          if ( i < 0.000003814697265625 )
            v20 = 0.000003814697265625;
          sub_446680(this);
          sub_446B00(this, v20 * 0.5);
          *(double *)(this + 128) = v20 * 0.5 + v29;
          sub_4506A0();
          sub_439B70((double *)this);
          sub_4445D0();
          sub_61DD30(this + 6244);
          sub_61DE90(this + 6244);
          sub_61E0D0(v18);
          sub_446A80();
        }
      }
      if ( v34 <= v18 )
        break;
      *(double *)(this + 128) = v27 + v18;
    }
    *(double *)(this + 6432) = *(double *)(this + 2336) + *(double *)(this + 1056);
    *(double *)(this + 128) = a2;
    sub_443D30(this);
    v5 = (long double *)(this + 888);
    v6 = 4;
    do
    {
      *v5 = fmod(*v5, 6.283185307179586);
      sub_4401A0((int)(v5 - 22), *(double *)(this + 136));
      v5 += 160;
      --v6;
    }
    while ( v6 );
    sub_4407C0(this + 712, *(double *)(this + 136), *(double **)(this + 1068));
    sub_4407C0(this + 1992, *(double *)(this + 136), *(double **)(this + 2348));
    v7 = *(double *)(this + 136);
    v8 = this + 3272;
    if ( *(_DWORD *)(this + 5832) )
    {
      sub_4407C0(v8, v7, *(double **)(this + 5832));
      sub_4407C0(this + 4552, *(double *)(this + 136), *(double **)(this + 5832));
    }
    else
    {
      sub_4407C0(v8, v7, *(double **)(this + 3628));
      sub_4407C0(this + 4552, *(double *)(this + 136), *(double **)(this + 4908));
    }
    v9 = (double *)(this + 1944);
    v10 = 4;
    do
    {
      if ( (*(v9 - 3) - *v9) / (v9[1] - *v9) < 0.33000001 )
        sub_4FB7E0(*(_DWORD *)(this + 9392) + 14824, 1, 9);
      v9 += 160;
      --v10;
    }
    while ( v10 );
    v11 = this + 848;
    v19 = 4;
    do
    {
      v12 = *(double **)(v11 + 220);
      if ( v12 )
      {
        if ( !*(_BYTE *)(v11 + 320) )
        {
          v13 = *(double **)(this + 6312);
          v31 = v12[4];
          v32 = v12[7];
          v33 = v12[10];
          if ( v33 * v13[10] + v32 * v13[7] + v31 * v13[4] < 0.5
            || fabs(v33 * v13[11] + v32 * v13[8] + v31 * v13[5]) > 0.7 )
          {
            v28 = v13[5] * *(double *)v11 + v13[6] * *(double *)(v11 + 8) + v13[4] * *(double *)(v11 - 8) + v13[1];
            v30 = v13[8] * *(double *)v11 + v13[9] * *(double *)(v11 + 8) + v13[7] * *(double *)(v11 - 8) + v13[2];
            v14 = v13[11] * *(double *)v11 + v13[12] * *(double *)(v11 + 8) + v13[10] * *(double *)(v11 - 8) + v13[3];
            qmemcpy(v35, v13 + 4, sizeof(v35));
            sub_61B900(v11 + 16, 0);
            v23 = *(_QWORD *)(*(_DWORD *)(HIDWORD(v20) + 6312) + 128);
            v24 = *(_QWORD *)(*(_DWORD *)(HIDWORD(v20) + 6312) + 136);
            v15 = *(_DWORD *)(*(_DWORD *)(HIDWORD(v20) + 6312) + 148);
            v16 = (double *)(*(_DWORD *)(v11 + 220) + 8);
            v25 = *(_DWORD *)(*(_DWORD *)(HIDWORD(v20) + 6312) + 144);
            *v16 = v28;
            v26 = v15;
            v16[1] = v30;
            v16[2] = v14;
            v17 = *(_DWORD *)(v11 + 220);
            qmemcpy((void *)(v17 + 32), v35, 0x48u);
            sub_618D20(v17);
            *(_QWORD *)(v17 + 128) = v23;
            *(_QWORD *)(v17 + 136) = v24;
            *(_DWORD *)(v17 + 144) = v25;
            *(_DWORD *)(v17 + 148) = v26;
            sub_618E60(v17);
            sub_446A80();
            this = HIDWORD(v20);
          }
        }
      }
      v11 += 1280;
      result = --v19;
    }
    while ( v19 );
    if ( HIDWORD(v21) != 512 )
      return sub_6154A0(HIDWORD(v21));
  }
  return result;
}
