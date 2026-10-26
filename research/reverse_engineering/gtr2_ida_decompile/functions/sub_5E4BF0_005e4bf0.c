int __thiscall sub_5E4BF0(void *this, _BYTE *a2)
{
  _DWORD *v2; // eax
  char v5; // [esp+0h] [ebp-4h]

  if ( !a2 )
    goto LABEL_6;
  v2 = dword_FB2D78;
  if ( !dword_FB2D78 )
    goto LABEL_6;
  while ( !*v2 || (_BYTE *)*v2 != a2 )
  {
    v2 = (_DWORD *)v2[1];
    if ( !v2 )
      goto LABEL_6;
  }
  if ( *v2 )
  {
    if ( (*((_DWORD *)a2 + 27))-- == 1 )
    {
      sub_5E6DD0(a2);
      a2[140] = 0;
      sub_5D9A40((int *)&dword_FB2D78, (int)a2, 1);
      `eh vector destructor iterator'(a2, 0xD8u, *((_DWORD *)a2 - 1), j_j_nullsub_7);
      j__free(a2 - 4);
    }
    return 0;
  }
  else
  {
LABEL_6:
    sub_5D8C80((int)this, (char *)0xFFFFFFFF, "Invalid texture pointer", v5);
    return -1;
  }
}
