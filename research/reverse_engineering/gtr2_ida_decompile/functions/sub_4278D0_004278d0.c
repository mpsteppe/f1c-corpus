char __thiscall sub_4278D0(_DWORD *this)
{
  int v2; // eax
  int v3; // edx
  double v4; // st7
  char v5; // al
  int v6; // eax
  int v7; // edx
  int v8; // ecx
  bool v9; // zf
  double v10; // st7
  double v11; // st7
  int v12; // ebx
  int v13; // edi
  int *v14; // ebp
  int i; // eax
  _DWORD *v16; // ecx
  char v18; // [esp+1h] [ebp-61h]
  int v19; // [esp+6h] [ebp-5Ch]
  int v20; // [esp+Ah] [ebp-58h]
  char v21; // [esp+29h] [ebp-39h]
  float v22; // [esp+2Ah] [ebp-38h]
  float v23; // [esp+2Eh] [ebp-34h]
  float v24[2]; // [esp+3Eh] [ebp-24h] BYREF
  int v25; // [esp+46h] [ebp-1Ch]
  _BYTE v26[12]; // [esp+4Ah] [ebp-18h] BYREF
  char v27[12]; // [esp+56h] [ebp-Ch] BYREF

  v2 = this[5374];
  v3 = this[5228];
  *((_BYTE *)this + 20844) = 1;
  *((_BYTE *)this + 20908) = 0;
  if ( v2 + 1 > v3 )
  {
    if ( *(_DWORD *)dword_B640C8 == 6 )
    {
      if ( dword_B64134 != 8 )
        *((_BYTE *)this + 20908) = 1;
      v25 = dword_FADE18 - this[4821];
      v4 = (double)v25 + 1.5;
    }
    else
    {
      v4 = (double)(int)this[4 * v2 + 5230] - (double)(int)this[4821];
    }
  }
  else
  {
    v25 = this[4 * v2 + 5234] - this[4821];
    v4 = (double)v25 + 1.5;
  }
  v5 = *((_BYTE *)this + 17319);
  v24[0] = v4;
  if ( v5 )
  {
    v6 = *(_DWORD *)dword_B640C8;
    if ( *(_DWORD *)dword_B640C8 != 6 )
      goto LABEL_15;
    sub_573540(this + 4);
    v7 = this[4821];
    v8 = 4 * this[5374];
    *((_BYTE *)this + 20908) = 0;
    this[v8 + 5230] = v7;
    this[4 * this[5374] + 5233] = 8;
  }
  v6 = *(_DWORD *)dword_B640C8;
  if ( *(_DWORD *)dword_B640C8 == 6 )
  {
    if ( this[4821] < dword_FADE18 && dword_B64134 != 8 )
    {
      v9 = *((_BYTE *)this + 17319) == 0;
      goto LABEL_17;
    }
    goto LABEL_18;
  }
LABEL_15:
  v25 = this[4 * this[5374] + 5233] & 8;
  if ( !v25 )
  {
    v9 = v6 == 6;
LABEL_17:
    if ( v9 )
      goto LABEL_20;
  }
LABEL_18:
  sub_53E6F0(0.0);
  sub_54FDF0(&unk_FADD40, *this, v27, v26);
  this[5192] = 5;
  sub_57DCC0(v26, v24);
  *((float *)this + 5201) = dbl_FB1D18 + 180.0;
  if ( *(_DWORD *)dword_B640C8 == 6 )
  {
    *((_BYTE *)this + 20416) = 1;
    *((_BYTE *)this + 21516) = 0;
    sub_52BF50(1);
  }
LABEL_20:
  if ( v22 >= 3.0 )
    v10 = v22;
  else
    v10 = 3.0;
  v11 = v10 * *((float *)this + 5376);
  if ( v11 > *((float *)this + 4300) )
    v11 = *((float *)this + 4300);
  v23 = v11;
  *(float *)&this[4 * this[5374] + 5231] = v11;
  sub_4FB830(v23);
  if ( !v21 )
  {
    sub_578550(LODWORD(v23));
    sub_4220E0((int)this);
  }
  if ( *(_DWORD *)(*this + 4352) && !*(_BYTE *)(*this + 4416) )
  {
    sub_4FB7E0(this + 3706, 1, 5);
    sub_4FB7E0(this + 3706, 1, 6);
  }
  if ( *(_DWORD *)(*this + 4420) && !*(_BYTE *)(*this + 4484) )
  {
    sub_4FB7E0(this + 3706, 1, 5);
    sub_4FB7E0(this + 3706, 1, 7);
  }
  if ( sub_592970(&dword_FB1EF8) >= 0.0099999998 )
  {
    if ( sub_592970(&dword_FB1EF8) >= 0.33000001 )
    {
      v19 = 6;
      if ( sub_592970(&dword_FB1EF8) >= 0.66000003 )
        v19 = 7;
    }
    else
    {
      v19 = 5;
    }
  }
  else
  {
    v19 = this[5229];
  }
  v12 = 0;
  v20 = (int)(this + 5382);
  do
  {
    if ( *(_DWORD *)v20 == v19 )
    {
      v13 = 3;
      v14 = this + 3765;
      do
      {
        for ( i = *v14; *v14 != v12; i = *v14 )
        {
          v16 = this + 3706;
          if ( i >= v12 )
            sub_4FF620(v16, v13);
          else
            sub_4FF5B0(v16, v13);
          if ( ++v20 > 8 )
            break;
        }
        ++v13;
        v14 += 16;
      }
      while ( v13 <= 4 );
    }
    ++v12;
    v19 += 4;
  }
  while ( v12 < 8 );
  return v18;
}
