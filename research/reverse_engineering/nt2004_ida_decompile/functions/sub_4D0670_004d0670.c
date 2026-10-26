float *__thiscall sub_4D0670(int this, float *a2)
{
  float *result; // eax

  result = a2;
  *a2 = (double)(int)(*(_DWORD *)(this + 8) << 20) * 0.00000011920929;
  a2[1] = (double)(int)((*(_DWORD *)(this + 8) & 0xFFFFF000) << 10) * 0.000000029802322;
  a2[2] = (double)(((*(_DWORD *)(this + 8) >> 2) & 0x3FF00000) + (*(unsigned __int16 *)(this + 12) << 30))
        * 0.00000011920929;
  return result;
}
