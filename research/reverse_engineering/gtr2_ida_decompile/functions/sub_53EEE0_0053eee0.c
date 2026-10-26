void __thiscall sub_53EEE0(float *this)
{
  double v2; // st7
  double v3; // st7
  double v4; // st7
  _DWORD *v5; // eax
  float v6; // [esp+4h] [ebp-4h]

  if ( *((_DWORD *)this + 3705) > 1u )
    return;
  if ( !(unsigned __int8)sub_4735A0() )
    goto LABEL_11;
  if ( this[5644] >= 0.0 )
  {
    if ( this[5644] > 5.0 )
      this[5644] = 5.0;
  }
  else
  {
    this[5644] = 0.0;
  }
  v2 = this[5644] - dbl_FB1D08;
  this[5644] = v2;
  if ( v2 <= 0.0 )
  {
    v3 = sub_474B10(&dword_B6CBA8, *((_DWORD *)this + 5617), -1.0);
    v6 = -v3;
    v4 = v3 + this[5644];
    if ( v6 > v4 )
      v4 = v6;
    this[5644] = v4;
LABEL_11:
    if ( dword_82F4A0 >= 1023 )
    {
      v5 = (_DWORD *)off_9034A4;
    }
    else
    {
      ++dword_82F4A0;
      v5 = (_DWORD *)off_9034A4;
      off_9034A4 += 848;
    }
    sub_53EC40((int)this, v5, -8388609);
    sub_577180(this + 4);
  }
}
