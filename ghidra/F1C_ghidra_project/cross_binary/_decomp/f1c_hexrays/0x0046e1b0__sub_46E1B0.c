// f1c  0x0046e1b0  size=121
int __thiscall sub_46E1B0(_DWORD **this)
{
  int v1; // eax
  int v2; // eax
  int v3; // esi
  int v5; // [esp+4h] [ebp-90h] BYREF
  _BYTE v6[140]; // [esp+8h] [ebp-8Ch] BYREF

  v1 = (*(int (__thiscall **)(_DWORD *, int))(*this[16] + 28))(this[16], 31);
  if ( v1 )
  {
    if ( *(int *)(v1 + 376) < 0 )
    {
      v2 = sub_489950(v1);
      if ( v2 )
      {
        v3 = sub_587ECE(v2);
        sub_461470(v6);
        if ( sub_462460(dword_7CD25C, v3, v6, &v5) )
          sub_462940(dword_7CD25C, v5);
        nullsub_3(v6);
      }
    }
  }
  return 0;
}
