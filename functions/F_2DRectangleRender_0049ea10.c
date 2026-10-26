int __thiscall sub_49EA10(int this, int a2, int a3, int a4, int a5, int a6)
{
  int result; // eax
  int v8; // eax
  float v9; // ebp
  float v10; // [esp+8h] [ebp+4h]
  float v11; // [esp+10h] [ebp+Ch]
  float v12; // [esp+10h] [ebp+Ch]
  float v13; // [esp+10h] [ebp+Ch]
  float v14; // [esp+14h] [ebp+10h]
  float v15; // [esp+18h] [ebp+14h]

  result = *(_DWORD *)(this + 8);
  if ( result )
  {
    ShortComputation_ec40(this);
    result = ObjectConstructorWithAllocationAndSubInit(this, a6, *(_DWORD *)(this + 8), 32, 192);
    if ( !result )
    {
      v15 = (float)a4;
      *(float *)(this + 36) = *(float *)&a2;
      *(_DWORD *)(this + 40) = a3;
      v8 = *(_DWORD *)(this + 8);
      *(float *)(this + 44) = *(float *)&a4;
      *(float *)(this + 48) = *(float *)&a5;
      *(float *)(this + 52) = v15 / (double)*(int *)(*(_DWORD *)(v8 + 84) + 28);
      v11 = (float)a5;
      *(float *)(this + 56) = v11 / (double)*(int *)(*(_DWORD *)(v8 + 84) + 32);
      v10 = (float)a2;
      v14 = (float)a3;
      sub_553650(0, v10, v14, 1.0, 0.0, 0.0, -1);
      v12 = v11 + v14;
      v9 = v12;
      sub_553650(1, v10, v12, 1.0, 0.0, 1.0, -1);
      v13 = v15 + v10;
      sub_553650(2, v13, v9, 1.0, 1.0, 1.0, -1);
      return sub_553650(3, v13, v14, 1.0, 1.0, 0.0, -1);
    }
  }
  return result;
}
