// f1c  0x004e1970  size=39
int __thiscall sub_4E1970(int *this)
{
  int v2; // esi
  int *v3; // edi
  int result; // eax

  v2 = 0;
  v3 = this + 732;
  do
  {
    result = sub_4E18C0((int)this, v2);
    *v3 = result;
    ++v2;
    ++v3;
  }
  while ( v2 < 14 );
  return result;
}
