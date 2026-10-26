int __thiscall sub_542200(int this, float a2, float a3, float a4, float a5, int a6)
{
  double v7; // st7
  double v8; // st7
  int v9; // edi
  int v10; // eax
  int result; // eax
  bool v12; // zf
  double v13; // st7
  double v14; // st6
  int v15; // [esp+Ch] [ebp+4h]
  int v16; // [esp+14h] [ebp+Ch]
  float v17; // [esp+14h] [ebp+Ch]
  float v18; // [esp+1Ch] [ebp+14h]
  int v19; // [esp+1Ch] [ebp+14h]

  if ( a6 )
  {
    v7 = 1.0;
    v18 = 1.0;
    if ( a4 >= 0.0 )
      *(_DWORD *)(this + 84) = CRTFtol(1.0);
    else
      *(_DWORD *)(this + 84) = 0;
  }
  else
  {
    v7 = (double)dword_8B8DD4;
    v18 = (float)dword_8B8DD8;
    if ( a4 <= 1.0 )
      a4 = a4 * v7;
    if ( a5 <= 1.0 )
      a5 = v18 * a5;
    if ( a4 > v7 || a4 >= 0.0 )
      *(_DWORD *)(this + 84) = CRTFtol(v7);
    else
      *(_DWORD *)(this + 84) = 0;
    if ( a5 > (double)v18 )
      goto LABEL_16;
  }
  if ( a5 < 0.0 )
  {
    *(_DWORD *)(this + 88) = 0;
    goto LABEL_17;
  }
LABEL_16:
  *(_DWORD *)(this + 88) = CRTFtol(v7);
LABEL_17:
  v8 = a3;
  if ( a3 <= 1.0 )
    v8 = v8 * v18;
  v9 = CRTFtol(v8);
  *(_DWORD *)(this + 104) = v9;
  v10 = CRTFtol(v8);
  v15 = *(_DWORD *)(this + 84);
  v16 = v9 + (v15 >> 1);
  *(_DWORD *)(this + 92) = v16;
  v19 = *(_DWORD *)(this + 88);
  *(float *)(this + 20) = (float)v16;
  *(_DWORD *)(this + 100) = v10;
  result = (v19 >> 1) + v10;
  *(_DWORD *)(this + 96) = result;
  v12 = (*(_BYTE *)(this + 128) & 0x10) == 0;
  *(float *)(this + 24) = (float)result;
  v13 = (double)v15;
  v17 = 0.5 * v13 / *(float *)(this + 28);
  *(float *)(this + 12) = v17;
  v14 = (double)v19;
  *(float *)(this + 16) = 0.5 * v14 / *(float *)(this + 32);
  *(float *)(this + 116) = v13 / v14;
  if ( !v12 )
    *(float *)(this + 12) = -v17;
  return result;
}
