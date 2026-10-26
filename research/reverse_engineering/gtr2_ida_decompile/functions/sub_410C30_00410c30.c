int __thiscall sub_410C30(int this, int a2, int a3)
{
  int v4; // edi
  int v5; // eax
  int v6; // ecx
  int result; // eax
  int v8; // et2

  *(_BYTE *)(this + 58) = 1;
  if ( a2 <= 0 )
    *(_DWORD *)(this + 60) = 0;
  else
    *(_DWORD *)(this + 60) = a2;
  if ( a3 <= 0 || a3 <= a2 )
    *(_DWORD *)(this + 64) = a2 + 5;
  else
    *(_DWORD *)(this + 64) = a3;
  v4 = *(_DWORD *)(this + 60);
  v5 = rand();
  v6 = *(_DWORD *)(this + 64) - v4;
  v8 = v5 % v6;
  result = v5 / v6;
  *(float *)(this + 72) = (float)(v4 + v8);
  return result;
}
