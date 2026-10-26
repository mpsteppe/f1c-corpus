char __thiscall sub_4F6A50(int this, float a2, float *a3)
{
  char result; // al

  result = *(_BYTE *)(this + 1236);
  if ( result )
  {
    result = (char)a3;
    *a3 = a2 * *(double *)(this + 1256) * a2
        + a2 * *(double *)(this + 1264)
        + a2 * *(double *)(this + 1248)
        + *(double *)(this + 1240);
  }
  else
  {
    *a3 = 0.0;
  }
  return result;
}
