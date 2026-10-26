int __thiscall sub_5DAC00(char *this, char *a2, __int16 a3)
{
  char *v3; // eax
  char *v5; // edi
  int v6; // edx
  char v7; // cl

  v3 = a2;
  v5 = this + 468;
  v6 = this + 468 - a2;
  do
  {
    v7 = *v3;
    v3[v6] = *v3;
    ++v3;
  }
  while ( v7 );
  _strupr(v5);
  if ( (a3 & 0x10) != 0 )
    *(_DWORD *)this |= 0x10u;
  if ( (a3 & 0x100) != 0 )
    *(_DWORD *)this |= 0x110u;
  if ( (a3 & 0x2000) != 0 )
    *(_DWORD *)this |= 0x2010u;
  if ( (a3 & 4) != 0 )
    *(_DWORD *)this |= 4u;
  *(_DWORD *)this |= 0x400u;
  return 0;
}
