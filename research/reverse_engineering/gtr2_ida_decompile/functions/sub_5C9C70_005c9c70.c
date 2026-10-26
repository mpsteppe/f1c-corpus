char __thiscall sub_5C9C70(_BYTE *this, int a2, int a3, int a4, int a5)
{
  _UNKNOWN **v7; // esi
  int v8; // esi
  int v9; // eax
  double v10; // st7
  double v11; // st6
  float v12; // edx
  double v13; // st7
  double v14; // st6
  float v15; // edx
  double v16; // st7
  double v17; // st6
  float v18; // edx
  double v19; // st7
  double v20; // st6
  _UNKNOWN **v21; // [esp+24h] [ebp-ACh] BYREF
  int v22; // [esp+28h] [ebp-A8h]
  void *Block; // [esp+2Ch] [ebp-A4h]
  int v24; // [esp+34h] [ebp-9Ch]
  char v25[8]; // [esp+40h] [ebp-90h] BYREF
  _BYTE v26[32]; // [esp+48h] [ebp-88h] BYREF
  float v27; // [esp+68h] [ebp-68h]
  float v28; // [esp+6Ch] [ebp-64h]
  float v29; // [esp+70h] [ebp-60h]
  float v30; // [esp+74h] [ebp-5Ch]
  float v31; // [esp+78h] [ebp-58h]
  float v32; // [esp+7Ch] [ebp-54h]
  float v33; // [esp+80h] [ebp-50h]
  float v34; // [esp+84h] [ebp-4Ch]
  float v35; // [esp+88h] [ebp-48h]
  float v36; // [esp+8Ch] [ebp-44h]
  float v37; // [esp+90h] [ebp-40h]
  float v38; // [esp+94h] [ebp-3Ch]
  float v39; // [esp+98h] [ebp-38h]
  float v40; // [esp+9Ch] [ebp-34h]
  float v41; // [esp+A0h] [ebp-30h]
  float v42; // [esp+A4h] [ebp-2Ch]
  unsigned __int8 v43; // [esp+A8h] [ebp-28h]
  unsigned __int8 v44; // [esp+A9h] [ebp-27h]
  int v45; // [esp+BCh] [ebp-14h]
  int v46; // [esp+C4h] [ebp-Ch]

  v45 = dword_912B08;
  v24 = 0;
  if ( a3 )
  {
    (*(void (__thiscall **)(int, _BYTE *, int))(*(_DWORD *)a2 + 4))(a2, v26, 108);
    if ( this[12] )
    {
      sub_643E40("- Material name = '%s'", v25);
      if ( this[12] )
      {
        sub_643E40("    + Ambient       : (%f, %f, %f)", v27, v28, v29);
        if ( this[12] )
        {
          sub_643E40("    + Diffuse       : (%f, %f, %f)", v30, v31, v32);
          if ( this[12] )
          {
            sub_643E40("    + Specular      : (%f, %f, %f)", v33, v34, v35);
            if ( this[12] )
            {
              sub_643E40("    + Emissive      : (%f, %f, %f)", v36, v37, v38);
              if ( this[12] )
              {
                sub_643E40("    + Shine         : %f", v39);
                if ( this[12] )
                {
                  sub_643E40("    + Shine strength: %f", v40);
                  if ( this[12] )
                  {
                    sub_643E40("    + Opacity       : %f", v41);
                    if ( this[12] )
                    {
                      sub_643E40("    + IOR           : %f", v42);
                      if ( this[12] )
                      {
                        sub_643E40("    + Double sided  : %d", v43);
                        if ( this[12] )
                          sub_643E40("    + WireFrame     : %d", v44);
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    v7 = (_UNKNOWN **)operator new(0x74u);
    v21 = v7;
    v46 = 0;
    if ( v7 )
    {
      sub_4050C0((int)v25);
      return off_16C97A8(v7, a2, a3, a4, a5);
    }
    else
    {
      v46 = 2;
      v21 = &off_7296CC;
      v22 = 0;
      sub_5BD2D0(&v21, 0);
      v46 = 4;
      if ( ((unsigned __int8)Block & 1) != 0 )
        sub_5A8840();
      v8 = v22;
      if ( v22 )
        v9 = (*(int (__thiscall **)(int))(*(_DWORD *)v22 + 12))(v22);
      else
        v9 = 0;
      v10 = v28;
      v11 = v29;
      *(float *)(v9 + 32) = v27;
      *(float *)(v9 + 36) = v10;
      *(_DWORD *)(v9 + 44) = 1065353216;
      *(float *)(v9 + 40) = v11;
      v12 = v30;
      v13 = v31;
      v14 = v32;
      *(_DWORD *)(v9 + 60) = 1065353216;
      *(float *)(v9 + 48) = v12;
      *(float *)(v9 + 52) = v13;
      *(float *)(v9 + 56) = v14;
      v15 = v33;
      v16 = v34;
      v17 = v35;
      *(_DWORD *)(v9 + 76) = 1065353216;
      *(float *)(v9 + 64) = v15;
      *(float *)(v9 + 68) = v16;
      *(float *)(v9 + 72) = v17;
      v18 = v36;
      v19 = v37;
      v20 = v38;
      *(_DWORD *)(v9 + 92) = 1065353216;
      *(float *)(v9 + 80) = v18;
      *(float *)(v9 + 84) = v19;
      *(float *)(v9 + 88) = v20;
      *(_BYTE *)(v9 + 112) = v43;
      *(float *)(v9 + 108) = v42;
      *(float *)(v9 + 104) = v41;
      *(float *)(v9 + 96) = v39;
      *(_BYTE *)(v9 + 113) = v44;
      *(float *)(v9 + 100) = v40;
      sub_5BD510();
      v45 = -1;
      if ( v8 )
        (*(void (__thiscall **)(int, _DWORD, _UNKNOWN ***))(*(_DWORD *)v8 + 4))(v8, 0, &v21);
      return 1;
    }
  }
  else
  {
    if ( this[12] )
      sub_643E40("Passed actor seems to be not valid!");
    return 0;
  }
}
