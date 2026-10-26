char __thiscall sub_5243B0(int this, float a2, float *a3)
{
  char result; // al

  result = *(_BYTE *)(this + 1296);
  if ( result )
  {
    result = (char)a3;
    *a3 = a2 * *(double *)(this + 1316) * a2
        + a2 * *(double *)(this + 1324)
        + a2 * *(double *)(this + 1308)
        + *(double *)(this + 1300);
  }
  else
  {
    *a3 = 0.0;
  }
  return result;
}
