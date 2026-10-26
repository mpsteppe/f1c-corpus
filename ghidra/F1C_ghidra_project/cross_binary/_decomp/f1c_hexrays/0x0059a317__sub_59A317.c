// f1c  0x0059a317  size=31
// positive sp value has been detected, the output may be wrong!
void *__userpurge sub_59A317@<eax>(int a1@<ecx>, int a2@<esi>, char a3)
{
  void *v3; // esi
  int v6; // [esp-10h] [ebp-10h]
  int v7; // [esp-Ch] [ebp-Ch]
  int v8; // [esp-8h] [ebp-8h]

  v3 = (void *)(a1 - 4);
  sub_5998E5((char *)(a1 - 4), a2, v6, v7, v8);
  if ( (a3 & 1) != 0 )
    sub_587BCF(v3);
  return v3;
}
