int __thiscall sub_4A5020(int *this)
{
  int v1; // edx

  v1 = *this;
  if ( *(_BYTE *)this[69] )
    this[67] = 0;
  else
    this[67] = 1;
  return (*(int (__stdcall **)(int))(v1 + 44))(this[67]);
}
