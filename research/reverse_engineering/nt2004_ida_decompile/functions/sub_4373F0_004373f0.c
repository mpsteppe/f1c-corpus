int __thiscall sub_4373F0(_DWORD *this)
{
  int result; // eax

  sub_437430(this);
  this[2] = sub_40C460(&dword_6291CC);
  result = sub_437460(this);
  if ( result )
    return 1;
  *(_BYTE *)this = 1;
  return result;
}
