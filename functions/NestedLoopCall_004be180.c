int __thiscall sub_4BE180(_DWORD *this, int a2)
{
  _DWORD *v2; // esi
  int v3; // ebp
  int v4; // edi

  v2 = this;
  v3 = 8;
  do
  {
    v4 = 8;
    do
    {
      ArrayRemoveByValue(v2, a2);
      v2 += 9;
      --v4;
    }
    while ( v4 );
    --v3;
  }
  while ( v3 );
  return ArrayRemoveByValue(this + 576, a2);
}
