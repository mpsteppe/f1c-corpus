int __thiscall sub_40D360(int this, int a2, int a3)
{
  int v4; // edi
  int v5; // eax
  int v6; // ecx
  int result; // eax
  int v8; // et2

  *(_BYTE *)(this + 46) = 1;
  if ( a2 <= 0 )
    *(_DWORD *)(this + 48) = 0;
  else
    *(_DWORD *)(this + 48) = a2;
  if ( a3 <= 0 || a3 <= a2 )
    *(_DWORD *)(this + 52) = a2 + 5;
  else
    *(_DWORD *)(this + 52) = a3;
  v4 = *(_DWORD *)(this + 48);
  v5 = sub_5884ED();
  v6 = *(_DWORD *)(this + 52) - v4;
  v8 = v5 % v6;
  result = v5 / v6;
  *(float *)(this + 60) = (float)(v4 + v8);
  return result;
}
