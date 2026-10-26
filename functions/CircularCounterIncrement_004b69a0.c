_DWORD *__thiscall sub_4B69A0(_DWORD *this)
{
  int v2; // eax
  int v3; // ecx

  v2 = this[620];
  v3 = (this[622] + 1) % this[621];
  this[622] = v3;
  return PhysicsObjectListManager((char *)(v2 + 176 * v3));
}
