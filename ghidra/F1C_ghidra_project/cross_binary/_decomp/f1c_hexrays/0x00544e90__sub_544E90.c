// f1c  0x00544e90  size=87
int __thiscall sub_544E90(void *this, _DWORD *a2, const char *a3)
{
  _DWORD *v4; // eax
  _DWORD *v5; // esi

  v4 = (_DWORD *)sub_587C03(444);
  if ( v4 && (v5 = sub_5418B0(v4)) != 0 )
  {
    *v5 = this;
    sub_5418E0((int)v5, a3);
    if ( a2 )
      *a2 = v5;
    return 0;
  }
  else
  {
    sub_53C590(-1, aErrorCreatingV_0);
    return -1;
  }
}
