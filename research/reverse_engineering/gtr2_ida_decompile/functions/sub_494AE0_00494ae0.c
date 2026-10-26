int __usercall sub_494AE0@<eax>(int a1@<ecx>, int a2@<edi>)
{
  int ContentID; // eax
  int v4; // edi
  char *FileName; // eax
  int FileRating; // eax
  int v8; // [esp+14h] [ebp-114h] BYREF
  int FileCount; // [esp+18h] [ebp-110h]
  char Buffer[256]; // [esp+1Ch] [ebp-10Ch] BYREF
  int v11; // [esp+124h] [ebp-4h]

  v8 = 0;
  sub_4CE140(a1, &v8);
  ContentID = CGarageOnline::GetContentID((CGarageOnline *)dword_B6CBB8);
  if ( *(_DWORD *)(a1 + 596) == ContentID )
    return 0;
  *(_DWORD *)(a1 + 596) = ContentID;
  sub_4D0AC0(a2);
  v4 = 1;
  FileCount = CGarageOnline::GetFileCount((CGarageOnline *)dword_B6CBB8);
  if ( FileCount < 1 )
    return 0;
  do
  {
    v11 = 0;
    FileName = CGarageOnline::GetFileName((CGarageOnline *)dword_B6CBB8, v4);
    sub_615860(FileName);
    strlen((const char *)0xFFFFFFFF);
    FileRating = CGarageOnline::GetFileRating((CGarageOnline *)dword_B6CBB8, v4);
    sprintf(Buffer, "%s%s%d", WindowName, (const char *)&v8, FileRating);
    sub_4D93B0(Buffer, 0, 0, 0, 0, 0, -1, -1, -1, -1);
    v11 = -1;
    ++v4;
  }
  while ( v4 <= FileCount );
  return 0;
}
