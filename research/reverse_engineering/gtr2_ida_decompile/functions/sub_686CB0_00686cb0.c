int __thiscall sub_686CB0(void **this, _DWORD *a2, void *a3, void *a4)
{
  int result; // eax
  void *v6; // eax

  result = sub_681D0E(this, a2);
  if ( result >= 0 )
  {
    this[48] = (void *)a2[48];
    v6 = (void *)a2[49];
    this[53] = 0;
    this[54] = 0;
    this[55] = 0;
    this[49] = v6;
    this[50] = a3;
    this[51] = a4;
    this[29] = (void *)a2[29];
    this[30] = (void *)a2[30];
    this[31] = (void *)a2[31];
    this[32] = (void *)a2[32];
    this[33] = (void *)a2[33];
    this[34] = (void *)a2[34];
    this[35] = (void *)a2[35];
    this[36] = (void *)a2[36];
    this[37] = (void *)a2[37];
    this[38] = (void *)a2[38];
    this[39] = (void *)a2[39];
    this[40] = (void *)a2[40];
    this[41] = (void *)a2[41];
    this[42] = (void *)a2[42];
    this[43] = (void *)a2[43];
    this[44] = (void *)a2[44];
    this[45] = (void *)a2[45];
    this[46] = (void *)a2[46];
    memset(this + 10, 0, 0x4Cu);
    result = (*((int (__thiscall **)(void **))*this + 3))(this);
    if ( result >= 0 )
    {
      result = sub_682468(this, 0);
      if ( result >= 0 )
        return 0;
    }
  }
  return result;
}
