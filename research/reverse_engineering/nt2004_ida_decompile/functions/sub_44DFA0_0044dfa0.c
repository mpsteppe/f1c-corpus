signed int __thiscall sub_44DFA0(void *this, int a2, char **a3)
{
  int v3; // esi
  char *v6[5]; // [esp+Ch] [ebp-14h] BYREF

  v3 = dword_7DA9B8;
  if ( dword_7DA9B8 )
  {
    if ( a2 )
    {
      if ( a2 == 1 )
      {
        sub_44D0F0(this, dword_7DA9B8, a3);
        sub_44BB40((int *)a3);
        return sub_44BC20((size_t *)a3);
      }
      if ( a2 == 2 )
      {
        sub_44B6F0(v6);
        sub_44D0F0(this, v3, v6);
        sub_44BB40((int *)v6);
        sub_44D7B0(this, (int *)v6, a3);
        sub_44B780(v6);
        return sub_44BC20((size_t *)a3);
      }
    }
    else
    {
      sub_44D0F0(this, dword_7DA9B8, a3);
    }
  }
  return sub_44BC20((size_t *)a3);
}
