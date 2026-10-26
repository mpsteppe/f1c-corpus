int __thiscall sub_5DC700(void *this, int **a2, char *a3, __int16 a4)
{
  int *v5; // eax
  int *v6; // esi
  int v8; // eax

  v5 = (int *)operator new(0x28Cu);
  if ( v5 )
    v6 = sub_5DB7E0(v5);
  else
    v6 = 0;
  v6[155] = (int)this;
  if ( sub_5DAC00((char *)v6, a3, a4) )
  {
    sub_5DBA90(v6);
    j__free(v6);
    return -1;
  }
  else
  {
    if ( (*(_BYTE *)v6 & 0x10) != 0 )
    {
      sub_5FDFB0(v6, 1);
      v8 = *v6 | 0x100000;
    }
    else
    {
      sub_5FDFB0(v6, 1);
      v8 = *v6 | 0x200000;
    }
    *v6 = v8;
    if ( a2 )
      *a2 = v6;
    return 0;
  }
}
