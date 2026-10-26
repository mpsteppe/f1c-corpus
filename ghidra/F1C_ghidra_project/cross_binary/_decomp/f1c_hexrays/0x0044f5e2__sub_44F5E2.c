// f1c  0x0044f5e2  size=14
// positive sp value has been detected, the output may be wrong!
int __usercall sub_44F5E2@<eax>(_BYTE *a1@<edx>, char a2@<ch>)
{
  int v3; // [esp-14h] [ebp-14h]
  int v4; // [esp-10h] [ebp-10h]
  int v5; // [esp-Ch] [ebp-Ch]
  int v6; // [esp-8h] [ebp-8h]

  *a1 += a2;
  sub_44F6F6(v3, v4, v5, v6);
  return 0;
}
