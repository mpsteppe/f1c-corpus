int __cdecl _get_lc_time(int a1)
{
  int v2; // edi
  int v3; // edi
  int v4; // edi
  int v5; // edi
  int v6; // edi
  int v7; // edi
  int v8; // edi
  int v9; // edi
  int v10; // edi
  int v11; // edi
  int v12; // edi
  int v13; // edi
  int v14; // edi
  int v15; // edi
  int v16; // edi
  int v17; // edi
  int v18; // edi
  int v19; // edi
  int v20; // edi
  int v21; // edi
  int v22; // edi
  int v23; // edi
  int v24; // edi
  int v25; // edi
  int v26; // edi
  int v27; // edi
  int v28; // edi
  int v29; // edi
  int v30; // edi
  int v31; // edi
  int v32; // edi
  int v33; // edi
  int v34; // edi
  int v35; // edi
  int v36; // edi
  int v37; // edi
  int v38; // edi
  int v39; // edi
  int v40; // edi
  int v41; // edi
  int v42; // edi
  int v43; // edi
  LCID v44; // [esp+4h] [ebp-8h]
  LCID Locale; // [esp+8h] [ebp-4h]

  Locale = (unsigned __int16)word_7FF242;
  v44 = (unsigned __int16)word_7FF244;
  if ( !a1 )
    return -1;
  v2 = __getlocaleinfo(1, (unsigned __int16)word_7FF242, 0x31u, a1 + 4);
  v3 = __getlocaleinfo(1, Locale, 0x32u, a1 + 8) | v2;
  v4 = __getlocaleinfo(1, Locale, 0x33u, a1 + 12) | v3;
  v5 = __getlocaleinfo(1, Locale, 0x34u, a1 + 16) | v4;
  v6 = __getlocaleinfo(1, Locale, 0x35u, a1 + 20) | v5;
  v7 = __getlocaleinfo(1, Locale, 0x36u, a1 + 24) | v6;
  v8 = __getlocaleinfo(1, Locale, 0x37u, a1) | v7;
  v9 = __getlocaleinfo(1, Locale, 0x2Au, a1 + 32) | v8;
  v10 = __getlocaleinfo(1, Locale, 0x2Bu, a1 + 36) | v9;
  v11 = __getlocaleinfo(1, Locale, 0x2Cu, a1 + 40) | v10;
  v12 = __getlocaleinfo(1, Locale, 0x2Du, a1 + 44) | v11;
  v13 = __getlocaleinfo(1, Locale, 0x2Eu, a1 + 48) | v12;
  v14 = __getlocaleinfo(1, Locale, 0x2Fu, a1 + 52) | v13;
  v15 = __getlocaleinfo(1, Locale, 0x30u, a1 + 28) | v14;
  v16 = __getlocaleinfo(1, Locale, 0x44u, a1 + 56) | v15;
  v17 = __getlocaleinfo(1, Locale, 0x45u, a1 + 60) | v16;
  v18 = __getlocaleinfo(1, Locale, 0x46u, a1 + 64) | v17;
  v19 = __getlocaleinfo(1, Locale, 0x47u, a1 + 68) | v18;
  v20 = __getlocaleinfo(1, Locale, 0x48u, a1 + 72) | v19;
  v21 = __getlocaleinfo(1, Locale, 0x49u, a1 + 76) | v20;
  v22 = __getlocaleinfo(1, Locale, 0x4Au, a1 + 80) | v21;
  v23 = __getlocaleinfo(1, Locale, 0x4Bu, a1 + 84) | v22;
  v24 = __getlocaleinfo(1, Locale, 0x4Cu, a1 + 88) | v23;
  v25 = __getlocaleinfo(1, Locale, 0x4Du, a1 + 92) | v24;
  v26 = __getlocaleinfo(1, Locale, 0x4Eu, a1 + 96) | v25;
  v27 = __getlocaleinfo(1, Locale, 0x4Fu, a1 + 100) | v26;
  v28 = __getlocaleinfo(1, Locale, 0x38u, a1 + 104) | v27;
  v29 = __getlocaleinfo(1, Locale, 0x39u, a1 + 108) | v28;
  v30 = __getlocaleinfo(1, Locale, 0x3Au, a1 + 112) | v29;
  v31 = __getlocaleinfo(1, Locale, 0x3Bu, a1 + 116) | v30;
  v32 = __getlocaleinfo(1, Locale, 0x3Cu, a1 + 120) | v31;
  v33 = __getlocaleinfo(1, Locale, 0x3Du, a1 + 124) | v32;
  v34 = __getlocaleinfo(1, Locale, 0x3Eu, a1 + 128) | v33;
  v35 = __getlocaleinfo(1, Locale, 0x3Fu, a1 + 132) | v34;
  v36 = __getlocaleinfo(1, Locale, 0x40u, a1 + 136) | v35;
  v37 = __getlocaleinfo(1, Locale, 0x41u, a1 + 140) | v36;
  v38 = __getlocaleinfo(1, Locale, 0x42u, a1 + 144) | v37;
  v39 = __getlocaleinfo(1, Locale, 0x43u, a1 + 148) | v38;
  v40 = __getlocaleinfo(1, Locale, 0x28u, a1 + 152) | v39;
  v41 = __getlocaleinfo(1, Locale, 0x29u, a1 + 156) | v40;
  v42 = __getlocaleinfo(1, v44, 0x1Fu, a1 + 160) | v41;
  v43 = __getlocaleinfo(1, v44, 0x20u, a1 + 164) | v42;
  return v43 | __getlocaleinfo(1, v44, 0x1003u, a1 + 168);
}
