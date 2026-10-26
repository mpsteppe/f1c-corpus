int __thiscall sub_434820(_DWORD *this)
{
  sub_434860(this);
  this[2] = sub_40C870(&dword_5EA510);
  if ( sub_4348B0(this) )
    return 1;
  sub_40CDE0(&dword_5EA510, 5, 1);
  *(_BYTE *)this = 1;
  return 0;
}
