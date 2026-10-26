void __thiscall sub_584520(int this, float a2)
{
  unsigned int v3; // ecx
  unsigned __int8 v5; // c0
  unsigned __int8 v6; // c2
  char v7; // dl
  long double v8; // st7
  int v9; // edi
  int v10; // eax
  int v11; // eax
  int v12; // ecx
  bool v13; // zf
  bool v14; // sf
  bool v15; // of
  float v16; // ecx
  float *v17; // eax
  float v18; // ecx
  float v19; // edx
  float v20; // [esp+14h] [ebp-70h] BYREF
  float v21; // [esp+18h] [ebp-6Ch] BYREF
  float v22[2]; // [esp+1Ch] [ebp-68h] BYREF
  int v23; // [esp+24h] [ebp-60h] BYREF
  int v24; // [esp+28h] [ebp-5Ch] BYREF
  float v25; // [esp+2Ch] [ebp-58h] BYREF
  float v26; // [esp+30h] [ebp-54h] BYREF
  _BYTE v27[4]; // [esp+34h] [ebp-50h] BYREF
  float v28; // [esp+38h] [ebp-4Ch]
  int v29; // [esp+3Ch] [ebp-48h]
  int v30; // [esp+40h] [ebp-44h]
  float v31[6]; // [esp+58h] [ebp-2Ch] BYREF
  float v32; // [esp+70h] [ebp-14h] BYREF
  float v33; // [esp+74h] [ebp-10h]
  float v34; // [esp+78h] [ebp-Ch]
  float v35; // [esp+80h] [ebp-4h]

  v3 = *(_DWORD *)(this + 14804);
  if ( v3 <= 1 && (*(_DWORD *)(*(_DWORD *)this + 22580) & 8) != 0 )
  {
    if ( byte_B72D3C != 1 )
      goto LABEL_42;
    if ( *(float *)(this + 15952) >= 0.70710677 )
    {
      *(_DWORD *)(this + 19188) = 0;
    }
    else
    {
      v22[0] = a2 + *(float *)(this + 19188);
      *(float *)(this + 19188) = v22[0];
      if ( v5 | v6 )
      {
        v7 = 0;
        if ( !v3 && (byte_B660D7 || byte_B660DB) )
          v7 = 1;
        if ( v22[0] > 5.0 || v7 && v22[0] > 3.0 )
        {
          sub_573810();
          v8 = atan2(*(float *)(this + 15944), *(float *)(this + 15968));
          *(_DWORD *)(this + 15984) = 0;
          *(_DWORD *)(this + 15992) = 0;
          *(float *)(this + 15988) = v8;
          sub_614A90(this + 15984, this + 15936);
          sub_577780((float *)this, &v26, &v23);
          sub_57DCC0((void *)this, (int)&v26, &v23);
        }
      }
    }
    if ( *(_BYTE *)(*(_DWORD *)this + 15572) )
      goto LABEL_42;
    v9 = 0;
    v10 = 0;
    if ( *(_BYTE *)(this + 3216) )
    {
      v10 = 1;
      v9 = *(_DWORD *)(this + 0x4000) == 0;
    }
    if ( *(_BYTE *)(this + 3512) )
    {
      ++v10;
      if ( !*(_DWORD *)(this + 16636) )
        ++v9;
    }
    if ( *(_BYTE *)(this + 3808) )
    {
      ++v10;
      if ( !*(_DWORD *)(this + 16888) )
        ++v9;
    }
    if ( *(_BYTE *)(this + 4104) )
    {
      ++v10;
      if ( !*(_DWORD *)(this + 17140) )
        ++v9;
    }
    if ( v9 || v10 <= 2 )
    {
      if ( v9 == v10 && *(_BYTE *)(this + 19185) )
      {
        sub_573810();
        *(_DWORD *)(this + 15972) = *(_DWORD *)(this + 19208);
        v12 = *(_DWORD *)(this + 19216);
        *(_DWORD *)(this + 15976) = *(_DWORD *)(this + 19212);
        *(_DWORD *)(this + 15980) = v12;
        sub_577780((float *)this, v22, &v24);
        sub_57DCC0((void *)this, (int)v22, &v24);
      }
      else
      {
        v15 = __OFSUB__(v9, 1);
        v13 = v9 == 1;
        v14 = v9 - 1 < 0;
        if ( v9 <= 1 )
        {
LABEL_41:
          *(_BYTE *)(this + 19185) = !(v14 ^ v15 | v13);
LABEL_42:
          sub_57F4F0(this, v35);
          return;
        }
        if ( *(_BYTE *)(this + 19185) )
        {
          v31[0] = *(float *)(this + 15972);
          v16 = *(float *)(this + 15976);
          v31[2] = *(float *)(this + 15980);
          v31[1] = v16;
          v17 = sub_401290((float *)(this + 19208), (float *)(this + 15972), (float *)&v24);
          v18 = *v17;
          v19 = v17[1];
          v34 = v17[2];
          v32 = v18;
          v33 = sqrt(v34 * v34 + v18 * v18) * 0.1 + v19;
          if ( sub_4011C0(&v32) )
          {
            off_16C97F0(LODWORD(a2));
            return;
          }
          sub_401380(&v32);
          v31[3] = v32;
          v31[4] = v33;
          v31[5] = v34;
          sub_576B50((float *)this, v31, &v32, &v20, &v21, 0);
          if ( v20 > 0.0 )
            v20 = 0.0;
          v29 = 1056964608;
          v30 = 11;
          v28 = -1.0 / v21 * v20;
          sub_584170((int)v27);
          sub_5768E0((float *)this, &v25);
        }
      }
    }
    else
    {
      *(_DWORD *)(this + 19208) = *(_DWORD *)(this + 15972);
      v11 = *(_DWORD *)(this + 15980);
      *(_DWORD *)(this + 19212) = *(_DWORD *)(this + 15976);
      *(_DWORD *)(this + 19216) = v11;
    }
    v15 = __OFSUB__(v9, 1);
    v13 = v9 == 1;
    v14 = v9 - 1 < 0;
    goto LABEL_41;
  }
}
