float *__userpurge sub_64CB44@<eax>(unsigned int a1@<edi>, unsigned int a2@<esi>, int a3)
{
  float *result; // eax
  float *v4; // ecx
  int v5; // eax
  int v6; // edx
  double v7; // st7
  float *v8; // [esp+0h] [ebp-1Ch]
  float v9; // [esp+10h] [ebp-Ch]
  float v10; // [esp+14h] [ebp-8h]
  unsigned int i; // [esp+18h] [ebp-4h]

  result = (float *)operator new(16 * a1);
  v4 = result;
  if ( result )
  {
    v8 = result;
    for ( i = 0; i < a1; *(v4 - 1) = 1.0 - v7 )
    {
      v9 = (double)a2 / (double)a1;
      v10 = ((double)i + 0.5) * v9 + 0.5;
      v5 = (int)v10;
      v6 = v5 - 1;
      v7 = (double)v5 + 1.0 - v10;
      if ( v5 - 1 < 0 )
        v6 = a3 != 0 ? a2 - 1 : 0;
      if ( v5 >= a2 )
        v5 = a3 == 0 ? a2 - 1 : 0;
      v4[1] = v7;
      *(_DWORD *)v4 = v6;
      *((_DWORD *)v4 + 2) = v5;
      v4 += 4;
      ++i;
    }
    return v8;
  }
  return result;
}
