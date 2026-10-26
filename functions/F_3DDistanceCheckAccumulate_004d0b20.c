int __thiscall sub_4D0B20(int *this, float a2)
{
  float *v3; // eax
  double v4; // st7
  int v5; // ebp
  double v6; // st7
  int result; // eax
  bool v8; // cc
  int v9; // ebx
  int v10; // esi
  int v11; // ecx
  int v12; // esi
  double v13; // st7
  double v14; // st7
  unsigned __int8 v16; // c0
  unsigned __int8 v17; // c3
  float v18; // [esp+8h] [ebp-18h] BYREF
  float v19; // [esp+Ch] [ebp-14h] BYREF
  float v20; // [esp+10h] [ebp-10h] BYREF
  float v21; // [esp+14h] [ebp-Ch]
  float v22; // [esp+18h] [ebp-8h]
  float v23; // [esp+1Ch] [ebp-4h]

  v3 = (float *)VirtualDispatchHelper(&dword_5EA510);
  v4 = v3[3];
  v3 += 3;
  v21 = -v4;
  v5 = 0;
  v22 = -v3[1];
  v6 = v3[2];
  result = *this;
  v8 = *this <= 0;
  v23 = -v6;
  if ( !v8 )
  {
    v9 = 0;
    do
    {
      v10 = this[1];
      v11 = *(_DWORD *)(v10 + v9 + 104);
      v12 = v9 + v10;
      if ( v11 )
      {
        TripleFieldQuery(&v18, &v19, &v20);
        v18 = v18 - v21;
        v19 = v19 - v22;
        v13 = v20 - v23;
        v20 = v13;
        if ( v13 * v20 + v19 * v19 + v18 * v18 < 1024.0 )
        {
          v14 = a2 + *(float *)(v12 + 128);
          *(float *)(v12 + 128) = v14;
          if ( !(v16 | v17) )
            *(float *)(v12 + 128) = v14 - *(float *)(v12 + 124);
          sub_4A2840(v12 + 4, *(float *)(v12 + 128));
        }
      }
      result = *this;
      ++v5;
      v9 += 132;
    }
    while ( v5 < *this );
  }
  return result;
}
