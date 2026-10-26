int __fastcall sub_62CC00(unsigned int a1, unsigned __int8 *a2, unsigned int a3)
{
  unsigned __int8 *v3; // edi
  unsigned int v4; // esi
  unsigned int v5; // ecx
  unsigned int i; // ebx
  int v8; // eax
  unsigned int v9; // edx
  int v10; // esi
  int v11; // ecx
  int v12; // esi
  int v13; // ecx
  int v14; // esi
  int v15; // ecx
  int v16; // esi
  int v17; // ecx
  int v18; // esi
  int v19; // ecx
  int v20; // esi
  int v21; // ecx
  int v22; // esi
  int v23; // ecx
  int v24; // esi
  int v25; // ecx
  int v26; // esi
  int v27; // ecx
  int v28; // esi
  int v29; // ecx
  int v30; // esi
  int v31; // ecx
  int v32; // esi
  int v33; // ecx
  int v34; // esi
  int v35; // ecx
  int v36; // esi
  int v37; // ecx
  int v38; // esi
  int v39; // ecx

  v3 = a2;
  v4 = (unsigned __int16)a1;
  v5 = HIWORD(a1);
  if ( !a2 )
    return 1;
  for ( i = a3; i; v5 %= 0xFFF1u )
  {
    v8 = i;
    if ( i >= 0x15B0 )
      v8 = 5552;
    i -= v8;
    if ( v8 >= 16 )
    {
      v9 = (unsigned int)v8 >> 4;
      v8 += -16 * ((unsigned int)v8 >> 4);
      do
      {
        v10 = *v3 + v4;
        v11 = v10 + v5;
        v12 = v3[1] + v10;
        v13 = v12 + v11;
        v14 = v3[2] + v12;
        v15 = v14 + v13;
        v16 = v3[3] + v14;
        v17 = v16 + v15;
        v18 = v3[4] + v16;
        v19 = v18 + v17;
        v20 = v3[5] + v18;
        v21 = v20 + v19;
        v22 = v3[6] + v20;
        v23 = v22 + v21;
        v24 = v3[7] + v22;
        v25 = v24 + v23;
        v26 = v3[8] + v24;
        v27 = v26 + v25;
        v28 = v3[9] + v26;
        v29 = v28 + v27;
        v30 = v3[10] + v28;
        v31 = v30 + v29;
        v32 = v3[11] + v30;
        v33 = v32 + v31;
        v34 = v3[12] + v32;
        v35 = v34 + v33;
        v36 = v3[13] + v34;
        v37 = v36 + v35;
        v38 = v3[14] + v36;
        v39 = v38 + v37;
        v4 = v3[15] + v38;
        v5 = v4 + v39;
        v3 += 16;
        --v9;
      }
      while ( v9 );
    }
    for ( ; v8; --v8 )
    {
      v4 += *v3++;
      v5 += v4;
    }
    v4 %= 0xFFF1u;
  }
  return v4 | (v5 << 16);
}
