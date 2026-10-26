double __fastcall sub_5A0670(int a1, int a2, int a3, int a4, int a5)
{
  return (*(float *)(a3 + 4 * a5) - *(float *)(a2 + 4 * a5)) * (*(float *)(a1 + 4 * a4) - *(float *)(a2 + 4 * a4))
       - (*(float *)(a1 + 4 * a5) - *(float *)(a2 + 4 * a5)) * (*(float *)(a3 + 4 * a4) - *(float *)(a2 + 4 * a4));
}
