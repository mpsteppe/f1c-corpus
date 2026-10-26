int __thiscall sub_49F1C0(_DWORD *this, int a2, int a3, int a4, int a5, int a6)
{
  _DWORD *v6; // edi
  int result; // eax
  int v8; // ebp
  int v9; // ebp
  char *v10; // eax
  char v11; // cl
  int v12; // edi
  int v13; // eax
  int v14; // edi
  int v15; // edi
  int v16; // ebp
  int v17; // [esp+Ch] [ebp-78h]
  float v18; // [esp+Ch] [ebp-78h]
  int v19; // [esp+10h] [ebp-74h]
  float v20; // [esp+10h] [ebp-74h]
  int v21; // [esp+14h] [ebp-70h]
  const char *v22; // [esp+18h] [ebp-6Ch]
  int v23; // [esp+18h] [ebp-6Ch]
  float v24; // [esp+18h] [ebp-6Ch]
  int v25; // [esp+1Ch] [ebp-68h]
  int v26; // [esp+1Ch] [ebp-68h]
  int v27; // [esp+20h] [ebp-64h] BYREF
  int v28; // [esp+24h] [ebp-60h]
  int v29; // [esp+28h] [ebp-5Ch]
  int v30; // [esp+2Ch] [ebp-58h] BYREF
  int v31; // [esp+30h] [ebp-54h]
  int v32; // [esp+34h] [ebp-50h]
  int v33; // [esp+38h] [ebp-4Ch]
  float v34; // [esp+3Ch] [ebp-48h]
  _DWORD *v35; // [esp+40h] [ebp-44h]
  float v36; // [esp+44h] [ebp-40h] BYREF
  float v37; // [esp+48h] [ebp-3Ch]
  int v38; // [esp+4Ch] [ebp-38h]
  float v39; // [esp+50h] [ebp-34h]
  float v40; // [esp+54h] [ebp-30h]
  int v41; // [esp+58h] [ebp-2Ch]
  _BYTE v42[31]; // [esp+64h] [ebp-20h] BYREF
  char v43; // [esp+83h] [ebp-1h]

  v6 = this;
  v35 = this;
  result = 1;
  if ( a5 && a6 )
  {
    v21 = a3;
    sub_5531F0(aWijs, &v27, &v30, 0);
    v27 /= 4;
    v32 = a2 + 11 * v27 + v27 / 2;
    v8 = dword_7C54E8 + 13004;
    v31 = a2 + 11 * v27 - v27 / 2;
    v28 = v30 + 1;
    v25 = dword_7C54E8 + 13004;
    PitRepairStatusDisplay(dword_7C54E8 + 13004);
    if ( *(int *)((v6[1] << 6) + v8 + 40) <= 1 )
      sub_49F170(v6, 1);
    v9 = 0;
    v29 = 0;
    v26 = v25 + 54;
    do
    {
      v22 = (const char *)sub_4A47E0(v9);
      if ( BinarySearchInStringTable(byte_5EC4C0, v22, byte_5EC4CC) )
      {
        v10 = (char *)v22;
        if ( v22 )
        {
          do
          {
            v11 = *v10;
            v10[byte_5EC4CC - v22] = *v10;
            ++v10;
          }
          while ( v11 );
        }
        else
        {
          byte_5EC4CC[0] = 0;
        }
      }
      sub_587DD0(v42, byte_5EC4CC, 31);
      v43 = 0;
      StringFormatAndRender(v42, v31, v21, a5, a6, 1);
      sub_587DD0(v42, v26, 31);
      v43 = 0;
      StringFormatAndRender(v42, v32, v21, a5, a6, 0);
      if ( v9 == v6[1] )
      {
        v12 = CRTFtol((double)a2 * *(float *)(a5 + 92));
        v19 = v12;
        v23 = CRTFtol((double)a3 * *(float *)(a5 + 96));
        v13 = CRTFtol((double)v28 * *(float *)(a5 + 96));
        if ( *(int *)(a6 + 28) >= 300 )
          v14 = v12 + 1000;
        else
          v14 = v12 + 250;
        v17 = v14;
        v20 = (float)v19;
        v36 = v20;
        v15 = v23 + v9 * v13;
        v33 = v15;
        v37 = (float)v15;
        v34 = v37;
        v18 = (float)v17;
        v39 = v18;
        v40 = v37;
        v16 = v23 + v13 * (v9 + 1);
        v38 = 0;
        v41 = 0;
        FloatToIntConversionChain(&v36, a4);
        v33 = v15 - 1;
        v39 = v18;
        v37 = (float)(v15 - 1);
        v40 = v37;
        v36 = v20;
        v38 = 0;
        v41 = 0;
        FloatToIntConversionChain(&v36, a4);
        v24 = (float)v16;
        v40 = v24;
        v39 = v20;
        FloatToIntConversionChain(&v36, a4);
        v37 = v24;
        v36 = v18;
        v39 = v18;
        v40 = v34;
        FloatToIntConversionChain(&v36, a4);
        v36 = v18;
        v37 = v24;
        v40 = v24;
        v39 = v20;
        FloatToIntConversionChain(&v36, a4);
        LODWORD(v34) = v16 + 1;
        v39 = v20;
        v37 = (float)(v16 + 1);
        v40 = v37;
        v36 = v18;
        FloatToIntConversionChain(&v36, a4);
        v6 = v35;
        v9 = v29;
      }
      v21 += v28;
      v29 = ++v9;
      v26 += 64;
    }
    while ( v9 < 5 );
    return 0;
  }
  return result;
}
