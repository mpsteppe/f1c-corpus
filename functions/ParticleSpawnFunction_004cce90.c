void __thiscall sub_4CCE90(float *this, float *a2, int a3, float *a4, int a5, int a6)
{
  double v7; // st7
  double v8; // st7
  double v9; // st7
  float *v10; // eax
  int v11; // ebp
  float *v12; // eax
  double v13; // st7
  double v14; // st7
  double v15; // st6
  double v16; // st7
  double v17; // st7
  double v18; // st7
  double v19; // st7
  double v20; // st7
  double v21; // st7
  double v22; // st6
  float v23; // [esp+10h] [ebp-98h]
  float v24; // [esp+10h] [ebp-98h]
  float v25; // [esp+14h] [ebp-94h]
  float v26; // [esp+14h] [ebp-94h]
  float v27; // [esp+18h] [ebp-90h]
  float v28; // [esp+18h] [ebp-90h]
  float v29; // [esp+1Ch] [ebp-8Ch]
  float v30; // [esp+20h] [ebp-88h]
  float v31; // [esp+24h] [ebp-84h]
  float v32; // [esp+28h] [ebp-80h] BYREF
  float v33; // [esp+2Ch] [ebp-7Ch]
  float v34; // [esp+30h] [ebp-78h]
  float v35; // [esp+34h] [ebp-74h]
  float v36; // [esp+38h] [ebp-70h]
  float v37; // [esp+3Ch] [ebp-6Ch]
  float v38; // [esp+40h] [ebp-68h]
  float v39; // [esp+44h] [ebp-64h]
  float v40; // [esp+48h] [ebp-60h]
  float v41; // [esp+4Ch] [ebp-5Ch]
  float v42[4]; // [esp+50h] [ebp-58h] BYREF
  float v43; // [esp+60h] [ebp-48h]
  float v44; // [esp+64h] [ebp-44h]
  double v45[3]; // [esp+68h] [ebp-40h] BYREF
  int v46; // [esp+80h] [ebp-28h]
  int v47; // [esp+84h] [ebp-24h]
  int v48; // [esp+88h] [ebp-20h]
  int v49; // [esp+8Ch] [ebp-1Ch]
  double v50; // [esp+90h] [ebp-18h]
  int v51; // [esp+98h] [ebp-10h]
  float v52; // [esp+A4h] [ebp-4h]

  if ( *((int *)this + 22) > 0 )
  {
    v7 = (double)a5;
    v30 = 0.0078125 * v7;
    v29 = v7 * 0.015625;
    v23 = *a4 * 0.5;
    v25 = a4[1] * 0.5;
    v27 = a4[2] * 0.5;
    if ( dword_8AB6E4 == 2 )
    {
      if ( VehicleDataAccessor(&dword_8AB6EC) == 5 )
        v8 = 0.0;
      else
        v8 = FloatDifference(&dword_8AB6EC);
    }
    else
    {
      v8 = dbl_8AFE98;
    }
    v36 = v23 * v8;
    v46 = 0;
    v47 = 1070596096;
    v37 = v25 * v8;
    v48 = 0x40000000;
    v49 = 1201543096;
    v51 = a6;
    v38 = v27 * v8;
    v45[0] = *a2;
    v45[1] = a2[1];
    v9 = a2[2];
    v45[2] = v9;
    if ( CollisionNormalFromFeature(dbl_7C9360, v45, &v32) )
    {
      v9 = v50 * v33 + v32 * *a2 + v34 * a2[2];
      v35 = v9;
    }
    else
    {
      v32 = 0.0;
      v33 = 1.0;
      v34 = 0.0;
      v35 = -3.4028235e38;
    }
    v10 = (float *)(VirtualDispatchHelper(&dword_5EA510) + 36);
    v28 = v10[2];
    v24 = *v10;
    v26 = v10[1];
    if ( dword_8AB6E4 == 2 )
      Delegation(&dword_8AB6EC);
    else
      v9 = dbl_8AFEA0;
    v11 = a3 >> *((_DWORD *)this + 2);
    v31 = v9;
    if ( v11 > 0 )
    {
      do
      {
        v12 = (float *)CircularBufferSlotAlloc(this);
        v13 = v31 + v12[4];
        v12[2] = v31;
        v12[3] = v13;
        v14 = flt_8AB274[(unsigned __int8)dword_8AAE70++];
        v43 = v14 * v37;
        v44 = v14 * v38;
        v15 = flt_8AB274[(unsigned __int8)dword_8AAE70++];
        v12[11] = v15 * v30 + *a2 + v36 * v14;
        v16 = flt_8AB274[(unsigned __int8)dword_8AAE70++];
        v12[12] = v16 * v30 + a2[1] + v43;
        v17 = flt_8AB274[(unsigned __int8)dword_8AAE70++];
        v12[13] = v17 * v30 + a2[2] + v44;
        v18 = flt_8AB274[(unsigned __int8)dword_8AAE70++];
        v12[14] = v18 * v29 + *a4;
        v19 = flt_8AB274[(unsigned __int8)dword_8AAE70++] * v29;
        v12[15] = v19 + a4[1];
        v20 = flt_8AB274[(unsigned __int8)dword_8AAE70++];
        v12[16] = v20 * v29 + a4[2];
        v12[21] = v32;
        v12[22] = v33;
        v12[23] = v34;
        v12[25] = v35;
        v21 = v12[14] - v24;
        v22 = v12[15] - v26;
        v52 = v12[16] - v28;
        v39 = v21 * 0.03125;
        v42[0] = v39;
        v40 = v22 * 0.03125;
        v42[1] = v40;
        v41 = v52 * 0.03125;
        v42[2] = v41;
        ParticleEffectBillboardQuadSetup(this, v12, v42);
        --v11;
      }
      while ( v11 );
    }
  }
}
