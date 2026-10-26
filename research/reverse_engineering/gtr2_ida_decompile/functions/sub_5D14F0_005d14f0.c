void __thiscall sub_5D14F0(int this, double a2, int a3)
{
  int v4; // ebx
  int i; // esi

  sub_5C22D0(*(void **)(this + 8));
  v4 = *(_DWORD *)(this + 12);
  for ( i = 0; i < v4; ++i )
    sub_5C24B0(*(float **)(*(_DWORD *)(this + 20) + 4 * i), a2);
}
