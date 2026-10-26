void __thiscall sub_4F3910(_BYTE *this, int a2)
{
  int v3; // edi
  bool v4; // bl
  _DWORD *v5; // esi
  _DWORD *v6; // esi
  _DWORD *v7; // esi
  int v8; // ecx
  int v9; // eax
  bool v10; // zf
  int v11; // esi
  int v12; // esi
  int v13; // eax
  float *v14; // eax
  int v15; // ecx
  _DWORD *v16; // eax
  int v17; // edx
  int v18; // ecx
  int v19; // edx
  int v20; // eax
  int v21; // ecx
  int v22; // eax
  int v23; // eax
  int v24; // edx
  int v25; // eax
  int v26; // ecx
  double *v27; // eax
  int v28; // [esp-18h] [ebp-B0h]
  float v29; // [esp+0h] [ebp-98h]
  char v30; // [esp+Bh] [ebp-8Dh]
  int v31; // [esp+Ch] [ebp-8Ch]
  float v32; // [esp+14h] [ebp-84h]
  float v33; // [esp+18h] [ebp-80h]
  float v34; // [esp+1Ch] [ebp-7Ch]
  int v35; // [esp+20h] [ebp-78h] BYREF
  int v36; // [esp+24h] [ebp-74h]
  int v37; // [esp+28h] [ebp-70h]
  int v38; // [esp+2Ch] [ebp-6Ch]
  _DWORD v39[2]; // [esp+30h] [ebp-68h] BYREF
  int v40; // [esp+38h] [ebp-60h] BYREF
  int v41; // [esp+3Ch] [ebp-5Ch] BYREF
  float v42[22]; // [esp+40h] [ebp-58h] BYREF

  v3 = (*(_DWORD *)a2 >> 5) & 0x3F;
  HIBYTE(v32) = *(int *)a2 < 0;
  v34 = *(float *)(a2 + 12);
  v4 = ((*(_DWORD *)a2 >> 30) & 1) == 0;
  v33 = *(float *)&v3;
  sub_51B230(&v35, &v41);
  this[8] = v4;
  if ( v4 )
  {
    v5 = (_DWORD *)*((_DWORD *)this + 54);
    if ( v5 )
    {
      v29 = 0.0;
      (*(void (__thiscall **)(_DWORD *))(*v5 + 20))(v5);
      v5[5] = 0;
      *((_DWORD *)this + 48) = 0;
    }
    v6 = (_DWORD *)*((_DWORD *)this + 55);
    if ( v6 )
    {
      (*(void (__thiscall **)(_DWORD *, _DWORD))(*v6 + 20))(v6, 0);
      v6[5] = 0;
      *((_DWORD *)this + 49) = 0;
    }
    v7 = (_DWORD *)*((_DWORD *)this + 56);
    if ( v7 )
    {
      (*(void (__thiscall **)(_DWORD *, _DWORD))(*v7 + 20))(v7, 0);
      v7[5] = 0;
      *((_DWORD *)this + 50) = 0;
    }
    v8 = *((_DWORD *)this + 34);
    if ( v8 )
    {
      if ( v30 )
        sub_5DB590(v8);
      else
        sub_5DB5A0();
    }
    v35 = v39[1];
    v38 = v39[0];
    v9 = *(_DWORD *)this;
    v10 = *(_DWORD *)this == 7;
    v36 = v40;
    v37 = v41;
    if ( (v10 || v9 == 8) && (v11 = **((_DWORD **)this + 58)) != 0 )
    {
      sub_4F2340((float *)&v35, v42);
      LODWORD(v42[13]) = v3;
      v42[12] = v32;
      v42[14] = v34;
      qmemcpy((void *)(v11 + 4), v42, 0x40u);
      v3 = v31;
    }
    else
    {
      v12 = *((_DWORD *)this + 34);
      if ( v12 )
      {
        sub_4F2340((float *)&v35, v42);
        v42[12] = v32;
        v42[14] = v34;
        LODWORD(v42[13]) = v3;
        qmemcpy((void *)(v12 + 76), v42, 0x40u);
        v3 = v31;
        **((_DWORD **)this + 34) |= 0x40u;
      }
      v13 = *((_DWORD *)this + 35);
      if ( v13 )
      {
        v14 = *(float **)(v13 + 8);
        v14[57] = v32;
        v15 = v35;
        v14[58] = v33;
        v14[59] = v34;
        v16 = *(_DWORD **)(*((_DWORD *)this + 35) + 8);
        v17 = v36;
        v16[53] = v15;
        v18 = v37;
        v16[54] = v17;
        v19 = v38;
        v16[55] = v18;
        v16[56] = v19;
      }
    }
    v20 = *((_DWORD *)this + 35);
    if ( v20
      && (*(unsigned __int8 (__thiscall **)(_DWORD))(**(_DWORD **)(*(_DWORD *)(v20 + 8) + 532) + 12))(*(_DWORD *)(*(_DWORD *)(v20 + 8) + 532)) )
    {
      do
      {
        v21 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 35) + 8) + 532);
        v22 = (*(int (__thiscall **)(int))(*(_DWORD *)v21 + 28))(v21);
      }
      while ( !v22 );
      sub_5BC080(*(_DWORD *)(*((_DWORD *)this + 35) + 8), v22, 0);
    }
    if ( *(float *)&v3 != 0.0 )
    {
      sub_5BFC10(&v40);
      v23 = *((_DWORD *)this + 39);
      *((_DWORD *)this + 41) = v3 - 1;
      v24 = *((_DWORD *)this + 35);
      v25 = 120 * v3 + v23;
      v42[0] = 1.0;
      v40 = 0;
      v41 = 0;
      v42[2] = NAN;
      BYTE2(v42[6]) = 0;
      *((_DWORD *)this + 40) = v25 - 120;
      v26 = *(_DWORD *)(v24 + 8);
      v28 = *(_DWORD *)(v25 - 8);
      v42[16] = 0.0;
      v27 = (double *)sub_5BBFE0(v26, v28, &v40);
      *((_DWORD *)this + 42) = v27;
      if ( v27 )
        *v27 = v29;
      v42[14] = NAN;
      nullsub_7(v39);
    }
  }
}
