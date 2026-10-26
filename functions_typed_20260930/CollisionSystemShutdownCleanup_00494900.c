int sub_494900()
{
  void *v0; // esi
  void *v1; // esi
  int result; // eax
  void *v3; // esi
  void *v4; // esi

  if ( dword_7CDE0C )
  {
    ResourceCascadeCleanup(dword_7CDE0C);
    dword_7CDE0C = 0;
  }
  if ( dword_7CDE04 )
  {
    DestructorWithConditionalFreeFlagClear();
    v0 = (void *)dword_7CDE04;
    if ( dword_7CDE04 )
    {
      EmptyStub_7470(dword_7CDE04);
      FreeWrapper_7bcf(v0);
    }
    dword_7CDE04 = 0;
    dword_7CDE08 = 0;
  }
  if ( dword_7CDE18 )
  {
    ResourceCascadeCleanup(dword_7CDE18);
    dword_7CDE18 = 0;
  }
  if ( dword_7CDE10 )
  {
    DestructorWithConditionalFreeFlagClear();
    v1 = (void *)dword_7CDE10;
    if ( dword_7CDE10 )
    {
      EmptyStub_7470(dword_7CDE10);
      FreeWrapper_7bcf(v1);
    }
    dword_7CDE10 = 0;
    dword_7CDE14 = 0;
  }
  result = dword_7CDE24;
  if ( dword_7CDE24 )
  {
    result = ResourceCascadeCleanup(dword_7CDE24);
    dword_7CDE24 = 0;
  }
  if ( dword_7CDE1C )
  {
    result = DestructorWithConditionalFreeFlagClear();
    v3 = (void *)dword_7CDE1C;
    if ( dword_7CDE1C )
    {
      EmptyStub_7470(dword_7CDE1C);
      result = FreeWrapper_7bcf(v3);
    }
    dword_7CDE1C = 0;
    dword_7CDE20 = 0;
  }
  if ( dword_7CDE28 )
  {
    result = DestructorWithConditionalFreeFlagClear();
    v4 = (void *)dword_7CDE28;
    if ( dword_7CDE28 )
    {
      EmptyStub_7470(dword_7CDE28);
      result = FreeWrapper_7bcf(v4);
    }
    dword_7CDE28 = 0;
    dword_7CDE2C = 0;
  }
  return result;
}

