// f1c  0x004c77d0  size=283
void __thiscall sub_4C77D0(float *this)
{
  double v2; // st7
  double v3; // st7
  double v4; // st7
  _DWORD *v5; // eax
  float v6; // [esp+4h] [ebp-4h]

  if ( *((_DWORD *)this + 3250) > 1u )
    return;
  if ( !sub_461DB0(dword_7CD25C) )
    goto LABEL_11;
  if ( this[4654] >= 0.0 )
  {
    if ( this[4654] > 5.0 )
      this[4654] = 5.0;
  }
  else
  {
    this[4654] = 0.0;
  }
  v2 = this[4654] - dbl_8AFE90;
  this[4654] = v2;
  if ( v2 <= 0.0 )
  {
    v3 = sub_462FF0(dword_7CD25C, *((_DWORD *)this + 4645), -1.0);
    v6 = -v3;
    v4 = v3 + this[4654];
    if ( v6 > v4 )
      v4 = v6;
    this[4654] = v4;
LABEL_11:
    if ( dword_83EE60 >= 1023 )
    {
      sub_4C71C0((int)this, (_DWORD *)dword_8AAE64);
    }
    else
    {
      ++dword_83EE60;
      v5 = (_DWORD *)dword_8AAE64;
      dword_8AAE64 += 432;
      sub_4C71C0((int)this, v5);
    }
    sub_4EF2E0(this + 3);
  }
}
