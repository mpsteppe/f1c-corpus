int __usercall _get_lc_time@<eax>(int a1@<esi>)
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
  int v44; // edi
  int v45; // eax
  int v46; // [esp+0h] [ebp-8h]
  int v47; // [esp+4h] [ebp-4h]

  v47 = (unsigned __int16)word_FB841E;
  v46 = (unsigned __int16)word_FB8420;
  if ( !a1 )
    return -1;
  v2 = sub_6422F4(1, (unsigned __int16)word_FB841E, 49, a1 + 4);
  v3 = sub_6422F4(1, v47, 50, a1 + 8) | v2;
  v4 = sub_6422F4(1, v47, 51, a1 + 12) | v3;
  v5 = sub_6422F4(1, v47, 52, a1 + 16) | v4;
  v6 = sub_6422F4(1, v47, 53, a1 + 20) | v5;
  v7 = sub_6422F4(1, v47, 54, a1 + 24) | v6;
  v8 = sub_6422F4(1, v47, 55, a1) | v7;
  v9 = sub_6422F4(1, v47, 42, a1 + 32) | v8;
  v10 = sub_6422F4(1, v47, 43, a1 + 36) | v9;
  v11 = sub_6422F4(1, v47, 44, a1 + 40) | v10;
  v12 = sub_6422F4(1, v47, 45, a1 + 44) | v11;
  v13 = sub_6422F4(1, v47, 46, a1 + 48) | v12;
  v14 = sub_6422F4(1, v47, 47, a1 + 52) | v13;
  v15 = sub_6422F4(1, v47, 48, a1 + 28) | v14;
  v16 = sub_6422F4(1, v47, 68, a1 + 56) | v15;
  v17 = sub_6422F4(1, v47, 69, a1 + 60) | v16;
  v18 = sub_6422F4(1, v47, 70, a1 + 64) | v17;
  v19 = sub_6422F4(1, v47, 71, a1 + 68) | v18;
  v20 = sub_6422F4(1, v47, 72, a1 + 72) | v19;
  v21 = sub_6422F4(1, v47, 73, a1 + 76) | v20;
  v22 = sub_6422F4(1, v47, 74, a1 + 80) | v21;
  v23 = sub_6422F4(1, v47, 75, a1 + 84) | v22;
  v24 = sub_6422F4(1, v47, 76, a1 + 88) | v23;
  v25 = sub_6422F4(1, v47, 77, a1 + 92) | v24;
  v26 = sub_6422F4(1, v47, 78, a1 + 96) | v25;
  v27 = sub_6422F4(1, v47, 79, a1 + 100) | v26;
  v28 = sub_6422F4(1, v47, 56, a1 + 104) | v27;
  v29 = sub_6422F4(1, v47, 57, a1 + 108) | v28;
  v30 = sub_6422F4(1, v47, 58, a1 + 112) | v29;
  v31 = sub_6422F4(1, v47, 59, a1 + 116) | v30;
  v32 = sub_6422F4(1, v47, 60, a1 + 120) | v31;
  v33 = sub_6422F4(1, v47, 61, a1 + 124) | v32;
  v34 = sub_6422F4(1, v47, 62, a1 + 128) | v33;
  v35 = sub_6422F4(1, v47, 63, a1 + 132) | v34;
  v36 = sub_6422F4(1, v47, 64, a1 + 136) | v35;
  v37 = sub_6422F4(1, v47, 65, a1 + 140) | v36;
  v38 = sub_6422F4(1, v47, 66, a1 + 144) | v37;
  v39 = sub_6422F4(1, v47, 67, a1 + 148) | v38;
  v40 = sub_6422F4(1, v47, 40, a1 + 152) | v39;
  v41 = sub_6422F4(1, v47, 41, a1 + 156) | v40;
  v42 = sub_6422F4(1, v46, 31, a1 + 160) | v41;
  v43 = sub_6422F4(1, v46, 32, a1 + 164) | v42;
  v44 = sub_6422F4(1, v46, 4099, a1 + 168) | v43;
  v45 = sub_6422F4(0, v46, 4105, a1 + 176);
  *(_DWORD *)(a1 + 172) = v46;
  return v45 | v44;
}
