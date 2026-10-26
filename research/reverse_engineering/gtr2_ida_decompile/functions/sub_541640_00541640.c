int __thiscall sub_541640(float *this)
{
  double v2; // st7
  int v3; // eax

  v2 = this[6] - dbl_FB1D10;
  this[6] = v2;
  if ( v2 <= 0.0
    && (this[6] = this[5], v3 = sub_410A80(&dword_91BF20), *((_DWORD *)this + 1))
    && v3
    && (unsigned __int8)sub_5DA650(v3) )
  {
    return (*(int (__thiscall **)(float *))(*(_DWORD *)this + 12))(this);
  }
  else
  {
    return 0;
  }
}
