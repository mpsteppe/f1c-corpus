char __thiscall sub_570D50(int this, float a2, float *a3, float *a4)
{
  int v5; // eax
  int v6; // edi
  double v7; // st7
  _DWORD *v8; // ebx
  float v10; // [esp+4h] [ebp-18h]
  float v11; // [esp+8h] [ebp-14h]
  float v12; // [esp+Ch] [ebp-10h]
  float v13[3]; // [esp+10h] [ebp-Ch] BYREF

  LOBYTE(v5) = *(_BYTE *)(this + 12112);
  if ( !(_BYTE)v5 )
  {
    v6 = 0;
    v10 = *a3 - *(float *)(this + 76);
    v11 = a3[1] - *(float *)(this + 80);
    v7 = a3[2] - *(float *)(this + 84);
    v13[0] = v10;
    v5 = *(_DWORD *)(this + 3868);
    v12 = v7;
    v13[1] = v11;
    v13[2] = v12;
    if ( v5 > 0 )
    {
      v8 = (_DWORD *)(this + 3872);
      do
      {
        sub_56DE30(v8, a2, v13, a4);
        v5 = *(_DWORD *)(this + 3868);
        ++v6;
        v8 += 187;
      }
      while ( v6 < v5 );
    }
  }
  return v5;
}
