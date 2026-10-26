char __thiscall sub_60A790(_DWORD *this)
{
  int v2; // eax

  v2 = this[61];
  if ( v2 )
  {
    LOBYTE(v2) = sub_609B00((int)this, 1, 1);
    this[61] = 0;
  }
  return v2;
}
