// f1c  0x00455e70  size=140
int __fastcall sub_455E70(int *a1, int a2)
{
  int result; // eax

  if ( dword_7C569C != 5 && (unsigned __int8)sub_4D7A50(2, aDDevF119992002_13, 5299) )
    sub_4D7AA0(&unk_8AD25C, aEnteredHwinput_3);
  sub_44F070((int)(a1 + 1), a2, 1);
  if ( a1[1637] )
    sub_4526C0(a1 + 1376);
  sub_44FBE0(a1 + 1121);
  sub_44FBE0(a1 + 866);
  sub_44EFE0(a1 + 1);
  result = *a1;
  if ( *a1 )
  {
    result = (*(int (__stdcall **)(int))(*(_DWORD *)result + 8))(*a1);
    *a1 = 0;
  }
  return result;
}
