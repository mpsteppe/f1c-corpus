// f1c  0x005938b4  size=283
int __cdecl sub_5938B4(_DWORD *a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  bool v8; // al
  int v9; // [esp+Ch] [ebp-2Ch]
  int v10; // [esp+10h] [ebp-28h]
  int v11; // [esp+18h] [ebp-20h]
  int v12; // [esp+1Ch] [ebp-1Ch]

  v10 = *(_DWORD *)(a2 - 4);
  v12 = sub_58E0C7()[27];
  v11 = sub_58E0C7()[28];
  sub_58E0C7()[27] = a1;
  sub_58E0C7()[28] = a3;
  v9 = sub_58A3B6(a2, a4, a5, a6, a7);
  *(_DWORD *)(a2 - 4) = v10;
  sub_58E0C7()[27] = v12;
  sub_58E0C7()[28] = v11;
  if ( *a1 == -529697949 && a1[4] == 3 && a1[5] == 429065504 && v9 )
  {
    v8 = sub_58890E();
    sub_593BBD(a1, v8);
  }
  return v9;
}
