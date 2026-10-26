int __fastcall sub_458590(int *a1, int a2)
{
  int result; // eax
  char v4; // [esp+0h] [ebp-4h]

  if ( dword_75CBA8 != 5 && (unsigned __int8)sub_500F90((int)&unk_7D7920, 2, (int)aDDevNascar2004_4, 5534) )
    sub_500FE0((int)&unk_7D7920, aEnteredHwinput_3, v4);
  sub_4514A0((int)(a1 + 1), a2, 1);
  if ( a1[1639] )
    sub_454C90(a1 + 1378);
  sub_452190(a1 + 1123);
  sub_452190(a1 + 868);
  sub_451430(a1 + 1);
  result = *a1;
  if ( *a1 )
  {
    result = (*(int (__stdcall **)(int))(*(_DWORD *)result + 8))(*a1);
    *a1 = 0;
  }
  return result;
}
