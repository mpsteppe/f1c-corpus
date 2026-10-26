int __thiscall sub_4913B0(int *this)
{
  int v1; // eax

  v1 = *this;
  if ( byte_91BF6C )
    this[67] = 0;
  else
    this[67] = 1;
  (*(void (__stdcall **)(int))(v1 + 44))(this[67]);
  return 0;
}
