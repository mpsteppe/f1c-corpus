int *__usercall sub_5421F2@<eax>(unsigned int a1@<ebx>, unsigned int a2@<edi>, int a3)
{
  int *result; // eax
  int *v4; // esi
  int v5; // eax
  double X; // st7
  int v7; // eax
  unsigned int v8; // ecx
  double v9; // st7
  int *v10; // [esp+Ch] [ebp-18h]
  float v11; // [esp+14h] [ebp-10h]
  float v12; // [esp+18h] [ebp-Ch]
  float v13; // [esp+1Ch] [ebp-8h]
  int v14; // [esp+20h] [ebp-4h]
  unsigned int v15; // [esp+20h] [ebp-4h]

  result = (int *)operator new(16 * a1);
  v4 = result;
  if ( result )
  {
    v10 = result;
    v5 = v14;
    v15 = 0;
    for ( dword_7E0594 = v5; v15 < a1; *((float *)v4 - 1) = 1.0 - v9 )
    {
      v11 = (double)a2 / (double)a1;
      X = (double)v15 * v11 - 0.5;
      v13 = X;
      v12 = floor(X);
      v7 = (int)v12;
      v8 = v7 + 1;
      if ( v7 < 0 )
        v7 = a3 != 0 ? a2 - 1 : 0;
      if ( v8 >= a2 )
        v8 = a3 == 0 ? a2 - 1 : 0;
      *v4 = v7;
      v4[2] = v8;
      v4 += 4;
      ++v15;
      v9 = 1.0 - (v13 - v12);
      *((float *)v4 - 3) = v9;
    }
    return v10;
  }
  return result;
}
