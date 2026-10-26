char __thiscall sub_553730(int this, int a2)
{
  char result; // al

  *(_DWORD *)a2 = *(_DWORD *)(this + 216);
  *(_DWORD *)(a2 + 4) = *(_DWORD *)(this + 220);
  *(_DWORD *)(a2 + 8) = *(_DWORD *)(this + 224);
  *(float *)(a2 + 12) = dbl_FB1D18;
  *(_DWORD *)(a2 + 16) = *(_DWORD *)(this + 228);
  *(_DWORD *)(a2 + 20) = *(_DWORD *)(this + 232);
  *(float *)(a2 + 24) = sub_552900(this);
  *(_DWORD *)(a2 + 28) = *(_DWORD *)(this + 348);
  *(_DWORD *)(a2 + 32) = *(_DWORD *)(this + 352);
  *(_DWORD *)(a2 + 36) = *(_DWORD *)(this + 312);
  *(_DWORD *)(a2 + 40) = *(_DWORD *)(this + 300);
  *(_DWORD *)(a2 + 44) = *(_DWORD *)(this + 476);
  sub_552890();
  *(_BYTE *)(a2 + 1836) = *(_BYTE *)(this + 472);
  result = *(_BYTE *)(this + 473);
  *(_BYTE *)(a2 + 1837) = result;
  *(_BYTE *)(a2 + 1838) = *(_BYTE *)(this + 474);
  return result;
}
