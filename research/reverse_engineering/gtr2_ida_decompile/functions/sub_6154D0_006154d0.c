int __fastcall sub_6154D0(int a1, int a2, int a3, int a4)
{
  int v4; // ebx
  int result; // eax
  int v6; // esi
  int v7; // ecx
  unsigned int v8; // edi
  double v9; // st7
  double v10; // st7
  double v11; // st7
  double v12; // st7
  int v13; // ecx
  int v14; // ebp
  double v15; // st7
  int v16; // [esp+8h] [ebp-4h]

  v4 = a3;
  result = a4 - a3 + 1;
  v16 = a1;
  if ( result >= 4 )
  {
    v6 = a1 + 8 * a3 + 24;
    v7 = a1 - a2;
    v8 = ((unsigned int)(a4 - a3 - 3) >> 2) + 1;
    result = a2 + 8 * a3 + 8;
    v4 = a3 + 4 * v8;
    do
    {
      v9 = *(double *)(v6 - 24);
      result += 32;
      v6 += 32;
      --v8;
      *(double *)(v6 - 56) = *(double *)(result - 40);
      *(double *)(result - 40) = v9;
      v10 = *(double *)(v7 + result - 32);
      *(double *)(v7 + result - 32) = *(double *)(result - 32);
      *(double *)(result - 32) = v10;
      v11 = *(double *)(v6 - 40);
      *(double *)(v6 - 40) = *(double *)(result - 24);
      *(double *)(result - 24) = v11;
      v12 = *(double *)(v6 - 32);
      *(double *)(v6 - 32) = *(double *)(result - 16);
      *(double *)(result - 16) = v12;
    }
    while ( v8 );
    a1 = v16;
  }
  if ( v4 <= a4 )
  {
    v13 = a1 - a2;
    result = a2 + 8 * v4;
    v14 = a4 - v4 + 1;
    do
    {
      v15 = *(double *)(result + v13);
      result += 8;
      --v14;
      *(double *)(result + v13 - 8) = *(double *)(result - 8);
      *(double *)(result - 8) = v15;
    }
    while ( v14 );
  }
  return result;
}
