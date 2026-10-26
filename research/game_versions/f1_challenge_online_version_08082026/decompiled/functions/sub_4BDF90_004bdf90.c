int __thiscall sub_4BDF90(_DWORD *this, int a2)
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
      sub_4BD8C0(v2, a2);
      v2 += 9;
      --v4;
    }
    while ( v4 );
    --v3;
  }
  while ( v3 );
  return sub_4BD8C0(this + 576, a2);
}
