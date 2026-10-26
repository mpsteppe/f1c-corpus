int __fastcall sub_537D10(unsigned int a1, unsigned __int8 *a2, unsigned int a3)
{
  unsigned __int8 *v3; // edi
  unsigned int v4; // esi
  unsigned int v5; // ecx
  unsigned int i; // ebx
  int v8; // eax
  unsigned int v9; // ebp
  int v10; // edx
  int v11; // esi
  int v12; // ecx
  int v13; // esi
  int v14; // ecx
  int v15; // esi
  int v16; // ecx
  int v17; // esi
  int v18; // ecx
  int v19; // esi
  int v20; // ecx
  int v21; // esi
  int v22; // ecx
  int v23; // esi
  int v24; // ecx
  int v25; // esi
  int v26; // ecx
  int v27; // esi
  int v28; // ecx
  int v29; // esi
  int v30; // ecx
  int v31; // esi
  int v32; // ecx
  int v33; // esi
  int v34; // ecx
  int v35; // esi
  int v36; // ecx
  int v37; // esi
  int v38; // ecx
  int v39; // esi
  int v40; // ecx

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
        v10 = *v3;
        v3 += 16;
        v11 = v10 + v4;
        v12 = v11 + v5;
        v13 = *(v3 - 15) + v11;
        v14 = v13 + v12;
        v15 = *(v3 - 14) + v13;
        v16 = v15 + v14;
        v17 = *(v3 - 13) + v15;
        v18 = v17 + v16;
        v19 = *(v3 - 12) + v17;
        v20 = v19 + v18;
        v21 = *(v3 - 11) + v19;
        v22 = v21 + v20;
        v23 = *(v3 - 10) + v21;
        v24 = v23 + v22;
        v25 = *(v3 - 9) + v23;
        v26 = v25 + v24;
        v27 = *(v3 - 8) + v25;
        v28 = v27 + v26;
        v29 = *(v3 - 7) + v27;
        v30 = v29 + v28;
        v31 = *(v3 - 6) + v29;
        v32 = v31 + v30;
        v33 = *(v3 - 5) + v31;
        v34 = v33 + v32;
        v35 = *(v3 - 4) + v33;
        v36 = v35 + v34;
        v37 = *(v3 - 3) + v35;
        v38 = v37 + v36;
        v39 = *(v3 - 2) + v37;
        v40 = v39 + v38;
        v4 = *(v3 - 1) + v39;
        v5 = v4 + v40;
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
