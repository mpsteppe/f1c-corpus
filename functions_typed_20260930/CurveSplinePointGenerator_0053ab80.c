_DWORD *__thiscall sub_53AB80(int *this, int a2)
{
  _DWORD *result; // eax
  int v4; // edi
  double v5; // st7
  int v6; // eax
  double v7; // st7
  int v8; // eax
  int i; // [esp+4h] [ebp-4h]
  int v10; // [esp+Ch] [ebp+4h]

  this[2] = a2;
  result = (_DWORD *)this[3];
  if ( result )
  {
    *result = 0;
    *(_DWORD *)(this[3] + 4) = 0;
    v4 = 1;
    v10 = 1;
    for ( i = *this; v4 < *this; i = *this )
    {
      v5 = (double)v10 / (double)i;
      sub_5881F0(v5);
      *(float *)(this[3] + 8 * v4) = v5;
      v6 = this[3];
      v7 = *(float *)(v6 + 8 * v4);
      v8 = v6 + 8 * v4++;
      v10 = v4;
      *(float *)(v8 + 4) = v7 - *(float *)(v8 - 8);
    }
    sub_5881F0(1.0);
    *(float *)(this[3] + 8 * *this) = 1.0;
    *(float *)(this[3] + 8 * *this + 4) = *(float *)(this[3] + 8 * *this) - *(float *)(this[3] + 8 * *this - 8);
    *(_DWORD *)(this[3] + 8 * *this + 8) = *(_DWORD *)(this[3] + 8 * *this);
    result = (_DWORD *)*this;
    *(_DWORD *)(this[3] + 8 * *this + 12) = 0;
  }
  return result;
}

