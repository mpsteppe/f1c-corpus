void __thiscall sub_53EC40(int this, _DWORD *a2, int a3)
{
  int *v4; // esi
  int v5; // ebp
  int v6; // ebx
  int v7; // eax
  unsigned int v8; // eax
  int v9; // eax
  unsigned int v10; // eax
  int v11; // eax
  unsigned int v12; // eax
  int v13; // eax
  unsigned int v14; // eax
  int v15; // eax
  unsigned int v16; // eax
  char v17; // al
  bool v18; // zf
  int v19; // eax
  unsigned int v20; // eax
  int v21; // eax
  unsigned int v22; // eax
  int v23; // eax
  unsigned int v24; // eax
  int v25; // eax
  unsigned int v26; // eax
  float v27; // [esp+8h] [ebp-14h]
  float *v28; // [esp+28h] [ebp+Ch]

  if ( *(float *)&a3 == -3.4028235e38 )
    *(float *)&a3 = dbl_FB1D18;
  else
    sub_578160(*(float *)&a3);
  sub_51B2A0(a2, 1, 0, 52, *(_DWORD *)(this + 22468), a3, 0);
  v4 = a2 + 2;
  a2[9] = *(_DWORD *)(this + 2792);
  a2[10] = *(_DWORD *)(this + 2796);
  a2[11] = *(_DWORD *)(this + 2800);
  a2[12] = *(_DWORD *)(this + 2728);
  a2[13] = *(_DWORD *)(this + 2732);
  a2[14] = *(_DWORD *)(this + 2736);
  sub_51A830(a2 + 6, (float *)(this + 16012));
  sub_51A940((int)(a2 + 6), (float *)(this + 16036));
  sub_51AAF0((float *)(this + 16088));
  v5 = 0;
  v6 = 0;
  v28 = (float *)(this + 16212);
  do
  {
    v27 = *(float *)(v6 + this + 3176) + *(float *)(this + 2784);
    sub_51ABA0(v4, v5, v27, *v28);
    v6 += 296;
    ++v5;
    v28 += 63;
  }
  while ( v6 < 1184 );
  sub_51AD40(v4, *(float *)(this + 17228));
  v7 = *v4;
  if ( *(_DWORD *)(this + 21788) )
    v8 = v7 | 0x20000;
  else
    v8 = v7 & 0xFFFDFFFF;
  *v4 = v8;
  sub_51AD90(v4, *(float *)(this + 16148));
  sub_51A1B0(v4, *(_DWORD *)(this + 17320));
  v9 = *v4;
  if ( *(_BYTE *)(this + 5776) )
    v10 = v9 | 0x80;
  else
    v10 = v9 & 0xFFFFFF7F;
  *v4 = v10;
  sub_51ADC0(v4, *(float *)(this + 16152));
  sub_51ADF0();
  v11 = a2[3];
  if ( (*(_DWORD *)(this + 22580) & 2) != 0 )
    v12 = v11 & 0xDFFFFFFF;
  else
    v12 = v11 | 0x20000000;
  a2[3] = v12;
  v13 = a2[3];
  if ( *(_BYTE *)(this + 5754) )
    v14 = v13 | 0x8000000;
  else
    v14 = v13 & 0xF7FFFFFF;
  a2[3] = v14;
  v15 = a2[3];
  if ( *(float *)(this + 16156) <= 0.0099999998 )
    v16 = v15 & 0xFBFFFFFF;
  else
    v16 = v15 | 0x4000000;
  a2[3] = v16;
  if ( *(_DWORD *)(this + 14820) == 4 )
    v17 = 0;
  else
    v17 = *(_BYTE *)(this + 5765);
  v18 = v17 == 0;
  v19 = a2[3];
  if ( v18 )
    v20 = v19 & 0xFDFFFFFF;
  else
    v20 = (unsigned int)&dword_2000000 | v19;
  a2[3] = v20;
  v21 = a2[3];
  if ( *(_BYTE *)(this + 5767) )
    v22 = v21 | 0x40000000;
  else
    v22 = v21 & 0xBFFFFFFF;
  a2[3] = v22;
  v23 = a2[3];
  if ( *(_BYTE *)(this + 15572) )
    v24 = v23 | 0x80000000;
  else
    v24 = v23 & 0x7FFFFFFF;
  a2[3] = v24;
  v25 = a2[3];
  if ( *(_BYTE *)(this + 19240) )
    v26 = (unsigned int)&dword_1000000 | v25;
  else
    v26 = v25 & 0xFEFFFFFF;
  a2[3] = v26;
  sub_51AF80(v4, *(float *)(this + 19244));
  sub_51A240(v4, *(_DWORD *)(*(&dword_91E088 + dword_91E078) + 22468));
  pfnAPC(5u);
}
