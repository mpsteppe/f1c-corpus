int __thiscall sub_46CD20(_DWORD *this)
{
  char *v1; // eax
  int v2; // edx
  int v3; // eax
  CHAR *v4; // edi
  int v5; // ecx
  const CHAR *v6; // ecx
  const char *v7; // edx
  const char *v8; // ecx
  int v9; // eax
  int v10; // esi
  char *v11; // eax
  int v12; // eax
  CHAR NewFileName[256]; // [esp+14h] [ebp-100h] BYREF

  v1 = (char *)this[57];
  if ( !v1 )
    v1 = byte_5EA438;
  NameCompareAndFormat(v1);
  PathTruncationUtility(NewFileName, 256);
  v2 = *(_DWORD *)&aProfileiconBmp[4];
  v3 = *(_DWORD *)&aProfileiconBmp[8];
  v4 = &NewFileName[strlen(NewFileName)];
  *(_DWORD *)v4 = *(_DWORD *)aProfileiconBmp;
  v5 = *(_DWORD *)&aProfileiconBmp[12];
  *((_DWORD *)v4 + 1) = v2;
  *((_DWORD *)v4 + 2) = v3;
  *((_DWORD *)v4 + 3) = v5;
  LinkedListNodeRemovalByStringKey(NewFileName);
  if ( sub_497AD0(lpExistingFileName, 0) )
  {
    v6 = &lpExistingFileName[strlen(lpExistingFileName)];
    if ( v6 > lpExistingFileName )
    {
      while ( *v6 != 92 )
      {
        if ( --v6 <= lpExistingFileName )
          goto LABEL_9;
      }
      ++v6;
    }
LABEL_9:
    if ( v6 )
    {
      StringCopyWithBufferRealloc(v6);
      v7 = (const char *)dword_7CE684;
      if ( !dword_7CE684 )
        v7 = byte_5EA438;
      v8 = &v7[strlen(v7)];
      if ( v8 > v7 )
      {
        while ( *v8 != 46 )
        {
          if ( --v8 <= v7 )
            goto LABEL_17;
        }
        *v8 = 0;
      }
    }
LABEL_17:
    FileAttributesExistenceCheck(NewFileName);
    CopyFileA(lpExistingFileName, NewFileName, 1);
  }
  v9 = (*(int (__thiscall **)(int, int))(*(_DWORD *)dword_7CD8C0 + 28))(dword_7CD8C0, 17);
  v10 = v9;
  if ( v9 )
  {
    SeasonSceneNameAccessor(v9);
    TrackSceneConfigLoader(v10);
  }
  v11 = (char *)dword_7CE64C;
  if ( !dword_7CE64C )
    v11 = byte_5EA438;
  StringCopyWithBufferRealloc(v11);
  StringCopyWithBufferRealloc(byte_5EA438);
  sub_4B0770(0);
  v12 = (*(int (__thiscall **)(int, int))(*(_DWORD *)dword_7CD8C0 + 28))(dword_7CD8C0, 45);
  if ( v12 )
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v12 + 56))(v12, 0);
  return 0;
}

