char __usercall sub_477E25@<al>(const CHAR *a1@<eax>, int a2@<ecx>, int a3@<edi>)
{
  const char *v4; // ecx
  const char *v5; // eax
  float *v6; // eax
  __int16 v7; // ax
  __int16 v8; // ax
  __int16 v9; // ax
  double v10; // st7
  int v11; // eax
  int v12; // ecx
  int v13; // eax
  int v14; // ecx
  char v15; // al
  char v16; // al
  char result; // al
  float v18[7]; // [esp+8h] [ebp-24h] BYREF
  char v19; // [esp+27h] [ebp-5h]

  if ( !a1 )
    a1 = WindowName;
  sub_538940(&unk_BE1CFD, a1, a3);
  v4 = (const char *)(396 * dword_BE1CD4 + dword_BE1CD8 + 4);
  v5 = &v4[strlen(v4) - 4 - dword_BE1CD8 + (_DWORD)v4 + -396 * dword_BE1CD4];
  if ( v5 > v4 )
  {
    while ( *v5 != 92 )
    {
      if ( --v5 <= v4 )
        goto LABEL_8;
    }
    ++v5;
  }
LABEL_8:
  sub_630FE0(v18, v5, 31);
  v19 = 0;
  v6 = (float *)((char *)v18 + strlen((const char *)v18));
  if ( v6 > v18 )
  {
    while ( *(_BYTE *)v6 != 46 )
    {
      v6 = (float *)((char *)v6 - 1);
      if ( v6 <= v18 )
        goto LABEL_13;
    }
    *(_BYTE *)v6 = 0;
  }
LABEL_13:
  sub_630FE0(a2 + 32, v18, 31);
  *(_BYTE *)(a2 + 63) = 0;
  sub_473C50();
  *(_BYTE *)(a2 + 104) = dword_B72C1C;
  *(_BYTE *)(a2 + 105) = 0;
  *(_BYTE *)(a2 + 106) = dword_B733C0;
  *(_BYTE *)(a2 + 107) = dword_B72EBC;
  *(_BYTE *)(a2 + 108) = dword_B73000;
  *(_BYTE *)(a2 + 109) = dword_B71DEC;
  *(_BYTE *)(a2 + 110) = dword_B6FE20;
  v7 = dword_B7336C & 0x3F;
  *(_WORD *)(a2 + 180) = v7;
  v8 = ((dword_B6FC28 & 1) << 8) + v7;
  *(_WORD *)(a2 + 180) = v8;
  v9 = ((dword_B700E4 & 1) << 9) + v8;
  *(_WORD *)(a2 + 180) = v9;
  *(_WORD *)(a2 + 180) = v9 + ((dword_B70228 & 1) << 10);
  *(_WORD *)(a2 + 180) += (sub_42FE40(&dword_B640C0) & 1) << 11;
  *(_WORD *)(a2 + 182) = dword_B6FFAC;
  *(_WORD *)(a2 + 184) = dword_B6FFD0;
  v10 = flt_B735A0 * 1000.0;
  v18[0] = v10;
  if ( v10 >= 0.0 )
  {
    if ( v18[0] > 65535.0 )
      v18[0] = 65535.0;
  }
  else
  {
    v18[0] = 0.0;
  }
  *(_WORD *)(a2 + 186) = sub_4015C0(v18[0]);
  switch ( dword_B7321C )
  {
    case 1:
      v11 = 8;
      break;
    case 2:
      v11 = 12;
      break;
    case 3:
      v11 = 14;
      break;
    case 4:
      v11 = 32;
      break;
    default:
      v11 = 6;
      break;
  }
  v12 = dword_B7329C;
  dword_B73294 = v11;
  if ( v11 < dword_B7329C || (v12 = dword_B732A0, v11 > dword_B732A0) )
  {
    LOBYTE(v11) = v12;
    dword_B73294 = v12;
  }
  *(_BYTE *)(a2 + 111) = v11;
  *(_BYTE *)(a2 + 112) = dword_B706CC;
  *(_BYTE *)(a2 + 114) = byte_B73528;
  *(_BYTE *)(a2 + 115) = byte_B73570;
  *(_BYTE *)(a2 + 116) = byte_B73588;
  *(_BYTE *)(a2 + 113) = dword_B70588;
  *(_DWORD *)(a2 + 96) = dword_B72958;
  *(_WORD *)(a2 + 166) = dword_B73348;
  *(_BYTE *)(a2 + 168) = byte_B6FEBC;
  *(_BYTE *)(a2 + 169) = byte_B6FED4;
  *(_BYTE *)(a2 + 170) = byte_B6FEEC;
  *(_BYTE *)(a2 + 171) = byte_B6FF04;
  *(_BYTE *)(a2 + 172) = byte_B6FF1C;
  *(_DWORD *)(a2 + 152) = dword_B737B0;
  *(_DWORD *)(a2 + 156) = dword_B737D4;
  *(_BYTE *)(a2 + 160) = dword_B72338;
  v13 = dword_B6CBA8;
  if ( *(_DWORD *)(dword_B6CBA8 + 113328) == 4 )
  {
    v14 = *(_DWORD *)(dword_B6CBA8 + 113316);
    if ( v14 )
    {
      if ( sub_59B670(v14) == 3 )
        *(_DWORD *)(dword_B6CBA8 + 113328) = 3;
      v13 = dword_B6CBA8;
    }
  }
  if ( *(_DWORD *)(v13 + 113328) == 1 || *(_BYTE *)(v13 + 1417) )
    v15 = *(_BYTE *)(a2 + 161) | 1;
  else
    v15 = *(_BYTE *)(a2 + 161) & 0xFE;
  *(_BYTE *)(a2 + 161) = v15;
  v16 = *(_BYTE *)(a2 + 161);
  if ( dword_B71F6C )
    result = v16 | 2;
  else
    result = v16 & 0xFD;
  *(_BYTE *)(a2 + 161) = result;
  return result;
}
