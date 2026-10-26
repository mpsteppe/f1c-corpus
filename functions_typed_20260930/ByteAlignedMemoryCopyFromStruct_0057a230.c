unsigned __int8 *__thiscall sub_57A230(unsigned __int8 *this, void *a2, unsigned int *a3)
{
  unsigned __int8 *result; // eax
  unsigned int v4; // ecx
  const void *v5; // esi

  result = this;
  v4 = this[44];
  *a3 = v4;
  if ( v4 )
  {
    v5 = result + 45;
    result = (unsigned __int8 *)v4;
    qmemcpy(a2, v5, v4);
  }
  return result;
}

