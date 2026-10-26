// f1c  0x0058a6eb  size=130
int __stdcall sub_58A6EB(int a1, int a2, int a3, void (__thiscall *a4)(int), int a5)
{
  int result; // eax
  int i; // [esp+10h] [ebp-1Ch]

  for ( i = 0; ; ++i )
  {
    result = i;
    if ( i >= a3 )
      break;
    a4(a1);
    a1 += a2;
  }
  return result;
}
