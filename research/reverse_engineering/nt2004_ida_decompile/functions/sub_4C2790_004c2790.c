char __thiscall sub_4C2790(float *this, float a2)
{
  int v3; // eax
  int v4; // esi
  double v5; // st7
  int v7; // [esp-10h] [ebp-20h]
  float v8; // [esp+0h] [ebp-10h]
  float v9; // [esp+0h] [ebp-10h]
  float v10; // [esp+4h] [ebp-Ch]
  float v11; // [esp+8h] [ebp-8h]
  float v12; // [esp+8h] [ebp-8h]
  float v13; // [esp+Ch] [ebp-4h]
  float v14; // [esp+Ch] [ebp-4h]
  float v15; // [esp+14h] [ebp+4h]
  float v16; // [esp+14h] [ebp+4h]

  if ( a2 >= (double)this[214] )
  {
    if ( *((_DWORD *)this + 222) )
      sub_51E4A0(*((_DWORD *)this + 219));
    sub_4C1790(this, 4);
    sub_41B3A0(*(_DWORD *)this);
    this[215] = dbl_7DA9D0 - this[213];
    sub_51F3D0(1, 2);
    if ( *(_DWORD *)(*(_DWORD *)this + 16584) == 1 )
    {
      sub_427A00(*(_DWORD *)this);
      sub_421590(*(_DWORD *)this, 15, 0);
    }
    sub_51E7C0(0.0, 0.0, 0.0, 0.0);
    sub_51E770(0);
    LOBYTE(v3) = sub_4EED40(*(_DWORD *)this);
    if ( (_BYTE)v3 )
    {
      if ( *((int *)this + 2) > -1 )
        sub_4BEE40(dword_766238);
      LOBYTE(v3) = dword_767C7C;
      if ( dword_767C7C > 0 )
      {
        LOBYTE(v3) = *(_BYTE *)(*(_DWORD *)this + 4768);
        if ( (_BYTE)v3 != 1 )
        {
          v7 = *(_DWORD *)(*(_DWORD *)this + 4760);
          *(_BYTE *)(*(_DWORD *)this + 4768) = 1;
          LOBYTE(v3) = sub_50B4E0(v7, 1);
        }
      }
    }
    v4 = *(_DWORD *)this + 20836;
    *(_BYTE *)(v4 + 198) = 1;
    *(_DWORD *)(v4 + 192) = 0;
    return v3;
  }
  if ( *(_DWORD *)(dword_75AAD0[dword_75AAC0] + 25248) == *((_DWORD *)this + 1)
    && *(_DWORD *)(*(_DWORD *)this + 20892) != 1 )
  {
    sub_501F60(2, 1);
  }
  if ( *((_BYTE *)this + 864) && this[214] - 2.0 <= a2 )
    *((_BYTE *)this + 864) = 0;
  if ( *((_DWORD *)this + 222) && a2 > (double)this[218] )
  {
    v5 = (a2 - this[218]) * 12.0 + this[217];
    v13 = v5;
    if ( v5 > this[219] )
      v13 = this[219];
    sub_51E4A0(LODWORD(v13));
  }
  v3 = *((_DWORD *)this + 223);
  if ( v3 )
  {
    v8 = 0.0;
    v11 = 0.0;
    v10 = 0.0;
    v14 = 0.0;
    switch ( *((_DWORD *)this + 220) )
    {
      case 1:
        if ( sub_404F90(&flt_628F60) )
        {
          v8 = 7.6999998;
          v11 = 14.26;
        }
        else
        {
          v8 = 5.46;
          v11 = 12.166;
        }
        break;
      case 2:
        if ( sub_404F90(&flt_628F60) )
        {
          v10 = 5.46;
          v14 = 12.166;
        }
        else
        {
          v10 = 7.6999998;
          v14 = 14.26;
        }
        break;
      case 3:
        if ( sub_404F90(&flt_628F60) )
        {
          v8 = 16.700001;
          v11 = 21.700001;
          v10 = 5.3000002;
          v14 = 11.2;
        }
        else
        {
          v8 = 5.3000002;
          v11 = 11.2;
          v10 = 16.700001;
          v14 = 21.700001;
        }
        break;
    }
    v15 = sub_4BE6A0((float *)dword_766238, *((_DWORD *)this + 2)) * (a2 - this[213]) + this[213];
    if ( v11 + this[233] < v15 )
      goto LABEL_42;
    if ( v8 + this[233] + 0.5 < v15 )
    {
      v12 = 0.18000001;
      v9 = 0.18000001;
      goto LABEL_43;
    }
    if ( v8 + this[233] >= v15 )
    {
LABEL_42:
      v12 = 0.0;
      v9 = 0.0;
    }
    else
    {
      v12 = (v15 - this[233] - v8) * 0.36000001;
      v9 = v12;
    }
LABEL_43:
    if ( v14 + this[233] >= v15 )
    {
      if ( v10 + this[233] + 0.5 < v15 )
      {
        LOBYTE(v3) = sub_51E7C0(v9, 0.18000001, v12, 0.18000001);
        return v3;
      }
      if ( v10 + this[233] < v15 )
      {
        v16 = (v15 - this[233] - v10) * 0.36000001;
        LOBYTE(v3) = sub_51E7C0(v9, v16, v12, v16);
        return v3;
      }
    }
    LOBYTE(v3) = sub_51E7C0(v9, 0.0, v12, 0.0);
  }
  return v3;
}
