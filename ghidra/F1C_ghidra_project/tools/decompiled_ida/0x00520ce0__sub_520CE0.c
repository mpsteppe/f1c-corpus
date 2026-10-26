// Address: 0x00520ce0
// Size: 276 bytes
// Name: sub_520CE0
// Type: float *__stdcall(float *, float *)
// Source: IDA Hex-Rays decompilation

float *__stdcall sub_520CE0(float *a1, float *a2)
{
  float *result; // eax
  double v3; // st7
  float v4; // edi
  float v5; // esi
  int v6; // ebp
  double v7; // st7
  int v8; // ecx
  int v9; // ebx
  int v10; // ebp
  float *v11; // esi
  long double v12; // st6
  long double v13; // st7
  float *v14; // ecx
  long double v15; // st6
  long double v16; // st7
  _DWORD v17[7]; // [esp+0h] [ebp-1Ch]

  result = a1;
  v3 = *a2 + a2[5] + a2[10];
  v4 = *a2;
  v5 = a2[5];
  v6 = *((_DWORD *)a2 + 10);
  if ( flt_8D627C < v3 )
  {
    v15 = sqrt(v3 + flt_8D6280) * flt_8D6284;
    v16 = flt_8D6288 / v15;
    a1[3] = v15;
    *a1 = (a2[6] - a2[9]) * v16;
    a1[1] = (a2[8] - a2[2]) * v16;
    a1[2] = v16 * (a2[1] - a2[4]);
  }
  else
  {
    v7 = a2[10];
    *(float *)v17 = *a2;
    *(float *)&v17[1] = v5;
    v17[2] = v6;
    v8 = 2;
    if ( *(float *)&v17[v5 > (double)v4] >= v7 )
      v8 = v5 > (double)v4;
    v9 = dword_8D6270[v8];
    v10 = dword_8D6270[v9];
    v11 = &a2[v8];
    v12 = sqrt(flt_8D6290 + *(float *)&v17[v8] - *(float *)&v17[v9] - *(float *)&v17[v10]) * flt_8D6294;
    v13 = flt_8D6298 / v12;
    a1[v8] = v12;
    v14 = &a2[4 * v8];
    a1[v9] = (v14[v9] + v11[4 * v9]) * v13;
    a1[v10] = (v11[4 * v10] + v14[v10]) * v13;
    a1[3] = v13 * (a2[4 * v9 + v10] - a2[4 * v10 + v9]);
  }
  return result;
}
