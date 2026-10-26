int __thiscall sub_4E5E60(int this, int a2, int a3, int a4, int a5, int a6)
{
  int result; // eax
  int v8; // eax
  int *v9; // esi
  int v11; // ecx
  float v12; // edi
  float v13; // ebp
  float v14; // [esp+8h] [ebp+4h]
  float v15; // [esp+8h] [ebp+4h]
  float v16; // [esp+8h] [ebp+4h]
  float v17; // [esp+18h] [ebp+14h]

  result = *(_DWORD *)(this + 12);
  if ( result )
  {
    v8 = *(_DWORD *)(this + 4);
    v9 = (int *)(this + 4);
    if ( v8 )
    {
      sub_5EE1D0(dword_FB1CE0, v8);
      *v9 = 0;
    }
    result = sub_5EE000(dword_FB1CE0, this + 4, a6, *(_DWORD *)(this + 12), 32, 192);
    if ( !result )
    {
      v17 = (float)a2;
      v14 = (float)a3;
      *(float *)(this + 60) = *(float *)&a2;
      *(_DWORD *)(this + 68) = a4;
      v11 = *v9;
      *(_DWORD *)(this + 64) = a3;
      *(_DWORD *)(this + 72) = a5;
      v12 = v14;
      sub_5EDF20(v11, 0, v17, v14, 1.0, 0.0, 0.0, -1);
      v15 = (double)a5 + v14;
      v13 = v15;
      sub_5EDF20(*v9, 1, v17, v15, 1.0, 0.0, 1.0, -1);
      v16 = (double)a4 + v17;
      sub_5EDF20(*v9, 2, v16, v13, 1.0, 1.0, 1.0, -1);
      return sub_5EDF20(*v9, 3, v16, v12, 1.0, 1.0, 0.0, -1);
    }
  }
  return result;
}
