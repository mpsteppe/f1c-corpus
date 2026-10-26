// f1c  0x0058801d  size=34
int __cdecl sub_58801D(int a1, int a2)
{
  int result; // eax

  *(_QWORD *)a2 = sub_58C7FC(a1);
  result = -1;
  if ( (*(_DWORD *)(a2 + 4) & *(_DWORD *)a2) != -1 )
    return 0;
  return result;
}
