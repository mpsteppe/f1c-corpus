void __thiscall sub_583360(int this, float a2)
{
  char v3; // al
  double v4; // st7
  double v5; // st7
  double v6; // st6
  double v7; // st7
  float *v8; // esi
  double v9; // st7
  int v10; // edi
  int v11; // edi
  float *v12; // esi
  float *v13; // eax
  float v14; // edx
  float v15; // ecx
  float v16; // eax
  float *v17; // eax
  float v18; // edx
  int v19; // esi
  int *v20; // ecx
  char v21; // al
  double v22; // st7
  unsigned __int8 v24; // c0
  unsigned __int8 v25; // c2
  int v26; // [esp+14h] [ebp-520h]
  char v27; // [esp+1Bh] [ebp-519h]
  _DWORD *v28; // [esp+1Ch] [ebp-518h]
  long double v29; // [esp+28h] [ebp-50Ch]
  float v30; // [esp+2Ch] [ebp-508h]
  float v31; // [esp+4Ch] [ebp-4E8h]
  float v32; // [esp+4Ch] [ebp-4E8h]
  float v33; // [esp+50h] [ebp-4E4h]
  float v34; // [esp+50h] [ebp-4E4h]
  float v35; // [esp+54h] [ebp-4E0h]
  float v36; // [esp+54h] [ebp-4E0h]
  float v37; // [esp+5Ch] [ebp-4D8h] BYREF
  float v38; // [esp+60h] [ebp-4D4h]
  float v39; // [esp+64h] [ebp-4D0h]
  int v40; // [esp+70h] [ebp-4C4h] BYREF
  float v41; // [esp+74h] [ebp-4C0h] BYREF
  float v42; // [esp+78h] [ebp-4BCh]
  float v43; // [esp+7Ch] [ebp-4B8h]
  _DWORD v44[3]; // [esp+8Ch] [ebp-4A8h] BYREF
  int v45; // [esp+98h] [ebp-49Ch] BYREF
  _BYTE v46[4]; // [esp+A0h] [ebp-494h] BYREF
  float v47[9]; // [esp+A4h] [ebp-490h] BYREF
  float v48[8]; // [esp+1ACh] [ebp-388h] BYREF
  int v49[2]; // [esp+1CCh] [ebp-368h] BYREF
  int v50; // [esp+1D4h] [ebp-360h] BYREF
  int v51[214]; // [esp+1DCh] [ebp-358h] BYREF
  float v52; // [esp+53Ch] [ebp+8h]

  v30 = dbl_FB1D10;
  sub_4FB790();
  switch ( *(_DWORD *)(this + 14804) )
  {
    case 0:
      v52 = a2 - *(float *)(this + 15932);
      v13 = sub_4012D0((float *)(this + 15996), v48, v52);
      v14 = v13[1];
      v15 = *v13;
      v16 = v13[2];
      v38 = v14;
      v37 = v15;
      v39 = v16;
      v17 = sub_401250((float *)(this + 15972), &v37, (float *)v49);
      v41 = *v17;
      v42 = v17[1];
      v43 = v17[2];
      off_16C94E4(LODWORD(v52));
      return;
    case 1:
      v3 = sub_5785A0(this);
      v4 = *(float *)(this + 16140);
      *(_BYTE *)(this + 5760) = v3;
      *(_BYTE *)(this + 5745) = v4 > 0.0099999998;
      *(_BYTE *)(this + 5747) = *(_DWORD *)(this + 17304) == -1;
      goto LABEL_3;
    case 2:
LABEL_3:
      v5 = a2 - *(float *)(this + 15932);
      v31 = v5 * *(float *)(this + 15996);
      v37 = v31;
      v33 = v5 * *(float *)(this + 16000);
      v38 = v33;
      v35 = v5 * *(float *)(this + 16004);
      v39 = v35;
      v32 = v31 + *(float *)(this + 15972);
      v41 = v32;
      v34 = v33 + *(float *)(this + 15976);
      v42 = v34;
      v36 = v35 + *(float *)(this + 15980);
      v43 = v36;
      v6 = v5 * *(float *)(this + 16020);
      qmemcpy(v47, (const void *)(this + 15936), sizeof(v47));
      v37 = v6;
      v38 = v5 * *(float *)(this + 16024);
      v7 = v5 * *(float *)(this + 16028);
      *(float *)v44 = v37;
      v39 = v7;
      *(float *)&v44[2] = v39;
      *(float *)&v44[1] = v38;
      sub_614F40(v44);
      sub_40D5D0(v47, (int)&v45);
      sub_569300((_DWORD *)(this + 2688), &v41, &v45, v47);
      sub_56B6A0((float *)(this + 2688), *(float *)(this + 16136));
      sub_569170((void *)(this + 2688));
      sub_53E380(
        (_DWORD *)(this + 8),
        &v40,
        v46,
        (_DWORD *)(this + 15996),
        *(_DWORD *)(this + 17212),
        *(_DWORD *)(this + 16132));
      if ( *(_BYTE *)(this + 19224) )
        sub_58C630(57);
      if ( *(float *)(this + 19228) != 0.0 )
      {
        v26 = 1065353216;
        sub_58C630(58);
      }
      if ( *(_DWORD *)(this + 14804) == 2 )
      {
        v8 = (float *)(this + 16184);
        v9 = *(float *)(this + 17156) * *(float *)(this + 16136);
        v10 = 4;
        *(float *)(this + 16188) = v9;
        *(float *)(this + 16440) = v9;
        do
        {
          *v8 = dbl_FB1D10 * v8[3] + *v8;
          v29 = *v8;
          if ( fabs(v29) > 50.265484 )
            *v8 = fmod(v29, 6.283185482025146);
          v8 += 63;
          --v10;
        }
        while ( v10 );
      }
      v11 = 0;
      v28 = (_DWORD *)(this + 3216);
      v12 = (float *)(this + 16184);
      do
      {
        if ( *(_BYTE *)v28 )
        {
          sub_5693D0((float *)(this + 2688), v11, *(v12 - 5), *v12, v12[1]);
          sub_5691C0(v11);
          *v28 = *((_DWORD *)v12 - 6);
          v28[1] = *((_DWORD *)v12 - 5);
          v28[2] = *((_DWORD *)v12 - 4);
        }
        ++v11;
        v12 += 63;
        v26 += 296;
        v28 += 3;
      }
      while ( v11 < 4 );
      v18 = *((float *)&dword_91E088 + dword_91E078);
      LOBYTE(v18) = *(_DWORD *)(LODWORD(v18) + 22468) == *(_DWORD *)(*(_DWORD *)this + 22468);
      sub_57EB40((float *)this, v18);
      goto LABEL_33;
    case 3:
    case 4:
      v19 = sub_615460(512);
      if ( *(_DWORD *)(this + 14804) == 4 )
      {
        if ( *(_DWORD *)dword_B72314 == 8 )
        {
          if ( ((_BYTE)dword_757C1C != 0 ? dword_91E084 : 0) == *(_DWORD *)this )
          {
            sub_5210A0(&dword_91E044);
            sub_5210B0(&dword_91E044);
            sub_5210A0(&dword_91E044);
            sub_527D50();
            sub_5237B0(&dword_91E044, 1, (int)&v50, -9.9999997e37);
            sub_527D50();
            goto LABEL_26;
          }
          sub_5237B0(&dword_91E044, *(_DWORD *)(this + 4), (int)v51, -9.9999997e37);
          v20 = (int *)&dword_91E044;
        }
        else
        {
          sub_5237B0((char **)&dword_BE1228, *(_DWORD *)(this + 4), (int)v51, -9.9999997e37);
          v20 = &dword_BE1228;
        }
      }
      else
      {
        sub_5237B0((char **)&dword_BE120C, *(_DWORD *)(this + 4), (int)v51, -9.9999997e37);
        v20 = &dword_BE120C;
      }
      sub_5210A0(v20);
LABEL_26:
      if ( HIBYTE(v30) )
      {
        sub_53F8A0((int)&unk_9204A0 + 22616 * *(_DWORD *)(this + 4), (int)v49, a2);
        if ( *(_BYTE *)(this + 19224) )
        {
          v27 = 63;
          sub_58C630(57);
        }
        if ( *(float *)(this + 19228) != 0.0 )
          sub_58C630(58);
      }
      if ( v19 != 512 )
        sub_6154A0(v19);
LABEL_33:
      sub_578360();
      if ( !v27 )
        return;
      sub_56E190(this + 2688);
      v21 = *(_BYTE *)(this + 19232) + 1;
      ++*(_DWORD *)(this + 19232);
      if ( (v21 & 0xF) != 0 )
        return;
      sub_57DF00((int *)this);
      if ( *(_DWORD *)(this + 14804) != 1 )
        goto LABEL_44;
      if ( sub_577A80((float *)this) )
        goto LABEL_43;
      v22 = sub_552900((int)dword_FADD40);
      if ( 0.44999999 - *(float *)(this + 5668) * 0.89999998 <= flt_FB1F04 )
      {
        if ( v22 <= 68400.0 )
        {
          if ( v22 >= 18000.0 )
LABEL_43:
            *(_BYTE *)(this + 5749) = 0;
          else
            *(_BYTE *)(this + 5749) = 1;
        }
        else
        {
          *(_BYTE *)(this + 5749) = 1;
        }
      }
      else
      {
        *(_BYTE *)(this + 5749) = 1;
      }
LABEL_44:
      if ( *(_DWORD *)(this + 14804) == 2
        && *(_DWORD *)dword_B640C8 != 6
        && v24 | v25
        && *(_DWORD *)(*(_DWORD *)this + 19428)
        && sub_577A80((float *)this) )
      {
        *(_DWORD *)(*(_DWORD *)this + 19428) = 0;
      }
      return;
    default:
      goto LABEL_33;
  }
}
