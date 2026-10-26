double __stdcall sub_5AF263(unsigned int a1)
{
  return (COERCE_FLOAT((unsigned int)off_16C9A34 & a1 | 0x3F000000)
        * *(float *)((char *)&unk_904D50 + ((a1 >> 12) & 0xFF8))
        + *(float *)((char *)&unk_904D54 + ((a1 >> 12) & 0xFF8)))
       * COERCE_FLOAT(((-1090519041 - a1) >> 1) & 0xFF800000);
}
