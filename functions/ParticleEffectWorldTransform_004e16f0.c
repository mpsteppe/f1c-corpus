void __thiscall sub_4E16F0(float *this, float *a2, float *a3, int a4)
{
  float *v4; // ebp
  float *v5; // esi
  unsigned __int8 v6; // al
  double v7; // st7
  double v8; // st6
  int v9; // [esp-14h] [ebp-28h]
  int v10; // [esp+4h] [ebp-10h]
  float v11[2]; // [esp+8h] [ebp-Ch] BYREF
  float v12; // [esp+10h] [ebp-4h]

  v4 = (float *)dword_8ACEB8;
  if ( dword_8ACEB8 )
  {
    v5 = this + 614;
    v10 = 17;
    do
    {
      v6 = *((_BYTE *)v5 - 8);
      if ( v6 )
      {
        v9 = *((unsigned __int8 *)v5 - 7);
        v7 = a2[1] * *v5 + a2[2] * v5[1] + *a2 * *(v5 - 1);
        v8 = a2[4] * *v5 + a2[5] * v5[1] + a2[3] * *(v5 - 1);
        v12 = a2[7] * *v5 + a2[8] * v5[1] + a2[6] * *(v5 - 1);
        v11[0] = v7 + *a3;
        v11[1] = v8 + a3[1];
        v12 = v12 + a3[2];
        ParticleSpawnFunction(v4, v11, v6, v5 + 2, v9, a4);
      }
      v5 += 7;
      --v10;
    }
    while ( v10 );
  }
}
