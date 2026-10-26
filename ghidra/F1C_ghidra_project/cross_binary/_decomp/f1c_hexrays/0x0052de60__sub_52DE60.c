// f1c  0x0052de60  size=167
int __thiscall sub_52DE60(int this)
{
  int v1; // edi
  int v2; // eax
  bool v3; // zf
  int v4; // eax
  int v5; // edx

  v1 = *(_DWORD *)(this + 9348);
  v2 = 5 * *(_DWORD *)(this + 9364);
  *(_DWORD *)(this + 9428) = 1;
  *(_DWORD *)(this + 9432) = 28800 * v2 / v1;
  *(_DWORD *)(this + 9436) = 28800 * v2 % v1 / 100;
  v3 = *(_BYTE *)(this + 9360) == 1;
  v4 = *(_DWORD *)(this + 9420);
  *(_DWORD *)(this + 9440) = v1 / 100;
  if ( v3 )
    *(_DWORD *)(this + 9356) = 768 * v4;
  else
    *(_DWORD *)(this + 9356) = 2304 * v4;
  v5 = *(_DWORD *)(this + 9356);
  *(_BYTE *)(this + 9404) = 1;
  *(_DWORD *)(this + 9372) = v5;
  return 0;
}
