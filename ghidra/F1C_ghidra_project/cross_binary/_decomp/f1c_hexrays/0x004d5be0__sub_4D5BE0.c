// f1c  0x004d5be0  size=78
int __thiscall sub_4D5BE0(_DWORD *this, int a2, int a3)
{
  int i; // eax
  int v4; // edx
  int v5; // ebp
  int v6; // ebx

  for ( i = 0; i < a3; this[5] = v4 )
  {
    v4 = this[3];
    v5 = v4 * *(unsigned __int8 *)(i + a2) + this[6];
    this[3] = this[4];
    v6 = this[5];
    ++i;
    this[6] = v5;
    this[4] = v6;
  }
  return sub_588678(a2, a3, 1, *this);
}
