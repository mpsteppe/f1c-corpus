float *__usercall sub_67CC1B@<eax>(float *result@<eax>, unsigned int a2@<ecx>)
{
  *result = (double)((unsigned __int16)a2 >> 11) * 0.032258064;
  result[1] = (double)((a2 >> 5) & 0x3F) * 0.015873017;
  result[2] = (double)(a2 & 0x1F) * 0.032258064;
  result[3] = 1.0;
  return result;
}
