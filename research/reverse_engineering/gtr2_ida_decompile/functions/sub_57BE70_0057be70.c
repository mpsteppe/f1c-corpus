void __thiscall sub_57BE70(char *this)
{
  sub_56DF50((_DWORD *)this + 672, (float *)this + 1101);
  sub_4FB7E0(this + 14808, 0, 7);
  if ( *((_DWORD *)this + 4603) == 1 )
    *((_DWORD *)this + 4603) = 0;
  if ( *((_DWORD *)this + 1101) && !this[4468] || *((_DWORD *)this + 1084) && !this[4400] )
    *((_DWORD *)this + 4358) = *((_DWORD *)this + 4362);
  else
    *((_DWORD *)this + 4358) = *((_DWORD *)this + 4361);
  sub_579710((int)this, 0);
  if ( *(_DWORD *)(*(_DWORD *)this + 22468) == *(_DWORD *)(dword_91E084 + 22468)
    && (!(unsigned __int8)sub_4735E0(&dword_B6CBA8) || !sub_473630(&dword_B6CBA8)) )
  {
    sub_443BA0(&dbl_B66040);
  }
}
