char __thiscall sub_5CA750(_BYTE *this, int a2, int a3, int a4, int a5)
{
  _WORD *v7; // eax
  double v8; // st7
  double v9; // st6
  double v10; // st7
  double v11; // st6
  double v12; // st7
  double v13; // st6
  double v14; // st7
  double v15; // st6
  double v16; // st7
  double v17; // st6
  double v18; // st7
  double v19; // st6
  int v20; // esi
  float v21; // [esp+34h] [ebp-60h] BYREF
  float v22; // [esp+38h] [ebp-5Ch]
  float v23; // [esp+3Ch] [ebp-58h]
  float v24; // [esp+40h] [ebp-54h]
  float v25; // [esp+44h] [ebp-50h]
  float v26; // [esp+48h] [ebp-4Ch]
  float v27; // [esp+4Ch] [ebp-48h]
  float v28; // [esp+50h] [ebp-44h]
  float v29; // [esp+54h] [ebp-40h]
  float v30; // [esp+58h] [ebp-3Ch]
  float v31; // [esp+5Ch] [ebp-38h]
  float v32; // [esp+60h] [ebp-34h]
  float v33; // [esp+64h] [ebp-30h]
  float v34; // [esp+68h] [ebp-2Ch]
  float v35; // [esp+6Ch] [ebp-28h]
  float v36; // [esp+70h] [ebp-24h]
  float v37; // [esp+74h] [ebp-20h]
  float v38; // [esp+78h] [ebp-1Ch]
  float v39; // [esp+7Ch] [ebp-18h]
  unsigned __int8 v40; // [esp+80h] [ebp-14h]
  unsigned __int8 v41; // [esp+81h] [ebp-13h]
  unsigned __int8 v42; // [esp+82h] [ebp-12h]
  unsigned __int8 v43; // [esp+83h] [ebp-11h]
  unsigned __int8 v44; // [esp+84h] [ebp-10h]
  unsigned __int8 v45; // [esp+85h] [ebp-Fh]
  unsigned __int8 v46; // [esp+86h] [ebp-Eh]
  unsigned __int8 v47; // [esp+87h] [ebp-Dh]
  unsigned __int8 v48; // [esp+88h] [ebp-Ch]
  int v49; // [esp+90h] [ebp-4h]

  v49 = dword_912B08;
  if ( a3 )
  {
    (*(void (__thiscall **)(int, float *, int))(*(_DWORD *)a2 + 4))(a2, &v21, 88);
    v7 = operator new(0x50u);
    if ( v7 )
    {
      *(_DWORD *)v7 = &off_72A210;
      v7[38] = 0;
      *((_DWORD *)v7 + 4) = 0;
      *((_DWORD *)v7 + 5) = 0;
      *((_DWORD *)v7 + 6) = 0;
      *((_DWORD *)v7 + 10) = 0;
      *((_DWORD *)v7 + 11) = 0;
      *((_DWORD *)v7 + 12) = 0;
      *((_DWORD *)v7 + 16) = 1065353216;
      *((_DWORD *)v7 + 17) = 1065353216;
      *((_DWORD *)v7 + 18) = 1065353216;
    }
    else
    {
      v7 = 0;
    }
    v8 = v23;
    v9 = v24;
    *((float *)v7 + 1) = v22;
    *((float *)v7 + 2) = v8;
    *((float *)v7 + 3) = v9;
    v10 = v26;
    v11 = v27;
    *((float *)v7 + 4) = v25;
    *((float *)v7 + 5) = v10;
    *((float *)v7 + 6) = v11;
    v12 = v29;
    v13 = v30;
    *((float *)v7 + 7) = v28;
    *((float *)v7 + 8) = v12;
    *((float *)v7 + 9) = v13;
    v14 = v32;
    v15 = v33;
    *((float *)v7 + 10) = v31;
    *((float *)v7 + 11) = v14;
    *((float *)v7 + 12) = v15;
    v16 = v35;
    v17 = v36;
    *((float *)v7 + 13) = v34;
    *((float *)v7 + 14) = v16;
    *((float *)v7 + 15) = v17;
    v18 = v38;
    v19 = v39;
    *((float *)v7 + 16) = v37;
    *((float *)v7 + 17) = v18;
    *((float *)v7 + 18) = v19;
    if ( v40 )
      *((_BYTE *)v7 + 76) |= 1u;
    else
      v7[38] ^= 1u;
    if ( v41 )
      *((_BYTE *)v7 + 76) |= 2u;
    else
      v7[38] ^= 2u;
    if ( v42 )
      *((_BYTE *)v7 + 76) |= 4u;
    else
      v7[38] ^= 4u;
    if ( v43 )
      *((_BYTE *)v7 + 76) |= 8u;
    else
      v7[38] ^= 8u;
    if ( v44 )
      *((_BYTE *)v7 + 76) |= 0x10u;
    else
      v7[38] ^= 0x10u;
    if ( v45 )
      *((_BYTE *)v7 + 76) |= 0x20u;
    else
      v7[38] ^= 0x20u;
    if ( v46 )
      *((_BYTE *)v7 + 76) |= 0x40u;
    else
      v7[38] ^= 0x40u;
    if ( v47 )
      *((_BYTE *)v7 + 76) |= 0x80u;
    else
      v7[38] ^= 0x80u;
    if ( v48 )
      *((_BYTE *)v7 + 77) |= 1u;
    else
      v7[38] ^= 0x100u;
    v20 = *(_DWORD *)(*(_DWORD *)(a3 + 452) + 4 * LODWORD(v21));
    sub_5C0710();
    if ( this[12] )
    {
      sub_643E40("- Limits for node '%s'", *(const char **)(v20 + 376));
      if ( this[12] )
      {
        sub_643E40("    + TranslateMin = %.3f, %.3f, %.3f", v22, v23, v24);
        if ( this[12] )
        {
          sub_643E40("    + TranslateMax = %.3f, %.3f, %.3f", v25, v26, v27);
          if ( this[12] )
          {
            sub_643E40("    + RotateMin    = %.3f, %.3f, %.3f", v28, v29, v30);
            if ( this[12] )
            {
              sub_643E40("    + RotateMax    = %.3f, %.3f, %.3f", v31, v32, v33);
              if ( this[12] )
              {
                sub_643E40("    + ScaleMin     = %.3f, %.3f, %.3f", v34, v35, v36);
                if ( this[12] )
                {
                  sub_643E40("    + ScaleMax     = %.3f, %.3f, %.3f", v37, v38, v39);
                  if ( this[12] )
                    sub_643E40(
                      "    + LimitFlags   = POS[%d, %d, %d], ROT[%d, %d, %d], SCALE[%d, %d, %d]",
                      v40,
                      v41,
                      v42,
                      v43,
                      v44,
                      v45,
                      v46,
                      v47,
                      v48);
                }
              }
            }
          }
        }
      }
    }
    return 1;
  }
  else
  {
    if ( this[12] )
      sub_643E40("Passed actor seems to be not valid!");
    return 0;
  }
}
