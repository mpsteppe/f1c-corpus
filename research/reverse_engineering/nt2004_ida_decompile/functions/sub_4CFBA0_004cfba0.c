float *__thiscall sub_4CFBA0(_DWORD *this, float *a2)
{
  float *result; // eax

  result = a2;
  *a2 = (double)(int)(*this << 18) * 0.00000011920929;
  a2[1] = (double)(int)(32 * (*this & 0xFFFFC000)) * 0.000000059604645;
  a2[2] = (double)(int)((this[1] << 23) + ((unsigned int)&unk_7C0000 & (*this >> 9))) * 0.00000011920929;
  return result;
}
