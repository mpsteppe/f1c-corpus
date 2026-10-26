int sub_4A08E0()
{
  int v0; // eax
  const char *v1; // eax
  _BYTE v3[128]; // [esp+4h] [ebp-180h] BYREF
  _BYTE v4[256]; // [esp+84h] [ebp-100h] BYREF

  if ( DelegatedFieldGetter(&dword_7D2DB0) == 3 )
  {
    v0 = LinkedListDereference(&dword_7D2DB0);
    if ( v0 )
    {
      if ( FixedOffsetReturn(v0) )
      {
        SceneNameLookupBySeason(v3, 128);
        if ( PathFileComparisonCounter(v3) == 1 && dword_7D032C == 1 )
        {
          v1 = (const char *)dword_5EC418;
          if ( !dword_5EC418 )
            v1 = byte_5EA438;
          StringFormatWithBufferOverflowCheck(v4, "%s%s", v1, aWinconstructor);
          FileLoadWithRetryLoop(v4, 1);
        }
      }
    }
  }
  ScoringClassificationDisplay();
  return 0;
}
