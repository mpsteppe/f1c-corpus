void __usercall sub_411260(int a1@<ecx>, int a2@<ebp>, int a3@<esi>)
{
  int v4; // esi
  int v5; // ebp
  int v6; // ebx
  char v7; // dl
  float v8; // eax
  int v9; // esi
  int v10; // eax
  int v11; // edx
  int v12; // ecx
  double v13; // st7
  int v14; // esi
  int v15; // edx
  _DWORD v16[3]; // [esp+24h] [ebp-94h] BYREF
  float v17; // [esp+30h] [ebp-88h]
  float v18; // [esp+34h] [ebp-84h]
  int v19; // [esp+3Ch] [ebp-7Ch] BYREF
  float v20; // [esp+40h] [ebp-78h]
  float v21; // [esp+44h] [ebp-74h]
  int v22; // [esp+54h] [ebp-64h] BYREF
  int v23; // [esp+58h] [ebp-60h] BYREF
  int v24; // [esp+5Ch] [ebp-5Ch] BYREF
  int v25; // [esp+60h] [ebp-58h] BYREF
  int v26; // [esp+64h] [ebp-54h] BYREF
  _DWORD v27[20]; // [esp+68h] [ebp-50h] BYREF

  v18 = *(float *)(a1 + 4);
  if ( LODWORD(v18) )
  {
    sub_5E5B70(4096);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)a1 + 20))(a1, a3);
    v25 = 0;
    v26 = 0;
    v27[0] = 0;
    v22 = 0;
    v23 = 0;
    v24 = 0;
    HIBYTE(v17) = 0;
    if ( !byte_B6F118 )
    {
      if ( dword_B6BBC4 )
      {
        sub_561700(&unk_FAE918);
      }
      else if ( *(_DWORD *)(a1 + 52) == 1 && !*(_DWORD *)(a1 + 64) )
      {
        HIBYTE(v17) = sub_561720(&v25, &v26, v27, &v22, &v23, &v24);
      }
    }
    switch ( *(_DWORD *)(a1 + 52) )
    {
      case 0:
      case 2:
        sub_5690F0(dword_91E07C + 2704, &v19, v16, a2);
        sub_562DD0(1);
        goto LABEL_23;
      case 1:
        sub_56ED00(&v19, v16, &v22);
        if ( byte_B71B1C )
          sub_562DD0(1);
        goto LABEL_23;
      case 3:
        sub_5690F0(dword_91E07C + 2704, &v19, v16, a2);
        v4 = *(_DWORD *)(a1 + 28);
        sub_562DD0(1);
        v5 = *(_DWORD *)(v4 + 168);
        v20 = *(float *)(v4 + 164);
        v6 = *(_DWORD *)(v4 + 172);
        v17 = *(float *)(v4 + 176);
        v7 = 0;
        if ( v20 >= -2.95 )
        {
          if ( v20 <= -0.050000001 )
            goto LABEL_17;
          v20 = -0.050000001;
        }
        else
        {
          v20 = -2.95;
        }
        v7 = 1;
LABEL_17:
        if ( v17 >= 3.5 )
        {
          if ( v17 <= 10.0 )
          {
            if ( !v7 )
            {
LABEL_23:
              off_16C954C();
              return;
            }
          }
          else
          {
            v17 = 10.0;
          }
        }
        else
        {
          v17 = 3.5;
        }
        v8 = v17;
        *(float *)(v4 + 164) = v20;
        *(_DWORD *)(v4 + 168) = v5;
        *(_DWORD *)(v4 + 172) = v6;
        sub_46B750(LODWORD(v8));
        (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 28))(v4);
        goto LABEL_23;
      case 4:
      case 5:
      case 6:
        sub_5690F0(dword_91E07C + 2704, &v19, v16, a2);
        goto LABEL_23;
      case 7:
        sub_5690F0(dword_91E07C + 2704, &v19, v16, a2);
        v9 = *(_DWORD *)(a1 + 44);
        if ( dword_757714 )
        {
          if ( dword_757714 == 1 )
          {
            v10 = v9 + 192;
            v11 = v9 + 192;
            v12 = *(_DWORD *)(v9 + 192);
            v21 = *(float *)(v9 + 196);
            v13 = flt_757710 + v21;
            goto LABEL_33;
          }
        }
        else
        {
          dword_757714 = 1;
        }
        goto LABEL_23;
      case 8:
        sub_5690F0(dword_91E07C + 2704, &v19, v16, a2);
        v14 = *(_DWORD *)(a1 + 48);
        if ( dword_757714 )
        {
          if ( dword_757714 == 1 )
          {
            v10 = v14 + 192;
            v11 = v14 + 192;
            v12 = *(_DWORD *)(v14 + 192);
            v21 = *(float *)(v14 + 196);
            v13 = v21 - flt_757710;
LABEL_33:
            v15 = *(_DWORD *)(v11 + 8);
            v21 = v13;
            *(_DWORD *)v10 = v12;
            *(float *)(v10 + 4) = v21;
            *(_DWORD *)(v10 + 8) = v15;
            dword_757714 = 2;
          }
        }
        else
        {
          dword_757714 = 1;
        }
        goto LABEL_23;
      default:
        v19 = 0;
        v20 = 0.0;
        v21 = 0.0;
        memset(v16, 0, sizeof(v16));
        goto LABEL_23;
    }
  }
}
