float *__stdcall sub_44C890(int a1, float *a2, float *a3)
{
  float *result; // eax

  if ( a1 > 7 )
  {
    *a2 = flt_761BA8[-a1];
    result = a3;
    *a3 = -flt_761B54[a1];
  }
  else
  {
    *(_DWORD *)a2 = dword_761B70[a1];
    result = a3;
    *a3 = *((float *)&unk_761B8C - a1);
  }
  return result;
}
