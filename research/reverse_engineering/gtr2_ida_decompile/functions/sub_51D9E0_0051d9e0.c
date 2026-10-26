int __thiscall sub_51D9E0(
        _DWORD *this,
        int a2,
        float a3,
        float a4,
        float a5,
        float a6,
        int a7,
        int a8,
        float *a9,
        float a10)
{
  _DWORD *v10; // eax
  bool v11; // cf
  float *v12; // edi
  int v13; // ebp
  float *v14; // esi
  int v15; // eax
  int v16; // ecx
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int *v20; // ebx
  _DWORD *v21; // ecx
  float *v22; // edx
  float *v23; // eax
  int result; // eax
  double v25; // st7
  double v26; // st7
  double v27; // st7
  double v28; // st7
  float *v29; // [esp+10h] [ebp-B8h]
  _DWORD *v30; // [esp+14h] [ebp-B4h]
  float *v31; // [esp+18h] [ebp-B0h]
  int v32; // [esp+1Ch] [ebp-ACh]
  float v33; // [esp+20h] [ebp-A8h] BYREF
  float v34; // [esp+24h] [ebp-A4h]
  float v35; // [esp+28h] [ebp-A0h]
  float v36; // [esp+2Ch] [ebp-9Ch]
  float v37; // [esp+30h] [ebp-98h]
  float v38; // [esp+34h] [ebp-94h]
  int v39; // [esp+38h] [ebp-90h]
  float v40; // [esp+3Ch] [ebp-8Ch]
  float v41; // [esp+40h] [ebp-88h]
  float v42; // [esp+44h] [ebp-84h]
  float v43[3]; // [esp+48h] [ebp-80h] BYREF
  _BYTE v44[8]; // [esp+54h] [ebp-74h] BYREF
  float v45; // [esp+5Ch] [ebp-6Ch]
  int v46; // [esp+60h] [ebp-68h] BYREF
  _DWORD v47[16]; // [esp+64h] [ebp-64h] BYREF
  _BYTE v48[8]; // [esp+A4h] [ebp-24h] BYREF
  char v49; // [esp+ACh] [ebp-1Ch] BYREF
  _BYTE v50[12]; // [esp+B0h] [ebp-18h] BYREF
  _BYTE v51[12]; // [esp+BCh] [ebp-Ch] BYREF

  memset(v47, 0, sizeof(v47));
  v10 = (_DWORD *)this[7];
  v47[15] = 1065353216;
  v47[10] = 1065353216;
  v47[5] = 1065353216;
  v47[0] = 1065353216;
  v46 = 1;
  v11 = (*v10 & 8) != 0;
  v39 = v10[26];
  v32 = v11 ? 0x8000 : 4096;
  sub_51D2B0(&a3, &a6, (int)&v46);
  sub_5EB210(a2, v48, v50, v51);
  v12 = a9;
  v13 = 0;
  v14 = (float *)&v49;
  do
  {
    if ( a2 >= *(_DWORD *)(v39 + 368) )
      v15 = 0;
    else
      v15 = *(_DWORD *)(v39 + 372) + 36 * a2;
    if ( v13 < 0 )
    {
      v19 = 0;
    }
    else
    {
      v16 = *(_DWORD *)(v15 + 8);
      v17 = *(unsigned __int16 *)(v15 + v13);
      if ( (*(_BYTE *)v16 & 8) != 0 )
        v18 = 88 * v17;
      else
        v18 = v17 << 6;
      v19 = *(_DWORD *)(v16 + 32) + v18;
    }
    if ( v32 == 4096 )
    {
      v20 = (int *)(v19 + 32);
      v21 = (_DWORD *)(v19 + 36);
      v22 = (float *)(v19 + 48);
      v23 = (float *)(v19 + 52);
    }
    else
    {
      v20 = (int *)(v19 + 56);
      v21 = (_DWORD *)(v19 + 60);
      v22 = (float *)(v19 + 72);
      v23 = (float *)(v19 + 76);
    }
    v30 = v21;
    v31 = v22;
    v29 = v23;
    result = *v20;
    if ( *v20 == 1036831949 || result == 1050253722 )
    {
      v36 = *(v14 - 2) - a3;
      v25 = *(v14 - 1);
      v33 = v36;
      v37 = v25 - a4;
      v26 = *v14;
      v34 = v37;
      v38 = v26 - a5;
      v35 = v38;
      sub_5D77B0(&v33, v43, v47);
      *v31 = (v43[0] + a10) * 0.1 + 0.5;
      v40 = v12[1] - a3;
      v27 = v12[2];
      v33 = v40;
      v41 = v27 - a4;
      v28 = v12[3];
      v34 = v41;
      v42 = v28 - a5;
      v35 = v42;
      result = sub_5D77B0(&v33, v44, v47);
      *v29 = v43[2] - v45 + v12[19];
      *v30 = -998637732;
      *v20 = 1045220557;
    }
    v13 += 2;
    v14 += 3;
  }
  while ( v13 < 6 );
  return result;
}
