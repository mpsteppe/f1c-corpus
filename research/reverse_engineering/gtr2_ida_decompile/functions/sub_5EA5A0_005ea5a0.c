const char *__thiscall sub_5EA5A0(const char *this)
{
  const char *result; // eax

  result = this;
  _mm_prefetch(this, 1);
  return result;
}
