unsigned int __usercall sub_529700@<eax>(__m64 a1@<mm0>)
{
  int v1; // eax

  v1 = _mm_cvtsi64_si32(a1);
  return v1 & 0x80000000 ^ v1;
}

