int *__thiscall sub_40B630(_DWORD *this, int a2, int *a3, float *a4)
{
  int v5; // edi
  int v7; // ebx
  double v8; // st7
  int *result; // eax
  float v10; // [esp+8h] [ebp-8h]
  int v11; // [esp+Ch] [ebp-4h]
  float v12; // [esp+14h] [ebp+4h]

  v5 = 0;
  v10 = 3.4028235e38;
  v11 = -1;
  if ( (int)this[4] > 0 )
  {
    v7 = 0;
    do
    {
      v12 = *(float *)(this[3] + v7 + 140);
      v8 = EmptyStub(a2) - v12;
      if ( v8 < v10 )
      {
        v10 = v8;
        v11 = v5;
      }
      ++v5;
      v7 += 208;
    }
    while ( v5 < this[4] );
  }
  result = a3;
  *a3 = v11;
  *a4 = v10;
  return result;
}

