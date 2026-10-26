int __thiscall sub_531830(int this, _WORD *a2, int a3)
{
  int v3; // esi
  char v4; // al
  int v5; // ecx
  int v6; // edi
  int result; // eax
  int v8; // eax
  int v9; // edx
  int v10; // ecx
  int v11; // ebx
  float *v12; // esi
  float *v13; // ebx
  _WORD *v14; // edx
  int v15; // ecx
  int v16; // edi
  double v17; // st7
  double v18; // st6
  int v19; // eax
  int v20; // eax
  float *v21; // esi
  float *v22; // ebx
  int v23; // ecx
  _WORD *v24; // edx
  double v25; // st7
  double v26; // st6
  int v27; // eax
  bool v28; // zf
  char v29; // [esp+Ch] [ebp-40h]
  int v31; // [esp+18h] [ebp-34h]
  float *v32; // [esp+1Ch] [ebp-30h]
  int v33; // [esp+30h] [ebp-1Ch]
  int v34; // [esp+34h] [ebp-18h]
  int v35; // [esp+38h] [ebp-14h]
  int v36; // [esp+3Ch] [ebp-10h]
  int v37; // [esp+40h] [ebp-Ch]
  _WORD *v38; // [esp+44h] [ebp-8h]
  int v40; // [esp+58h] [ebp+Ch]

  v3 = this;
  v4 = *(_BYTE *)(this + 9404) - 1;
  v31 = *(_DWORD *)(this + 9420);
  *(_BYTE *)(this + 9404) = v4 & 0xF;
  v5 = v4 & 0xF;
  v6 = v4 & 1;
  v29 = v4 & 1;
  result = !(v4 & 1);
  v37 = result + v5;
  if ( v31 > 0 )
  {
    v38 = a2;
    v40 = v3 + 4;
    v8 = 1152 * result;
    v35 = v31;
    v9 = v3 + 4;
    v10 = 288 * v6;
    v11 = v3 + v8 + 4 * v37 + 4;
    v33 = v8;
    v34 = 288 * v6;
    v36 = v11;
    while ( 1 )
    {
      v32 = (float *)(v9 + v8);
      F_32PointMDCTAudioTransform(v9 + 4 * (v10 + (((_BYTE)v6 + *(_BYTE *)(v3 + 9404)) & 0xF)), v11, a3);
      if ( a2 )
      {
        v12 = v32;
        v13 = (float *)((char *)&unk_5B666C - 4 * v37);
        v14 = v38;
        v15 = 16;
        v16 = 2 * v31;
        do
        {
          v17 = *v13 * *v12
              + v13[8] * v12[8]
              - v13[1] * v12[1]
              - v13[9] * v12[9]
              + v13[2] * v12[2]
              + v13[12] * v12[12]
              - v13[5] * v12[5]
              - v13[13] * v12[13];
          v18 = v13[6] * v12[6]
              + v13[14] * v12[14]
              - v13[7] * v12[7]
              - v13[15] * v12[15]
              + v13[4] * v12[4]
              + v13[10] * v12[10]
              - v13[3] * v12[3]
              - v13[11] * v12[11];
          v13 += 32;
          v12 += 16;
          v19 = (int)(v17 + v18);
          if ( v19 > 0x7FFF )
            v19 = 0x7FFF;
          if ( v19 < -32768 )
            LOWORD(v19) = 0x8000;
          *v14 = v19;
          v14 = (_WORD *)((char *)v14 + v16);
          --v15;
        }
        while ( v15 );
        v20 = (int)(*v13 * *v12
                  + v13[8] * v12[8]
                  + v13[2] * v12[2]
                  + v13[12] * v12[12]
                  + v13[6] * v12[6]
                  + v13[14] * v12[14]
                  + v13[4] * v12[4]
                  + v13[10] * v12[10]);
        if ( v20 > 0x7FFF )
          v20 = 0x7FFF;
        if ( v20 < -32768 )
          LOWORD(v20) = 0x8000;
        *v14 = v20;
        v21 = v12 - 16;
        v22 = &v13[2 * v37 - 32];
        v23 = 15;
        v24 = &v14[v16 / 2u];
        do
        {
          v25 = *(v22 - 1) * *v21
              + *(v22 - 5) * v21[4]
              + *(v22 - 9) * v21[8]
              + *(v22 - 13) * v21[12]
              + *(v22 - 2) * v21[1]
              + *(v22 - 7) * v21[6]
              + *(v22 - 11) * v21[10]
              + *(v22 - 15) * v21[14];
          v26 = *(v22 - 4) * v21[3]
              + *(v22 - 8) * v21[7]
              + *(v22 - 12) * v21[11]
              + *v22 * v21[15]
              + *(v22 - 3) * v21[2]
              + *(v22 - 6) * v21[5]
              + *(v22 - 10) * v21[9]
              + *(v22 - 14) * v21[13];
          v22 -= 32;
          v21 -= 16;
          v27 = (int)-(v25 + v26);
          if ( v27 > 0x7FFF )
            v27 = 0x7FFF;
          if ( v27 < -32768 )
            LOWORD(v27) = 0x8000;
          *v24 = v27;
          v24 = (_WORD *)((char *)v24 + v16);
          --v23;
        }
        while ( v23 );
        v3 = this;
        LOBYTE(v6) = v29;
        v11 = v36;
      }
      v40 += 2304;
      v11 += 2304;
      result = v35 - 1;
      v28 = v35 == 1;
      v36 = v11;
      a3 += 128;
      ++v38;
      --v35;
      if ( v28 )
        break;
      v9 = v40;
      v10 = v34;
      v8 = v33;
    }
  }
  return result;
}
