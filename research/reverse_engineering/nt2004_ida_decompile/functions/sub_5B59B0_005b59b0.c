int __thiscall sub_5B59B0(float *this, int a2, int a3, int a4, int a5)
{
  int result; // eax

  switch ( a2 )
  {
    case 1:
      this[2] = (double)a3 * 0.0039215689 * this[5];
      this[3] = (double)a4 * 0.0039215689 * this[5];
      this[4] = (double)a5 * 0.0039215689 * this[5];
      break;
    case 2:
      this[6] = (double)a3 * 0.0039215689 * this[9];
      this[7] = (double)a4 * 0.0039215689 * this[9];
      this[8] = (double)a5 * 0.0039215689 * this[9];
      break;
    case 3:
      this[10] = (double)a3 * 0.0039215689 * this[13];
      this[11] = (double)a4 * 0.0039215689 * this[13];
      this[12] = (double)a5 * 0.0039215689 * this[13];
      break;
  }
  result = dword_7E8E5C;
  *(_DWORD *)(dword_7E8E5C + 240) |= 0x800u;
  return result;
}
