_DWORD *__thiscall sub_4C0090(_DWORD *this)
{
  _DWORD *v2; // esi
  int v3; // edi

  v2 = this + 3;
  v3 = 12;
  do
  {
    sub_430A60(v2);
    v2 += 16;
    --v3;
  }
  while ( v3 );
  sub_4C00C0(this);
  return this;
}
