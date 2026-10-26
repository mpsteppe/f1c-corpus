int __thiscall sub_59C130(int this, int a2)
{
  int result; // eax
  _BYTE *v3; // esi
  int v4; // edi
  int v5; // ebp
  _BYTE *v6; // ecx
  int v7; // esi

  result = this;
  *(_DWORD *)(this + 4) = *(_DWORD *)(a2 + 4);
  v3 = (_BYTE *)(this + 8);
  v4 = a2 - this;
  v5 = 32;
  do
  {
    *v3 = v3[v4];
    ++v3;
    --v5;
  }
  while ( v5 );
  *(_BYTE *)(this + 40) = *(_BYTE *)(a2 + 40);
  *(_BYTE *)(this + 41) = *(_BYTE *)(a2 + 41);
  *(_BYTE *)(this + 42) = *(_BYTE *)(a2 + 42);
  *(_BYTE *)(this + 43) = *(_BYTE *)(a2 + 43);
  *(_BYTE *)(this + 44) = *(_BYTE *)(a2 + 44);
  v6 = (_BYTE *)(this + 45);
  v7 = 255;
  do
  {
    *v6 = v6[v4];
    ++v6;
    --v7;
  }
  while ( v7 );
  return result;
}
