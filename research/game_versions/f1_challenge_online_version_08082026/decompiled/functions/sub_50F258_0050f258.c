int __stdcall sub_50F258(int a1, int a2, float *a3, int a4, int a5, float *a6, int a7)
{
  unsigned __int8 v8; // c0
  unsigned __int8 v9; // c3
  int result; // eax
  float v11; // [esp+1Ch] [ebp-30h]
  float v12; // [esp+20h] [ebp-2Ch]
  int v13; // [esp+68h] [ebp+1Ch]
  float v14; // [esp+6Ch] [ebp+20h]
  float v15; // [esp+70h] [ebp+24h]
  int v16; // [esp+74h] [ebp+28h]
  float v17; // [esp+78h] [ebp+2Ch]
  float v18; // [esp+7Ch] [ebp+30h]
  float v19; // [esp+80h] [ebp+34h]
  float v20; // [esp+84h] [ebp+38h]
  float v21; // [esp+88h] [ebp+3Ch]
  float v22; // [esp+8Ch] [ebp+40h]
  float v23; // [esp+90h] [ebp+44h]
  float v24; // [esp+94h] [ebp+48h]
  float v25; // [esp+9Ch] [ebp+50h]
  float v26; // [esp+A0h] [ebp+54h]

  v21 = *a6;
  v22 = a6[1];
  v23 = a6[2];
  v24 = a6[3];
  if ( !(v8 | v9) )
  {
    v17 = -v21;
    v18 = -v22;
    v19 = -v23;
    v20 = -v24;
    v21 = v17;
    v22 = v18;
    v23 = v19;
    v24 = v20;
  }
  v25 = v22 - *(float *)(a7 + 4);
  v26 = v23 - *(float *)(a7 + 8);
  sub_50DF95();
  sub_50DE26();
  sub_50E04F();
  sub_50DE26();
  sub_50E04F();
  v14 = v11 + v25;
  v15 = v12 + v26;
  sub_50E0D3();
  sub_50DE26();
  *(_DWORD *)a1 = v13;
  *(float *)(a1 + 4) = v14;
  *(float *)(a1 + 8) = v15;
  *(_DWORD *)(a1 + 12) = v16;
  sub_50DF95();
  sub_50DE26();
  sub_50E04F();
  sub_50DE26();
  sub_50E04F();
  sub_50E0D3();
  result = sub_50DE26();
  *(_DWORD *)a2 = v13;
  *(float *)(a2 + 4) = v14;
  *(float *)(a2 + 8) = v15;
  *(_DWORD *)(a2 + 12) = v16;
  *a3 = v21;
  a3[1] = v22;
  a3[2] = v23;
  a3[3] = v24;
  return result;
}
