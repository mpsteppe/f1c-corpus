void *__thiscall ShortComputation_9c10(_DWORD *this, void *a2, _DWORD *a3)
{
  void *result; // eax

  *this = *a3;
  this[1] = a3[1];
  this[2] = a3[2];
  this[3] = a3[3];
  this[7] = a3[7];
  result = a2;
  this[8] = a3[8];
  qmemcpy(a2, this, 0x34u);
  return result;
}
