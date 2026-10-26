int __thiscall sub_4BBED0(_DWORD *this, int a2)
{
  int v2; // eax

  v2 = this[15];
  if ( v2 >= 4 )
  {
    this[2 * v2 + 15] += *(char *)(a2 + 8);
  }
  else
  {
    this[2 * v2 + 16] = 3;
    this[2 * this[15]++ + 17] = *(char *)(a2 + 8);
  }
  return sub_4A5660((_DWORD *)(*this + 13004), 1);
}
