// f1c  0x00454d30  size=102
char __thiscall sub_454D30(void *this, char *a2, _DWORD *a3, int a4)
{
  int v5; // edx
  int v7; // ecx

  if ( sub_454350((int)this, a2, &a4, a4) )
  {
    v5 = a4;
    *a3 = 1;
    a3[1] = v5;
    return 1;
  }
  else if ( sub_4541D0((int)this, a2, &a4) )
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
