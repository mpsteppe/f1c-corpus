char __thiscall sub_547DC0(char *this, char a2, char a3)
{
  double v3; // st7
  int v4; // eax
  _DWORD *v6; // ebp
  int v7; // edi
  _DWORD *v8; // eax
  double v9; // st7
  int v10; // edi
  double v11; // st7
  int v12; // ecx
  int v13; // ebp
  int v14; // esi
  float *v15; // esi
  double v16; // st7
  double v17; // st7
  int v18; // edx
  float *v19; // ecx
  double v20; // st7
  double v21; // st6
  int v22; // edx
  int v23; // edx
  long double v24; // st6
  long double v25; // st6
  double v26; // st7
  _DWORD *v28; // [esp+8h] [ebp-114h]
  float v29; // [esp+8h] [ebp-114h]
  float v30; // [esp+8h] [ebp-114h]
  float v31; // [esp+Ch] [ebp-110h]
  char ArgList[256]; // [esp+10h] [ebp-10Ch] BYREF
  int v33; // [esp+118h] [ebp-4h]

  flt_903994 = flt_B7138C * flt_B7138C;
  v3 = flt_B7138C + *(float *)&dword_B713B0;
  dword_903990 = dword_B713B0;
  LOBYTE(v4) = a2;
  flt_903998 = v3;
  flt_90399C = v3 * 1.4142135;
  if ( a2 )
  {
    if ( *((_DWORD *)this + 1) == 15 )
    {
      v6 = 0;
      *((_DWORD *)this + 2) = 0;
    }
    else
    {
      LOBYTE(v4) = dword_B7129C;
      *((_DWORD *)this + 2) = 4 - dword_B7129C;
      v6 = 0;
    }
    if ( dword_B7129C )
    {
      v4 = *((int *)this + 24) >> *((_DWORD *)this + 2);
      *((_DWORD *)this + 24) = v4;
    }
    else
    {
      *((_DWORD *)this + 24) = 0;
      *((_DWORD *)this + 27) = 0;
    }
  }
  else
  {
    v6 = 0;
  }
  if ( *((int *)this + 24) > 0 )
  {
    sprintf((char *const)(*((_DWORD *)this + 22) + 4), "Reaction%02d", *(_DWORD *)this);
    *(_DWORD *)(*((_DWORD *)this + 22) + 36) = *((_DWORD *)this + 24);
    *(_DWORD *)(*((_DWORD *)this + 22) + 40) = *((_DWORD *)this + 3);
    *(_DWORD *)(*((_DWORD *)this + 22) + 44) = *((_DWORD *)this + 4);
    *(_DWORD *)(*((_DWORD *)this + 22) + 48) = *((_DWORD *)this + 5);
    v28 = this + 92;
    if ( sub_5FDC80(dword_FB1D04, (int)(this + 92), *((_DWORD *)this + 22), a3) )
    {
      sub_5D8CB0(0, ArgList);
      if ( (unsigned __int8)sub_5612D0((int)byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\specialfx.cpp", 933) )
        sub_561210(
          (int)byte_FAE910,
          "Could not create %d-particle system using MTS:%s or BMP:%s with flags 0x%08x",
          *(_DWORD *)(*((_DWORD *)this + 22) + 36));
      LOBYTE(v4) = sub_5612D0((int)byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\specialfx.cpp", 936);
      if ( (_BYTE)v4 )
        LOBYTE(v4) = sub_561210((int)byte_FAE910, "CUBE Error: %s", (char)ArgList);
    }
    else
    {
      v7 = *((_DWORD *)this + 24);
      v8 = operator new(108 * v7 + 4);
      v33 = 0;
      if ( v8 )
      {
        v6 = v8 + 1;
        *v8 = v7;
        sub_630A11(v8 + 1, 108, v7, sub_542460, nullsub_7);
      }
      v9 = *((float *)this + 12);
      v10 = 0;
      v33 = -1;
      *((_DWORD *)this + 25) = v6;
      *((_DWORD *)this + 26) = 0;
      if ( v9 <= 0.0 )
        v11 = 0.0;
      else
        v11 = 1.0 / *((float *)this + 12);
      v12 = *((_DWORD *)this + 24);
      *((float *)this + 18) = v11;
      *((_DWORD *)this + 27) = 0;
      *((_DWORD *)this + 28) = operator new(4 * v12);
      v4 = *((_DWORD *)this + 24);
      if ( v4 > 0 )
      {
        v13 = 0;
        do
        {
          *(_DWORD *)(*((_DWORD *)this + 25) + v13) = v10;
          *(_DWORD *)(*((_DWORD *)this + 25) + v13 + 4) = -1;
          sub_543400(
            v13 + *((_DWORD *)this + 25),
            *((float *)this + 12),
            *((float *)this + 13),
            *((float *)this + 14),
            *((float *)this + 15),
            *((float *)this + 16),
            *((float *)this + 17));
          *(_DWORD *)(*((_DWORD *)this + 28) + 4 * v10) = 0;
          v4 = *((_DWORD *)this + 24);
          ++v10;
          v13 += 108;
        }
        while ( v10 < v4 );
      }
      v14 = *((_DWORD *)this + 1);
      if ( v14 == 15 )
      {
        dword_BE2720 = 0;
        v15 = flt_BE1FDC;
        do
        {
          do
          {
            v16 = flt_BE0CA4[(unsigned __int8)dword_BE08A0++] * 20.0;
            v29 = v16;
            v17 = ((double)(sub_51C780() & 0x1FFFF) * 0.000015258789 - 1.0) * 20.0;
          }
          while ( v17 * v17 + v29 * v29 >= 400.0 );
          *v15 = v17;
          *(v15 - 1) = v29;
          v15 += 2;
        }
        while ( (int)v15 < (int)flt_BE23DC );
        v18 = dword_BE08A0;
        v19 = (float *)&unk_BE1D60;
        do
        {
          v20 = flt_BE0CA4[(unsigned __int8)v18];
          dword_BE08A0 = v18 + 1;
          v21 = flt_BE0CA4[(unsigned __int8)(v18 + 1)];
          v22 = v18 + 2;
          v30 = v21;
          dword_BE08A0 = v22;
          v31 = flt_BE0CA4[(unsigned __int8)v22];
          *(v19 - 2) = v31;
          *v19 = v20;
          *(v19 - 1) = v30;
          v23 = v22 + 1;
          dword_BE08A0 = v23;
          v24 = v31 * v31 + v30 * v30 + v20 * v20;
          if ( v24 == 0.0 )
          {
            *(v19 - 2) = 0.0;
            *(v19 - 1) = 1.0;
            *v19 = 0.0;
          }
          else
          {
            v25 = 1.0 / sqrt(v24);
            *(v19 - 2) = v31 * v25;
            *(v19 - 1) = v30 * v25;
            *v19 = v20 * v25;
          }
          LOBYTE(v4) = v23;
          v26 = flt_BE08A4[(unsigned __int8)v23];
          v18 = v23 + 1;
          v19 += 10;
          dword_BE08A0 = v18;
          *(v19 - 9) = -24.0 - v26 * 3.0;
        }
        while ( (int)v19 < (int)flt_BE1FE0 );
      }
      else if ( (v14 == 7 || v14 == 8 || v14 == 9 || v14 == 10 || v14 == 11 || v14 == 12 || v14 == 16) && *v28 )
      {
        LOBYTE(v4) = sub_5FCD70(dword_B716EC);
      }
    }
  }
  return v4;
}
