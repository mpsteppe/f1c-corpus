int __thiscall sub_6815D6(double *this, int a2)
{
  if ( !a2 )
    return -2147467259;
  *((_DWORD *)this + 1) = *(_DWORD *)(a2 + 4);
  *((_DWORD *)this + 2) = *(_DWORD *)(a2 + 8);
  *((_DWORD *)this + 3) = *(_DWORD *)(a2 + 12);
  *((_DWORD *)this + 4) = *(_DWORD *)(a2 + 16);
  *((_DWORD *)this + 5) = *(_DWORD *)(a2 + 20);
  *((_DWORD *)this + 6) = *(_DWORD *)(a2 + 24);
  this[4] = *(double *)(a2 + 32);
  this[5] = *(double *)(a2 + 40);
  *(_DWORD *)this = *(_DWORD *)a2;
  *((_DWORD *)this + 12) = *(_DWORD *)(a2 + 48);
  *((_DWORD *)this + 13) = *(_DWORD *)(a2 + 52);
  *((_DWORD *)this + 14) = *(_DWORD *)(a2 + 56);
  *((_DWORD *)this + 16) = *(_DWORD *)(a2 + 64);
  *((_DWORD *)this + 15) = *(_DWORD *)(a2 + 60);
  *((_DWORD *)this + 17) = *(_DWORD *)(a2 + 68);
  *((_DWORD *)this + 18) = *(_DWORD *)(a2 + 72);
  *((_DWORD *)this + 19) = *(_DWORD *)(a2 + 76);
  *((_DWORD *)this + 20) = *(_DWORD *)(a2 + 80);
  *((_DWORD *)this + 21) = *(_DWORD *)(a2 + 84);
  *((_DWORD *)this + 22) = *(_DWORD *)(a2 + 88);
  *((_DWORD *)this + 23) = *(_DWORD *)(a2 + 92);
  *((_DWORD *)this + 24) = *(_DWORD *)(a2 + 96);
  *((_DWORD *)this + 25) = *(_DWORD *)(a2 + 100);
  *((_DWORD *)this + 26) = *(_DWORD *)(a2 + 104);
  *((_DWORD *)this + 27) = *(_DWORD *)(a2 + 108);
  *((_DWORD *)this + 28) = *(_DWORD *)(a2 + 112);
  *((_DWORD *)this + 29) = *(_DWORD *)(a2 + 116);
  return 0;
}
