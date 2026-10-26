int __thiscall sub_5FDC80(void *this, int **a2, _BYTE *a3, char a4)
{
  _DWORD *v5; // eax
  int *v6; // esi

  v5 = operator new(0x80u);
  if ( v5 )
    v6 = sub_5FC6D0(v5);
  else
    v6 = 0;
  if ( (*a3 & 8) != 0 )
  {
    if ( !sub_5FD1C0(v6, (int)a3, (int)this) )
    {
LABEL_13:
      sub_5FDFB0(v6, 1);
      if ( a2 )
        *a2 = v6;
      return 0;
    }
  }
  else if ( !sub_5FD5E0((int)v6, (int)a3) )
  {
    goto LABEL_13;
  }
  if ( v6 )
  {
    nullsub_7(v6);
    j__free(v6);
  }
  if ( a2 )
    *a2 = 0;
  return -1;
}
