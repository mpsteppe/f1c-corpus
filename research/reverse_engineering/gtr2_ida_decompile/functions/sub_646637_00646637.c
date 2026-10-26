double __stdcall sub_646637(unsigned int a1)
{
  unsigned __int16 v1; // dx

  LOBYTE(v1) = 0;
  HIBYTE(v1) = BYTE2(a1);
  return COERCE_FLOAT(HIBYTE(a1) + v1 + (((a1 << 16) + (a1 & 0xFF00)) << 8));
}
