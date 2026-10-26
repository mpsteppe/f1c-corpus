int __thiscall sub_524780(_DWORD *this)
{
  int v2; // ebp
  unsigned int v3; // ebx
  int v4; // esi
  int v5; // ecx
  int v6; // ebp
  bool v7; // zf
  bool v8; // cc
  float *v9; // ecx
  long double v10; // st7
  unsigned int v11; // ebp
  long double v12; // st7
  double v13; // st7
  int v14; // ebp
  int v16; // [esp+10h] [ebp-FCh]
  float v17; // [esp+10h] [ebp-FCh]
  float v18; // [esp+18h] [ebp-F4h]
  int v19; // [esp+20h] [ebp-ECh]
  int v20; // [esp+34h] [ebp-D8h]
  int v21; // [esp+38h] [ebp-D4h]
  int v22; // [esp+3Ch] [ebp-D0h]
  float v23; // [esp+40h] [ebp-CCh]
  int v24; // [esp+44h] [ebp-C8h]
  int v25; // [esp+48h] [ebp-C4h]
  int v26[6]; // [esp+4Ch] [ebp-C0h] BYREF
  int v27; // [esp+64h] [ebp-A8h]
  float v28; // [esp+68h] [ebp-A4h]
  float v29; // [esp+6Ch] [ebp-A0h]
  float v30; // [esp+70h] [ebp-9Ch]
  float v31; // [esp+80h] [ebp-8Ch]
  float v32; // [esp+84h] [ebp-88h]
  float v33; // [esp+88h] [ebp-84h]
  float v34; // [esp+98h] [ebp-74h]
  float v35; // [esp+9Ch] [ebp-70h]
  float v36; // [esp+A0h] [ebp-6Ch]
  float v37; // [esp+A4h] [ebp-68h]
  float v38; // [esp+A8h] [ebp-64h]
  float v39; // [esp+ACh] [ebp-60h]
  int v40[3]; // [esp+C8h] [ebp-44h] BYREF
  int v41[3]; // [esp+D4h] [ebp-38h] BYREF
  unsigned int v42; // [esp+ECh] [ebp-20h]
  float v43; // [esp+F8h] [ebp-14h]

  sub_546C00(&unk_BE2728, 12);
  sub_5D7710(2, 0);
  v2 = this[723234];
  v3 = 0;
  v4 = 0;
  v19 = v2;
  if ( (int)this[723232] > 0 )
  {
    while ( 1 )
    {
      v16 = (unsigned __int64)(*(float *)(v2 + 16) * 255.0);
      v5 = (unsigned __int64)(*(float *)(v2 + 20) * 255.0);
      v6 = -1;
      v7 = v5 == 0;
      v8 = v5 <= 0;
      v27 = -1;
      if ( v5 > 0 )
      {
        if ( !v16 )
        {
          v6 = -65792 * v5 - 1;
          v27 = v6;
        }
        v7 = v5 == 0;
        v8 = v5 <= 0;
      }
      if ( v7 )
        break;
      if ( !v8 && v16 > 0 )
      {
        if ( v16 <= v5 )
          v6 -= 65792 * v5;
        else
          v6 -= 257 * v16;
LABEL_16:
        v27 = v6;
      }
LABEL_17:
      if ( v4 )
      {
        v9 = (float *)this[723234];
        v31 = *(float *)v19 - *v9;
        v32 = *(float *)(v19 + 4) - v9[1];
        v18 = v32;
        v33 = *(float *)(v19 + 8) - v9[2];
        v10 = sqrt(v33 * v33 + v32 * v32 + v31 * v31);
        if ( v10 > 2.0 )
        {
          v28 = *(float *)v4 - *v9;
          v29 = *(float *)(v4 + 4) - v9[1];
          v18 = v29;
          v30 = *(float *)(v4 + 8) - v9[2];
          v17 = 2.0 - sqrt(v30 * v30 + v29 * v29 + v28 * v28);
          v12 = fmod(*(float *)(v4 + 12), 6.283185482025146);
          v43 = -cos(v12);
          v37 = -sin(v12) * v17;
          v34 = v37;
          v38 = v17 * 0.0;
          v35 = v38;
          v39 = v43 * v17;
          v36 = v39;
          v23 = v37 + *(float *)v4;
          *(float *)v40 = v23;
          *(float *)&v24 = v38 + *(float *)(v4 + 4);
          v40[1] = v24;
          v13 = v39 + *(float *)(v4 + 8);
          v42 = v3;
          v3 = v6;
          *(float *)&v25 = v13;
          v40[2] = v25;
          sub_523470((_DWORD *)v4, *(float *)(v4 + 12), (int)v41);
          sub_523470(v40, *(float *)(v4 + 12), (int)v26);
          sub_546BC0(&unk_BE2728, 12, v41, v26);
          *(_DWORD *)v4 = v20;
          *(_DWORD *)(v4 + 4) = v21;
          *(_DWORD *)(v4 + 8) = v22;
          v11 = v26[3];
        }
        else
        {
          v11 = ((unsigned int)(unsigned __int64)(v10 * 0.5 * 255.0) << 24) | (unsigned int)byte_FFFFFF & v6;
          v27 = v11;
        }
        v42 = v3;
        v3 = v11;
        sub_523470((_DWORD *)v4, *(float *)(v4 + 12), (int)v41);
        v14 = v19;
        sub_523470((_DWORD *)v19, *(float *)(v19 + 12), (int)v26);
        sub_546BC0(&unk_BE2728, 12, v41, v26);
      }
      else
      {
        v14 = v19;
      }
      v4 = v14;
      ++LODWORD(v18);
      if ( SLODWORD(v18) >= this[723232] )
        return sub_5D7710(1, 0);
      v2 = v14 + 24;
    }
    if ( v16 <= 0 )
      goto LABEL_17;
    v6 -= 257 * v16;
    goto LABEL_16;
  }
  return sub_5D7710(1, 0);
}
