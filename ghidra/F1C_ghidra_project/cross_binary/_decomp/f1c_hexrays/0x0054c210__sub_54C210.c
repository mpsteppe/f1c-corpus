// f1c  0x0054c210  size=25
int __thiscall sub_54C210(_DWORD *this)
{
  int v1; // ecx
  int result; // eax

  v1 = this[129];
  for ( result = 0; v1; ++result )
    v1 = *(_DWORD *)(v1 + 16);
  return result;
}
