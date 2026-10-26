// f1c  0x0044bb60  size=163
int __thiscall sub_44BB60(void *this, int a2, char **a3)
{
  int v3; // esi
  char *v6[5]; // [esp+Ch] [ebp-14h] BYREF

  v3 = dword_8AFE88;
  if ( dword_8AFE88 )
  {
    if ( a2 )
    {
      if ( a2 == 1 )
      {
        sub_44ACB0(this, dword_8AFE88, a3);
        sub_449700((int *)a3);
        return sub_4497E0((int *)a3);
      }
      if ( a2 == 2 )
      {
        sub_4492B0(v6);
        sub_44ACB0(this, v3, v6);
        sub_449700((int *)v6);
        sub_44B370(this, (int *)v6, a3);
        sub_449340(v6);
        return sub_4497E0((int *)a3);
      }
    }
    else
    {
      sub_44ACB0(this, dword_8AFE88, a3);
    }
  }
  return sub_4497E0((int *)a3);
}
