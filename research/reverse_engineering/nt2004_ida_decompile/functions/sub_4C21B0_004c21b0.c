double __thiscall sub_4C21B0(int *this, float *a2)
{
  int v3; // eax
  double v4; // st7
  bool v5; // c0
  bool v6; // c3
  double v7; // st7
  int v8; // eax
  int v9; // eax
  int v10; // edi
  int v11; // eax
  float v12; // eax
  int v13; // edi
  float v15; // [esp+0h] [ebp-120h]
  int v16; // [esp+0h] [ebp-120h]
  float v17; // [esp+14h] [ebp-10Ch]
  float v18; // [esp+18h] [ebp-108h]
  float v19; // [esp+1Ch] [ebp-104h]
  char v20[253]; // [esp+20h] [ebp-100h] BYREF
  __int16 v21; // [esp+11Dh] [ebp-3h]
  char v22; // [esp+11Fh] [ebp-1h]

  memset(this + 221, 0, 0x30u);
  *a2 = 0.0;
  v3 = this[236];
  if ( v3 > 0 && (v3 <= 2 || v3 == 8) )
    sub_4DC690(aPittedOnClosed, 3, 10);
  v18 = 0.0;
  v19 = 0.0;
  if ( this[8] && !this[236] )
    v18 = (float)(int)sub_4DC9C0(0);
  if ( !(unsigned __int8)sub_4EED40(*this) )
  {
    v4 = flt_7D3C54[(unsigned __int8)dword_7D3C50++];
    v19 = v4 + v4;
  }
  v20[0] = byte_629120;
  memset(&v20[1], 0, 0xFCu);
  v21 = 0;
  v22 = 0;
  if ( !sub_4E8F80(v20, 256) && sub_579060(v20, aInfineon) && !sub_404F90(&flt_628F60) )
  {
    v18 = v18 + 12.0;
    sub_45D100(&byte_764D68, (int)aHoldingFor12Se, 3, 16909060, 0);
  }
  this[217] = *(int *)(*this + 18792);
  v17 = sub_4C2BB0(this) + *((float *)this + 217);
  if ( v17 >= 0.0 )
  {
    if ( v17 > (double)*(float *)(*this + 18796) )
      v17 = *(float *)(*this + 18796);
  }
  else
  {
    v17 = 0.0;
  }
  v5 = v17 < (double)*((float *)this + 217);
  v6 = v17 == *((float *)this + 217);
  *((float *)this + 219) = v17;
  if ( v5 || v6 )
  {
    if ( dword_75CBB0 != 7 )
      sub_51E4A0(LODWORD(v17));
  }
  else
  {
    this[222] = 1;
    v7 = flt_7D3C54[(unsigned __int8)dword_7D3C50++];
    *((float *)this + 218) = v7 + v7 + *((float *)this + 213) + 1.0;
  }
  v8 = this[40];
  this[220] = v8;
  if ( v8 )
  {
    v9 = v8 - 1;
    v10 = this[72];
    if ( v9 )
    {
      v11 = v9 - 1;
      if ( v11 )
      {
        if ( v11 == 1 )
        {
          sub_51E470(0, 1, (double)this[88] * *(double *)(this + 85) + *(double *)(this + 83));
          sub_51E470(1, 1, (double)this[104] * *(double *)(this + 101) + *(double *)(this + 99));
          sub_51E470(2, 1, (double)this[120] * *(double *)(this + 117) + *(double *)(this + 115));
          sub_51E470(3, 1, (double)this[136] * *(double *)(this + 133) + *(double *)(this + 131));
          sub_51E670(v10, 1);
        }
      }
      else
      {
        sub_51E470(1, 1, (double)this[104] * *(double *)(this + 101) + *(double *)(this + 99));
        sub_51E4D0(1, v10, 1);
        sub_51E470(3, 1, (double)this[136] * *(double *)(this + 133) + *(double *)(this + 131));
        sub_51E4D0(3, v10, 1);
      }
    }
    else
    {
      sub_51E470(0, 1, (double)this[88] * *(double *)(this + 85) + *(double *)(this + 83));
      sub_51E4D0(0, v10, 1);
      sub_51E470(2, 1, (double)this[120] * *(double *)(this + 117) + *(double *)(this + 115));
      sub_51E4D0(2, v10, 1);
    }
    v12 = *((float *)this + 213);
    this[223] = 1;
    *((float *)this + 233) = v12;
    *((float *)this + 234) = v12 + 100.0;
  }
  if ( this[56] )
  {
    this[224] = 1;
    v13 = dword_7D3C44;
    if ( dword_79FC40 < 1023 )
    {
      ++dword_79FC40;
      dword_7D3C44 += 208;
    }
    v15 = dbl_7DA9D0;
    sub_4D0D00(6, 0, 4, this[1], LODWORD(v15), 0);
    *(float *)(v13 + 8) = dbl_7DA9D0;
    if ( *a2 < 8.0 )
      *a2 = 8.0;
  }
  if ( (unsigned __int8)sub_4EED40(*this) )
  {
    sub_4BEF30(dword_766238, this[2], this[213]);
    sub_4BECA0(dword_766238, 1);
    if ( dword_767C7C > 0 )
    {
      if ( *(_BYTE *)(*this + 4768) )
      {
        v16 = *(_DWORD *)(*this + 4760);
        *(_BYTE *)(*this + 4768) = 0;
        sub_50B4E0(v16, 1);
      }
    }
  }
  if ( this[152] == this[153] )
  {
    this[230] = 0;
  }
  else
  {
    this[230] = 1;
    if ( *a2 < 5.3000002 )
      *a2 = 5.3000002;
    this[153] = this[152];
    sub_51E440(3, (double)this[152] * *(double *)(this + 149) + *(double *)(this + 147));
  }
  if ( this[168] == this[169] )
  {
    this[231] = 0;
  }
  else
  {
    this[231] = 1;
    if ( *a2 < 5.4000001 )
      *a2 = 5.4000001;
    this[169] = this[168];
    sub_51E440(14, (double)this[168] * *(double *)(this + 165) + *(double *)(this + 163));
  }
  if ( this[184] == this[185] )
  {
    this[232] = 0;
  }
  else
  {
    this[232] = 1;
    if ( *a2 < 6.5 )
      *a2 = 6.5;
    this[185] = this[184];
    sub_51E440(29, (double)this[184] * *(double *)(this + 181) + *(double *)(this + 179));
  }
  if ( *(_DWORD *)(*this + 16584) == 1 )
    sub_4280C0(*this);
  return v19 + v18;
}
