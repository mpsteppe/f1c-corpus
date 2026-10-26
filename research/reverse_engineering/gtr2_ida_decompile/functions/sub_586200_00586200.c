char __thiscall sub_586200(int this, float a2, float *a3)
{
  char result; // al

  result = *(_BYTE *)(this + 1320);
  if ( result )
  {
    result = (char)a3;
    *a3 = a2 * *(double *)(this + 1344) * a2
        + a2 * *(double *)(this + 1360)
        + a2 * *(double *)(this + 1336)
        + *(double *)(this + 1328);
  }
  else
  {
    *a3 = 0.0;
  }
  return result;
}
