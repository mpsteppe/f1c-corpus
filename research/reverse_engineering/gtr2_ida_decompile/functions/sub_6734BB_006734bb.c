_DWORD *__thiscall sub_6734BB(int *this, int a2, const void *a3, int a4, int a5, int a6)
{
  _DWORD *v6; // ebx
  _DWORD *v7; // edi
  _DWORD *v8; // edx

  *this = a2;
  qmemcpy(this + 1, a3, 0x14u);
  v6 = this + 13;
  v7 = this + 11;
  this[7] = a5;
  this[8] = a6;
  this[6] = a4;
  this[9] = 0;
  this[11] = 0;
  this[13] = 0;
  sub_6733BF(a2, (int)a3, a4, 1, this + 11, this + 13);
  v8[10] = *v7 * *(unsigned __int16 *)(a4 + 8);
  v8[12] = *v6 * *(unsigned __int16 *)(a4 + 8);
  v8[14] = 0;
  v8[15] = 0;
  v8[16] = 0;
  return v8;
}
