int __thiscall sub_4B26D0(int this, float *a2)
{
  int result; // eax

  *a2 = (float)(char)sub_587BDC((double)*(char *)(this + 36) * 0.050000001);
  a2[1] = (float)(__int16)sub_587BDC((double)*(__int16 *)(this + 38) * 0.0020000001);
  result = sub_587BDC((double)*(char *)(this + 37) * 0.050000001);
  a2[2] = (float)(char)result;
  return result;
}
