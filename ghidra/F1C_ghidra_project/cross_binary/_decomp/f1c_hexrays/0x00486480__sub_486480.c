// f1c  0x00486480  size=49
void __thiscall sub_486480(_DWORD *this, int a2)
{
  int v2; // edx
  int i; // eax

  v2 = this[51];
  if ( v2 )
  {
    for ( i = *(_DWORD *)(v2 + 24); i; i = *(_DWORD *)(i + 24) )
      v2 = i;
    *(_DWORD *)(v2 + 24) = a2;
  }
  else
  {
    this[51] = a2;
  }
}
