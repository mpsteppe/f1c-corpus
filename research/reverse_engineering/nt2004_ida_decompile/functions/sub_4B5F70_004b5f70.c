int __thiscall sub_4B5F70(int this, int a2, int a3, int a4, int a5, int a6)
{
  int result; // eax
  int v8; // eax
  int v9; // ecx
  float v10; // ebp
  float v11; // [esp+8h] [ebp+4h]
  float v12; // [esp+10h] [ebp+Ch]
  float v13; // [esp+10h] [ebp+Ch]
  float v14; // [esp+10h] [ebp+Ch]
  float v15; // [esp+14h] [ebp+10h]
  float v16; // [esp+18h] [ebp+14h]

  result = *(_DWORD *)(this + 8);
  if ( result )
  {
    sub_4B61A0(this);
    result = sub_5A1A60(this, a6, *(_DWORD *)(this + 8), 32, 192);
    if ( !result )
    {
      v16 = (float)a4;
      *(float *)(this + 36) = *(float *)&a2;
      *(_DWORD *)(this + 40) = a3;
      v8 = *(_DWORD *)(this + 8);
      *(float *)(this + 44) = *(float *)&a4;
      *(float *)(this + 48) = *(float *)&a5;
      v9 = *(_DWORD *)this;
      *(float *)(this + 52) = v16 / (double)*(int *)(*(_DWORD *)(v8 + 16) + 28);
      v12 = (float)a5;
      *(float *)(this + 56) = v12 / (double)*(int *)(*(_DWORD *)(v8 + 16) + 32);
      v11 = (float)a2;
      v15 = (float)a3;
      sub_5A16E0(v9, 0, v11, v15, 1.0, 0.0, 0.0, -1);
      v13 = v12 + v15;
      v10 = v13;
      sub_5A16E0(*(_DWORD *)this, 1, v11, v13, 1.0, 0.0, 1.0, -1);
      v14 = v16 + v11;
      sub_5A16E0(*(_DWORD *)this, 2, v14, v10, 1.0, 1.0, 1.0, -1);
      return sub_5A16E0(*(_DWORD *)this, 3, v14, v15, 1.0, 1.0, 0.0, -1);
    }
  }
  return result;
}
