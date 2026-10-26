void __thiscall sub_57BCB0(float *this)
{
  int i; // edi

  sub_4FB7E0(this + 3702, 0, 5);
  if ( *((_DWORD *)this + 4603) == 1 )
    this[4603] = 0.0;
  if ( this[4357] != this[4360] )
    this[4357] = (this[4360] + this[4357]) * 0.5;
  if ( *((_DWORD *)this + 1101) && !*((_BYTE *)this + 4468) || *((_DWORD *)this + 1084) && !*((_BYTE *)this + 4400) )
    this[4358] = this[4362];
  else
    this[4358] = this[4361];
  sub_579710((int)this, 0);
  for ( i = 0; i < 5; ++i )
    sub_570EE0();
  if ( *(_DWORD *)(*(_DWORD *)this + 22468) == *(_DWORD *)(dword_91E084 + 22468)
    && (!(unsigned __int8)sub_4735E0(&dword_B6CBA8) || !sub_473630(&dword_B6CBA8)) )
  {
    sub_4439F0(&dbl_B66040);
  }
}
