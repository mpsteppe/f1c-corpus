void __thiscall sub_55D5C0(int this, float *a2, int a3)
{
  int v4; // edi
  int v5; // ecx
  int v6; // eax
  int v7; // ecx
  float *v8; // eax
  double v9; // st7
  double v10; // st6
  double v11; // st5
  long double v12; // st5
  long double v13; // st5
  double v14; // st7
  long double v15; // st4
  int v16; // [esp+Ch] [ebp-Ch] BYREF
  int v17; // [esp+10h] [ebp-8h] BYREF
  float v18; // [esp+14h] [ebp-4h] BYREF

  if ( a2 )
  {
    *(_DWORD *)(this + 20) |= 0x40000u;
    v4 = *(_DWORD *)(dword_8B8F28 + 288);
    v5 = *(_DWORD *)(dword_8B8F28 + 284);
    v6 = 0;
    if ( v5 > 0 )
    {
      while ( *(char *)v4 >= 0 )
      {
        v4 = *(_DWORD *)(v4 + 108);
        if ( ++v6 >= v5 )
          return;
      }
      v7 = *(_DWORD *)(this + 312);
      if ( (*(_BYTE *)(v7 + 60) & 0x10) != 0 )
      {
        v8 = (float *)(this + 232);
      }
      else
      {
        SceneNodePositionGetter((_DWORD *)v7, &v16, &v17, &v18);
        v8 = (float *)&v16;
      }
      v9 = a2[9] + *v8;
      v10 = v8[1] + a2[10];
      v11 = v8[2] + a2[11];
      v18 = v11;
      v12 = sqrt(v11 * v18 + v10 * v10 + v9 * v9);
      if ( v12 != 0.0 )
      {
        v13 = -1.0 / v12;
        v9 = v9 * v13;
        v10 = v10 * v13;
        v18 = v13 * v18;
      }
      *(float *)(this + 256) = v9 - *(float *)(v4 + 68);
      *(float *)(this + 260) = v10 - *(float *)(v4 + 72);
      v14 = v18 - *(float *)(v4 + 76);
      *(float *)(this + 264) = v14;
      v15 = sqrt(
              *(float *)(this + 256) * *(float *)(this + 256)
            + *(float *)(this + 260) * *(float *)(this + 260)
            + v14 * v14);
      if ( v15 != 0.0 )
      {
        *(float *)(this + 256) = 1.0 / v15 * *(float *)(this + 256);
        *(float *)(this + 260) = 1.0 / v15 * *(float *)(this + 260);
        *(float *)(this + 264) = 1.0 / v15 * *(float *)(this + 264);
      }
    }
  }
}

