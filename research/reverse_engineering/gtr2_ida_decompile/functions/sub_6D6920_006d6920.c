int __stdcall sub_6D6920(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  int v7; // eax
  int v8; // edx
  int result; // eax
  int v12; // eax
  unsigned __int8 *v13; // eax
  unsigned __int8 *v14; // eax
  unsigned __int8 *v15; // eax
  unsigned __int8 *v16; // eax
  unsigned __int8 *v17; // eax
  int v18; // edx
  unsigned __int8 *v19; // eax
  unsigned __int8 *v20; // eax
  unsigned __int8 *v21; // eax
  int i; // edi
  bool v23; // zf
  float v24[64]; // [esp+4h] [ebp-108h] BYREF
  void (__stdcall *v25)(float *); // [esp+104h] [ebp-8h]
  int v26; // [esp+108h] [ebp-4h]
  int v28; // [esp+118h] [ebp+Ch]
  int v29; // [esp+11Ch] [ebp+10h]
  int v30; // [esp+11Ch] [ebp+10h]
  int v31; // [esp+11Ch] [ebp+10h]
  int v32; // [esp+11Ch] [ebp+10h]
  int v33; // [esp+11Ch] [ebp+10h]
  int v34; // [esp+11Ch] [ebp+10h]
  int v35; // [esp+11Ch] [ebp+10h]
  int v36; // [esp+11Ch] [ebp+10h]
  int v37; // [esp+11Ch] [ebp+10h]
  int v38; // [esp+11Ch] [ebp+10h]
  int v39; // [esp+11Ch] [ebp+10h]
  int v40; // [esp+11Ch] [ebp+10h]
  int v41; // [esp+11Ch] [ebp+10h]
  int v42; // [esp+11Ch] [ebp+10h]
  int v43; // [esp+11Ch] [ebp+10h]
  int v44; // [esp+11Ch] [ebp+10h]
  int v45; // [esp+11Ch] [ebp+10h]
  int v46; // [esp+11Ch] [ebp+10h]
  int v47; // [esp+11Ch] [ebp+10h]
  int v48; // [esp+11Ch] [ebp+10h]
  int v49; // [esp+11Ch] [ebp+10h]
  int v50; // [esp+11Ch] [ebp+10h]
  int v51; // [esp+11Ch] [ebp+10h]
  int v52; // [esp+11Ch] [ebp+10h]
  int v53; // [esp+11Ch] [ebp+10h]
  int v54; // [esp+11Ch] [ebp+10h]
  int v55; // [esp+11Ch] [ebp+10h]
  int v56; // [esp+11Ch] [ebp+10h]
  int v57; // [esp+11Ch] [ebp+10h]
  int v58; // [esp+11Ch] [ebp+10h]
  int v59; // [esp+11Ch] [ebp+10h]
  int v60; // [esp+11Ch] [ebp+10h]
  int v61; // [esp+11Ch] [ebp+10h]
  int v62; // [esp+11Ch] [ebp+10h]
  int v63; // [esp+11Ch] [ebp+10h]
  int v64; // [esp+11Ch] [ebp+10h]
  int v65; // [esp+11Ch] [ebp+10h]
  int v66; // [esp+11Ch] [ebp+10h]
  int v67; // [esp+11Ch] [ebp+10h]
  int v68; // [esp+11Ch] [ebp+10h]
  int v69; // [esp+11Ch] [ebp+10h]
  int v70; // [esp+11Ch] [ebp+10h]
  int v71; // [esp+11Ch] [ebp+10h]
  int v72; // [esp+11Ch] [ebp+10h]
  int v73; // [esp+11Ch] [ebp+10h]
  int v74; // [esp+11Ch] [ebp+10h]
  int v75; // [esp+11Ch] [ebp+10h]
  int v76; // [esp+11Ch] [ebp+10h]
  int v77; // [esp+11Ch] [ebp+10h]
  int v78; // [esp+11Ch] [ebp+10h]
  int v79; // [esp+11Ch] [ebp+10h]
  int v80; // [esp+11Ch] [ebp+10h]
  int v81; // [esp+11Ch] [ebp+10h]
  int v82; // [esp+11Ch] [ebp+10h]

  v7 = *(_DWORD *)(a1 + 368);
  v25 = *(void (__stdcall **)(float *))(v7 + 28);
  v8 = *(_DWORD *)(v7 + 4 * *(_DWORD *)(a2 + 16) + 32);
  result = a7;
  v26 = v8;
  if ( a7 )
  {
    v28 = a7;
    do
    {
      v12 = *(_DWORD *)(a3 + 4 * a5);
      v29 = *(unsigned __int8 *)(v12 + a6) - 128;
      v13 = (unsigned __int8 *)(a6 + v12 + 1);
      v24[0] = (float)v29;
      v30 = *v13++ - 128;
      v24[1] = (float)v30;
      v31 = *v13++ - 128;
      v24[2] = (float)v31;
      v32 = *v13++ - 128;
      v24[3] = (float)v32;
      v33 = *v13++ - 128;
      v24[4] = (float)v33;
      v34 = *v13++ - 128;
      v24[5] = (float)v34;
      v24[6] = (float)(*v13 - 128);
      v35 = v13[1] - 128;
      v14 = (unsigned __int8 *)(a6 + *(_DWORD *)(a3 + 4 * a5 + 4));
      v24[7] = (float)v35;
      v36 = *v14++ - 128;
      v24[8] = (float)v36;
      v37 = *v14++ - 128;
      v24[9] = (float)v37;
      v38 = *v14++ - 128;
      v24[10] = (float)v38;
      v39 = *v14++ - 128;
      v24[11] = (float)v39;
      v40 = *v14++ - 128;
      v24[12] = (float)v40;
      v41 = *v14++ - 128;
      v24[13] = (float)v41;
      v24[14] = (float)(*v14 - 128);
      v42 = v14[1] - 128;
      v15 = (unsigned __int8 *)(a6 + *(_DWORD *)(a3 + 4 * a5 + 8));
      v24[15] = (float)v42;
      v43 = *v15++ - 128;
      v24[16] = (float)v43;
      v44 = *v15++ - 128;
      v24[17] = (float)v44;
      v45 = *v15++ - 128;
      v24[18] = (float)v45;
      v46 = *v15++ - 128;
      v24[19] = (float)v46;
      v47 = *v15++ - 128;
      v24[20] = (float)v47;
      v48 = *v15++ - 128;
      v24[21] = (float)v48;
      v24[22] = (float)(*v15 - 128);
      v49 = v15[1] - 128;
      v16 = (unsigned __int8 *)(a6 + *(_DWORD *)(a3 + 4 * a5 + 12));
      v24[23] = (float)v49;
      v50 = *v16++ - 128;
      v24[24] = (float)v50;
      v51 = *v16++ - 128;
      v24[25] = (float)v51;
      v52 = *v16++ - 128;
      v24[26] = (float)v52;
      v53 = *v16++ - 128;
      v24[27] = (float)v53;
      v54 = *v16++ - 128;
      v24[28] = (float)v54;
      v55 = *v16++ - 128;
      v24[29] = (float)v55;
      v24[30] = (float)(*v16 - 128);
      v56 = v16[1] - 128;
      v17 = (unsigned __int8 *)(a6 + *(_DWORD *)(a3 + 4 * a5 + 16));
      v24[31] = (float)v56;
      v57 = *v17++ - 128;
      v24[32] = (float)v57;
      v58 = *v17++ - 128;
      v24[33] = (float)v58;
      v18 = *v17++ - 128;
      v24[34] = (float)v18;
      v59 = *v17++ - 128;
      v24[35] = (float)v59;
      v60 = *v17++ - 128;
      v24[36] = (float)v60;
      v61 = *v17++ - 128;
      v24[37] = (float)v61;
      v24[38] = (float)(*v17 - 128);
      v62 = v17[1] - 128;
      v19 = (unsigned __int8 *)(a6 + *(_DWORD *)(a3 + 4 * a5 + 20));
      v24[39] = (float)v62;
      v63 = *v19++ - 128;
      v24[40] = (float)v63;
      v64 = *v19++ - 128;
      v24[41] = (float)v64;
      v65 = *v19++ - 128;
      v24[42] = (float)v65;
      v66 = *v19++ - 128;
      v24[43] = (float)v66;
      v67 = *v19++ - 128;
      v24[44] = (float)v67;
      v68 = *v19++ - 128;
      v24[45] = (float)v68;
      v24[46] = (float)(*v19 - 128);
      v69 = v19[1] - 128;
      v20 = (unsigned __int8 *)(a6 + *(_DWORD *)(a3 + 4 * a5 + 24));
      v24[47] = (float)v69;
      v70 = *v20++ - 128;
      v24[48] = (float)v70;
      v71 = *v20++ - 128;
      v24[49] = (float)v71;
      v72 = *v20++ - 128;
      v24[50] = (float)v72;
      v73 = *v20++ - 128;
      v24[51] = (float)v73;
      v74 = *v20++ - 128;
      v24[52] = (float)v74;
      v75 = *v20++ - 128;
      v24[53] = (float)v75;
      v24[54] = (float)(*v20 - 128);
      v76 = v20[1] - 128;
      v21 = (unsigned __int8 *)(a6 + *(_DWORD *)(a3 + 4 * a5 + 28));
      v24[55] = (float)v76;
      v77 = *v21++ - 128;
      v24[56] = (float)v77;
      v78 = *v21++ - 128;
      v24[57] = (float)v78;
      v79 = *v21++ - 128;
      v24[58] = (float)v79;
      v80 = *v21++ - 128;
      v24[59] = (float)v80;
      v81 = *v21++ - 128;
      v24[60] = (float)v81;
      v82 = *v21++ - 128;
      v24[61] = (float)v82;
      v24[62] = (float)(*v21 - 128);
      v24[63] = (float)(v21[1] - 128);
      v25(v24);
      for ( i = 0; i < 64; ++i )
        *(_WORD *)(a4 + 2 * i) = (__int64)(*(float *)(v26 + 4 * i) * v24[i] + 16384.5) - 0x4000;
      a6 += 8;
      result = v28 - 1;
      v23 = v28 == 1;
      a4 += 128;
      --v28;
    }
    while ( !v23 );
  }
  return result;
}
