float *__stdcall sub_44A450(int a1, float *a2, float *a3)
{
  float *result; // eax

  if ( a1 > 7 )
  {
    *a2 = flt_7CA3C0[-a1];
    result = a3;
    *a3 = -flt_7CA36C[a1];
  }
  else
  {
    *(_DWORD *)a2 = dword_7CA388[a1];
    result = a3;
    *a3 = *((float *)&unk_7CA3A4 - a1);
  }
  return result;
}

