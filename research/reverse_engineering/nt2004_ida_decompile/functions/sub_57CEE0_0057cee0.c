int __thiscall sub_57CEE0(int this)
{
  double *v2; // ebp
  int result; // eax

  qmemcpy((void *)(this + 4), (const void *)(this + 356), 0x18u);
  qmemcpy((void *)(this + 28), (const void *)(this + 380), 0x48u);
  qmemcpy((void *)(this + 100), (const void *)(this + 452), 0x18u);
  v2 = (double *)(this + 148);
  qmemcpy((void *)(this + 148), (const void *)(this + 476), 0x18u);
  qmemcpy((void *)(this + 308), (const void *)(this + 500), 0x18u);
  qmemcpy((void *)(this + 332), (const void *)(this + 524), 0x18u);
  result = sub_57C030(this);
  *(double *)(this + 124) = *(double *)(this + 252) * *(double *)(this + 164)
                          + *(double *)(this + 244) * *(double *)(this + 156)
                          + *(double *)(this + 236) * *(double *)(this + 148);
  *(double *)(this + 132) = *(double *)(this + 276) * *(double *)(this + 164)
                          + *(double *)(this + 268) * *(double *)(this + 156)
                          + *(double *)(this + 260) * *(double *)(this + 148);
  *(double *)(this + 140) = *(double *)(this + 300) * *(double *)(this + 164)
                          + *(double *)(this + 292) * *(double *)(this + 156)
                          + *(double *)(this + 284) * *v2;
  return result;
}
