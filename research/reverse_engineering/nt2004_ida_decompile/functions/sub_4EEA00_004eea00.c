void __thiscall sub_4EEA00(float *this)
{
  double v2; // st7
  _DWORD *v3; // eax

  if ( *((_DWORD *)this + 4146) > 1u )
    return;
  if ( !sub_463490(dword_764D70) )
    goto LABEL_9;
  if ( this[6323] >= 0.0 )
  {
    if ( this[6323] > 5.0 )
      this[6323] = 5.0;
  }
  else
  {
    this[6323] = 0.0;
  }
  v2 = this[6323] - dbl_7DA9C0;
  this[6323] = v2;
  if ( v2 <= 0.0 )
  {
    this[6323] = sub_464A00(dword_764D70, *((_DWORD *)this + 6312), -1.0);
LABEL_9:
    if ( dword_79FC40 >= 1023 )
    {
      v3 = (_DWORD *)dword_7D3C44;
    }
    else
    {
      ++dword_79FC40;
      v3 = (_DWORD *)dword_7D3C44;
      dword_7D3C44 += 208;
    }
    sub_4EE360((int)this, v3, -8388609);
    sub_51B960(this + 21);
  }
}
