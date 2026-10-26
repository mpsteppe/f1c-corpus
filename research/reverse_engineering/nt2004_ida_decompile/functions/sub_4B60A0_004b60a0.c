int __thiscall sub_4B60A0(int this, int a2, int a3, int a4, int a5, float a6)
{
  int result; // eax
  int *v8; // edi
  int v10; // ecx
  float v11; // esi
  float v12; // ebp
  float v13; // [esp+Ch] [ebp+4h]
  float v14; // [esp+Ch] [ebp+4h]
  float v15; // [esp+Ch] [ebp+4h]
  float v16; // [esp+1Ch] [ebp+14h]

  result = *(_DWORD *)(this + 12);
  if ( result )
  {
    sub_4B61E0(this);
    v8 = (int *)(this + 4);
    result = sub_5A1A60(this + 4, LODWORD(a6), *(_DWORD *)(this + 12), 32, 192);
    if ( !result )
    {
      v16 = (float)a2;
      v13 = (float)a3;
      *(float *)(this + 60) = *(float *)&a2;
      *(_DWORD *)(this + 68) = a4;
      v10 = *v8;
      *(_DWORD *)(this + 64) = a3;
      *(_DWORD *)(this + 72) = a5;
      v11 = v13;
      sub_5A16E0(v10, 0, v16, v13, 1.0, 0.0, 0.0, -1);
      v14 = (double)a5 + v13;
      v12 = v14;
      sub_5A16E0(*v8, 1, v16, v14, 1.0, 0.0, 1.0, -1);
      v15 = (double)a4 + v16;
      sub_5A16E0(*v8, 2, v15, v12, 1.0, 1.0, 1.0, -1);
      return sub_5A16E0(*v8, 3, v15, v11, 1.0, 1.0, 0.0, -1);
    }
  }
  return result;
}
