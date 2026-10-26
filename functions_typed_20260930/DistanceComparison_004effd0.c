bool __thiscall sub_4EFFD0(float *this)
{
  unsigned __int8 v3; // c0
  unsigned __int8 v4; // c2
  float v6; // [esp+4h] [ebp-30h] BYREF
  int v7; // [esp+10h] [ebp-24h] BYREF
  _DWORD v8[3]; // [esp+1Ch] [ebp-18h] BYREF
  _DWORD v9[3]; // [esp+28h] [ebp-Ch] BYREF

  F_3DTransformWithMatrixMultiplication(this, &v6, v8);
  RenderCallWithGuard(*(_DWORD **)this, &v7, v9);
  return (v3 | v4) != 0;
}

