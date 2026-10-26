int __thiscall sub_5BDFF0(_DWORD *this)
{
  int v2; // ebx
  int i; // esi

  v2 = 0;
  for ( i = 0; i < this[1]; ++i )
    v2 += sub_577650(*(void **)(*this + 4 * i));
  return v2;
}
