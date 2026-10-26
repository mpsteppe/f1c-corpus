int __thiscall sub_4F6D60(_DWORD *this)
{
  _DWORD *v1; // edx
  int result; // eax

  v1 = (_DWORD *)this[16];
  *this = 0;
  for ( result = 0; result < 5; ++result )
  {
    if ( !*v1 )
      break;
    ++v1;
    ++*this;
  }
  return result;
}

