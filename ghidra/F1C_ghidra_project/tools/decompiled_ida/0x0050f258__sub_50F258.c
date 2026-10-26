// Address: 0x0050f258
// Size: 986 bytes
// Name: sub_50F258
// Type: int __stdcall(float *, float *, float *, float *, float *, float *, float *)
// Source: IDA Hex-Rays decompilation

int __stdcall sub_50F258(float *a1, float *a2, float *a3, float *a4, float *a5, float *a6, float *a7)
{
  unsigned __int8 v8; // c0
  unsigned __int8 v9; // c3
  unsigned __int8 v11; // c0
  unsigned __int8 v12; // c3
  unsigned __int8 v14; // c0
  unsigned __int8 v15; // c3
  int result; // eax
  _BYTE v17[16]; // [esp+8h] [ebp-44h] BYREF
  float v18; // [esp+18h] [ebp-34h] BYREF
  float v19; // [esp+1Ch] [ebp-30h]
  float v20; // [esp+20h] [ebp-2Ch]
  float v21; // [esp+24h] [ebp-28h]
  float v22; // [esp+28h] [ebp-24h] BYREF
  float v23; // [esp+2Ch] [ebp-20h]
  float v24; // [esp+30h] [ebp-1Ch]
  float v25; // [esp+34h] [ebp-18h]
  float v26; // [esp+38h] [ebp-14h] BYREF
  float v27; // [esp+3Ch] [ebp-10h]
  float v28; // [esp+40h] [ebp-Ch]
  float v29; // [esp+44h] [ebp-8h]
  float v30; // [esp+48h] [ebp-4h] BYREF
  float v31; // [esp+4Ch] [ebp+0h]
  float v32; // [esp+50h] [ebp+4h]
  float v33; // [esp+54h] [ebp+8h]
  float v34; // [esp+58h] [ebp+Ch] BYREF
  float v35; // [esp+5Ch] [ebp+10h]
  float v36; // [esp+60h] [ebp+14h]
  float v37; // [esp+64h] [ebp+18h]
  float v38; // [esp+68h] [ebp+1Ch] BYREF
  float v39; // [esp+6Ch] [ebp+20h]
  float v40; // [esp+70h] [ebp+24h]
  float v41; // [esp+74h] [ebp+28h]
  float v42; // [esp+78h] [ebp+2Ch] BYREF
  float v43; // [esp+7Ch] [ebp+30h]
  float v44; // [esp+80h] [ebp+34h]
  float v45; // [esp+84h] [ebp+38h]
  float v46; // [esp+88h] [ebp+3Ch] BYREF
  float v47; // [esp+8Ch] [ebp+40h]
  float v48; // [esp+90h] [ebp+44h]
  float v49; // [esp+94h] [ebp+48h]
  float v50; // [esp+98h] [ebp+4Ch] BYREF
  float v51; // [esp+9Ch] [ebp+50h]
  float v52; // [esp+A0h] [ebp+54h]
  float v53; // [esp+A4h] [ebp+58h]

  v22 = *a4;
  v23 = a4[1];
  v24 = a4[2];
  v25 = a4[3];
  v34 = *a5;
  v35 = a5[1];
  v36 = a5[2];
  v37 = a5[3];
  v46 = *a6;
  v47 = a6[1];
  v48 = a6[2];
  v51 = v23 - v35;
  v49 = a6[3];
  v52 = v24 - v36;
  v26 = *a7;
  v27 = a7[1];
  v53 = v25 - v37;
  v28 = a7[2];
  v29 = a7[3];
  if ( !(v8 | v9) )
  {
    v42 = -v22;
    v43 = -v23;
    v44 = -v24;
    v45 = -v25;
    v22 = v42;
    v23 = v43;
    v24 = v44;
    v25 = v45;
  }
  v51 = v35 - v47;
  v52 = v36 - v48;
  v53 = v37 - v49;
  if ( !(v11 | v12) )
  {
    v42 = -v46;
    v43 = -v47;
    v44 = -v48;
    v45 = -v49;
    v46 = v42;
    v47 = v43;
    v48 = v44;
    v49 = v45;
  }
  v51 = v47 - v27;
  v52 = v48 - v28;
  v53 = v49 - v29;
  if ( !(v14 | v15) )
  {
    v42 = -v26;
    v43 = -v27;
    v44 = -v28;
    v45 = -v29;
    v26 = v42;
    v27 = v43;
    v28 = v44;
    v29 = v45;
  }
  sub_50DF95(&v42, &v34);
  sub_50DE26(&v38, &v42, &v22);
  v30 = v38;
  v31 = v39;
  v32 = v40;
  v33 = v41;
  sub_50E04F(&v18, &v30);
  sub_50DE26(&v38, &v42, &v46);
  v30 = v38;
  v31 = v39;
  v32 = v40;
  v33 = v41;
  sub_50E04F(&v50, &v30);
  v39 = v19 + v51;
  v40 = v20 + v52;
  v30 = (v18 + v50) * -0.25;
  v31 = v39 * -0.25;
  v32 = v40 * -0.25;
  v33 = (v21 + v53) * -0.25;
  sub_50E0D3(v17, &v30);
  sub_50DE26(&v38, &v34, v17);
  *a1 = v38;
  a1[1] = v39;
  a1[2] = v40;
  a1[3] = v41;
  sub_50DF95(&v42, &v46);
  sub_50DE26(&v38, &v42, &v34);
  v30 = v38;
  v31 = v39;
  v32 = v40;
  v33 = v41;
  sub_50E04F(&v18, &v30);
  sub_50DE26(&v38, &v42, &v26);
  v30 = v38;
  v31 = v39;
  v32 = v40;
  v33 = v41;
  sub_50E04F(&v50, &v30);
  v39 = v19 + v51;
  v40 = v20 + v52;
  v30 = (v18 + v50) * -0.25;
  v31 = v39 * -0.25;
  v32 = v40 * -0.25;
  v33 = (v21 + v53) * -0.25;
  sub_50E0D3(v17, &v30);
  result = sub_50DE26(&v38, &v46, v17);
  *a2 = v38;
  a2[1] = v39;
  a2[2] = v40;
  a2[3] = v41;
  *a3 = v46;
  a3[1] = v47;
  a3[2] = v48;
  a3[3] = v49;
  return result;
}
