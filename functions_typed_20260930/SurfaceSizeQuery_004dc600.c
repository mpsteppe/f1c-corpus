int __fastcall sub_4DC600(int a1, int a2, int *a3, int *a4, float a5, float a6)
{
  int result; // eax
  int v8; // esi

  result = WideStringLinkedListSearch(a1);
  v8 = result;
  *a4 = 0;
  *a3 = 0;
  if ( result )
  {
    sub_5531F0(a2, a3, a4, 0);
    *a3 = CRTFtol((double)*a3 * *(float *)(v8 + 92) * a5);
    result = CRTFtol((double)*a4 * *(float *)(v8 + 96) * a6);
    *a4 = result;
  }
  return result;
}

