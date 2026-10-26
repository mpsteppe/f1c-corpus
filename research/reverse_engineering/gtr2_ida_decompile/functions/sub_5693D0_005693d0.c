int __thiscall sub_5693D0(float *this, int a2, float a3, float a4, float a5)
{
  double v5; // st7
  int v6; // eax
  int v7; // ebx
  double v8; // st7
  float v10; // [esp-10h] [ebp-10h]
  float v11; // [esp+10h] [ebp+10h]

  v5 = a3 - this[20];
  v6 = 74 * a2;
  this[v6 + 118] = v5;
  this[v6 + 135] = v5;
  v7 = (int)&this[74 * a2 + 88];
  v11 = a5 + this[74 * a2 + 150];
  v8 = this[74 * a2 + 138];
  this[74 * a2 + 151] = a4;
  if ( v11 != v8 )
  {
    v10 = this[74 * a2 + 139];
    this[74 * a2 + 138] = v11;
    sub_614EF0(v11, v10);
  }
  qmemcpy((void *)(v7 + 140), (const void *)(v7 + 208), 0x24u);
  return sub_615100(a4, v7 + 128);
}
