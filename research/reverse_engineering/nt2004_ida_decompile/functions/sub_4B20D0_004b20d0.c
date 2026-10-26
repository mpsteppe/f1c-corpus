char __thiscall sub_4B20D0(float *this, int a2)
{
  double v3; // st7
  unsigned __int16 v4; // bx
  int v5; // eax
  int v6; // ebx
  unsigned int v7; // eax
  int v8; // eax
  int v9; // ecx
  int v10; // edx
  int v11; // edi
  double v12; // st7
  int v13; // ebx
  double v14; // st7
  __int64 v15; // rax
  __int64 v16; // rax
  double v17; // st6
  int v18; // eax
  int v20; // [esp-10h] [ebp-12Ch]
  int v21; // [esp+4h] [ebp-118h]
  float v22; // [esp+8h] [ebp-114h]
  float v23; // [esp+8h] [ebp-114h]
  float v24; // [esp+Ch] [ebp-110h]
  int v25; // [esp+Ch] [ebp-110h]
  float v26; // [esp+Ch] [ebp-110h]
  int v27; // [esp+10h] [ebp-10Ch]
  float v28; // [esp+10h] [ebp-10Ch]
  float v29; // [esp+14h] [ebp-108h]
  int v30; // [esp+14h] [ebp-108h]
  float v31; // [esp+18h] [ebp-104h]
  int v32[4]; // [esp+20h] [ebp-FCh] BYREF
  int v33; // [esp+30h] [ebp-ECh] BYREF
  float v34; // [esp+34h] [ebp-E8h]
  float v35[3]; // [esp+3Ch] [ebp-E0h] BYREF
  float v36; // [esp+48h] [ebp-D4h]
  float v37; // [esp+4Ch] [ebp-D0h]
  int v38; // [esp+50h] [ebp-CCh]
  float v39; // [esp+5Ch] [ebp-C0h]
  float v40; // [esp+60h] [ebp-BCh]
  int v41; // [esp+64h] [ebp-B8h]
  float v42; // [esp+68h] [ebp-B4h]
  float v43; // [esp+6Ch] [ebp-B0h]
  int v44; // [esp+70h] [ebp-ACh]
  float v45; // [esp+7Ch] [ebp-A0h]
  float v46; // [esp+80h] [ebp-9Ch]
  int v47; // [esp+84h] [ebp-98h]
  float v48; // [esp+88h] [ebp-94h]
  float v49; // [esp+8Ch] [ebp-90h]
  int v50; // [esp+90h] [ebp-8Ch]
  float v51; // [esp+9Ch] [ebp-80h]
  float v52; // [esp+A0h] [ebp-7Ch]
  int v53; // [esp+A4h] [ebp-78h]
  float v54; // [esp+A8h] [ebp-74h]
  float v55; // [esp+ACh] [ebp-70h]
  int v56; // [esp+B0h] [ebp-6Ch]
  float v57; // [esp+BCh] [ebp-60h]
  float v58; // [esp+C0h] [ebp-5Ch]
  int v59; // [esp+C4h] [ebp-58h]
  float v60; // [esp+C8h] [ebp-54h]
  float v61; // [esp+CCh] [ebp-50h]
  int v62; // [esp+D0h] [ebp-4Ch]
  float v63; // [esp+DCh] [ebp-40h]
  float v64; // [esp+E0h] [ebp-3Ch]
  int v65; // [esp+E4h] [ebp-38h]
  float v66; // [esp+E8h] [ebp-34h]
  float v67; // [esp+ECh] [ebp-30h]
  int v68; // [esp+F0h] [ebp-2Ch]
  float v69; // [esp+FCh] [ebp-20h]
  float v70; // [esp+100h] [ebp-1Ch]
  int v71; // [esp+104h] [ebp-18h]
  float v72; // [esp+108h] [ebp-14h]
  float v73; // [esp+10Ch] [ebp-10h]
  int v74; // [esp+110h] [ebp-Ch]

  if ( !*(_BYTE *)this || !dword_766080[*((_DWORD *)this + 3)] )
    return 0;
  if ( this[1] >= (double)this[2] || this[2] <= 0.0 )
  {
    v6 = -1996488705;
  }
  else
  {
    v3 = (this[2] - this[1]) / this[2];
    if ( v3 >= 0.0 )
    {
      if ( v3 > 1.0 )
        v3 = 1.0;
    }
    else
    {
      v3 = 0.0;
    }
    v24 = 1.0 - v3;
    v22 = 255.0 * v3;
    v29 = v24 * 255.0;
    HIBYTE(v4) = (__int64)(v24 * 136.0 + v22);
    LOBYTE(v4) = (__int64)(v29 + v22);
    v5 = (unsigned __int8)(__int64)(v3 * 0.0 + v29);
    v6 = v5 | ((v5 | (v4 << 8)) << 8);
  }
  if ( this[11] <= 0.1 )
    return 0;
  sub_5069D0(*((__int16 *)this + 8), *((__int16 *)this + 9), 1, 0);
  sub_506980(
    (__int64)((double)*((__int16 *)this + 12) * this[11]),
    (__int64)((double)*((__int16 *)this + 13) * this[11]));
  sub_506B20(v6);
  sub_506960(0);
  if ( a2 != 5 )
    return 0;
  v7 = sub_4F82E0(dword_75AAC4);
  if ( v7 == -2 )
  {
    v7 = 48;
  }
  else if ( v7 > 0x30 )
  {
    return 0;
  }
  v8 = 6326 * v7;
  if ( (dword_632238[v8] & 2) != 0 )
  {
    v9 = dword_62C724[v8];
    v32[1] = dword_62C720[v8];
    v10 = dword_62C728[v8];
    v32[2] = v9;
    v32[3] = v10;
    sub_40C4B0(&dword_6291CC);
    if ( (unsigned __int8)sub_5060A0((int)&v33, (int)v32, 200.0) )
    {
      v11 = (__int64)*(float *)&v33;
      v12 = (double)dword_6152E8;
      v13 = (__int64)v34;
      if ( v11 > (int)(__int64)(0.050000001 * v12) && v11 < (int)(__int64)(v12 * 0.94999999) )
      {
        v14 = (double)dword_6152EC;
        if ( v13 > (int)(__int64)(0.050000001 * v14) && v13 < (int)(__int64)(v14 * 0.94999999) )
        {
          v30 = *((__int16 *)this + 8);
          v27 = (__int64)((double)*((__int16 *)this + 12) * this[11] + (double)v30);
          v21 = *((__int16 *)this + 13);
          v25 = *((__int16 *)this + 9);
          v15 = (__int64)((double)v21 * this[11] + (double)v25);
          v35[2] = 0.0;
          v35[0] = (float)v30;
          v38 = 0;
          v41 = 0;
          v44 = 0;
          v47 = 0;
          v26 = (float)v25;
          v50 = 0;
          v35[1] = v26;
          v46 = v26;
          v36 = (float)v27;
          v40 = v26;
          v39 = v35[0];
          v42 = v35[0];
          v37 = v26;
          v53 = 0;
          v43 = (float)(int)v15;
          v56 = 0;
          v45 = v36;
          v48 = v36;
          v49 = v43;
          v51 = v35[0];
          v52 = v43;
          v54 = v36;
          v55 = v43;
          v16 = (__int64)((double)(v21 / 2) * this[11] + v26);
          v57 = v36;
          v17 = (double)(int)v16;
          v59 = 0;
          v28 = v17;
          v58 = v17 - 1.0;
          v31 = (float)v11;
          v60 = v31;
          v62 = 0;
          v65 = 0;
          v23 = (float)(__int64)v34;
          v68 = 0;
          v61 = v23;
          v63 = v36;
          v67 = v23;
          v64 = v17;
          v20 = dword_7E8CDC;
          v66 = v31;
          v69 = v36;
          v71 = 0;
          v72 = v31;
          v73 = v23;
          v74 = 0;
          v70 = v28 + 1.0;
          v18 = sub_4B1A80(3355443, -1996523657, 0.667);
          sub_4AB2E0((int)v35, 7, v18, v20, 0);
          return 0;
        }
      }
    }
  }
  return 0;
}
