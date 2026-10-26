// f1c  0x005355f0  size=39
int __fastcall sub_5355F0(int a1, unsigned int a2)
{
  int v4; // edi
  int result; // eax

  v4 = 4;
  do
  {
    result = sub_589898((unsigned __int8)a2, a1);
    a2 >>= 8;
    --v4;
  }
  while ( v4 );
  return result;
}
