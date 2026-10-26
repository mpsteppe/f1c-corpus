void *__thiscall sub_57C580(_DWORD *this)
{
  void *v2; // eax
  void *v3; // eax
  void *result; // eax
  unsigned int v5; // [esp-Ch] [ebp-10h]
  unsigned int v6; // [esp-8h] [ebp-Ch]

  v2 = operator new(56 * this[139]);
  v6 = 132 * this[141];
  this[140] = v2;
  this[139] = 0;
  v3 = operator new(v6);
  v5 = 88 * this[143];
  this[142] = v3;
  this[141] = 0;
  result = operator new(v5);
  this[144] = result;
  this[143] = 0;
  return result;
}
