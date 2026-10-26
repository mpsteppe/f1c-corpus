int __thiscall sub_57BF60(int this, int a2)
{
  int result; // eax

  sub_57EAD0(a2);
  result = sub_57C030(this);
  *(double *)(this + 124) = *(double *)(this + 252) * *(double *)(this + 164)
                          + *(double *)(this + 244) * *(double *)(this + 156)
                          + *(double *)(this + 236) * *(double *)(this + 148);
  *(double *)(this + 132) = *(double *)(this + 276) * *(double *)(this + 164)
                          + *(double *)(this + 268) * *(double *)(this + 156)
                          + *(double *)(this + 260) * *(double *)(this + 148);
  *(double *)(this + 140) = *(double *)(this + 300) * *(double *)(this + 164)
                          + *(double *)(this + 292) * *(double *)(this + 156)
                          + *(double *)(this + 284) * *(double *)(this + 148);
  return result;
}
