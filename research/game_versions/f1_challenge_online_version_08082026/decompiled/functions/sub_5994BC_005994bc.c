int __thiscall sub_5994BC(int this, int a2, int a3)
{
  int result; // eax

  *(_BYTE *)(this + 72) = a3 == 1;
  if ( !a3 )
  {
    sub_598C70((_DWORD *)(this + 76));
    if ( this != -76 )
      sub_598C1C((_DWORD *)(this + 76));
    *(_DWORD *)(this + 68) = 0;
  }
  sub_59A4C9(this);
  if ( a2 && !*(_BYTE *)(this + 72) )
  {
    *(_DWORD *)(this + 28) = a2;
    *(_DWORD *)(this + 12) = a2 + 8;
    *(_DWORD *)(this + 16) = a2 + 8;
    *(_DWORD *)(this + 32) = a2;
    *(_DWORD *)(this + 44) = a2 + 4;
    *(_DWORD *)(this + 48) = a2 + 4;
  }
  *(_DWORD *)(this + 80) = a2;
  *(_DWORD *)(this + 64) = dword_8D5A68;
  result = dword_8D5A68;
  *(_DWORD *)(this + 56) = 0;
  *(_DWORD *)(this + 60) = result;
  return result;
}
