int __thiscall sub_673626(_DWORD *this, _DWORD *a2)
{
  int v2; // esi
  int v3; // eax
  int v4; // esi
  int v5; // eax

  *a2 = 0;
  a2[1] = 0;
  a2[2] = 0;
  v2 = this[1];
  if ( v2 )
    v3 = v2 + *(_DWORD *)(*this + 8);
  else
    v3 = 0;
  *a2 = v3;
  a2[1] = *((unsigned __int16 *)this + 4);
  a2[2] = *((unsigned __int16 *)this + 5);
  a2[3] = *((unsigned __int16 *)this + 6);
  a2[4] = *(unsigned __int16 *)this[6];
  a2[5] = *(unsigned __int16 *)(this[6] + 2);
  a2[6] = *(unsigned __int16 *)(this[6] + 4);
  a2[7] = *(unsigned __int16 *)(this[6] + 6);
  a2[8] = *(unsigned __int16 *)(this[6] + 8);
  a2[9] = *(unsigned __int16 *)(this[6] + 10);
  a2[10] = 4 * a2[7] * a2[6] * a2[8];
  v4 = this[5];
  if ( v4 )
    v5 = v4 + *(_DWORD *)(*this + 8);
  else
    v5 = 0;
  a2[11] = v5;
  return 0;
}
