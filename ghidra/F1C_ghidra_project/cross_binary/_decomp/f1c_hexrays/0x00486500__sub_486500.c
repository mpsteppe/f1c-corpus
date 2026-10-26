// f1c  0x00486500  size=49
void __thiscall sub_486500(_DWORD *this, int a2)
{
  int v2; // edx
  int i; // eax

  v2 = this[53];
  if ( v2 )
  {
    for ( i = *(_DWORD *)(v2 + 24); i; i = *(_DWORD *)(i + 24) )
      v2 = i;
    *(_DWORD *)(v2 + 24) = a2;
  }
  else
  {
    this[53] = a2;
  }
}
