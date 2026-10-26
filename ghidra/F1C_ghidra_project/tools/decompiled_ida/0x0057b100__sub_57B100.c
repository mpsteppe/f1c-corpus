// Address: 0x0057b100
// Size: 122 bytes
// Name: sub_57B100
// Type: int __thiscall(int this)
// Source: IDA Hex-Rays decompilation

int __thiscall sub_57B100(int this)
{
  int i; // esi
  LPVOID *v3; // edi
  int result; // eax
  int j; // esi
  LPVOID *v6; // edi

  *(_BYTE *)(this + 4) = 0;
  for ( i = *(_DWORD *)(this + 8); i; result = sub_587BCF(v3) )
  {
    v3 = (LPVOID *)i;
    i = *(_DWORD *)(i + 4);
    if ( *((_BYTE *)v3 + 8) )
      sub_587BCF(*v3);
  }
  *(_DWORD *)(this + 8) = 0;
  *(_DWORD *)(this + 12) = 0;
  *(_DWORD *)(this + 16) = 0;
  *(_DWORD *)(this + 20) = 0;
  for ( j = *(_DWORD *)(this + 24); j; result = sub_587BCF(v6) )
  {
    v6 = (LPVOID *)j;
    j = *(_DWORD *)(j + 4);
    if ( *((_BYTE *)v6 + 8) )
      sub_587BCF(*v6);
  }
  *(_DWORD *)(this + 24) = 0;
  *(_DWORD *)(this + 28) = 0;
  *(_DWORD *)(this + 32) = 0;
  *(_DWORD *)(this + 36) = 0;
  return result;
}
