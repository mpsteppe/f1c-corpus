// positive sp value has been detected, the output may be wrong!
_DWORD *__userpurge sub_59927C@<eax>(_DWORD *a1@<ecx>, int a2@<esi>, char a3)
{
  int v6; // [esp-10h] [ebp-10h]
  int v7; // [esp-Ch] [ebp-Ch]
  int v8; // [esp-8h] [ebp-8h]

  sub_598AEA(a1, a2, v6, v7, v8);
  if ( (a3 & 1) != 0 )
    sub_587BCF(a1);
  return a1;
}
