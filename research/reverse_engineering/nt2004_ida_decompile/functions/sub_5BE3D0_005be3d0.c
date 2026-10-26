int __thiscall sub_5BE3D0(void *this)
{
  int result; // eax
  int i; // esi

  result = sub_577650(this);
  for ( i = result - 1; i >= 0; --i )
    result = sub_5BE2D0((int)this, i);
  return result;
}
