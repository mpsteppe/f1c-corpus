void __thiscall sub_509F0C(_DWORD *this, int a2, int a3, _DWORD *a4)
{
  unsigned __int8 *v4; // eax
  unsigned __int8 *i; // edx
  _DWORD *v7; // esi
  _DWORD *v8; // edi

  v4 = (unsigned __int8 *)(this[6] + a3 * this[1045] + a2 * this[1044]);
  for ( i = &v4[this[1046]]; v4 < i; *v8 = v7[1] )
  {
    v7 = &this[4 * *v4 + 12];
    *a4 = *v7++;
    a4[1] = *v7++;
    a4[2] = *v7;
    v8 = a4 + 3;
    ++v4;
    a4 += 4;
  }
  if ( this[4] )
    ContactManifoldCleanup((int)this, (unsigned int)&a4[-4 * this[1046]]);
}

