// bad sp value at call has been detected, the output may be wrong!
// positive sp value has been detected, the output may be wrong!
int __usercall sub_47E3F4@<eax>(char a1@<bl>, int a2@<ebp>)
{
  int v2; // eax
  int v3; // eax
  int v5; // [esp-8h] [ebp-8h]

  *(_BYTE *)(a2 + 95) += a1;
  (*(void (**)(void))(v5 - 117))();
  __asm { icebp }
  if ( sub_4C5840(0) )
  {
    v2 = sub_5679C0(aRacelaps);
    if ( v2 )
    {
      v3 = sub_567970(v2);
      sub_488B40(v3);
    }
  }
  return 0;
}
