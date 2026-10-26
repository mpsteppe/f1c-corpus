char __thiscall sub_46E780(int this)
{
  int *v2; // ecx

  sub_4A4490();
  v2 = *(int **)(this + 340);
  *(_DWORD *)(this + 280) = 0;
  if ( v2 )
  {
    sub_459B30(v2);
    *(_BYTE *)(this + 360) = 0;
  }
  *(_BYTE *)(this + 420) = 0;
  return 1;
}
