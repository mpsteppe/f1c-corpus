float *__thiscall sub_491B30(int this)
{
  float *result; // eax

  result = *(float **)(this + 312);
  *(float *)(this + 304) = *result / *(float *)(this + 308);
  return result;
}
