void *__thiscall sub_6191E0(_DWORD *this)
{
  void *v2; // eax
  void *v3; // eax
  void *result; // eax
  size_t v5; // [esp-Ch] [ebp-10h]
  size_t v6; // [esp-8h] [ebp-Ch]

  v2 = operator new(56 * this[140]);
  v6 = 136 * this[142];
  this[141] = v2;
  this[140] = 0;
  v3 = operator new(v6);
  v5 = 88 * this[144];
  this[143] = v3;
  this[142] = 0;
  result = operator new(v5);
  this[145] = result;
  this[144] = 0;
  return result;
}
