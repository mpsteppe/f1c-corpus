_DWORD *__thiscall sub_4E0380(_DWORD *this)
{
  _DWORD *v2; // edi
  int v3; // ebx

  v2 = this;
  v3 = 64;
  do
  {
    sub_4DFFC0(v2);
    v2 += 9;
    --v3;
  }
  while ( v3 );
  sub_4DFFC0(this + 576);
  this[585] = 0;
  this[586] = 0;
  this[587] = 0;
  this[588] = 0;
  this[589] = 0;
  return this;
}
