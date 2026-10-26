// f1c  0x00496280  size=56
void __thiscall sub_496280(float *this)
{
  int v1; // esi
  float *v2; // edi
  double v3; // st7
  int v4; // [esp+8h] [ebp-4h]

  v1 = 0;
  v4 = 0;
  v2 = this + 1419;
  do
  {
    v3 = (double)v4 * 0.0625;
    sub_5881F0(v3);
    *v2 = v3;
    ++v1;
    ++v2;
    v4 = v1;
  }
  while ( v1 < 16 );
}
