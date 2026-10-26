int __usercall sub_558E01@<eax>(int a1@<eax>, int a2)
{
  unsigned int v2; // kr00_4
  _DWORD v4[4]; // [esp+0h] [ebp-1Ch] BYREF
  unsigned int v5; // [esp+10h] [ebp-Ch]
  int v6; // [esp+14h] [ebp-8h]

  v6 = a1;
  v2 = __readeflags();
  v5 = v2;
  v4[3] = 2143034241;
  v4[2] = 1779892224;
  v4[1] = 127455822;
  v4[0] = 1169037710;
  sub_1007D10(byte_16C5BF9, v4);
  __writeeflags(v5);
  return sub_53F0E0(a2);
}
