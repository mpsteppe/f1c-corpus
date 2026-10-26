// f1c  0x00405e60  size=275
int __thiscall sub_405E60(float *this, float a2, int a3, float *a4, float *a5, float *a6, float *a7)
{
  float *v8; // ecx
  float *v9; // edi
  double v10; // st7
  double v12; // st7

  *((_DWORD *)this + 18) = a3;
  v8 = (float *)*((_DWORD *)this + 21);
  this[10] = *a4;
  this[11] = a4[1];
  this[12] = a4[2];
  this[13] = *a5;
  this[14] = a5[1];
  this[15] = a5[2];
  v9 = v8 + 22;
  if ( a2 < 0.001953125 )
    a2 = 0.0;
  if ( (*(int (__thiscall **)(float *))(*(_DWORD *)v8 + 88))(v8) == 1 )
  {
    v10 = ((double (__thiscall *)(_DWORD))*(_DWORD *)(**((_DWORD **)this + 21) + 48))(*((_DWORD *)this + 21)) * a2;
    if ( v10 > 1.0 )
      v10 = 1.0;
  }
  else
  {
    v10 = 0.0;
  }
  this[16] = v10;
  if ( v10 == 0.0 )
  {
    (*(void (__thiscall **)(float *))(*(_DWORD *)this + 8))(this);
    return 1;
  }
  else
  {
    if ( ((_BYTE)this[6] & 8) != 0 )
    {
      *a6 = 0.0;
    }
    else
    {
      *a7 = *a4 - *v9;
      a7[1] = a4[1] - v9[1];
      v12 = a4[2] - v9[2];
      a7[2] = v12;
      *a6 = sqrt(*a7 * *a7 + a7[1] * a7[1] + v12 * v12);
    }
    return 0;
  }
}
