char __thiscall sub_5CA030(_BYTE *this, int a2, int a3, int a4, int a5)
{
  void *v7; // esi
  int v8; // eax
  int v9; // esi
  int v10; // eax
  double v11; // st7
  double v12; // st6
  float v13; // edx
  double v14; // st7
  double v15; // st6
  float v16; // edx
  double v17; // st7
  double v18; // st6
  float v19; // edx
  double v20; // st7
  double v21; // st6
  void *Block; // [esp+2Ch] [ebp-CCh] BYREF
  int v23; // [esp+30h] [ebp-C8h]
  int v24; // [esp+34h] [ebp-C4h]
  int v25; // [esp+38h] [ebp-C0h]
  _BYTE v26[12]; // [esp+3Ch] [ebp-BCh] BYREF
  char v27[80]; // [esp+48h] [ebp-B0h] BYREF
  float v28; // [esp+98h] [ebp-60h]
  float v29; // [esp+9Ch] [ebp-5Ch]
  float v30; // [esp+A0h] [ebp-58h]
  float v31; // [esp+A4h] [ebp-54h]
  float v32; // [esp+A8h] [ebp-50h]
  float v33; // [esp+ACh] [ebp-4Ch]
  float v34; // [esp+B0h] [ebp-48h]
  float v35; // [esp+B4h] [ebp-44h]
  float v36; // [esp+B8h] [ebp-40h]
  float v37; // [esp+BCh] [ebp-3Ch]
  float v38; // [esp+C0h] [ebp-38h]
  float v39; // [esp+C4h] [ebp-34h]
  float v40; // [esp+C8h] [ebp-30h]
  float v41; // [esp+CCh] [ebp-2Ch]
  float v42; // [esp+D0h] [ebp-28h]
  float v43; // [esp+D4h] [ebp-24h]
  unsigned __int8 v44; // [esp+D8h] [ebp-20h]
  unsigned __int8 v45; // [esp+D9h] [ebp-1Fh]
  int v46; // [esp+E4h] [ebp-14h]
  int v47; // [esp+ECh] [ebp-Ch]
  int v48; // [esp+F4h] [ebp-4h]
  char vars0; // [esp+F8h] [ebp+0h]

  v46 = dword_912B08;
  v24 = 0;
  if ( a3 )
  {
    (*(void (__thiscall **)(int, char *, int))(*(_DWORD *)a2 + 4))(a2, v27, 148);
    if ( this[12] )
    {
      sub_643E40("- Material name = '%s'", v27);
      if ( this[12] )
      {
        sub_643E40("    + Ambient       : (%f, %f, %f)", v28, v29, v30);
        if ( this[12] )
        {
          sub_643E40("    + Diffuse       : (%f, %f, %f)", v31, v32, v33);
          if ( this[12] )
          {
            sub_643E40("    + Specular      : (%f, %f, %f)", v34, v35, v36);
            if ( this[12] )
            {
              sub_643E40("    + Emissive      : (%f, %f, %f)", v37, v38, v39);
              if ( this[12] )
              {
                sub_643E40("    + Shine         : %f", v40);
                if ( this[12] )
                {
                  sub_643E40("    + Shine strength: %f", v41);
                  if ( this[12] )
                  {
                    sub_643E40("    + Opacity       : %f", v42);
                    if ( this[12] )
                    {
                      sub_643E40("    + IOR           : %f", v43);
                      if ( this[12] )
                      {
                        sub_643E40("    + Double sided  : %d", v44);
                        if ( this[12] )
                          sub_643E40("    + WireFrame     : %d", v45);
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
    v7 = operator new(0x74u);
    Block = v7;
    v48 = 0;
    if ( v7 )
    {
      sub_4050C0((int)v27);
      vars0 = 1;
      v25 = 1;
      v8 = sub_5D3BE0(v7, v26);
    }
    else
    {
      v8 = 0;
    }
    v48 = 2;
    Block = &off_7296CC;
    v23 = 0;
    sub_5BD2D0(&Block, v8);
    v48 = 4;
    if ( (v24 & 1) != 0 )
      sub_5A8840();
    v9 = v23;
    if ( v23 )
      v10 = (*(int (__thiscall **)(int))(*(_DWORD *)v23 + 12))(v23);
    else
      v10 = 0;
    v11 = v29;
    v12 = v30;
    *(float *)(v10 + 32) = v28;
    *(float *)(v10 + 36) = v11;
    *(_DWORD *)(v10 + 44) = 1065353216;
    *(float *)(v10 + 40) = v12;
    v13 = v31;
    v14 = v32;
    v15 = v33;
    *(_DWORD *)(v10 + 60) = 1065353216;
    *(float *)(v10 + 48) = v13;
    *(float *)(v10 + 52) = v14;
    *(float *)(v10 + 56) = v15;
    v16 = v34;
    v17 = v35;
    v18 = v36;
    *(_DWORD *)(v10 + 76) = 1065353216;
    *(float *)(v10 + 64) = v16;
    *(float *)(v10 + 68) = v17;
    *(float *)(v10 + 72) = v18;
    v19 = v37;
    v20 = v38;
    v21 = v39;
    *(_DWORD *)(v10 + 92) = 1065353216;
    *(float *)(v10 + 80) = v19;
    *(float *)(v10 + 84) = v20;
    *(float *)(v10 + 88) = v21;
    *(_BYTE *)(v10 + 112) = v44;
    *(float *)(v10 + 108) = v43;
    *(float *)(v10 + 104) = v42;
    *(float *)(v10 + 96) = v40;
    *(_BYTE *)(v10 + 113) = v45;
    *(float *)(v10 + 100) = v41;
    sub_5BD510();
    v47 = -1;
    if ( v9 )
      (*(void (__thiscall **)(int, _DWORD, void **))(*(_DWORD *)v9 + 4))(v9, 0, &Block);
    return 1;
  }
  else
  {
    if ( this[12] )
      sub_643E40("Passed actor seems to be not valid!");
    return 0;
  }
}
