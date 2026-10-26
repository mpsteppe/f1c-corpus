int __thiscall sub_52B1B0(_BYTE *this, int a2)
{
  int result; // eax

  result = a2;
  *(_BYTE *)a2 = *this;
  *(_BYTE *)(a2 + 1) = this[1];
  *(_BYTE *)(a2 + 2) = this[2];
  *(_DWORD *)(a2 + 4) = *((_DWORD *)this + 1);
  *(_DWORD *)(a2 + 8) = *((_DWORD *)this + 2);
  *(_DWORD *)(a2 + 12) = *((_DWORD *)this + 3);
  *(_DWORD *)(a2 + 16) = *((_DWORD *)this + 4);
  *(_DWORD *)(a2 + 20) = *((_DWORD *)this + 5);
  return result;
}
