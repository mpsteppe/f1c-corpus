int __thiscall sub_5BC080(int *this)
{
  int result; // eax
  int v2; // edx

  result = *this;
  if ( *this )
  {
    v2 = *(_DWORD *)(result + 32);
    *this = v2;
    if ( !v2 )
      this[1] = 0;
    --this[2];
  }
  return result;
}
