void __cdecl sub_55EE20(_DWORD *a1, float *a2)
{
  int v2; // ecx
  float *v3; // ebx
  float *v4; // edi
  double v5; // st7
  double v6; // st6

  v2 = a1[2];
  dword_5DC470 = v2;
  v3 = (float *)a1[3];
  v4 = (float *)a1[15];
  do
  {
    v5 = a2[1] * *v3 + a2[5] * v3[1] + a2[9] * v3[2] + a2[13];
    v6 = a2[2] * *v3 + a2[6] * v3[1] + a2[10] * v3[2] + a2[14];
    *v4 = *a2 * *v3 + a2[4] * v3[1] + a2[8] * v3[2] + a2[12];
    v4[2] = v6;
    v4[1] = v5;
    v3 += 12;
    v4 += 6;
  }
  while ( v2-- > 1 );
}

