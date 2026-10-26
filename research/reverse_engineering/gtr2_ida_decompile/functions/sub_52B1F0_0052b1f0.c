int __thiscall sub_52B1F0(_BYTE *this, int a2)
{
  int result; // eax

  *this = *(_BYTE *)a2;
  this[1] = *(_BYTE *)(a2 + 1);
  this[2] = *(_BYTE *)(a2 + 2);
  *((_DWORD *)this + 1) = *(_DWORD *)(a2 + 4);
  *((_DWORD *)this + 2) = *(_DWORD *)(a2 + 8);
  *((_DWORD *)this + 3) = *(_DWORD *)(a2 + 12);
  *((_DWORD *)this + 4) = *(_DWORD *)(a2 + 16);
  result = *(_DWORD *)(a2 + 20);
  *((_DWORD *)this + 5) = result;
  return result;
}
