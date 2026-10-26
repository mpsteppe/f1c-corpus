BOOL __thiscall sub_46CE70(int this)
{
  double v1; // st7
  BOOL result; // eax

  *(_DWORD *)(this + 36) = 0;
  *(_DWORD *)(this + 40) = 0;
  *(_DWORD *)(this + 44) = 0;
  *(_DWORD *)(this + 192) = 0;
  *(_BYTE *)(this + 208) = 0;
  *(_DWORD *)(this + 176) = 1065353216;
  if ( this != -148 )
  {
    *(_DWORD *)(this + 24) = *(_DWORD *)(this + 148);
    *(_DWORD *)(this + 28) = *(_DWORD *)(this + 152);
    *(_DWORD *)(this + 32) = *(_DWORD *)(this + 156);
  }
  *(_BYTE *)(this + 164) = 1;
  *(_DWORD *)(this + 212) = 1065353216;
  *(_DWORD *)(this + 224) = 0;
  v1 = flt_BE08A4[(unsigned __int8)dword_BE08A0++];
  result = v1 < 0.80000001;
  *(_BYTE *)(this + 220) = result;
  *(_DWORD *)(this + 228) = 1082130432;
  if ( v1 < 0.80000001 )
    *(_DWORD *)(this + 224) = 1;
  *(_DWORD *)(this + 236) = 0;
  *(_DWORD *)(this + 252) = 0;
  *(_DWORD *)(this + 256) = 0;
  *(_DWORD *)(this + 260) = 0;
  *(_DWORD *)(this + 240) = 0;
  *(_DWORD *)(this + 244) = 0;
  *(_DWORD *)(this + 248) = 0;
  *(_DWORD *)(this + 232) = 0;
  *(_DWORD *)(this + 212) = 1065353216;
  return result;
}
