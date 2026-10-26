// f1c  0x004b5e30  size=25
int __thiscall sub_4B5E30(_DWORD *this)
{
  int result; // eax
  _DWORD *v2; // ecx
  int v3; // edx

  result = 0;
  v2 = this + 19;
  v3 = 104;
  do
  {
    result += *v2;
    v2 += 4;
    --v3;
  }
  while ( v3 );
  return result;
}
