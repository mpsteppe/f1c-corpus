char __thiscall sub_5CDCC0(_BYTE *this, int a2, int a3, int a4, int a5)
{
  char v7; // al
  void *v8; // eax
  int v9; // eax
  void *v10; // esi
  int v11; // eax
  double v12; // st7
  double v13; // st6
  float v14; // edx
  double v15; // st7
  double v16; // st6
  float v17; // edx
  double v18; // st7
  double v19; // st6
  float v20; // edx
  double v21; // st7
  double v22; // st6
  _UNKNOWN **v23; // [esp+1Ch] [ebp-8Ch] BYREF
  void *v24; // [esp+20h] [ebp-88h]
  void *Block[2]; // [esp+28h] [ebp-80h] BYREF
  char v26[4]; // [esp+38h] [ebp-70h] BYREF
  const char *v27; // [esp+3Ch] [ebp-6Ch]
  int v28; // [esp+44h] [ebp-64h]
  float v29; // [esp+48h] [ebp-60h]
  float v30; // [esp+4Ch] [ebp-5Ch]
  float v31; // [esp+50h] [ebp-58h] BYREF
  float v32; // [esp+54h] [ebp-54h]
  float v33; // [esp+58h] [ebp-50h]
  float v34; // [esp+5Ch] [ebp-4Ch]
  float v35; // [esp+60h] [ebp-48h]
  float v36; // [esp+64h] [ebp-44h]
  float v37; // [esp+68h] [ebp-40h]
  float v38; // [esp+6Ch] [ebp-3Ch]
  float v39; // [esp+70h] [ebp-38h]
  float v40; // [esp+74h] [ebp-34h]
  float v41; // [esp+78h] [ebp-30h]
  float v42; // [esp+7Ch] [ebp-2Ch]
  float v43; // [esp+80h] [ebp-28h]
  float v44; // [esp+84h] [ebp-24h]
  unsigned __int8 v45; // [esp+88h] [ebp-20h]
  unsigned __int8 v46; // [esp+89h] [ebp-1Fh]
  int v47; // [esp+90h] [ebp-18h]
  char v48; // [esp+98h] [ebp-10h]
  int v49; // [esp+9Ch] [ebp-Ch]

  if ( a3 )
  {
    (*(void (__thiscall **)(int, float *, int))(*(_DWORD *)a2 + 4))(a2, &v31, 68);
    sub_5BE610((int)Block, a2);
    v49 = 0;
    sub_5BE610((int)v26, a2);
    v7 = this[12];
    LOBYTE(v49) = 1;
    if ( v7 )
    {
      sub_643E40("- Material name = '%s'", (const char *)Block[1]);
      if ( this[12] )
      {
        sub_643E40("    + Shader filename = '%s'", v27);
        if ( this[12] )
        {
          sub_643E40("    + Ambient       : (%f, %f, %f)", v29, v30, v31);
          if ( this[12] )
          {
            sub_643E40("    + Diffuse       : (%f, %f, %f)", v32, v33, v34);
            if ( this[12] )
            {
              sub_643E40("    + Specular      : (%f, %f, %f)", v35, v36, v37);
              if ( this[12] )
              {
                sub_643E40("    + Emissive      : (%f, %f, %f)", v38, v39, v40);
                if ( this[12] )
                {
                  sub_643E40("    + Shine         : %f", v41);
                  if ( this[12] )
                  {
                    sub_643E40("    + Shine strength: %f", v42);
                    if ( this[12] )
                    {
                      sub_643E40("    + Opacity       : %f", v43);
                      if ( this[12] )
                      {
                        sub_643E40("    + IOR           : %f", v44);
                        if ( this[12] )
                        {
                          sub_643E40("    + Double sided  : %d", v45);
                          if ( this[12] )
                            sub_643E40("    + WireFrame     : %d", v46);
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
    }
    v8 = operator new(0x74u);
    v24 = v8;
    LOBYTE(v49) = 2;
    if ( v8 )
      v9 = sub_5D3BE0(v8, Block);
    else
      v9 = 0;
    v48 = 1;
    v23 = &off_7296CC;
    v24 = 0;
    sub_5BD2D0(&v23, v9);
    v10 = v24;
    v48 = 3;
    if ( v24 )
      v11 = (*(int (__thiscall **)(void *))(*(_DWORD *)v24 + 12))(v24);
    else
      v11 = 0;
    v12 = v29;
    v13 = v30;
    *(_DWORD *)(v11 + 32) = v28;
    *(float *)(v11 + 36) = v12;
    *(_DWORD *)(v11 + 44) = 1065353216;
    *(float *)(v11 + 40) = v13;
    v14 = v31;
    v15 = v32;
    v16 = v33;
    *(_DWORD *)(v11 + 60) = 1065353216;
    *(float *)(v11 + 48) = v14;
    *(float *)(v11 + 52) = v15;
    *(float *)(v11 + 56) = v16;
    v17 = v34;
    v18 = v35;
    v19 = v36;
    *(_DWORD *)(v11 + 76) = 1065353216;
    *(float *)(v11 + 64) = v17;
    *(float *)(v11 + 68) = v18;
    *(float *)(v11 + 72) = v19;
    v20 = v37;
    v21 = v38;
    v22 = v39;
    *(_DWORD *)(v11 + 92) = 1065353216;
    *(float *)(v11 + 80) = v20;
    *(float *)(v11 + 84) = v21;
    *(float *)(v11 + 88) = v22;
    *(_BYTE *)(v11 + 112) = LOBYTE(v44);
    *(float *)(v11 + 108) = v43;
    *(float *)(v11 + 104) = v42;
    *(float *)(v11 + 96) = v40;
    *(_BYTE *)(v11 + 113) = BYTE1(v44);
    *(float *)(v11 + 100) = v41;
    sub_5BD510();
    LOBYTE(v47) = 1;
    if ( v10 )
      (*(void (__thiscall **)(void *, _DWORD, _UNKNOWN ***))(*(_DWORD *)v10 + 4))(v10, 0, &v23);
    LOBYTE(v47) = 0;
    sub_5A8840();
    v47 = -1;
    sub_5A8840();
    return 1;
  }
  else
  {
    if ( this[12] )
      sub_643E40("Passed actor seems to be not valid!");
    return 0;
  }
}
