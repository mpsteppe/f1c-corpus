void *__thiscall sub_6623AF(int this, unsigned int a2)
{
  unsigned int v3; // eax
  unsigned int v4; // esi
  void *result; // eax
  void *v6; // [esp+10h] [ebp+8h]

  v3 = *(_DWORD *)(this + 148);
  if ( a2 <= v3 )
    return *(void **)(this + 144);
  if ( v3 )
    v4 = 2 * v3;
  else
    v4 = 16;
  while ( v4 < a2 )
    v4 *= 2;
  result = operator new(4 * v4);
  v6 = result;
  if ( result )
  {
    j__free(*(void **)(this + 144));
    *(_DWORD *)(this + 144) = v6;
    *(_DWORD *)(this + 148) = v4;
    return *(void **)(this + 144);
  }
  return result;
}
