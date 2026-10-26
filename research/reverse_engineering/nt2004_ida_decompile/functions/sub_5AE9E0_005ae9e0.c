_DWORD *__thiscall sub_5AE9E0(_DWORD *this)
{
  _DWORD *v2; // esi
  int v3; // ebx

  sub_5918B0(this);
  v2 = this + 1;
  v3 = 8;
  do
  {
    sub_5A9F40(v2);
    v2 += 16;
    --v3;
  }
  while ( v3 );
  this[129] = 0;
  this[130] = 0;
  this[131] = 0;
  return this;
}
