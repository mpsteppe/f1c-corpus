// f1c  0x004dcba0  size=231
int __thiscall sub_4DCBA0(_DWORD *this, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10)
{
  int v10; // ebx
  int v12; // eax
  int v13; // eax
  int v15; // [esp+Ch] [ebp-4h] BYREF

  v10 = 0;
  v15 = 0;
  sub_4DCD10(this);
  if ( a3 )
  {
    if ( a10 )
      sub_53CBC0(&v15, a10);
    v12 = sub_587C03(96);
    v13 = v12 ? sub_54FE10(v12) : 0;
    this[1] = v13;
    *(_DWORD *)(v13 + 68) |= 1u;
    if ( sub_550080(a3, 0, 2052) )
      goto LABEL_10;
  }
  if ( sub_553980(this, 2, this[1], 32, 192) )
  {
LABEL_10:
    v10 = 1;
  }
  else
  {
    this[5] = a7;
    this[6] = a8;
    this[7] = a2;
    sub_4DCDD0(a4, a5, a6, a9);
  }
  if ( v15 )
    sub_53CE40(v15);
  if ( v10 )
    sub_4DCD10(this);
  return v10;
}
