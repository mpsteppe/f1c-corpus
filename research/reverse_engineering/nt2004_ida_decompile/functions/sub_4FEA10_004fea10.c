int __thiscall sub_4FEA10(int this, unsigned __int8 *Buffer, signed int ElementSize)
{
  signed int i; // eax
  int v4; // edx
  int v5; // ebp
  int v6; // ebx

  for ( i = 0; i < ElementSize; *(_DWORD *)(this + 20) = v4 )
  {
    v4 = *(_DWORD *)(this + 12);
    v5 = v4 * Buffer[i] + *(_DWORD *)(this + 24);
    *(_DWORD *)(this + 12) = *(_DWORD *)(this + 16);
    v6 = *(_DWORD *)(this + 20);
    ++i;
    *(_DWORD *)(this + 24) = v5;
    *(_DWORD *)(this + 16) = v6;
  }
  return sub_5BF5A6(Buffer, ElementSize, 1u, *(FILE **)this);
}
