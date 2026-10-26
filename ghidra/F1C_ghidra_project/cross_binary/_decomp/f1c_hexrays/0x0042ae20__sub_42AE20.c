// f1c  0x0042ae20  size=54
void __thiscall sub_42AE20(int this, int a2)
{
  int v2; // eax
  int v3; // edx

  v2 = a2;
  v3 = 0;
  if ( a2 == *(_DWORD *)(this + 17916) )
  {
    *(_DWORD *)(this + 17916) = 0;
    sub_42AD00((float *)this, 100);
    *(_DWORD *)(this + 17440) = v3;
  }
  if ( v2 == *(_DWORD *)(this + 17912) )
    *(_DWORD *)(this + 17912) = v3;
}
