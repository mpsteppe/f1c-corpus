float *__thiscall sub_519ED0(int this, float *a2)
{
  float *result; // eax

  result = a2;
  *a2 = (double)(int)((*(_DWORD *)(this + 4) & 0xFFFFFE00) << 14) * 0.0000000037252903;
  a2[1] = (double)(int)(2 * (*(_DWORD *)(this + 4) & 0xFFFC0000)) * 0.000000014901161;
  a2[2] = (double)(int)(((unsigned int)&byte_800000 & (*(_DWORD *)(this + 4) >> 8))
                      + (*(unsigned __int8 *)(this + 8) << 24))
        * 0.0000000037252903;
  return result;
}
