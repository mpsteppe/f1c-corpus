__m128 *__thiscall sub_5B139F(__m128 *this, unsigned int *a2)
{
  __m128 *result; // eax

  result = this;
  *this = _mm_shuffle_ps((__m128)*a2, (__m128)*a2, 0);
  this[4] = _mm_shuffle_ps((__m128)a2[4], (__m128)a2[4], 0);
  this[8] = _mm_shuffle_ps((__m128)a2[8], (__m128)a2[8], 0);
  this[12] = _mm_shuffle_ps((__m128)a2[12], (__m128)a2[12], 0);
  this[1] = _mm_shuffle_ps((__m128)a2[1], (__m128)a2[1], 0);
  this[5] = _mm_shuffle_ps((__m128)a2[5], (__m128)a2[5], 0);
  this[9] = _mm_shuffle_ps((__m128)a2[9], (__m128)a2[9], 0);
  this[13] = _mm_shuffle_ps((__m128)a2[13], (__m128)a2[13], 0);
  this[2] = _mm_shuffle_ps((__m128)a2[2], (__m128)a2[2], 0);
  this[6] = _mm_shuffle_ps((__m128)a2[6], (__m128)a2[6], 0);
  this[10] = _mm_shuffle_ps((__m128)a2[10], (__m128)a2[10], 0);
  this[14] = _mm_shuffle_ps((__m128)a2[14], (__m128)a2[14], 0);
  this[3] = _mm_shuffle_ps((__m128)a2[3], (__m128)a2[3], 0);
  this[7] = _mm_shuffle_ps((__m128)a2[7], (__m128)a2[7], 0);
  this[11] = _mm_shuffle_ps((__m128)a2[11], (__m128)a2[11], 0);
  this[15] = _mm_shuffle_ps((__m128)a2[15], (__m128)a2[15], 0);
  return result;
}
