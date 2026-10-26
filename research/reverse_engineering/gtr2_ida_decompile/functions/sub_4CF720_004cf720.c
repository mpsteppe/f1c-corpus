int __thiscall sub_4CF720(_DWORD *this)
{
  int v1; // eax

  v1 = this[67];
  if ( v1 )
  {
    if ( v1 == 1 )
    {
      this[67] = 3;
      return 0;
    }
  }
  else
  {
    this[67] = 2;
  }
  return 0;
}
