int __thiscall sub_510360(_DWORD *this, int a2)
{
  int v3; // eax
  int v4; // edx
  int v5; // ecx
  int v6; // edx
  int v7; // eax
  int v8; // ecx
  int v9; // eax
  int v11; // [esp-4h] [ebp-Ch]
  int v12; // [esp+0h] [ebp-8h]

  if ( (_BYTE)a2 )
  {
    if ( (byte_B6A7F4 & 1) != 0 )
    {
      sub_50F6B0((int)this, 2, 0.0);
    }
    else if ( (byte_B6ABF8 & 1) != 0 )
    {
      sub_50F6B0((int)this, 3, 0.0);
    }
    else
    {
      sub_50F6B0((int)this, 1, 0.0);
    }
  }
  else
  {
    v3 = this[2573];
    v4 = this[2574];
    this[2571] = 1;
    v5 = this[2571];
    if ( v5 >= v3 )
    {
      if ( v5 > v4 )
        this[2571] = v4;
    }
    else
    {
      this[2571] = v3;
    }
  }
  if ( (int)this[2580] > 0 )
  {
    v6 = this[2583];
    this[2580] = dword_91CB60;
    v7 = this[2582];
    v8 = this[2580];
    if ( v8 >= v7 )
    {
      if ( v8 > v6 )
        this[2580] = v6;
    }
    else
    {
      this[2580] = v7;
    }
  }
  v9 = dword_BE1CD8 + 396 * dword_BE1CD4;
  if ( v9 )
    sub_538860(&unk_BE1CFD, v9 + 260, v11, v12);
  ((void (__thiscall *)(_DWORD *))loc_50BCB0)(this);
  sub_50F0F0((int)this);
  sub_50A880((int)this);
  sub_50ADC0((int)this);
  sub_50BB30(this);
  return sub_615860(a2);
}
