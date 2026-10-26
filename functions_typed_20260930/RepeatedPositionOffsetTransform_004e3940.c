int __thiscall sub_4E3940(int this, float a2, float *a3, float *a4)
{
  int v5; // edi
  double v6; // st7
  int result; // eax
  int v8; // ebx
  float v9; // [esp+8h] [ebp-18h]
  float v10; // [esp+Ch] [ebp-14h]
  float v11; // [esp+10h] [ebp-10h]
  float v12[3]; // [esp+14h] [ebp-Ch] BYREF

  v5 = 0;
  v9 = *a3 - *(float *)(this + 72);
  v10 = a3[1] - *(float *)(this + 76);
  v6 = a3[2] - *(float *)(this + 80);
  v12[0] = v9;
  result = *(_DWORD *)(this + 2984);
  v11 = v6;
  v12[1] = v10;
  v12[2] = v11;
  if ( result > 0 )
  {
    v8 = this + 2988;
    do
    {
      sub_4DEF70(v8, a2, v12, a4);
      result = *(_DWORD *)(this + 2984);
      ++v5;
      v8 += 748;
    }
    while ( v5 < result );
  }
  return result;
}

