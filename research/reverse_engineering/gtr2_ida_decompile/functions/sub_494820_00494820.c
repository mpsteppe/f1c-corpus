int sub_494820()
{
  int result; // eax
  int v1; // ebx
  int i; // esi
  char *FolderName; // eax
  int v4; // [esp+0h] [ebp-Ch]

  sub_4D0AC0(v4);
  result = CGarageOnline::GetFolderCount((CGarageOnline *)dword_B6CBB4);
  v1 = result;
  for ( i = 1; i <= v1; ++i )
  {
    FolderName = CGarageOnline::GetFolderName((CGarageOnline *)dword_B6CBB4, i);
    result = sub_4D93B0(FolderName, 0, 0, 0, 0, 0, -1, -1, -1, -1);
  }
  return result;
}
