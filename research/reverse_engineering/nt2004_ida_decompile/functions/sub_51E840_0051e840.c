void __thiscall sub_51E840(int this, float a2)
{
  unsigned int v3; // ecx
  unsigned __int8 v5; // c0
  unsigned __int8 v6; // c2
  char v7; // dl
  long double v8; // st7
  int v9; // ebp
  int v10; // edi
  _DWORD *v11; // eax
  _BYTE *v12; // ecx
  int v13; // edx
  int v14; // edx
  int v15; // eax
  bool v16; // zf
  bool v17; // sf
  bool v18; // of
  double v19; // st7
  float v20; // edx
  double v21; // st7
  double v22; // st7
  double v23; // st7
  long double v24; // st7
  long double v25; // st6
  float v26; // [esp+4h] [ebp-68h] BYREF
  float v27; // [esp+8h] [ebp-64h] BYREF
  float v28; // [esp+Ch] [ebp-60h] BYREF
  float v29; // [esp+10h] [ebp-5Ch]
  float v30; // [esp+14h] [ebp-58h]
  float v31[3]; // [esp+18h] [ebp-54h] BYREF
  float v32[9]; // [esp+24h] [ebp-48h] BYREF
  float v33[6]; // [esp+48h] [ebp-24h] BYREF
  float v34; // [esp+60h] [ebp-Ch] BYREF
  float v35; // [esp+64h] [ebp-8h]
  float v36; // [esp+68h] [ebp-4h]

  v3 = *(_DWORD *)(this + 16500);
  if ( v3 <= 1 && (*(_DWORD *)(*(_DWORD *)this + 25296) & 8) != 0 )
  {
    if ( byte_769254 != 1 )
      goto LABEL_38;
    if ( *(float *)(this + 17500) >= 0.70710677 )
    {
      *(_DWORD *)(this + 20692) = 0;
    }
    else
    {
      v26 = a2 + *(float *)(this + 20692);
      *(float *)(this + 20692) = v26;
      if ( v5 | v6 )
      {
        v7 = 0;
        if ( !v3 && (byte_75E9C7 || byte_75E9CB) )
          v7 = 1;
        if ( v26 > 5.0 || v7 && v26 > 3.0 )
        {
          sub_51F0F0(this);
          v8 = atan2(*(float *)(this + 17492), *(float *)(this + 17516));
          *(_DWORD *)(this + 17532) = 0;
          *(_DWORD *)(this + 17540) = 0;
          *(float *)(this + 17536) = v8;
          sub_579100(this + 17532, this + 17484);
          sub_51C1E0((float *)this, v31, &v28);
          sub_51BE20(this, v31, &v28);
        }
      }
    }
    v9 = 0;
    v10 = 0;
    v11 = (_DWORD *)(this + 17924);
    v12 = (_BYTE *)(this + 2212);
    v13 = 4;
    do
    {
      if ( *v12 )
      {
        ++v10;
        if ( !*v11 )
          ++v9;
      }
      v12 += 304;
      v11 += 62;
      --v13;
    }
    while ( v13 );
    if ( v9 || v10 <= 2 )
    {
      if ( v9 == v10 && *(_BYTE *)(this + 20689) )
      {
        sub_51F0F0(this);
        *(_DWORD *)(this + 17520) = *(_DWORD *)(this + 20712);
        v15 = *(_DWORD *)(this + 20720);
        *(_DWORD *)(this + 17524) = *(_DWORD *)(this + 20716);
        *(_DWORD *)(this + 17528) = v15;
        sub_51C1E0((float *)this, &v28, v31);
        sub_51BE20(this, &v28, v31);
      }
      else
      {
        v18 = __OFSUB__(v9, 1);
        v16 = v9 == 1;
        v17 = v9 - 1 < 0;
        if ( v9 <= 1 )
        {
LABEL_37:
          *(_BYTE *)(this + 20689) = !(v17 ^ v18 | v16);
LABEL_38:
          if ( dword_75CBB0 != 8 )
            sub_51EC00(a2);
          return;
        }
        if ( *(_BYTE *)(this + 20689) )
        {
          v19 = *(float *)(this + 20712) - *(float *)(this + 17520);
          v33[0] = *(float *)(this + 17520);
          v28 = v19;
          v20 = *(float *)(this + 17528);
          v21 = *(float *)(this + 20716) - *(float *)(this + 17524);
          v33[1] = *(float *)(this + 17524);
          v33[2] = v20;
          v29 = v21;
          v22 = *(float *)(this + 20720);
          v35 = v29;
          v23 = v22 - *(float *)(this + 17528);
          v34 = v28;
          v30 = v23;
          v36 = v30;
          v24 = sqrt(v30 * v30 + v28 * v28) * 0.1 + v29;
          if ( v28 == 0.0 && v24 == 0.0 && v36 == 0.0 )
          {
            v34 = 0.0;
            v35 = 1.0;
            v36 = 0.0;
          }
          else
          {
            v25 = 1.0 / sqrt(v24 * v24 + v36 * v36 + v34 * v34);
            v34 = v34 * v25;
            v35 = v25 * v24;
            v36 = v25 * v36;
          }
          v33[3] = v34;
          v33[4] = v35;
          v33[5] = v36;
          sub_519A30((float *)this, v33, &v34, &v26, &v27, 0);
          if ( v26 > 0.0 )
            v26 = 0.0;
          v32[2] = 0.5;
          LODWORD(v32[3]) = 10;
          v32[1] = -(v26 / v27);
          sub_518070((float *)this, (int)v32, 0);
          sub_518510((float *)this, v32);
        }
      }
    }
    else
    {
      *(_DWORD *)(this + 20712) = *(_DWORD *)(this + 17520);
      v14 = *(_DWORD *)(this + 17528);
      *(_DWORD *)(this + 20716) = *(_DWORD *)(this + 17524);
      *(_DWORD *)(this + 20720) = v14;
    }
    v18 = __OFSUB__(v9, 1);
    v16 = v9 == 1;
    v17 = v9 - 1 < 0;
    goto LABEL_37;
  }
}
