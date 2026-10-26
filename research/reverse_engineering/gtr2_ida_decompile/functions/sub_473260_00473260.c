int __thiscall sub_473260(int this, float a2)
{
  double v2; // st7
  unsigned __int8 v4; // c0
  unsigned __int8 v5; // c3
  double v6; // st7
  double v7; // st6
  double v8; // st6
  int result; // eax
  int v10; // ecx

  v2 = a2 + *(float *)(this + 4);
  *(float *)(this + 4) = v2;
  if ( !(v4 | v5) )
  {
    v6 = 1.0 / v2;
    *(_DWORD *)(this + 4) = 0;
    v7 = (double)*(int *)(this + 8);
    *(_DWORD *)(this + 8) = 0;
    *(float *)(this + 16) = v7 * v6;
    v8 = (double)*(int *)(this + 12);
    *(_DWORD *)(this + 12) = 0;
    *(float *)(this + 20) = v8 * v6;
  }
  result = this + 860;
  v10 = 26;
  do
  {
    result += 32;
    --v10;
    *(float *)(result - 864) = a2 + *(float *)(result - 864);
    *(float *)(result - 32) = a2 + *(float *)(result - 32);
    *(float *)(result - 860) = a2 + *(float *)(result - 860);
    *(float *)(result - 28) = a2 + *(float *)(result - 28);
    *(float *)(result - 856) = a2 + *(float *)(result - 856);
    *(float *)(result - 24) = a2 + *(float *)(result - 24);
    *(float *)(result - 852) = a2 + *(float *)(result - 852);
    *(float *)(result - 20) = a2 + *(float *)(result - 20);
    *(float *)(result - 848) = a2 + *(float *)(result - 848);
    *(float *)(result - 16) = a2 + *(float *)(result - 16);
    *(float *)(result - 844) = a2 + *(float *)(result - 844);
    *(float *)(result - 12) = a2 + *(float *)(result - 12);
    *(float *)(result - 840) = a2 + *(float *)(result - 840);
    *(float *)(result - 8) = a2 + *(float *)(result - 8);
    *(float *)(result - 836) = a2 + *(float *)(result - 836);
    *(float *)(result - 4) = a2 + *(float *)(result - 4);
  }
  while ( v10 );
  return result;
}
