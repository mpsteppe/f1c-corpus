_DWORD *__thiscall sub_590050(int *this, int a2)
{
  _DWORD *result; // eax
  int v3; // edi
  int v4; // eax
  double v5; // st7
  int v6; // eax
  int i; // [esp+4h] [ebp-4h]
  int v8; // [esp+Ch] [ebp+4h]

  this[2] = a2;
  result = (_DWORD *)this[3];
  if ( result )
  {
    *result = 0;
    *(_DWORD *)(this[3] + 4) = 0;
    v3 = 1;
    v8 = 1;
    for ( i = *this; v3 < *this; i = *this )
    {
      *(float *)(this[3] + 8 * v3) = pow((double)v8 / (double)i, *((float *)this + 2));
      v4 = this[3];
      v5 = *(float *)(v4 + 8 * v3);
      v6 = v4 + 8 * v3++;
      v8 = v3;
      *(float *)(v6 + 4) = v5 - *(float *)(v6 - 8);
    }
    *(float *)(this[3] + 8 * *this) = pow(1.0, *((float *)this + 2));
    *(float *)(this[3] + 8 * *this + 4) = *(float *)(this[3] + 8 * *this) - *(float *)(this[3] + 8 * *this - 8);
    *(_DWORD *)(this[3] + 8 * *this + 8) = *(_DWORD *)(this[3] + 8 * *this);
    result = (_DWORD *)*this;
    *(_DWORD *)(this[3] + 8 * *this + 12) = 0;
  }
  return result;
}
