// f1_2002_full  0x0042cf10  size=66
int __thiscall sub_42CF10(int this)
{
  int v2; // edi
  int v3; // eax

  sub_42E540((_BYTE *)this);
  v2 = sub_42DE40(this);
  sub_42E6B0(this);
  sub_4DBDE0(0, 0);
  v3 = *(_DWORD *)(this + 16);
  if ( v3 )
  {
    *(_DWORD *)(this + 56) = *(_DWORD *)(v3 + 40);
    *(_DWORD *)(this + 60) = *(_DWORD *)(v3 + 44);
  }
  return v2;
}
