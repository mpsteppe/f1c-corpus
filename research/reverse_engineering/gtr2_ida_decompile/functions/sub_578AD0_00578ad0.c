int __thiscall sub_578AD0(float *this, int a2, _DWORD *a3, float *a4)
{
  int v5; // eax
  _BYTE v7[68]; // [esp+8h] [ebp-50h] BYREF
  int v8; // [esp+54h] [ebp-4h]

  *a3 = 0;
  *a4 = 0.0;
  sub_61E6A0(v7);
  v8 = 0;
  if ( !sub_61E750(a2, 0) )
  {
    v5 = sub_61DB10("penalty");
    if ( v5 )
      *a4 = this[4017] * *(double *)(v5 + 16);
    else
      *a4 = this[4017] * 0.40000001;
    if ( this[4017] > 0.0 )
      *a4 = *a4 / this[4017];
  }
  v8 = -1;
  return sub_61E700(v7);
}
