// bad sp value at call has been detected, the output may be wrong!
int __userpurge sub_46FCF9@<eax>(int a1@<esi>, char a2)
{
  _BYTE *v2; // edx
  int v3; // ecx
  int v4; // esi
  char v6; // [esp+DE0Ch] [ebp-Ch]
  char v7; // [esp+DE10h] [ebp-8h]

  (*(void (**)(void))(a1 + 106))();
  *v2 += BYTE1(v3);
  v4 = v3;
  sub_487220(v6, v7);
  *(_BYTE *)(v4 + 228) = a2;
  *(_DWORD *)v4 = &off_5A00F0;
  return v4;
}
