int sub_477680()
{
  int result; // eax
  char **v1; // esi
  char *v2; // eax
  char **v3; // esi
  char *v4; // eax
  _BYTE v5[512]; // [esp+4h] [ebp-200h] BYREF

  result = LinkedListIndexedAccessor_f590();
  if ( result )
  {
    v1 = *(char ***)(result + 60);
    if ( v1 )
    {
      sub_4B1520(1, v5, 512);
      sub_4C4D50(v5);
      v2 = *v1;
      if ( !*v1 )
        v2 = byte_5EA438;
      SeasonSceneMatchByIndex(v2);
      dword_8AC38C = ListIndexedAccessor(&dword_8AC36C);
      v3 = (char **)CurrentVehicleAccessor(&unk_8AC388);
      v4 = *v3;
      if ( !*v3 )
        v4 = byte_5EA438;
      StringCopyWithBufferRealloc(v4);
      return StringCopyWithBufferRealloc(v3 + 47);
    }
  }
  return result;
}
