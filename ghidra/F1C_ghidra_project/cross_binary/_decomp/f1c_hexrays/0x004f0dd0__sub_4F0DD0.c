// f1c  0x004f0dd0  size=356
int __thiscall sub_4F0DD0(float *this)
{
  bool v2; // al
  float v3; // ecx
  bool v4; // zf
  signed int v5; // eax
  double v6; // st7
  double v7; // st7
  float v9; // [esp+4h] [ebp-14h]
  float v10; // [esp+4h] [ebp-14h]
  float v11; // [esp+10h] [ebp-8h]
  float v12; // [esp+14h] [ebp-4h]

  v2 = !byte_7C56AC || dword_8AB6E4 == 2;
  v3 = *this;
  v9 = *(float *)(*(_DWORD *)this + 4184);
  v12 = this[3408] * -0.5;
  if ( v2 )
  {
    v3 = this[3387];
    v11 = sqrt(v3 * v3 + this[3388] * this[3388] + this[3389] * this[3389])
        * 2.2369363
        * 0.0049999999
        * (sqrt(v3 * v3 + this[3388] * this[3388] + this[3389] * this[3389])
         * 2.2369363
         * 0.0049999999);
  }
  else
  {
    v11 = 0.0;
  }
  v5 = sub_5884ED(LODWORD(v3)) & 0x80000001;
  v4 = v5 == 0;
  if ( v5 < 0 )
    v4 = (((_BYTE)v5 - 1) | 0xFFFFFFFE) == -1;
  if ( v4 )
    v6 = 1.0;
  else
    v6 = -1.0;
  v7 = (v11 * 0.30000001 * v6 + v12 - v9) * dbl_8AFE98 + v9;
  v10 = v7;
  if ( v7 < -0.30000001 )
    return sub_4E0C90(*(_DWORD *)this + 1776, -0.30000001);
  if ( v10 > 0.30000001 )
    v10 = 0.30000001;
  return sub_4E0C90(*(_DWORD *)this + 1776, v10);
}
