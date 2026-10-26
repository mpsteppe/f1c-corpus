unsigned int __thiscall sub_65667F(_DWORD *this, int a2, int a3, const void *a4)
{
  unsigned int result; // eax

  if ( this[4] )
    a4 = (const void *)sub_650093(this, (int)a4);
  result = 16 * this[26];
  qmemcpy((void *)(this[8] + a3 * this[25] + a2 * this[24]), a4, result);
  return result;
}
