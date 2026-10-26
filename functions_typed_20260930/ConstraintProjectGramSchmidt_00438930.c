double __thiscall sub_438930(_DWORD *this)
{
  int v1; // eax
  double result; // st7
  double v3; // st5
  double v4; // [esp+10h] [ebp-8h]

  v1 = this[87];
  result = *(double *)(v1 + 76) * *(double *)(v1 + 348)
         + *(double *)(v1 + 52) * *(double *)(v1 + 340)
         + *(double *)(v1 + 28) * *(double *)(v1 + 332);
  v3 = result * *(double *)(v1 + 52);
  v4 = result * *(double *)(v1 + 76);
  *(double *)(v1 + 332) = *(double *)(v1 + 332) - result * *(double *)(v1 + 28);
  *(double *)(v1 + 340) = *(double *)(v1 + 340) - v3;
  *(double *)(v1 + 348) = *(double *)(v1 + 348) - v4;
  return result;
}

