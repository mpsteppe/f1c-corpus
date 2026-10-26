int __thiscall sub_567BE0(int this)
{
  int v2; // ecx
  int result; // eax
  float v4; // [esp+0h] [ebp-20h]
  float v5; // [esp+0h] [ebp-20h]
  float v6; // [esp+0h] [ebp-20h]
  float v7; // [esp+0h] [ebp-20h]
  float v8; // [esp+4h] [ebp-1Ch]
  float v9; // [esp+4h] [ebp-1Ch]
  float v10; // [esp+4h] [ebp-1Ch]
  float v11; // [esp+4h] [ebp-1Ch]
  float v12; // [esp+8h] [ebp-18h]
  float v13; // [esp+8h] [ebp-18h]
  float v14; // [esp+8h] [ebp-18h]
  float v15; // [esp+8h] [ebp-18h]

  v2 = *(_DWORD *)this;
  if ( v2 )
  {
    v12 = (float)*(int *)(this + 16);
    v8 = (float)*(int *)(this + 12);
    v4 = (float)*(int *)(this + 8);
    sub_5EDF20(v2, 0, v4, v8, v12, 0.0, 0.0, *(_DWORD *)(this + 28));
    v13 = (float)*(int *)(this + 16);
    v9 = (float)(*(_DWORD *)(this + 24) + *(_DWORD *)(this + 12));
    v5 = (float)*(int *)(this + 8);
    sub_5EDF20(*(_DWORD *)this, 1, v5, v9, v13, 0.0, *(float *)(this + 36), *(_DWORD *)(this + 28));
    v14 = (float)*(int *)(this + 16);
    v10 = (float)(*(_DWORD *)(this + 24) + *(_DWORD *)(this + 12));
    v6 = (float)(*(_DWORD *)(this + 20) + *(_DWORD *)(this + 8));
    sub_5EDF20(*(_DWORD *)this, 2, v6, v10, v14, *(float *)(this + 32), *(float *)(this + 36), *(_DWORD *)(this + 28));
    v15 = (float)*(int *)(this + 16);
    v11 = (float)*(int *)(this + 12);
    v7 = (float)(*(_DWORD *)(this + 20) + *(_DWORD *)(this + 8));
    return sub_5EDF20(*(_DWORD *)this, 3, v7, v11, v15, *(float *)(this + 32), 0.0, *(_DWORD *)(this + 28));
  }
  return result;
}
