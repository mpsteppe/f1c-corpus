int __thiscall sub_4E9600(int this)
{
  int v1; // esi

  v1 = this + 1764;
  F_3x3MatrixTransform(
    (_DWORD *)(this + 1764),
    (float *)(this + 13524),
    (_DWORD *)(this + 13536),
    (const void *)(this + 13488));
  return FieldReadDelegate(v1);
}
