char __thiscall sub_457310(void *this, char *a2, _DWORD *a3, int a4)
{
  int v5; // edx
  int v7; // ecx

  if ( (unsigned __int8)((int (__thiscall *)(void *, char *, int *, int))loc_456930)(this, a2, &a4, a4) )
  {
    v5 = a4;
    *a3 = 1;
    a3[1] = v5;
    return 1;
  }
  else if ( sub_456750((int)this, a2, &a4) )
  {
    v7 = a4;
    *a3 = 0;
    a3[1] = v7;
    return 1;
  }
  else
  {
    return 0;
  }
}
