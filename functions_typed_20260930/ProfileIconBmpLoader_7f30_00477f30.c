int __thiscall sub_477F30(void *this)
{
  char *v1; // edi
  int v2; // eax
  int v3; // ecx
  int v4; // edx
  char v6[128]; // [esp+8h] [ebp-80h] BYREF

  (*(void (__thiscall **)(void *, _DWORD))(*(_DWORD *)this + 60))(this, 0);
  PathTruncationUtility(v6, 128);
  v1 = &v6[strlen(v6) + 1];
  v2 = *(_DWORD *)&aProfileiconBmp[4];
  v3 = *(_DWORD *)&aProfileiconBmp[8];
  *(_DWORD *)--v1 = *(_DWORD *)aProfileiconBmp;
  v4 = *(_DWORD *)&aProfileiconBmp[12];
  *((_DWORD *)v1 + 1) = v2;
  *((_DWORD *)v1 + 2) = v3;
  *((_DWORD *)v1 + 3) = v4;
  StringCopyWithBufferRealloc(v6);
  return 0;
}

