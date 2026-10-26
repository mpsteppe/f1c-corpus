int __thiscall sub_407440(_DWORD *this, int a2)
{
  int v2; // eax
  int result; // eax
  float v4; // [esp+0h] [ebp-18h]
  float v5; // [esp+4h] [ebp-14h]
  int v6; // [esp+8h] [ebp-10h]

  v2 = this[14];
  v4 = 0.0;
  v5 = 0.0;
  v6 = 0;
  if ( v2 )
  {
    v4 = *(float *)(v2 + 116);
    v6 = *(_DWORD *)(v2 + 124);
    v5 = *(float *)(v2 + 120);
  }
  result = a2;
  *(float *)a2 = v4;
  *(float *)(a2 + 4) = v5;
  *(_DWORD *)(a2 + 8) = v6;
  return result;
}
