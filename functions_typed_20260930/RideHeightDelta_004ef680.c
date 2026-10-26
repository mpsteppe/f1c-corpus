int __thiscall sub_4EF680(float *this, int a2)
{
  int result; // eax

  result = a2;
  *(float *)(a2 + 8) = this[467];
  *(_DWORD *)(a2 + 4) = 0;
  *(_DWORD *)a2 = 0;
  *(float *)(a2 + 4) = (this[3490] - this[3522] + this[3428] - this[3460]) * 0.5;
  return result;
}

