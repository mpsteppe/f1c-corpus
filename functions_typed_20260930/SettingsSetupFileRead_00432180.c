char __thiscall sub_432180(char **this)
{
  char v3[512]; // [esp+10h] [ebp-200h] BYREF

  v3[0] = 0;
  PathTruncationUtility(v3, 512);
  strcat(v3, off_5C3FA0[0]);
  *(_WORD *)&v3[strlen(v3)] = word_5C2AAC;
  StringCopyWithBufferRealloc(v3);
  StringCopyWithBufferRealloc(&byte_5EA438);
  DirectoryFileEnumerator(*this, 0);
  return 1;
}

