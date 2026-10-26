void __thiscall sub_4F0D20(float *this)
{
  unsigned __int8 v3; // c0
  unsigned __int8 v4; // c2
  float v5; // [esp+4h] [ebp-34h]
  int v6; // [esp+8h] [ebp-30h] BYREF
  float v7; // [esp+14h] [ebp-24h] BYREF
  _DWORD v8[3]; // [esp+20h] [ebp-18h] BYREF
  _DWORD v9[3]; // [esp+2Ch] [ebp-Ch] BYREF

  v5 = 1.0;
  if ( *((_DWORD *)this + 1) != *(_DWORD *)(LODWORD(dword_7C54F0[dword_7C54DC]) + 18580) )
  {
    RenderCallWithGuard(*(_DWORD **)this, &v6, v8);
    F_3DTransformWithMatrixMultiplication(this, &v7, v9);
    if ( v3 | v4 )
      v5 = *(float *)&dword_7CF83C;
  }
  ScalePropagate((int)(this + 441), v5);
}

